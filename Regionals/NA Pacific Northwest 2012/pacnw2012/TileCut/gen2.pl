$m = shift ;
$n = shift ;
for ($cnt=0; $cnt<1; $cnt++) {
   for ($i=0; $i<$n; $i++) {
      for ($j=0; $j<$m; $j++) {
         print (('W','I','N')[rand 3]) ;
      }
      print "\n" ;
   }
   print "\n" ;
}
