#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int n;

// return pair of (node, dist)
pair<int, int> calc_longest(int root) {
  int dist = -1;
  int node = 0;

  map<int, int> mp;

  for (int i = 1; i <= n; ++i) {
    if (i == root) continue;

    int cur_dist;
    cout << "? " << root << " " << i << endl;
    cin >> cur_dist;

    if (cur_dist > dist) {
      dist = cur_dist;
      node = i;
      mp[i] = dist;
    }
  }

  return make_pair(node, dist);
}

int main(void) {
  // Here your code !
  scanf("%d", &n);

  int v = calc_longest(1).first;
  int diameter = calc_longest(v).second;

  cout << "! " << diameter << endl;

  return 0;
}
