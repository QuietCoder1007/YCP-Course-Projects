package edu.ycp.cs201.cards;

import java.util.ArrayList;

/**
 * The controller class implements all of the logic required to
 * play a game of Klondike.  All of the data is represented
 * in a {@link KlondikeModel} object, and each controller method
 * takes a reference to the model object as a parameter. 
 */
public class KlondikeController {
	
	/**
	 * Initialize the model object.
	 * Should populate and shuffle the main deck, and then
	 * deal cards from the main deck onto the seven tableau piles.
	 * It should set the expose index of each tableau pile
	 * so that only the top card is exposed.
	 * It should set the expose index of the main deck so that
	 * only the top card is exposed.
	 * It should set the expose index of the waste pile so that
	 * no cards can ever be exposed (i.e., set it to a high value,
	 * such that even if it contains all 52 cards, none of them
	 * would be exposed).
	 * It should set the expose index of each foundation pile to 0.
	 * 
	 * @param model the {@link KlondikeModel} object to initialize
	 */
	public void initModel(KlondikeModel model) {
		
		//Populate the main deck
		model.getMainDeck().populate();
		
		//Shuffle the main deck
		model.getMainDeck().shuffle();
		
		//Loop that sets expose index of each Tableau Pile
		//and cascades the index with each pile having one
		//more card than the one on the left
		
		//Tableau Piles are populated by removing cards from the main Deck
		for(int i = 0; i < 7; i++) {
			model.getTableauPile(i).addCards((model.getMainDeck().removeCards(i + 1)));
			model.getTableauPile(i).setExposeIndex(model.getTableauPile(i).getIndexOfTopCard());	
		}
		
		//Loop that sets expose index of each Foundation Pile
		for(int i = 0; i < 4; i++) {
			model.getFoundationPile(i).setExposeIndex(0);
		}
		
		//Set the expose index o the main deck
		model.getMainDeck().setExposeIndex(model.getMainDeck().getIndexOfTopCard());
		
		//Set the expose index o the waste deck so high that it's never encountered
		model.getWastePile().setExposeIndex(5300);
	}

	/**
	 * <p>Attempt to create a {@link Selection} that represents one
	 * or more {@link Card}s to be moved from a pile
	 * indicated by a {@link Location}.  The {@link Location} specifies
	 * which pile to move cards from, and which card or cards
	 * within the pile should be moved.  Note that this method
	 * must check to see whether the proposed move is legal:
	 * it should return <code>null</code> if it is not legal
	 * to move the card or cards indicated by the {@link Location}.</p>
	 * 
	 * <p>If the {@link Location} has {@link LocationType#MAIN_DECK} as
	 * its location type, then the main deck must not be empty,
	 * the selected card must be the top card on the main deck.
	 * </p>
	 * 
	 * <p>If the {@link Location} has {@link LocationType#TABLEAU_PILE}
	 * as its location type, then the {@link Location}'s card index
	 * must refer to a valid card, and the card index must be
	 * greater than or equal to the tableau pile's expose index.</p>
	 * 
	 * <p>It is not legal to move cards from the waste pile or from
	 * a foundation pile, so if the {@link Location}'s location type
	 * is {@link LocationType#WASTE_PILE} or {@link LocationType#FOUNDATION_PILE},
	 * then the method should return null.</p>
	 * 
	 * <p>If the move is legal, the indicated cards should be removed
	 * from the source pile (as indicated by the {@link Location}),
	 * and transfered into the {@link Selection} object returned from
	 * the method.
	 * 
	 * @param model   the {@link KlondikeModel}
	 * @param location the {@link Location} specifying which card or cards to move
	 * @return a {@link Selection} containing the cards to move and the
	 *         {@link Location}, or null if the {@link Location} does not
	 *         indicate a legal location from which cards can be moved
	 */
	public Selection select(KlondikeModel model, Location location) {
		ArrayList<Card> selectedCardsToMove = new ArrayList<Card>();
		Selection movedCards;
		
		//if the selected location is the main deck, the main deck is not empty, and the selected card is exposed
		if(location.getLocationType() == LocationType.MAIN_DECK && 
				!model.getMainDeck().isEmpty() && 
				location.getCardIndex() == model.getMainDeck().getIndexOfTopCard()) {
			
			//Then remove and add those cards from the main deck to the selected Cards arrayList
			//and add the cards and its location to selection moveCards
			
			selectedCardsToMove.add(model.getMainDeck().drawCard());
			movedCards = new Selection(location, selectedCardsToMove);
			
			//Then return the movedCards
			return movedCards;
		}
		
		//if the selected location is the tableau pile, the tableau pile is not empty, and the selected card is exposed
		else if(location.getLocationType() == LocationType.TABLEAU_PILE &&  
				(location.getCardIndex() >= 0 && 
				location.getCardIndex()	< model.getTableauPile(location.getPileIndex()).getNumCards()) &&
				(location.getCardIndex() >= model.getTableauPile(location.getPileIndex()).getExposeIndex())){
			
			//Then remove and add those cards from the tableau pile to the selected Cards arrayList
			//and add the cards and its location to selection moveCards
			
			selectedCardsToMove.addAll(model.getTableauPile(location.getPileIndex()).removeCards(model.getTableauPile(location.getPileIndex()).getNumCards() - location.getCardIndex()));
			movedCards = new Selection(location, selectedCardsToMove);
			
			//Then return the movedCards
			return movedCards;
		}
		return null;
	}

