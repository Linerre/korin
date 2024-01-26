/*
 * File: card.cpp
 * --------------------
 * This file implements Card class and its methods.
 */

#include <iostream>
#include <string>
#include <cctype>
#include "card.h"

using namespace std;

Card::Card()
{
  rank = 1;
  suit = Suit::CLUBS;
}

// Card::Card(string s)
// {
//   int N = s.size();
//   rank = rankFromStr(s);
//   suit = suitFromStr(s);
// }

Card::Card(int rank, Suit suit)
{
  this->rank = rank;
  this->suit = suit;
}

int Card::getRank()
{
  return rank;
}

Suit Card::getSuit()
{
  return suit;
}

Suit suitFromStr(string s)
{
  if (s == "C") return Suit::CLUBS;
  if (s == "H") return Suit::HEARTS;
  if (s == "D") return Suit::DIAMONDS;
  if (s == "S") return Suit::SPADES;
  return Suit::CLUBS;
}

string suitToStr(Suit s)
{
  switch(s) {
  case Suit::CLUBS: return string("C");
  case Suit::DIAMONDS: return string("D");
  case Suit::HEARTS: return string("H");
  case Suit::SPADES: return string("S");
  default: return string("C");
  }
}

string rankToStr(int r)
{
  if (r >= 2 && r <= 10) return to_string(r);
  else if (r == ACE) return string("A");
  else if (r == KING) return string("K");
  else if (r == QUEEN) return string("Q");
  else if (r == JACK) return string("J");
}

// int Card::rankFromStr(string s) {
//   int N = s.size();
//   if (N == 2) {
//     string ranstr = s.substr(0,1);
//     if (isdigit(ranstr)) return (int)string::stoul(s.substr(0,1));
//
//   }
//
//   if (N == 3)
//     return (int)string::stoul(s.substr(0,2));
//
//   return 0;
// }

ostream & operator<<(ostream & os, Card card)
{
  string strc = "";
  strc += rankToStr(card.rank);
  strc += suitToStr(card.suit);
  os << strc;
  return os;
}


Suit & operator++(Suit & s)
{
  if (s + 1 >= 4) return s;
  s = static_cast<Suit>(s + 1);
  return s;
}
// Implement postfix ++ operators for the enum
// Note the dummy int parameter and
// usually the prefix ++ needs to be implemented as well
Suit operator++(Suit & s, int)
{
  Suit rs(s);
  ++rs;
  return rs;
}


bool operator<=(Suit s1, Suit s2)
{
  return (s1 + 0 <= s2 + 0);
}
