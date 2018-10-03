//
//  VTapManager.h
//  VTap
//
//  Created by V-Key on 5/3/15.
//  Copyright (c) 2015 vkey. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "DistinguishedName.h"
#import "ResultCode.h"

@protocol VTapManagerDelegate <NSObject>
@required
-(void) didStartVTap:(int)statusCode;
@end

@interface VTapManager : NSObject {
    id <VTapManagerDelegate> delegate;
}
@property (retain) id delegate;


#define PKI_FUNC_ID_AUTH                  0
#define PKI_FUNC_ID_VMESSAGE              1
#define PKI_FUNC_ID_DOCSIGN               2

#define ASP_CERT                            @"ASP_CERT"
#define SMP_CERT                            @"SMP_CERT"
#define ASP_DOC_CERT                        @"ASP_DOC_CERT"
#define READ_MSG                            @"READ_MSG"
    
#define SEED_TOTP1                  1
#define SEED_TOTP2                  2
#define SEED_CR                     3
#define SEED_TXS                    4
    

/*========================= Generic VKEY API Starts =========================*/

// Generic : Set Up VKey Components API
+(VTapManager *) sharedInstance;
-(void)setHostName:(NSString *) provServer vtapServer:(NSString *) vtapServer ;
-(void)setupVTap;
-(NSString*)getDFPHash;
-(BOOL)isProvisioningDone;
-(NSArray*)getAllProvisionedTokens;

//-(int)setDefaultToken:(NSString *)TokenSerial;
//-(NSString *)getDefaultToken;

-(TokenType)getTokenType:(NSString *)tokenSerial;

// Generic : Lifecycle Actions API
-(void)onResume;
-(void)onPause;
-(void)onDestroy;

// Generic : Troubleshooting Logs API
-(NSString *)getTroubleshootingId;
-(int)sendTroubleshootingLogs;

//  Generic : Device Check API
-(int)checkDeviceCompatibility;
-(int)sendDeviceInfo: (NSString *) deviceInfo status:(int) status;

/*========================= Generic VKEY API Ends =========================*/

// Luke Pham added for new rest APIs
-(int)setAdditionalData:(NSString *)data additionalDataType:(NSString *)dataType;
-(int)setMessageTypeData:(NSString *)data;
-(NSString *)getAdditionalData:(NSString *)dataType;
-(int)disableAdditionalData:(NSString *)dataType;

/*========================= OTP TA API Starts =========================*/

// OTP TA: Transaction API
-(int)setOtpLength:(int)length;
-(NSArray*)generateTOTP: (int)num;
-(NSArray*)generateCR:(NSString*)crMsg;
-(NSArray*)generateTxS:(NSString*)account amount: (NSString*)amount;

-(NSString*)getTokenSerial;

/*========================= OTP TA API Ends =========================*/

/*========================= Multiple TA API Starts =========================*/

//  Multiple(OTP/PKC) TA : Provisioning API
-(BOOL)validateChecksum:(NSArray *)provisioningInfo;
-(int)getLoadAckTokenFirmware:(NSArray*) provisioningInfo ;
-(int)loadTokenFirmware:(NSString *)tokenSerial APIN:(NSString *) aPIN downloadFilePath:(NSString *) filePath;

-(int)removeTokenFirmware:(NSString *)tokenSerial;

-(int)loadToken:(NSString *)tokenSerial;
-(int)unloadToken:(NSString *)tokenSerial;
-(NSString*)getTokenFirmwareVersion:(NSString *)tokenSerial;

//  Multiple TA: Token PIN Management API
-(BOOL)isTokenRegistered:(NSString *)tokenSerial;
-(int)createTokenPIN: (NSString *)pin withTokenSerial:(NSString *)tokenSerial;
-(int)checkTokenPIN: (NSString *)pin remember:(BOOL)rememberPin withTokenSerial:(NSString *)tokenSerial;
-(int)checkTokenPIN: (NSString *)pin remember:(BOOL)rememberPin withTokenSerial:(NSString *)tokenSerial andSeed:(int)seed;
-(BOOL)isTokenPINRemembered:(NSString *)tokenSerial;
-(int)changeTokenPIN: (NSString *)oldPin withNewPIN:(NSString *)newPin withTokenSerial:(NSString *)tokenSerial;

