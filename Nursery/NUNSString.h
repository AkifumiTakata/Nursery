//
//  NUNSString.h
//  Nursery
//
//  Created by Akifumi Takata on 2013/11/16.
//
//

#import <Foundation/NSString.h>
#import "NUTypes.h"

@interface NSString (NUCharacter)

- (NUUInt64)indexedIvarsSize;

@end

@interface NUNSString : NSString
@end

@interface NUNSMutableString : NSMutableString
@end
