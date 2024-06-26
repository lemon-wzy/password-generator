//
// Created by wangzy on 2024/6/12.
//

#ifndef PASSWORD_GENERATOR_PASSWORD_GENERATOR_H
#define PASSWORD_GENERATOR_PASSWORD_GENERATOR_H

#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
//#include <unistd.h>
#include <random>
#include <ctime>
#include <algorithm>
#include "common_lib.h"
#ifdef _WIN32
#include <io.h>
#include <getopt.h>
#define access _access
#else
#include <unistd.h>
#endif

//默认值枚举类
enum class DEFAULT_VALUE {
    //0值
    ZERO = 0,
    //默认长度
    DEFAULT_LENGTH = 16,
    //默认剪切长度
    DEFAULT_CUT = 4,
    //默认生成总数
    DEFAULT_GENERATE_TOTAL = 5
};
//小写字母池
const static char LOWERCASE_LETTER[] = {LOWERCASE_LETTERS};
//大写字母池
const static char UPPERCASE_LETTER[] = {UPPERCASE_LETTERS};
//数字
const static char NUMBER[] = {NUMBERS};
//特殊字符
const static char SPECIAL_CHARACTER[] = {SPECIAL_CHARACTERS};
//所有字符
const static char ALL_CHARACTERS[] = {LOWERCASE_LETTERS, UPPERCASE_LETTERS, NUMBERS, SPECIAL_CHARACTERS};
/**
 * 生成密码
 * @param length
 * @param upper
 * @param lower
 * @param number
 * @param special
 * @return
 */
auto generate_password(int length, int upper, int lower, int number, int special) -> std::string;
/**
 * 生成密码
 * @param length
 * @return
 */
auto generate_password(int length) -> std::string;
/**
 * 生成密码
 * @return
 */
std::string generate_password();
//初始化参数（弃用）
void init_args(int argc, char **argv, int *length, int *upper, int *lower, int *number, int *special);
/**
 * 产生一个随机数
 * @return
 */
auto rand_num() -> int;
#endif //PASSWORD_GENERATOR_PASSWORD_GENERATOR_H
