//create a module
var app1 = angular.module('app1', []);	
//app1 is module name, [] are the dependencies

//create a controller
var mycontroller = function ($scope){
	$scope.message = "CSE Branch MIT manipal.";
};
//scope is the parameter object, message is the property


//registering the controller to the module
app1.controller("mycontroller", mycontroller);