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


public class four extends Application{

   public static void GCD(String s1,String s2, Label display){
        String num = " ";
        int num1 = Integer.parseInt(s1);
        int num2 = Integer.parseInt(s2);

        int max = (num1>num2)?num1:num2;
        int min = (num1>num2)?num2:num1;

        for(int i = 1; i <= min; i++){
            if(min % i == 0 && max % i == 0){
                num = Integer.toString(i);
            }
            
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
        myStage.setTitle("GCD");
        
        GridPane rootNode = new GridPane();
        Label display = new Label();

        TextField b1 = new TextField();
        TextField b2 = new TextField();

        Button mybutton = new Button("Calculate GCD");

        rootNode.setVgap(3); 
        rootNode.setHgap(3);
       

        rootNode.setAlignment(Pos.CENTER);
        
        //create a scene, 300 and 200 are the window dimensions
        Scene myScene = new Scene(rootNode,500, 200);
        
          mybutton.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent ae) {
                four.GCD(b1.getText(), b2.getText(), display);
            }
        });;
        //set the scene on the stage
        myStage.setScene(myScene);        
        //create a label
        Label myLabel = new Label("Num1");
        Label myLabel2 =  new Label("Num2");
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