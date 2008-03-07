#include "KeywordMapper.h"
#include "KeywordMapping.h"

@interface KeywordMapper (Internal)

- (void) setupDefaults;
- (void) buildCache;
- (NSString*) mappingFileName;
- (BOOL) isUrl: (NSString*) string;
- (void) replaceInString: (NSMutableString*) string 
    fromString: (NSString*) fromString 
    toString: (NSString*) toString;
- (void) loadMappingsFromDictionary: (NSDictionary*) dictionary 
    oldVersion: (BOOL) oldVersion;

@end

@implementation KeywordMapper

- (id) init {
    mappings = [NSMutableArray new];
    cache = [NSMutableDictionary new];
    [self reloadMappings];
    return self;
}

- (int) numberOfRowsInTableView: (NSTableView*) aTableView {
    return [mappings count];
}

- (id) tableView: (NSTableView*) aTableView 
    objectValueForTableColumn: (NSTableColumn*) aTableColumn
    row: (int) rowIndex {
    KeywordMapping* mapping = [mappings objectAtIndex: rowIndex];
    if ([[aTableColumn identifier] isEqualToString: @"Keyword"]) {
        return [mapping keyword];
    } else {
        return nil;
    }
}

- (void) tableView: (NSTableView*) aTableView 
    setObjectValue: (id) anObject 
    forTableColumn: (NSTableColumn*) aTableColumn 
    row: (int) rowIndex {
    KeywordMapping* mapping = [mappings objectAtIndex: rowIndex];
    if ([[aTableColumn identifier] isEqualToString: @"Keyword"]) {
        [mapping setKeyword: anObject];
        [self buildCache];
    }
}

- (NSString*) mapKeywordInput: (NSString*) input {
    NSString* result = input;
    if (![self isUrl: input]) {
        NSString* keyword = nil;
        NSString* query = nil;
        input = [input stringByTrimmingCharactersInSet: [NSCharacterSet whitespaceCharacterSet]];
        NSRange spaceRange = [input rangeOfString: @" "];
        if (spaceRange.location != NSNotFound) {
            keyword = [input substringToIndex: spaceRange.location];
            query = [input substringFromIndex: spaceRange.location + 1];
            query = [query stringByTrimmingCharactersInSet: [NSCharacterSet whitespaceCharacterSet]];
        } else {
            keyword = input;
            query = @"";
        }
        KeywordMapping* mapping = [cache objectForKey: keyword];
        if (!mapping) {
           mapping = [cache objectForKey: @"default"];
           query = input;
        }
        if (mapping) {
            NSArray* parts = [mapping tokenizeParts: query];
            input = [mapping encodeQuery: input];
            query = [mapping encodeQuery: query];
            NSMutableString* expansion = [[mapping expansion] mutableCopy];
            [expansion replaceOccurrencesOfString: @"{query}" withString: query options: 0 range: NSMakeRange(0, [expansion length])];
            [expansion replaceOccurrencesOfString: @"{input}" withString: input options: 0 range: NSMakeRange(0, [expansion length])];
            for (int i = 0; i < [parts count]; i++) {
                NSString* symbol = [NSString stringWithFormat: @"{%d}", i + 1];
                NSString* part = [parts objectAtIndex: i];
                if (part) {
                    [expansion replaceOccurrencesOfString: symbol withString: part options: 0 range: NSMakeRange(0, [expansion length])];
                }
            }
            [parts release];
            result = expansion;
        }
    }
    return result;
}

- (BOOL) isUrl: (NSString*) string {
    BOOL isUrl = NO;
    @try {
        NSURL* url = [NSURL URLWithString: string];
        if ([url scheme] != nil && ([url host] != nil || [url path] != nil)) {
            isUrl = YES;
        }
    } @catch (NSException* e) {
        NSLog(@"Exception parsing URL: %@", e);
    }
    return isUrl;
}

- (NSString*) mappingFileName {
    NSArray* paths = NSSearchPathForDirectoriesInDomains(NSApplicationSupportDirectory, NSUserDomainMask, YES);
    NSString* path = [[paths objectAtIndex: 0] stringByAppendingPathComponent: @"Keywurl/Keywords.plist"];
    return path;
}

- (void) reloadMappings {
    [self loadMappingsFromFile: [self mappingFileName]];
}

- (void) loadMappingsFromFile: (NSString*) path {
    #ifdef DEBUG
    NSLog(@"Loading keywords from %@", path);
    #endif
    [mappings removeAllObjects];
    if ([[NSFileManager defaultManager] fileExistsAtPath: path]) {
        NSData* data = [NSData dataWithContentsOfFile: path];
        NSPropertyListFormat format;
        NSString* error;
        id plist = [NSPropertyListSerialization propertyListFromData: data
            mutabilityOption: NSPropertyListImmutable
            format: &format
            errorDescription: &error];
        if (plist) {
            NSNumber* configVersion = [plist objectForKey: @"version"];
            if (configVersion == nil) {
                [self loadMappingsFromDictionary: plist oldVersion: YES];
            } else {
                id keywordNode = [plist objectForKey: @"keywords"];
                if (keywordNode && [keywordNode isKindOfClass: [NSDictionary class]]) {
                    [self loadMappingsFromDictionary: (NSDictionary*) keywordNode oldVersion: NO];
                }
            }
        } else {
            NSLog(@"Could not load keywords: %@", error);
            [error release];
        }
    } else {
        [self setupDefaults];
    }
    [self buildCache];
}

