#ifndef __PLAYER_H_INCLUDED__
#define __PLAYER_H_INCLUDED__

#include <iostream>
#include <vector>

// A commenter

class Player
{
public:
  Player ();
  ~Player ();
  int dice_nb() const;
  vector<int> get_dices_value();
  void roll_dices();
  operator++();
  operator--();
  
private:
  vector<int> _dices_value;
};


#endif
