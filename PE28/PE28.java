/*
1, 9, 25, 49 ... 1001^2
sqs
+8, +16, +24

1, 3, 13, 31
+2, +10, +18

1, 5, 17, 37
+4, +12, +20

1, 7, 21, 43
+6, +14, +22
*/

public class PE28 {
	static int mysum = 0;
	
	public static void add(int addend, int delta) {
		while (addend <= 1001*1001) {
			mysum += addend;
			addend += delta;
			delta += 8;
		}
	}
	
	public static void main(String args[]) {
		add(1, 8); // up right
		add(1, 2); // down right
		add(1, 4); // down left
		add(1, 6); // up left
		
		mysum -= 3;
		
		System.out.println(mysum);
	}
}
