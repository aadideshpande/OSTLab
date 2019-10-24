// A JavaFX skeleton

import javafx.application.*;
import javafx.scene.*;
import javafx.stage.*;
import javafx.scene.layout.*;

public class one extends Application{
    public static void main(String args[]){
        System.out.println("Launching JFX");
        
        //start the javaFX app by calling launch
        launch(args);
    }
    //override the init() method
    //init() is not used to create stage or scene of the GUI
    public void init(){
        System.out.println("inside the init() method ");
    }
    //override the start() method
    // parameter myStage receives a reference to the primary stage of 
    //the app.
    public void start(Stage myStage){
        //this is printed in the console
        System.out.println("inside the start() method ");
        
        //give the stage a title
        myStage.setTitle("JavaFX Skeleton");
        
        //create a root node,
        //flowpane is a layout to place the elements in the window
        FlowPane rootNode = new FlowPane();
        
        //create a scene, 300 and 200 are the window dimensions
        Scene myScene = new Scene(rootNode,300, 200);
        
        //set the scene on the stage
        myStage.setScene(myScene);
        
        //show the stage
        myStage.show();
    }
    //override the stop method
    public void stop(){
        System.out.println("inside the stop() method ");
    }
    
}
