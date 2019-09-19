package pack1;

public class ExtendThread extends Thread {
	public ExtendThread() {
		super("a new demo thread");	//super invokes the Thread constructor
		System.out.println("child thread " + this);
		start();
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


