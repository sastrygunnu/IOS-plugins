//
// Created by Assaf Gamliel on 10/1/17.
// Copyright (c) 2017 Avner Barr. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface InsertInitParams : NSObject

/** @brief The visitor's id */
@property (nonatomic, copy, nullable) NSString *visitorId;

/** @brief The account's id */
@property (nonatomic, copy, nullable) NSString *accountId;

/** @brief The attributes that are used by Insert for creating audiences or reporting analytics. */
@property (nonatomic, copy, nullable) NSDictionary *userAttributes;

@end
