#ifndef TINDER_MARKOV_MARKOV_HPP
#define TINDER_MARKOV_MARKOV_HPP

#include <random>
#include <map>
#include <iostream>

#include "dictionary.hpp"
#include "transition.hpp"

class MarkovChain
{
  private:

    Dictionary m_dictionary;

    std::map<WordId, Transition> m_function;

  public:

    MarkovChain() = default;

  public:

    WordId
    add_word(const std::string& word);

    void
    add_transition(WordId src, WordId dst);

    template<typename T>
    void next(std::ostream& out, T random_provider)
    {
        std::uniform_int_distribution<typename T::result_type>
            distribution{1, 10000};

        WordId current_id = m_dictionary.push("<<START>>");
        WordId next_id;

        while (true)
        {
            next_id = choose_next(
                current_id,
                distribution(random_provider)
            );

            auto next = m_dictionary.get(next_id);
            if (next == "<<END>>")
                break;

            out << next << " ";
            current_id = next_id;
        }

        out << std::endl;
    }

  private:

    WordId
    choose_next(WordId current, unsigned int rand);

};


#endif //markov_H
