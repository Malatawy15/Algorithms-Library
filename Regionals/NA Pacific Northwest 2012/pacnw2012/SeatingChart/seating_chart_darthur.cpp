#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;

ll CountInversions(vector<int>& v) {
  if (v.size() == 1) return 0;
  vector<int> v1, v2;
  for (int i = 0; i < v.size() / 2; ++i)
    v1.push_back(v[i]);
  for (int i = v.size() / 2; i < v.size(); ++i)
    v2.push_back(v[i]);
  ll result = CountInversions(v1) + CountInversions(v2);

  int i1 = 0, i2 = 0, i = 0;
  while (i1 < v1.size() || i2 < v2.size()) {
    int x1 = (i1 < v1.size() ? v1[i1] : 9999999);
    int x2 = (i2 < v2.size() ? v2[i2] : 9999999);
    if (x1 < x2) {
      v[i++] = x1;
      ++i1;
    } else {
      v[i++] = x2;
      ++i2;
      result += (v1.size() - i1);
    }
  }
  return result;
}

int main() {
  int n;
  string temp;
  while (cin >> n) {
    if (n == 0) break;
    map<string, int> frodo_pos;
    for (int i = 0; i < n; ++i) {
      cin >> temp;
      frodo_pos[temp] = i;
    }
    vector<int> sam;
    for (int i = 0; i < n; ++i) {
      cin >> temp;
      sam.push_back(frodo_pos[temp]);
    }
    cout << CountInversions(sam) << endl;
  }
  return 0;
}
