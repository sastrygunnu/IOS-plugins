//
//  SecureFileIO.h
//  VGuard
//
//  Created by Hong Nhat Pham on 23/10/13.
//  Copyright (c) 2013 V-Key Pte Ltd. All rights reserved.
//

#ifndef Vos_SecureFileIO_h
#define Vos_SecureFileIO_h

#ifdef __OBJC__
#import <Foundation/Foundation.h>
#endif

//Objective-C interface
#ifdef __OBJC__

__attribute__((visibility("default")))
@interface VOSSecureFileIO : NSObject
+ (int) initSecureFileIO: (NSData*) pwdArray;
+ (int) version;

//secure data IO
+ (NSData*)dataWithContentsOfFile:(NSString *)path;
+ (BOOL)writeData:(NSData*)data toFile:(NSString *)path atomically:(BOOL)useAuxiliaryFile;
+ (BOOL)writeData:(NSData*)data toFile:(NSString *)path options:(NSDataWritingOptions)writeOptionsMask error:(NSError **)error;

//secure string's data IO
+ (NSString*)stringWithContentsOfFile:(NSString *)path
                             encoding:(NSStringEncoding)enc
                                error:(NSError **)error;
+ (NSString*)stringWithContentsOfFile:(NSString *)path
                         usedEncoding:(NSStringEncoding*)enc
                                error:(NSError **)error;
+ (BOOL)writeString:(NSString*)str
             toFile:(NSString *)path
         atomically:(BOOL)useAuxiliaryFile;
+ (BOOL)writeString:(NSString*)str
             toFile:(NSString *)path
         atomically:(BOOL)useAuxiliaryFile
           encoding:(NSStringEncoding)enc
              error:(NSError **)error;

@end

#endif//__OBJC__

#endif
