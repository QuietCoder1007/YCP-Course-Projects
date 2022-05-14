package edu.ycp.cs320.lab02a_llewis9.controller;

import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

import edu.ycp.cs320.lab02a_llewis9.controller.NumbersController;
import edu.ycp.cs320.lab02a_llewis9.model.Numbers;

public class NumbersControllerTest {
	private NumbersController controller;
	private Numbers model;
	
	@Before
	public void setUp() {
		controller = new NumbersController();
		model = new Numbers();
		
		model.setFirst(5.0);
		model.setSecond(9.0);
		model.setThird(2.0);

		controller.setModel(model);
	}
	
	@Test
	public void addNumbersTest() {
		model.setResult(controller.add(model.getFirst(), model.getSecond(), model.getThird()));
		assertEquals(16.0, model.getResult(), 0.0);
	}
	
	public void subtractNumbersTest() {
		model.setResult(controller.subtract(model.getFirst(), model.getSecond(), model.getThird()));
		assertEquals(-6.0, model.getResult(), 0.0);
	}

	public void divideNumbersTest() {
		model.setResult(controller.divide(model.getFirst(), model.getSecond(), model.getThird()));
		assertEquals(0.27778, model.getResult(), 0.1);
	}
	
	public void multiplyNumbersTest() {
		model.setResult(controller.multiply(model.getFirst(), model.getSecond(), model.getThird()));
		assertEquals(90.0, model.getResult(), 0.0);
	}
}
