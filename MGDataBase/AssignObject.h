//
//  AssignObject.h
//  quxue3
//
//  Created by mac on 2018/4/2.
//  Copyright © 2018年 BW. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <objc/runtime.h>


@interface AssignObject : NSObject

+ (id)getPropertyListWithClassStr:(NSString *)classStr;
+ (id)reflectDataFromOtherObject:(id)dataSource classStr:(NSString *)classStr;


@end
