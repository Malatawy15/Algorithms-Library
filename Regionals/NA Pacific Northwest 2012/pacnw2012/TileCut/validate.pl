my @dat = () ;
sub process {
   @dat >= 1 && @dat <= 30 or die "Bad dat length" ;
   length($dat[0]) >= 1 && length($dat[0]) <= 30 or die "Bad dat length" ;
   %cnt = () ;
   for (@dat) {
      die "Mismatch size" if length($dat[0]) != length($_) ;
      die "Bad char" if $_ !~ /^[WIN]+$/ ;
   }
   @dat = () ;
}
while (<>) {
   chomp ;
   if ($_ eq '') {
      process() ;
   } else {
      push @dat, $_ ;
   }
}
process() ;
