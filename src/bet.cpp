#include "bet.hpp"

Bet::Bet ()
{
  this->_count_bet = 0;
  this->_value_bet = 0;
}

Bet::~Bet () {}

Bet::get_count () const
{
  return _count_bet;
}

Bet::get_value () const
{
  return _value_bet;
}

bool set_bet (int const & count, int const & value, bool palifico)
{
  return false;
}
