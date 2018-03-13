//
//  NUBranchNursery.m
//  Nursery
//
//  Created by Akifumi Takata on 2013/06/29.
//
//

#import "NUBranchNursery.h"
#import "NUBranchSandbox.h"
#import "NUBranchNurseryAssociation.h"
#import "NUPupilAlbum.h"
#import "NUNurseryNetClient.h"

@implementation NUBranchNursery

+ (instancetype)branchNurseryWithServiceName:(NSString *)aServiceName
{
    return [[[self alloc] initWithServiceName:aServiceName] autorelease];
}

- (instancetype)initWithServiceName:(NSString *)aServiceName
{
    if (self = [super init])
    {
        _netClient = [[NUNurseryNetClient alloc] initWithServiceName:aServiceName];
        sandbox = [[NUSandbox sandboxWithNursery:self usesGradeSeeker:YES] retain];
        pupilAlbum = [NUPupilAlbum new];
    }
    
    return self;
}

- (NUPupilAlbum *)pupilAlbum
{
    return pupilAlbum;
}

- (void)dealloc
{
    [_netClient stop];
    [_netClient release];
    [pupilAlbum release];
    
    [super dealloc];
}

@end

@implementation NUBranchNursery (Grade)

- (NUUInt64)latestGrade:(NUSandbox *)sender
{
    return [[self netClient] latestGrade];
}

- (NUUInt64)olderRetainedGrade:(NUSandbox *)sender
{
    return [[self netClient] olderRetainedGrade];
}

- (NUUInt64)retainLatestGradeBySandbox:(NUSandbox *)sender
{
    return [[self netClient] retainLatestGradeBySandboxWithID:[sender ID]];
}

- (void)retainGrade:(NUUInt64)aGrade bySandbox:(NUSandbox *)sender
{
    [[self netClient] retainGrade:aGrade bySandboxWithID:[sender ID]];
}

@end

@implementation NUBranchNursery (Testing)

- (BOOL)isMainBranch
{
    return NO;
}

@end

@implementation NUBranchNursery (Private)

- (void)setPupilAlbum:(NUPupilAlbum *)aPupilAlbum
{
    [pupilAlbum autorelease];
    pupilAlbum = [aPupilAlbum retain];
}

@end
