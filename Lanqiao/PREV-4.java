/*
 * Lanqiao PREV-4
 * Hint: dfs
 * */

import java.util.*;
import java.math.*;

public class Main{
	static int INF = 1000000;
	static int max = 10 + 1;
	static int sum;
	static int table[][];
	static int width;
	static int height;
	static int ans;
	static int visi[][];
	static int move[][] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
			width = sc.nextInt();
			height = sc.nextInt();
			table = new int[max][max];
			visi = new int[max][max];
			sum = 0;
			ans = INF;
			for(int n = 1;n<=height;n++)
				for(int m = 1;m<=width;m++){
					table[n][m] = sc.nextInt();
					sum += table[n][m];
				}
			if(sum%2==1)
				System.out.println("0");
			else{
				sum /= 2;
				visi[1][1] = 1;
				dfs(1, 1, table[1][1], 1);
				if(ans == INF)
					System.out.println("searched"+"0");
				else
					System.out.println(ans);
			}
		}//while
	}//main
	private static void dfs(int x, int y, int s, int t){//s -- sum, t -- times
		if(s == sum){
			ans = (ans <= t) ? ans:t;
			return;
		}
		if(s > sum || t > ans)
			return;
		for(int i=0;i<4;i++){
			int nextx = x + move[i][0];
			int nexty = y + move[i][1];
			if(nextx >= 1 && nextx <= height && nexty>=1 && nexty <= width && visi[nextx][nexty]!=1){
				visi[nextx][nexty] = 1;
				dfs(nextx, nexty, s+table[nextx][nexty], t+1);
				visi[nextx][nexty] = 0;
			}
		}//for
	}
}
