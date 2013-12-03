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
   last if !defined($lin) ;
   chomp $lin ;
   @f = integers($lin);
   die "Expected  six integers" if @f != 6 ;
   die "Top should be less than bottom" if $f[2] >= $f[1] ;
   die "Bad height" if $f[0] < 1 || $f[0] > 1000000 ;
   die "Bad bottom" if $f[1] < 1 || $f[1] > 1000000 ;
   die "Bad top" if $f[2] < 1 || $f[2] > 1000000 ;
   die "Bad brick 0" if $f[3] < 1 || $f[3] > $f[0] ;
   die "Bad brick 1" if $f[4] < 1 || $f[4] > $f[0] ;
   die "Bad brick 2" if $f[5] < 1 || $f[5] > $f[0] ;
}
