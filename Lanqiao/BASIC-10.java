/*
 * Lanqiao BASIC-10
 * */

import java.util.*;
import java.math.*;

public class Main{
	static int N;
	static List<Integer> store;
	static Map<Integer, Character> map;

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		store = new ArrayList<>();
		map = new HashMap<Integer, Character>();
		init();
		cal();
		Collections.reverse(store);
		StringBuilder builder = new StringBuilder();
		for(int i : store)
			builder.append(map.get(i));
		String result = builder.toString();
		System.out.println(result);
	}

	protected static void cal(){
		if(N == 0)
			store.add(0);
		while(N != 0){
			store.add(N%16);
			N /= 16;	
		}
	}

	protected static void init(){
		map.put(0, '0');
		map.put(1, '1');
		map.put(2, '2');
		map.put(3, '3');
		map.put(4, '4');
		map.put(5, '5');
		map.put(6, '6');
		map.put(7, '7');
		map.put(8, '8');
		map.put(9, '9');
		map.put(10, 'A');
		map.put(11, 'B');
		map.put(12, 'C');
		map.put(13, 'D');
		map.put(14, 'E');
		map.put(15, 'F');
	}
}
