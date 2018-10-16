#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int n;
string s;

pair<bool, string> check(string inits) {
  for (int i = 2; i < n; ++i) {
    if (inits[i - 1] == 'S') {  // S say
      if (inits[i - 2] == 'S') {
        if (s[i - 1] == 'o') {
          inits.push_back('S');
        } else {
          inits.push_back('W');
        }
      } else {
        if (s[i - 1] == 'o') {
          inits.push_back('W');
        } else {
          inits.push_back('S');
        }
      }
    } else {  // W say
      if (inits[i - 2] == 'S') {
        if (s[i - 1] == 'o') {
          inits.push_back('W');
        } else {
          inits.push_back('S');
        }
      } else {
        if (s[i - 1] == 'o') {
          inits.push_back('S');
        } else {
          inits.push_back('W');
        }
      }
    }
  }

  char fst;

  if (inits[n - 1] == 'S') {  // S say
    if (inits[n - 2] == 'S') {
      if (s[n - 1] == 'o') {
        fst = 'S';
      } else {
        fst = 'W';
      }
    } else {
      if (s[n - 1] == 'o') {
        fst = 'W';
      } else {
        fst = 'S';
      }
    }
  } else {  // W say
    if (inits[n - 2] == 'S') {
      if (s[n - 1] == 'o') {
        fst = 'W';
      } else {
        fst = 'S';
      }
    } else {
      if (s[n - 1] == 'o') {
        fst = 'S';
      } else {
        fst = 'W';
      }
    }
  }

  char snd;

  if (inits[0] == 'S') {  // S say
    if (inits[n - 1] == 'S') {
      if (s[0] == 'o') {
        snd = 'S';
      } else {
        snd = 'W';
      }
    } else {
      if (s[0] == 'o') {
        snd = 'W';
      } else {
        snd = 'S';
      }
    }
  } else {  // W say
    if (inits[n - 1] == 'S') {
      if (s[0] == 'o') {
        snd = 'W';
      } else {
        snd = 'S';
      }
    } else {
      if (s[0] == 'o') {
        snd = 'S';
      } else {
        snd = 'W';
      }
    }
  }

  if (fst == inits[0] && snd == inits[1]) {
    return make_pair(true, inits);
  } else {
    return make_pair(false, inits);
  }
}

int main(void) {
  // Here your code !
  scanf("%d", &n);
  cin >> s;

  string str_ss = "SS";
  auto pair_ss = check(str_ss);

  if (pair_ss.first) {
    cout << pair_ss.second << endl;
    return 0;
  }

  string str_sw = "SW";
  auto pair_sw = check(str_sw);

  if (pair_sw.first) {
    cout << pair_sw.second << endl;
    return 0;
  }

  string str_ws = "WS";
  auto pair_ws = check(str_ws);

  if (pair_ws.first) {
    cout << pair_ws.second << endl;
    return 0;
  }

  string str_ww = "WW";
  auto pair_ww = check(str_ww);

  if (pair_ww.first) {
    cout << pair_ww.second << endl;
    return 0;
  }

  printf("-1\n");

  return 0;
}
