package edu.ycp.cs201.mandelbrot;

import java.awt.Color;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;
import java.util.TreeMap;

// Distribute colors based on an even distribution of iteration counts
// Colors are created using a trigonometric process for all 3 colors
//    blue from cos(0) * 255 to cos(PI/2) * 255
//    red from sin(PI/2) * 255 to sin(0) * 255
//    green from sin(0) * 255 to sin(PI) * 255
public class ExtraColorMappingColorChooser implements ColorChooser {

	// declare map references
	private TreeMap<Integer, Integer> iterCountMap;
	private HashMap<Integer, Integer> iterSpectrumMap;
	private HashMap<Integer, Color>   iterColorMap;
	
	// the max spectrum location - should always be Mandelbrot.WIDTH * Mandelbrot.HEIGHT
	//    but it is calculated in createIterSpectrumMap()
	private int maxLocation;
	final static int maxCounts = 2000;
	
	// CONSTRUCTOR: that creates the 3 maps, but doesn't populate them
	// the maps will need to be created separately
	// this allows for separate testing of the constituent map creation methods
	ExtraColorMappingColorChooser() {
		
		// create the Maps, but don't populate them
		iterCountMap    = new TreeMap<Integer, Integer>();
		iterSpectrumMap = new HashMap<Integer, Integer>();
		iterColorMap    = new HashMap<Integer, Color>();
	}	
	
	
	// CONSTRUCTOR: creates all 3 Maps and populates them
	ExtraColorMappingColorChooser(int[][] iterCounts) {
		
		// create the Maps
		iterCountMap    = new TreeMap<Integer, Integer>();
		iterSpectrumMap = new HashMap<Integer, Integer>();
		iterColorMap    = new HashMap<Integer, Color>();		
		
		// populate the Maps from iterCounts arrays
		createIterCountMap(iterCounts);
		createIterSpectrumMap();
		createIterColorMap();
	}

	
	// GET COLOR: returns the Color mapped to the iterCount in iterColorMap
	@Override
	public Color getColor(int iterCount) {
		
		// if invalid iterCount, return BLACK
		if (!iterColorMap.containsKey(iterCount)) {
			System.out.println("Invalid iterCount key: " + iterCount + ", set to BLACK");
			return Color.BLACK;
		}
		
		// otherwise return color from Color Map
		return iterColorMap.get(iterCount);
	}	

	
	// CREATE ITERCOUNT MAP: run through iterCounts array, and accumulate distribution of counts
	// for an 800 x 800 array, the # of points will be 640,000, but there can only be
	// maxCounts different iteration values
	public TreeMap<Integer, Integer> createIterCountMap(int[][] iterCounts) {
		//Iterate through the iterCounts array and map the value 
		//and the number of occurrences of that key from iterCounts
		for(int[] index : iterCounts) {
			for(Integer value : index) {
				if(iterCountMap.containsKey(value)) {
					iterCountMap.put(value, iterCountMap.get(value) + 1);
				}
				else {
					iterCountMap.put(value, 1);
				}
			}
		}
		return iterCountMap;
	}
	
	
	// CREATE ITER SPECTRUM MAP: run through iterCountMap, and determine the spectrum location (this
	// is not the actual color, but rather its relative location in the color spectrum), based on
	// an even distribution for each iteration count in the iterCountMap
	public HashMap<Integer, Integer> createIterSpectrumMap() {
		//throw new UnsupportedOperationException("TODO - implement");		
		Integer sum = 0;
		for(Map.Entry<Integer, Integer> entry : iterCountMap.entrySet()) {
			Integer key = entry.getKey();
			Integer value = entry.getValue();
			sum += value;
			
			//Map each key to a coordinate in the color plane
			iterSpectrumMap.put(key, (sum-value) + (value/2) + 1);
		}
		return iterSpectrumMap;
	}
	
	
	// CREATE ITER COLOR MAP: run through iterSpectrumMap, and create a color mapping
	// using trig functions to create a smooth transition between RGB color bands
	public HashMap<Integer, Color> createIterColorMap() {
		for(Map.Entry<Integer, Integer> entry: iterSpectrumMap.entrySet()) {
			Integer key = entry.getKey();
			Integer value = entry.getValue();
			Color color;
			
			//Calculate the relative location of the spectrum values and type cast them from ints to doubles 
			double relativeLocation = (double)value / (double)maxLocation;
		 	
			//Equations to measure the intensities of each color
			int red  = (int) (Math.sin(relativeLocation * (Math.PI/2)) * 255);
			int green  = (int) (Math.sin(relativeLocation * Math.PI) * 255);
			int blue  = (int) (Math.cos(relativeLocation * (Math.PI/2)) * 255);

			color = new Color(red, green, blue);
			
			//All invalid keys less than or equal to 0 and equal to maxCounts are mapped to black 
			if(key <= 0 || key >= maxCounts) {
				color = Color.BLACK;
			}
			iterColorMap.put(key, color);
		}
		return iterColorMap;		
	}
}
