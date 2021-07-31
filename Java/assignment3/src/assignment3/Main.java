package assignment3;

import java.util.Random;
//import java.util.*;

public class Main {

	public static void main(String[] args) {
		Random r = new Random(); 
		int contor = 0;
		float suma = 0;
		int[] v = new int[100];
		for(int i = 0; i<100;i++) {
			v[i] = r.nextInt(100);
			contor++;
			suma = suma + v[i];
		//	System.out.print(v[i] + " ");
			
			
			
		}
		
		
		//System.out.println(suma + " " + contor);
		int above = 0;
		//i know contor > 0
		float medie = suma/contor;  /*(float)*/
		int j = 0;
		while(j<100) {
			if(v[j] > medie) {
			above++;	
			}
		j++;
		}
		//System.out.println("\n" + medie);
		System.out.println("numbers above the average: " + above);
	

	}

}
