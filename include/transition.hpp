#ifndef TINDER_MARKOV_TRANSITION_HPP
#define TINDER_MARKOV_TRANSITION_HPP

#include <string>
#include <utility>
#include <map>

#include "dictionary.hpp"

class Transition
{
    std::map<WordId, unsigned int> m_words;

    unsigned int m_total_count = 0u;

  public:

    void
    add_transition(WordId word);

    WordId
    choose(unsigned int random);

};

#endif //transition_H
