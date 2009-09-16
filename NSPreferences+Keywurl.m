#import "NSPreferences+Keywurl.h"
#import "KeywurlPreferences.h"
#import "KeywurlPlugin.h"

#import "objc/runtime.h"

@implementation NSPreferences (KeywurlNSPreferences)

+ (void) load
{	
	// Class method -> target should be metaclass
	[KeywurlPlugin swizzleClass: object_getClass(self) method: @"sharedPreferences"];
}

+ (id) keywurl_sharedPreferences
{
	static BOOL	added = NO;
	id preferences = [self keywurl_sharedPreferences];
	if (preferences != nil && !added)
	{
		added = YES;
		[preferences addPreferenceNamed: @"Keywurl" owner: [KeywurlPreferences sharedInstance]];
	}	
	return preferences;
}

@end
