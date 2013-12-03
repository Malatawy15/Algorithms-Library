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
   die "Expected three integers" if @f != 3 ;
   last if $lin eq "0 0 0" ;
   my ($N, $E, $P) = @f ;
   die "Bad N" if $N < 1 || $N > 1000 ;
   die "Bad E" if $E < 0 || $E > 1000000000 ;
   die "Bad P" if $P < 1 || $P > 1000000000 ;
   $posparent = 0 ;
   for ($i=0; $i<$N; $i++) {
      $lin = <> ;
      chomp $lin ;
      @f = integers($lin);
      die "Expected three integers" if @f != 3 ;
      my ($e, $p, $parent) = @f ;
      die "Bad e" if $e < 1 || $e > 1000000000 ;
      die "Bad p" if $p < 0 || $p > 1000000000 ;
      die "Bad parent" if $parent < 0 || $parent > $N || $parent == $i+1 ;
      $posp++ if $p > 0 ;
   }
   die "No positive p" if $posp == 0 ;
}
$lin = <> ;
die "Expected end of file [$lin]" if defined($lin) ;
