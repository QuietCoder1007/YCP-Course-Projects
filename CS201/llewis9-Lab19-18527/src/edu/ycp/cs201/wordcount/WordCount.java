package edu.ycp.cs201.wordcount;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Iterator;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class WordCount {
	private static final Pattern wordPattern =
		Pattern.compile("[a-z]+", Pattern.CASE_INSENSITIVE);
	
	public static void main(String[] args) throws IOException {
		Scanner keyboard = new Scanner(System.in);
		
		System.out.print("Read which file? ");
		String fileName = keyboard.next();
		
		// TODO: read all of the words in the file,
		//       storing occurrence counts for each word
		//       in a map.  After the file has been
		//       fully read, print a histogram
		//       showing the frequencies of each
		//       word, in alphabetical order.

		BufferedReader reader = new BufferedReader(new FileReader(fileName));
		TreeMap<String, Integer> foo = new TreeMap<String, Integer>();
		Matcher m = null;
		// This loop reads each line of the input file
		try {
			while (true) {
				String line = reader.readLine();
				if (line == null) {
					break;
				}
				m = wordPattern.matcher(line);
				
			
			
			// This loop finds each word in the current line
			
			while (m.find()) {
				
				String word = m.group(0);
				word = word.toLowerCase();
				
				// TODO: do something with word
				if(!foo.containsKey(word)) {
					foo.put(word, 1);
				}
				else if (foo.containsKey(word)) {
					foo.put(word, foo.get(word) + 1);
				}
			}
		}
			
			int len = 0;
			
			String wordCounts = "Word counts:" ;
			System.out.println(wordCounts);
			
			len = wordCounts.length();
			
			Iterator<String> word = foo.keySet().iterator(); 
			Iterator<Integer> value = foo.values().iterator();
			
			/*while(word.hasNext()) {
				String key = word.next();
				Integer num = value.next();
				
				System.out.print(key);
				for(int i = 0; i < len - key.length(); i++) {
					System.out.print(" ");
				}
				
				System.out.print(": ");
				
				for(int i = 0; i < num; i++) {
					System.out.print("=");
				}
				System.out.println();
			}*/
			for(Map.Entry<String, Integer> entry : foo.entrySet()) {
				
				String key = entry.getKey();
				Integer num = entry.getValue();
				
				System.out.print(key);
				for(int i = 0; i < len - key.length(); i++) {
					System.out.print(" ");
				}
				
				System.out.print(": ");
				
				for(int i = 0; i < num; i++) {
					System.out.print("=");
				}
				System.out.println();
			}
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			System.err.println();
		}finally {
			keyboard.close();
			reader.close();
		}
	}
}
