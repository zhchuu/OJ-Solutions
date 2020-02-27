/*
 * Lanqiao PREV-23
 * TLE
 * Using int or long isn't enough
 * */

import java.util.*;
import java.math.*;

public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		int T = sc.nextInt();
		int number = 1;
		int cnt = 1;
		int sum = number;
		int idx = 1;
		while(cnt < T){
			number = (number + idx)%k;
			if(idx%n == 0){
				sum += number;
				cnt++;
			}//if
			idx++;
		}//while
		System.out.println(sum);
	}
}
