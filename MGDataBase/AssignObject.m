//
//  AssignObject.m
//  quxue3
//
//  Created by mac on 2018/4/2.
//  Copyright © 2018年 BW. All rights reserved.
//

#import "AssignObject.h"
#import "FMDatabase.h"
#import "FMDatabaseAdditions.h"

@implementation AssignObject

//获取类的各个属性，存到数组中
+ (id)getPropertyListWithClassStr:(NSString *)classStr

{
    unsigned int outCount, i;
    
    //获取一个类的各个成员变量存放在properties[]数组中
    objc_property_t *properties = class_copyPropertyList([NSClassFromString(classStr) class], &outCount);
    
    NSMutableArray *keys = [[NSMutableArray alloc] initWithCapacity:outCount];
    
    for (i = 0; i < outCount; i++) {
        
        objc_property_t property = properties[i];
        
        NSString *propertyName = [[NSString alloc] initWithCString:property_getName(property) encoding:NSUTF8StringEncoding];
        
        [keys addObject:propertyName];
        
    }
    
    free(properties);
    
    return keys;
    
}

//用字典为类的各个属性赋值
+ (id)reflectDataFromOtherObject:(FMResultSet *)dataSource classStr:(NSString *)classStr

{
    
    id model = [[NSClassFromString(classStr) alloc] init];
    
    BOOL ret = NO;
    
    for (NSString *key in [self getPropertyListWithClassStr:classStr])
    {
        
        if ([dataSource isKindOfClass:[FMResultSet class]])
        {
            
            ret = ([dataSource stringForColumn:key] == nil ) ? NO : YES;
            
        }
        
        else
            
        {
            
            ret = [dataSource respondsToSelector:NSSelectorFromString(key)];
            
        }
        
        if (ret)
        {
            
            id propertyValue = [dataSource stringForColumn:key];
            
            //该值不为NSNULL，并且也不为nil
            
            if (![propertyValue isKindOfClass:[NSNull class]] && propertyValue != nil)
            {
                
                //为对象的各个属性赋值
                [model setValue:propertyValue forKey:key];
                
            }
            
        }
        
    }
    
    return model;
    
}


@end
