
#import "CustomVMAppDelegate.h"

@implementation CustomVMAppDelegate


/*Generated code please DO NOT remove*/
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
  if ([WCSession isSupported]) {
      self.session = [WCSession defaultSession];
      self.session.delegate = self;
      [self.session activateSession];
  }
  return [super application:application didFinishLaunchingWithOptions:launchOptions];
}


/*Generated code please DO NOT remove*/
- (void)session:(WCSession *)session didReceiveMessage:(NSDictionary<NSString *, id> *)message replyHandler:(void(^)(NSDictionary<NSString *, id> *replyMessage))replyHandler{
  [super callOnWatchRequestForSession:session withMessage:message andHandler:replyHandler];
}

@end

