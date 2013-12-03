#include <cstdio>
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
fpt half(pt &a, pt &b) {
   return make_pair(make_pair(a.first+b.first, 2LL),
                    make_pair(a.second+b.second,2LL)) ;
}
fpt solve3(pt &a, pt &b, pt &c) {
   fpt r = make_pair(make_pair(0LL, 0LL), make_pair(0LL, 0LL)) ;
   long long a1 = 2 * (a.first - b.first) ;
   long long b1 = 2 * (a.second - b.second) ;
   long long c1 = (a.first - b.first) * (a.first + b.first) +
                  (a.second - b.second) * (a.second + b.second) ;
   long long a2 = 2 * (a.first - c.first) ;
   long long b2 = 2 * (a.second - c.second) ;
   long long c2 = (a.first - c.first) * (a.first + c.first) +
                  (a.second - c.second) * (a.second + c.second) ;
   long long den = a1 * b2 - a2 * b1 ;
   if (den == 0)
      return r ;
   r.first.first = c1 * b2 - c2 * b1 ;
   r.second.first = a1 * c2 - a2 * c1 ;
   r.first.second = r.second.second = den ;
   return r ;
}
long long dist2(fpt c, pt p1) {
   long long dx = p1.first * c.first.second - c.first.first ;
   long long dy = p1.second * c.second.second - c.second.first ;
   return dx * dx + dy * dy ;
}
void tryit(fpt c, pt p1) {
   double den = (double)c.first.second ;
   long long disc = dist2(c, p1) ;
   double d = sqrt(disc / (den * den)) ;
   if (d >= res)
      return ;
   vector<int> onindices ;
   int onin = 0 ;
   int onoff = 0 ;
   for (int i=0; i<pts.size(); i++) {
      long long t = dist2(c, pts[i]) ;
      if (t == disc) {
         if (included[i])
            onin++ ;
         else
            onoff++ ;
         onindices.push_back(i) ;
      } else if (t > disc) {
         if (included[i])
            return ;
      } else {
         if (!included[i])
            return ;
      }
   }
   if (onin > 1 && onoff > 1) {
      int trans = 0 ;
      int hird = onindices[0] ;
      int lord = onindices[0] ;
      long long cy = c.second.first ;
      if (c.second.second < 0)
         cy = (- cy) / (- c.second.second) ;
      else
         cy = cy / c.second.second ;
      for (int i=1; i<onindices.size(); i++) {
         int ii = onindices[i] ;
         if (pts[ii].second <= cy) {
            if (included[ii] != included[lord])
               trans++ ;
            lord = ii ;
         } else {
            if (included[ii] != included[hird])
               trans++ ;
            hird = ii ;
         }
      }
      if (included[hird] != included[lord])
         trans++ ;
      if (trans > 2)
         return ;
   }
   res = d ;
}
vector<int> sortme ;
void process() {
   if (!havedata)
      return ;
   havedata = false ;
   sort(sortme.begin(), sortme.end()) ;
   pts.clear() ;
   included.clear() ;
   int inpts = 0 ;
   for (int i=0; i<sortme.size(); i++) {
      int v = sortme[i] ;
      pts.push_back(make_pair((v >> 16), (v >> 1) & 0x7fff)) ;
      included.push_back(v & 1) ;
      if (included[i])
         inpts++ ;
   }
   res = 0.0 ;
   if (inpts >= 2) {
      res = 1e20 ;
      for (int i=0; i<pts.size(); i++)
         if (included[i])
            for (int j=i+1; j<pts.size(); j++)
               if (included[j]) {
                  fpt c = half(pts[i], pts[j]) ;
                  tryit(c, pts[i]) ;
                  for (int k=0; k<pts.size(); k++) {
                     if (included[k] && k <= j)
                        continue ;
                     c = solve3(pts[i], pts[j], pts[k]) ;
                     if (c.first.second != 0)
                        tryit(c, pts[i]) ;
                  }
               }
   }
   sortme.clear() ;
   if (res == 1e20)
      printf("The Orcs are close\n") ;
   else
      printf("%.15g\n", res) ;
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
      while (scanf(" (%d,%d)", &x, &y) == 2)
         sortme.push_back((x<<16)+(y<<1)+((lineparity & 1) == 0)) ;
      scanf("none") ;
      if (lineparity & 1)
         process() ;
      lineparity++ ;
   }
}
