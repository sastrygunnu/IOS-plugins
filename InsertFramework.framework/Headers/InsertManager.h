//
//  InsertManager.h
//  InsertFramework
//

#import <Foundation/Foundation.h>

@class InsertInitParams;

NS_ASSUME_NONNULL_BEGIN

/**
 *  The SDK will post the following notifications on initialization.
 *  The notifications are posted to the main thread
 *
 *  This notification is sent out after the SDK has successfully initialized
 */
extern NSString *const kIIODidSuccessfullyInitializeSDKNotification;

/**
 *  This notification is sent out when an error occurs during initialization of the SDK
 */
extern NSString *const kIIOErrorInitializeSDKNotification;

/**
 *  InsertManager. Handles initialization of the Insert SDK.
 */
@interface InsertManager : NSObject

/**
 *  Use [InsertManager sharedManager] instead
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 *  The shared instance of the InsertManager
 */
+ (instancetype)sharedManager;

/**
 *  Call this method on the sharedManger with your application key and company name
 *
 *  @param appKey The app key for your account
 *  @param companyName The company name as defined in your account
 *  @param initParams @code(nullable)@endcode Extra initialize parameters (e.g. account id, visitor id...).
 */
- (void)initSDK:(nonnull NSString *)appKey companyName:(nonnull NSString *)companyName initParams:(nullable InsertInitParams *)initParams;

/**
 *  Called from your app delegate when launched from a deep link containing an insert pairing URL
 *  @warning This method should always be called after initSDK: with your application key
 *  @param url The pairing URL
 */
- (void)initWithUrl:(NSURL *)url;

/**
 * Must be called <b>after</b> the SDK was initialized.
 * @brief Clears the current visitor.
 */
- (void)clearVisitor;

/**
 * Must be called <b>after</b> the SDK was initialized.
 * @brief Sets a new visitor.
 * @param visitorId The visitor's ID.
 * @param accountId The account's ID.
 */
- (void)setVisitor:(nullable NSString *)visitorId accountId:(nullable NSString *)accountId;

/**
 Stops the SDK. The SDK will invalidate all current inserts.
 */
- (void)stop;

/**
 *  Called from your app delegate [appDelegate application:didReceiveRemoteNotification:] (or variants) to notify the insert SDK that a push was received
 *  This is required for push based inserts
 *
 *  @param userInfo The user info object passed from the push notification
 */
- (void)didReceiveRemoteNotification:(NSDictionary *)userInfo;

/**
 *  Calling this method will forcefully close any currently visible inserts
 */
- (void)dismissVisibleInserts;

/**
 *  Called from host app for custom event occurring.
 *
 *  @param eventName - The event name that was selected by the host app
 *  @param params - A dictionary of parameters defined by the host app for checking against pre-defined conditions
 *
 */
- (void)eventOccurred:(NSString *)eventName params:(nullable NSDictionary<NSString *, NSString *> *)params;

/**
 * Set a user attribute value for a given attribute name.
 * These attributes are used by Insert for creating audiences or reporting analytics.
 * For instance you might want to provide an attribute on the user's age or if the user is logged into a service.
 * @code [[InsertManager sharedManager] setUserAttribute:@(YES) forKey:@"LoggedIn"]
 * You can provide multiple user attributes to the initSDK method call
 * or supply a dictionary of attributes 
 * @code [InsertManager sharedManager].userAttributes = @{@"attribute1" :@"value1", ....};
 
 * @param attributeValue The attribute value
 * @param attributeName The attribute name
 */
- (void)setUserAttributeValue:(NSString *)attributeValue forKey:(NSString *)attributeName;

/**
 Returns the user attribute value for a given key

 @param attributeName The attribute name
 @return The attribute value
 */
- (NSString *)attributeValueForKey:(NSString *)attributeName;

/**
 * Call to pause guide showing.
 */
- (void)pauseGuides;

/**
 * Called in order to resume guide showing.
 */
- (void)resumeGuides;

/**
 *  The app key used when initializing the SDK.
 */
@property(nonatomic, readonly) NSString *appKey;

/**
 *  The company name used when initializing the SDK.
 */
@property(nonatomic, readonly) NSString *companyName;

/**
 *  Provide user attributes to the Insert SDK.
 */
@property(nonatomic, strong, nullable) NSDictionary *userAttributes;

/**
 *  Provide a visitor id to the Insert SDK.
 */
@property(nonatomic, strong, readonly, nullable) NSString *visitorId;

/**
 *  Provide a account id to the Insert SDK.
 */
@property(nonatomic, strong, readonly, nullable) NSString *accountId;

/**
 * Provide a device token to the insert SDK.
 */
@property(nonatomic, strong, nullable) NSData *pushId;

/**
 *  The internal device ID used by the Insert SDK. This value will not change if setting a visitor id.
 */
@property(nonatomic, readonly) NSString *insertDeviceUserId;

/**
 * Holds whether the guides are currently paused or not.
 */
@property(atomic, readonly) BOOL areGuidesPaused;

@end

NS_ASSUME_NONNULL_END


