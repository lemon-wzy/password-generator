#include "lib/password_generator.h"
#include "lib/console_args.h"

int main(int argc, char **argv) {
    console_args args{};
    args.set_argc(argc);
    args.set_argv(argv);
    args.init_args(&args);
    std::string password;
    for (int i = 0; i < args.get_total(); i++) {
        if (static_cast<int>(DEFAULT_VALUE::ZERO) >= args.get_upper() + args.get_lower() + args.get_number() + args.get_special()) {
            password = generate_password(args.get_length());
        } else {
            password = generate_password(args.get_length(), args.get_upper(), args.get_lower(), args.get_number(), args.get_special());
        }
        std::cout << password << std::endl;
    }
    return 0;
}

