package assignment4;

public class Matrix implements MatrInterface {
 int rows,cols;
 int[][] data;
 
 public Matrix(int rows, int cols) {
	 this.rows  = rows;
	 this.cols  = cols;
	 data = new int[rows][cols];
	 
 }
 
 public Matrix(int[][] data) {
	 cols = data.length;
	 rows = data[0].length;
	 this.data  =new int [rows][cols];
	 for (int i = 0; i < rows; i++)
         for (int j = 0; j < cols; j++)
                 this.data[i][j] = data[i][j];
 }
 
 public void show() {
		for(int i = 0; i<rows; i++) {
			for(int j = 0; j < cols; j++) {
				System.out.printf("%d ", data[i][j]);
			}
			System.out.println();
		}
	}
 
 
 
}
