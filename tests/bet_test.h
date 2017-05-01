#ifndef BET_TEST_H
#define BET_TEST_H

/*! 
 * @file bet_test.h
 * @author Probak
 * @brief Tests de la classe Bet
 * @version 0.1
 */

#include <cppunit/extensions/HelperMacros.h>
#include "../include/bet.hpp"

/*!
 * @class bet_test
 * @brief Contient les tests pour la classe Bet
 */
class bet_test : public CppUnit::TestCase {
    
public:
    /*!
     * @brief Constructeur
     * @param name est le nom du test.
     */
    bet_test (std::string name);
    /*!
     * @brief Surcharge de la methode runTest() de cppUnit
     */
    void runTest();

};

#endif /* BET_TEST_H */

