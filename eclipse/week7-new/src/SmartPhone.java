import java.util.Scanner;

class SmartPhone implements Phone.Callable{
	String num2 ;
	public SmartPhone() {
		Scanner sc = new Scanner(System.in);
		System.out.println("enter your phone number");
		num2 = sc.nextLine();
	}
	
	public void makeAudioCall(String cell) {
		System.out.println(num2 + " is calling " + cell);
	}
	public void makeVideoCall(String cell) {
		System.out.println(num2 + " is video calling "+ cell);
	}
}