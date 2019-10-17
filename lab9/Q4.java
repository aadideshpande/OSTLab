//using wildcard arguements to compare averages
// of different object types 
import java.util.Scanner;

class Stats<T extends Number>{
	T arr[];
	Double sum;
	Double avg;
	Stats(T myarr[]){
		sum = 0.0;
		arr = myarr;

		for(int i = 0; i < myarr.length;i++){
			sum += myarr[i].doubleValue();
		}
		System.out.println("sum is " + sum);
		avg = sum / myarr.length;
	}

	void avg(){
		
	}
	boolean sameavg(Stats<?> ob){
		if(avg == ob.avg){
			return true;
		}
		else{
			return false;
		}
	}

}

class Q4{
	public static void main(String args[]){
		Double[] dnums = {1.2,3.4,5.4};
		Integer[] inums = {1,3,5,7};
		Stats<Double> dob = new Stats<Double>(dnums);
		Stats<Integer> iob = new Stats<Integer>(inums);
		
		if(iob.sameavg(dob)){
			System.out.println("same avg");
		}
		else{
			System.out.println("different avg ");
		}

	}
}
