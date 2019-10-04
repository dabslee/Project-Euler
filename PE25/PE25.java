import java.math.*;

public class PE25 {
	public static void main(String args[]) {
		BigInteger f = new BigInteger("1");
		int i = 1;
		BigInteger fp = new BigInteger("0");
		
		while (f.toString().length() < 1000) {
			i++;
			BigInteger temp = f;
			f = fp.add(f);
			fp = temp;
		}
		
		System.out.println(i);
	}
}