- (void) loadMappingsFromDictionary: (NSDictionary*) dictionary 
    oldVersion: (BOOL) oldVersion {
    NSEnumerator* keyEumerator = [dictionary keyEnumerator];
    NSString* keyword;
    while (keyword = [keyEumerator nextObject]) {
        KeywordMapping* mapping;
        id value = [dictionary objectForKey: keyword];
        if ([value isKindOfClass: [NSString class]]) {
            NSString* expansion = [dictionary objectForKey: keyword];
            mapping = [[KeywordMapping alloc] initWithKeyword: keyword
                expansion: expansion];
        } else {
            mapping = [[KeywordMapping alloc] initWithKeyword: keyword
                fromDictionary: (NSDictionary*) value];
        }
        if (oldVersion) {
            NSMutableString* newExpansion = [[mapping expansion] mutableCopy];
            [newExpansion replaceOccurrencesOfString: @"@@@" withString: @"{query}" 
                options: 0 range: NSMakeRange(0, [newExpansion length])];
            [newExpansion replaceOccurrencesOfString: @"$$$" withString: @"{input}" 
                options: 0 range: NSMakeRange(0, [newExpansion length])];
            [mapping setExpansion: newExpansion];
        }
        [self addKeyword: mapping];
        [mapping release];
    }    
}

- (void) setupDefaults {
    // Set up some sensible defaults
    [self addKeyword: @"default"
        expansion: @"http://www.google.com/search?q=@$"];
    [self addKeyword: @"amazon" 
        expansion: @"http://www.amazon.com/exec/obidos/search-handle-url/index%3Dblended%26field-keywords%3D{query}"
        dontUseUnicode: YES
        encodeSpaces: NO];
    [self addKeyword: @"allmusic"
        expansion: @"http://allmusic.com/cg/amg.dll?P=amg&sql={query}&opt1=1"];
    [self addKeyword: @"discogs"
        expansion: @"http://www.discogs.com/search?type=all&q={query}"];
    [self addKeyword: @"flickr"
        expansion: @"http://flickr.com/photos/tags/{query}"];
    [self addKeyword: @"imdb"
        expansion: @"http://imdb.com/find?s=all&q={query}"
        dontUseUnicode: YES
        encodeSpaces: NO];
    [self addKeyword: @"gmaps"
        expansion: @"http://maps.google.com/maps?oi=map&q={query}"];
    [self addKeyword: @"gimages"
        expansion: @"http://images.google.com/images?q={query}&ie=UTF-8&oe=UTF-8"];
    [self addKeyword: @"wiki"
        expansion: @"http://en.wikipedia.org/wiki/Special:Search?search={query}&go=Go"
        dontUseUnicode: NO
        encodeSpaces: YES];
    [self addKeyword: @"youtube"
        expansion: @"http://youtube.com/results?search_query={query}"];    
}

- (void) saveMappings {
    [self saveMappingsToFile: [self mappingFileName]];
}

- (void) saveMappingsToFile: (NSString*) path {
    NSLog(@"Saving keywords to %@", path);
    NSString* error;
    NSMutableDictionary* plist = [NSMutableDictionary new];
    NSMutableDictionary* keywordDictionary = [NSMutableDictionary new];
    for (int i = [mappings count] - 1; i >= 0; i--) {
        KeywordMapping* mapping = [mappings objectAtIndex: i];
        [keywordDictionary setObject: [mapping toDictionary] forKey: [mapping keyword]];
    }
    [plist setObject: keywordDictionary forKey: @"keywords"];
    [plist setObject: [NSNumber numberWithInt: 1] forKey: @"version"];
    NSData* data = [NSPropertyListSerialization dataFromPropertyList: plist
        format: NSPropertyListXMLFormat_v1_0
        errorDescription: &error];
    if (data) {
        NSString* directory = [path stringByDeletingLastPathComponent];
        if (![[NSFileManager defaultManager] fileExistsAtPath: directory]) {
            if (![[NSFileManager defaultManager] createDirectoryAtPath: directory attributes: nil]) {
                NSLog(@"Could not create directory");
            }
        }
        if (![data writeToFile: path atomically: YES]) {
            NSLog(@"Could not write mappings to file");
        }
    } else {
        NSLog(@"Could not serialize keywords: %@", error);
        [error release];
    }
}

- (void) addKeyword: (KeywordMapping*) mapping {
    [mappings addObject: mapping];
    [self buildCache];
}

- (void) addKeyword: (NSString*) keyword expansion: (NSString*) expansion {
    [self addKeyword: keyword expansion: expansion dontUseUnicode: NO encodeSpaces: NO];
}

- (void) addKeyword: (NSString*) keyword expansion: (NSString*) expansion
    dontUseUnicode: (BOOL) theDontUseUnicode
    encodeSpaces: (BOOL) theEncodeSpaces {
    KeywordMapping* mapping = [[KeywordMapping alloc] initWithKeyword: keyword 
        expansion: expansion
        dontUseUnicode: theDontUseUnicode
        encodeSpaces: theEncodeSpaces];
    [self addKeyword: mapping];
}

- (void) removeKeyword: (NSString*) keyword {
    for (int i = [mappings count] - 1; i >= 0; i--) {
        KeywordMapping* mapping = [mappings objectAtIndex: i];
        if ([[mapping keyword] isEqualToString: keyword]) {
            [mappings removeObjectAtIndex: i];
        }
    }
    [self buildCache];
}

- (void) removeKeywordAtIndex: (int) index {
    [mappings removeObjectAtIndex: index];
    [self buildCache];
}

- (NSArray*) mappings {
    return mappings;
}

- (void) buildCache {
    [cache removeAllObjects];
    for (int i = [mappings count] - 1; i >= 0; i--) {
        KeywordMapping* mapping = [mappings objectAtIndex: i];
        [cache setValue: mapping forKey: [mapping keyword]];
    }
}

@end
