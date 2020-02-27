/*
 * Lanqiao PREV-26
 * TLE with Java
 * */

import java.util.*;
import java.math.*;

public class Main{
	static int row;
	static int col;
	static int max = 500;
	static int[][] matrix;
	static int[] dp;
	static int ans;
	public static void main(String[] args){
		matrix = new int[max][max];
		ans = -9999;
		Scanner sc = new Scanner(System.in);
		row = sc.nextInt();
		col = sc.nextInt();
		for(int i=0;i<row;i++)
			for(int j=0;j<col;j++)
				matrix[i][j] = sc.nextInt();
		for(int i=0;i<row;i++){				
			dp = new int[col];
			for(int j=i;j<row;j++){
				for(int k=0;k<col;k++)
					dp[k] += matrix[j][k];
				solve(dp);
			}//for
		}//for
		System.out.println(ans);
	}
	static void solve(int[] arr){
		int temp = 0;
		for(int i=0;i<col;i++){
			temp = (temp + arr[i] < arr[i]) ? arr[i] : (temp+=arr[i]);
			ans = (temp > ans) ? temp : ans;
		}
	}
}
