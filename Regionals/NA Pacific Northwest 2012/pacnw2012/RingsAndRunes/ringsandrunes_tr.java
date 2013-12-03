import java.io.* ;
public class ringsandrunes_tr {
   public static int[] readInts(BufferedReader br) throws Exception {
      String s = br.readLine() ;
      String[] a = s.split(" ") ;
      int[] r = new int[a.length] ;
      for (int i=0; i<r.length; i++)
         r[i] = Integer.parseInt(a[i]) ;
      return r ;
   }
   public static int abs(int v) {
      return Math.abs(v) ;
   }
   static int ringv[] ;
   static int runea[][] ;
   static boolean satisfy(int at) {
      if (at == runea.length)
         return true ;
      int j = 0 ;
      int r = 0 ;
      boolean okay = false ;
      while (j < 3) {
         r = abs(runea[at][j]) ;
         if (ringv[r] == 0) {
            ringv[r] = 1 ;
            if (satisfy(at))
               return true ;
            ringv[r] = -1 ;
            if (satisfy(at))
               return true ;
            ringv[r] = 0 ;
            return false ;
         }
         if (runea[at][j] * ringv[r] > 0)
            okay = true ;
         j++ ;
      }
      if (okay && satisfy(at+1))
         return true ;
      return false ;
   }
   public static String process(BufferedReader br) throws Exception {
      int[] f = readInts(br) ;
      int rings = f[0] ;
      int runes = f[1] ;
      runea = new int[runes][] ;
      String err = null ;
      for (int rune=0; rune<runes; rune++) {
         f = readInts(br) ;
         for (int i=0; i<3; i++)
            if (f[i] == 0)
               err = "INVALID: NULL RING" ;
         runea[rune] = f ;
      }
      if (err != null)
         return err ;
      for (int rune=0; rune<runes; rune++)
         if (abs(runea[rune][0]) > rings ||
             abs(runea[rune][1]) > rings ||
             abs(runea[rune][2]) > rings)
            return "INVALID: RING MISSING" ;
      for (int rune=0; rune<runes; rune++)
         if (abs(runea[rune][0]) == abs(runea[rune][1]) ||
             abs(runea[rune][0]) == abs(runea[rune][2]) ||
             abs(runea[rune][1]) == abs(runea[rune][2]))
            return "INVALID: RUNE CONTAINS A REPEATED RING" ;
      ringv = new int[1+rings] ;
      if (satisfy(0))
         return "RUNES SATISFIED!" ;
      else
         return "RUNES UNSATISFIABLE! TRY ANOTHER GATE!" ;
   }
   public static void main(String args[]) throws Exception {
      BufferedReader br = new BufferedReader(
                                       new InputStreamReader(System.in)) ;
      int kases = readInts(br)[0] ;
      for (int kase=1; kase<=kases; kase++)
         System.out.println(process(br)) ;
   }
}
