package edu.ycp.cs201.tictactoe;

import java.util.Scanner;

public class TicTacToe {
	public static final int PLAYER_X = 1;
	public static final int PLAYER_O = 2;
	
	public static void main(String[] args) {
		int[][] board = new int[3][3];
		
		Scanner keyboard = new Scanner(System.in);
		
		int player = PLAYER_X;
		boolean done = false;
		while (!done) {
			System.out.println();
			printBoard(board);
			
			System.out.printf("\nPlayer %c's turn:\n", (player == PLAYER_X) ? 'X' : 'O');
			int row = getRow(keyboard);
			int col = getCol(keyboard);
			
			if (!isLegalMove(board, row, col)) {
				System.out.println("Invalid move, try again");
			} else {
				placeMarker(board, row, col, player);
				if (playerWins(board, player)) {
					// Current player wins
					System.out.printf("Player %s wins!\n", player == PLAYER_X ? "X" : "O");
					done = true;
				} else if (isDraw(board)) {
					// Game is a draw
					System.out.println("It's a draw!");
					done = true;
				} else {
					// Switch player
					player = (player == PLAYER_X) ? PLAYER_O : PLAYER_X;
				}
			}
		}
		System.out.println("Thanks for playing!");
	}

	public static void printBoard(int[][] board) {
		char columns = '|';
		String spaces = "   ";
		String rows = "---";
		for(int i=0; i<5; i++) {
			if(i % 2 == 1) {
				for(int j = 0; j<board.length; j++) {
					System.out.print(rows);
					
					if(j!=2)
					System.out.print(columns);
					
					if(j==2) {
						System.out.print("\n");
					}
				}
			}
			if(i % 2 == 0) {
				for(int j = 0; j<board.length; j++) {
					if(i == 0) {
						if(board[i][j] == 0) {
							System.out.print(spaces);
						}
						else if (board[i][j] == 1){
							System.out.print(" X ");
						}
						else if (board[i][j] == 2){
							System.out.print(" O ");
						}
					}
					else if(i == 2) {
						if(board[i - 1][j] == 0) {
							System.out.print(spaces);
						}
						else if (board[i - 1][j] == 1){
							System.out.print(" X ");
						}
						else if (board[i - 1][j] == 2){
							System.out.print(" O ");
						}
					}
					else if(i == 4) {
						if(board[i - 2][j] == 0) {
							System.out.print(spaces);
						}
						else if (board[i - 2][j] == 1){
							System.out.print(" X ");
						}
						else if (board[i - 2][j] == 2){
							System.out.print(" O ");
						}
					}
					if(j!=2)
					System.out.print(columns);
					
					if(j==2) {
						System.out.print("\n");
					}
				}
			}
		}
	}
	
	
	public static int getRow(Scanner keyboard) {
			System.out.println("What row?\n");  // (2)
		    int rows = keyboard.nextInt();  
		    return rows;
	}

	public static int getCol(Scanner keyboard) {
		System.out.println("What column?\n");  // (2)
	    int col = keyboard.nextInt();
	    return col;
	}

	public static boolean isLegalMove(int[][] board, int row, int col) {
		boolean test;
			if(board[row][col] == 0) {			
				test = true;
			}
			else{
				test = false;
			}
		return test;
	}
	public static void placeMarker(int[][] board, int row, int col, int player) {
		
		if(player == PLAYER_X) {
			if(isLegalMove(board, row, col) == true) {
			board[row][col] = 1;
				
			}
		}
		else if (player == PLAYER_O) {
			if(isLegalMove(board, row, col) == true) {
			board[row][col] = 2;
			}
		}
	}

	public static boolean playerWins(int[][] board, int player) {
		// TODO: implement this for real
		boolean win = false;
		if(player == PLAYER_X) {
			for(int row=0; row<board.length; row++) {
				for(int col=0; col<board.length; col++) {
					if(board[row][0] == board[row][1] && board[row][0] == board[row][2] && board[row][0] == 1) {
						win = true;
					}
					else if(board[0][col] == board[1][col] && board[0][col] == board[2][col] && board[0][col] == 1) {
						win = true;
					}
				}
			}
		}
		else if (player == PLAYER_O) {
			for(int row=0; row<board.length; row++) {
				for(int col=0; col<board.length; col++) {
					if(board[row][0] == board[row][1] && board[row][0] == board[row][2] && board[row][0] == 2) {
						win = true;
					}
					else if(board[0][col] == board[1][col] && board[0][col] == board[2][col] && board[0][col] == 2) {
						win = true;
					}
				}
			}
		}
		else {
			win = false;
		}
		return win;
	}
	public static boolean isDraw(int[][] board) {
		// TODO: implement this for real
		boolean draw = false;
		for(int i=0; i<board.length;i++) {
			for(int j=0; j<board.length; j++) {
				if(board[i][j] != 0) {
					draw = true;
				}
				else {
					draw = false;
				}
			}
		}
		return draw;
	}
}
