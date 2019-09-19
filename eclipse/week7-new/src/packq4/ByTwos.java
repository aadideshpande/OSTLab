package packq4;
import java.util.Scanner;

public class ByTwos implements Series {
	int inum;
	
	public int GetNext() {
		inum += 2;
		return inum;
	}
	
	public void setStart() {
		Scanner sc = new Scanner(System.in);
		System.out.println("enter new number");
		inum = sc.nextInt();
	}
	public void Reset() {
		System.out.println("series reset ");
	}

}
