import java.math.*;

public class PE16 {
	public static void main(String args[]) {
		int mysum = 0;
		String mystring = (new BigInteger("2")).pow(1000).toString();
		for (char c : mystring.toCharArray()) {
			mysum += c - '0';
		}
		System.out.println(mysum);
	}
}
