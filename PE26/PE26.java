import java.util.*;

public class PE26 {
	public static int cyclelen(int d) {
		Set<Integer> rems = new HashSet<Integer>();
		int count = 1;
		int i = 1;
		while (!rems.contains(i * 10 % d)) {
			rems.add(i*10%d);
			i = i*10%d;
			count++;
			if (i*10%d == 0) return 0;
		}
		return (count - 1);
	}
	public static void main(String args[]) {
		int maximum = 0;
		int maxd = 0;
		for (int d = 2; d < 1000; d++) {
			if (cyclelen(d) > maximum) {
				maximum = cyclelen(d);
				maxd = d;
			}
		}
		System.out.println(maxd);
	}
}
