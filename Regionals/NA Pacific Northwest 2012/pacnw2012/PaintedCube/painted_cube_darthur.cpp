#include <assert.h>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

vector<int> choose_encode(1 << 26, -1);
vector<int> choose_decode;
void FillChooseEncode(int num_placed, int spot, int decode) {
  if (num_placed == 6) {
    choose_encode[decode] = choose_decode.size();
    choose_decode.push_back(decode);
    return;
  }
  if (spot >= 26) return;
  FillChooseEncode(num_placed, spot+1, decode);
  FillChooseEncode(num_placed+1, spot+1, decode + (1<<spot));
}

void FullDecode(int code, int* pos, int* bm) {
  *pos = code % 20;
  *bm = choose_decode[code / 20];
}
int FullEncode(int pos, int bm) { return pos + choose_encode[bm] * 20; }
int EncodeSize() { return 20 * choose_decode.size(); }

// Where do the new bits come from on each move?
// Move order: W, N, E, S
// Cube order: Floor, N, E, S, W, Sky
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int cube_perm[4][6] = {
  {4, 1, 0, 3, 5, 2},
  {1, 5, 2, 0, 4, 3},
  {2, 1, 5, 3, 0, 4},
  {3, 0, 2, 5, 4, 1}};
int RotateCube(int old_pattern, int dir) {
  int new_pattern = 0;
  for (int i = 0; i < 6; ++i) {
    int src = cube_perm[dir][i];
    if (old_pattern & (1 << src)) {
      new_pattern |= (1 << i);
    }
  }
  return new_pattern;
}
int rotate_cube[64][4];

int main() {
  // Precompute stuff.
  FillChooseEncode(0, 0, 0);
  for (int i = 0; i < 64; ++i)
    for (int d = 0; d < 4; ++d)
      rotate_cube[i][d] = RotateCube(i, d);

  while (true) {
    vector<string> board;
    string temp;
    while (getline(cin, temp) && !temp.empty()) {
      board.push_back(temp);
      assert(temp.size() == board[0].size());
    }
    if (board.empty()) return 0;

    int start_bm = 0, spots = 0;
    int start_y = -1, start_x = -1;
    int goal_y = -1, goal_x = -1;
    vector<vector<int> > spot_index(board.size(),
				    vector<int>(board[0].size(), -1));
    vector<int> spot_x, spot_y;
    for (int y = 0; y < board.size(); ++y)
      for (int x = 0; x < board[0].size(); ++x)
	if (board[y][x] != '#') {
	  spot_x.push_back(x);
	  spot_y.push_back(y);
	  spot_index[y][x] = spots;
	  if (board[y][x] == 'C') {
	    assert(start_y == -1);
	    start_y = y;
	    start_x = x;
	  }
	  if (board[y][x] == 'G') {
	    assert(goal_y == -1);
	    goal_y = y;
	    goal_x = x;
	  }
	  if (board[y][x] == 'P') start_bm += (1 << spots);
	  ++spots;
	}
    assert(start_y != -1);
    assert(goal_y != -1);
    int start_vertex = FullEncode(spot_index[start_y][start_x], start_bm << 6);
    int goal_vertex = FullEncode(spot_index[goal_y][goal_x], 63);

    vector<int> dist(EncodeSize(), -1);
    vector<int> q(1, start_vertex);
    int q_pos = 0;
    dist[start_vertex] = 0;
    while (q_pos < q.size()) {
      int v1 = q[q_pos++];
      int bm, pos1;
      FullDecode(v1, &pos1, &bm);
      assert(v1 >= 0 && v1 < dist.size());
      assert(pos1 >= 0 && pos1 < spot_x.size());
      int x = spot_x[pos1], y = spot_y[pos1];
      for (int d = 0; d < 4; ++d) {
	int x2 = x + dx[d];
	int y2 = y + dy[d];
	if (x2 < 0 || x2 >= board[0].size() ||
	    y2 < 0 || y2 >= board.size() ||
	    board[y2][x2] == '#') {
	  continue;
	}
	int bm2 = rotate_cube[bm & 63][d] | (bm & ~63);
	int bm_lookup = (1 << (spot_index[y2][x2] + 6));
	bool bit1 = (bm2 & 1) > 0;
	bool bit2 = (bm2 & bm_lookup) > 0;
	if (bit1 != bit2) bm2 ^= (1 | bm_lookup);
	int v2 = FullEncode(spot_index[y2][x2], bm2);
	if (v2 < 0 || v2 >= dist.size()) {
	  cout << x << " " << y << " " << bm << " " << d << endl;
	  cout << x2 << " " << y2 << " " << bm2 << endl;
	  cout << v2 << " " << dist.size() << endl;
	}
	assert(v2 >= 0 && v2 < dist.size());
	if (dist[v2] == -1) {
	  dist[v2] = dist[v1] + 1;
	  q.push_back(v2);
	}
	if (v2 == goal_vertex) break;
      }
    }
    cout << dist[goal_vertex] << endl;
  }
  return 0;
}
