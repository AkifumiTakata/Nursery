//
//  NUBranchNursery.h
//  Nursery
//
//  Created by P,T,A on 2013/06/29.
//
//

#import <Nursery/NUNursery.h>
#import <Nursery/NUMainBranchNurseryAssociation.h>

@class NUBranchNurseryAssociation, NUBranchPlayLot, NUPupilAlbum;

@interface NUBranchNursery : NUNursery
{
    NSURL *url;
    NUBranchNurseryAssociation *association;
    NUPupilAlbum *pupilAlbum;
}

- (id)initWithURL:(NSURL *)aURL association:(NUBranchNurseryAssociation *)anAssociation;

- (NSURL *)URL;

- (NSString *)name;

- (NUBranchNurseryAssociation *)association;

- (id <NUMainBranchNurseryAssociation>)mainBranchAssociationForPlayLot:(NUBranchPlayLot *)aPlayLot;

- (NUPupilAlbum *)pupilAlbum;

@end

@interface NUBranchNursery (Private)

- (void)setURL:(NSURL *)aURL;
- (void)setAssociation:(NUBranchNurseryAssociation *)anAssociation;
- (void)setPupilAlbum:(NUPupilAlbum *)aPupilAlbum;

@end