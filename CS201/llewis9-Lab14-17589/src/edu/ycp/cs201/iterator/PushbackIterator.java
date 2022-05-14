package edu.ycp.cs201.iterator;

import java.util.Iterator;

public class PushbackIterator<E> implements Iterator<E> {
	private Iterator<E> delegate;
	private E cached;
	
	public PushbackIterator(Iterator<E> delegate) {
		this.delegate = delegate;
		this.cached = null;
	}
	
	@Override
	public boolean hasNext() {
		return cached != null || delegate.hasNext();
	}
	
	@Override
	public E next() {
		if (cached != null) {
			E result = cached;
			cached = null;
			return result;
		} else {
			return delegate.next();
		}
	}
	
	@Override
	public void remove() {
		if (cached != null) {
			throw new UnsupportedOperationException("Pushed back element can't be removed");
		}
		delegate.remove();
	}
	
	public void pushback(E value) {
		if (cached != null) {
			throw new UnsupportedOperationException("Only one value may be pushed back");
		}
		cached = value;
	}
}
