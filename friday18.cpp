#include <iostream>
using namespace std;

int main()
{
  int Jan13, Feb13, Mar13, Apr13, May13, Jun13;
  int Jul13, Aug13, Sep13, Oct13, Nov13, Dec13;
  int week[7] = {0};

  Dec13 = 0;
  for (int year = 1900; year < 2000; year++) {
    Jan13 = (Dec13 + 31) % 7;
    week[Jan13]++;
    Feb13 = (Jan13 + 30) % 7;
    week[Feb13]++;
    Mar13 = (Feb13 + 28) % 7;
    week[Mar13]++;
    Apr13 = (Mar13 + 30) % 7;
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
    Oct13 = (Sep13 + 31) % 7;
    week[Oct13]++;
    Nov13 = (Oct13 + 30) % 7;
    week[Nov13]++;
    Dec13 = (Nov13 + 30) % 7;
    week[Dec13]++;
  }

  for (int day = 0; day < 7; day++) {
    cout << week[day] << " ";
  }

  cout << endl;

}
