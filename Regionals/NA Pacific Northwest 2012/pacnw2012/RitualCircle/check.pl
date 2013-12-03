use strict ;
@ARGV == 2 or die "Usage: perl check.pl RitualCircle.out judged-solution.out" ;
my $imp = 'The Orcs are close' ;
my $f1 = shift ;
my $f2 = shift ;
open F, $f1 or die "Can't open $f1" ;
open G, $f2 or die "Can't open $f2" ;
sub number {
   my $v = shift ;
   return 0 if $v eq '' ;
   return 0 if $v !~ /\d/ ;
   return $v =~ /-?\d*\.?\d*([eE][+-]?\d+)?/ ;
}
my $INCOMPLETE = "Incomplete Output" ;
my $UNKNOWN = "undetermined" ;
my $EXCESSIVE = "Excessive Output" ;
my $INCORRECT = "Wrong Output" ;
my $ACCEPTED = "yes" ;
sub fail {
   my $response = shift ;
   my $msg = shift ;
   print <<EOF ;
<?xml version="1.0"?>
<result outcome="$response" security="$f2">$msg</result>
EOF
   if ($response eq $ACCEPTED) {
      exit(0) ;
   } else {
      exit(10) ;
   }
}
while (1) {
   my $lin1 = <F> ;
   my $lin2 = <G> ;
   fail $INCOMPLETE, "Ran out of input on $f2" if !defined($lin2) && defined($lin1) ;
   fail $EXCESSIVE, "Ran out of input on $f1" if !defined($lin1) && defined($lin2) ;
   last if !defined($lin1) && !defined($lin2) ;
   chomp $lin1 ;
   chomp $lin2 ;
   next if $lin1 eq $imp && $lin2 eq $imp ;
   fail $INCORRECT, "Mismatch: $lin1 $lin2" if $lin1 eq $imp || $lin2 eq $imp ;
   fail $UNKNOWN, "Bad number on $f1: $lin1" if !number($lin1) ;
   fail $INCORRECT, "Bad number on $f2: $lin2" if !number($lin2) ;
   next if $lin1 == 0 && $lin2 == 0 ;
   fail $INCORRECT, "Mismatch: $lin1 $lin2" if abs($lin1-$lin2) / ($lin1+$lin2) > 0.5e-7 ;
}
fail $ACCEPTED, '' ;
