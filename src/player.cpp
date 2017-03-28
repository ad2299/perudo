#include "player.hpp"


Player::Player () : _dices_value (5){}
Player::~Player () {}

int Player::dice_nb () const
{
  return _dices_value.size();
}

vector<int> Player::get_dices_value ()
{
  // Normalement ça copie bien...
  vector<int> v_ret = _dices_value;
  return v_ret;
}


void Player::roll_dices ()
{
  int i, random;
  srand (time(0));
  for (i=0; i<=_dices_value.size(); ++i)
    {
      random = rand() % 6;
      _dices_value.at(i) = random;
    }
}

Player Player::operator ++ ()
{
  if (_dices_value.size () <= MAXIMUM_DICES)
    {
      _dices_value.push_back(0);
    }
}

Player Player::operator -- ()
{
  if (_dices_value.size() <= MINIMUM_DICES)
    {
      _dices_value.resize(_dices_value.size()-1);
    }
}
