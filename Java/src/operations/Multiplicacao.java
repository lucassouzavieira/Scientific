package operations;

public class Multiplicacao extends Thread {
	
	public static int[][] Normal (int[][] a, int[][] b) {
		
		int[][] c = new int[a.length][b[0].length];
		int acum;
		//Algoritmo padrão de multiplicação de Matrizes
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < b[0].length; j++) {
				acum = 0;
				for (int k = 0; k < a[0].length; k++) {
					acum += a[i][k]*b[k][j];
				}
				c[i][j]=acum;
			}
		}
		
		return c;
	}
	
	public static int[][] Blocos (int[][] a, int[][] b) {
		
		//Variáveis que receberão as matrizes particionadas
		int[][] bloco11a = new int [a.length/2][b[0].length/2];
		int[][] bloco12a = new int [a.length/2][b[0].length/2];
		int[][] bloco21a = new int [a.length/2][b[0].length/2];
		int[][] bloco22a = new int [a.length/2][b[0].length/2];
		
		int[][] bloco11b = new int [a.length/2][b[0].length/2];
		int[][] bloco12b = new int [a.length/2][b[0].length/2];
		int[][] bloco21b = new int [a.length/2][b[0].length/2];
		int[][] bloco22b = new int [a.length/2][b[0].length/2];
		
		//Criando os blocos de resultado
		int[][] bloco11c = new int [a.length/2][b[0].length/2];
		int[][] bloco12c = new int [a.length/2][b[0].length/2];
		int[][] bloco21c = new int [a.length/2][b[0].length/2];
		int[][] bloco22c = new int [a.length/2][b[0].length/2];
		
		//Resultado final, com os blocos concatenados
		int[][] c = new int [a.length][b[0].length];
		
		//Particionando as Matrizes
		for (int i = 0; i < a.length/2; i++) {
			for (int j = 0; j < b[0].length/2; j++ ) {
				bloco11a[i][j] = a[i][j];
				bloco12a[i][j] = a[i][j+b[0].length/2];
				bloco21a[i][j] = a[i+a.length/2][j];
				bloco22a[i][j] = a[i+a.length/2][j+b[0].length/2];
				
				bloco11b[i][j] = b[i][j];
				bloco12b[i][j] = b[i][j+b[0].length/2];
				bloco21b[i][j] = b[i+a.length/2][j];
				bloco22b[i][j] = b[i+a.length/2][j+b.length/2];
			}
		}
		
		//Multiplicação dos Blocos
		bloco11c = Soma.Normal(Normal(bloco11a, bloco11b),Normal(bloco12a,bloco21b));
		bloco12c = Soma.Normal(Normal(bloco11a, bloco12b),Normal(bloco12a,bloco22b));
		bloco21c = Soma.Normal(Normal(bloco21a, bloco11b),Normal(bloco22a,bloco21b));
		bloco22c = Soma.Normal(Normal(bloco21a, bloco12b),Normal(bloco22a,bloco22b));
		
		//Juntando os resultados
		for (int i = 0; i < a.length/2; i++) {
			for (int j = 0; j < b[0].length/2; j++ ) {
			c[i][j] = bloco11c[i][j];
			c[i][j+b[0].length/2] = bloco12c[i][j];
			c[i+a.length/2][j] = bloco21c[i][j];
			c[i+a.length/2][j+b[0].length/2]=bloco22c[i][j];
			}
		}
		
		return c;
		
	}

	
	public static int[][] Threads (int[][] a, int[][] b) {
		
		int[][] bloco11a = new int [a.length/2][b[0].length/2];
		int[][] bloco12a = new int [a.length/2][b[0].length/2];
		int[][] bloco21a = new int [a.length/2][b[0].length/2];
		int[][] bloco22a = new int [a.length/2][b[0].length/2];
		
		int[][] bloco11b = new int [a.length/2][b[0].length/2];
		int[][] bloco12b = new int [a.length/2][b[0].length/2];
		int[][] bloco21b = new int [a.length/2][b[0].length/2];
		int[][] bloco22b = new int [a.length/2][b[0].length/2];
		
		int[][] bloco11c = new int [a.length/2][b[0].length/2];
		int[][] bloco12c = new int [a.length/2][b[0].length/2];
		int[][] bloco21c = new int [a.length/2][b[0].length/2];
		int[][] bloco22c = new int [a.length/2][b[0].length/2];
		
		int[][] c = new int [a.length][b[0].length];
		
		for (int i = 0; i < a.length/2; i++) {
			for (int j = 0; j < b[0].length/2; j++ ) {
				bloco11a[i][j] = a[i][j];
				bloco12a[i][j] = a[i][j+b[0].length/2];
				bloco21a[i][j] = a[i+a.length/2][j];
				bloco22a[i][j] = a[i+a.length/2][j+b[0].length/2];
				
				bloco11b[i][j] = b[i][j];
				bloco12b[i][j] = b[i][j+b[0].length/2];
				bloco21b[i][j] = b[i+a.length/2][j];
				bloco22b[i][j] = b[i+a.length/2][j+b.length/2];
			}
		}
		
		
		Multiplicacao thread1 = new Multiplicacao();
		Multiplicacao thread2 = new Multiplicacao();
		Multiplicacao thread3 = new Multiplicacao();
		Multiplicacao thread4 = new Multiplicacao();
		Multiplicacao thread5 = new Multiplicacao();
		Multiplicacao thread6 = new Multiplicacao();
		Multiplicacao thread7 = new Multiplicacao();
		Multiplicacao thread8 = new Multiplicacao();
		
		Thread mult1 = new Thread(thread1);
		Thread mult2 = new Thread(thread2);
		Thread mult3 = new Thread(thread3); 
		Thread mult4 = new Thread(thread4);
		Thread mult5 = new Thread(thread5);
		Thread mult6 = new Thread(thread6);
		Thread mult7 = new Thread(thread7);
		Thread mult8 = new Thread(thread8);
		
		mult1.start();
		mult2.start();
		mult3.start();
		mult4.start();
		mult5.start();
		mult6.start();
		mult7.start();
		mult8.start();
		
		int[][] bloco111c = thread1.run(bloco11a, bloco11b);
		int[][] bloco112c = thread2.run(bloco12a, bloco21b);
		int[][] bloco121c = thread3.run(bloco11a, bloco12b);
		int[][] bloco122c = thread4.run(bloco12a, bloco22b);
		int[][] bloco211c = thread5.run(bloco21a, bloco11b);
		int[][] bloco212c = thread6.run(bloco22a,bloco21b);
		int[][] bloco221c = thread7.run(bloco21a, bloco12b);
		int[][] bloco222c = thread8.run(bloco22a,bloco22b);
		
		bloco11c = Soma.Normal(bloco111c, bloco112c);
		bloco12c = Soma.Normal(bloco121c, bloco122c);
		bloco21c = Soma.Normal(bloco211c, bloco212c);
		bloco22c = Soma.Normal(bloco221c, bloco222c);
		
		for (int i = 0; i < a.length/2; i++) {
			for (int j = 0; j < b[0].length/2; j++ ) {
			c[i][j] = bloco11c[i][j];
			c[i][j+b[0].length/2] = bloco12c[i][j];
			c[i+a.length/2][j] = bloco21c[i][j];
			c[i+a.length/2][j+b[0].length/2]=bloco22c[i][j];
			}
		}
		
		return c;
		
	}
	
	public int[][] run(int[][] a, int[][] b) {
		//Este método é padrão da classe Thread, apenas reescrevendo
		int[][] c = new int[a.length][b[0].length];
		int acum;
	
		//Algoritmo padrão de multiplicação de Matrizes
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < b[0].length; j++) {
				acum = 0;
				for (int k = 0; k < a[0].length; k++) {
					acum += a[i][k]*b[k][j];
				}
			c[i][j]=acum;
			}
		}
	
		return c;
	}

}
