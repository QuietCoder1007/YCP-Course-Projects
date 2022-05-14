package edu.ycp.cs201.inheritance;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.Closeable;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class StartLab {
	private static final String FROM_PROJECT = "CS201_Lab07";
	private static final String PACKAGE = "edu.ycp.cs201.inheritance";
	
	public static void main(String[] args) {
		Scanner keyboard = new Scanner(System.in);
		
		System.out.print("Copy files from " + FROM_PROJECT + " (yes/no)? ");
		String response = keyboard.nextLine();
		if (response == null || !response.toLowerCase().equals("yes")) {
			System.out.println("OK, exiting");
			return;
		}
		
		int numErrors = 0;
		
		numErrors += copyFiles(findFilesIn("src", PACKAGE));
		numErrors += copyFiles(findFilesIn("junit", PACKAGE));
		
		if (numErrors == 0) {
			System.out.println("All files copied successfully (don't forget to refresh the project)");
		}
	}
	
	private static String[] findFilesIn(String dir, String pkg) {
		List<String> result = new ArrayList<String>();
		File d = new File("../" + FROM_PROJECT + "/" + dir + "/" + pkg.replace('.', '/'));
		File[] contents = d.listFiles();
		for (File f : contents) {
			result.add(f.getPath().substring(("../" + FROM_PROJECT + "/").length()));
		}
		return result.toArray(new String[result.size()]);
	}

	private static int copyFiles(String[] files) {
		
		int numErrors = 0;
		for (String file : files) {
			try {
				InputStream in = null;
				OutputStream out = null;
				
				try {
					in = read(file);
					out = write(file);
					copy(in, out);
					System.out.println("Copied " + file + "...");
				} finally {
					closeQuietly(in);
					closeQuietly(out);
				}
			} catch (IOException e) {
				System.err.println("Error copying " + file.substring(file.lastIndexOf('/') + 1) + ": " + e.getMessage());
				numErrors++;
			}
		}

		return numErrors;
	}

	private static InputStream read(String file) throws FileNotFoundException {
		return new BufferedInputStream(new FileInputStream("../" + FROM_PROJECT + "/" + file));
	}

	private static OutputStream write(String file) throws FileNotFoundException {
		return new BufferedOutputStream(new FileOutputStream(file));
	}

	private static void copy(InputStream in, OutputStream out) throws IOException {
		byte[] buf = new byte[4096];
		while (true) {
			int n = in.read(buf);
			if (n < 0) {
				break; // end of input file
			}
			out.write(buf, 0, n);
		}
	}

	private static void closeQuietly(Closeable obj) {
		if (obj != null) {
			try {
				obj.close();
			} catch (IOException e) {
				// ignore
			}
		}
	}
}
