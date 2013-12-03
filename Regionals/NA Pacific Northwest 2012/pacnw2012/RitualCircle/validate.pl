$cnt = 0 ;
$pts = 0 ;
%seen = 0 ;
while (1) {
   $lin = <> ;
   last if !defined($lin) ;
   chomp $lin ;
   @f = split " ", $lin ;
   die "Bad spacing" if "@f" ne $lin ;
   if ($cnt % 2 == 0) {
      die "Missing Companions" if $f[0] ne 'Companions:' ;
   } else {
      die "Missing Orcs" if $f[0] ne 'Orcs:' ;
   }
   if (@f == 2 && $f[1] eq 'none') {
   } else {
      for ($i=1; $i<@f; $i++) {
         $f[$i] =~ /^\((\d+),(\d+)\)$/ or die "Bad format" ;
         $x = $1 ;
         $y = $2 ;
         die "Bad x" if $x < 0 || $x > 100 ;
         die "Bad y" if $y < 0 || $y > 100 ;
         $pts++ ;
         die "Duplicate point" if $seen{"$x,$y"}++ ;
      }
   }
   $cnt++ ;
   if ($cnt % 2 == 0) {
      die "Too many points" if $pts > 300 ;
      $big++ if $pts > 200 ;
      $pts = 0 ;
      %seen = () ;
   }
}
die "Odd number of lines?" if $cnt % 2 == 1 ;
die "Too many big $big" if $big > 10 ;
