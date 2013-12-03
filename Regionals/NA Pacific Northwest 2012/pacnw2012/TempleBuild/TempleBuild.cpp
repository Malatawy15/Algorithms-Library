#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std ;
const int MAX = 1000000 ;
long long best[MAX+1] ;
int main(int argc, char *argv[]) {
   long long height, lobase, hibase ;
   int bricks[3] ;
   while (1) {
      cin >> height >> lobase >> hibase ;
      if (cin.eof())
         break ;
      cin >> bricks[0] >> bricks[1] >> bricks[2] ;
      memset(best, -1, sizeof(best)) ;
      best[0] = 0 ;
      long long r = 0 ;
      for (int i=1; i<=height; i++)
         for (int b=0; b<3; b++)
            if (i >= bricks[b] && best[i-bricks[b]] >= 0) {
               long long w =
                (hibase + (lobase - hibase) * (height-i) / height) / bricks[b] ;
               long long t = best[i-bricks[b]] +
                                         w * w * bricks[b]*bricks[b]*bricks[b] ;
               if (t > best[i]) {
                  best[i] = t ;
                  if (t > r)
                     r = t ;
               }
            }
      cout << r << endl ;
   }
}
