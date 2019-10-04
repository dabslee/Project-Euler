package projecteuler40;

public class PE40 {
	public static void main(String args[]) {
		int myprod = 1;
		int numdigits = 0;
		int nextnum = 0;
		for (int i = 0; i < 7; i++) {
			while (numdigits < Math.pow(10, i)) {
				numdigits += Integer.toString(nextnum).length();
				nextnum++;
			}
			myprod *= Integer.toString(nextnum).charAt(numdigits-(int)Math.pow(10, i)) - '0';
		}
		System.out.println(myprod);
	}
}
