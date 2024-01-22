/*
 * File: ex1.cpp
 * -------------
 * Use readVector(infile, roots) to overload one another.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
using namespace std;


void readVector(istream & is, vector<double> & vec);

int main()
{
  ifstream file("squareandcuberoots.txt");
  vector<double> roots;
  if (file.is_open()) {
    // First call
    readVector(file, roots);
    cout << "Roots: [";
    for (size_t i = 0; i < roots.size(); ++i) {
      cout << fixed << setprecision(4) << roots[i] << ", ";
    }
    cout << "]" << endl;

    // second call
    readVector(file, roots);
    cout << "Roots: [";
    for (size_t i = 0; i < roots.size(); ++i) {
      cout << fixed << setprecision(4) << roots[i] << ", ";
    }
    cout << "]" << endl;

    // third call
    readVector(file, roots);
    cout << "Roots: [";
    for (size_t i = 0; i < roots.size(); ++i) {
      cout << fixed << setprecision(4) << roots[i] << ", ";
    }
    cout << "]" << endl;
  }

  file.close();
  return 0;
}

void readVector(istream & is, vector<double> & vec)
{
  if (!vec.empty()) vec.clear();

  stringstream converter;
  string line = "";
  double number = 0.0;
  while (true) {
    getline(is, line);
    if (is.fail()) break; // EOF
    if (line.size() == 0) break; // Empty line
    converter << line;
    converter >> number;
    converter.clear();
    vec.push_back(number);
  }
}
