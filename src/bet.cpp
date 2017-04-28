#include "bet.hpp"


Bet::Bet (): _count_bet (0), _value_bet (0) {}

Bet::~Bet () {}

int Bet::get_count () const
{
  return _count_bet;
}

int Bet::get_value () const
{
  return _value_bet;
}

bool Bet::set_bet (int const & count, int const & value)
{
  if (count > 0)
    {
      _count_bet = count;
      return true;
    }
  if (value > 0 && value < 7)
    {
      _value_bet = value;
      return true;
    } 
  return false;
}