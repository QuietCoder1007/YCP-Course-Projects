package edu.ycp.cs320.lab02a_llewis9.controller;
import edu.ycp.cs320.lab02a_llewis9.model.Numbers;

public class NumbersController {
	private Numbers model;
	
	public void setModel(Numbers model) {
		this.model = model;
	}
	
	public Double add(Double first, Double second, Double third) {
		return this.model.getFirst() + this.model.getSecond() + this.model.getThird();
	}
	
	public Double multiply(Double first, Double second, Double third) {
		return this.model.getFirst() * this.model.getSecond() * this.model.getThird();
	}
	
	public Double divide(Double first, Double second, Double third) {
		return this.model.getFirst() / this.model.getSecond() / this.model.getThird();
	}
	
	public Double subtract(Double first, Double second, Double third) {
		return this.model.getFirst() - this.model.getSecond() - this.model.getThird();
	}
}
