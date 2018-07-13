#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <random>
#include <ctime>

#include <markov.hpp>
#include <bios.hpp>

int
main(int argc, char *argv[])
{
    if (argc == 1) {
        std::cout << "Please provide the path to the bio file" << std::endl;
        return 1;
    }

    std::stringstream stringstream;
    for (auto i = 1; i < argc; i++) {
        stringstream << argv[i];

        if (i + 1 != argc)
            stringstream << " ";
    }

    auto file_name = stringstream.str();
    std::cout << "Reading file: '" << file_name << "'" << std::endl;
    std::ifstream file{file_name};
    if (file.fail())
        throw std::runtime_error{"Could not open file"};

    MarkovChain markovChain;
    while (!file.eof()) {
        bio::parse(file, markovChain);
    }

    std::cout << std::endl;
    std::mt19937 rng{static_cast<unsigned long>(std::time(0u))};
    markovChain.next(std::cout, rng);

    return 0;
}