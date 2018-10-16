#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e2 + 5);

int n, k;
char a[MAX_N];

char b[MAX_N];
multiset<char> whole;

string ans;

bool check_inner(int index, int remain, multiset<char> store) {
  if (index == n) {
    return true;
  }

  for (int i = index; i < n; ++i) {
    auto ptr = store.find(a[i]);
    if (ptr != store.end()) store.erase(ptr);
  }

  return (remain >= (int)(store.size()));
}

pair<char, bool> check(int index, int remain, multiset<char> store) {
  for (auto &e : store) {
    multiset<char> tmp_store(store);
    int tmp_remain = remain;

    auto ptr = tmp_store.find(e);
    tmp_store.erase(ptr);

    tmp_remain -= (e == a[index]) ? 0 : 1;

    if (check_inner(index + 1, tmp_remain, tmp_store)) {
      return make_pair(e, true);
    }
  }

  return make_pair('a', false);
}

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &k);
  scanf("%s", &a);

  for (int i = 0; i < n; ++i) {
    whole.insert(a[i]);
  }

  int remain = k;
  multiset<char> store(whole);

  int break_index = n;

  for (int i = 0; i < n; ++i) {
    auto result = check(i, remain, store);

    if (result.second) {
      char frnt = result.first;

      auto ptr = store.find(frnt);
      store.erase(ptr);

      remain -= (frnt == a[i]) ? 0 : 1;

      ans.push_back(frnt);
    } else {
      break_index = i;
      break;
    }
  }

  for (int i = break_index; i < n; ++i) {
    auto ptr = whole.find(a[i]);

    if (ptr == whole.end()) {
      ans.push_back('!');
    } else {
      ans.push_back(a[i]);
      whole.erase(ptr);
    }
  }

  for (auto &e : ans) {
    if (e == '!') {
      char cur = *whole.begin();
      printf("%c", cur);

      auto ptr = whole.find(cur);
      whole.erase(ptr);
    } else {
      printf("%c", e);
    }
  }

  printf("\n");

  return 0;
}
