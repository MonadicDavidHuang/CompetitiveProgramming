#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

string s;

int main(void) {
  // Here your code !

  cin >> s;

  string year = "";
  for (int i = 0; i < 4; ++i) {
    year += s[i];
  }

  string month = "";
  for (int i = 5; i < 7; ++i) {
    month += s[i];
  }

  string day = "";
  for (int i = 8; i < 10; ++i) {
    day += s[i];
  }

  if (stoi(year) <= 2019 && stoi(month) <= 4 && stoi(day) <= 30) {
    printf("Heisei\n");
  } else {
    printf("TBD\n");
  }

  return 0;
}
