//
// Created by wangzy on 2ZERO24/6/12.
//
#include "../lib/password_generator.h"


/**
 * 生成密码
 * @param length        密码长度
 * @param upper         大写字母个数
 * @param lower         小写字母个数
 * @param number        数字个数
 * @param special       特殊字符个数
 * @return             生成的密码
 */
std::string generate_password(int length, int upper, int lower, int number, int special) {
    std::string password;
    // 生成大写字母
    if (upper > static_cast<int>(DEFAULT_VALUE::ZERO)) {
        for (auto i = static_cast<int>(DEFAULT_VALUE::ZERO); i < upper; i++) {
            password  += UPPERCASE_LETTER[rand_num() % (sizeof (UPPERCASE_LETTER) / sizeof (char))];
        }
    }
    // 生成小写字母
    if (lower > static_cast<int>(DEFAULT_VALUE::ZERO)) {
        for (auto i = static_cast<int>(DEFAULT_VALUE::ZERO); i < lower; i++) {
            password += LOWERCASE_LETTER[rand_num() % (sizeof(LOWERCASE_LETTER) / sizeof(char))];
        }
    }
    // 生成数字
    if (number > static_cast<int>(DEFAULT_VALUE::ZERO)) {
        for (auto i = static_cast<int>(DEFAULT_VALUE::ZERO); i < number; i++) {
            password  += NUMBER[rand_num() % (sizeof(NUMBER) / sizeof(char))];
        }
    }

    // 生成特殊字符
    if (special > static_cast<int>(DEFAULT_VALUE::ZERO)) {
        for (auto i = static_cast<int>(DEFAULT_VALUE::ZERO); i < special; i++) {
            password += SPECIAL_CHARACTER[rand_num() % (sizeof(SPECIAL_CHARACTER) / sizeof(char))];
        }
    }

    // 生成剩余位数
    if (upper + lower + number + special < length) {
        for (auto i = static_cast<int>(DEFAULT_VALUE::ZERO); i < length - (upper + lower + number + special); i++) {
            password  += ALL_CHARACTERS[rand_num() % (sizeof(ALL_CHARACTERS) / sizeof(char))];
        }
    }
    // 随机打乱密码
    std::ranges::shuffle(password.begin(), password.end(), std::mt19937(std::random_device{}()));
    return password;
}

/**
 * 生成密码
 * @param length
 * @return
 */
std::string generate_password(int length) {
    return generate_password(length, static_cast<int>(DEFAULT_VALUE::ZERO),
                             static_cast<int>(DEFAULT_VALUE::ZERO),
                             static_cast<int>(DEFAULT_VALUE::ZERO),
                             static_cast<int>(DEFAULT_VALUE::ZERO));
}

/**
 * 生成密码
 * @return
 */
std::string generate_password() {
    return generate_password(static_cast<int>(DEFAULT_VALUE::DEFAULT_LENGTH),
                             static_cast<int>(DEFAULT_VALUE::DEFAULT_CUT),
                             static_cast<int>(DEFAULT_VALUE::DEFAULT_CUT),
                             static_cast<int>(DEFAULT_VALUE::DEFAULT_CUT),
                             static_cast<int>(DEFAULT_VALUE::DEFAULT_CUT));
}

/**
 * 随机生成一个整数
 * @return int
 */
int rand_num() {
    std::mt19937 rng(std::random_device{}());
    return rng();
}

