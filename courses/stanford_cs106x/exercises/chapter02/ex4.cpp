/*
 * Function: windChill
 * -------------------
 * Displays the table showing the relation between wind speed (mph) and
 * temperature (F). See page 117
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;

string error(string msg) {
  cout << "ERROR: " << msg << endl;
  exit(EXIT_FAILURE);
}

double windChill(double temperature) {
  return temperature;
}

int windChill(double t, double v)
{
  if (t > 40) error("Temperature should not exceed 40 F.");
  double windChill = 35.74 + 0.6215 * t - 35.75 * pow(v, 0.16) + 0.4275 * t * pow(v, 0.16);
  return windChill > 0 ? (int) (windChill + 0.5) : (int) (windChill - 0.5);
}

/*
 * Suppose we do not know the stream manipulators yet and the table
 * wil not be fully/perfectly aligned
 */
int main()
{
  double result = windChill(25);
  cout << "No Wind chill as there is only temperature: " << result << "F." << endl;

  double windv = 5;
  double temp = 25;
  cout << "Wind chill at wind speed " << windv << " and "
       << " temperature " << temp << " : "
       << windChill(temp, windv) << endl;

  cout << "Calm" << " ";
  for (int t=40; t >= -45; t-=5) {
    if (t == -45)
      cout << " " << t << endl; // whitespace before t is for minus sign
    else
      cout << " " << t << " ";
  }

  for (int v=5; v<=60; v+=5) {
    if (v < 10)
      cout << v << "  " << " " << " "; // Explicitly show the number of ws
    else
      cout << v << "  " << " "; // Explicitly show the number of ws

    for (int t=40; t>=-45; t-=5) {
      if (t == -45)
        cout << " " << windChill(t,v) << endl;
      else
        cout << " " << windChill(t,v) << " ";
    }
  }
  return 0;
}
