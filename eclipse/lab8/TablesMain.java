
class Mul{
	synchronized void multi(int n){
		for(int i = 0; i < 11; i++)
		{
			System.out.println(n + " * " + i + " = " + n*i);
		}

	}
}

class MulThread implements Runnable{
	Thread t;
	Mul m;
	int n;

	MulThread(Mul m1, int n1){
		t = new Thread(this);
		n = n1;
		m = m1;
		t.start();
	}

	public void run(){
			m.multi(n);

	}
}

class TablesMain{
	public static void main(String args[]){
		Mul m = new Mul();
		MulThread a = new MulThread(m,7);
		MulThread b = new MulThread(m,5);
	}
}
