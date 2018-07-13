#ifndef TINDER_MARKOV_TRANSITION_HPP
#define TINDER_MARKOV_TRANSITION_HPP

#include <string>
#include <utility>
#include <map>

class Transition
{
    std::map<std::string, unsigned int> m_words;

    unsigned int m_total_count = 0u;

  public:

    void operator+=(const std::string& word);

    std::string choose(unsigned int random);

};

#endif //transition_H
