my $max = 30 ;
for ($cnt=0; $cnt<20; $cnt++) {
   $m = 1 + rand $max ;
   $n = 1 + rand $max ;
   for ($i=0; $i<$n; $i++) {
      for ($j=0; $j<$m; $j++) {
         print (('W','I','N')[rand 3]) ;
      }
      print "\n" ;
   }
   print "\n" ;
}
