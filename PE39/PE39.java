package projecteuler39;

import java.util.stream.IntStream;

public class PE39 {
	public static void main(String args[]) {
		int[][] primitives = new int[][] {{3,4,5}, {5, 12, 13}, {8, 15, 17}, {7, 24, 25}, {20, 21, 29}, {12, 35, 37}, {9, 40, 41}, {28, 45, 53}, {11, 60, 61}, {33, 56, 65}, {16, 63, 65}, {48, 55, 73}, {36, 77, 85}, {13, 84, 85}, {39, 80, 89}, {65, 72, 97}};
		int[] perimeters = new int[1000+1];
		for (int[] triple : primitives) {
			int[] tcopy = triple.clone();
			while (IntStream.of(tcopy).sum() <= 1000) {
				perimeters[IntStream.of(tcopy).sum()] += 1;
				tcopy[0] += triple[0];
				tcopy[1] += triple[1];
				tcopy[2] += triple[2];
			}
		}
		int maxvalue = 0;
		int maxindex = 0;
		for (int i = 0; i < perimeters.length; i++) {
			if (perimeters[i] > maxvalue) {
				maxvalue = perimeters[i];
				maxindex = i;
			}
		}
		System.out.println(maxindex);
	}
}
