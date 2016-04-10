package control;

import java.util.Random;

public class Gerador {
	public static int[][] Gera (int a, int b) {
		int [][]x = new int [a][b];
		
		Random gerador = new Random();
		
		for(int i = 0; i < a ; i++){
			for(int j = 0; j < b ; j++){
				x[i][j] = (gerador.nextInt());
			}
	    }
		
		return x;
	}
}
