package projecteuler45;

import java.math.*;

public class PE45 {
	static boolean pentagonal(BigInteger p) {
		return p.multiply(BigInteger.valueOf(24)).add(BigInteger.valueOf(1)).sqrt().add(BigInteger.valueOf(1)).mod(BigInteger.valueOf(6)).equals(BigInteger.ZERO);
	}
	static boolean hexagonal(BigInteger h) {
		return h.multiply(BigInteger.valueOf(8)).add(BigInteger.valueOf(1)).sqrt().add(BigInteger.valueOf(1)).mod(BigInteger.valueOf(4)).equals(BigInteger.ZERO);
	}
	public static void main(String args[]) {
		for (int n = 1; n < 1000000; n++) {
			BigInteger t = BigInteger.valueOf(n*(n+1)/2);
			if (pentagonal(t) && hexagonal(t)) {
				System.out.println(t);
			}
		}
	}
}
