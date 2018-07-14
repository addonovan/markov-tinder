#include <algorithm>
#include <cassert>
#include <climits>

#include <dictionary.hpp>

WordId
Dictionary::push(const std::string& word)
{
    auto iter = std::find(
        m_words.begin(),
        m_words.end(),
        word
    );

    // if we couldn't find it, then we'll throw it in the back
    if (iter == m_words.end()) {
        m_words.push_back(word);
    }

    auto index = iter - m_words.begin();
    assert(index > 0);
    assert(index < UINT_MAX);

    return static_cast<unsigned int>(index);
}

std::string
Dictionary::get(WordId id) const
{
    return m_words.at(id);
}
