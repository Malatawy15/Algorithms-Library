#!perl
#
#   Validate input.
#
sub integers {
   my $inline = shift ;
   $inline =~ s/-0/0/g ; # permit -0 this problem only
   my @dat = map { 0 - - $_ } split " ", $inline ;
   my $testline = "@dat" ;
   die "Bad line [$inline] vs [$testline]" if $testline ne $inline ;
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
   die "Bad input; expected 2 integers" if @f != 2 ;
   ($rings, $runes) = @f ;
   die "Bad ring count" if $rings < 3 || $rings > 22 ;
   die "Bad rune count" if $runes < 1 || $runes > 100 ;
   for ($i=0; $i<$runes; $i++) {
      $lin = <> ;
      chomp $lin ;
      @f = integers($lin) ;
      die "Bad rune" if @f != 4 || $f[3] != 0 ;
   }
}
$lin = <> ;
die "Expected end of file [$lin]" if defined($lin) ;
