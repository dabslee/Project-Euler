
public class PE9 {
	public static void main (String args[]) {
		for (int a = 1; a < 1000; a++) {
			for (int b = 1; b <= a; b++) {
				int csq = a * a + b * b;
				if (Math.sqrt(csq) == (int)Math.sqrt(csq) && a + b + Math.sqrt(csq) == 1000) {
					System.out.println(a * b * (int)Math.sqrt(csq));
					return;
				}
			}
		}
	}
}
