package edu.ycp.cs201.functors;

public class SumIntFunctor implements Functor<Integer> {
	// TODO: field(s)
	private int sum;
	
	public SumIntFunctor() {
		// TODO: initialize field(s)
		this.sum = 0;
	}
	
	@Override
	public void apply(Integer value) {
		this.sum += (int)value;
	}
	
	/**
	 * @return the sum of all Integer values seen by this functor
	 */
	public int getSum() {
		return this.sum;
		
	}
}
