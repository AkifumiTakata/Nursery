//
//  NUOpaqueBPlusTree.h
//  Nursery
//
//  Created by Akifumi Takata on 10/09/09.
//  Copyright 2010 Nursery-Framework. All rights reserved.
//

#import <Foundation/NSObject.h>
#import "NUTypes.h"

@class NUOpaqueBPlusTreeNode, NUOpaqueBPlusTreeBranch, NUOpaqueBPlusTreeLeaf, NUMainBranchNursery, NUPages, NUPage, NUOpaqueArray, NUSpaces, NUU64ODictionary;

@interface NUOpaqueBPlusTree : NSObject
{
	NUOpaqueBPlusTreeNode *root;
	NUUInt32 level;
	NUUInt32 keyLength;
	NUUInt32 leafValueLength;
	NUSpaces *spaces;
	NUUInt64 rootLocation;
	NUU64ODictionary *nodeDictionary;
}
@end

@interface NUOpaqueBPlusTree (InitializingAndRelease)

- (id)initWithKeyLength:(NUUInt32)aKeyLength leafValueLength:(NUUInt32)aLeafValueLength rootLocation:(NUUInt64)aRootLocation on:(NUSpaces *)aSpaces;

@end

@interface NUOpaqueBPlusTree (Accessing)

- (NUOpaqueBPlusTreeNode *)root;
- (void)setRoot:(NUOpaqueBPlusTreeNode *)aRoot;
- (NUOpaqueBPlusTreeNode *)loadRoot;

- (NUMainBranchNursery *)nursery;
- (NUSpaces *)spaces;
- (NUPages *)pages;

- (NUUInt32)level;
- (NUUInt32)nodeHeaderLength;
- (NUUInt32)keyLength;
- (NUUInt32)branchValueLength;
- (NUUInt32)leafValueLength;
- (NUComparisonResult (*)(NUUInt8 *, NUUInt8 *))comparator;
- (Class)branchNodeClass;
- (Class)leafNodeClass;
+ (NUUInt64)rootLocationOffset;

@end

@interface NUOpaqueBPlusTree (GettingNode)

- (NUOpaqueBPlusTreeLeaf *)leafNodeContainingKey:(NUUInt8 *)aKey keyIndex:(NUUInt32 *)aKeyIndex;
- (NUOpaqueBPlusTreeLeaf *)leafNodeContainingKeyGreaterThanOrEqualTo:(NUUInt8 *)aKey keyIndex:(NUUInt32 *)aKeyIndex;
- (NUOpaqueBPlusTreeLeaf *)leafNodeContainingKeyLessThanOrEqualTo:(NUUInt8 *)aKey keyIndex:(NUUInt32 *)aKeyIndex;
- (NUOpaqueBPlusTreeLeaf *)mostLeftNode;
- (NUOpaqueBPlusTreeLeaf *)mostRightNode;

- (NUOpaqueBPlusTreeBranch *)parentNodeOf:(NUOpaqueBPlusTreeNode *)aNode;

@end

@interface NUOpaqueBPlusTree (GettingAndSettingValue)

- (NUUInt8 *)valueFor:(NUUInt8 *)aKey;
- (void)setOpaqueValue:(NUUInt8 *)aValue forKey:(NUUInt8 *)aKey;
- (void)removeValueFor:(NUUInt8 *)aKey;

- (NUUInt8 *)firstKey;
- (NUUInt8 *)firstValue;

- (NUOpaqueBPlusTreeLeaf *)getNextKeyIndex:(NUUInt32 *)aKeyIndex node:(NUOpaqueBPlusTreeLeaf *)aNode;

@end

@interface NUOpaqueBPlusTree (ManagingNodes)

- (NUOpaqueBPlusTreeNode *)nodeFor:(NUUInt64)aNodeLocation;
- (NUOpaqueBPlusTreeNode *)loadNodeFor:(NUUInt64)aNodeLocation;
- (NUOpaqueBPlusTreeNode *)makeNodeFromPageAt:(NUUInt64)aPageLocation;
- (NUU64ODictionary *)nodeDictionary;

- (NUOpaqueBPlusTreeBranch *)makeBranchNode;
- (NUOpaqueBPlusTreeBranch *)makeBranchNodeWithKeys:(NUOpaqueArray *)aKeys values:(NUOpaqueArray *)aNodes;
- (NUOpaqueBPlusTreeLeaf *)makeLeafNode;
- (NUOpaqueBPlusTreeLeaf *)makeLeafNodeWithKeys:(NUOpaqueArray *)aKeys values:(NUOpaqueArray *)aValues;
- (NUOpaqueBPlusTreeNode *)makeNodeOf:(Class)aNodeClass;
- (NUOpaqueBPlusTreeNode *)makeNodeOf:(Class)aNodeClass keys:(NUOpaqueArray *)aKeys values:(NUOpaqueArray *)aValues;

- (NUUInt64)allocateNodePage;
- (void)releaseNodePage:(NUUInt64)aNodePage;

- (void)addNode:(NUOpaqueBPlusTreeNode *)aNode;
- (void)removeNodeAt:(NUUInt64)aPageLocation;

- (void)updateRootLocationIfNeeded;

- (void)save;
- (void)load;
- (void)saveNodes;

@end

@interface NUOpaqueBPlusTree (NodeDelegate)

- (void)branch:(NUOpaqueBPlusTreeBranch *)aBranch didInsertNodes:(NUUInt8 *)aNodeLocations at:(NUUInt32)anIndex count:(NUUInt32)aCount;

@end

@interface NUOpaqueBPlusTree (Debug)

- (void)validateAllNodeLocations;

@end