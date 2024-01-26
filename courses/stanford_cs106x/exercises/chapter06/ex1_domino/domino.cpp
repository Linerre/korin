/*
 * File: domino.cpp
 * --------------------
 * This file implements the Domino class.
 */

#include <iostream>
#include <string>
#include "domino.h"

using namespace std;

Domino::Domino()
{
  leftdots = 0;
  rightdots = 0;
}

Domino::Domino(int left, int right)
{
  leftdots = left;
  rightdots = right;
}

string Domino::toString() {
  string domino = "";
  domino += to_string(leftdots);
  domino += "-";
  domino += to_string(rightdots);
  return domino;
}

ostream & operator<<(ostream & os, Domino domino)
{
  return os << domino.toString();
}

int Domino::getLeftDots()
{
  return leftdots;
}

int Domino::getRightDots()
{
  return rightdots;
}
