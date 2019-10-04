package projecteuler44;

public class PE44 {
	static boolean is_pentagonal(int n) {
		return (1+Math.sqrt(24*n+1)%6==0);
	}
	public static void main(String args[]) {
		boolean flag = true;
		int i = 1;
		while (flag) {
			for (int j = 1; j < i; j++) {
				int a = i*(3*i-1)/2;
				int b = j*(3*j-1)/2;
				if (is_pentagonal(a+b) && is_pentagonal(a-b)) {
					System.out.println((int)(a-b));
					flag = false;
					break;
				}
			}
			i++;
		}
	}
}
