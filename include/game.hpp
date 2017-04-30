#ifndef __GAME_H_INCLUDED__
#define __GAME_H_INCLUDED__

#include <vector>
#include <iostream>
#include "player.hpp"
#include "bet.hpp"
/*!
 * @file game.h
 * @brief Gestion du jeu en general.
 * @author Probak
 * @version 0.1
 */
using namespace std;

/*!
 * Regles du jeu :
 * Chaque joueur commence avec un nombre fixe de des (defini dans player.hpp) et
 * leur but est d etre le dernier joueur a posseder des des. Chaque joueur peut 
 * perdre et gagner des des un par un. Le but est de miser sur le nombre de des 
 * ainsi que leur valeur present dans le jeu. Au debut de chaque manche, chaque 
 * joueur lance tout ses des et a le droit de ne regarder que les siens puis un
 * joueur decide une mise de depart(exemple de mise : je pari qu il y a 5 des
 * ayant la valeur 3 sur la table). C est alors au joueur suivant (ordre de jeu
 * fixe, exemple sens des aiguilles d une montre) de modifier la mise (si il le
 * desire) selon ces regles :
 *  - Il est seulement possible d augmenter un chiffre ou les deux.
 *  - Le nombre de des peut etre augmente sans limite (du nombre qu on veut sans
 *    limite max).
 *  - La valeur des des peut etre augmente jusqu a 6 et les 1 (Rqe : la valeur 1
 *    a comme nom les "toucan") comptent comme des "jokers" et  valent tout les 
 *    nombres en meme temps (sauf exception : voir Palifico).
 *  - Il est possible de baisser les valeur en passant par les toucan. Pour se 
 *    faire, le joueur doit diviser le nombre de de par 2 (arrondi au sup). 
 *    (avec l exemple ci dessus : 3 toucans)
 *    (Rqe : le joueur peut decider de miser plus que 3 toucan ex 5 toucan, mais
 *     pas moins de 3 car 5/2 = 2.5 = 3).
 *  - Il est possible de commencer une mise directement sur des toucans.
 *  - Pour passer des toucans aux valeurs numeriques, il faut multiplier le
 *    nombre de des par 2 puis ajouter 1. (3 toucan -> 7 X) X peut valoir 
 *    n importe quelle valeur entre 2 et 6.
 *
 * Chaque joueur (sauf celui donnant la mise de depart) peut aussi decider de 
 * "jouer" avec la precedente mise. Pour ce faire il dispose de deux options :
 *  - Il decide d accuser le precedant joueur (celui ayant changer ou initialise
 *    la mise) de mentir. L accusateur assume alors que les des presents sur la
 *    table sont inferieurs (strict) a ceux annonce par la mise (Le joueur 
 *    precedent annonce 9 3, le joueur actuel l accuse de mentir tout le monde
 *    revele ses des et il se trouve qu il y a 4x3 + 2 toucans = 6 x 3, le 
 *    joueur ayant mise perde alors un de car sa mise est superieure a la 
 *    realite, la manche prend fin et ce sera alors a l accusateur d annoncer la
 *    mise) Dans le cas contraire (celui ou la mise est inferieur ou egale a la 
 *    realite) c est alors a l accusateur de perdre un de et c est a l accuse de
 *    lancer la mise lors de la prochaine manche.
 *  - Il decide de parier sur le fait que la mise correspond exactement a la
 *    realite. Si c est le cas, le joueur gagne un de et il relancera la mise de
 *    depart pour la prochaine manche, sinon il en perd un et c est au joueur 
 *    precedent de relancer la mise de depart.
 *
 * Case specifique : Palifico.
 * Lorsqu un joueur tombe a un de la manche suit alors des regles particulieres.
 * Il est impossible de changer la valeur des des, il est alors possible de
 * changer uniquement leur nombres, c est donc au premier joueur de decider de
 * la valeur des des durant toute la manche. Durant cette manche palifico, les
 * toucans perdent leur atout de joker et sont alors de simples valeurs comme
 * les autres.
 */


/*!
 * @class Game
 * @brief Regroupe toutes les methodes de gestion des joueurs et de la mise
 * 
 * C est dans cette classe que se trouve toutes les methodes qui seront utilises
 * pour les actions des joueurs et la gestion de victoire d un des joueurs.
 */

class Game
{
    
private:
    vector<Player*> _players; /*!< Vecteur pour stocker les joueurs.        */
    bool _is_palifico;        /*!< Variable de la gestion de palifico.      */
    Bet* _bet;                /*!< Represente la mise courante du jeu.      */
    int _turn;                /*!< Utilise pour indiquer le joueur courant. */
    
public:
    /*!
     * @brief Constructeur.
     * 
     * Instancie le vecteur de joueur avec la bonne taille. 
     * _is_palifico est initialise a false.
     * _turn doit etre initialise a 0.
     * 
     * @Param  nb_players est le nombre de joueurs initial.
     */
    Game(int nb_players);
    
    /*!
     * @brief Destructeur.
     */
    ~Game();
    
    /*!
     * @brief Gestion de la fin de partie.
     *  
     * @return false si il reste plus d un joueur sinon true.
     */
    bool game_over();
    
    /*!
     * @brief change la mise courante.
     * 
     * Fait appel a la methode de la classe Bet pour changer les valeurs de la
     * mise. Cette methode ne prend pas fin tant que le joueur n a pas saisi des
     * valeurs correctes (gestion des valeurs dans Bet::set_value()).
     * 
     * @param count est la mise sur le nombre de des.
     * @param value est la mise sur la valeur des des.
     **/
    void change_bet (int const & count, int const & value);
    
    /*!
     * @brief Verrifie si le joueur precedent mens.
     * 
     * Verrifie tout les des de tout les joueurs. Fait perdre un de a un des
     * deux joueurs concerne : la mise est correcte, le joueur d indice _turn 
     * perd un de sinon celui d indice (_turn - 1)%_players::size perd un de. Si
     * le joueur qui perd un de se retrouve a un seul de, la variable 
     * _is_palifico est changee en true si elle est egal a false. Si un joueur 
     * n a plus de des, il est retire du vecteur membre.
     */
    void you_lie();
    
    /*!
     * @brief Verrifie si le joueur courrant a le bom nombre de des.
     * 
     * Verrifie si la mise actuelle correspond exactement a la valeur reelle 
     * (celle du joueur courrant). Si oui, le joueur d indice _turn gagne un de 
     * et cette meme variable ne change pas, sinon il perd un de et le joueur
     * precedent commence (decrementer la variable _turn). Rqe : comme pour les
     * fonctions precedentes, il faut verrifier si la manche suivant sera 
     * palifico et si un joueur a perdu. il faut aussi penser a la gestion de la
     * donne membre booleenne.
     */
    void right_count();
    
    /*!
     * @brief fonction de debug
     * 
     * @param mode
     * @return 
     */
    bool eval_bet (const int & mode);
};

#endif
