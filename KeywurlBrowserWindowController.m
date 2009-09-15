#include "KeywurlBrowserWindowController.h"
#include "KeywurlPlugin.h"

#include <objc/runtime.h>

@implementation NSObject (KeywurlBrowserWindowController)

// We override this method to intercept addresses at an early stage without 
// invoking Safari's fallback system. This is quicker as it avoids unnecessary 
// DNS lookups
- (void) keywurl_goToToolbarLocation: (id) sender {
    KeywurlPlugin* plugin = [KeywurlPlugin sharedInstance];
    KeywordMapper* mapper = [plugin keywordMapper];
    NSString* input = [[[self keywurl_locationFieldEditor] textStorage] string];
    if (input) {
        BOOL useDefault = NO;
        if ([input rangeOfString: @" "].location != NSNotFound ||
          [input rangeOfString: @"."].location == NSNotFound) {
            // URL contains spaces and is not a single word that contains dots, 
            // so it's pretty much guaranteed to not be a URL
            useDefault = YES;
        }
        NSString* newUrl = [mapper mapKeywordInput: input withDefault: useDefault];
        if (![input isEqualToString: newUrl]) {
			NSTextField *field;
			object_getInstanceVariable([self keywurl_locationFieldEditor],
									   "field", (void**)&field);
            [field setObjectValue: newUrl];
        }
    }
    return [self keywurl_goToToolbarLocation: sender];
}

- (LocationFieldEditor*) keywurl_locationFieldEditor {
    LocationFieldEditor *ret;
	object_getInstanceVariable(self, "_locationFieldEditor", (void**)&ret);
	return ret;
}

@end
