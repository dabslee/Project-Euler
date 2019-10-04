package projecteuler46;

import java.util.*;

public class PE46 {
	static boolean isprime(int n) {
		if (n < 2) return false;
		if (n < 4) return true;
		for (int i = 2; i < (int)Math.sqrt(n)+1; i++) {
			if (n % i == 0) return false;
		}
		return true;
	}
	public static void main(String args[]) {
		ArrayList<Integer> primes = new ArrayList<Integer>();
		ArrayList<Integer> twicesquares = new ArrayList<Integer>();
		for (int i = 2; i < 10000; i++) {
			if (isprime(i)) primes.add(i);
		}
		for (int i = 1; i < 100; i++) {
			twicesquares.add(2*i*i);
		}
		
		boolean[] array = new boolean[30000];
		for (int p : primes) {
			for (int t : twicesquares) {
				array[p+t] = true;
			}
		}
		for (int i = 1; i < 100000000; i++) {
			if (!(isprime(2*i+1))) {
				if (!(array[2*i+1])) {
					System.out.println(2*i+1);
					return;
				}
			}
		}
	}
}
