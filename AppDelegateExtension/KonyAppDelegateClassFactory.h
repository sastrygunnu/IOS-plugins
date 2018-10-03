//
//  KonyAppDelegateClassFactory.h
//  VM
//
//
//

#import <Foundation/Foundation.h>

@interface KonyAppDelegateClassFactory : NSObject

/**
 @return Returns the Custom Application Delegate Class one wants to make as the application's delegate.
 
 @note The custom Application Delegate should extend from <code>VMAppDelegate</code> (Kony's default Application Delegate). It should also invoke the parent implementation of the overridden iOS <code>UIApplicationDelegate</code> methods WITHOUT FAIL for the kony application to work properly.
 */
+(Class)appDelegateClass;

@end
