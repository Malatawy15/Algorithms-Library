#include <assert.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

char vowel_cycle[] = {'a', 'i', 'y', 'e', 'o', 'u'};
int vowel_cycle_len = sizeof(vowel_cycle) / sizeof(vowel_cycle[0]);
char cons_cycle[] = {'b', 'k', 'x', 'z', 'n', 'h', 'd', 'c',
		     'w', 'g', 'p', 'v', 'j', 'q', 't', 's',
		     'r', 'l', 'm', 'f'};
int cons_cycle_len = sizeof(cons_cycle) / sizeof(cons_cycle[0]);

int main() {
  vector<char> mapping(256, -1);
  for (int i = 0; i < 256; ++i)
    mapping[i] = i;
  for (int i = 0; i < vowel_cycle_len; ++i) {
    mapping[vowel_cycle[i]] = vowel_cycle[(i + 3) % vowel_cycle_len];
    mapping[vowel_cycle[i] + 'A' - 'a'] =
      vowel_cycle[(i + 3) % vowel_cycle_len] + 'A' - 'a';
  }
  for (int i = 0; i < cons_cycle_len; ++i) {
    mapping[cons_cycle[i]] = cons_cycle[(i + 10) % cons_cycle_len];
    mapping[cons_cycle[i] + 'A' - 'a'] =
      cons_cycle[(i + 10) % cons_cycle_len] + 'A' - 'a';
  }

  string s;
  while (getline(cin, s)) {
    for (int i = 0; i < s.size(); ++i)
      s[i] = mapping[s[i]];
    cout << s << endl;
  }

  return 0;
}
