package edu.ycp.cs201.cards;


import java.util.ArrayList;

/**
 * Model class storing information about a Klondike game
 * in progress.  Consists of a number of {@link Pile} objects
 * representing the various piles: main deck, waste,
 * foundation, and tableau piles.  Note that none of the
 * game logic is implemented in this class: all logic
 * is implemented in the {@link KlondikeController} class.
 */
public class KlondikeModel {
	// TODO: add fields
	private Pile main;
	private Pile discard;
	private Pile[] foundation;
	private Pile[] tableau;
	/**
	 * Constructor.  Should create all of the required {@link Pile} objects,
	 * but it should <em>not</em> initialize them.  All piles should start
	 * out as empty.
	 */
	//Constructor that creates the required object fields
	public KlondikeModel() {
		main = new Pile();
		discard = new Pile();
		foundation = new Pile[4];
		tableau = new Pile[7];
		//Each index is an individual object field that needs to be created
		for(int i = 0; i < foundation.length; i++) {
			foundation[i] = new Pile();
		}
		
		//Each index is an individual object field that needs to be created
		for(int i = 0; i < tableau.length; i++) {
			tableau[i] = new Pile();
		}
	}
	
	/**
	 * @return the {@link Pile} representing the main deck
	 */
	//Getter for the main deck
	public Pile getMainDeck() {
		return main;
	}

	/**
	 * Get a reference to one of the tableau piles.
	 * 
	 * @param index index of a tableau pile (in the range 0..6)
	 * @return the tableau {@link Pile}
	 */
	//Getter for the tableau piles
	public Pile getTableauPile(int index) {
		return tableau[index];
	}
	
	/**
	 * Get a reference to one of the foundation piles.
	 * 
	 * @param index index of a foundation pile (in the range 0..3)
	 * @return the foundation {@link Pile}
	 */
	//Getter for the foundation piles
	public Pile getFoundationPile(int index) {
		return foundation[index];
	}

	/**
	 * @return the {@link Pile} representing the waste pile
	 */
	//Getter for the discarded pile
	public Pile getWastePile() {
		return discard;
	}
}
