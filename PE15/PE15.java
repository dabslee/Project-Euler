import java.math.*;

public class PE15 {
	public static BigInteger factorial(int n) {
		BigInteger prod = new BigInteger("1");
		for (int i = 1; i <= n; i++) {
			prod = prod.multiply(BigInteger.valueOf(i));
		}
		return prod;
	}
	
	public static BigInteger ncr(int n, int r) {
		return (factorial(n)).divide(factorial(r).multiply(factorial(n-r)));
	}
	
	public static void main(String args[]) {
		int size = 20;
		System.out.println(ncr(size*2, size));
	}
}
