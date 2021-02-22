//
//  NUCEqualityExpression.h
//  Nursery
//
//  Created by TAKATA Akifumi on 2021/02/17.
//  Copyright © 2021年 Nursery-Framework. All rights reserved.
//

#import "NUCPreprocessingToken.h"

@class NUCRelationalExpression, NUCDecomposedPreprocessingToken;

@interface NUCEqualityExpression : NUCPreprocessingToken
{
    NUCRelationalExpression *relationalExpression;
    NUCEqualityExpression *equalityExpression;
    NUCDecomposedPreprocessingToken *equalityOperator;
}

+ (instancetype)expressionWithRelationalExpression:(NUCRelationalExpression *)aRelationalExpression;

+ (instancetype)expressionWithEqualityExpression:(NUCEqualityExpression *)anEqualityExpression equalityOperator:(NUCDecomposedPreprocessingToken *)anOperator relationalExpression:(NUCRelationalExpression *)aRelationalExpression;

- (instancetype)initWithRelationalExpression:(NUCRelationalExpression *)aRelationalExpression;

- (instancetype)initWithEqualityExpression:(NUCEqualityExpression *)anEqualityExpression equalityOperator:(NUCDecomposedPreprocessingToken *)anOperator relationalExpression:(NUCRelationalExpression *)aRelationalExpression;

@end

