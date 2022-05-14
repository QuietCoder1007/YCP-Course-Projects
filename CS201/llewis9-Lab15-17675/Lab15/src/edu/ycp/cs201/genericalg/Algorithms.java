package edu.ycp.cs201.genericalg;

import java.util.Collection;
import java.util.Comparator;
import java.util.Iterator;
import java.util.List;

public class Algorithms {
	public static<E extends Comparable<E>> E findMin(Collection<E> c) {
		Iterator<E> i = c.iterator();
		E minObject = i.next();
		E nextObject = i.next();
		
		while(i.hasNext()) {
			
			if(minObject.compareTo(nextObject) > 0) {
				minObject = nextObject;
			}
			nextObject = i.next();
		}
		
		return minObject;
	}
	
	public static<E> E findMin(Collection<E> c, Comparator<E> comp) {
		Iterator<E> i = c.iterator();
		E minObject = i.next();
		E nextObject = i.next();
		
		while(i.hasNext()) {
			
			if(comp.compare(minObject, nextObject) > 0) {
				minObject = nextObject;
			}
			nextObject = i.next();
		}
		
		return minObject;
		
	}

	public static<E extends Comparable<E>> E findMax(Collection<E> c) {
		Iterator<E> i = c.iterator();
		E maxObject = i.next();
		E nextObject = i.next();
		
		while(i.hasNext()) {
		
			if(maxObject.compareTo(nextObject) < 0) {
				maxObject = nextObject;
			}
			nextObject = i.next();
		}
		
		return maxObject;
	}
	
	public static<E> E findMax(Collection<E> c, Comparator<E> comp) {
		Iterator<E> i = c.iterator();
		E maxObject = i.next();
		E nextObject = i.next();
		
		while(i.hasNext()) {
		
			if(comp.compare(maxObject, nextObject) < 0) {
				maxObject = nextObject;
			}
			nextObject = i.next();
		}
		
		return maxObject;
	}
	
	public static<E> int sequentialSearch(List<E> list, E searchVal) {
		if(list.contains(searchVal)) {
			return list.indexOf(searchVal);
		}
		return -1;
	}
}
