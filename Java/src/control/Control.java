package control;

import operations.*; 
import io.*;

public class Control {

	public static void main(String[] args) {
	
		
		
		int [][]a = Gerador.Gera(2000, 2000);
		int [][]b = Gerador.Gera(2000, 2000);
		
		
		int c[][] = Multiplicacao.Normal(a, b);
		
		IO.Imprime(c);
	}
}
