package edu.ycp.cs201.tictactoe;

import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

public class TicTacToeTest {
	private static int[][] CENTER_X_BOARD = {
			{ 0, 0, 0 },
			{ 0, TicTacToe.PLAYER_X, 0 },
			{ 0, 0, 0 },
	};
	private static int[][] X_WINS_ROW_BOARD = {
			{ 0, TicTacToe.PLAYER_O, TicTacToe.PLAYER_O },
			{ TicTacToe.PLAYER_X, TicTacToe.PLAYER_X, TicTacToe.PLAYER_X },
			{ TicTacToe.PLAYER_O, 0, 0 },
	};
	private static int[][] DRAW_BOARD = {
			{ TicTacToe.PLAYER_X, TicTacToe.PLAYER_O, TicTacToe.PLAYER_X },
			{ TicTacToe.PLAYER_X, TicTacToe.PLAYER_X, TicTacToe.PLAYER_O },
			{ TicTacToe.PLAYER_O, TicTacToe.PLAYER_X, TicTacToe.PLAYER_O },
	};
	
	private int[][] transpose(int[][] a) {
		int[][] result = new int[3][3];
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				result[j][i] = a[i][j];
			}
		}
		return result;
	}
	
	private int[][] invertPlayer(int[][] a) {
		int[][] result = new int[3][3];
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				int p = a[i][j];
				if (p != 0) {
					p = (p == TicTacToe.PLAYER_X) ? TicTacToe.PLAYER_O : TicTacToe.PLAYER_X;
				}
				result[i][j] = p;
			}
		}
		return result;
	}

	private int[][] emptyBoard;
	private int[][] centerX;
	private int[][] xWinsRow;
	private int[][] xWinsCol;
	private int[][] oWinsRow;
	private int[][] oWinsCol;
	private int[][] draw;
	
	@Before
	public void setUp() {
		emptyBoard = new int[3][3];
		centerX = CENTER_X_BOARD.clone();
		xWinsRow = X_WINS_ROW_BOARD.clone();
		xWinsCol = transpose(X_WINS_ROW_BOARD);
		oWinsRow = invertPlayer(X_WINS_ROW_BOARD);
		oWinsCol = transpose(invertPlayer(X_WINS_ROW_BOARD));
		draw = DRAW_BOARD.clone();
	}
	
	@Test
	public void testIsLegalMove() {
		assertTrue(TicTacToe.isLegalMove(emptyBoard, 0, 0));
		assertTrue(TicTacToe.isLegalMove(emptyBoard, 0, 1));
		assertTrue(TicTacToe.isLegalMove(emptyBoard, 0, 2));
		assertTrue(TicTacToe.isLegalMove(emptyBoard, 1, 0));
		assertTrue(TicTacToe.isLegalMove(emptyBoard, 1, 1));
		assertTrue(TicTacToe.isLegalMove(emptyBoard, 1, 2));
		assertTrue(TicTacToe.isLegalMove(emptyBoard, 2, 0));
		assertTrue(TicTacToe.isLegalMove(emptyBoard, 2, 1));
		assertTrue(TicTacToe.isLegalMove(emptyBoard, 2, 2));
		
		assertFalse(TicTacToe.isLegalMove(emptyBoard, 3, 0));
		assertFalse(TicTacToe.isLegalMove(emptyBoard, 0, 3));
		
		assertFalse(TicTacToe.isLegalMove(emptyBoard, -1, 0));
		assertFalse(TicTacToe.isLegalMove(emptyBoard, 0, -1));
		
		assertTrue(TicTacToe.isLegalMove(centerX, 0, 0));
		assertFalse(TicTacToe.isLegalMove(centerX, 1, 1));
	}

	@Test
	public void testPlaceMarkerX() {
		TicTacToe.placeMarker(emptyBoard, 2, 1, TicTacToe.PLAYER_X);
		assertEquals(TicTacToe.PLAYER_X, emptyBoard[2][1]);
		assertEquals(0, emptyBoard[1][2]);
	}
	
	@Test
	public void testPlaceMarkerO() {
		TicTacToe.placeMarker(emptyBoard, 2, 1, TicTacToe.PLAYER_O);
		assertEquals(TicTacToe.PLAYER_O, emptyBoard[2][1]);
		assertEquals(0, emptyBoard[1][2]);
	}
	
	@Test
	public void testPlayerWins() {
		assertTrue(TicTacToe.playerWins(xWinsRow, TicTacToe.PLAYER_X));
		assertTrue(TicTacToe.playerWins(xWinsCol, TicTacToe.PLAYER_X));
		assertFalse(TicTacToe.playerWins(xWinsRow, TicTacToe.PLAYER_O));
		assertFalse(TicTacToe.playerWins(xWinsCol, TicTacToe.PLAYER_O));

		assertTrue(TicTacToe.playerWins(oWinsRow, TicTacToe.PLAYER_O));
		assertTrue(TicTacToe.playerWins(oWinsCol, TicTacToe.PLAYER_O));
		assertFalse(TicTacToe.playerWins(oWinsRow, TicTacToe.PLAYER_X));
		assertFalse(TicTacToe.playerWins(oWinsCol, TicTacToe.PLAYER_X));
		
		assertFalse(TicTacToe.playerWins(draw, TicTacToe.PLAYER_X));
		assertFalse(TicTacToe.playerWins(draw, TicTacToe.PLAYER_O));
	}
	
	@Test
	public void testIsDraw() {
		assertFalse(TicTacToe.isDraw(emptyBoard));
		assertFalse(TicTacToe.isDraw(centerX));
		assertFalse(TicTacToe.isDraw(xWinsRow));
		assertTrue(TicTacToe.isDraw(draw));
	}
}
