package edu.ycp.cs201.mandelbrot;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.MultipleGradientPaint.ColorSpaceType;
import java.awt.image.BufferedImage;
import java.io.BufferedOutputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.util.Scanner;

import javax.imageio.ImageIO;

public class Mandelbrot {
	public static final int HEIGHT = 1200;

	public static final int WIDTH = 1200;
	
	//Constant for max iterations
	public static double MAX = 1000;
	
	//Function from Tic-Tac-Toe assignment that 
	//converts colors of type PixelColor to typ Color 
	public static Color colorOf(PixelColor dc) {
		return new Color(dc.red(), dc.green(), dc.blue());
	}
	
	public static void main(String[] args) {
		Scanner keyboard = new Scanner(System.in);
		
		System.out.println("Please enter coordinates of region to render:");
		System.out.print("  x1: ");
		double x1 = keyboard.nextDouble();
		System.out.print("  y1: ");
		double y1 = keyboard.nextDouble();
		System.out.print("  x2: ");
		double x2 = keyboard.nextDouble();
		System.out.print("  y2: ");
		double y2 = keyboard.nextDouble();
		
		//Appends .png to your filename
		System.out.print("Output filename: ");
		String fileName = keyboard.next() + ".png";
		
		// TODO: create the rendering, save it to a file
		int[][] iterCounts = new int[HEIGHT][WIDTH];
		
		//Array of tasks and threads to muli-thread the Mandelbrot Tasks
		MandelbrotTask task[] = new MandelbrotTask[4];
		Thread[] thread = new Thread[4];
		
		//For loop that instantiates tasks and threads with tasks
		for(int i = 0; i < task.length; i ++) {
			task[i] = new MandelbrotTask(x1, y1, x2, y2, 0, WIDTH, 0, (i+1)*HEIGHT/4, iterCounts);
			thread[i] = new Thread(task[i]);
		}
		
		//Start computing the points
		thread[0].start();
		thread[1].start();
		thread[2].start();
		thread[3].start();
		
		//Stop computing the points
		try {
			thread[0].join();
			thread[1].join();
			thread[2].join();
			thread[3].join();
			
		//If it cannot then there is an InterruptedException 
		}catch(InterruptedException e){
			System.err.println("It appears a thread was interrupted: " + e.getMessage());
		}
		
		//Creates the image instance to be drawn to
		BufferedImage bufferedImage = new BufferedImage(WIDTH, HEIGHT, BufferedImage.TYPE_INT_ARGB);
		Graphics g = bufferedImage.getGraphics();
		
		//Instance of color class to use
		PixelColor newPixelColor [] = PixelColor.values();
		
		int val = 1000/15;
		//Loop to retrieve iterCounts 2-D array values in each index
		for(int i = 0; i < HEIGHT; i++) {
			for(int j = 0; j < WIDTH; j++) {
				int a = iterCounts[i][j] % newPixelColor.length;
				
				//Iterative if statement that runs from 0 to 1000  at 15 intervals and
				//it assigns a color based on those intervals so each one has a different
				//color rather than make 15 or more if statements
				if(iterCounts[i][j] >= a*val && iterCounts[i][j] < (a+1)*val) {
					g.setColor(colorOf(newPixelColor[a]));
				}
				else {
					//coloring method for each pixel
					g.setColor(Color.BLACK);
				}
				//drawing method for each pixel
				g.drawRect(i, j, 1, 1);
			}
		}
		
		// ... use g to perform drawing operations ...
		OutputStream os = null;
			try {
				os = new BufferedOutputStream(new FileOutputStream(fileName));
				ImageIO.write(bufferedImage, "PNG", os);
			} catch(Exception e) {
				e.printStackTrace();
			} finally {
				try {
					//Try closing the BufferStream and keyboard
					os.close();
					keyboard.close();
				} catch (IOException e) {
					// Print the stack trace if there is an IOException
					e.printStackTrace();
				}
			}
		g.dispose();
	}
}
