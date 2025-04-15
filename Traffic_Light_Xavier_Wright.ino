/*
Project 6 - Traffic Lights
Created by Xavier Wright
Date 4/15/2025
Description - This code simulates a traffic light intersection with functions to increase readabillity 


*/
// assigns the pins
#define westButton 3
#define eastButton 13
#define westRed 2
#define westYellow 1
#define westGreen 0
#define eastRed 12
#define eastYellow 11
#define eastGreen 10


#define yellowBlinkTime 500  // defines a time for the yellow led to blink

boolean trafficWest = true;  // west = true, east = false
int flowTime = 10000;
int changeDelay = 2000;

void setup() {
  // sets the input and output
  pinMode(westButton, INPUT);
  pinMode(eastButton, INPUT);
  pinMode(westRed, OUTPUT);
  pinMode(westYellow, OUTPUT);
  pinMode(westGreen, OUTPUT);
  pinMode(eastRed, OUTPUT);
  pinMode(eastYellow, OUTPUT);
  pinMode(eastGreen, OUTPUT);

  // sets the starting conditions of the lights
  digitalWrite(westRed, LOW);
  digitalWrite(westYellow, LOW);
  digitalWrite(westGreen, HIGH);
  digitalWrite(eastRed, HIGH);
  digitalWrite(eastYellow, LOW);
  digitalWrite(eastGreen, LOW);
}

void loop() {
  if (digitalRead(westButton) == HIGH)  // reads the input if the button if it is pressed runs the code below
  {
    if (trafficWest != true)  // trafficWest is initially true so this code will not run the first time around
    {
      trafficWest = true;  // sets traficWest to true
      delay(flowTime);
      changeGreenToRed(eastGreen, eastYellow, eastRed);// simulates a traffic intersection changing from green to red
      delay(changeDelay);  // waits 2 seconds

      changeYellow(westYellow);// blinks the west yellow light 5 time
  
      changeDirection(westGreen, westYellow, westRed);//simulates a traffic intersection changing direction
    }
  }

  if (digitalRead(eastButton) == HIGH)  // check if button is pressed
  {
    if (trafficWest == true)  // since trafficWest is initially true this code will run
    {
      trafficWest = false;  // sets trafficWest to false
      delay(flowTime);
      changeGreenToRed(westGreen, westYellow, westRed);// simulates a traffic intersection changing from green to red
      delay(changeDelay);
      
      changeYellow(eastYellow);// blinks the east yellow light 5 time

      changeDirection(eastGreen, eastYellow, eastRed);//simulates a traffic intersection changing direction
    }
  }
}

//
void changeGreenToRed(int Green, int Yellow, int Red) {

  digitalWrite(Green, LOW);  // turns off the green 
  digitalWrite(Yellow, HIGH);  // turns on the yellow 
  delay(changeDelay);          // waits 2 seconds

  digitalWrite(Yellow, LOW);   // turns off the yellow 
  digitalWrite(Red, HIGH);
}

void changeDirection(int green, int yellow, int red) {

  digitalWrite(yellow, LOW);  // turns off yellow
  digitalWrite(red, LOW);     // turns off red
  digitalWrite(green, HIGH);  // turns on green
}

void changeYellow(int yellowLight) {

// blinks yellow five times
  for (int a = 0; a < 5; a++) {
    digitalWrite(yellowLight, LOW);// turns off yellow
    delay(yellowBlinkTime); // waits half a second
    digitalWrite(yellowLight, HIGH); // turns on yellow
    delay(yellowBlinkTime);
  }
}