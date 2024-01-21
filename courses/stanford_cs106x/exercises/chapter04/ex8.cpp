/*
 * Function: removeComments(istream & is, ostream & os);
 * ----------------------------------------------------
 * Remove both block comments and line comments in a cpp file.
 * Ignore in-quotes comments for now.  See example.cpp for
 * what types of comments will be removed.  The result is stored in
 * nocmt.cpp.
 */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>

using namespace std;

void removeComments(istream & is, ostream & os)
{
  stringstream temp;
  string line = "";
  bool bcmtExpand = false;

  while (true) {
    if (is.fail()) break;
    getline(is, line);

    string::size_type bcmtStart = line.find("/*");
    string::size_type bcmtEnd = line.find("*/");
    string::size_type lcmt = line.find("//");

    if (bcmtStart != string::npos && bcmtEnd != string::npos) {
      if (lcmt != string::npos && lcmt < bcmtStart) {
        //Line comment /* like this
        os << line.substr(0, lcmt) << '\n';
      } else if ((long unsigned)bcmtEnd == line.size() - 1) {
        os << line.substr(0, bcmtStart) << '\n';
      } else {
        os << line.substr(0, bcmtStart) << " " << line.substr(bcmtEnd+2) << '\n';
      }
    }
    else if (bcmtStart != string::npos && bcmtEnd == string::npos) {
      os << line.substr(0, bcmtStart) << '\n';
      bcmtExpand = true;
      continue;
    }
    else if (bcmtStart == string::npos && bcmtEnd != string::npos) {
      bcmtExpand = false;
      if ((long unsigned)bcmtEnd == line.size() - 1) {
        continue;
      } else {
        os << line.substr(bcmtEnd+2) << '\n';
      }
    }
    else if (lcmt != string::npos) {
      os << line.substr(0, lcmt) << '\n';
    }
    else {
      if (bcmtExpand)
        continue;
      else {
        cout << line << endl;
        os << line << '\n';
      }
    }
  }
}

int main()
{
  ifstream example ("example.cpp");
  ofstream nocomments ("nocmt.cpp");
  if (example.is_open() && nocomments.is_open())
  {
    removeComments(example, nocomments);
  }

  example.close();
  nocomments.close();
  return 0;
}
