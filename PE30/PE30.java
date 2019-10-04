public class PE30 {
	public static boolean writable(int n) {
		int mysum = 0;
		for (char c : Integer.toString(n).toCharArray()) {
			mysum += Math.pow(c - '0', 5);
		}
		return (n == mysum);
	}
	
	public static void main(String args[]) {
		int mysum = 0;
		for (int i = 2; i < 1000000; i++) {
			if (writable(i)) mysum += i;
		}
		System.out.println(mysum);
	}
}
