#include "bet.hpp"

/* ===== Constantes symboliques ===== */

const int MAX_DICE_VALUE (6);
const int TOUCAN (1);

/* ===== Constantes symboliques ===== */


Bet::Bet (): _count (-1), _value (-1) {}

int Bet::get_count () const
{
    return _count;
}

int Bet::get_value () const
{
    return _value;
}

// Il faut completer cette methode.
bool Bet::check_bet (int const & count, int const & value, bool const & palifico)
{
    // Cas du non palifico.
    if (!palifico)
    {
        //  Cas où la valeur n'est pas un toucan.  
        if (value > TOUCAN)
        {
            /* On peut alors augmenter la valeur ou le count.
             * Il faut alors que la valeur soit inferieure a la valeur max des
             * des et que le nombre de des soit superieur au nombre de des 
             * actuel */
            if (value <= MAX_DICE_VALUE && count > _count)
            {
                set_bet (count, value);
                return true;
            }
            /* On traite maintenant le cas ou l on veut changer des toucans 
             * aux valeurs numeriques. */
            if (value <= MAX_DICE_VALUE && count > ((_count*2) + 1))
            {
                set_bet (count, value);
                return true;
            }
        }
        
        // On regarde maintenant les cas ou l on est dans le cas des toucans.
        else if (value == TOUCAN)
        {
            /* Cas ou l on veut augmenter le nombre de des mais pas changer les
             * toucans.*/
            if (count > _count)
            {
                set_bet (count, value);
                return true;
            }
            if (count > (_count / 2))
            {
                set_bet (count, value);
                return true;
            }
        }
    }
    
    // Cas ou l on est en palifico.
    else
    {
        if (value == _value && count > _count)
        {
            set_bet (count, value);
            return true;
        }
    }
    return false;
}