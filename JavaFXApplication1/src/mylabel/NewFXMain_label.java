// A JavaFX label example

import javafx.application.*;
import static javafx.application.Application.launch;
import javafx.scene.*;
import javafx.stage.*;
import javafx.scene.layout.*;
import javafx.scene.control.*;

public class NewFXMain_label extends Application{
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
        myStage.setTitle("JavaFX label demo");
        
        //create a root node,
        //flowpane is a layout to place the elements in the window
        FlowPane rootNode = new FlowPane();
        
        //create a scene, 300 and 200 are the window dimensions
        Scene myScene = new Scene(rootNode,300, 200);
        
        //set the scene on the stage
        myStage.setScene(myScene);
        
        //create a label
        Label myLabel = new Label("this is a JavaFX label");
        //add label to scene graph
        rootNode.getChildren().add(myLabel);
        //                    .addAll() to add multiple children to the scene
        //it adds label to the list of children for which rootNode
        //is the parent.
        //rootNode.getChildren().remove(myLabel); to remove control from graph
        
        //show the stage
        myStage.show();
    }
    //override the stop method
    public void stop(){
        System.out.println("inside the stop() method ");
    }
    
}