import java.util.Scanner;


public class Spellcasting {
  static int[] parent = new int[1024];
  static double[] energy = new double[1024];
  static double[] power = new double[1024];
  
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    
    while (true) {
      int N = in.nextInt();
      double E = in.nextDouble();
      double P = in.nextDouble();
      
      if (N == 0) break;
      
      for (int i = 1; i <= N; i++) {
        energy[i] = in.nextDouble();
        power[i] = in.nextDouble();
        parent[i] = in.nextInt();
      }
      
      double best = Double.MAX_VALUE;
      
      for (int i = 1; i <= N; i++) {
        double c = energy[i];
        double p = power[i];
        if (p > 0) best = Math.min(best, c / p);
        int cur = i;
        while (parent[cur] != 0) {
          c -= energy[cur] / 2;
          cur = parent[cur];
          c += energy[cur];
          p += power[cur];
          if (p > 0) best = Math.min(best, c / p);
        }
      }
      
      double answer = Math.max(0, best * Math.log(P * best / E));
      
//      System.out.println(answer);
      System.out.println((long) Math.ceil(answer));
    }
  }
}
