/*
 * Lanqiao BASIC-13
 * */

import java.util.*;
import java.math.*;

public class Main{
	static List<Integer> arr = new ArrayList<>();
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
			arr.clear();
			int num = sc.nextInt();
			while(num>0){
				arr.add(sc.nextInt());
				num = num - 1;
			}//while
			Collections.sort(arr);
			System.out.print(arr.get(0));
			int size = arr.size();
			for(int n = 1;n<size;n++){
				System.out.print(" " + arr.get(n));
			}
			System.out.print("\n");
		}//while
	}
}
