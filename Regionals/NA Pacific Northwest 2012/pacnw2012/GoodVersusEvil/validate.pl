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
$lin = <> ;
chomp $lin ;
@f = integers($lin);
die "Expected only one integer on first line" if @f != 1 ;
my $cases = $f[0] ;
for ($case=1; $case<=$cases; $case++) {
   $lin = <> ;
   chomp $lin ;
   @f = integers($lin) ;
   die "Bad input; expected 6 integers" if @f != 6 ;
   $lin = <> ;
   chomp $lin ;
   @f = integers($lin) ;
   die "Bad input; expected 7 integers" if @f != 7 ;
}
$lin = <> ;
die "Expected end of file [$lin]" if defined($lin) ;
