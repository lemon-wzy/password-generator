//
// Created by wangzy on 2024/6/12.
//
#include "../lib/password_generator.h"
#include "../lib/console_args.h"

/**
 * 初始化参数
 * @param argc
 * @param argv
 * @param length
 * @param upper
 * @param lower
 * @param number
 * @param special
 */
void init_args(int argc, char **argv, int *length, int *upper, int *lower, int *number, int *special) {
    int ch;
    while ((ch = getopt(argc, argv, DEFAULT_CONSOLE_ARGS)) != -1) {
        switch (ch) {
            case 'l':
                *length = atoi(optarg);
                break;
            case 'u':
                *upper = atoi(optarg);
                break;
            case 'n':
                *number = atoi(optarg);
                break;
            case 's':
                *special = atoi(optarg);
                break;
            case 'o':
                *lower = atoi(optarg);
                break;
            case 'h':
                printf("Usage: %s [-l length] [-u upper] [-n number] [-s special] [-o lower]\n", argv[0]);
                exit(0);
            default:
                *length = static_cast<int>(DEFAULT_VALUE::DEFAULT_LENGTH);
                *upper = static_cast<int>(DEFAULT_VALUE::ZERO);
                *lower = static_cast<int>(DEFAULT_VALUE::ZERO);
                *number = static_cast<int>(DEFAULT_VALUE::ZERO);
                *special = static_cast<int>(DEFAULT_VALUE::ZERO);
                break;
        }
    }
    if (*length == static_cast<int>(DEFAULT_VALUE::ZERO)) {
        *length = static_cast<int>(DEFAULT_VALUE::DEFAULT_LENGTH);
    }
}

