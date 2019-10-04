import java.math.*;

public class PE20 {
	public static void main(String args[]) {
		BigInteger fac = new BigInteger("1");
		
		for (int i = 1; i <= 100; i++) {
			fac = fac.multiply(BigInteger.valueOf(i));
		}
		
		int mysum = 0;
		String facstr = fac.toString();
		for (char c : facstr.toCharArray()) {
			mysum += c - '0';
		}
		
		System.out.println(mysum);
	}
}
