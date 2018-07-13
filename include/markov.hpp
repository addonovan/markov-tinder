#ifndef TINDER_MARKOV_MARKOV_HPP
#define TINDER_MARKOV_MARKOV_HPP

#include <random>
#include <map>
#include <iostream>

#include <transition.hpp>

class MarkovChain
{
  private:

    std::map<std::string, Transition> m_function;

  public:

    MarkovChain() = default;

  public:

    void add_transition(const std::string& from, const std::string& to);

    template<typename T>
    void next(std::ostream& out, T random_provider)
    {
        std::uniform_int_distribution<typename T::result_type>
            distribution{1, 10000};

        std::string current = "<<START>>";
        std::string next;

        while (true)
        {
            next = choose_next(current, distribution(random_provider));

            if (next == "<<END>>")
                break;

            out << next << " ";
            current = next;
        }

        out << std::endl;
    }

  private:

    std::string choose_next(const std::string& current, unsigned int rand);

};


#endif //markov_H
