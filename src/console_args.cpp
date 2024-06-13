//
// Created by wangzy on 2024/6/13.
//

#include "../lib/console_args.h"
#include "../lib/password_generator.h"


int console_args::get_length() const {
    return length;
}

int console_args::get_upper() const {
    return upper;
}

int console_args::get_lower() const {
    return lower;
}

int console_args::get_number() const {
    return number;
}

int console_args::get_special() const {
    return special;
}

int console_args::get_argc() const {
    return argc;
}



char **console_args::get_argv() const {
    return argv;
}

int console_args::get_total() const {
    return total;
}

void console_args::set_number(int number) {
    this->number = number;
}

void console_args::set_length(int length) {
    this->length = length;
}

void console_args::set_lower(int lower) {
    this->lower = lower;
}

void console_args::set_special(int special) {
    this->special = special;
}

void console_args::set_upper(int upper) {
    this->upper = upper;
}

void console_args::set_argc(int argc) {
    this->argc = argc;
}

void console_args::set_argv(char **argv) {
    this->argv = argv;
}

void console_args::set_total(int total) {
    this->total = total;
}

void console_args::init_args(console_args *args) {
    int ch;
    while ((ch = getopt(args->get_argc(), args->get_argv(), DEFAULT_CONSOLE_ARGS)) != -1) {
        switch (ch) {
            case 'l':
                args->set_length(atoi(optarg));
                break;
            case 'u':
                args->set_upper(atoi(optarg));
                break;
            case 'n':
                args->set_number(atoi(optarg));
                break;
            case 's':
                args->set_special(atoi(optarg));
                break;
            case 'o':
                args->set_lower(atoi(optarg));
                break;
            case 't':
                args->set_total(atoi(optarg));
                break;
            case 'h':
                printf("Usage: %s [-l length] [-u upper] [-n number] [-s special] [-o lower]\n", argv[0]);
                exit(0);
            case '?':
                printf("Usage: %s [-l length] [-u upper] [-n number] [-s special] [-o lower]\n", argv[0]);
                exit(0);
            default:
                args->set_number(static_cast<int>(DEFAULT_VALUE::ZERO));
                args->set_length(static_cast<int>(DEFAULT_VALUE::DEFAULT_LENGTH));
                args->set_lower(static_cast<int>(DEFAULT_VALUE::ZERO));
                args->set_upper(static_cast<int>(DEFAULT_VALUE::ZERO));
                args->set_special(static_cast<int>(DEFAULT_VALUE::ZERO));
                args->set_total(static_cast<int>(DEFAULT_VALUE::DEFAULT_GENERATE_TOTAL));
                break;
        }
    }
    if (args->get_length() == static_cast<int>(DEFAULT_VALUE::ZERO)) {
        args->set_length(static_cast<int>(DEFAULT_VALUE::DEFAULT_LENGTH));
    }
    if (args->get_total() <= static_cast<int>(DEFAULT_VALUE::ZERO)) {
        args->set_total(static_cast<int>(DEFAULT_VALUE::DEFAULT_GENERATE_TOTAL));
    }
}

