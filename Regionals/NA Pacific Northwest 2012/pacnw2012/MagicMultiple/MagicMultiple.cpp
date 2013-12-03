#include <iostream>
using namespace std ;
int main(int argc, char *argv[]) {
   long long n ;
   while (1) {
      cin >> n ;
      if (cin.eof())
         break ;
      int digs = 0 ;
      int k = 0 ;
      while (digs != 0x3ff) {
         k++ ;
         long long w = n * k ;
         while (w > 0) {
            digs |= 1<<(w % 10) ;
            w /= 10 ;
         }
      }
      cout << k << endl ;
   }
}
