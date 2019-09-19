import java.util.Scanner;

class Matadd implements Runnable{
	int arr[];
	int sum;
	Thread t = new Thread(this);	//create a thread object

	Matadd(int ar[]){
		arr = ar;
		t.start(); 
	}
	public void run(){
		for(int i = 0; i < arr.length; i++){
			sum += arr[i];
		}
	}

}

class MatrixSumMain{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		
		int m,n,msum = 0;
		System.out.println("enter dimensions");
		m = sc.nextInt();
		n = sc.nextInt();
		int mat[][] = new int[m][n];

		System.out.println("enter the matrix elements: ");
		for(int i = 0; i < mat.length; i++)
			for(int j = 0; j < mat[0].length; j++)
			{
				mat[i][j] = sc.nextInt();
			}

		Matadd m1[] = new Matadd[mat.length];
		
		//create all the child threads first
		for(int x = 0; x < mat.length; x++){
			m1[x] = new Matadd(mat[x]);
		}
		
		// now, we call the threads 
		try{
			for(int i = 0; i < mat.length; i++){
				m1[i].t.join();
			}
		}
		catch(InterruptedException e){
			System.out.println(e);
		}

		for(int i = 0; i < mat.length; i++){
			msum += m1[i].sum;
		}

		System.out.println("the final sum is : " + msum);
	}	
}