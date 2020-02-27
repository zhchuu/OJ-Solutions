/*
 * Lanqiao ADV-167
 * Hint: Knapsack
 * TLE
 * */

import java.util.*;
import java.math.*;
import java.text.*;

public class Main{
	static int n;
	static int w;
	static item items[];
	static double result = 0;
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		w = sc.nextInt();
		items = new item[n];
		for(int i=0;i<n;i++){
			double gi,pi,value;
			gi = sc.nextDouble();
			pi = sc.nextDouble();
			value = pi/gi;
			items[i] = new item(gi, pi, value);
		}
		Arrays.sort(items);
		//for(item it : items)
		//	System.out.println(it);
		for(item it : items){
			//System.out.println(result);
			if(n<=0)
				break;
			if(w >= it.getGi()){
				result += it.getPi();
				w -= it.getGi();
				n--;
			}
			else{
				result += it.getValue()*w;
				n--;
				break;
			}
		}//for
		DecimalFormat df = new DecimalFormat("#.0");
		System.out.println(df.format(result));
	}

	public static class item implements Comparable<item>{
		double gi;
		double pi;
		double value;
		public item(double gi, double pi, double value){
			this.gi = gi;
			this.pi = pi;
			this.value = value;
		}
		public int compareTo(item it){
			if(it.getValue() > this.value)
				return 1;
			return -1;
		}
		public String toString(){
			return gi + " " + pi + " " + value;
		}
		public double getGi(){	return gi;}
		public double getPi(){	return pi;}
		public double getValue(){	return value;}
	}
}