	/**
	 * "Undo" a selection by moving cards from a {@link Selection} object
	 * back to the pile they were taken from, as indicated by the
	 * selection's origin {@link Location}.  For example, if the location
	 * indicates that the selection's cards were taken from a tableau
	 * pile, then they should be moved back to that tableau pile.
	 * 
	 * @param model      the {@link KlondikeModel}
	 * @param selection  the {@link Selection} to undo
	 */
	
	public void unselect(KlondikeModel model, Selection selection) {
		
		//the cards selected are from the main deck
		if(selection.getOrigin().getLocationType() == LocationType.MAIN_DECK) {
			
			//then pass them back to the main deck at the top and in the same order
			model.getMainDeck().addCards(selection.getCards());
		}
		
		//the cards selected are from the tableau pile
		else if(selection.getOrigin().getLocationType() == LocationType.TABLEAU_PILE) {
			
			//then pass them back to the tableau pile at the top and in the same order
			model.getTableauPile(selection.getOrigin().getPileIndex()).addCards(selection.getCards());
		}
	}

	/**
	 * <p>Determine whether it is legal to move the current {@link Selection} to a
	 * destination pile indicated by a {@link Location}.</p>
	 * 
	 * <p>If the destination {@link Location} has {@link LocationType#FOUNDATION_PILE}
	 * as its {@link LocationType}, then the {@link Selection} must contain a single card.
	 * 
	 * If the foundation pile is empty, then the selected card must be an {@link Rank#ACE}.
	 * 
	 * If the foundation pile is not empty, then the selected card must have the same suit
	 * as the top card on the foundation pile, and the ordinal value of its {@link Rank} must
	 * be one greater than the top card on the foundation pile.</p>
	 * 
	 * <p>If the destination {@link Location} has {@link LocationType#TABLEAU_PILE}
	 * as its {@link LocationType}, then:
	 * <ul>
	 * 
	 * 
	 * 
	 *   <li>If the destination tableau pile is empty, the bottom card of the {@link Selection}
	 *   must be {@link Rank#KING} </li>
	 *   
	 *   
	 *   
	 *   
	 *   
	 *   
	 *   <li>If the destination tableau pile is not empty, the bottom card of the {@link Selection}
	 *   must have a {@link Suit} that is a different {@link Color} than the top card of the
	 *   tableau pile, and the bottom card of the {@link Selection} must have an
	 *   {@link Rank} whose ordinal value is one less than the ordinal value of the
	 *   top card of the tableau pile.</li>
	 * </ul>
	 * </p>
	 * 
	 * <p>If the destination {@link Location} has {@link LocationType#MAIN_DECK} or
	 * {@link LocationType#WASTE_PILE} as its {@link LocationType}, then the move is not legal.</p>
	 * 
	 * <p>
	 * Note that this method just checks to see whether or not a move would
	 * be legal: it does not move any cards.
	 * </p>
	 * 
	 * @param model      the {@link KlondikeModel}
	 * @param selection  the {@link Selection}
	 * @param dest       the destination {@link Location}
	 * @return true if the move is legal, false if the move is not legal
	 */
//////////////////////////* !!!DOESN'T WORK!!!*///////////////////////////
//////////////////////////* !!!DOESN'T WORK!!!*///////////////////////////
//////////////////////////* !!!DOESN'T WORK!!!*///////////////////////////
	
