import java.util.*;

public class PE21 {
	public static int sumdiv(int n) {
		int sum = 0;
		for (int f = 1; f <= (int)Math.sqrt(n); f++) {
			if (n % f == 0) sum += f + n/f;
		}
		if (Math.sqrt(n) == (int)Math.sqrt(n)) return sum -= (int)Math.sqrt(n);
		return sum - n;
	}
	public static void main(String args[]) {
		ArrayList<Integer> proper = new ArrayList<Integer>();
		for (int i = 2; i < 10000; i++) {
			int j = sumdiv(i);
			if (proper.contains(j) || i == j) continue;
			if (i == sumdiv(j)) {
				proper.add(i); proper.add(j);
			}
		}
		int sum = 0;
		for (int i : proper) sum += i;
		System.out.println(sum);
	}
}
