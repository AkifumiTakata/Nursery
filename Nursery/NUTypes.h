/*
 *  NUTypes.h
 *  Nursery
 *
 *  Created by Akifumi Takata on 10/09/09.
 *  Copyright 2010 Nursery-Framework. All rights reserved.
 *
 */

#include <stdint.h>
#include <CoreGraphics/CGGeometry.h>

typedef uint8_t		NUUInt8;
typedef uint16_t	NUUInt16;
typedef uint32_t	NUUInt32;
typedef uint64_t    NUUInt64;

typedef int8_t	    NUInt8;
typedef int16_t	    NUInt16;
typedef int32_t		NUInt32;
typedef int64_t     NUInt64;
typedef float	    NUFloat;
typedef double	    NUDouble;

typedef NUInt32 NUInt;

typedef NUUInt8 NUObjectFormat;
typedef NUUInt8 NUIvarType;

extern const NUUInt64 NUUInt64Max;
extern const NUUInt32 NUUInt32Max;

extern const NUUInt32 NUNotFound32;
extern const NUUInt64 NUNotFound64;

typedef struct _NURegion {
	NUUInt64 location;
	NUUInt64 length;
} NURegion;

typedef struct _NUBellBall {
    NUUInt64 oop;
    NUUInt64 grade;
} NUBellBall;

extern const NUBellBall NUNotFoundBellBall;

typedef CGPoint NUPoint;
typedef CGSize  NUSize;
typedef CGRect  NURect;

typedef enum _NUComparisonResult {
    NUOrderedAscending = -1L,
    NUOrderedSame,
    NUOrderedDescending
} NUComparisonResult;
