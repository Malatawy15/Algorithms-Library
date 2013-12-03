for ($case=0; $case<40; $case++) {
   $height = 1 + int rand 1000000 ;
   $height = 1000000 if $case == 10 ;
   $lobase = 1 + int rand 1000000 ;
   $hibase = 1 + int rand $lobase ;
   $c1 = int rand $height / 100 ;
   $c2 = int rand $height / 100 ;
   $c3 = int rand $height / 100 ;
   print "$height $lobase $hibase $c1 $c2 $c3\n" ;
}
