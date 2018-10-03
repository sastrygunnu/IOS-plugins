//
//  VGuardManager.h
//  VGuard
// 
//  Copyright (c) 2012 V-Key Pte Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    VGUARD_UNSAFE=0,
    VGUARD_SAFE,
    VGUARD_UNDETERMINE
}   VGUARD_STATUS;

typedef enum {
    VOS_NOTOK=0,
    VOS_OK
}   VOS_STATUS;


@protocol VGuardManagerProtocol <NSObject>
@required

/**
 * Discussion: status of VOS, error if any failure
 */
-(void)statusVOS:(VOS_STATUS)status withError:(NSError *)error;


/**
 * Discussion: status of Vguard, error if any failure
 */
-(void)statusVGuard:(VGUARD_STATUS)status withError:(NSError *)error;


/**
 * @discussion Tells the client that the V-Guard initialization was successful or not.
 * @param status A BOOL value indicating the V-Guard initialization status. Status is YES if V-Guard initialization was successful. Otherwise, status is NO.
 * @param error NSError if there is any error during initialization. Otherwise, error is Nil.
 */
- (void)vGuardDidFinishInitializing:(BOOL)status withError:(NSError *)error;

/**
 * Discussion: SSL hooking or pinning detection
 */
-(void)sslErroDetected:(NSError *)error;

@end

@interface VGuardManager : NSObject 
@property (unsafe_unretained, nonatomic) id<VGuardManagerProtocol> delegate;
@property (assign, nonatomic) BOOL isDebug; // Set debug to TRUE during development set debug to FALSE for distribution
@property (assign, nonatomic) BOOL enableSSLPinning; // enable SSL Pinning checking, default is 'TRUE', SSL Pinning is enforce


/**
 * Create a VGuardManager instance
 *
 * Parameters: none
 *
 * Return Value: an instance of VGuardManager
 *
 * Discussion:
 */
+ (VGuardManager *)sharedVGuardManager;


/**
 * Create a VGuardManager initialization
 *
 * Parameters: none
 *
 * Return Value: YES if VGuardManager initialization success
 *
 * Discussion:
 */
- (BOOL)initializeVGuard;


/**
 * Start the VGuard scanning
 *
 * Parameters: none
 *
 * Return Value: status from delegate result
 *
 * Discussion: start the VGuard scanning
 */
- (void)start;

/**
 * Get Customer ID
 * 
 * Parameters: none
 * 
 * Return Value: CustomerID if VOS started Sucsessfully else return nill
 *
 * Discussion: Call this method after started the VOS Sucsessfully
 */
- (NSString * )getCustomerID;


/**
 * Get Password
 *
 * Parameters: none
 *
 * Return Value: Password if VOS started Sucsessfully else return nil
 *
 * Discussion: Call this method after started the VOS Sucsessfully
 */
- (NSString *)getPassword;


/**
 * Lock VOS
 *
 * Parameters: none
 *
 * Return Value:
 *
 * Discussion: Its stop the VOS and coulden't do VOS related stuff
 */
- (int)lockVOS;


/**
 * Encrypt Data
 *
 * Parameters: Data to encrypt
 *
 * Return Value: Encrypted Data and error if encryption failed
 *
 * Discussion: to string encoding convert it to NSData ([@"StringToEncode" dataUsingEncoding:NSUTF8StringEncoding];)
 */
- (NSData *)getEncryptData:(NSData *)data error:(NSError **)error;



/**
* Decrypt Data
*
* Parameters: Data to Decrypt
*
* Return Value: Decrypted Data and error if decryption failed
*
* Discussion: to string decoding use bellow practice
*
* NSString *decryptedString=[NSString stringWithUTF8String:[decryptedData bytes]];
* if (!decryptedString) {
*   decryptedString=[[NSString alloc] initWithData:decryptedData encoding:NSUTF8StringEncoding];
* }
*
*/
- (NSData *)getDecryptData:(NSData *)data error:(NSError **)error;


/**
 * Encrypt String
 *
 * Parameters: String to encrypt
 *
 * Return Value: Encrypted string and nil if encryption failed
 *
 * Discussion:
 */
- (NSString *)encryptString:(NSString *)string;



/**
 * Decrypt String
 *
 * Parameters: String to Decrypt
 *
 * Return Value: Decrypted string and nill if decryption failed
 *
 * Discussion:
 */
- (NSString *)decryptString:(NSString *)string;


/**
 * Troubleshooting ID
 *
 * Parameters: none
 *
 * Return Value: Troubleshooting ID
 *
 * Discussion:
 *  
 */
- (NSString *)getDFPHashHash;

/**
 * VGuard Version Information
 *
 * Parameters: none
 *
 * Return Value: VGuard Version Info
 *
 * Discussion:
 *
 */
- (NSString *)getVGuardVersionInformation;

@end
