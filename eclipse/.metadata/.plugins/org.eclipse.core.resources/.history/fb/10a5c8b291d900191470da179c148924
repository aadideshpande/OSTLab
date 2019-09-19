import java.util.Scanner;

class BasicPhone implements Phone.Callable{
	String num1 ;
	public BasicPhone() {
		Scanner sc = new Scanner(System.in);
		System.out.println("enter your phone number");
		num1 = sc.nextLine();
	}
	
	public void makeAudioCall(String cell) {
		System.out.println(num1 + " is calling " + cell);
	}
	public void makeVideoCall(String cell) {
		System.out.println("in basic phone, video call not possible");
	}
}
