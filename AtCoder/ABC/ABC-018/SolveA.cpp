#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

vector<pair<int, int>> alphabets;

int main(void) {
  // Here your code !
  for (int i = 0; i < 3; ++i) {
    int score;
    scanf("%d", &score);
    alphabets.push_back(make_pair(score, i));
  }

  sort(alphabets.begin(), alphabets.end(), greater<pair<int, int>>());

  map<int, int> mp;

  for (int i = 1; i <= 3; ++i) {
    mp[alphabets[i - 1].second] = i;
  }

  for (auto &e : mp) {
    printf("%d\n", e.second);
  }

  return 0;
}
