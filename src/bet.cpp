#include "bet.hpp"

Bet::Bet (): _count_bet (-1), _value_bet (-1) {}

int Bet::get_count () const
{
  return _count_bet;
}

int Bet::get_value () const
{
  return _value_bet;
}

// Il faut completer cette methode.
bool Bet::set_bet (int const & count, int const & value)
{
  if (count > _count_bet)
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