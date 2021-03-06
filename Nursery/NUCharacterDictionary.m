//
//  NUCharacterDictionary.m
//  Nursery
//
//  Created by Akifumi Takata on 2013/10/05.
//
//

#import "NUCharacterDictionary.h"
#import "NUMutableDictionary.h"
#import "NUCharacter.h"
#import "NUCharacter+Project.h"
#import "NUIvar.h"
#import "NUAliaser.h"
#import "NUBell.h"
#import "NUGarden.h"

@implementation NUCharacterDictionary

+ (id)dictionary
{
    return [[[self alloc] init] autorelease];
}

- (id)init
{
    if (self = [super init])
    {
        dictionary = [NUMutableDictionary new];
    }
    
    return self;
}

- (void)dealloc
{
    [dictionary release];
    
    [super dealloc];
}

- (NSUInteger)count
{
    return [[self dictionary] count];
}

- (id)objectForKey:(id)aKey
{
    return [[self dictionary] objectForKey:aKey];
}

- (void)setObject:(id)anObject forKey:(id<NSCopying>)aKey
{
    NUCharacter *aCharacter = anObject;
    
    [[self dictionary] setObject:anObject forKey:aKey];
    [[aCharacter superCharacter] addSubCharacter:aCharacter];
    [[[self bell] garden] markChangedObject:self];
}

- (void)enumerateUsingBlock:(void (^)(NSString *anInheritanceNameWithVersion, NUCharacter *aCharacter, BOOL *aStop))aBlock
{
    [[self dictionary] enumerateKeysAndObjectsUsingBlock:^(id  _Nonnull key, id  _Nonnull obj, BOOL * _Nonnull stop) {
        aBlock(key, obj, stop);
    }];
}

- (NSEnumerator *)keyEnumerator
{
    return [[self dictionary] keyEnumerator];
}

- (NUBell *)bell
{
	return bell;
}

- (void)setBell:(NUBell *)aBell
{
	bell = aBell;
}

+ (void)defineCharacter:(NUCharacter *)aCharacter on:(NUGarden *)aGarden
{
    [aCharacter addOOPIvarWithName:@"dictionary"];
}

- (void)encodeWithAliaser:(NUAliaser *)anAliaser
{
	[anAliaser encodeObject:dictionary];
}

- (id)initWithAliaser:(NUAliaser *)anAliaser
{
    NUSetIvar(&dictionary, [anAliaser decodeObjectReally]);
	
	return self;
}

- (void)moveUpWithAliaser:(NUAliaser *)anAliaser
{
    [anAliaser moveUp:[self dictionary] ignoreGradeAtCallFor:NO];
}

@end

@implementation NUCharacterDictionary (Private)

- (NUMutableDictionary *)dictionary
{
    return dictionary;
}

- (void)setDictionary:(NUMutableDictionary *)aDictionary
{
    [dictionary autorelease];
    dictionary = [aDictionary retain];
}

@end
