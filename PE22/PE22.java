import java.io.*;
import java.util.*;

public class PE22 {
	public static int strval(String s) {
		int val = 0;
		for (char c : s.toCharArray()) val += c - 'A' + 1;
		return val;
	}
	public static void main(String args[]) throws IOException {
		Scanner f = new Scanner(new File("names.txt"));
		String[] fcomma = f.nextLine().split(",");
		f.close();
		
		ArrayList<String> mylist = new ArrayList<String>();
		for (String s : fcomma) {
			mylist.add(s.substring(1, s.length()-1));
		}
		Collections.sort(mylist);
		
		int mysum = 0;
		int i = 1;
		for (String s : mylist) {
			mysum += i * strval(s);
			i++;
		}
		
		System.out.println(mysum);
	}
}
