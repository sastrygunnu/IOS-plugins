
#import "VMAppDelegate.h"
#import <WatchConnectivity/WCSession.h>

@interface CustomVMAppDelegate : VMAppDelegate <WCSessionDelegate>
@property (nonatomic, retain)WCSession *session;
@end

