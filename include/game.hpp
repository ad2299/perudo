#ifndef __GAME_H_INCLUDED__
#define __GAME_H_INCLUDED__

#include <vector>
#include <iostream>
#include "player.hpp"
#include "bet.hpp"

using namespace std;

/**
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
 **/


/**
 * Cette classe va gerer le jeu.
 **/

class Game
{
public:
    /**
     * @Param : le nombre de joueurs de depart de la partie.
     * Le vecteur de joueur devra etre instancie avec nb_player "cases".
     * _is_palifico devra etre initialise a false.
     * _bet devra etre instancie.
     * _turn devra etre initialise a 0.
     **/
    Game(int nb_players);
    
    /**
     * Doit faire appel aux destructeur de vector et de Bet.
     **/
    ~Game();
    
    /**
     * @return : La fonction renvoie false si il reste plus d un joueur dans la
     * partie (vector::size > 1) et true dans le cas inverse.
     **/
    bool game_over();
    
    /**
     * Fait appel a la methode de la classe Bet pour changer les valeurs de la
     * mise. Cette methode ne prend pas fin tant que le joueur n a pas saisi des
     * valeurs correctes (gestion des valeurs dans Bet::set_value()) Cette 
     * methode prend la valeur de tout les des de tout les joueurs pour les 
     * donner a Bet::set_value(). Il faudra prendre en compte le tour palifico.
     * Une fois que la mise est correcte, met a jour la donne membre 
     * _turn(++_turn%_players::size).
     **/
    void change_bet (int const & count, int const & value);
    
    /**
     * Verrifie tout les des de tout les joueurs. En suivant les regles enumeres
     * en debut de cet en tete, fait perdre un de a un des deux joueurs 
     * concerne : la mise est correcte, le joueur d indice _turn perd un de,
     * sinon celui d indice (_turn - 1)%_players::size perd un de. Si le joueur
     * qui perd un de se retrouve a un seul de, la variable _is_palifico est 
     * changee en true si elle est egal a false. Si un joueur n a plus de des, 
     * mettre a jour le vecteur membre.
     **/
    void you_lie();
    
    /**
     * Verrifie si la mise actuelle correspond exactement a la valeur reelle 
     * (celle des joueurs). si oui, le joueur d indice _turn gagne un de et 
     * cette meme variable ne change pas, sinon il perd un de et le joueur
     *  precedent commence (decrementer la variable _turn). Rqe : comme pour les
     * fonctions precedentes, il faut verrifier si la manche suivant sera 
     * palifico et si un joueur a perdu. il faut aussi penser a la gestion de la
     * donne membre booleenne.
     **/
    void right_count();
    
    bool eval_bet (const int & mode);
private:
    /**
     * Evalue la mise courante selon le mode et le palifico
     * Le mode est un entier à deux valeurs possibles (1 ou 0).
     * renvoie true en cas de gain de de, false dans l'autre cas.
     **/
    
    
    vector<Player*> _players;
    bool _is_palifico;
    Bet* _bet;
    int _turn;
};

#endif
