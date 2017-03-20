#ifndef __BET_H_INCLUDED__
#define __BET_H_INCLUDED__

#include <iostream>

/**
 * Cette classe servira pour la gestion des paris durant la partie sous la forme de deux entiers.
 **/

class Bet
{

public:
  /**
   * Simple fonction d'instanciation de la classe. Les deux entiers seront initialises a 0.
   **/
  Bet ();
  ~Bet ();

  // getters classiques.
  int get_count () const;
  int get_value () const;

  /**
   * @Param : count ne peut pas etre negatif mais n'a pas de maximum.
   * @Param : value doit etre comprit entre 1 et 6.
   * Cette fonction a pour but de gerer les deux valeurs de la mise en meme temps.
   * Elle devra gerer le fait que la mise sur la valeur soit comprise entre 1 et 6 puis que
   * la mise sur le nombre de des soit positive ou nulle. Si les parametres sont corrects
   * la fonction renvoie vrai, sinon faux.
   * si la variable palifico est vraie, voir les regles du jeu (game.hpp) pour calculer
   * la mise. (section palifico)
   **/
  bool set_bet (int const & count, int const & value);
  
private:

  /**
   * _count_bet definit le nombre de des sur le quel le dernier joueur mise, c est a dire combien 
   * de des de valeur X (ici _value_bet) il y a sur la table.
   * _value_bet definit la valeur sur le quel le dernier joueur a mise (valeur alant de 1 a 6).
   **/
  int _count_bet;
  int _value_bet;
};

#endif
