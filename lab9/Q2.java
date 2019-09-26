//generic stack class
import java.util.Scanner;

class stack<T>{
	T arr[];
	int top;
	int limit;

	stack(T arr[], int lim){
		top = -1;
		this.arr = arr;
		limit = lim;
	}

	void push(T item){
		if(top == limit )
			System.out.println("stack is full");
		else
			arr[++top] = item;
			//System.out.println("top is " + top + "and top element is " + arr[top] );

	}

	void pop(){
		if(top == -1){
			System.out.println("the stack is empty");
		}
			
		else if(top != -1){
			top--;
		}
	}
	void display(){
		int newtop = top;
		while(newtop != -1)
		{
			System.out.print(arr[newtop] + " ");
			newtop--;
		}
		System.out.println();

	}
}

class Q2{
	public static void main(String args[]) {
		stack<Integer>istack;
		Integer stackarr[] = new Integer[5];
		istack = new stack<Integer>(stackarr, 5);
		istack.push(11);
		istack.push(12);
		istack.push(13);
		istack.push(14);
		istack.push(15);
		istack.pop();
		istack.display();


		stack<Character>cstack;
		Character stackarr2[] = new Character[5];
		cstack = new stack<Character>(stackarr2, 5);
		cstack.push('a');
		cstack.push('b');
		cstack.push('c');
		cstack.push('d');
		cstack.push('e');
		cstack.pop();
		cstack.display();


		stack<String>sstack;
		String stackarr3[] = new String[5];
		sstack = new stack<String>(stackarr3, 5);
		sstack.push("sup");
		sstack.push("yo");
		sstack.push("computer");
		sstack.push("nice");
		sstack.push("data");
		sstack.pop();
		sstack.display();	
	}
}