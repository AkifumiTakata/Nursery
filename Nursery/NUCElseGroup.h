//
//  NUCElseGroup.h
//  Nursery
//
//  Created by TAKATA Akifumi on 2021/02/01.
//  Copyright © 2021年 Nursery-Framework. All rights reserved.
//

#import "NUCPreprocessingDirective.h"

@class NUCDecomposedPreprocessingToken, NUCNewline, NUCGroup;

@interface NUCElseGroup : NUCPreprocessingDirective
{
    NUCDecomposedPreprocessingToken *hash;
    NUCDecomposedPreprocessingToken *directiveName;
    NUCNewline *newline;
    NUCGroup *group;
}

+ (instancetype)elseGroupWithHash:(NUCDecomposedPreprocessingToken *)aHash directiveName:(NUCDecomposedPreprocessingToken *)anElse newline:(NUCNewline *)aNewline group:(NUCGroup *)aGroup;

- (instancetype)initWithHash:(NUCDecomposedPreprocessingToken *)aHash directiveName:(NUCDecomposedPreprocessingToken *)anElse newline:(NUCNewline *)aNewline group:(NUCGroup *)aGroup;

- (NUCDecomposedPreprocessingToken *)hash;
- (NUCDecomposedPreprocessingToken *)else;
- (NUCNewline *)newline;
- (NUCGroup *)group;

@end