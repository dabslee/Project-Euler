
public class PE17 {
	static String ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	static String teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
	static String tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
	static String twodigit(int n) {
		if (n < 10) return ones[n];
		if (n < 20) return teens[n-10];
		return tens[n/10] + ones[n%10];
	}
	static String threedigit(int n) {
		if (n < 100) return twodigit(n);
		if (n == 1000) return "onethousand";
		if (n % 100 != 0) return ones[n/100] + "hundredand" + twodigit(n%100);
		return ones[n/100] + "hundred";
	}
	public static void main(String args[]) {
		int mysum = 0;
		for (int i = 1; i <= 1000; i++) {
			mysum += threedigit(i).length();
		}
		System.out.println(mysum);
	}
}
