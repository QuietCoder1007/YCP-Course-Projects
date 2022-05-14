package edu.ycp.cs201.mandelbrot;

public class MandelbrotTask implements Runnable {
    private double x1, y1, x2, y2;
    private int startCol, endCol, startRow, endRow;
    private int[][] iterCounts;
    
    public static double MAX = 1000;

    public MandelbrotTask(double x1, double y1, double x2, double y2,
                          int startCol, int endCol, int startRow, int endRow,
                          int[][] iterCounts) {
        this.x1 = x1;
        this.y1 = y1;
        this.x2 = x2;
        this.y2 = y2;
        this.startCol = startCol;
        this.endCol = endCol;
        this.startRow = startRow;
        this.endRow = endRow;
        this.iterCounts = iterCounts;
    }

    public void run() {
        for (int i = startRow; i < endRow; i++) {
            for (int j = startCol; j < endCol; j++) {
                Complex c = getComplex(i, j);              
                int iterCount = computeIterCount(c);
                iterCounts[i][j] = iterCount;
            }
        }
    }

    // TODO: implement getComplex and computeIterCount methods
    public Complex getComplex(int x, int y) {
    	
    	//Difference between the x and y points
    	double xDiff = (this.x2 - this.x1);
    	double yDiff = (this.y2 - this.y1);
    	
    	//Equation for calculating new imaginary number
    	Complex c = new Complex((xDiff * x)/iterCounts[x].length + this.x1, (yDiff * y)/iterCounts.length + this.y1);
    	
    	return c;
    }
    
    public int computeIterCount(Complex c) {
    	Complex z = new Complex(0, 0);
    	//Put i outside of loop so it can be accessed and 
    	//returned by the method function after the loop
    	//collapses
    	int i = 0;
    	for(; !z.isTwoReached() && i < 1000; i++){
    		//Equation for new Z
    		z = z.multiply(z).add(c);
    	}
    	return i;
    }
    
}