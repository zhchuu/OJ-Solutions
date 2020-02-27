/*
 * PAT L2-009
 * TLE using Java
 * */

import java.util.*;
import java.math.*;
import java.io.*;
import java.text.*;

public class Main{
	static people[] data;
	public static void main(String[] args){
		int num;
		Scanner sc = new Scanner(System.in);
		num = sc.nextInt();
		data = new people[num+1];
		for(int i=1;i<=num;i++)
			data[i] = new people(i, 0, 0);
		for(int i=1;i<=num;i++){
			int cnt = sc.nextInt();
			double giveOut = 0;
			for(int j=0;j<cnt;j++){
				int idx = sc.nextInt();
				double mon = sc.nextDouble();
				data[idx].addCount();
				data[idx].addMoney(mon);
				giveOut += mon;
			}
			data[i].addMoney(-giveOut);
		}
		Arrays.sort(data, 1, num+1);
		for(int i=1;i<=num;i++)
			System.out.println(data[i]);
	}
	public static class people implements Comparable<people>{
		int index;
		double money;
		int count;
		public people(int index, double money, int count){
			this.index = index;
			this.money = money;
			this.count = count;
		}
		public int compareTo(people p){
			if(p.getMoney() == this.money && p.getCount() == this.count)
				return this.index - p.getIndex();
			else if(p.getMoney() == this.money)
				return p.getCount() - this.count;
			else{
				if(p.getMoney() > this.money)
					return 1;
				return -1;
			}
		}

		public int getIndex(){	return index;}

		public double getMoney(){	return money;}

		public int getCount(){	return count;}

		public void addMoney(double mon){	this.money += mon;}

		public void addCount(){	this.count++;}

		public String toString(){
			DecimalFormat df = new DecimalFormat("#.00");
			return index + " " + String.format("%.2f", money/100.00);
			//return index + " " + df.format(money/100.00);
		}
	}
}
