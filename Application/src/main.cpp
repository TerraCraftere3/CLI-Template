#include <iostream>
#include <argparse/argparse.hpp>

#include "Config.h"

int main (int argc, char** argv) {
    Config conf;

    argparse::ArgumentParser program("CLI-App");
    program.add_argument("-v", "--verbose")
        .help("increase output verbosity")
        .default_value(false)
        .implicit_value(true);
    try {
        program.parse_args(argc, argv);
    } catch (const std::runtime_error& err) {
        std::cerr << err.what() << std::endl;
        std::cerr << program.help().str() << std::endl;
        return 1;
    }
    conf.verbose = program.get<bool>("--verbose");
    return 0;
}