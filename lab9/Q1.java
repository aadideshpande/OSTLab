//exchange positions of any two elements in the array
import java.util.Scanner;

//a generic class with type T
class Gen<T> {
	int p1;
	int p2;
	T temp;
	Gen(int p1,int p2, T arr[]){
		this.p1 = p1;
		this.p2 = p2;
	}

	void exchange(T arr[])
	{
		temp = arr[p1];
		arr[p1] = arr[p2];
		arr[p2] = temp;
	}

	
}

class Q1{
	public static void main(String args[]) {

		Scanner sc = new Scanner(System.in);
		Integer intarr[] = {1,3,5,7,9,11,13,15};

		System.out.println("the orignal array is ");
		for(int i = 0; i < intarr.length; i++)
		{
			System.out.println(intarr[i]);
		}

		System.out.println("enter the two positions that should be replaced");
		Integer p1 = sc.nextInt();
		//sc.nextLine();
		Integer p2 = sc.nextInt();

		Gen<Integer>iob;
		iob = new Gen<Integer>(p1,p2, intarr);
		iob.exchange(intarr);

		System.out.println("the new array is ");
		for(int i = 0; i < intarr.length; i++)
		{
			System.out.println(intarr[i]);
		}

		Character chararr[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
		Gen<Character>cob;
		cob = new Gen<Character>(p1,p2,chararr);
		cob.exchange(chararr);
		for(int i = 0; i < chararr.length; i++)
		{
			System.out.println(chararr[i]);
		}
	}
}