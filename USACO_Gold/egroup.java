import java.util.*;
import java.io.*;
import java.math.*;

public class egroup {
	public static int n;
	public static void main(String[] args) throws IOException, FileNotFoundException {
		//BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader input = new BufferedReader(new FileReader( new File("egroup.in")));
		StringTokenizer st = new StringTokenizer(input.readLine());
		n = Integer.parseInt(st.nextToken());
		int[] org = new int[n];
		int[] rev = new int[n];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(input.readLine());
			org[i] = Integer.parseInt(st.nextToken());
		}
		int in = solve(org); //increasing order
		for (int i = 0; i < n; i++) { //switch cow numbers
			rev[i] = org[n-i-1];
		}
		int de = solve(rev); //decreasing order
		System.out.println(Math.min(in, de));
	}

	public static int solve(int[] cows) {
		int[][] dp = new int[n][3];
		for (int i = 0; i < 3; i++) {
			dp[0][i] = 1;
		}
		dp[0][cows[0]-1] = 0;
		for (int i = 1; i < n; i++) {
			dp[i][0] = dp[i-1][0]+1;
			if (cows[i]==1) {
				dp[i][0]--;
			}
			if (cows[i]==2) {
				dp[i][1] = Math.min(dp[i-1][0], dp[i-1][1]);
			} else {
				dp[i][1] = Math.min(dp[i-1][0], dp[i-1][1]+1);
			}
			if (cows[i]==3) {
				dp[i][2] = Math.min(Math.min(dp[i-1][0], dp[i-1][1]), dp[i-1][2]);
			} else {
				dp[i][2] = Math.min(Math.min(dp[i-1][0], dp[i-1][1]), dp[i-1][2]+1);
			}
		}	
		return Math.min(Math.min(dp[n-1][0], dp[n-1][1]), dp[n-1][2]);
	}	
}