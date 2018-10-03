
#import "TmbVmAppDelegate.h"
#import <InsertFramework/InsertFramework.h>

@implementation TmbVmAppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;{
    @try {
      
        [[InsertManager sharedManager] initSDK:@"15923feb76f7f8a671257dc0a17599839245bfa2617d1a1bf482cc693ea1473edf50299a3487027c604bf5e24e63fabef7bbd2c2ca1b39a39c8526a001fbf6932b132e7a4e67e13789ed5999908d1962.082b886765522de64c6f6427e1f03735.27ccd507135cd66cd9671667038f46e54fde5d38fc27cde2fb7498d9f5cc67b4"
                                   companyName: @"tmbbankthailand" initParams:nil];
       [super application:application didFinishLaunchingWithOptions:launchOptions];
        
        
    } @catch (NSException *exception) {
    }

    return YES;
}

@end
