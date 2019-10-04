
public class PE12 {
	public static int numfac(int n) {
		// Square case
		if (Math.sqrt(n)==(int)Math.sqrt(n)) {
			int num = 0;
			for (int i = 1; i < (int)Math.sqrt(n); i++) {
				if (n % i == 0) num += 2;
			}
			num++;
			return num;
		}
		int num = 0;
		for (int i = 1; i < (int)Math.sqrt(n)+1; i++) {
			if (n % i == 0) num += 2;
		}
		return num;
	}
	
	public static void main(String args[]) {
		int n = 1;
		while (numfac(n*(n+1)/2) <= 500) n++;
		System.out.println(n*(n+1)/2);
	}
}
