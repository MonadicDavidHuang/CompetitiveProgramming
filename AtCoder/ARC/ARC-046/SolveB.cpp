#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

ll n;
ll a, b;

string takahashi = "Takahashi";
string aoki = "Aoki";

int main(void) {
  // Here your code !
  scanf("%lld", &n);

  scanf("%lld %lld", &a, &b);

  string winner;

  if (n <= a) {  // tak take all at first move, so tak win
    winner = takahashi;
  } else {  // n > a
    if (a == b) {
      if (n % (a + 1) == 0) {
        // aok can make tak never take all, no matter how tak take stones, so aok win
        // e.g. tak: i, aok: a - i + 1 (1 <= i <= a)
        winner = aoki;
      } else {
        // tak can take redudant fron n and make (n % (a + 1) == 0) stands
        // which means the game can be considered as start from aok with (n % (a + 1) == 0)
        // so with above's reason, tak win
        winner = takahashi;
      }
    } else {  // a != b
      if (a > b) {
        // tak can make aok never take all for following reason
        // while n > a, tak always take 1
        // then (n - 1) > (a - 1) >= b stands,
        // which means after tak's turn the number of remaining stones is always larger than aok's capacity
        // if n <= a tak just take all, so tak win
        winner = takahashi;
      } else {  // a < b
        // note that b >= n > a could stands, if so aok can take all no matter how tak take stones
        // for the case n > b > a, aok can make tak never take all for following reason
        // while n > b (after tak's turn, if n <= b just fall back to noted situation), aok always take 1
        // then (n - 1) > (b - 1) >= a stands,
        // which means after aok's turn the number of remaining stones is always larger than tak's capacity
        // if n <= b aok just take all, so aok win
        winner = aoki;
      }
    }
  }

  cout << winner << endl;

  return 0;
}
