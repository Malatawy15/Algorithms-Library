while (1) {
   $lin = <> ;
   chomp $lin ;
   last if $lin eq '0' ;
   $n = - - $lin ;
   die "Bad format" if "$n" ne $lin ;
   die "Bad n" if $n < 1 || $n > 100000 ;
   $lin1 = <> ;
   chomp $lin1 ;
   $lin2 = <> ;
   chomp $lin2 ;
   @f1 = split " ", $lin1 ;
   die "Bad lin1" if "@f1" ne $lin1 ;
   @f2 = split " ", $lin2 ;
   die "Bad lin2" if "@f2" ne $lin2 ;
   die "Bad count" if @f1 != $n || @f2 != $n ;
   @a = sort { $a cmp $b } @f1 ;
   @b = sort { $a cmp $b } @f2 ;
   die "Bad sets" if "@a" ne "@b" ;
   die "Bad chars" if $lin1 !~ /^[a-zA-Z ]+$/ ;
   die "Bad chars" if $lin2 !~ /^[a-zA-Z ]+$/ ;
   %seen = () ;
   for (@a) {
      die "Duplicate" if $seen{$_}++ ;
   }
}
$lin = <> ;
die "Unexpected input at end" if defined($lin) ;
