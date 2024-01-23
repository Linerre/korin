/*
 * File: parenCheck()
 * ------------------
 * Check if the bracketing operators (parentheses, brackets, and curly braces)
 * in a string are properly matched.
 */
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <stack>
#include <iomanip>
#include <algorithm>
using namespace std;

bool balanced(string & prog);

int main()
{
  vector<string> progs = {
    "{ s = 2 * (a[2] + 3); x = (1 + (2)); }",
    "{ s = 2 * {a[2] + 3); x = (1 + (2)); }",
    "{ s = 2 * )(a[2] + 3); x = (1 + (2)); }",
    "{ s = 2 * {{{}(a[2] + 3); x = (1 + (2)); }",
    "{{{}",
    "{}}}}",
  };

  for_each(progs.begin(), progs.end(), [](string & p) {
    cout << "program: " << p << " balanced? "
         << boolalpha << balanced(p) << endl;
  });
  return 0;
}

bool balanced(string & prog)
{
  stack<char> open_parens;
  int N = prog.size();
  for (int j = 0; j < N; ++j) {
    char c = prog[j];
    if (c == '{' || c == '(' || c == '[') open_parens.push(c);
    else if (c == '}' && open_parens.size() > 0 && open_parens.top() != '{') return false;
    else if (c == ')' && open_parens.size() > 0 && open_parens.top() != '(') return false;
    else if (c == ']' && open_parens.size() > 0 && open_parens.top() != '[') return false;

    if (c == '}' || c == ')' || c == ']') {
      if (open_parens.size() > 0) open_parens.pop();
      else return false;
    }
  }
  return open_parens.size() == 0;
}
