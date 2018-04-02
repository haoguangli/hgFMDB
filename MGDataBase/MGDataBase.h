//
//  MGDataBase.h
//  quxue3
//
//  Created by mac on 2018/4/2.
//  Copyright © 2018年 BW. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FMDatabase.h"
#import "FMDatabaseAdditions.h"

@interface MGDataBase : NSObject


@property(nonatomic, strong) FMDatabase *fmdb;
@property(nonatomic, strong) FMResultSet *fmrs;

//得到数据库，单例的数据库
+ (MGDataBase *)shareDataBase;

//判断表格是否存在（tableName是表名）
- (BOOL)isExistTable:(NSString *)tableName;

//根据对象中的一个字段判断是否在数据库中存在
- (BOOL)isExistTable:(NSString *)tableName andObject:(id)object andObjectAtIndex:(int)index;

//根据对象中的两个字段判断是否在数据库中存在
- (BOOL)isTwoExistTable:(NSString *)tableName andObject:(id)object andObjectAtIndex:(int)index andObjectAtIndex:(int)index;

#pragma mark - 创建表格
//创建表格（会自动加上id作为主键,fieldArray是字段）
- (void)createTableID:(NSString *)tableName;

#pragma mark - 插入记录
//以model的形式请求插入用户数据
- (BOOL)insertRecorderDataWithTableName:(NSString *)tableName andModel:(id)object;

//插入记录
- (BOOL)insertRecorderDataWithTableName:(NSString *)tableName valuesDictionary:(NSMutableDictionary *)dic;


#pragma mark - 删除记录
//删除记录(dic中包含了关键字段)
- (void)deleteRecordDataWithTableName:(NSString *)tableName andDictionary:(NSMutableDictionary *)dic;

//删除一个表中所有信息
-(void)deleteReCordFromTableName:(NSString *)tableName;

#pragma mark - 修改记录
//修改记录
- (void)modifyRecorderData:(NSString *)tableName andNewDictionary:(NSMutableDictionary *)dic andOriginDictionary:(NSMutableDictionary *)keyDic;


#pragma mark - 获取记录
- (NSMutableArray *)getRecorderDataWithTableName:(NSString *)tableName from:(NSString *)fromIdStr to:(NSString *)toIdStr;

- (NSMutableArray *)getRecorderDataForTwoWithTableName:(NSString *)tableName andDicitonary:(id)keyDic;

//返回数据库表中所有的数据对象
-(NSMutableArray *)gainTableRecoderID:(NSString *)tableName;



@end
