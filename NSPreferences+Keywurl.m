#import "NSPreferences+Keywurl.h"
#import "KeywurlPreferences.h"

#import "JRSwizzle.h"
#import <objc/runtime.h>

@implementation NSPreferences (KeywurlNSPreferences)

+ (void) load
{
//	[NSPreferences_Keywurl poseAsClass: [NSPreferences class]];
	
	// Class method -> target should be metaclass
	NSError *err = nil;
	[object_getClass(self) jr_swizzleMethod: @selector(sharedPreferences)
								 withMethod: @selector(keywurl_sharedPreferences)
									  error: &err];
	if (err) NSLog(@"ERROR: %@", [err description]);
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
