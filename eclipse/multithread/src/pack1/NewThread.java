//create a new thread and get it running using RUNNABLE
package pack1;

public class NewThread implements Runnable {
	Thread t;	// t is a reference to class Thread
	
	NewThread(){
		t = new Thread(this, "Demo Thread");	//instantiating the object
		// THIS is the instance of the class that implements runnable 
		System.out.println("child thread " + t);
		t.start();	// to run the new thread.....start executes a call to run
	}
	
	public void run() {
		try {
			for(int i = 5; i > 0; i--) {
				System.out.println("child thread " + i);
				Thread.sleep(500);
			}
		}
		catch (InterruptedException e) {
			System.out.println("child interrupted ");
		}
		System.out.println("exiting child thread");
	}
}