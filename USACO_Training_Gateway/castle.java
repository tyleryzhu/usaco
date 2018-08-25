/*
ID: chen.ca1
LANG: JAVA
TASK: castle
*/

import java.io.*;
import java.util.*;

public class castle {

	public static int[][] rooms; 
	public static int[][] walls; //input numbers
	public static boolean[][] marked;
	public static int w; 
	public static int l;
	public static int number = 0; //number of rooms during each floodfill
	public static int[] size = new int[2500]; //size[i] = size of room w/ count i

	public static void main(String[] args) throws FileNotFoundException, java.lang.Exception {
		BufferedReader input = new BufferedReader(new FileReader(new File("castle.in")));
		PrintStream output = new PrintStream(new File("castle.out"));
		StringTokenizer st = new StringTokenizer(input.readLine());
		w = Integer.parseInt(st.nextToken());
		l = Integer.parseInt(st.nextToken());
		rooms = new int[l][w];
		walls = new int[l][w];
		marked = new boolean[l][w];
		for (int i = 0; i < l; i++) { //read  in input
			st = new StringTokenizer(input.readLine());
			for (int j = 0; j < w; j++) {
				walls[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		int max = 0;
		int count = 0;
		for (int i = 0; i < l; i++) { //floodfill w/ numbers
			for (int j = 0; j < w; j++) {
				if (!marked[i][j]) {
					number = 0;
					dfs(i, j, count);
					size[count] = number;
					if (number > max) {
						max = number;
					}
					count++;
				}
			}
		} 

		for (int i = 0; i < l; i++) { //prints out room array r i p
			for (int j = 0; j < w; j++) {
				System.out.print(rooms[i][j]);
			}
			System.out.println();
		}
		
		output.println(count);
		output.println(max);
		output.close();
	}

	public static void dfs(int y, int x, int count) {
		boolean[] exists = new boolean[4]; //whether each wall exists
		if (x < 0 || x >= w || y < 0 || y >= l || marked[y][x]) {
			return;
		}
		rooms[y][x] = count;
		marked[y][x] = true;
		number++;
		for (int i = 0; i < 4; i++) {
			exists[i] = false;
		}
		if ((walls[y][x]&1) == 1) {
			exists[0] = true;
		}
		if ((walls[y][x]&2) == 2) {
			exists[1] = true;
		}
		if ((walls[y][x]&4) == 4) {
			exists[2] = true;
		}
		if ((walls[y][x]&8) == 8) {
			exists[3] = true;
		}	
		
		if (!exists[1]) { //go north
			dfs(y-1, x, count);
		} 
		if (!exists[3]) { //go south
			dfs(y+1, x, count);
		}
		if (!exists[0]) { //go west
			dfs(y, x-1, count);
		}
		if (!exists[2]) { //go east
			dfs(y, x+1, count);
		}	
	}
}
