//
//  NUGardenSeeker.m
//  Nursery
//
//  Created by Akifumi Takata on 2013/08/31.
//
//

#import <Foundation/NSArray.h>
#import <Foundation/NSThread.h>

#import "NUGardenSeeker.h"
#import "NUGarden.h"
#import "NUGarden+Project.h"
#import "NUNurseryRoot.h"
#import "NUBell.h"
#import "NUBell+Project.h"
#import "NUBellBall.h"
#import "NUMainBranchAperture.h"
#import "NUBranchAperture.h"
#import "NUMainBranchGardenSeeker.h"
#import "NUBranchGardenSeeker.h"
#import "NUU64ODictionary.h"
#import "NUQueue.h"

@implementation NUGardenSeeker

+ (id)gardenSeekerWithGarden:(NUGarden *)aGarden
{
    return [[[self alloc] initWithGarden:aGarden aperture:[[[aGarden class] apertureClass] apertureWithNursery:[aGarden nursery] garden:aGarden]] autorelease];
}

+ (id)gardenSeekerWithGarden:(NUGarden *)aGarden aperture:(NUAperture *)aAperture
{
    return [[[self alloc] initWithGarden:aGarden aperture:aAperture] autorelease];
}

- (id)initWithGarden:(NUGarden *)aGarden aperture:(NUAperture *)anAperture
{
    if (self = [super initWithGarden:aGarden])
    {
        aperture = [anAperture retain];
        bellsLock = [NSRecursiveLock new];
        bells = [NUQueue new];
        lock = [NSRecursiveLock new];
    }
    
    return self;
}

- (void)dealloc
{
    [aperture release];
    [bellsLock release];
    [bells release];
    [lock release];
    
    [super dealloc];
}

- (void)lock
{
    [lock lock];
}

- (void)unlock
{
    [lock unlock];
}

- (void)pushRootBell:(NUBell *)aBell
{
    [bellsLock lock];
    
    [[self bells] removeAll];
    [self pushBell:aBell];
    
    [bellsLock unlock];
}

- (void)pushBellIfNeeded:(NUBell *)aBell
{
    if (aBell && [aBell gradeForGardenSeeker] < [self grade])
        [self pushBell:aBell];
}

- (NUQueue *)bells
{
    return bells;
}

- (NUBell *)popBell
{
    NUBell *aBell = nil;
    
    [bellsLock lock];
    
    aBell = [[self bells] pop];
    
    [bellsLock unlock];
    
    return aBell;
}

- (void)pushBell:(NUBell *)aBell
{
    [bellsLock lock];
    
    [[self bells] push:aBell];
    
    [bellsLock unlock];
}

- (NUAperture *)aperture
{
    return aperture;
}

- (NUUInt64)grade
{
    return [[self garden] grade];
}

- (void)process
{
    while (![self shouldStop])
    {
        [self lock];
        
        NUBell *aBell = [self popBell];

        if (aBell)
            [self seekObjectFor:aBell];
        else
        {
            [self collectGrade];
            [self setShouldStop:YES];
        }

        [self unlock];
    }
}

- (void)seekObjectFor:(NUBell *)aBell
{    
    if ([aBell gradeForGardenSeeker] == [self grade]) return;
    
    [aBell setGradeForGardenSeeker:[self grade]];
    [self seekIvarsOfObjectFor:aBell];
}

- (void)seekIvarsOfObjectFor:(NUBell *)aBell
{
}

- (void)collectGrade
{
    @try {
        [[self garden] lock];
        
        NUU64ODictionary *aCopyOfBells = [[self garden] copyBells];
        NSMutableArray *aBells = [NSMutableArray array];
        
        [aCopyOfBells enumerateKeysAndObjectsUsingBlock:^(NUUInt64 aKey, NUBell *aBell, BOOL *stop)
        {
            if ([aBell gradeForGardenSeeker] < [self grade])
                [[self garden] invalidateBell:aBell];
            else
                [aBells addObject:aBell];
        }];
        
        [aCopyOfBells release];

        [[self garden] collectGradeLessThan:[self grade]];
    }
    @finally {
        [[self garden] unlock];
    }
}

- (void)bellDidLoadIvars:(NUBell *)aBell
{
    if ([aBell gradeForGardenSeeker] == [self grade])
    {
        [aBell setGradeForGardenSeeker:NUNilGrade];
        [self pushBellIfNeeded:aBell];
    }
}

- (void)objectDidLoadIvars:(id)anObject
{
    [self bellDidLoadIvars:[[self garden] bellForObject:anObject]];
}

@end