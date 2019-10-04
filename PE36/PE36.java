package projecteuler36;

import java.math.*;

public class PE36 {
	static BigInteger toib2(int ib10) {
		return new BigInteger(Integer.toBinaryString(ib10));
	}
	
	static boolean checkpalin(BigInteger i) {
		return (i.toString().equals(new StringBuilder(i.toString()).reverse().toString()));
	}
	
	static boolean check10(int ib10) {
		return checkpalin(BigInteger.valueOf(ib10));
	}
	
	static boolean check2(int ib10) {
		return checkpalin(toib2(ib10));
	}
	
	public static void main(String args[]) {
		int mysum = 0;
		for (int i = 1; i < 1000000; i++) {
			if (check10(i) && check2(i)) {
				mysum += i;
			}
		}
		System.out.println(mysum);
	}
}
