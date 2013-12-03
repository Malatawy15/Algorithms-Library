#include <iostream>
#include <vector>

using namespace std;

typedef vector<string> VS;
typedef vector<int> VI;
typedef vector<VI> VVI;

const int INF = 1000000000;

struct MaxFlow {
  int N;
  VVI cap;
  VI seen;

  MaxFlow(int N) :
    N(N), cap(N, VI(N)), seen(N) {}

  void AddEdge(int from, int to, int cap) {
    this->cap[from][to] += cap;
  }

  int Augment(int here, int sink, int amt) {
    if (here == sink) return amt;
    seen[here] = true;
    for (int i = 0; i < N; ++i) {
      if (!seen[i] && cap[here][i]) {
        int ret = Augment(i, sink, min(amt, cap[here][i]));
        if (ret) {
          cap[here][i] -= ret;
          cap[i][here] += ret;
          return ret;
        }
      }
    }
    return 0;
  }

  int GetMaxFlow(int source, int sink) {
    int ret = 0;
    while (true) {
      fill(seen.begin(), seen.end(), false);
      int flow = Augment(source, sink, INF);
      if (!flow) break;
      ret += flow;
    }
    return ret;
  }
};

int solve(const VS &grid) {
  const int m = grid.size();
  const int n = grid[0].length();
  const int source = 2 * m * n;
  const int sink = 2 * m * n + 1;
  const int in = 0;
  const int out = m * n;
  MaxFlow mf(2 * m * n + 2);

  const int dr[] = {1, 0, -1, 0};
  const int dc[] = {0, 1, 0, -1};
  for (size_t i = 0; i < m; ++i) {
    for (size_t j = 0; j < n; ++j) {
      mf.AddEdge(i*n+j+in, i*n+j+out, 1);
      switch (grid[i][j]) {
        case 'W': mf.AddEdge(source, i*n+j+in, 1); break;
        case 'I':
          for (int d = 0; d < 4; ++d) {
            const int ni = i + dr[d];
            const int nj = j + dc[d];
            if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
            switch (grid[ni][nj]) {
              case 'W': mf.AddEdge(ni*n+nj+out, i*n+j+in, 1); break;
              case 'N': mf.AddEdge(i*n+j+out, ni*n+nj+in, 1); break;
            }
          }
          break;
        case 'N': mf.AddEdge(i*n+j+out, sink, 1); break;
      }
    }
  }
  return mf.GetMaxFlow(source, sink);
}

int main() {
  while (true) {
    string s;
    vector<string> grid;
    while (getline(cin, s)) {
      if (s.length() == 0) break;
      grid.push_back(s);
    }
    if (grid.size() == 0) break;
    cout << solve(grid) << endl;
  }
  return 0;
}
