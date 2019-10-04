
public class PE5 {
	public static boolean checksol(int n) {
		for (int i = 1; i <= 20; i++) {
			if (n % i != 0) return false;
		}
		return true;
	}
	
	public static void main (String args[]) {
		int p = 2*3*5*7*11*13*17*19;
		int i = 0;
		while (true) {
			i += p;
			if (checksol(i)) {
				System.out.println(i);
				break;
			}
		}
	}
}
