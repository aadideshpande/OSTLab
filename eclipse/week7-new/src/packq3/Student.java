package packq3;

public class Student {
	String name;
	int year;
	
	public Student(String str,int y) {
		name = str;
		year = y;
	}
	
	void check(int i) {
		try {
			int rem = year % 100;
			int regno = rem * 100 + i;
			int limit = rem * 100 + 25;
			if(regno > limit)
			{
				throw new SeatsFilledException();
			}
		}
		catch(SeatsFilledException e) {
			System.out.println("the seats are filled now");
		}
	}	
}