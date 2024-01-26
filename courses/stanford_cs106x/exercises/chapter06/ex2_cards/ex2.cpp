#include <iostream>
#include <string>
#include "card.h"

using namespace std;

int main()
{
  // FIXME: this enum stuck in the first item
  for (Suit suit = CLUBS; suit <= SPADES; suit++) {
    cout << suit << endl;
    for (int rank = ACE; rank <= KING; rank++) {
      cout << " " << Card(rank, suit);
    }
    cout << endl;
  }
  return 0;
}
