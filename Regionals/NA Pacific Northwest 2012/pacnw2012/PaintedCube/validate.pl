my @dat = () ;
sub process {
   @dat >= 1 && @dat <= 20 or die "Bad dat length" ;
   length($dat[0]) >= 1 && length($dat[0]) <= 20 or die "Bad dat length" ;
   %cnt = () ;
   for (@dat) {
      die "Mismatch size" if length($dat[0]) != length($_) ;
      die "Bad char" if $_ !~ /^[PCG#\.]+$/ ;
      for ($i=0; $i<length($_); $i++) {
         $c = substr($_, $i, 1) ;
         $cnt{$c}++ ;
      }
   }
   die "Bad G count" if $cnt{'G'} != 1 ;
   die "Bad C count" if $cnt{'C'} != 1 ;
   die "Bad P count" if $cnt{'P'} != 6 ;
   die "Bad . count" if $cnt{'.'} > 12 ;
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
