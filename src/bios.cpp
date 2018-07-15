#include <stdexcept>
#include <iomanip>

#include <bios.hpp>

namespace
{

  void
  add_transition(
      MarkovChain& markov,
      const std::string& from,
      const std::string& to
  )
  {
      WordId src = markov.add_word(from);
      WordId dst = markov.add_word(to);
      markov.add_transition(src, dst);

      auto quoted_from = "'" + from + "'";
      std::cout << std::setw(15) << quoted_from << " --> '" << to << "'" << std::endl;
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
