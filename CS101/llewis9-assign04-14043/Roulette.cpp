		// CS101 Assignment 4 - Fall 2018
	//Le Quient Lewis II
//Create a roulette machine with 38 slots, two are green and the rest (1-36) are regular colors. 
//If the users input equals the spin of the wheel, even or odd, then the player wins twice of what they bet.
//If they bet on a particular number and win, then they get 35 times their plus their bet once more.
//Anything else they lose their bet and it gets subtracted from their chosen total and prompting if the user wants to quit or continue.
//Create this program using only 8 functions

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

bool Test=true;

int get_bet_amount(int amount);

int get_bet_type();

int get_number();

int spin_wheel();

int evaluate_odd(int spin, int numChose, int betAmount); 

int evaluate_even(int spin, int numChose, int betAmount);

int evaluate_number(int spin, int numChose, int betAmount);

void print_winnings(int profit, int amount);

int main() {
int bet=0, profit=0, betType=0, numGot, numChose;

	int i=1;
	//Money in user's account. Prompt user for how much they want
	int totMoney;
	printf("How much money will you take to play Roulette?:$ ");
	scanf("%i",&totMoney);

	while(totMoney>0 && i==1){
		betType=get_bet_amount(totMoney);
		
		
		srand(time(0));
		
		numChose=get_number();
		numGot=spin_wheel();
		
		switch(betType)
		{
			case 1:	evaluate_odd(numGot,numChose, bet);
			profit=evaluate_odd(numGot,numChose, bet);
			break;
			case 2: evaluate_even(numGot,numChose, bet);
			profit=evaluate_even(numGot,numChose, bet);		
			break;
			case 3: evaluate_number(numGot,numChose, bet);
			profit=evaluate_number(numGot,numChose, bet);
			break;
		}
		print_winnings(profit, totMoney);
	return 0;
	}
}

//Bet amount function
int get_bet_amount(int amount){
	int bet=0;

	//Prompt user for how much they will bet
	printf("Enter starting bet: $");
	scanf("%i",&bet)
	;
	//Test for valid bet input
	while(Test){
		if(bet>0 && bet<=amount){
			Test=false;
		}
		else{ 
			printf("INVALID.");
			printf("YOU MUST HAVE A VALID INPUT.");
			printf("PUT IN A CORRECT INPUT OR WE, THE DALEKS, WILL EXTERMINATE: $");
			scanf("%i",&bet);
		}
	}
	return bet;
}

//Bet type function
int get_bet_type(){
	int betType;
	Test=true;
	
	//Test for valid input for bet Type 
	while(Test==true){
	printf("How do you wish to bet?\n");
	printf("1 To bet on Odd\n");
	printf("2 To bet on Even\n");
	printf("3 To bet on a Particular Number\n");
	scanf("%i",&betType);
	
		if (betType>0 && betType<4){
			Test=false;
		}
		else{
			printf("INVALID.");
			printf("YOU MUST HAVE A VALID INPUT.");
			printf("PUT IN A CORRECT INPUT OR WE, THE DALEKS, WILL EXTERMINATE! : ");
			scanf("%i",&betType);
		}
	}
	return betType;
}	

//Function prompting user to choose number
int get_number(){
	int numChose=0;
	switch(get_bet_type()){
		case 1:printf("Pick an Odd Number from 1-36: ");
		scanf("%i",&numChose);
		while(numChose%2==0){
			scanf("%i",&numChose);
		}
		break;
		
		case 2:printf("Pick an Even Number from 1-36: ");
		scanf("%i",&numChose);
		while(numChose%2==1){
			scanf("%i",&numChose);
		}
		break;
		
		case 3:printf("Pick ANY Number from 1-36: ");
		scanf("%i",&numChose);
		break;
	}
	return numChose;
}

//Function evaluating what the ball will roll on
int spin_wheel(){
	int numGot=0;
	
	//reroll until loop breaks with valid input
	while(numGot<0 || numGot>38){
	numGot=rand()%38;
	}
	
	//Tells user where he has landed
	if(numGot>0 and numGot<37)
		printf("You have landed on %i\n", numGot);
	else if(numGot==0 or numGot==37)
		printf("You landed on a green zero. You suck at this game.\n");
	
	return numGot;
}

//Evaluate whether the input for the chosen number is equal to the spin and whether they win or not
int evaluate_odd(int spin, int numChose, int betAmount){
int win;

	//If they win, they win twice their original bet
	if(spin==numChose){
		win=2*betAmount;
	}
	
	//If they lose, they lose only their original bet amount
	else if(spin!=numChose){
		win=-2*betAmount;
	}
	return win;
}

	//Evaluate whether the input for the chosen number is equal to the spin and whether they win or not
int evaluate_even(int spin, int numChose, int betAmount){
int win;

	//If they win, they win twice their original bet	
	if(spin==numChose){
		win=2*betAmount;
	}
	
	//If they lose, they lose only their original bet amount
	else if(spin!=numChose){
		win=-2*betAmount;
	}
	return win;
}

//Evaluate whether the input for the chosen number is equal to the spin and whether they win or not
int evaluate_number(int spin, int numChose, int betAmount){
int win;
	
	//If they win, they win twice their original bet
	if(spin==numChose){
		win=(35*betAmount)+betAmount;
	}
	
	//If they lose, they lose only their original bet amount
	else if(spin!=numChose){
		win=-2*betAmount;
	}
	return win;
}

//Function that computes their totals wins/losses and calculates their total account balance
void print_winnings(int profit, int amount){
	
	amount+=profit;
	printf("Your total winnings are %i\n", profit);
	printf("Your current account is $%i\n",amount);
}