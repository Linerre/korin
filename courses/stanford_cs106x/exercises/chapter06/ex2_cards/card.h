/*
 * File: card.h
 * ---------------
 * Define the class `Card' and its methods.
 */

#ifndef _card_h
#define _card_h

#include <string>				/* Note this appears after #ifndef */

enum Suit { CLUBS = 1, DIAMONDS, HEARTS, SPADES };
Suit & operator++(Suit & s);
Suit operator++(Suit & s, int);
bool operator<=(Suit & s1, Suit & s2);

const int ACE = 1;
const int KING = 13;
const int QUEEN = 12;
const int JACK = 11;

class Card
{
private:
  int rank;
  Suit suit;

public:
  Card();
  Card(std::string s);
  Card(int rank, Suit suit);

  int getRank();
  Suit getSuit();

  std::string toString();

  friend std::ostream & operator<<(std::ostream & os, Card card);
};

#endif
