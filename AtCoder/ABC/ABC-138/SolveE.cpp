#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

string s;
string t;

string dup_s;
vector<map<char, ll>> acc;

bool check(int next, int pos, char target) {
  return (acc[next][target] - acc[pos][target]) >= 1;
}

ll search(int pos, char target) {
  int ok = dup_s.size();
  int ng = pos;

  while (abs(ok - ng) > 1) {
    int next = (ok + ng) / 2;

    if (check(next, pos, target)) {
      ok = next;
    } else {
      ng = next;
    }
  }

  return ok - pos;
}

ll ans;

int main(void) {
  // Here your code !
  cin >> s;
  cin >> t;

  set<char> set_s;
  for (auto &e : s) {
    set_s.insert(e);
  }

  for (auto &e : t) {
    if (set_s.find(e) == set_s.end()) {
      printf("-1\n");
      return 0;
    }
  }

  dup_s = s + s;

  map<char, ll> cnt;

  for (int i = 0; i < dup_s.size(); ++i) {
    cnt[dup_s[i]] += 1;
    acc.push_back(cnt);
  }

  int pos;

  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == t[0]) {
      pos = i;
      break;
    }
  }

  ans = pos;

  for (int i = 0; i < t.size() - 1; ++i) {
    pos %= s.size();

    int commit = search(pos, t[i + 1]);

    pos += commit;

    ans += commit;
  }

  ans += 1LL;

  printf("%lld\n", ans);

  return 0;
}
