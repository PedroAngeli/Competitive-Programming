
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    BigInteger x, y, ans;
    Scanner scanner = new Scanner(System.in);

    while (scanner.hasNext()) {
      x = scanner.nextBigInteger();
      y = scanner.nextBigInteger();
      ans = x.multiply(y);
      System.out.println(ans);
    }

  }

}