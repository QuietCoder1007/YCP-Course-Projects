package edu.ycp.cs201.nchoosek;

public class Memoization implements ComputeBinomialCoefficient {

	public int compute(int n, int k) {
		// TODO: implement
		//throw new UnsupportedOperationException("not implemented yet!");
		return computeMemo(n , k, new int[n + 1][k + 1]) + computeMemo(n, k, new int[n + 1][k + 1]);
	}
	
	public static int computeMemo(int n, int k, int[][] memo) {
		if(k == 0 || k == n) {
			return 1;
		}
		int answer = memo[n][k];
		if (answer == 0) {
			answer = computeMemo(n-1, k, memo) + computeMemo(n-1,k-1,memo);
			memo[n][k] = answer;
		}
		return answer;
	}
	public String toString() {
		return "Memoization";
	}
}
