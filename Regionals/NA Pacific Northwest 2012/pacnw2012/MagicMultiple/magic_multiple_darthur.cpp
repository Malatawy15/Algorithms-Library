#include <assert.h>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int Add(ll x, int bm) {
  while (x > 0) {
    int d = x % 10;
    bm |= (1 << d);
    x /= 10;
  }
  return bm;
}

int main() {
  ll value;
  while (cin >> value) {
    int bm = 0, k;
    for (k = 1; bm + 1 != (1 << 10); ++k) {
      assert(k <= 100);
      bm = Add(value * k, bm);
    }
    cout << (k - 1) << endl;
  }
  return 0;
}

