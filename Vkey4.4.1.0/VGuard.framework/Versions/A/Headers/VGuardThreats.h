//
//  VGuardThreats.h
//  VGuard
//
//  Created by Chinwee Koh on 12/6/14.
//  Copyright (c) 2014 V-Key Pte Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol VGuardThreatsDelegate <NSObject>
@optional
-(void)vGuardScan:(NSArray*)threatsArray;
@end

@interface VGuardThreats : NSObject
@property (unsafe_unretained, nonatomic) id<VGuardThreatsDelegate> delegate;

+(id)sharedModule;
@end
