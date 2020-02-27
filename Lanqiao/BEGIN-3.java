/*
 * Lanqiao BEGIN-3
 * */

import java.util.*;
import java.math.*;
import java.text.*;

public class Main{
	static double pai = 3.14159265358979323;
	static DecimalFormat df = new DecimalFormat("#.0000000");
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
			int r = Integer.parseInt(sc.next());
			double ans = r*r*pai;
			System.out.println(df.format(ans));
		}//while
	}
}
