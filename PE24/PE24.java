import java.util.*;

public class PE24 {
	public static ArrayList<ArrayList<Integer>> permutation(ArrayList<Integer> lst){
		if (lst.size() == 0)
	        return new ArrayList<ArrayList<Integer>>();
		if (lst.size() == 1) {
			ArrayList<ArrayList<Integer>> mylist = new ArrayList<ArrayList<Integer>>();
			mylist.add(lst);
	        return mylist;
		}
		ArrayList<ArrayList<Integer>> l = new ArrayList<ArrayList<Integer>>();
		
		for (int i = 0; i < lst.size(); i++) {
			int m = lst.get(i);
			ArrayList<Integer> remLst = new ArrayList<Integer>(lst.subList(0, i));
			remLst.addAll(lst.subList(i+1, lst.size()));
			for (ArrayList<Integer> p : permutation(remLst)) {
				ArrayList<Integer> mcopy = new ArrayList<Integer>();
				mcopy.add(m);
				mcopy.addAll(p);
				l.add(mcopy);
			}
		}
		return l;
	}
	
	public static void main(String args[]) {
		ArrayList<Integer> digits = new ArrayList<Integer>();
		for (int i = 0; i < 10; i++) digits.add(i);
		ArrayList<ArrayList<Integer>> permutations = permutation(digits);
		ArrayList<String> permstr = new ArrayList<String>();
		for (ArrayList<Integer> a : permutations) {
			String mystr = "";
			for (int i : a) mystr += Integer.toString(i);
			permstr.add(mystr);
		}
		Collections.sort(permstr);
		System.out.println(permstr.get(1000000-1));
	}
}
