#ifndef __GAME_H_INCLUDED__
#define __GAME_H_INCLUDED__

#include <vector>
#include <iostream>
#include "player.hpp"
#include "bet.hpp"

// a commenter

class Game
{
public:
  Game();
  ~Game();
  bool game_over();
  void player_lose(Player p);
  void change_bet();
  void you_lie();
  void right_count();

private:
  vector<Player> _players;
  bool _is_palifico;
  Bet _bet;
  int _turn;
}

#endif
