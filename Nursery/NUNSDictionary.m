//
//  NUNSDictionary.m
//  Nursery
//
//  Created by Akifumi Takata on 2013/11/16.
//
//

#import "NUNSDictionary.h"
#import "NUCharacter.h"
#import "NUGarden.h"
#import "NUDictionaryCoder.h"

@implementation NSDictionary (NUCharacter)

- (Class)classForNursery
{
    if ([[self classForCoder] isSubclassOfClass:[NSMutableDictionary class]])
        return [NUNSMutableDictionary class];
    return [NUNSDictionary class];
}

- (NUUInt64)indexedIvarsSize
{
	return sizeof(NUUInt64) * [self count] * 2;
}

@end

@implementation NUNSDictionary

+ (void)defineCharacter:(NUCharacter *)aCharacter on:(NUGarden *)aGarden
{
    [aCharacter setIsMutable:NO];
    [aCharacter setFormat:NUIndexedIvars];
	[aCharacter setCoderClass:[NUDictionaryCoder class]];
}

@end

@implementation NUNSMutableDictionary

+ (void)defineCharacter:(NUCharacter *)aCharacter on:(NUGarden *)aGarden
{
    [aCharacter setFormat:NUIndexedIvars];
	[aCharacter setCoderClass:[NUDictionaryCoder class]];
}

@end
