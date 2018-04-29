//
//  NUAliaser.h
//  Nursery
//
//  Created by Akifumi Takata on 11/02/05.
//  Copyright 2011 Nursery-Framework. All rights reserved.
//

#import <Foundation/NSRange.h>
#import <Foundation/NSGeometry.h>
#import <Nursery/NUTypes.h>

@class NSMutableArray;
@class NUGarden, NUIndexArray, NUBell, NUCharacter, NUQueue;

extern NSString *NUObjectLocationNotFoundException;
extern NSString *NUBellBallNotFoundException;
extern NSString *NUAliaserCannotEncodeObjectException;
extern NSString *NUAliaserCannotDecodeObjectException;

@interface NUAliaser : NSObject
{
	NUGarden *garden;
	NSMutableArray *contexts;
	NSMutableArray *roots;
	NUQueue *objectsToEncode;
    NSMutableArray *encodedPupils;
	NUIndexArray *rootOOPs;
}
@end

@interface NUAliaser (Initializing)

+ (id)aliaserWithGarden:(NUGarden *)aGarden;

- (id)initWithGarden:(NUGarden *)aGarden;

@end

@interface NUAliaser (Accessing)

- (NUGarden *)garden;

- (NUUInt64)indexedIvarOffset;
- (NUUInt64)indexedIvarsSize;
- (NUCharacter *)character;
- (NUUInt64)rootOOP;


@end

@interface NUAliaser (Testing)

- (BOOL)containsValueForKey:(NSString *)aKey;

@end

@interface NUAliaser (Encoding)

- (void)encodeObject:(id)anObject;

- (void)encodeInt8:(NUInt8)aValue;
- (void)encodeInt16:(NUInt16)aValue;
- (void)encodeInt32:(NUInt32)aValue;
- (void)encodeInt64:(NUInt64)aValue;

- (void)encodeUInt8:(NUUInt8)aValue;
- (void)encodeUInt16:(NUUInt16)aValue;
- (void)encodeUInt32:(NUUInt32)aValue;
- (void)encodeUInt64:(NUUInt64)aValue;
- (void)encodeUInt64Array:(NUUInt64 *)aValues count:(NUUInt64)aCount;

- (void)encodeFloat:(NUFloat)aValue;
- (void)encodeDouble:(NUDouble)aValue;
- (void)encodeBOOL:(BOOL)aValue;

- (void)encodeRegion:(NURegion)aValue;
- (void)encodeRange:(NSRange)aValue;
- (void)encodePoint:(NSPoint)aValue;
- (void)encodeSize:(NSSize)aValue;
- (void)encodeRect:(NSRect)aValue;

- (void)encodeObject:(id)anObject forKey:(NSString *)aKey;

- (void)encodeInt8:(NUInt8)aValue forKey:(NSString *)aKey;
- (void)encodeInt16:(NUInt16)aValue forKey:(NSString *)aKey;
- (void)encodeInt32:(NUInt32)aValue forKey:(NSString *)aKey;
- (void)encodeInt64:(NUInt64)aValue forKey:(NSString *)aKey;

- (void)encodeUInt8:(NUUInt8)aValue forKey:(NSString *)aKey;
- (void)encodeUInt16:(NUUInt16)aValue forKey:(NSString *)aKey;
- (void)encodeUInt32:(NUUInt32)aValue forKey:(NSString *)aKey;
- (void)encodeUInt64:(NUUInt64)aValue forKey:(NSString *)aKey;

- (void)encodeFloat:(NUFloat)aValue forKey:(NSString *)aKey;;
- (void)encodeDouble:(NUDouble)aValue forKey:(NSString *)aKey;
- (void)encodeBOOL:(BOOL)aValue forKey:(NSString *)aKey;

- (void)encodeRegion:(NURegion)aValue forKey:(NSString *)aKey;
- (void)encodeRange:(NSRange)aValue forKey:(NSString *)aKey;
- (void)encodePoint:(NSPoint)aValue forKey:(NSString *)aKey;
- (void)encodeSize:(NSSize)aValue forKey:(NSString *)aKey;
- (void)encodeRect:(NSRect)aValue forKey:(NSString *)aKey;

- (void)encodeIndexedIvars:(id *)anIndexedIvars count:(NUUInt64)aCount;
- (void)encodeIndexedBytes:(const NUUInt8 *)aBytes count:(NUUInt64)aCount;
- (void)encodeIndexedBytes:(const NUUInt8 *)aBytes count:(NUUInt64)aCount at:(NUUInt64)anOffset;

@end

@interface NUAliaser (Decoding)

- (id)decodeObject;
- (id)decodeObjectReally;

- (NUInt8)decodeInt8;
- (NUInt16)decodeInt16;
- (NUInt16)decodeInt32;
- (NUInt64)decodeInt64;

- (NUUInt8)decodeUInt8;
- (NUUInt16)decodeUInt16;
- (NUUInt32)decodeUInt32;
- (NUUInt64)decodeUInt64;
- (void)decodeUInt64Array:(NUUInt64 *)aValues count:(NUUInt64)aCount;

- (NUFloat)decodeFloat;
- (NUDouble)decodeDouble;
- (BOOL)decodeBOOL;

- (NURegion)decodeRegion;
- (NSRange)decodeRange;
- (NSPoint)decodePoint;
- (NSSize)decodeSize;
- (NSRect)decodeRect;

- (id)decodeObjectForKey:(NSString *)aKey;

- (NUInt8)decodeInt8ForKey:(NSString *)aKey;
- (NUInt16)decodeInt16ForKey:(NSString *)aKey;
- (NUInt32)decodeInt32ForKey:(NSString *)aKey;
- (NUInt64)decodeInt64ForKey:(NSString *)aKey;

- (NUUInt8)decodeUInt8ForKey:(NSString *)aKey;
- (NUUInt16)decodeUInt16ForKey:(NSString *)aKey;
- (NUUInt32)decodeUInt32ForKey:(NSString *)aKey;
- (NUUInt64)decodeUInt64ForKey:(NSString *)aKey;

- (NUFloat)decodeFloatForKey:(NSString *)aKey;
- (NUDouble)decodeDoubleForKey:(NSString *)aKey;
- (BOOL)decodeBOOLForKey:(NSString *)aKey;

- (NURegion)decodeRegionForKey:(NSString *)aKey;
- (NSRange)decodeRangeForKey:(NSString *)aKey;
- (NSPoint)decodePointForKey:(NSString *)aKey;
- (NSSize)decodeSizeForKey:(NSString *)aKey;
- (NSRect)decodeRectForKey:(NSString *)aKey;

- (void)decodeIndexedIvar:(id *)anIndexedIvars count:(NUUInt64)aCount really:(BOOL)aReallyDecode;
- (void)decodeBytes:(NUUInt8 *)aBytes count:(NUUInt64)aCount;
- (void)decodeBytes:(NUUInt8 *)aBytes count:(NUUInt64)aCount at:(NUUInt64)aLocation;

- (void)moveUp:(id)anObject;
- (void)moveUp:(id)anObject ignoreGradeAtCallFor:(BOOL)anIgnoreFlag;

@end

