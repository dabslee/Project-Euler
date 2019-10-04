
public class PE14 {
	
	public static int chainlengths[] = new int[1000000];
	
	public static int findlength(long n) {
		if (n >= chainlengths.length) {
			if (n % 2 == 0) return findlength(n/2) + 1;
			else return findlength(3*n+1) + 1;
		}
		int intn = (int) n;
		if (chainlengths[intn] != -1) return chainlengths[intn];
		if (n % 2 == 0) {
			chainlengths[intn] = findlength(n/2)+1;
			return chainlengths[intn];
		}else {
			chainlengths[intn] = findlength(3*n+1)+1;
			return chainlengths[intn];
		}
	}
	
	public static void main(String args[]) {
		for (int i = 0; i < chainlengths.length; i++) chainlengths[i] = -1;
		chainlengths[1] = 1;
		int maxlen = 0;
		int index = 0;
		for (int i = 1; i < 1000000; i++) {
			int thislen = findlength(i);
			if (thislen > maxlen) {
				maxlen = thislen;
				index = i;
			}
		}
		System.out.println(index);
	}
}