/*========================= Multiple TA API Ends =========================*/

/*========================= PKI API Starts =========================*/
//PKI TA -  Registration
-(void)setPKIHostName:(NSString *)pkiServer;
-(NSString *)getPKITokenSerial;

// Register APNs Token for Push Notification
-(int)pushNotificationRegister:(NSString *)userId deviceId:(NSString *)deviceId andToken:(NSString *)pushToken;
-(int)triggerCertPushNotification:(int)functionID;
-(NSString *)getRegisteredUserId;
-(NSString *)getRegisteredDeviceId;

// PKI Generate ECC Key Pair and Send to server
-(int)generateCsrAndSend:(int)functionId distinguishedName:(DistinguishedName *) distinguishedName pin:(NSString *)pin andRememberPin:(BOOL)rememberPin;
-(int)generateCsrAndSendSync:(int)functionId distinguishedName:(DistinguishedName *) distinguishedName pin:(NSString *)pin andRememberPin:(BOOL)rememberPin;
-(int)pkiCertDownload:(int)functionId  messageId:(NSString *)messageId andMessageType:(NSString *)messageType;

// PKI PIN Management
-(BOOL)isPKIFunctionRegistered:(int)functionId;
-(BOOL)isPKIFunctionPinRemembered:(int)functionId;
-(int)pkiFunctionCheckPin:(int)functionId withPin:(NSString *)pin andRememberPin:(BOOL) rememberPin;
-(int)pkiFunctionChangePIN:(int)functionId oldPin:(NSString *)oldPin withNewPIN:(NSString *)newPin;

// PKI Signing
-(int)pkiFunctionAuthenticate:(NSString *)messageId dataToBeSigned:(NSString *)dataToBeSigned andReject:(BOOL)reject;
-(int)pkiFunctionDocSign:(NSString *)messageId dataToBeSigned:(NSString *)dataToBeSigned andReject:(BOOL)reject;

//V-Message
-(NSString *)vMessageDecrypt:(NSData *)encryptedMsg;
-(NSArray *)vMessageDownload:(NSString *)messageId messageType:(NSString *)messageType andMessageFlag:(NSString *)messageFlag;
-(int)vMessageAck:(NSString *)messageId;

//Remove PKI Function KeyPair
-(void)removePKIFunction:(int)functionId;
/*========================= PKC TA API Ends =========================*/


/*========================= Netrust Customization API Starts =========================*/
-(NSArray *)generateEccCsrWithAlias:(NSString *)inputString andKeyAlias:(int)keyAlias;
-(int)deleteEccKeyWithAlias:(int)keyAlias;
-(NSArray *)eccSignWithAlias:(NSData *)inputData andKeyAlias:(int)keyAlias;
-(NSArray *)eccSha1SignWithAlias:(NSData *)inputData andKeyAlias:(int)keyAlias;
-(NSArray *)eccSha256SignWithAlias:(NSData *)inputData andKeyAlias:(int)keyAlias;
-(int)eccVerifyWithAlias:(NSData *)inputData andSignature:(NSData *)signature andKeyAlias:(int)keyAlias;
-(int)eccSha1VerifyWithAlias:(NSData *)inputData andSignature:(NSData *)signature andKeyAlias:(int)keyAlias;
-(int)eccSha256VerifyWithAlias:(NSData *)inputData andSignature:(NSData *)signature andKeyAlias:(int)keyAlias;
-(int)addCertWithAlias:(NSArray *)certArray andCertAlias:(int)certAlias;
-(NSArray *)getCertWithAlias:(int)certAlias;
-(int)deleteCertWithAlias:(int)certAlias;
-(int)isKeyAlias:(int)keyAlias;
-(int)isCertAlias:(int)certAlias;
-(NSArray *)getKeyAliases;
-(NSArray *)getCertAliases;
-(int)resetTokenFirmware;
/*========================= Netrust Customization API Ends =========================*/
@end
