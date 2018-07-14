#ifndef MARKOV_DICTIONARY_HPP
#define MARKOV_DICTIONARY_HPP

#include <string>
#include <vector>

typedef unsigned int WordId;

class Dictionary
{
  private:

    std::vector<std::string> m_words;

  public:

    WordId
    push(const std::string& word);

    std::string
    get(WordId id) const;

};

#endif //MARKOV_DICTIONARY_HPP
