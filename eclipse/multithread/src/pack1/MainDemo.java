//Controlling the main thread
package pack1;

public class MainDemo {
	public static void main(String[] args) {
		Thread t = Thread.currentThread();	//reference to current thread is stored in local variable 't'
		System.out.println("Current thread is " + t);
		System.out.println("nm is " + t.getName());	//print the name of the string
		//change the thread name
		t.setName("My Thread");
		System.out.println("after name change: " + t);
		
		try {
			for(int i = 5; i >= 0; i--)
			{
				System.out.println(i);
				Thread.sleep(1000);	//pause for 1000 ms or 1 second
			}
		}
		catch(InterruptedException e) {	// sleep might throw an exception if some other thread interrupts it 
			System.out.println("main thread interrupted");
		}
	}
}