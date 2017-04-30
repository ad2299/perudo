#ifndef __BET_H_INCLUDED__
#define __BET_H_INCLUDED__

/*!
 * @file bet.h
 * @brief Gestion des mises durant le jeu.
 * @author Probak
 * @version 0.1
 */

#include <iostream>
/*!
 * @class Bet
 * @brief Gere la mise d un joueur.
 */
class Bet
{
private:
    
    int _count_bet;  /*!< Nombre de de sur le quel le dernier joueur mise. */
    int _value_bet;  /*!< La valeur du de de la mise.                      */
    
public:
    /*!
     * @brief Constructeur
     * 
     * Constructeur de la classe Bet, initialise les deux donnees membres de la 
     * classe a -1.
     */
    Bet ();
    
    /*!
     * @brief getter classique.
     * @return _count_bet.
     */
    int get_count () const;
    /*!
     * @brief getter classique.
     * @return _value_bet.
     */
    int get_value () const;
    
    /*!
     * @brief Gestion du changement de mise.
     * 
     * Cette fonction a pour but de gerer les deux valeurs de la mise en 
     * meme temps. Elle devra gerer le fait que la mise sur la valeur soit 
     * comprise entre 1 et 6 puis que la mise sur le nombre de des soit positive
     * ou nulle. Si les parametres sont correct, la fonction renvoie vrai, sinon
     * faux. si la variable palifico est vraie, voir les regles du jeu
     * (game.hpp) pour calculer la mise (section palifico).
     * 
     * @Param count count ne peut pas etre negatif mais n'a pas de maximum.
     * @Param value value doit etre comprit entre 1 et 6.
     * @return true si le changement est bien fait, false sinon.
     */
    bool set_bet (int const & count, int const & value);
    
};

#endif
