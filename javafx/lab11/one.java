// A JavaFX label example

import javafx.application.*;
import static javafx.application.Application.launch;
import javafx.scene.*;
import javafx.stage.*;
import javafx.scene.layout.*;
import javafx.scene.control.*;
import javafx.event.*;
import javafx.geometry.*;

//for adding color
import javafx.scene.paint.Color;


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
        myStage.setTitle("This is the first JavaFX App.");
        
        //create a root node,
        //flowpane is a layout to place the elements in the window
        FlowPane rootNode = new FlowPane(20,20);
        rootNode.setAlignment(Pos.CENTER);
        
        //create a scene, 300 and 200 are the window dimensions
        Scene myScene = new Scene(rootNode,500, 200);
        
        //set the scene on the stage
        myStage.setScene(myScene);
        
        //create a label
        Label myLabel = new Label("Welcome to JavaFX");
        myLabel.setTextFill(Color.MAGENTA);
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