	public boolean allowMove(KlondikeModel model, Selection selection, Location dest) {
		
		//Variable for selection card(s) since that's constant
		Card bottomCard = selection.getCards().get(0);
		
		//Variable for the top card of either the Foundation_Pile or the Tableau_Pile
		Card topCard;
		
		//If the destination is the foundation pile
		if(dest.getLocationType() == LocationType.FOUNDATION_PILE) {
			
			topCard = model.getFoundationPile(dest.getPileIndex()).getTopCard();
			
			//AND if the number of cards is not more or less than 1
			if(selection.getNumCards() == 1) {
			
				//AND if foundation pile at its designated index is not empty
				if(model.getFoundationPile(dest.getPileIndex()).isEmpty()) {
				
					//AND if the selected card's Rank, i.e. the bottom card, is equal to ace then it returns true
					if(bottomCard.getRank() == Rank.ACE) {
					
						return true;
					
					}
				
				}
				
				// OR if foundation pile at its designated index is empty
				else {
					
					//AND if the bottom cards suit is equal to the top card of the foundation pile at its designated index's suit
					if(bottomCard.getSuit() == topCard.getSuit()) {
					
						//AND if the bottom card's rank ordinal is equal to the top card of the foundation pile at its designated index's rank ordinal + 1
						if(bottomCard.getRank().ordinal() == topCard.getRank().ordinal() + 1) {
						
							return true;
						}
					}
				}
			}
		}
		
		//If the destination is the tableau Pile
		else if(dest.getLocationType() == LocationType.TABLEAU_PILE){
			
			topCard = model.getTableauPile(dest.getPileIndex()).getTopCard();
			
			//AND if foundation pile at its designated index is not empty
			if(model.getTableauPile(dest.getPileIndex()).isEmpty()) {
			
				if(bottomCard.getRank() == Rank.KING) {
				
					return true;
				}
			}
			
			//OR if foundation pile at its designated index is empty
			else {
				//AND if the selected bottom Card is a different color than the designated top Card's color
				if(bottomCard.getSuit().getColor() != topCard.getSuit().getColor()) {
				
					//AND if the selected bottom Card Rank ordinal is equal to the designated tableau pile's top Card's Rnak ordinal
					if(bottomCard.getRank().ordinal() == topCard.getRank().ordinal() - 1) {
					
						return true;
					}
				}
			}
		}
		
		//if neither of the se conditions are met then it is returned false
		return false;
	}

	/**
	 * <p>Move the cards in a {@link Selection} onto a pile as indicated
	 * by the destination {@link Location}.</p>
	 * 
	 * <p>The method does <em>not</em> need to check whether or not the move is legal:
	 * it can assume that the {@link #allowMove(KlondikeModel, Selection, Location)}
	 * method has already determined that the move is legal.</p>
	 * 
	 * <p>
	 * <strong>Important</strong>: If the pile that the selected cards
	 * were taken from is non-empty, and if its top card is not exposed,
	 * then its top card should be exposed.
	 * </p>
	 * 
	 * <p>
	 * Note that the expose index of the destination pile should not change.
	 * </p>
	 * 
	 * @param model      the {@link KlondikeModel} 
	 * @param selection  the {@link Selection} containing the selected cards
	 * @param dest       the destination {@link Location}
	 */
	
