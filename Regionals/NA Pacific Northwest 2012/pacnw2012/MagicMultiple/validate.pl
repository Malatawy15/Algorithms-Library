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
   die "Expected only one integer" if @f != 1 ;
   die "Out of range [@f]" if $f[0] < 1 || $f[0] > 200000000 ;
}
