package packq4;
import java.util.Scanner;

public class q4 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("1. Start 2. Get NExt 3.Reset 4. Exit");
		int n = 0;
		n = sc.nextInt();
		ByTwos b = new ByTwos();
		
		while(n != 4) {
			switch (n) {
			case 1:
				b.setStart();
				break;
			case 2:
				System.out.println(b.GetNext());
				break;
			case 3:
				b.Reset();
				break;
			default:
				break;
			}
			System.out.println("enter another option ");
			n = sc.nextInt();
		}
	}
}
