package projecteuler33;

import java.util.*;
import java.math.*;

public class PE33 {
	
	public static int gcd(int a, int b) {
	    BigInteger b1 = BigInteger.valueOf(a);
	    BigInteger b2 = BigInteger.valueOf(b);
	    BigInteger gcd = b1.gcd(b2);
	    return gcd.intValue();
	}
	
	public static void main(String args[]) {
		ArrayList<Integer> fracs_n = new ArrayList<Integer>();
		ArrayList<Integer> fracs_d = new ArrayList<Integer>();
		
		// ab/cd
		for (int a = 1; a < 10; a++) {
			for (int b = 0; b < 10; b++) {
				for (int c = 1; c < 10; c++) {
					for (int d = 0; d < 10; d++) {
						if (10*a+b > 10*c+d || 10*a+b == 10*c+d) continue;
						if (b == 0 && d == 0) continue;
		                if (gcd(10*a+b, 10*c+d) == 1) continue;
		                if (a == c) {
		                	if (d == 0 || 1.0*b/d != 1.0*(10*a+b)/(10*c+d)) continue;
		                } else if (a == d) {
		                    if (1.0*b/c != 1.0*(10*a+b)/(10*c+d)) continue;
		                } else if (b == c) {
		                    if (d == 0 || 1.0*a/d != 1.0*(10*a+b)/(10*c+d)) continue;
		                } else if (b == d) {
		                    if (1.0*a/c != 1.0*(10*a+b)/(10*c+d)) continue;
		                } else continue;
		                fracs_n.add(10*a+b);
		                fracs_d.add(10*c+d);
					}
				}
			}
		}
		
		int numer = 1;
		for (int n : fracs_n) numer *= n;
		int denom = 1;
		for (int d : fracs_d) denom *= d;
		System.out.println(denom/gcd(numer, denom));
	}
}
