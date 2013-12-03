#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
  vector<int> v;
  ll N, E, P;
  while (cin >> N >> E >> P) {
    if (N == 0) break;
    vector<ll> e(N), p(N), parent(N);
    for (int i = 0; i < N; ++i) cin >> e[i] >> p[i] >> parent[i];
    double best_slope = 0;
    for (int i = 0; i < N; i++) {
      double temp_e = 0, temp_p = 0;
      int pos = i;
      double sub = 0;
      while (pos != -1) {
        sub = e[pos] / 2.0;
        temp_e += e[pos];
        temp_p += p[pos];
	      pos = parent[pos] - 1;
        best_slope = max(best_slope, double(temp_p) / temp_e);
        temp_e -= sub;
      }
    }

    // power_0 = E * best_slope
    // dpower = power * best_slope
    // power = e^(best_slope*t) * (E*best_slope)
    // e^(best_slope*t) = P / (E*best_slope)
    // best_slope = ln(P / E*best_slope) / best_slope
    if (P < E*best_slope) {
      cout << 0 << endl;
    } else {
      double x = log(P / (E*best_slope)) / best_slope;
      cout << ll(x + 0.99999999999) << endl;
    }
  }
  return 0;
}
