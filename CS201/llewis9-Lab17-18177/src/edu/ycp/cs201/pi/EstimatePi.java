package edu.ycp.cs201.pi;

import java.util.Scanner;

public class EstimatePi {
	private static final int NUM_POINTS = 100000000;
	
	public static void main(String[] args) {
		Scanner keyboard = new Scanner(System.in);
		
		System.out.print("How many computation threads? ");
		int numThreads = keyboard.nextInt();
		
		double a = 0.0; // estimated area
		
		System.gc();
		
		double begin = System.currentTimeMillis();
		
		PiTask[] tasks;
		Thread[] threads;
		
		if (numThreads == 1) {
			// TODO: sequential computation
			tasks = new PiTask[1];
			threads = new Thread[1];
			
			tasks[0] = new PiTask(NUM_POINTS);
			threads[0] = new Thread(tasks[0]);
			threads[0].start();
			
			try {
				threads[0].join();
			}
			catch (InterruptedException e) {
				System.err.println("A thread was interrupted");
			}
			
			a = ((double)tasks[0].getCount()/(double)NUM_POINTS);
			
		} else if (numThreads == 2) {
			// TODO: parallel computation using 2 threads
			tasks = new PiTask[2];
			threads = new Thread[2];
			
			for(int i = 0; i < 2; i++) {
				tasks[i] = new PiTask(NUM_POINTS/2);
				threads[i] = new Thread(tasks[i]);
			}
			
			threads[0].start();
			threads[1].start();
			
			try {
				threads[0].join();
				threads[1].join();
			}
			catch (InterruptedException e) {
				System.err.println("A thread was interrupted");
			}
		
			a = ((double)tasks[0].getCount()/(double)NUM_POINTS) + ((double)tasks[1].getCount()/(double)NUM_POINTS) ;
		} else {
			throw new IllegalArgumentException("only 1 or 2 threads are allowed");
		}
		
		// TODO: compute estimate of pi, print it
		
		
		double end = System.currentTimeMillis();
		
		a = a/0.25;
		
		System.out.println("Computation took " + (end - begin) + " milliseconds");
		System.out.println("Pi rouhgly equals " + a);
	}
}
