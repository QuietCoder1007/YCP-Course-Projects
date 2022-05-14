package edu.ycp.cs320.lab02a_llewis9.controller;

import edu.ycp.cs320.lab02a_llewis9.model.GuessingGame;

/**
 * Controller for the guessing game.
 */
public class GuessingGameController {
	private GuessingGame model;

/**
* Set the model.
*
* @param model the model to set
*/
public void setModel(GuessingGame model) {
	this.model = model;
}

/**
* Start a new guessing game by setting the minimum to 1 and the maximum to 100.
*/
public void startGame() {
	this.model.setMax(100);
	this.model.setMin(1);
}

/**
* Called to indicate that the current guess is correct.
* Set the min and max to the current guess.
*/
public void setNumberFound() {
	this.model.setMax(this.model.getGuess());
	this.model.setMin(this.model.getGuess());
}

/**
* Called to indicate that the user is thinking of a number that
* is less than the current guess.
*/
public void setNumberIsLessThanGuess() {
	this.model.setMax(this.model.getGuess());
}

/**
* Called to indicate that the user is thinking of a number that
* is greater than the current guess.
*/
public void setNumberIsGreaterThanGuess() {
		this.model.setMin(this.model.getGuess());
	}
}