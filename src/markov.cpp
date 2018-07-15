#include <markov.hpp>
#include <iomanip>

WordId
MarkovChain::add_word(const std::string& word)
{
    return m_dictionary.push(word);
}

void
MarkovChain::add_transition(
    WordId src,
    WordId dst
)
{
    if (auto item = m_function.find(src); item != m_function.end()) {
        item->second.add_transition(dst);
    }
    else {
        Transition trans;
        trans.add_transition(dst);
        m_function[src] = trans;
    }
}

WordId
MarkovChain::choose_next(
    WordId current,
    unsigned int rand
)
{
    return m_function.find(current)->second.choose(rand);
}

std::ostream&
operator<<(
    std::ostream& os,
    MarkovChain& mc
)
{
    for (auto& item : mc.m_function) {
        os << std::setw(10) << mc.m_dictionary.get(item.first) << " => [ ";

        for (auto& out : item.second.words()) {
            os << "'" << mc.m_dictionary.get(out) << "' ";
        }

        os << "]" << std::endl;
    }

    return os;
}

