#include <algorithm>
#include <assert.h>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

struct Point {
  ll ox, oy;
  ll x, y;
  bool negative;
};

bool operator<(const Point& p1, const Point& p2) {
  return p1.y * p2.x - p1.x * p2.y > 0;
}

int main() {
  int N, W, H;
  while (cin >> N >> W >> H) {
    if (N == 0) break;
    vector<Point> points;

    int num_neg = 0;
    for (int i = 0; i < N; ++i) {
      Point p;
      cin >> p.ox >> p.oy;
      p.x = 2*p.ox - W;
      p.y = 2*p.oy - H;
      p.negative = (p.y < 0) || (p.y == 0 && p.x < 0);
      if (p.negative) {
	p.negative = true;
	p.x = -p.x;
	p.y = -p.y;
	++num_neg;
      }
      points.push_back(p);
    }
    sort(points.begin(), points.end());

    int cutoff;
    for (cutoff = 0; 2*num_neg != points.size(); ++cutoff) {
      assert(cutoff < points.size());
      if (points[cutoff].negative) {
	num_neg--;
      } else {
	num_neg++;
      }
    }

    for (int i = 0; i < points.size(); ++i) {
      if (!(points[i].negative ^ (i < cutoff))) {
	cout << points[i].ox << " " << points[i].oy << endl;
      }
    }
  }
  return 0;
}
