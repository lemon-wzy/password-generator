//
// Created by wangzy on 2024/6/13.
//

#ifndef PASSWORD_GENERATOR_CONSOLE_ARGS_H
#define PASSWORD_GENERATOR_CONSOLE_ARGS_H

//命令行参数类
class console_args {
private:
    //密码长度
    int length;
    //大写字母个数
    int upper;
    //生成密码总数
    int total;
    //小写字母个数
    int lower;
    //数字个数
    int number;
    //特殊字符个数
    int special;
    //命令行参数个数
    int argc;
    //命令行参数
    char **argv;

public:
    [[nodiscard]] auto get_length() const -> int;
    [[nodiscard]] auto get_upper() const -> int;
    [[nodiscard]] auto get_lower() const -> int;
    [[nodiscard]] auto get_number() const -> int;
    [[nodiscard]] auto get_special() const -> int;
    [[nodiscard]] auto get_argc() const -> int;
    [[nodiscard]] auto get_total() const -> int;
    [[nodiscard]] auto get_argv() const -> char **;
    void set_length(int length);
    void set_upper(int upper);
    void set_lower(int lower);
    void set_number(int number);
    void set_special(int special);
    void set_argc(int argc);
    void set_argv(char **argv);
    void set_total(int total);
    //初始化参数
    void init_args(console_args * args);
};
//默认命令行参数
#define DEFAULT_CONSOLE_ARGS "l:u:n:s:o:t:h::"


#endif //PASSWORD_GENERATOR_CONSOLE_ARGS_H
