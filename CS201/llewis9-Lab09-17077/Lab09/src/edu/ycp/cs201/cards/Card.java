package edu.ycp.cs201.cards;

import java.lang.Comparable;

public class Card implements Comparable<Card> {
	// TODO - add fields an methods
	private Rank rank;
	private Suit suit;
	
	public Card(Rank r, Suit s) {
		this.rank = r;
		this.suit = s;
	}
	
	public Rank getRank() {
		return this.rank;
	}
	
	public Suit getSuit() {
		return this.suit;
	}

	@Override
	public int compareTo(Card card) {
		Card other = card;
		int val;
		
		val = other.getSuit().compareTo(this.suit);
		
		if(val == 0) {
			return val = other.getRank().compareTo(this.rank);
		}
		return val;
	}
}
