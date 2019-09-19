package packq2;
import java.util.Scanner;

public class CurrentDate {
	public int day;
	public int month;
	public int year;
	
	void createDate() {
		Scanner sc = new Scanner(System.in);
		
		System.out.println("enter day");
		day = sc.nextInt();
		System.out.println("enter month");
		month = sc.nextInt();
		System.out.println("enter year");
		year = sc.nextInt();
		int k = 0;
		
		try {
			if(day < 1 || day > 30)
			{
				k += 1;
				throw new InvalidDayException();
			}
		}
		catch (InvalidDayException e) {
			System.out.println("day should be b/w 1 and 30");
		}
		
		try {
			if(month < 1 || month > 12)
			{
				k += 1;
				throw new InvalidMonthException();
			}
		}
		catch(InvalidMonthException e){
			System.out.println("month should be b/w 1 and 12");
		}
		
		if(k == 0) {
			System.out.println("no errors " + java.time.LocalDate.now());  
		}
	}
}
