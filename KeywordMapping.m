#import "KeywordMapping.h"

@implementation QueryToken

- (NSString*) description {
    return @"{query}";
}

- (NSString*) label {
    return @"Query";
}

@end

@implementation QueryPartToken

- (id) initWithPartNumber: (int) thePartNumber {
    partNumber = thePartNumber;
    return self;
}

- (int) partNumber {
    return partNumber;
}

- (NSString*) description {
    return [NSString stringWithFormat: @"{%d}", partNumber];
}

- (NSString*) label {
    return [NSString stringWithFormat: @"Query %d", partNumber];
}

@end

@implementation InputToken

- (NSString*) description {
    return @"{input}";
}

- (NSString*) label {
    return @"Input";
}

@end

@implementation KeywordMapping

- (id) initWithKeyword: (NSString*) theKeyword fromDictionary: (NSDictionary*) dictionary {
    NSString* theExpansion = [dictionary objectForKey: @"expansion"];
    BOOL theDontUseUnicode = [[dictionary objectForKey: @"dontUseUnicode"] 
        isEqualToNumber: [NSNumber numberWithInt: 1]];
    BOOL theEncodeSpaces = [[dictionary objectForKey: @"encodeSpaces"] 
        isEqualToNumber: [NSNumber numberWithInt: 1]];
    return [self initWithKeyword: theKeyword 
        expansion: theExpansion 
        dontUseUnicode: theDontUseUnicode 
        encodeSpaces: theEncodeSpaces];
}

- (id) initWithKeyword: (NSString*) theKeyword 
    expansion: (NSString*) theExpansion {
    return [self initWithKeyword: theKeyword expansion: theExpansion dontUseUnicode: NO encodeSpaces: NO];
}

- (id) initWithKeyword: (NSString*) theKeyword 
    expansion: (NSString*) theExpansion
    dontUseUnicode: (BOOL) theDontUseUnicode
    encodeSpaces: (BOOL) theEncodeSpaces {
    keyword = [theKeyword copy];
    expansion = [theExpansion copy];
    dontUseUnicode = theDontUseUnicode;
    encodeSpaces = theEncodeSpaces;
    return self;
}

- (void) dealloc {
    [keyword release];
    [expansion release];
    [super dealloc];
}

- (NSString*) keyword {
    return keyword;
}

- (void) setKeyword: (NSString*) newKeyword {
    [keyword release];
    keyword = [newKeyword copy];
}

- (NSString*) expansion {
    return expansion;
}

- (NSArray*) expansionAsTokens {
    NSMutableArray* tokens = [NSMutableArray new];
    NSLog(@"making tokens from %@", expansion);
    int start = 0;
    int searchStart = 0;
    while (start < [expansion length]) {
        NSRange searchRange = NSMakeRange(searchStart, [expansion length] - searchStart);
        int curlStart = [expansion rangeOfString: @"{" options: 0 range: searchRange].location;
        int curlEnd = curlStart == NSNotFound ? NSNotFound : [expansion rangeOfString: @"}" options: 0 
            range: NSMakeRange(curlStart, [expansion length] - curlStart)].location;
        if (curlEnd != NSNotFound) {
            NSString* symbol = [expansion substringWithRange: NSMakeRange(curlStart + 1, curlEnd - curlStart - 1)];
            if ([symbol isEqualToString: @"query"]) {
                [tokens addObject: [expansion substringWithRange: NSMakeRange(start, curlStart - start)]];
                [tokens addObject: [[QueryToken alloc] init]];                
                start = curlEnd + 1;
            } else if ([symbol isEqualToString: @"input"]) {
                [tokens addObject: [expansion substringWithRange: NSMakeRange(start, curlStart - start)]];
                [tokens addObject: [[InputToken alloc] init]];                
                start = curlEnd + 1;
            } else if ([symbol intValue] >= 1 && [symbol intValue] <= 9) {
                [tokens addObject: [expansion substringWithRange: NSMakeRange(start, curlStart - start)]];
                [tokens addObject: [[QueryPartToken alloc] initWithPartNumber: [symbol intValue]]];
                start = curlEnd + 1;
            }
            searchStart = curlEnd + 1;
        } else {
            [tokens addObject: [expansion substringWithRange: NSMakeRange(start, [expansion length] - start)]];
            break;            
        }
    }
    NSLog(@"as tokens: %@", tokens);
    return tokens;
}

- (void) setExpansion: (NSString*) newExpansion {
    [expansion release];
    expansion = [newExpansion copy];
}

- (void) setDontUseUnicode: (BOOL) flag {
    dontUseUnicode = flag;
}

- (BOOL) dontUseUnicode {
    return dontUseUnicode;
}

- (void) setEncodeSpaces: (BOOL) flag {
    encodeSpaces = flag;
}

- (BOOL) encodeSpaces {
    return encodeSpaces;
}

- (NSDictionary*) toDictionary {
    NSMutableDictionary* dictionary = [NSMutableDictionary new];    
    [dictionary setObject: expansion forKey: @"expansion"];
    [dictionary setObject: [NSNumber numberWithInt: dontUseUnicode ? 1 : 0] forKey: @"dontUseUnicode"];
    [dictionary setObject: [NSNumber numberWithInt: encodeSpaces ? 1 : 0] forKey: @"encodeSpaces"];
    return dictionary;
}

- (NSString*) encodeQuery: (NSString*) query {
    if (dontUseUnicode) {
        query = [query stringByAddingPercentEscapesUsingEncoding: NSISOLatin1StringEncoding];
    } else {
        // Hashes are interpreted as URL fragments by Safari
        query = [query stringByAddingPercentEscapesUsingEncoding: NSUTF8StringEncoding];
    }
    NSMutableString* result = [query mutableCopy];
    [result replaceOccurrencesOfString: @"#" withString: @"%23" options: 0 range: NSMakeRange(0, [result length])];
    [result replaceOccurrencesOfString: @":" withString: @"%3a" options: 0 range: NSMakeRange(0, [result length])];
    if (encodeSpaces) {
        [result replaceOccurrencesOfString: @"%20" withString: @"+" options: 0 range: NSMakeRange(0, [result length])];
    }
    return result;
}

- (NSArray*) tokenizeParts: (NSString*) query {
    NSMutableArray* parts = [NSMutableArray new];
    NSCharacterSet* whitespaceSet = [NSCharacterSet whitespaceAndNewlineCharacterSet];
    int offset = 0;
    BOOL quoted = NO;
    int start = -1;
    while (offset < [query length]) {
        unichar c = [query characterAtIndex: offset];
        if (c == '"') {
            quoted = !quoted;
            if (start == -1) {
                start = offset;
            }
        } else if (!quoted && [whitespaceSet characterIsMember: c]) {
            if (start != -1 && offset > start) {
                NSString* part = [query substringWithRange: NSMakeRange(start, offset - start)];
                [parts addObject: part];
                start = -1;
            }
        } else {
            if (start == -1) {
                start = offset;
            }
        }
        offset++;
    }
    if (start != -1 && offset > start) {
        NSString* part = [query substringWithRange: NSMakeRange(start, offset - start)];
        [parts addObject: part];
    }
    NSLog(@"Parts: %@", parts);
    return parts;
}

@end
