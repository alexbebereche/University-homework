package assignment5;

import java.util.Random;

public class Main {

	public static void main(String[] args) {
		
		
	
		
		
		
//5.2
		int[] software_minutes = new int[21];
		int minim = 1441;
		int maxim = -1;
		int ind_minim = 0;
		int ind_maxim = 0;
		Random r = new Random();
		
		for(int i = 0; i < 21; i++) {
			software_minutes[i] = r.nextInt(480);} //8 hours
			for(int j = 0 ; j < 21; j++) {
				
					if(software_minutes[j] < minim) {
						minim = software_minutes[j];
						ind_minim = j;}
					if(software_minutes[j] > maxim) {
						maxim = software_minutes[j];
						ind_maxim = j;
					
					
					}
			}

		
		for(int i = 0; i < 21; i++) {
			System.out.println(software_minutes[i]);} 
		System.out.println("maxim: " + maxim + " in ziua " + (ind_maxim+1));
		System.out.println("minim: " + minim + " in ziua " + (ind_minim+1));
		
		
		
		
		
	}
		

	
}
