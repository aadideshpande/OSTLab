
public class PC {
	public static void main(String[] args) {
		Q q = new Q();
		new Producer(q);
		new Consumer(q);
		
		System.out.println("press control C to stop");
	}
}
