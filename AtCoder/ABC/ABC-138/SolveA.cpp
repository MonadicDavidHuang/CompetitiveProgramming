#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int a;

string s;

int main(void) {
  // Here your code !
  scanf("%d", &a);

  cin >> s;

  if (a >= 3200) {
    cout << s << endl;
  } else {
    cout << "red" << endl;
  }

  return 0;
}
