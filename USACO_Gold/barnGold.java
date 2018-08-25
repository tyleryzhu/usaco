import java.io.*;
import java.util.*;
public class barnGold {
  static char[][] grid;
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new FileReader("barnjump.in"));
    PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("barnjump.out")));
    StringTokenizer st = new StringTokenizer(br.readLine());
    int r = Integer.parseInt(st.nextToken());
    int c = Integer.parseInt(st.nextToken());
    int colors = Integer.parseInt(st.nextToken());
    int[][] grid = new int[r][c];
    ArrayList<Integer>[] columns = new ArrayList[colors+1];
    for(int i = 1; i < columns.length; i++) {
      columns[i] = new ArrayList<Integer>();
    }
    for(int i = 0; i < r; i++) {
      st = new StringTokenizer(br.readLine());
      for(int j = 0; j < c; j++) {
        grid[i][j] = Integer.parseInt(st.nextToken());
      }
    }
    for(int j = 0; j < c; j++) {
      for(int i = 0; i < r; i++) {
        int color = grid[i][j];
        if(!columns[color].isEmpty() && columns[color].get(columns[color].size()-1) == j) continue;
        columns[color].add(j);
      }
    }
    for (int i = 1; i < columns.length; i++){
        System.out.print(i + ": ");
        for (int j = 0; j < columns[i].size(); j++) {
            System.out.print(columns[i].get(j) + " ");
        }
        System.out.println();
    }
    }
}
