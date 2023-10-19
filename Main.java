import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

class Main{
	public static boolean isFound=false;
	public static int[][] takeInput(String name){
		int[][] sudoku = new int[9][9];
		try{
			File file = new File(name);
			Scanner scan = new Scanner(file);
			int row = 0;
			while(scan.hasNextLine()){
				String line = scan.nextLine();
				String[] words = line.split(" ");
				int arr[] = new int [9];
				int count=0;
				for(String word:words){
					arr[count++]=Integer.valueOf(word); 
				}
				for(int i=0;i<9;i++) sudoku[row][i]=arr[i];
				row++;
			}
			scan.close();
		}
		catch(FileNotFoundException e){
			e.printStackTrace();
		}
		return sudoku;
	}
	public static void main(String[] args){
		int[][] sudoku= new int[9][9];
		sudoku = takeInput("sudoku.txt");
		printSudoku(sudoku);
		System.out.println("Hello Sudoku!");
		solveSudokuEff(0 ,0 ,sudoku);
	}
	
	public static void printSudoku(int [][] sudoku){
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				System.out.print(sudoku[i][j] + " ");
			}
			System.out.println("");
		}
		
	}
	public static boolean solveSudokuEff(int r,int c, int[][] sudoku){
		boolean isFilled=true;
		if(isFound) return true;
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				if(sudoku[i][j]==0) {
					isFilled=false;
					break;
				}
			}
			if(isFilled==false) break;
		}
		if(isFilled) {
			for(int i=0;i<9;i++){
				for(int j=0;j<9;j++){
					System.out.print(sudoku[i][j] + " ");
				}
				System.out.println("");
			}
			isFound=true;
			return true;
		}
		if(r>8) return false;
		if(sudoku[r][c]==0){
			for(int i=1;i<10;i++){
				if(!isCorrect(i, r, c, sudoku)) continue;
				sudoku[r][c]=i;
				if(c<8) solveSudokuEff(r ,c+1 ,sudoku);
				else solveSudokuEff(r+1 ,0 ,sudoku);
				sudoku[r][c]=0;
			}
		}
		else{
			if(c<8) solveSudokuEff(r ,c+1 ,sudoku);
			else solveSudokuEff(r+1 ,0 ,sudoku);
		}

		return isFilled;
	}


	public static boolean isCorrect(int item, int row, int column,int[][] sudoku){
		for(int i=0;i<9;i++){
			if(sudoku[i][column]==item) return false;
		}
		for(int i=0;i<9;i++){
            if(sudoku[row][i]==item) return false;
        }
		int rRow=row%3;
		int rColumn=column%3;
		int topRow=row-rRow;
		int topColumn=column-rColumn;
		for(int i=topRow;i<topRow+3; i++){
		    for(int j=topColumn;j<topColumn+3;j++){
		    	if(sudoku[i][j]==item) return false;
		    }
		}
		return true;
	}
}
