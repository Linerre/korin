/*
 * File: domino.h
 * --------------------
 * This file exports a simple domino class that displays a domino card.
 */

#ifndef _domino_h
#define _domino_h

#include <string>

/*
 * Class: Domino
 * --------------------
 * This class is used to represent a 4-1 domino (a traditional one). It exports:
 * A default constructor that creates the 0-0 domino
 * A constructor that takes the number of dots on each side
 * A `toString' method that creates a string representation of the domino
 * Two getter methods named `getLeftDots' and `getRightDots'
 */

class Domino {

public:
	Domino();
	Domino(int left, int right);

  std::string toString();

	int getLeftDots();
	int getRightDots();

private:
  int leftdots;
  int rightdots;

};

#endif
