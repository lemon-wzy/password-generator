//
// Created by wangzy on 2ZERO24/6/12.
//
#include "../lib/password_generator.h"


/**
 * 生成密码
 * @param length
 * @param upper
 * @param lower
 * @param number
 * @param special
 * @return
 */
std::string generate_password(int length, int upper, int lower, int number, int special) {
    std::string password;
    if (upper > static_cast<int>(DEFAULT_VALUE::ZERO)) {
        for (auto i = static_cast<int>(DEFAULT_VALUE::ZERO); i < upper; i++) {
            password  += UPPERCASE_LETTER[rand_num() % (sizeof (UPPERCASE_LETTER) / sizeof (char))];
        }
    }
    if (lower > static_cast<int>(DEFAULT_VALUE::ZERO)) {
        for (auto i = static_cast<int>(DEFAULT_VALUE::ZERO); i < lower; i++) {
            password += LOWERCASE_LETTER[rand_num() % (sizeof(LOWERCASE_LETTER) / sizeof(char))];
        }
    }
    if (number > static_cast<int>(DEFAULT_VALUE::ZERO)) {
        for (auto i = static_cast<int>(DEFAULT_VALUE::ZERO); i < number; i++) {
            password  += NUMBER[rand_num() % (sizeof(NUMBER) / sizeof(char))];
        }
    }
    if (special > static_cast<int>(DEFAULT_VALUE::ZERO)) {
        for (auto i = static_cast<int>(DEFAULT_VALUE::ZERO); i < special; i++) {
            password += SPECIAL_CHARACTER[rand_num() % (sizeof(SPECIAL_CHARACTER) / sizeof(char))];
        }
    }

    if (upper + lower + number + special < length) {
        for (auto i = static_cast<int>(DEFAULT_VALUE::ZERO); i < length - (upper + lower + number + special); i++) {
            password  += ALL_CHARACTERS[rand_num() % (sizeof(ALL_CHARACTERS) / sizeof(char))];
        }
    }

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

