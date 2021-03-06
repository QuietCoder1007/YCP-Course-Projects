package edu.ycp.cs201.functors;

public interface Functor<E> {
	/**
	 * Apply the functor to a value.
	 * 
	 * @param value a value
	 */
	public void apply(E value);
}
