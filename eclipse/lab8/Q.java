
public class Q {
	int n;
	boolean valueSet = false;
	
	synchronized int get() {
		while(!valueSet) {
			try {
				wait();
			}
			catch(InterruptedException e) {
				System.out.println("InterruptedException caught");
			}
		}
		
		System.out.println("got " + n);
		valueSet = false;
		notify();
		return n;
	}
	
	synchronized void put(int n) {
		while(valueSet) {
			try {
				wait();
			}
			catch(InterruptedException e) {
				System.out.println("InterruptedException caught");
			}
		}
		
		this.n = n;
		valueSet = true;
		System.out.println("put " + n);
		notify();
	}
}
