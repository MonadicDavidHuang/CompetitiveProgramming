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

int k, a, b;

int main() {
  scanf("%d", &k);

  vector<FastFourierTransform::C> g(k + 1), h(k + 1);

  for (int i = 0; i < k; ++i) {
    scanf("%d %d", &a, &b);
    g[i + 1].real(a);
    h[i + 1].real(b);
  }

  FastFourierTransform fft;

  auto c = fft.multiply(g, h);
  for (int i = 0; i < 2 * k; ++i) printf("%lld\n", c[i + 1]);
}
