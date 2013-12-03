#
#   Generate som boards.
#
my $maxdimen = 20 ;
sub add {
   my ($x, $y) = @_ ;
   my $key = "$x,$y" ;
   $seen{$key} = '#' if !defined($seen{$key}) ;
}
while (1) {
   $n = 8 + int rand 13 ;
   %seen = () ;
   $seen{"0,0"} = '#' ;
   $cnt = 0 ;
   @ord = qw(G C P P P P P P) ;
   push @ord, '.' while @ord < $n ;
   for ($i=0; $i<$n; $i++) {
      $j = $i + int rand($n-$i) ;
      $t = $ord[$i] ; $ord[$i] = $ord[$j] ; $ord[$j] = $t ;
   }
   my $minx = 0 ;
   my $miny = 0 ;
   my $maxx = 0 ;
   my $maxy = 0 ;
   while ($cnt < $n) {
      @t = keys %seen ;
      $x = $t[rand @t] ;
      if ($seen{$x} eq '#') {
         $seen{$x} = $ord[$cnt] ;
         $cnt++ ;
         my ($x, $y) = split ",", $x ;
         add($x-1, $y) ;
         add($x+1, $y) ;
         add($x, $y-1) ;
         add($x, $y+1) ;
         $minx = $x if $x < $minx ;
         $miny = $y if $y < $miny ;
         $maxx = $x if $x > $maxx ;
         $maxy = $y if $y > $maxy ;
      }
   }
   next if ($maxx - $minx + 1 > $maxdimen ||
	    $maxy - $miny + 1 > $maxdimen) ;
   if (int rand 2) {
       if (int rand 2) {
	   $maxx = $minx + $maxdimen - 1 ;
       } else {
	   $minx = $maxx - $maxdimen + 1 ;
       }
   }
   if (int rand 2) {
       if (int rand 2) {
	   $maxy = $miny + $maxdimen - 1 ;
       } else {
	   $miny = $maxy - $maxdimen + 1 ;
       }
   }
   for ($y=$miny; $y<=$maxy; $y++) {
      for ($x=$minx; $x<=$maxx; $x++) {
         print $seen{"$x,$y"} || '#' ;
      }
      print "\n" ;
   }
   print "\n" ;
}
