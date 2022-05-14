package edu.ycp.cs201.cards;

import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.*;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;

public class CardTest {
	// TODO - define test fixture objects
	Random rand = new Random();
	ArrayList<Card> deck = new ArrayList<Card>();
	Card randDiamonds;
	Card randHearts;
	Card randTwo;
	Card randJack;
	Card randQueen;
	Card randKing;
	Card randClubs;
	Card randSpades;
	Card randomCard;
	
	Card lowestCard;
	Card secondLowestCard;
	Card thirdLowestCard;
	Card fourthLowestCard;
	Card fifthLowestCard;
	Card sixthLowestCard;
	Card seventhLowestCard;
	Card eighthLowestCard;
	Card ninethLowestCard;
	Card tenthLowestCard;
	
	
	@Before
	public void setUp() throws Exception {
		// TODO - create test fixture objects
		randDiamonds = new Card(Rank.values()[rand.nextInt(12)], Suit.DIAMONDS);
		deck.add(randDiamonds);
		
		randHearts = new Card(Rank.values()[rand.nextInt(12)], Suit.HEARTS);
		deck.add(randHearts);
		
		randTwo = new Card(Rank.TWO, Suit.values()[rand.nextInt(4)]);
		deck.add(randSpades);
		
		randJack = new Card(Rank.JACK, Suit.values()[rand.nextInt(4)]);
		deck.add(randJack);
		
		randQueen = new Card(Rank.QUEEN, Suit.values()[rand.nextInt(4)]);
		deck.add(randQueen);
		
		randKing = new Card(Rank.KING, Suit.values()[rand.nextInt(4)]);
		deck.add(randKing);
		
		randSpades = new Card(Rank.values()[rand.nextInt(4)], Suit.SPADES);
		deck.add(randSpades);
		
		randClubs = new Card(Rank.values()[rand.nextInt(12)], Suit.CLUBS);
		deck.add(randClubs);
		
		randomCard = new Card(Rank.values()[rand.nextInt(12)], Suit.values()[rand.nextInt(3)]);
		deck.add(randomCard);
	}
	
	// TODO - add test methods
	
	@Test
	public void testGetSuit() {
		// TODO: test calling getSuit() on your Card objects 
		randDiamonds.getSuit();
		randHearts.getSuit();
		randTwo.getSuit();
		randJack.getSuit();
		randQueen.getSuit();
		randKing.getSuit();
		randSpades.getSuit();
		randClubs.getSuit();
		randSpades.getSuit();
		randomCard.getSuit();
	}
	
	@Test
	public void testGetRank() throws Exception {
		randDiamonds.getRank();
		randHearts.getRank();
		randTwo.getRank();
		randJack.getRank();
		randQueen.getRank();
		randKing.getRank();
		randSpades.getRank();
		randClubs.getRank();
		randSpades.getRank();
		randomCard.getRank();
	}
	
	@Test
	public void testCompareTo() throws Exception {
		randDiamonds.compareTo(randHearts);
		randHearts.compareTo(randSpades);
		randSpades.compareTo(randHearts);
		randClubs.compareTo(randClubs);
		randTwo.compareTo(randTwo);
		randKing.compareTo(randQueen);
		randJack.compareTo(randKing);
		randSpades.compareTo(randSpades);
		randomCard.compareTo(randSpades);
		
	}
	
	public void testSort() throws Exception {
		Collections.sort(deck);
		
		assertEquals(lowestCard, deck.get(0));
		assertEquals(secondLowestCard, deck.get(1));
		assertEquals(thirdLowestCard, deck.get(2));
		assertEquals(fourthLowestCard, deck.get(3));
		assertEquals(fifthLowestCard, deck.get(4));
		assertEquals(sixthLowestCard, deck.get(5));
		assertEquals(seventhLowestCard, deck.get(6));
		assertEquals(eighthLowestCard, deck.get(7));
		assertEquals(ninethLowestCard, deck.get(8));
		assertEquals(tenthLowestCard, deck.get(9));

		
	}
}
