#include <stdint.h>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

// Goal: compute sum_{i < j} 1{mapping[i] > mapping[j]}
int64_t solve(std::vector<int> &mapping, int left, int right) {
  if (right - left <= 1) return 0;

  // partition array and solve each half
  const int mid = (left + right) / 2;
  int64_t num_pairs = 0;
  num_pairs += solve(mapping, left, mid);
  num_pairs += solve(mapping, mid, right);

  // merge sort
  std::vector<int> copy;
  int i = left;
  int j = mid;
  while (i < mid && j < right) {
    if (mapping[i] < mapping[j]) {
      copy.push_back(mapping[i++]);
    } else if (mapping[j] < mapping[i]) {
      num_pairs += mid - i;
      copy.push_back(mapping[j++]);
    }
  }
  while (i < mid)
    copy.push_back(mapping[i++]);
  while (j < right)
    copy.push_back(mapping[j++]);
  std::copy(copy.begin(), copy.end(), mapping.begin() + left);
  return num_pairs;
}

int64_t solve(std::vector<std::pair<std::string, int> > &original,
              std::vector<std::pair<std::string, int> > &revised) {
  std::sort(original.begin(), original.end());
  std::sort(revised.begin(), revised.end());
  std::vector<int> mapping(original.size());
  for (size_t i = 0; i < original.size(); ++i)
    mapping[original[i].second] = revised[i].second;
  return solve(mapping, 0, mapping.size());
}

std::vector<std::pair<std::string, int> > read_seating_chart(int n) {
  std::vector<std::pair<std::string, int> > chart;
  for (int i = 0; i < n; ++i) {
    std::string s;
    std::cin >> s;
    chart.push_back(std::make_pair(s, i));
  }
  return chart;
}

int main() {
  int n;
  //srand48(0);
  while (std::cin >> n) {
    if (n == 0) break;
    std::vector<std::pair<std::string, int> > original = read_seating_chart(n);
    std::vector<std::pair<std::string, int> > revised = read_seating_chart(n);
    std::cout << solve(original, revised) << std::endl;
  }
  return 0;
}
