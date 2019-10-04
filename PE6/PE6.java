
public class PE6 {
	public static long sumofsq(int n) {
		long sum = 0;
		for (int i = 1; i <= n; i++) {
			sum += Math.pow(i, 2);
		}
		return sum;
	}

	public static int sqofsum(int n) {
		return (int)Math.pow((n + 1)*n / 2, 2);
	}

	public static void main(String args[]) {
		int n = 100;
		System.out.println(Math.abs(sumofsq(n) - sqofsum(n)));
	}
}
