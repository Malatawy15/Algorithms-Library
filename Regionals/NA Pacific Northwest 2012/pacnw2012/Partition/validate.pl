#!perl
#
#   Validate input.
#
sub integers {
   my $inline = shift ;
   my @dat = map { 0 - - $_ } split " ", $inline ;
   my $testline = "@dat" ;
   die "Bad line [$inline] vs [$testline]" if $testline ne $inline ;
   for (@dat) {
      die "Negative integer unexpected" if $_ < 0 ;
   }
   return @dat ;
}
while (1) {
   $lin = <> ;
   chomp $lin ;
   @f = integers($lin);
   die "Expected three integers on first line" if @f != 3 ;
   last if $lin eq "0 0 0" ;
   ($N, $W, $H) = @f ;
   die "Bad N" if $N < 2 || $N > 50000 ;
   die "Odd N" if $N % 2 != 0 ;
   die "Bad W" if $W < 2 || $W > 10000 ;
   die "Bad H" if $H < 2 || $H > 10000 ;
   die "Bad H/W" if $W % 2 == 0 && $H % 2 == 0 ;
   %seen = () ;
   for ($i=0; $i<$N; $i++) {
      $lin = <> ;
      chomp $lin ;
      @f = integers($lin) ;
      die "Bad input; expected 2 integers" if @f != 2 ;
      ($x, $y) = @f ;
      die "Bad x x=$x W=$W" if $x <= 0 || $x >= $W ;
      die "Bad y" if $y <= 0 || $y >= $H ;
      die "Duplicate point [$lin]" if $seen{$lin}++ ;
   }
}
$lin = <> ;
die "Expected end of file [$lin]" if defined($lin) ;
