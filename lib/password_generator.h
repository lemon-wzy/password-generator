//
// Created by wangzy on 2024/6/12.
//

#ifndef PASSWORD_GENERATOR_PASSWORD_GENERATOR_H
#define PASSWORD_GENERATOR_PASSWORD_GENERATOR_H

#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <random>
#include <ctime>
#include <algorithm>
#include "common_lib.h"


enum class DEFAULT_VALUE {
    ZERO = 0,
    DEFAULT_LENGTH = 16,
    DEFAULT_CUT = 4,
    DEFAULT_GENERATE_TOTAL = 5
};
const static char LOWERCASE_LETTER[] = {LOWERCASE_LETTERS};
const static char UPPERCASE_LETTER[] = {UPPERCASE_LETTERS};
const static char NUMBER[] = {NUMBERS};
const static char SPECIAL_CHARACTER[] = {SPECIAL_CHARACTERS};
const static char ALL_CHARACTERS[] = {LOWERCASE_LETTERS, UPPERCASE_LETTERS, NUMBERS, SPECIAL_CHARACTERS};
std::string generate_password(int length, int upper, int lower, int number, int special);
std::string generate_password(int length);
std::string generate_password();
void init_args(int argc, char **argv, int *length, int *upper, int *lower, int *number, int *special);
int rand_num();
#endif //PASSWORD_GENERATOR_PASSWORD_GENERATOR_H
