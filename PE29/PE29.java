import java.util.*;

public class PE29 {
	public static void main(String args[]) {
		Set<Double> myset = new HashSet<Double>();
		
		for (int a = 2; a <= 100; a++) {
			for (int b = 2; b <= 100; b++) {
				myset.add(Math.pow(a, b)); // Rounding error when I use Integer class for set
			}
		}
		
		System.out.println(myset.size());
	}
}
