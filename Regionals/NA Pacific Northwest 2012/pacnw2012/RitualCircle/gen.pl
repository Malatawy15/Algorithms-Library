#
#   Generate RitualCircle test cases.
#
#   First, test some borderline cases.
#
my $mx = 100 ;
my $mxpts = 300 ;
sub out2 {
   my ($str, $dat) = @_ ;
   print "$str:" ;
   my @dat = split " ", $dat ;
   print " ($_)" for @dat ;
   print "\n" ;
}
sub test {
   my $s = shift ;
   my @inout = split "/", $s ;
   out2("Included", $inout[0]) ;
   out2("Excluded", $inout[1]) ;
}
test("/") ;
test("/50,50") ;
test("50,50/") ;
test("0,0 0,1 1,0/1,1") ;
test("0,0 0,1 1,0 1,1/") ;
test("0,0 0,1/1,0 1,1") ;
test("0,0 1,1/1,0 0,1") ;
test("0,0 100,100/") ;
test("0,0 100,100/50,50") ;
test("0,0 100,100/50,51") ;
test("0,0 98,100/48,49") ;
#
#   Some interesting cases.
#
sub d {
   my ($x1, $y1, $x2, $y2) = @_ ;
   $x1 -= $x2 ;
   $y1 -= $y2 ;
   return $x1 * $x1 + $y1 * $y1 ;
}
sub gcd2 {
   my ($a, $b) = @_ ;
   return gcd2($b, $a) if $a > $b ;
   return $b if $a == 0 ;
   return gcd2($b % $a, $a) ;
}
sub gcd {
   my ($a, $b) = @_ ;
   $a = - $a if $a < 0 ;
   $b = - $b if $b < 0 ;
   return 1 if $a == 0 || $b == 0 ;
   return gcd2($a, $b) ;
}
$cnt = 0 ;
while ($cnt < 200) {
   my @p1 = (int rand $mx, int rand $mx) ;
   my @p2 = (int rand $mx, int rand $mx) ;
   my @p3 = (int rand $mx, int rand $mx) ;
   $a1 = 2 * ($p1[0]-$p2[0]) ;
   $b1 = 2 * ($p1[1]-$p2[1]) ;
   $c1 = ($p1[0]-$p2[0])*($p1[0]+$p2[0]) + ($p1[1]-$p2[1])*($p1[1]+$p2[1]) ;
   $a2 = 2 * ($p1[0]-$p3[0]) ;
   $b2 = 2 * ($p1[1]-$p3[1]) ;
   $c2 = ($p1[0]-$p3[0])*($p1[0]+$p3[0]) + ($p1[1]-$p3[1])*($p1[1]+$p3[1]) ;
   $den = $a1 * $b2 - $a2 * $b1 ;
   next if $den == 0 ;
   $nx = $c1 * $b2 - $c2 * $b1 ;
   $ny = $a1 * $c2 - $a2 * $c1 ;
   my $a = $den * $p1[0] - $nx ;
   my $b = $den * $p1[1] - $ny ;
   my $c = $a * $a + $b * $b ;
   my @p = () ;
   for ($i=0; $i<=100; $i++) {
      $aa = $den * $i - $nx ;
      $bb = $c - $aa * $aa ;
      next if $bb < 0 ;
      $bt = sqrt($bb) ;
      next if $bt * $bt != $bb ;
      $j = ($bt + $ny) / $den ;
      push @p, $i, $j if $j == int($j) && $j >= 0 && $j <= $mx ;
      $j = ($ny - $bt) / $den ;
      push @p, $i, $j if $j == int($j) && $j >= 0 && $j <= $mx && $bt > 0 ;
   }
   if (@p > 8) {
      my $cx = $den / gcd($den, $nx) ;
      my $cy = $den / gcd($den, $ny) ;
      my $ax = $nx / $den ;
      my $ay = $ny / $den ;
      $cx = - $cx if $cx < 0 ;
      $cy = - $cy if $cy < 0 ;
      if (($cx & ($cx - 1)) > 0 && ($cy & ($cy - 1)) > 0) {
         my @a = ("Included:", "Excluded:") ;
         for ($i=0; $i<@p; $i += 2) {
            $a[int rand 2] .= " ($p[$i],$p[$i+1])" ;
         }
         print "$a[0]\n$a[1]\n" ;
         $cnt++ ;
      }
   }
}
#
#   Now some randomish cases.  Generate a bunch of points, then
#   pick a random circle, and then pick which are in and which
#   are out.
#
$cnt = $mxpts ;
for ($ii=0; $ii<10; $ii++) {
   my $cx = rand $mx ;
   my $cy = rand $mx ;
   my $r = rand ($mx / 1.7) ;
   %seen = () ;
   my @instr ;
   my @outstr ;
   my $failit = int rand 3 ;
   for ($i=0; $i<$cnt; ) {
      my $x = int rand (1 + $mx) ;
      my $y = int rand (1 + $mx) ;
      next if $seen{"$x,$y"}++ ;
      $i++ ;
      my $in ;
      if ($failit == 0) {
         $in = int rand 2 ;
      } elsif ($failit == 1) {
         $in = 1 ;
      } else {
         $in = (($cx - $x) * ($cx - $x) + ($cy - $y) * ($cy - $y)) <= $r * $r ;
      }
      if ($in) {
         push @instr, "$x,$y" ;
      } else {
         push @outstr, "$x,$y" ;
      }
   }
   test(join(' ', @instr) . '/' . join(' ', @outstr)) ;
}
my @cocirc = qw(1 74 1 29 2 76 2 27 5 81 5 22 8 85 8 18 15 92 15 11 19 95 19 8 24 98 24 5 26 99 26 4 38 0 59 0 71 99 71 4 73 98 73 5 78 95 78 8 82 92 82 11 89 85 89 18 92 81 92 22 95 76 95 27 96 74 96 29 100 62 100 41) ;
my $cn = @cocirc / 2 ;
for ($cnt=0; $cnt<40; $cnt++) {
   my $pcnt = 1 + int rand $cn ;
   %seen = () ;
   my @instr ;
   my @outstr ;
   my $fail = int rand 2 ;
   my $b1 = 0 ;
   my $b2 = 0 ;
   my $mx, $my ;
   if (!$fail) {
      $b1 = $b2 = 2 * int rand $cn ;
      $b2 = 2 * int rand $cn while $b1 == $b2 ;
      $mx = ($cocirc[$b2+1] - $cocirc[$b1+1]) ;
      $my = ($cocirc[$b2] - $cocirc[$b1]) ;
      $my = - $my ;
      $mz = $mx * $cocirc[$b1] + $my * $cocirc[$b1+1] ;
      $mz2 = $mx * $cocirc[$b2] + $my * $cocirc[$b2+1] ;
      die "Broken" if $mz != $mz2 ;
   }
   for ($i=0; $i<$pcnt; $i++) {
      my $ii = 2 * int rand $cn ;
      my $x = $cocirc[$ii] ;
      my $y = $cocirc[$ii+1] ;
      next if $seen{"$x,$y"}++ ;
      my $in ;
      if ($fail) {
         $in = int rand 2 ;
      } else {
         $in = ($mx * $x + $my * $y >= $mz) ;
      }
      if ($in) {
         push @instr, "$x,$y" ;
      } else {
         push @outstr, "$x,$y" ;
      }
   }
   test(join(' ', @instr) . '/' . join(' ', @outstr)) ;
}
