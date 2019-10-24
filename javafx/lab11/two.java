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


public class two extends Application{

   public static void Print(String s, Label display){
        String num = " ";
        for(int i = 0; i < 11; i++){
            num += Integer.parseInt(s) * i + "\n";
            
        }
        display.setText(num);
        
   }

    public static void main(String args[]){
        System.out.println("Launching JFX");
        
        //start the javaFX app by calling launch
        launch(args);
    }
    //override the start() method
    // parameter myStage receives a reference to the primary stage of 
    //the app.
    public void start(Stage myStage){
        
        //give the stage a title
        myStage.setTitle("Multiplication");
        
        //create a root node,
        //flowpane is a layout to place the elements in the window
        FlowPane rootNode = new FlowPane(20,20);
;
        Label display1 = new Label();
        Label display = new Label();

        TextField b = new TextField();


       

        rootNode.setAlignment(Pos.CENTER);
        
        //create a scene, 300 and 200 are the window dimensions
        Scene myScene = new Scene(rootNode,500, 200);
        
        EventHandler<ActionEvent> event = new EventHandler<ActionEvent>(){
            public void handle(ActionEvent e){
               two.Print(b.getText(),display);  
                
            
            }
        };

        b.setOnAction(event);
        //set the scene on the stage
        myStage.setScene(myScene);        
        //create a label
        Label myLabel = new Label("Welcome to JavaFX");
        myLabel.setTextFill(Color.MAGENTA);
        //add label to scene graph
        rootNode.getChildren().addAll(myLabel,b,display,display1);
       
        myStage.show();
    }
}