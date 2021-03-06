//
//  NUDefaultComparator.h
//  Nursery
//
//  Created by Akifumi Takata on 2013/01/26.
//
//

#import "NUComparator.h"
#import "NUCoding.h"

@class NUBell;

@interface NUDefaultComparator : NSObject <NUComparator>
{
    NUBell *bell;
}

- (NSComparisonResult)compareObject:(id)anObject1 toObject:(id)anObject2;

@end

@interface NUDefaultComparator (Coding) <NUCoding>
@end
