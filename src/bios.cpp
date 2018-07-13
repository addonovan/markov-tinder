#include <stdexcept>

#include <bios.hpp>

namespace
{

  void
  add_transition(
      MarkovChain& markov,
      std::string& from,
      std::string& to
  )
  {
      markov.add_transition(from, to);
      std::cout << from << " --> " << to << std::endl;
  }

}

namespace bio
{

  unsigned int
  parse(
      std::istream& in,
      MarkovChain& markov
  )
  {
      std::string previous = "<<START>>";
      std::string next;
      in >> next;

      auto count = 0u;
      while (next != "#####") {
          if (in.eof() || in.bad())
              throw std::runtime_error{"Unexpected EOF"};

          add_transition(markov, previous, next);
          previous = next;
          in >> next;
          count++;
      }

      next = "<<END>>";
      add_transition(markov, previous, next);
      return count + 1;
  }

}
