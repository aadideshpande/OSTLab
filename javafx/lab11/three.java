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


public class three extends Application{


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
        myStage.setTitle("Login");
        
        //create a root node,
        //flowpane is a layout to place the elements in the window
        GridPane rootNode = new GridPane();
        Label display1 = new Label();
        Label display = new Label();

        TextField b1 = new TextField();
        PasswordField b2 = new PasswordField();

        Button mybutton = new Button("Submit");

        rootNode.setVgap(3); 
        rootNode.setHgap(3);
       

        rootNode.setAlignment(Pos.CENTER);
        
        //create a scene, 300 and 200 are the window dimensions
        Scene myScene = new Scene(rootNode,500, 200);
        
          mybutton.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent ae) {
               display.setText("welcome" + " " + b1.getText());
            }
        });;
        //set the scene on the stage
        myStage.setScene(myScene);        
        //create a label
        Label myLabel = new Label("Name");
        Label myLabel2 =  new Label("Password");
        //add label to scene graph
        //rootNode.getChildren().addAll(myLabel,b1,myLabel2,b2);
        rootNode.add(myLabel,1,6);
        rootNode.add(b1,3,6);
        rootNode.add(myLabel2,1,8);
        rootNode.add(b2,3,8);
        rootNode.add(mybutton,4,30);
        rootNode.add(display,3,30);
       
        myStage.show();
    }
}