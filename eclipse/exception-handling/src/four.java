// DEMONSTRATE THE throw AND rethrow features
public class four {
	
	static void demo() {
		try {
			throw new NullPointerException("demo"); //NullPointerException is an error, new is used to construct it 
		}
		catch(NullPointerException e){
			System.out.println("we are inside the catch ");
			throw e;	// e is a throwable instance, we are rethrowing the exception
		}
	}
	
	public static void main(String[] args) {
		try {
			demo();
		}
			catch(NullPointerException e) {
				System.out.println("recaught: " + e);
			}
		
	}
}
