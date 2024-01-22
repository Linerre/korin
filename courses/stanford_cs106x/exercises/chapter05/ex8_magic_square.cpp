/*
 * Exercise: Magic Square
 * ----------------------
 * A square (Grid) in which each of rows, cols and diagonals
 * add up to the same number. By no means a good solution, just a working one.
 */

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
 * Function: createVec(vector<in> vals)
 * ------------------------------------
 * Create a Grid of N x N size where N = sqrt(vals.size())
 */
vector<vector<int>> Grid(vector<int> vals);

/*
 * Function: isMagicSqr(vector<vector<in>> vals)
 * ------------------------------------
 * Decide if a given grid is magic
 */
bool isMagicSqr(vector<vector<int>> & grid);

int main()
{
  vector<int> vals1 = {8,1,6,3,5,7,4,9,2};
  vector<vector<int>> g1 = Grid(vals1);
  cout << "Grid one is magic? " << isMagicSqr(g1) << endl;

  vector<int> vals2 = {16,3,2,13,5,10,11,8,9,6,7,12,4,15,14,1};
  vector<vector<int>> g2 = Grid(vals2);
  cout << "Grid two is magic? " << isMagicSqr(g2) << endl;

  return 0;
}


vector<vector<int>> Grid(vector<int> vals)
{
  vector<vector<int>> grid;
  int N = vals.size();
  int M = (int) sqrt(N);
  cout << "Grid size: " << M << " x " << M << endl;
  for (int i = 0; i < M; ++i) {
    vector<int> row;
    for (int j = 0; j < M; ++j) {
      row.push_back(vals[i*M+j]);
    }
    grid.push_back(row);
  }
  return grid;
}

bool isMagicSqr(vector<vector<int>> & grid)
{
  int sum = 0;

  if (grid.size() == 0) return false;
  if (grid.size() != grid[0].size()) return false;

  int N = grid.size();
  cout << "Grid size: " << N << endl;
  for (int i = 0; i < N; ++i) {
    sum += grid[0][i];
  }
  cout << "Sum to check: " << sum << endl;

  // Check row sums
  for (int i = 0; i < N; ++i) {
    int rowSum = 0;
    for (int j = 0; j < N; ++j) {
      rowSum += grid[i][j];
    }
    cout << "Row " << i
         << " sum is: " << rowSum << endl;
    if (rowSum != sum) return false;
  }

  // Check col sums
  for (int i = 0; i < N; ++i) {
    int colSum = 0;
    for (int j = 0; j < N; ++j) {
      colSum += grid[j][i];
    }
    if (colSum != sum) return false;
  }

  // Check dia sums
  int diaSum = 0;
  for (int i = 0; i < N; ++i) {
    diaSum += grid[i][i];
  }

  if (diaSum != sum) return false;

  return true;
}
