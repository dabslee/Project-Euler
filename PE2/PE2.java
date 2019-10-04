
public class PE2 {
	public static void main (String args[]) {
		int f = 1;
		int fp = 1;
		int s = 0;
		while (f <= 4000000) {
			if (f % 2 == 0) {
				s += f;
			}
			int temp = f;
			f += fp;
			fp = temp;
		}
		System.out.println(s);
	}
}
