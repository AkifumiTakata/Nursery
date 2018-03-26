//
//  SelfReferencedObject.m
//  NurseryTests
//
//  Created by Akifumi Takata on 2018/03/26.
//  Copyright © 2018年 Nursery-Framework. All rights reserved.
//

#import "SelfReferenceObject.h"

@implementation SelfReferenceObject

+ (BOOL)automaticallyEstablishCharacter
{
    return YES;
}

+ (void)defineCharacter:(NUCharacter *)aCharacter on:(NUSandbox *)aSandbox
{
    [aCharacter addOOPIvarWithName:@"myself"];
}

- (void)encodeWithAliaser:(NUAliaser *)anAliaser
{
    [anAliaser encodeObject:myself];
}

- (id)initWithAliaser:(NUAliaser *)anAliaser
{
    [super init];
    
    myself = [[anAliaser decodeObject] retain];
    
    return self;
}

- (SelfReferenceObject *)myself
{
    return NUGetIvar(&myself);
}

- (void)setMyself:(SelfReferenceObject *)aMyself
{
    NUSetIvar(&myself, aMyself);
}

@end
