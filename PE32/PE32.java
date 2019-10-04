package projecteuler32;

import java.util.*;

public class PE32 {
	
	public static ArrayList<String> permstrs = new ArrayList<String>();
	
	public static String swap(String a, int i, int j) 
    { 
        char temp; 
        char[] charArray = a.toCharArray(); 
        temp = charArray[i] ; 
        charArray[i] = charArray[j]; 
        charArray[j] = temp; 
        return String.valueOf(charArray); 
    } 
	
	public static void permutation(String str, int l, int r) 
    { 
        if (l == r) 
            permstrs.add(str); 
        else
        { 
            for (int i = l; i <= r; i++) 
            { 
                str = swap(str,l,i); 
                permutation(str, l+1, r); 
                str = swap(str,l,i); 
            } 
        } 
    } 
	
	public static void main(String args[]) {
		permutation("123456789", 0, 8);
		
		Set<Integer> myset = new HashSet<Integer>();
		for (String perm : permstrs) {
			for (int x = 0; x < 9; x++) {
				for (int e = x+1; e < 8; e++) {
					int a = Integer.parseInt(perm.substring(0, x+1));
					int b = Integer.parseInt(perm.substring(x+1, e+1));
					int c = Integer.parseInt(perm.substring(e+1, perm.length()));
					if (a*b == c) myset.add(c);
				}
			}
		}
		
		int mysum = 0;
		for (int i : myset) {
			mysum += i;
		}
		System.out.println(mysum);
	}
}
