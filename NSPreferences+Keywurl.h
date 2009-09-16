#import <Cocoa/Cocoa.h>
#import "NSPreferenceModule.h"

@interface NSPreferences (KeywurlNSPreferences)

+ (void) load;
+ (id) keywurl_sharedPreferences;

@end
