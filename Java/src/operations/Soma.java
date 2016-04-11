package operations;

public class Soma {
	public static int[][] Normal (int[][] a, int[][] b) {
		
		int[][] c = new int[a.length][b[0].length];
		
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a[0].length; j++) {
				c[i][j]=a[i][j]+b[i][j];
			}
		}
		
		return c;
	}
}
