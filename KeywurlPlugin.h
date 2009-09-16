#import <Cocoa/Cocoa.h>
#import "KeywordMapper.h"

@interface KeywurlPlugin : NSObject {
    IBOutlet NSWindow* introWindow;
    KeywordMapper* fKeywordMapper;
    NSMutableDictionary* preferences;
    BOOL fLoaded;
}

- (id) init;
- (KeywordMapper*) keywordMapper;
- (BOOL) isLoaded;
- (NSString*) preferenceFileName;
- (NSMutableDictionary*) preferences;
- (void) savePreferences;

+ (KeywurlPlugin*) sharedInstance;

- (IBAction) createKeywordSearchFromForm: (id) sender;

// Swizzling utilities
+ (BOOL) swizzleClass: (Class) aClass method: (NSString*) methodName;
+ (BOOL) swizzleClassName: (NSString*) className
				   method: (NSString*) methodName;

@end
