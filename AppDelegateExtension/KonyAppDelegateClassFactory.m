//
//  KonyAppDelegateClassFactory.m
//  VM
//
//
//

#import "KonyAppDelegateClassFactory.h"

#import "CustomVMAppDelegate.h"
#import "TmbVmAppDelegate.h"

@implementation KonyAppDelegateClassFactory

+(Class)appDelegateClass
{
    return [TmbVmAppDelegate class];
}

@end

