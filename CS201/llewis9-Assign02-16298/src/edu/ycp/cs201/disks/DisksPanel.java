package edu.ycp.cs201.disks;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.ArrayList;
import java.util.Random;

import javax.swing.JPanel;
import javax.swing.Timer;

public class DisksPanel extends JPanel {
	private static final long serialVersionUID = 1L;

	public static final int WIDTH = 400;
	public static final int HEIGHT = 300;
	
	private Timer timer;
	// TODO: add any other fields you need to represent the state of the game
	
	public DisksPanel() {
		setPreferredSize(new Dimension(WIDTH, HEIGHT));
		setBackground(Color.GRAY);
		
		addMouseListener(new MouseAdapter(){
			@Override
			public void mouseClicked(MouseEvent e) {
				handleMouseClick(e);
			}
		});
		
		addMouseMotionListener(new MouseAdapter() {
			@Override
			public void mouseMoved(MouseEvent e) {
				handleMouseMove(e);
			}
		});
		
		// Schedule timer events to fire every 100 milliseconds (0.1 seconds)
		this.timer = new Timer(100, new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				handleTimerEvent(e);
			}
		});
	}

	// You can call this method to convert a DiskColor value into
	// a java.awt.Color object.
	public Color colorOf(DiskColor dc) {
		return new Color(dc.red(), dc.green(), dc.blue());
	}

	// This method is called whenever the mouse is moved
	protected void handleMouseMove(MouseEvent e) {
		// TODO
	}
	
	// This method is called whenever the mouse is clicked
	protected void handleMouseClick(MouseEvent e) {
		// TODO
	}
	
	// This method is called whenever a timer event fires
	protected void handleTimerEvent(ActionEvent e) {
		// TODO
	}
	
	private static final Font FONT = new Font("Dialog", Font.BOLD, 24);

	// This method is called automatically whenever the contents of
	// the window need to be redrawned.
	@Override
	public void paintComponent(Graphics g) {
		// Paint the window background
		super.paintComponent(g);
		
		// TODO: draw everything that needs to be drawn
	}
}
