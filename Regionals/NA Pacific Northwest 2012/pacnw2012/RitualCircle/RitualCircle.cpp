#include <cstdio>
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std ;
typedef pair<long long,long long> pt ;
typedef pair<long long,long long> frac ;
typedef pair<frac,frac> fpt ;
vector<pt> pts ;
vector<bool> included ;
double res ;
bool havedata = false ;
pt half(pt &a, pt &b) {
   return make_pair((a.first+b.first)/2, (a.second+b.second)/2) ;
}
long long dist2(pt a, pt b) {
   return (a.first - b.first) * (a.first - b.first) +
          (a.second - b.second) * (a.second - b.second) ;
}
long long cross(pt a, pt b, pt c) {
   return (b.first - a.first) * (c.second - a.second) -
          (b.second - a.second) * (c.first - a.first) ;
}
bool operator<(const frac &a, const frac &b) {
   return a.first * b.second < a.second * b.first ;
}
bool operator==(const frac &a, const frac &b) {
   return a.first * b.second == a.second * b.first ;
}
frac make_frac(long long num, long long den) {
   if (den < 0)
      return make_pair(-num, -den) ;
   else
      return make_pair(num, den) ;
}
void process() {
   if (!havedata)
      return ;
   havedata = false ;
   int inpts = 0 ;
   for (int i=0; i<included.size(); i++)
      if (included[i])
         inpts++ ;
   res = 0.0 ;
   if (inpts >= 2) {
      res = 1e20 ;
      for (int i=0; i<pts.size(); i++)
         if (included[i])
            for (int j=i+1; j<pts.size(); j++)
               if (included[j]) {
                  pt c = half(pts[i], pts[j]) ;
                  long long dc = dist2(pts[i], c) ;
                  frac leftbound = make_pair(-1000000000LL, 1LL) ;
                  frac rightbound = make_pair(1000000000LL, 1LL) ;
                  bool leftstrict = false ;
                  bool rightstrict = false ;
                  bool fail = false ;
                  for (int k=0; !fail && k<pts.size(); k++) {
                     if (k != i && k != j) {
                        long long num = dist2(c, pts[k]) - dc ;
                        long long den = cross(c, pts[j], pts[k]) ;
                        if (den == 0) {
                           if (num > 0) {
                              if (included[k])
                                 fail = true ;
                           } else {
                              if (!included[k])
                                 fail = true ;
                           }
                        } else {
                           frac bz = make_frac(-num, den) ;
                           if (den > 0) {
                              if (included[k]) {
                                 if (bz < rightbound) {
                                    rightbound = bz ;
                                    rightstrict = false ;
                                 }
                              } else {
                                 if (leftbound < bz) {
                                    leftbound = bz ;
                                    leftstrict = true ;
                                 } else if (leftbound == bz)
                                    leftstrict = true ;
                              }
                           } else {
                              if (included[k]) {
                                 if (leftbound < bz) {
                                    leftbound = bz ;
                                    leftstrict = false ;
                                 }
                              } else {
                                 if (bz < rightbound) {
                                    rightbound = bz ;
                                    rightstrict = true ;
                                 } else if (bz == rightbound)
                                    rightstrict = true ;
                              }
                           }
                        }
                        if ((rightbound < leftbound) ||
                            (rightbound == leftbound &&
                             (leftstrict || rightstrict))) {
                           fail = true ;
                        }
                     }
                  }
                  if (!fail) {
                     frac x = make_pair(0LL, 1LL) ;
                     if (rightbound < x)
                        x = rightbound ;
                     else if (x < leftbound)
                        x = leftbound ;
                     double v = 0.5 * (double)(x.first) / (double)(x.second) ;
                     v = 0.5 * sqrt(((double)dc) * (1.0 + v * v)) ;
                     if (v < res)
                        res = v ;
                  }
               }
   }
   if (res == 1e20)
      printf("The Orcs are close\n") ;
   else
      printf("%.15g\n", res) ;
   pts.clear() ;
   included.clear() ;
}
int main(int argc, char *argv[]) {
   long long n ;
   int x, y ;
   int lineparity = 0 ;
   while (1) {
      int c ;
      while ((c=getchar()) != ':')
         if (c == EOF)
            exit(0) ;
      if (lineparity & 1)
         havedata = true ;
      while (scanf(" (%d,%d)", &x, &y) == 2) {
         pts.push_back(make_pair(2LL*x, 2LL*y)) ;
         included.push_back((lineparity & 1) == 0) ;
      }
      scanf("none") ;
      if (lineparity & 1)
         process() ;
      lineparity++ ;
   }
}
