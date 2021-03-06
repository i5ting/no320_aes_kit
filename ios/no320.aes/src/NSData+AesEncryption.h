//
//  Encryption.h
//  ssss
//
//  Created by alfred sang on 7/20/14.
//  Copyright (c) 2014 alfred sang. All rights reserved.
//
// Usage:
//
/**
     NSString *key = @"my password";
     NSString *secret = @"text to encrypt";
     //加密
     NSData *plain = [secret dataUsingEncoding:NSUTF8StringEncoding];
     NSData *cipher = [plain AES256EncryptWithKey:key];
     NSLog(@"%@",[[cipher newStringInBase64FromData] autorelease]);
     printf("%s\n", [[cipher description] UTF8String]);
     NSLog(@"%@", [[[NSString alloc] initWithData:cipher encoding:NSUTF8StringEncoding] autorelease]);//打印出null,这是因为没有解密。
     //解密
     plain = [cipher AES256DecryptWithKey:key];
     printf("%s\n", [[plain description] UTF8String]);
     NSLog(@"%@", [[[NSString alloc] initWithData:plain encoding:NSUTF8StringEncoding] autorelease]);
     //打印出secret的内容,用密码解密过了。如果使用错误的密码，则打印null
 */

#import <Foundation/Foundation.h>
#import "GTMBase64.h"


@interface NSData (AesEncryption)


/**
 * 加密
 */
- (NSData *)AES256EncryptWithKey:(NSData *)key;

/**
 * 解密
 */
- (NSData *)AES256DecryptWithKey:(NSString *)key;

/**
 * 追加64编码
 */
- (NSString *)newStringInBase64FromData;

/**
 * 同上64编码
 */
+ (NSString*)base64encode:(NSString*)str;


- (NSString *)hexadecimalString;



@end



@interface NSString (AesEncryption)
#pragma mark - Utils Method by alfred.sang

/**
 * 返回加密后的base46字符串
 *
 * @param plain_text（NSString）
 * @param key_data  （NSData）
 */
+ (NSString *)get_base64_encrypt_string:(NSString *)plain_text key_data:(NSData *)key_data;


/**
 * 返回加密后的base46字符串 todo
 *
 * @param plain_text（NSString）
 * @param key_data  （NSData）
 */
+ (NSString *)get_base64_encrypt_string:(NSString *)plain_text key_byte_arr:(id)key_byte_arr;

@end
