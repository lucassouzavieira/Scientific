package control;

import operations.*;
import io.*;

public class Control {

	public static void main(String[] args) {
		
		int [][]a = Gerador.Gera(1000, 1000);
		int [][]b = Gerador.Gera(1000, 1000);
		
		long tempoInicio = System.currentTimeMillis();
		int c[][] = Multiplicacao.Normal(a, b);
		long tempo = (System.currentTimeMillis()-tempoInicio);
		System.out.println("Tempo Normal: "+tempo+" ms.");
		tempoInicio = System.currentTimeMillis();
		int d[][] = Multiplicacao.Blocos(a, b);
		tempo = (System.currentTimeMillis()-tempoInicio);
		System.out.println("Tempo Blocos: "+tempo+" ms.");
		tempoInicio = System.currentTimeMillis();
		int e[][] = Multiplicacao.Threads(a, b);
		tempo = (System.currentTimeMillis()-tempoInicio);
		System.out.println("Tempo Threads: "+tempo+" ms.");
		//IO.Imprime(c);
		//IO.Imprime(d);
		//IO.Imprime(e);
	}
}
