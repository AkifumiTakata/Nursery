//
//  NUCLogicalANDExpression.m
//  Nursery
//
//  Created by TAKATA Akifumi on 2021/02/14.
//  Copyright © 2021年 Nursery-Framework. All rights reserved.
//

#import "NUCLogicalANDExpression.h"

@implementation NUCLogicalANDExpression

+ (instancetype)expressionWithInclusiveORExpression:(NUCInclusiveORExpression *)anInclusiveORExpression
{
    return [[[self alloc] initWithInclusiveORExpression:anInclusiveORExpression] autorelease];
}

+ (instancetype)expressionWithLogicalANDExpression:(NUCLogicalANDExpression *)aLogicalANDExpression logicalANDOperator:(NUCDecomposedPreprocessingToken *)aLogicalANDOperator inclusiveORExpression:(NUCInclusiveORExpression *)anInclusiveORExpression
{
    return [[[self alloc] initWithLogicalANDExpression:aLogicalANDExpression logicalANDOperator:aLogicalANDOperator inclusiveORExpression:anInclusiveORExpression] autorelease];
}

- (instancetype)initWithInclusiveORExpression:(NUCInclusiveORExpression *)anInclusiveORExpression
{
    return [self initWithLogicalANDExpression:nil logicalANDOperator:nil inclusiveORExpression:anInclusiveORExpression];
}

- (instancetype)initWithLogicalANDExpression:(NUCLogicalANDExpression *)aLogicalANDExpression logicalANDOperator:(NUCDecomposedPreprocessingToken *)aLogicalANDOperator inclusiveORExpression:(NUCInclusiveORExpression *)anInclusiveORExpression
{
    if (self = [super initWithType:NUCLexicalElementLogicalANDExpressionType])
    {
        inclusiveORExpression = [anInclusiveORExpression retain];
        logicalANDExpression = [aLogicalANDExpression retain];
        logicalANDOperator = [aLogicalANDOperator retain];
    }
    
    return self;
}

- (void)dealloc
{
    [inclusiveORExpression release];
    [logicalANDExpression release];
    [logicalANDOperator release];
    
    [super dealloc];
}

@end
