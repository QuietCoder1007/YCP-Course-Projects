package edu.ycp.cs201.mandelbrot;

public enum PixelColor {
	BLUE("05EDFF"),
	GREEN("66ff00"),
	CYAN("08e8de"),
	RED("AA0000"),
	MAGENTA("ff08e8"),
	ORANGE("ff4500"),
	LIGHT_GRAY("AAAAAA"),
	GRAY("555555"),
	LIGHT_BLUE("5555FF"),
	LIGHT_GREEN("55FF55"),
	LIGHT_CYAN("55FFFF"),
	LIGHT_RED("FF5555"),
	LIGHT_MAGENTA("FF55FF"),
	YELLOW("FFFF2E"),
	WHITE("FFFFFF");
	
	private String rgb;
	
	private PixelColor(String rgb) {
		this.rgb = rgb;
	}
	
	public int red() {
		return hexToInt(rgb.substring(0, 2));
	}
	
	public int green() {
		return hexToInt(rgb.substring(2, 4));
	}
	
	public int blue() {
		return hexToInt(rgb.substring(4, 6));
	}

	private int hexToInt(String s) {
		return Integer.parseInt(s, 16);
	}
}
