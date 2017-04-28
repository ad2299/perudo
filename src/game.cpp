#include "game.hpp"

static const int LIE = 1;	
static const int RIGHT_COUNT = 0;

Game::Game (int nb_players) : _players (0),
			      _is_palifico (false),
			      _bet (),
			      _turn (0)
{

} 

Game::~Game ()
{
  delete _bet;
}

bool Game::game_over ()
{
  return (_players.size() == 1);
}

void Game::change_bet (int const & count, int const & value)
{
}

void Game::you_lie ()
{
  
}

bool Game::eval_bet (const int & mode) 
{
  int i;
  int count = 0;
  Bet b = Bet ();
  //bool palifico = _is_palifico;
  //  int bet_value = _bet->get_value;
  // Cherche parmis tout les joueurs.
  for (i=0; i<_players.size(); ++i)
    int tmp = _players.at(i)->occ_nb(_bet->get_value(), _is_palifico);
  
  // Cas du mensonge
  if (mode)
    {    
      // Cas ou le joueur courant a raison.
      if (count < _bet->get_count())
	return true;
      return false;
    }
      
  // Cas du compte est bon
  else
    {
      // Cas ou le joueur courrant a le bon nombre de des.
      if (count == _bet->get_count())
	return true;
      return false;
    }
}


void Game::right_count ()
{
  int i;
}

int main (void)
{
  cout << "Hello, world!" << endl;
  return 0;
}
