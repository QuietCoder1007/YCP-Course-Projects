package edu.ycp.cs201.coins;

public class Coins {
	// TODO: add fields here
	private int pennies;
	private int nickels;
	private int dimes;
	private int quarters; 

	// TODO: add constructors
	public Coins(){
		pennies = 0;
		nickels = 0;
		dimes = 0;
		quarters = 0;
	}
	
	public Coins(int pennies, int nickels, int dimes, int quarters){
		this.pennies = pennies;
		this.nickels = nickels;
		this.dimes = dimes;
		this.quarters = quarters;
	}
	// TODO: add methods
	public int findCentsValue() {
		return pennies + (nickels * 5) + (dimes * 10) + (quarters * 25);
	}
	
	public int findDollars() {
		return findCentsValue() / 100;
	}
	
	public int findChange() {
		return findCentsValue() % 100; 
		
	}
}
