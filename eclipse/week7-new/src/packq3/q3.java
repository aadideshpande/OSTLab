package packq3;
import java.util.Scanner;
public class q3 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		System.out.println("enter the no. of inputs");
		int no = sc.nextInt();
		Student s[] = new Student[no+1];
		
		for(int i = 1; i <= no; i++)
		{	
			System.out.println("enter name");
			String str = sc.nextLine();
			sc.nextLine();
			
			System.out.println("enter year of admission");
			int y = sc.nextInt();
			
			s[i] = new Student(str, y);
			s[i].check(i);
		}
	}
}
