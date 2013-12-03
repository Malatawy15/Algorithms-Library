import java.io.*;
import java.util.*;

public class Tongues {
  public static void main(String[] args) throws IOException {
    String vowels = "aiyeou";
    String consonants = "bkxznhdcwgpvjqtsrlmf";

    char[] remap = new char[256];
    for (int i = 0; i < 256; ++i)
      remap[i] = (char) i;
    for (int i = 0; i < vowels.length(); ++i)
      remap[(int) vowels.charAt(i)] =
        vowels.charAt((i + 3) % vowels.length());
    for (int i = 0; i < consonants.length(); ++i)
      remap[(int) consonants.charAt(i)] =
        consonants.charAt((i + 10) % consonants.length());

    vowels = vowels.toUpperCase();
    consonants = consonants.toUpperCase();
    for (int i = 0; i < vowels.length(); ++i)
      remap[(int) vowels.charAt(i)] =
        vowels.charAt((i + 3) % vowels.length());
    for (int i = 0; i < consonants.length(); ++i)
      remap[(int) consonants.charAt(i)] =
        consonants.charAt((i + 10) % consonants.length());

    Scanner scanner = new Scanner(new InputStreamReader(System.in));
    while (scanner.hasNextLine()) {
      String s = scanner.nextLine();
      for (int i = 0; i < s.length(); ++i) {
        char c = s.charAt(i);
        System.out.print(remap[(int) c]);
      }
      System.out.println();
    }
  }
}
