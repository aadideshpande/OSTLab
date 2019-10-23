// A JavaFX buttons and labels

import javafx.application.*;
import static javafx.application.Application.launch;
import javafx.scene.*;
import javafx.stage.*;
import javafx.scene.layout.*;
import javafx.scene.control.*;
import javafx.event.*;
import javafx.geometry.*;

public class NewFXMain_button extends Application{
    Label response;
    
    public static void main(String args[]){
        
        launch(args);
    }

    //override the start() method
    // parameter myStage receives a reference to the primary stage of 
    //the app.
    public void start(Stage myStage){
        
        //give the stage a title
        myStage.setTitle("JavaFX Buttons and Events demo ");
        
        //create a root node,
        //flowpane is a layout to place the elements in the window
        //vertical and horizontal gaps of 10
        FlowPane rootNode = new FlowPane(10,10);
        
        //center the controls in the scene
        rootNode.setAlignment(Pos.CENTER);
        
        //create a scene
        Scene myScene = new Scene(rootNode,300, 100);
        
        //set the scene on the stage
        myStage.setScene(myScene);
        
        //create a label
        Label response = new Label("Push the Button");
        
        //create two push buttons
        Button btnalpha = new Button("Alpha");
        Button btnbeta = new Button("Beta");
        
        //buttons respond to the events of type ActionEvent
        //to register a handler for these events, setOnAction() methos
        //is called to the button.
        //it uses an anonymous inner class to implement EventHandler
        //interface.
        //
        
        //handle the action events for the alpha button
        btnalpha.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent ae) {
               response.setText("alpha is pressed");
            }
        });
        
         //handle the action events for the beta button
        btnbeta.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent ae) {
               response.setText("beta is pressed");
            }
        });
        
         
        //add label to scene graph
        rootNode.getChildren().addAll(btnalpha,btnbeta,response);
                
        //show the stage
        myStage.show();
    }
    //override the stop method
    public void stop(){
        System.out.println("inside the stop() method ");
    }
    
}