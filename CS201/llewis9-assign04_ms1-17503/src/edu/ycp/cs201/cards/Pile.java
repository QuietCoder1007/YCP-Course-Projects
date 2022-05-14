package edu.ycp.cs201.cards;

import java.util.ArrayList;
import java.util.Collections;
import java.util.NoSuchElementException;

/**
 * Class to represent a pile of {@link Card}s.
 * Each card has an index, with index 0 being the card
 * at the bottom of the pile.
 * Each pile has an "expose index": all cards whose
 * indices are greater than or equal to the expose index
 * are face-up, and all other cards are face-down.
 */
public class Pile {
	// TODO: add fields
	private ArrayList<Card> cardPile;
	private Card exposed;
	/**
	 * Constructor.  The pile will be empty initially,
	 * and its expose index will be set to 0.
	 */
	//Constructor to create empty ArrayList field
	public Pile() {
		cardPile = new ArrayList<Card>();
	}

	/**
	 * @return the expose index
	 */
	//Getter for expose index
	public int getExposeIndex() {
		if(isEmpty()) {
			return 0;
		}
		return getIndexOfTopCard();
	}
	
	/**
	 * Set the expose index.
	 * 
	 * @param exposeIndex the expose index to set
	 */
	//Setter for cardPile ArrayList to what the exposedIndex is
	public void setExposeIndex(int exposeIndex) {
		cardPile.set(exposeIndex, exposed);
	}
	
	/**
	 * Add a {@link Card} to the pile.  The card added is placed
	 * on top of the cards currently in the pile.
	 * 
	 * @param card the {@link Card} to add
	 */
	//Method that adds new cards to the top of the pile
	public void addCard(Card card) {
		cardPile.add(card);
	}

	/**
	 * @return the number of @{link Card}s in the pile
	 */
	//Getter for the number of cards in the Pile
	public int getNumCards() {
		return cardPile.size();
	}
	
	/**
	 * @return true if the pile is empty, false otherwise
	 */
	//Logic for determining if an array is empty
	public boolean isEmpty() {
		return (getNumCards() < 1) ? true : false;
	}
	
	/**
	 * Get the {@link Card} whose index is given.
	 * 
	 * @param index the index of the card to get
	 * @return the {@link Card} at the index
	 * @throws NoSuchElementException if the index does not refer to a valid card
	 */
	//Getter for a specific card at a certain index
	public Card getCard(int index) {
		//Throws NoSuchElementException if numCards is an invalid value
		if(index < 0 || index > getNumCards() - 1) {
			throw new NoSuchElementException("Not a valid index!");
		}
		return cardPile.get(index);
	}

	/**
	 * Get the {@link Card} on top of the pile.
	 * 
	 * @return the {@link Card} on top of the pile
	 * @throws NoSuchElementException if the pile is empty
	 */
	//Getter for the exposedIndex
	public Card getTopCard() {
		//Throws NoSuchElementException if the cardPile is empty
		if(isEmpty()) {
			throw new NoSuchElementException("Your Pile is empty!");
		}
		return cardPile.get(getExposeIndex());
	}
	
	/**
	 * @return the index of the top {@link Card}, or -1 if the pile is empty
	 */
	//Getter for index of the last card added
	//Returns -1 if cardPile is empty
	public int getIndexOfTopCard() {
		return ( isEmpty() ) ? -1 : getNumCards() - 1;
	}
	
	/**
	 * Remove given number of {@link Card}s from the top of the pile.
	 * 
	 * @param numCards number of cards to remove
	 * @return an ArrayList containing the removed cards
	 * @throws IllegalArgumentException if the pile does not have enough {@link Card}s to satisfy the request
	 */
	//Method that removes last numCards in the ArrayList and appends to another ArrayList in the same order
	//and returns that new ArrayList (cardsRemoved)
	public ArrayList<Card> removeCards(int numCards) {
		//Throws IllegalArgumentException if numCards is an invalid value
		if(numCards > cardPile.size()) {
			throw new IllegalArgumentException("Please use a valid input!");
		}
		ArrayList<Card> cardsRemoved = new ArrayList<Card>();
		/* Removes numCards of cards from cardPile and
		/  appends them to cardsRemoved in the same line since
		/ the ArrayList's remove method also returns that indexed
		/ element as well
		*/
		for(int i = 0; i < numCards; i++) {
			cardsRemoved.add(0, cardPile.remove(getIndexOfTopCard()));
		}
		return cardsRemoved;
	}
	
	/**
	 * Add {@link Card}s to the top of the pile.
	 * 
	 * @param cardsToAdd an ArrayList containing the {@link Card}s to add
	 */
	//Method that appends an ArrayList of cards to the ArrayList cardPile
	public void addCards(ArrayList<Card> cardsToAdd) {
		cardPile.addAll(cardsToAdd);
	}
	
	/**
	 * Populate the pile by adding 52 {@link Card}s
	 * representing all possible combinations of
	 * {@link Suit} and {@link Rank}.
	 */
	//Method that populates the cardPile ArrayList with 52 cards
	public void populate() {
		Suit[] allSuits = Suit.values();
    	Rank[] allRanks = Rank.values();
		for (int j = 0; j < allSuits.length; j++) {
    	    for (int i = 0; i < allRanks.length; i++) {
    	        // use allSuits[j] and allRanks[i] to create a Card
    	    	cardPile.add(new Card(allRanks[i], allSuits[j]));
    	    }
    	}
	}

	/**
	 * Shuffle the {@link Card}s in the pile by rearranging
	 * them randomly.
	 */
	//Method that shuffles all the cards in cardPile
	public void shuffle() {
		Collections.shuffle(cardPile);
	}
	
	/**
	 * Remove the top {@link Card} on the pile and return it.
	 * 
	 * @return the removed {@link Card}
	 * @throws NoSuchElementException if the pile is empty
	 */
	//Method removes and returns the top card in the ArrayList
	public Card drawCard() {
		//Throws NoSuchElementException if numCards is an invalid value
		if(isEmpty()) {
			throw new NoSuchElementException();
		}
		return cardPile.remove(getIndexOfTopCard());
	}
}
