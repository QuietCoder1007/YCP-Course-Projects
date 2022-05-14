package edu.ycp.cs201.cards;

import java.util.ArrayList;
import java.util.List;

/**
 * A Selection object represents one or more cards that
 * the user wants to move.  A {@link Location} indicates the
 * source of the moved cards (e.g., the main deck or a
 * tableau pile).  An ArrayList of {@link Card}s stores
 * references to the cards that the user wants to move.
 */
public class Selection {
	// TODO: add fields
	private Location pileSelected;
	private ArrayList<Card> cardsSelected;
	/**
	 * Constructor.
	 * 
	 * @param origin   a {@link Location} describing the origin (source) of the moved cards
	 * @param selected an ArrayList containing the {@link Card}s the user wants to move
	 */
	//Constructor to pass the values for the origin of the cards selected to
	//add to a private Location field and the number of cards that were 
	//selected to append to a private ArrayList
	public Selection(Location origin, ArrayList<Card> selected) {
		pileSelected = origin;
		cardsSelected = selected;
		
	}

	/**
	 * @return the origin (source) {@link Location} which describes where the cards
	 *         are being moved from
	 */
	//Getter for the Location private field
	public Location getOrigin() {
		return pileSelected;
	}

	/**
	 * @return the ArrayList of {@link Card}s the user wants to move
	 */
	//Getter for the private ArrayList field
	public ArrayList<Card> getCards() {
		return cardsSelected;
	}

	/**
	 * @return the number of cards the user wants to move
	 */
	//Getter for the number cards in the private ArrayList field
	public int getNumCards() {
		return cardsSelected.size();
	}
}
