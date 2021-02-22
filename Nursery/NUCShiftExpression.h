//
//  NUCShiftExpression.h
//  Nursery
//
//  Created by TAKATA Akifumi on 2021/02/21.
//  Copyright © 2021年 Nursery-Framework. All rights reserved.
//

#import "NUCPreprocessingToken.h"

@class NUCAdditiveExpression, NUCDecomposedPreprocessingToken;

@interface NUCShiftExpression : NUCPreprocessingToken
{
    NUCAdditiveExpression *additiveExpression;
    NUCShiftExpression *shiftExpression;
    NUCDecomposedPreprocessingToken *shiftOperator;
}

+ (instancetype)expressionWithAdditiveExpression:(NUCAdditiveExpression *)anAdditiveExpression;

+ (instancetype)expressionWithShiftExpression:(NUCShiftExpression *)aShiftExpression shiftOperator:(NUCDecomposedPreprocessingToken *)aShiftOperator additiveExpression:(NUCAdditiveExpression *)anAdditiveExpression;

- (instancetype)initWithAdditiveExpression:(NUCAdditiveExpression *)anAdditiveExpression;

- (instancetype)initWithShiftExpression:(NUCShiftExpression *)aShiftExpression shiftOperator:(NUCDecomposedPreprocessingToken *)aShiftOperator additiveExpression:(NUCAdditiveExpression *)anAdditiveExpression;

@end

