
public class PE4 {
	public static String reverse(String s) {
		String ns = "";
		for (char i : s.toCharArray()) {
			ns = i + ns;
		}
		return ns;
	}
	
	public static boolean isPalin(int n) {
		return (Integer.toString(n).equals(reverse(Integer.toString(n))));
	}
	
	public static void main (String args[]) {
		int m = 0;
		for (int i = 1; i < 1000; i++) {
			for (int j = 1; j < 1000; j++) {
				if (isPalin(i*j) && i*j > m) m=i*j;
			}
		}
		System.out.println(m);
	}
}
