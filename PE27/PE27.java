public class PE27 {
	public static boolean isPrime(int n) {
		if (n <= 1) return false;
		if (n <= 3) return true;
		if (n % 2 == 0 || n % 3 == 0) return false;
	    int i = 5;
	    while(i * i <= n) {
	        if (n % i == 0 || n % (i + 2) == 0) return false;
	        i += 6;
	    }
	    return true;
	}
	public static int f (int a, int b, int n) {
		return n*n+a*n+b;
	}
	public static int numprimes(int a, int b) {
		int n = 0;
		while (isPrime(f(a,b,n))) {
			n++;
		}
		return n;
	}
	
	public static void main(String args[]) {
		int maxnum = 0;
		int maxprod = 0;
		for (int a = -999; a <= 999; a++) {
			for (int b = -1000; b <= 1000; b++) {
				int nump = numprimes(a,b);
				if (nump > maxnum) {
					maxnum = nump;
					maxprod = a*b;
				}
			}
		}
		System.out.println(maxprod);
	}
}
