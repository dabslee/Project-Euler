import java.io.*;
import java.math.*;
import java.util.*;


public class PE13 {
	public static void main(String args[]) throws IOException {
		Scanner sc = new Scanner(new File("PE13.txt"));
		ArrayList<BigInteger> intlist = new ArrayList<BigInteger>();
		for (int i = 0; i < 100; i++) {
			intlist.add(sc.nextBigInteger());
		}
		BigInteger mysum = new BigInteger("0");
		for (BigInteger i : intlist) {
			mysum = mysum.add(i);
		}
		System.out.println(mysum.toString().substring(0, 10));
		sc.close();
	}
}
