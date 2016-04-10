package operations;

public class Multiplicacao {
	
	public static int[][] Normal (int[][] a, int[][] b) {
		
		if (a[0].length != b.length) {
			System.out.println("As matrizes não são compatíveis!");
			System.exit(1); //A ser removido
		}
		
		int[][] c = new int[a.length][b[0].length];
		int acum;
		
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
		
		if (a[0].length != b.length) {
			System.out.println("As matrizes não são compatíveis!");
			System.exit(1); //A ser removido
		}
		
		int[][] c = new int[a.length][b[0].length];
	//	int acum;
		
		
		
		return c;
	}
}
