import java.util.*;

public class PE23 {
	public static int sum(Set<Integer> a) {
		int mysum = 0;
		for (int i : a) mysum += i;
		return mysum;
	}
	public static int sumdiv(int n) {
		int num = 0;
	    // square number case
	    if (Math.sqrt(n) == (int)Math.sqrt(n)) {
	        for (int f = 1; f <= Math.sqrt(n); f++) {
	        	if (n % f == 0) {
	                num += f + n/f;
	        	}
	        }
	        num -= (int)Math.sqrt(n);
	        return num - n;
	    }
	    else {
	    	for (int f = 1; f <= Math.sqrt(n); f++) {
	            if (n % f == 0) {
	                num += f + n/f;
	            }
	    	}
	        return num - n;
	    }
	}
	public static void main(String args[]) {
		// first find all the abundant numbers
		// then find all the sums that can be found using them

		ArrayList<Integer> abundants = new ArrayList<Integer>();
		// find all the abundant numbers
		for (int i = 1; i <= 28123; i++) {
			if (sumdiv(i) > i) {
				abundants.add(i);
			}
		}
		// find all the sums that can be found using them
		Set<Integer> sums = new HashSet<Integer>();
		
		for (int i = 0; i < abundants.size(); i++) {
			for (int j = i; j < abundants.size(); j++) {
				if (abundants.get(i)+abundants.get(j) <= 28123) {
					sums.add(abundants.get(i)+abundants.get(j));
				}
			}
		}
		// subtract out all the abundants
		System.out.println(28123*(28123+1)/2 - sum(sums));
	}
}
