package projecteuler42;

import java.util.*;
import java.io.*;

public class PE42 {
	static int value(String s) {
		int mysum = 0;
		for (char c : s.toCharArray()) {
			mysum += c - 'A' + 1;
		}
		return mysum;
	}
	
	public static void main(String args[]) throws IOException {
		ArrayList<Integer> triangles = new ArrayList<Integer>();
		for (int i = 0; i < 1000; i++) {
			triangles.add(i*(i+1)/2);
		}
		Scanner sc = new Scanner(new File("words.txt"));
		String[] words = sc.nextLine().strip().split(",");
		sc.close();
		for (int i = 0; i < words.length; i++) {
			words[i] = words[i].replace("\"", "");
		}
		int count = 0;
		for (String word : words) {
			if (triangles.contains(value(word))) {
				count++;
			}
		}
		System.out.println(count);
	}
}
