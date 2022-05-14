package edu.ycp.cs201.functors;

public class CountJFunctor implements Functor<String> {
	// TODO: field(s)
	private int count;
	public CountJFunctor() {
		// TODO: initialize field(s)
		this.count = 0;
	}

	@Override
	public void apply(String value) {
		for(int i = 0; i < value.length(); i++){
			if(value.substring(i, i + 1).equalsIgnoreCase("j")) {
				this.count++;
			}
		}
	}

	/**
	 * @return the total number of 'J' or 'j' characters contained
	 *         in all of the String values seen by this functor
	 */
	public int getJCount() {
		return this.count;
	}

}
