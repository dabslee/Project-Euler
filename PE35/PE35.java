package projecteuler35;

public class PE35 {
	static boolean isPrime(int n) {
		if (n < 2) return false;
		if (n < 4) return true;
		if (n == 4) return false;
		if (n == 5) return true;
		for (int i = 2; i < (int)Math.pow(n, 0.5)+1; i++) {
			if (n % i == 0) return false;
		}
		return true;
	}
	
	static String shiftleft(String sn) {
		String shifted = sn.substring(1);
		shifted += sn.charAt(0);
		return shifted;
	}
	
	static boolean checkcirc(String sn) {
		if (!isPrime(Integer.parseInt(sn))) return false;
		String sn2 = shiftleft(sn);
		while (!sn2.equals(sn)) {
			if (!isPrime(Integer.parseInt(sn2))) return false;
			sn2 = shiftleft(sn2);
		}
		return true;
	}
	
	public static void main(String args[]) {
		int count = 0;
		for (int i = 2; i < 1000000; i++) {
			if (checkcirc(Integer.toString(i))) count++;
		}
		System.out.println(count);
	}
}
