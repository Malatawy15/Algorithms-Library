import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;


public class PaintedCubeAN {
  static int[] queue = new int[1 << 23];
  static int head = 0, tail = 0;
  static void reset() {head = tail = 0;}
  static int dequeue() {int answer = queue[head++]; return answer;}
  static void enqueue(int val) {queue[tail++] = val;}
  static boolean isEmpty() {return head == tail;}
  
  static HashMap<Integer, Integer> dist = new HashMap<Integer, Integer>();
  
  static char[][] board = new char[20][];
  static int[][] grid = new int[20][20];
  static int[] rmap = new int[20];
  static int[] cmap = new int[20];
  
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    while (s.hasNextLine()) {
      Arrays.fill(board, null);
      for (int i = 0; i < 20; i++) Arrays.fill(grid[i], -1); 
      int nr = 0, nc = 0;
      dist.clear();
      reset();
      String line = s.nextLine();
      while (line.length() > 0) {
        nc = line.length();
        board[nr++] = line.toCharArray();
        if (s.hasNextLine()) line = s.nextLine();
        else line = "";
      }
      
      int index = 0;
      int start = 0, end = 0;
      int seed = 0;
      for (int r = 0; r < nr; r++) {
        for (int c = 0; c < nc; c++) {
          switch (board[r][c]) {
          case '.': rmap[index] = r; cmap[index] = c; grid[r][c] = index++; break;
          case 'P': seed += (1 << index); rmap[index] = r; cmap[index] = c; grid[r][c] = index++; break;
          case 'C': start = index; rmap[index] = r; cmap[index] = c; grid[r][c] = index++; break;
          case 'G': end = index; rmap[index] = r; cmap[index] = c; grid[r][c] = index++; break;
          default:
          }
        }
      }
      
      seed += start << 26;
      
      dist.put(seed, 0);
      enqueue(seed);
      
      int goal = (end << 26) + (63 << 20);
      while(!isEmpty()) {
        int cur = dequeue();
        if (cur == goal) break;
        int curDist = dist.get(cur);
        index = cur >> 26;
        int die = (cur & ((1 << 26) - 1)) >> 20;
        int rest = cur & ((1 << 20) - 1);
        int r = rmap[index];
        int c = cmap[index];
        if (c > 0 && board[r][c-1] != '#') {
          // left
          int nextIndex = grid[r][c-1];
          int nextState = (nextIndex << 26) + (roll(0, die) << 20) + rest;
          nextState = bitSwap(nextState, 23, nextIndex);
          if (!dist.containsKey(nextState)) {
            dist.put(nextState, curDist + 1);
            enqueue(nextState);
          }
        }
        if (r > 0 && board[r-1][c] != '#') {
          // up
          int nextIndex = grid[r-1][c];
          int nextState = (nextIndex << 26) + (roll(1, die) << 20) + rest;
          nextState = bitSwap(nextState, 23, nextIndex);
          if (!dist.containsKey(nextState)) {
            dist.put(nextState, curDist + 1);
            enqueue(nextState);
          }
        }
        if (c < nc - 1 && board[r][c+1] != '#') {
          // right
          int nextIndex = grid[r][c+1];
          int nextState = (nextIndex << 26) + (roll(2, die) << 20) + rest;
          nextState = bitSwap(nextState, 23, nextIndex);
          if (!dist.containsKey(nextState)) {
            dist.put(nextState, curDist + 1);
            enqueue(nextState);
          }
        }
        if (r < nr - 1 && board[r+1][c] != '#') {
          // down
          int nextIndex = grid[r+1][c];
          int nextState = (nextIndex << 26) + (roll(3, die) << 20) + rest;
          nextState = bitSwap(nextState, 23, nextIndex);
          if (!dist.containsKey(nextState)) {
            dist.put(nextState, curDist + 1);
            enqueue(nextState);
          }
        }
      }
      
      if (dist.containsKey(goal))
        System.out.println(dist.get(goal));
      else
        System.out.println(-1);
    }
  }
  
  static int[][] transform = {{0, 2, 3, 4, 1, 5}, {1, 5, 2, 0, 4, 3}, {0, 4, 1, 2, 3, 5}, {3, 0, 2, 5, 4, 1}};
  
  static int bitSwap(int n, int a, int b) {
    int x = 1 & ((n >> a) ^ (n >> b));
    return n ^ ((x << a) | (x << b));
  }
  
  static int roll(int dir, int pattern) {
    int answer = 0;
    for (int i = 0; i < 6; i++) answer += ((pattern & (1 << transform[dir][i])) >> transform[dir][i]) << i;
    return answer;
  }
  
  // 0
  // top 1 2 3 4 left
  // 5
}
