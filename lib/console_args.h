//
// Created by wangzy on 2024/6/13.
//

#ifndef PASSWORD_GENERATOR_CONSOLE_ARGS_H
#define PASSWORD_GENERATOR_CONSOLE_ARGS_H


class console_args {
private:
    int length;
    int upper;
    int total;
    int lower;
    int number;
    int special;
    int argc;
    char **argv;

public:
    int get_length() const;
    int get_upper() const;
    int get_lower() const;
    int get_number() const;
    int get_special() const;
    int get_argc() const;
    int get_total() const;
    char **get_argv() const;
    void set_length(int length);
    void set_upper(int upper);
    void set_lower(int lower);
    void set_number(int number);
    void set_special(int special);
    void set_argc(int argc);
    void set_argv(char **argv);
    void set_total(int total);
    void init_args(console_args * args);
};

#define DEFAULT_CONSOLE_ARGS "l:u:n:s:o:t:h::"


#endif //PASSWORD_GENERATOR_CONSOLE_ARGS_H
