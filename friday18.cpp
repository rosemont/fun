/*******************************************************************
* USACO Friday the Thirteenth
* Input: 0 < N <= 400  in a period of N years
* Output: the number of times the 13th falls on Sat, Sun, Mon, ..., Fri
* Sample input: 
* $ 20
* Sample output:
* $ 36 33 34 33 35 35 34
********************************************************************/

#include <iostream>
using namespace std;

int main()
{
  int Jan13, Feb13, Mar13, Apr13, May13, Jun13, Jul13, Aug13, Sep13, Oct13, Nov13, Dec13;
  int week[7] = {0};
  int number_of_years;
  int leap;

  cin >> number_of_years;
  Dec13 = 4;
  for (int year = 1900; year < (1900+number_of_years); year++) {
    Jan13 = (Dec13 + 31) % 7;
    week[Jan13]++;
    Feb13 = (Jan13 + 31) % 7;
    week[Feb13]++;
    if ((year % 4) == 0) {
      leap = 29;
      if ((year % 100) == 0)
        leap = 28;
      if ((year % 400) == 0)
        leap = 29;
    } else
      leap = 28;
    Mar13 = (Feb13 + leap) % 7;
    week[Mar13]++;
    Apr13 = (Mar13 + 31) % 7;
    week[Apr13]++;
    May13 = (Apr13 + 30) % 7;
    week[May13]++;
    Jun13 = (May13 + 31) % 7;
    week[Jun13]++;
    Jul13 = (Jun13 + 30) % 7;
    week[Jul13]++;
    Aug13 = (Jul13 + 31) % 7;
    week[Aug13]++;
    Sep13 = (Aug13 + 31) % 7;
    week[Sep13]++;
    Oct13 = (Sep13 + 30) % 7;
    week[Oct13]++;
    Nov13 = (Oct13 + 31) % 7;
    week[Nov13]++;
    Dec13 = (Nov13 + 30) % 7;
    week[Dec13]++;
  }

  for (int day = 0; day < 7; day++) {
    cout << week[day] << " ";
  }

  cout << endl;

}
