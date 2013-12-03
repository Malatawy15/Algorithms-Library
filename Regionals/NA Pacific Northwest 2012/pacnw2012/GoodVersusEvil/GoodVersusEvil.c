/* On the side of good we have the following races, with their associated
   worth in battle:

   Hobbits - 1
   Men - 2
   Elves - 3
   Dwarves - 3
   Eagles - 4
   Wizards - 10

   On the side of evil we have:

   Orcs - 1
   Men - 2
   Wargs - 2
   Goblins - 2
   Uruk Hai - 3
   Trolls - 5
   Wizards - 10
 */
 #include <stdio.h>

 int main(int argc, char** argv)
 {
    int  good[] = { 1, 2, 3, 3, 4, 10},
         bad[]  = { 1, 2, 2, 2, 3, 5, 10};
    int  ng = sizeof(good) / sizeof(*good),
         nb = sizeof(bad)  / sizeof(*bad);
 // Retain vector for debugging
    int *Gforce = (int*) calloc(ng, sizeof(*Gforce)),
        *Bforce = (int*) calloc(nb, sizeof(*Bforce));
    int  prob, nProb, tmp,
         Gvalue, Bvalue;

    scanf("%d\n", &nProb);
    //printf("%d problems.\n", nProb);
    for (prob = 1; prob <= nProb; prob++)
    {  int j;
       for (j = Gvalue = 0; j < ng; j++)
       {  scanf("%d", Gforce+j);
          Gvalue += good[j]*Gforce[j];
       }
       while ((tmp = getchar()) != '\n')
          if (tmp < 0) exit(-1);
       for (j = Bvalue = 0; j < nb; j++)
       {  scanf("%d", Bforce+j);
          Bvalue += bad[j]*Bforce[j];
       }
       while ((tmp = getchar()) != '\n')
          if (tmp < 0) exit(-1);
       printf("Battle %d: ", prob);
       if (Gvalue > Bvalue)
         // printf("Good triumphs over Evil %d %d\n", Gvalue, Bvalue);
		  printf("Good triumphs over Evil\n");
       else if (Gvalue < Bvalue)
         // printf("Evil eradicates all trace of Good %d %d\n", Gvalue, Bvalue);
		  printf("Evil eradicates all trace of Good\n");
       else
         // printf("No victor on this battle field %d %d\n", Gvalue, Bvalue);
		  printf("No victor on this battle field\n");
    }

    return 0;
 }
