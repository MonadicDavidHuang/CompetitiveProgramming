#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

/////////////////////////////////////////////////////////////
class FastFourierTransform {
 public:
  using C = complex<double>;

  void dft(vector<C> &f, int m, int v) {
    if (m == 1) return;

    vector<C> f0(m / 2), f1(m / 2);
    for (int i = 0; i < m / 2; ++i) f0[i] = f[2 * i];
    for (int i = 0; i < m / 2; ++i) f1[i] = f[2 * i + 1];

    dft(f0, m / 2, v);
    dft(f1, m / 2, v);

    C z(cos(M_PI / (m / 2)), sin(M_PI / (m / 2)) * v);
    C pow = 1;

    for (int i = 0; i < m; ++i) {
      f[i] = f0[i % (m / 2)] + f1[i % (m / 2)] * pow;
      pow *= z;
    }
  }

  vector<ll> multiply(vector<C> &g, vector<C> &h) {
    int t = (int)(g.size() + h.size()) + 1;

    int n = 1;
    while (n <= t) n <<= 1;

    g.resize(n);
    h.resize(n);

    dft(g, n, 1);
    dft(h, n, 1);

    vector<C> gh(n);
    for (int i = 0; i < n; ++i) gh[i] = g[i] * h[i];
    dft(gh, n, -1);

    for (int i = 0; i < n; ++i) gh[i] /= C(n, 0);

    vector<ll> ret(n);

    for (int i = 0; i < n; ++i) ret[i] = llround(gh[i].real());

    return ret;
  }

  vector<ll> multiply(vector<int> &g, vector<int> &h) {
    vector<C> gc(g.size());
    vector<C> hc(h.size());

    for (int i = 0; i < g.size(); ++i) {
      gc[i].real(g[i]);
    }

    for (int i = 0; i < h.size(); ++i) {
      hc[i].real(h[i]);
    }

    return multiply(gc, hc);
  }
};
/////////////////////////////////////////////////////////////

int main(void) {
  // Here your code !
  vector<int> g{1, 1, 4, 5, 1, 4, 19, 19};
  vector<int> h{810, 931, 931};

  vector<ll> gh_brutal(g.size() + h.size() + 2);

  for (int i = 0; i < g.size(); ++i) {
    for (int j = 0; j < h.size(); ++j) {
      gh_brutal[i + j] += (ll)(g[i] * h[j]);
    }
  }

  FastFourierTransform fft;

  auto gh = fft.multiply(g, h);

  for (int i = 0; i < gh_brutal.size(); ++i) {
    printf("%lld %lld\n", gh_brutal[i], gh[i]);
  }

  return 0;
}
