class Priority implements Runnable{
	String newname;
	Thread t;

	Priority(String s){
		t = new Thread(this, s);
		newname = s;
		t.start();
	}

	public void run(){
		System.out.println(t.getName() + " is now running");	
	}
}

class PriorityMain{
	public static void main(String args[]){
		Priority p1 = new Priority("school");
		Priority p2 = new Priority("sports");
		//p1.t.setPriority(Thread.NORM_PRIORITY - 2);
		//p2.t.setPriority(Thread.NORM_PRIORITY + 2);
		System.out.println("the main thread priority is " + Thread.currentThread().getPriority());
		p1.t.setPriority(4);	// p1 is school
		p2.t.setPriority(7);	// p2 is sports
	}
}