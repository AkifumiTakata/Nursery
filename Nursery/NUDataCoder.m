//
//  NUDataCoder.m
//  Nursery
//
//  Created by Akifumi Takata on 2013/11/17.
//
//

#include <stdlib.h>
#import <Foundation/NSData.h>

#import "NUDataCoder.h"
#import "NUCharacter.h"
#import "NUGarden.h"
#import "NUAliaser.h"

@implementation NUDataCoder : NUCoder

- (id)new
{
	return [NSMutableData new];
}

- (void)encode:(id)anObject withAliaser:(NUAliaser *)anAliaser
{
    [self encodeIndexedIvarsOf:anObject withAliaser:anAliaser];
}

- (void)encodeIndexedIvarsOf:(id)anObject withAliaser:(NUAliaser *)anAliaser
{
	NSMutableData *aData = anObject;
	[anAliaser encodeIndexedBytes:(NUUInt8 *)[aData bytes] count:[aData length]];
}

- (void)decode:(id)anObject withAliaser:(NUAliaser *)anAliaser
{
    [self decodeIndexedIvarsOf:anObject withAliaser:anAliaser];
}

- (void)decodeIndexedIvarsOf:(id)anObject withAliaser:(NUAliaser *)anAliaser
{
	NSMutableData *aData = anObject;
	[aData setData:[self decodeObjectWithAliaser:anAliaser]];
}

- (id)decodeObjectWithAliaser:(NUAliaser *)anAliaser
{
	NUUInt64 aLength = [anAliaser indexedIvarsSize];
	NSData *aData = nil;
	
	if (aLength)
	{
		NUUInt8 *aBytes = malloc((size_t)aLength);
		[anAliaser decodeBytes:aBytes count:aLength];
		aData = [[NSData alloc] initWithBytesNoCopy:aBytes length:(NSUInteger)aLength freeWhenDone:YES];
	}
	else
		aData = [NSData new];
    
	return [aData autorelease];
}

- (BOOL)canMoveUpObject:(id)anObject withAliaser:(NUAliaser *)anAliaser
{
    return [[anAliaser character] isMutable];
}

- (void)moveUpObject:(id)anObject withAliaser:(NUAliaser *)anAliaser
{
    if (![[anAliaser character] isMutable]) return;
    
    NSMutableData *aData = anObject;
    [aData setData:[self decodeObjectWithAliaser:anAliaser]];
    [[anAliaser garden] unmarkChangedObject:aData];
}

@end
