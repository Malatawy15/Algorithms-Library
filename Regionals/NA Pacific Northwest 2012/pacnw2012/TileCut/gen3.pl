#
#   Generate denser solutions, but still with random-ish.
#   Keep track of perimeter; only add on perimeter.  We may
#   isolate some cells on the edges, but that's okay.
#
my $m = shift ;
my $n = shift ;
my %perim ;
my $x = $m-1  ; 
my $y = 0 ;
$perim{"$x,$y"} = 1 ;
$used{"$x,$y"} = 1 ;
my @dx = (-1, 1, 0, 0) ;
my @dy = (0, 0, 1, -1) ;
my @seq = qw(W I N) ;
while (keys %perim) {
   my @k = keys %perim ;
   my $k = @k[rand @k] ;
   my ($x, $y) = ($k =~ /(\d+),(\d+)/) ;
   my @coords = ($x, $y) ;
   delete $perim{$k} ;
   for ($s=0; $s<3; $s++) {
      my $nx = -1 ;
      my $ny = -1 ;
      my $ds = int rand 4 ;
      for ($dd=0; $dd<4; $dd++) {
         $d = ($dd + $ds) % 4 ;
         my $xx = $x + $dx[$d] ;
         my $yy = $y + $dy[$d] ;
         next if $xx < 0 || $yy < 0 || $xx >= $m || $yy >= $n ;
         my $kk = "$xx,$yy" ;
         if (!$used{$kk}) {
            $used{$kk}++ ;
            $perim{$kk}++ ;
         }
         if ($s < 2 && $nx < 0 && $perim{$kk}) {
            delete $perim{$kk} ;
            $nx = $xx ;
            $ny = $yy ;
         }
      }
      if ($nx >= 0) {
         $x = $nx ;
         $y = $ny ;
         $k = "$x,$y" ;
         push @coords, $x, $y ;
      }
   }
   my @let = () ;
   if (@coords == 6) {
      if (int rand 2) {
         @let = @seq ;
      } else {
         @let = reverse @seq ;
      }
      $good++ ;
   } else {
      @let = ($seq[rand @seq], $seq[rand @seq]) ;
   }
   for ($i=0; 2*$i<@coords; $i++) {
      $b[$coords[2*$i]][$coords[2*$i+1]] = $let[$i] ;
   }
}
for ($i=0; $i<$n; $i++) {
   for ($j=0; $j<$m; $j++) {
      print $b[$j][$i] ;
   }
   print "\n" ;
}
print "\n" ;
