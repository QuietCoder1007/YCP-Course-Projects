package edu.ycp.cs201.nchoosek;

public class TestDriver {
	private static final int N = 25;
	
	public static void main(String[] args) {
		test(new NaiveRecursive());
		System.out.println();
		test(new Memoization());
	}

	private static void test(ComputeBinomialCoefficient functor) {
		System.out.println("Testing " + functor.toString() + " implementation of binomial coefficient");
		for (int k= 0; k <= N; k++) {
			long start = System.currentTimeMillis();
			int result = functor.compute(N, k);
			long end = System.currentTimeMillis();
			System.out.println("Computed C("+N+","+k+")=" + result + " in " + (end-start) + " milliseconds");
		}
	}
}
