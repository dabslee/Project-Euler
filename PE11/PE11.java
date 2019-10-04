import java.io.*;
import java.util.*;


public class PE11 {
	public static final int SIZE = 20;
	public static final int LEN = 4;
	
	public static void getinput(int matrix[][]) throws FileNotFoundException {
		Scanner myfile = new Scanner(new File("PE11.txt"));
		int j = 0;
		while (myfile.hasNextLine()) {
			String linearr[] = myfile.nextLine().split(" ");
			for (int i = 0; i < SIZE; i++) {
				matrix[j][i] = Integer.parseInt(linearr[i]);
			}
			j++;
		}
		myfile.close();
	}
	
	// The following function returns product in direction, or -1 if undef.	
	public static int product(int matrix[][], int len, int i0, int j0, int di, int dj){ // smallest it would return is 1.
		int s = 1;
		int num = 0;
		while (num < len) {
			int newi = i0 + di * num;
			int newj = j0 + dj * num;
			if (newi > 0 && newi < SIZE && newj > 0 && newj < SIZE) {
				s *= matrix[i0 + di * num][j0 + dj * num];
			}
			num++;
		}
		return s;
	}
	
	public static void main(String args[]) throws FileNotFoundException {
		int maxim = 0;
		int matrix[][] = new int[SIZE][SIZE];
		printmatrix(matrix);
		getinput(matrix);
		printmatrix(matrix);
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				for (int di = -1; di <= 1; di++) {
					for (int dj = -1; dj <= 1; dj++) {
						if (!(di == 0 && dj == 0)) {
							int testprod = product(matrix, LEN, i, j, di, dj);
							maxim = testprod > maxim ? testprod : maxim;
						}
					}
				}
			}
		}
		System.out.println(maxim);
	}
	
	public static void printmatrix(int matrix[][]) {
		for (int i = 0; i  < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				System.out.print(matrix[i][j]);
				System.out.print(" ");
			}
			System.out.println();
		}
		System.out.println();
	}
}
