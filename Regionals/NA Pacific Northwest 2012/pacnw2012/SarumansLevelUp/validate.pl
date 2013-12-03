while (<>) {
   chomp ;
   $lin = $_ ;
   $n = - - $lin ;
   die "Bad integer" if $n <= 0 || $n > 1e16 ;
   die "Bad format" if $lin ne "$lin" ;
}
