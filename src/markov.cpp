#include <markov.hpp>

void
MarkovChain::add_transition(
    const std::string& from,
    const std::string& to
)
{
    if (auto item = m_function.find(from); item != m_function.end()) {
        item->second += to;
    }
    else {
        Transition trans;
        trans += to;
        m_function[from] = trans;
    }
}

std::string
MarkovChain::choose_next(
    const std::string& current,
    unsigned int rand
)
{
    return m_function.find(current)->second.choose(rand);
}
