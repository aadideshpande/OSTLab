
public class Phone {
	String Brand;
	int memCapacity;
	
	public interface Callable{
		void makeAudioCall(String cellNum);
		void makeVideoCall(String cellNum);
	}	
}

