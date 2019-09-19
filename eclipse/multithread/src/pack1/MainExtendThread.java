package pack1;

public class MainExtendThread {
	public static void main(String[] args) {
		new ExtendThread();
		
		try {
			for(int i = 5; i > 0; i--) {
				System.out.println("main thread " + i);
				Thread.sleep(1000);
			}
		}
		catch(InterruptedException e) {
			System.out.println("main thread interrupted ");
		}
		System.out.println("main thread exiting ");
	}
}
