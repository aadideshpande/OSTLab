class Gen<T> {
	T ob;
	Gen(T o){
		ob = o;
	}

	T getob(){
		return ob;
	}
	void showType(){
		System.out.println("type of T is " + ob.getClass().getName());
	}
}

class practice{
	public static void main(String args[]) {
		Gen<Integer>iOb;
		iOb = new Gen<Integer>(88);
		iOb.showType();
		int v = iOb.getob();
		System.out.println("value " + v);
		System.out.println();
	}
}