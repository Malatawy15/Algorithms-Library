import java.io.* ;
import java.util.* ;
public class TileCut {
   int augment(int[][] g, int[][] now, int at, int sink, boolean[] seen,
               int sofar) {
      if (at == sink)
         return sofar ;
      if (seen[at])
         return 0 ;
      seen[at] = true ;
      for (int i=0; i<g.length; i++)
         if (now[at][i] < g[at][i]) {
            int t = augment(g, now, i, sink, seen,
                            Math.min(sofar, g[at][i]-now[at][i])) ;
            if (t > 0) {
               now[at][i] += t ;
               now[i][at] -= t ;
               return t ;
            }
         }
      return 0 ;
   }
   int[][] flow(int[][] g, int src, int sink) {
      int[][] now = new int[g.length][g[0].length] ;
      while (augment(g, now, src, sink, new boolean[g.length],
                                                        1000000000) > 0) ;
      return now ;
   }
   public static void process(ArrayList<String> al) {
      if (al.size() == 0)
	  return ;
      int w = al.get(0).length() ;
      int h = al.size() ;
      int n = 2 + 2*w*h ;
      int[][] g = new int[n][n] ;
      for (int i=0; i<h; i++)
	  for (int j=0; j<w; j++) {
	      char c = al.get(i).charAt(j) ;
	      int ind = 1 + 2 * (i * w + j) ;
	      if (c == 'W')
		  g[0][ind] = 1 ;
	      if (c == 'N')
		  g[ind+1][n-1] = 1 ;
              g[ind][ind+1] = 1 ;
	      if (i > 0) {
		  char c2 = al.get(i-1).charAt(j) ;
		  int ind2 = ind - 2*w ;
		  if ((c == 'W' && c2 == 'I') ||
		      (c == 'I' && c2 == 'N')) {
		      g[ind+1][ind2] = 1 ;
		  } else if ((c2 == 'W' && c == 'I') ||
		      (c2 == 'I' && c == 'N')) {
		      g[ind2+1][ind] = 1 ;
		  }
	      }
	      if (j > 0) {
		  char c2 = al.get(i).charAt(j-1) ;
		  int ind2 = ind - 2 ;
		  if ((c == 'W' && c2 == 'I') ||
		      (c == 'I' && c2 == 'N')) {
		      g[ind+1][ind2] = 1 ;
		  } else if ((c2 == 'W' && c == 'I') ||
		      (c2 == 'I' && c == 'N')) {
		      g[ind2+1][ind] = 1 ;
		  }
	      }
	  }
      int[][] ra = new TileCut().flow(g, 0, n-1) ;
      int r = 0 ;
      for (int i=1; i<n; i++)
	  r += ra[0][i] ;
      al.clear() ;
      System.out.println(r) ;
   }
   public static void main(String[] args) throws Exception {
      BufferedReader br = new BufferedReader(
					 new InputStreamReader(System.in)) ;
      ArrayList<String> board = new ArrayList<String>() ;
      while (true) {
	  String s = br.readLine() ;
	  if (s == null)
	      break ;
	  s = s.trim() ;
	  if (s.length() == 0) {
	      process(board) ;
	  } else {
	      board.add(s) ;
	  }
      }
      process(board) ;
   }
}
