#ifndef TINDER_MARKOV_BIOS_HPP
#define TINDER_MARKOV_BIOS_HPP

#include <string>
#include <iostream>
#include <markov.hpp>

namespace bio
{

  unsigned int parse(std::istream& in, MarkovChain& markov);

}

#endif //bios_H
