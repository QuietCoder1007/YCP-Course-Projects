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
	
	// TODO: add any other fields you need to represent the state of the game
	private Random rand;
	private Timer timer;
	private int tick;
	
	private int randRadius;
	
	private Color barColor;
	private DiskColor newDiskColor;
	
	private int x;
	private int y;
	
	private ArrayList<Disk> disk = new ArrayList<Disk>();
	
	private int diskCount;
	
	private boolean lose;
	
	public DisksPanel() {
		setPreferredSize(new Dimension(WIDTH, HEIGHT));
		setBackground(Color.GRAY);
		rand = new Random();
		
		lose = false;
		
		//randomize the DiskColor for each disk
		newDiskColor = DiskColor.values()[diskCount % DiskColor.values().length];
		barColor = new Color(255, 23, 23, 63);
		
		//Randomize the radius
		randRadius = rand.nextInt(44);
		tick = 45;
		
		//reRandomize the first value until it is greater than 10
		while( randRadius < 10 ) {
			randRadius = rand.nextInt(44);
		}

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
		//Initiate timer loop
		timer.start();
	}

	// You can call this method to convert a DiskColor value into
	// a java.awt.Color object.
	public Color colorOf(DiskColor dc) {
		return new Color(dc.red(), dc.green(), dc.blue());
	}

	// This method is called whenever the mouse is moved
	protected void handleMouseMove(MouseEvent e) {
		
		//Assigns x/y positions of mouse to state variables x/y
		this.x = e.getX();
		this.y = e.getY();
			
		//Repaint to update circle around cursor
		repaint();
	}
	
	
	// This method is called whenever the mouse is clicked
	protected void handleMouseClick(MouseEvent e) {
		//DiskColor variable to assign randomized color for disk ArrayList from DiskColor enum array
		newDiskColor = DiskColor.values()[diskCount % DiskColor.values().length];
		
		//Increments disk by 1 starting from 0
		diskCount++;
		
		//Assigns elements to a new disk and grows it
		disk.add( new Disk(e.getX(), e.getY(), randRadius, newDiskColor) );			
		if( e.getButton() == MouseEvent.BUTTON1 ) {
			
			for(int i = 0; i < disk.size() - 1; i++) {
				//Test conditions for overlap. Assigns true to lose condition if true
				if( disk.get(disk.size() - 1).overlaps(disk.get(disk.size()  - i - 2)) ){
					lose = true;
				}
			}
			//Test conditions for Boundary Collision. Assigns true to lose condition if true
			if( disk.get(disk.size() - 1).isOutOfBounds(WIDTH, HEIGHT) ) {
				lose = true;
			}
		}
		timer.stop();
		
		//Decrements tick by 5 every time the diskCount increases by 5
		switch(diskCount / 5) {
		case 0: tick = 45;
				break;
		case 1: tick = 35;
				break;
		case 2: tick = 30;
				break;
		case 3: tick = 25;
				break;
		case 4: tick = 20;
				break;
		case 5: tick = 15;
				break;
		case 6: tick = 10;
				break;
	}
		
		timer.start();
		
		
		//stops the game from drawing if lose condition is false
		if( !lose ) {
		// if condition is true, call repaint to update board with new disk
			repaint();
		}
		
		
		//Randomize radius again to ensure it is greater than 10
		randRadius = rand.nextInt(44);
		
		//If radius is less than 10 it reassigns the value until it is greater than 10
		while( randRadius < 10 ) {
			randRadius = rand.nextInt(44);
		}
	}
	
	// This method is called whenever a timer event fires
	protected void handleTimerEvent(ActionEvent e) {
		//repaint timer bar if the condition is true
		if(tick == 0) {
			lose = true;
		}
		if( lose != true) {
			tick--;
		}
		repaint();
	}
	
	private static final Font FONT = new Font("Dialog", Font.BOLD, 48);

	// This method is called automatically whenever the contents of
	// the window need to be redrawn.
	@Override
	public void paintComponent(Graphics g) {
		// Paint the window background
		super.paintComponent(g);
		String youLost = "GAME OVER!!!";
		
		// TODO: draw everything that needs to be drawn
		
		//Circle that follows the mouse cursor
		g.setColor(Color.BLACK);
		g.drawOval(x - (int)randRadius, y - (int)randRadius, (int)2*randRadius, (int)2*randRadius);
		
		//Loop for drawing the disks
		for(int i = 0; i < disk.size(); i++) {
			g.setColor(colorOf( disk.get(i).getColor()) );
			g.fillOval((int)disk.get(i).getX() - ((int)disk.get(i).getRadius()), (int)disk.get(i).getY() - ((int)disk.get(i).getRadius()), (int) (2*disk.get(i).getRadius()), (int) (2*disk.get(i).getRadius()));
		}
		
		//Game Over condition. If lose is true stop game
		if( lose ) {
			g.setFont(FONT);
			g.setColor(Color.BLACK);
			g.drawString(youLost, 50, 150);
			timer.stop();
		}	

		
		//Draws number of disks on the screen starting from 0
		g.setFont(FONT);
		g.setColor(Color.BLACK);
		g.drawString("" + diskCount, 305, 250);
		
		//Timer bar
		g.setColor(barColor);
		g.fillRect(0, 265 , 5 * tick, 25);
	}
}
