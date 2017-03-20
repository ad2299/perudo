#ifndef __PLAYER_H_INCLUDED__
#define __PLAYER_H_INCLUDED__

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#define STARTING_DICE_COUNT 5
#define MAXIMUM_DICES 10
#define MINIMUM_DICES 1

using namespace std;

/**
 * Classe contenant toutes les informations relatives aux joueurs. Sa fonction principale
 * est de gerer les des de chaque joueurs.
 **/

class Player
{
public:
  /**
   * L instanciation de la classe Player ne requiert aucun parametres. Elle devra se contenter 
   * d allouer la donnee membre avec la taille de STARTING_DICE_COUNT definie dans ce header.
   **/
  Player ();

  /**
   * Le destructeur devra seulement liberer le vecteur membre.
   **/
  ~Player ();

  /**
   * @return cette methode renverra le nombre de des du joueur ce qui correspond a la taille du 
   * vecteur membre.
   **/
  int dice_nb() const;

  /**
   * @return revoie le vecteur membre pour avoir la valeur de chaque de du joueur.
   **/
  vector<int> get_dices_value();

  /**
   * Donne une valeur aleatoire entre 1 et 6 a chaque "case" du vecteur membre.
   * Rappel : le vecteur ne peut pas avoir une taille superieure a MAXIMUM_DICES.
   **/
  void roll_dices();

  /**
   * Surcharge de l operateur ++, celui ci augmentera la taille du vecteur de 1 puis initialisera
   * la valeur de la nouvelle case a 0. La taille du vecteur ne doit pas depasser MAXIMUM_DICES.
   **/
  operator++();
  
  /**
   * Surcharge de l operateur --, celui ci diminura la taille du vecteur de 1. Ne fait rien si la
   * taille du vecteur est egal a 0.
   **/
  operator--();
  
private:

  /**
   * Cet vecteur doit etre initialise grace a la valeur STARTING_DICE_COUNT pour la taille et ses
   * cases initialies a 0.
   **/
  vector<int> _dices_value;
};


#endif