	public void moveCards(KlondikeModel model, Selection selection, Location dest) {
		//if the destination is the tableau pile
		if(dest.getLocationType() == LocationType.TABLEAU_PILE) {
			
			//add the selected cards to the Tableau Pile at its designated index
			model.getTableauPile(dest.getPileIndex()).addCards(selection.getCards());
			
			/* Logic for selected piles*/
			
			//if the selected pile (main deck) is not empty
			if(!model.getMainDeck().isEmpty() && selection.getOrigin().getLocationType() == LocationType.MAIN_DECK) {
				
				//Update the expose index to the topCard
				model.getMainDeck().setExposeIndex(model.getMainDeck().getIndexOfTopCard());
			
			}
			//if the selected pile (tableau deck) is not empty
			else if(!model.getTableauPile(selection.getOrigin().getPileIndex()).isEmpty() && selection.getOrigin().getLocationType() == LocationType.TABLEAU_PILE) {
				//Update the expose index to the topCard
				model.getTableauPile(selection.getOrigin().getPileIndex()).setExposeIndex(model.getTableauPile(selection.getOrigin().getPileIndex()).getIndexOfTopCard());
			
			}
		}
		//if the destination is the foundation pile
		else if(dest.getLocationType() == LocationType.FOUNDATION_PILE) {
			
			//Add selected card (single because you can only move card to a a foundation pile at a time) to the foundation pile at its designated index
			model.getFoundationPile(dest.getPileIndex()).addCard(selection.getCards().get(0));
			
			//if the selected pile (main deck) is not empty
			if(!model.getMainDeck().isEmpty() && selection.getOrigin().getLocationType() == LocationType.MAIN_DECK) {
			
				//Update the expose index to the topCard
				model.getMainDeck().setExposeIndex(model.getMainDeck().getIndexOfTopCard());
			}
			
			//if the selected pile (tableau deck) is not empty
			else if(!model.getTableauPile(selection.getOrigin().getPileIndex()).isEmpty() && selection.getOrigin().getLocationType() == LocationType.TABLEAU_PILE) {
				
				//Update the expose index to the topCard
				model.getTableauPile(selection.getOrigin().getPileIndex()).setExposeIndex(model.getTableauPile(selection.getOrigin().getPileIndex()).getIndexOfTopCard());
			
			}
		}
		
	}

	/**
	 * <p>If the main deck is not empty, then remove the top card from the main deck
	 * and add it to the waste pile.  If the main deck is empty, then all cards
	 * should be moved from the waste pile back to the main deck.</p>
	 * 
	 * <p>Note: when the waste pile is recycled, it should move cards
	 * back to the main deck such that they are in the same order in which
	 * they originally occurred.  In other words, drawing all of the cards
	 * from the main deck and then moving them back to the main deck
	 * should result in the main deck being in its original order.</p>
	 * 
	 * <p>Before this method returns, it should check whether the
	 * main deck is non-empty, and if it is non-empty, it should ensure
	 * that the top card on the main deck is exposed.</p>
	 * 
	 * @param model the {@link KlondikeModel}
	 */
	public void drawCardOrRecycleWaste(KlondikeModel model) {
		/*Logic checks if waste deck is empty and if it is not
		 * 
		 * then remove a card from the MainDeck and add it to the waste*/
		if( !model.getMainDeck().isEmpty() ) {
			model.getWastePile().addCard(model.getMainDeck().drawCard());
			model.getMainDeck().setExposeIndex(model.getMainDeck().getIndexOfTopCard());
		}
		
		/*if it is then add all the cards from the waste pile to the main deck*/
		else {
			
			//Keep adding cards from waste pile to the bottom of the main deck top until the waste pile is empty
			while(!model.getWastePile().isEmpty()) {
				model.getMainDeck().addCard(model.getWastePile().drawCard());
			}	
		}
	}

	/**
	 * Determine if the player has won the game.
	 * 
	 * @param model the {@link KlondikeModel}
	 * @return true if each foundation pile has 13 cards, false otherwise
	 */
	public boolean isWin(KlondikeModel model) {
		
		//Loop that checks if each pile is true
		for(int i = 0; i < 4; i++) {
			
			//There are not 13 cards in each foundation pile
			if( model.getFoundationPile(i).getNumCards() != 13 ) {
				
				//return false
				return false;
			}
		}
		
		//if the condition is never met in the loop then return true
		return true;
	}
}
