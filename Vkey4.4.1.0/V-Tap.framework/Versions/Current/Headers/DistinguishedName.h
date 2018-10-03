//
//  DistinguishedName.h
//  
//
//  Created by Vkey on 7/7/16.
//
//

#import <Foundation/Foundation.h>

@interface DistinguishedName : NSObject

@property (nonatomic, strong)NSString* country;
@property (nonatomic, strong)NSString* stateName;
@property (nonatomic, strong)NSString* localityName;
@property (nonatomic, strong)NSString* organizationName;
@property (nonatomic, strong)NSString* organizationUnit;
@property (nonatomic, strong)NSString* emailAddress;

-(id)init;
@end

