#include <algorithm>

#include <transition.hpp>
#include <dictionary.hpp>

void
Transition::add_transition(WordId word)
{
    if (auto iter = m_words.find(word); iter != m_words.end()) {
        iter->second += 1;
    }
    else {
        m_words[word] = 1;
    }
    m_total_count += 1;
}

WordId
Transition::choose(unsigned int random)
{
    auto weight = random % m_total_count;

    for (auto& item : m_words) {
        if (weight < item.second) {
            return item.first;
        }
        weight -= item.second;
    }

    throw std::runtime_error{"Failed to choose any item!"};
}

std::vector<WordId>
Transition::words() const
{
    std::vector<WordId> words;

    for (auto& item : m_words) {
        words.push_back(item.first);
    }

    return words;
}
