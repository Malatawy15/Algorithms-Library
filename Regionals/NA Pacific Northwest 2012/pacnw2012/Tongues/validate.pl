while (<>) {
   chomp ;
   die "Too long an input line" if length($_) > 100 ;
   die "Bad chars" if $_ !~ /^[ -~]*$/ ;
}
