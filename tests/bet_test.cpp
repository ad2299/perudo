/*! 
 * @file   bet_test.cpp
 * @author Probak
 * 
 * 
 */

#include "bet_test.h"
using namespace Bet;


bet_test::bet_test(std::string name) : CppUnit::TestCase (name) {}


void runTest ()
{
  // Test du constructeur et des getters.
  Bet b ();
  CPPUNIT_ASSERT (b.get_count() == -1 && b.get_value() == -1);
  
  // Test de la methode set_bet.
  CPPUNIT_ASSERT ();
}