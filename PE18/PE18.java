import java.util.*;
import java.io.*;

public class PE18 {
	
	public static void main(String args[]) throws IOException {
		// get input
		Scanner sc = new Scanner(new File("PE18.txt"));
		ArrayList<ArrayList<Integer>> input = new ArrayList<ArrayList<Integer>>();
		
		int depth = 1;
		while(sc.hasNextInt()) {
			ArrayList<Integer> oneline = new ArrayList<Integer>();
			for (int i = 0; i < depth; i++) {
				oneline.add(sc.nextInt());
			}
			input.add(oneline);
			depth++;
		}
		depth--;
		
		// create matrix of max sums
		int sums[][] = new int[depth][depth + 1];
		for (int i = 0; i < depth; i++) {
			for (int j = 0; j < depth + 1; j++) {
				sums[i][j] = 0;
			}
		}
		sums[0][1] = input.get(0).get(0);
		for (int i = 1; i < depth; i++) {
			for (int j = 1; j <= i + 1; j++) {
				sums[i][j] = Math.max(sums[i-1][j-1]+input.get(i).get(j-1),
						sums[i-1][j]+input.get(i).get(j-1));
			}
		}
		
		// check for maximum sum in the bottom-most row
		int maxsum = 0;
		for (int i = 0; i < depth + 1; i++) {
			maxsum = Math.max(sums[depth-1][i], maxsum);
		}
		System.out.println(maxsum);
		
		sc.close();
	}
}
