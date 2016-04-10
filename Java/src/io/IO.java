package io;

public class IO {
	
	public static void Imprime (int[][] a) {
		
		for(int i=0; i<a.length; i++){ 
			for(int j=0; j<a[0].length; j++) 
				System.out.print(a[i][j]+" "); 
			System.out.println(); 

		}
	}
}