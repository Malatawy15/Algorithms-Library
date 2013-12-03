
#include <iostream>

using namespace std;


long long count1(long long k);
long long solve(long long N);


long long count1(long long k) {  // counts the number of 1s in k
    long long ret = 0;
    while(k) {
        if (k & (long long)1) ret++;
        k = k >> 1;
    }
    return ret;
}



long long solve(long long N) {
    long long ret = 0;
	for (long long i = 1; i <= N; i++) {
		if (count1(i) % 3 == 0) ret++;
	}
    return ret;
}


int main () {
    long long N;
    cin >> N;
    while(!cin.eof()) {
        cout << "Day " << N << ": Level = " << solve(N) << endl;
        cin >> N;
    }
}

