package edu.ycp.cs201.mandelbrot;


public class Complex {
    private double real;
    private double imag;

    // Constructor
    public Complex(double real, double imag) {
        this.real = real;
        this.imag = imag;
    }
    //real number Getter
    public double getX() {
        return this.real;
    }
    
    //imaginary number Getter
    public double getY() {
        return this.imag;
    }

    // add given complex number to this one, returning the Complex result
    public Complex add(Complex other) {
        return new Complex(this.real + other.real, this.imag + other.imag);
    }

    // multiply given complex number by this one, returning the Complex result
    public Complex multiply(Complex other) {
        return new Complex((this.real * other.real) - (this.imag * other.imag), (other.real * this.imag) + (this.real * other.imag)) ;
    }

    // get the magnitude of this complex number
    public double getMagnitude() {
        return Math.sqrt(Math.pow(this.real, 2) + Math.pow(this.imag, 2));
    }
    //Logic method for if the magnitude reaches or passes 2.0
    public boolean isTwoReached() {
    	return getMagnitude() >= 2.0 ? true : false;
    }
}