#ifndef __PLAYER_H_INCLUDED__
#define __PLAYER_H_INCLUDED__

/*!
 * @file player.h
 * @brief Classe de gestion des de d un joeur.
 * @author Probak
 * @version 0.1
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

/*!
 * @class Player
 * @brief Regroupe les methodes de gestion des des.
 * 
 * Classe contenant toutes les informations relatives aux joueurs. Sa fonction 
 * principale est de gerer les des de chaque joueurs.
 */

class Player
{
private:
    
    vector<int> _dices_value; /*!< Vecteur contenant les des du joueur. */
    
public:
    /*!
     * @brief Constructeur
     * 
     * Alloue le bon nombre d espace au vecteur membre grace au constantes.
     */
    Player ();
    
    /*!
     * @brief Destructeur
     */
    ~Player ();
    
    /*!
     * @brief Sorte de getter.
     * 
     * Le nombre de des du joueur devrait etre la taille du vecteur membre.
     * 
     * @return Le nombre de des du joueur.
     */
    int dice_nb() const;
    
    /*!
     * @brief Getter sur le vecteur membre.
     * @return Le vecteur d entier membre
     */
    vector<int> get_dices_value();
    
    /*!
     * @brief Donne a chaque case du vecteur une valeur aleatoire.
     * 
     * La valeur de chaque case du vecteur doit etre comprise entre 1 et 6.
     */
    void roll_dices();
    
    /*!
     * @brief Trouve le nombre d occurence dans le vecteur d une valeur donnee.
     * 
     * Cherche dans le vecteur membre le nombre d occurence de valeur, elle doit
     * prendre en compte le fait que la manche courante peut suivre les regles
     * du palifico ou non, si la variable palifico vaut false, on ajoute on doit
e     * prendre en compte les valeurs 1 dans la valeur de retour de la methode.
     * 
     * @param value est egale a la valeur que l on cherche dans le vecteur.
     * @param palifico specifie a la methode si elle doit compter les des de 
     *        valeur 1 dans les occurences ou non (voir règles du jeu).
     * @return Le nombre d occurences de value dans le vecteur membre.
     */
    
    int occ_nb (int value, bool palifico);
    
    /*!
     * @brief Surcharge de l operateur ++.
     * 
     * Ajoute une case au vecteur, la taille du vecteur ne doit pas depasser la
     * valeur de MAXIMUM_DICES.
     */
    
    Player operator++();
    
    /*!
     * @brief Surcharge de l operateur --.
     * 
     * Retire une case au vecteur, la taille du vecteur ne doit pas etre 
     * inferieure a MINIMUM_DICES.
     */
    Player operator--();
};
#endif
