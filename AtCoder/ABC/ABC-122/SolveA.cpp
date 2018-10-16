#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

char b;

char ans;

int main(void) {
  // Here your code !
  scanf("%c", &b);

  if (b == 'A')
    ans = 'T';
  else if (b == 'C')
    ans = 'G';
  else if (b == 'G')
    ans = 'C';
  else
    ans = 'A';

  printf("%c\n", ans);

  return 0;
}
