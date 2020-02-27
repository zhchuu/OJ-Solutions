/*
 * Lanqiao PREV-6
 * */

import java.util.*;
import java.math.*;
import java.io.*;

public class Main{
	static int max = 1000 + 2;
	public static void main(String[] args) throws Exception{
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		String[] start = bf.readLine().split("");
		String[] end = bf.readLine().split("");
		int size = start.length;
		int data[] = new int[max];
		for(int i=0;i<size;i++){
			if(start[i].equals(end[i]))
				data[i] = 0;
			else
				data[i] = 1;
		}
		int ans = 0;
		for(int j=0;j<size-1;j++){
			if(data[j] == 1){
				data[j] = 0;
				data[j+1] = (data[j+1] == 1) ? 0:1;
				ans++;
			}
		}//for
		System.out.println(ans);
	}
}
