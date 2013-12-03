
#include <iostream>

using namespace std;


long long choose(long long n, long long r);
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


long long gcd(long long a, long long b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return gcd(b%a, a);
}


long long solve(long long N) {
    long long ret = 0;
    long long bits = 0;
    long long k = ((long long)1) << 60;
    long long r = 60;

    while(k) {
        if (k & N) {
            for (long long i = 0; i <= r; i++) {
                if (((i + bits) > 0) && ((i + bits) % 3 == 0)) {
                    ret += choose(r, i);
                }
            }

            bits++;
        }
        k = k >> 1;
        r--;
    }
    if ((bits > 0) && (bits % 3) == 0) ret++;
    return ret;
}


long long choose(long long n, long long r) {  // computes nCr for "small" n
    long long ret = 1;
    long long k, g;
    if (r > (n-r)) r = n-r;
    for (long long i = 1; i <= r; i++) {
        k = (n-i+1);
        g = gcd(k, i);
        ret = ret / (i/g) * (k/g);
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

