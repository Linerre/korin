/*
 * File: ex5.cpp
 * -------------
 * Get file root and extention.  For example:
 * getExt("somefile.txt") prints `somefile' as root and `txt' as extention.
 * If no extention found, return empty string.
 */

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
using namespace std;

string getRoot(string & filename)
{
  string::size_type dotpos = filename.find(".");
  if (dotpos != string::npos) {
    return filename.substr(0, dotpos);
  } else {
    return "";
  }
}

string getExt(string & filename)
{
  string::size_type dotpos = filename.find(".");
  if (dotpos != string::npos) {
    return filename.substr(dotpos);
  } else {
    return "";
  }
}

string defaultExt(string & filename, string ext)
{
  string fileExt = getExt(filename);
  string root = getRoot(filename);
  string::size_type star = ext.find("*.");
  if (star != string::npos && root.size() > 0) {
    return root += ext.substr(1);
  }
  else if (fileExt.size() == 0)
    return filename += ext;
  else
    return filename;
}

int main()
{
  string file1 = "Middlemarch.txt";
  string file2 = "Unknown";
  string file3 = "Shakespeare";
  string file4 = "library.h";

  cout << setw(20) << "File" << " | "
       << setw(15) << "Filename(root)" << " | "
       << setw(10) << "Extentsion" << " | "
       << setw(15) << "Default Ext." << " |" << endl;

  cout << setw(20) << file1 << " | "
       << setw(15) << getRoot(file1) << " | "
       << setw(10) << getExt(file1) << " | "
       << setw(15) << defaultExt(file1, ".cpp") << " |" << endl;

  cout << setw(20) << file2 << " | "
       << setw(15) << getRoot(file2) << " | "
       << setw(10) << getExt(file2) << " | "
       << setw(15) << defaultExt(file2, ".txt") << " |" << endl;

  cout << setw(20) << file2 << " | "
       << setw(15) << getRoot(file2) << " | "
       << setw(10) << getExt(file2) << " | "
       << setw(15) << defaultExt(file2, "*.danger") << " |" << endl;


  cout << setw(20) << file3 << " | "
       << setw(15) << getRoot(file3) << " | "
       << setw(10) << getExt(file3) << " | "
       << setw(15) << defaultExt(file3, ".txt") << " |" << endl;

  cout << setw(20) << file4 << " | "
       << setw(15) << getRoot(file4) << " | "
       << setw(10) << getExt(file4) << " | "
       << setw(15) << defaultExt(file4, ".cpp") << " |" << endl;

  cout << setw(20) << file4 << " | "
       << setw(15) << getRoot(file4) << " | "
       << setw(10) << getExt(file4) << " | "
       << setw(15) << defaultExt(file4, "*.cpp") << " |" << endl;


  return 0;


}
