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
  int day13;
  int week[7] = {0};
  int month[12] = {31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
  int number_of_years;

  cin >> number_of_years;
  day13 = 4;
  for (int year = 1900; year < (1900+number_of_years); year++)
    for (int mon = 0; mon < 12; mon++) {
      if (mon == 2)
        if ((((year % 4)==0) && ((year % 100)!=0)) || ((year % 400)==0))
          month[mon] = 29;
        else
          month[mon] = 28;
      day13 = (day13 + month[mon]) % 7;
      week[day13]++;
    }

  for (int day = 0; day < 7; day++) {
    cout << week[day] << " ";
  }
  cout << endl;

}
