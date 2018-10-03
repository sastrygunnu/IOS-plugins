//
//  VGConstant.h
//  VGuard
//
//  Created by C-VKEY-1000018 on 14/5/15.
//  Copyright (c) 2015 V-Key Pte Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString * const VGuardErrorDomain;

@interface VGConstant : NSObject


typedef NS_ENUM(NSInteger, VGuardErrorCode)
{
    // firmware errors
    VGUARD_ERROR_FIRMWARE_MISSING = 20000,      // Error firmware missing,
    VGUARD_ERROR_FIRMWARE_CORRUPTED = 20001,    // Error firmware corrupted,
    
    // profile errors
    VGUARD_ERROR_PROFILE_MISSING = 20010,       // Error profile missing,
    VGUARD_ERROR_PROFILE_CORRUPTED = 20011,     // Error profile corrupted,
    VGUARD_ERROR_PROFILE_DECRYPTION = 20012,    // Error profile decryption,
    
    // signature errors
    VGUARD_ERROR_SIGNATURE_MISSING = 20020,     // Error signature missing,
    VGUARD_ERROR_SIGNATURE_CORRUPTED = 20021,   // Error signature corrupted,
    VGUARD_ERROR_SIGNATURE_DECRYPTION = 20022,  // Error signature decryption,
    VGUARD_ERROR_SIGNATURE_INVALID = 20023,     // Error invalid Android signature,

    // license, app signer errors
    VGUARD_ERROR_LICENSE_SIGNER_CERT_MISMATCH = 20032,  // signer cert mismatch
    VGUARD_ERROR_LICENSE_PACKAGE_NAME_MISMATCH = 20033, // package name mismatch
    VGUARD_ERROR_LICENSE_MISSING = 20030,               // missing license
    VGUARD_ERROR_LICENSE_CORRUPTED = 20031,             // empty license -> -1008
    VGUARD_ERROR_LICENSE_VERIFICATION = 20034,          // Licence verification faild, customerKey nill, customerId = 0, customerFeature = 0
    
    VGUARD_ERROR_HOOK_SSL_FOUND = 20060,        //  ssl hook found
    VGUARD_ERROR_HOOK_C_FUNCTION_FOUND = 20061, //  C function hook found
    
    VGUARD_ERROR_SSL_PINNING_FOUND = 20070  //  ssl Pinning found
};

@end
