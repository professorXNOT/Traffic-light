/*
Project 5 - Traffic Lights
Created by Xavier Wright
Date 3/28/2025


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
int flowTime = 10000;        //
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
      digitalWrite(eastGreen, LOW);  // turns off the east green traffic light

      digitalWrite(eastYellow, HIGH);  // turns on the east yellow traffic light
      delay(changeDelay);              // waits 2 seconds
      digitalWrite(eastYellow, LOW);   // turns off the east yellow traffic light
      digitalWrite(eastRed, HIGH);     // turns on the east red light
      delay(changeDelay);              // waits 2 seconds

      // this loop blinks the west yellow lighr 5 times
      for (int a = 0; a < 5; a++) {
        digitalWrite(westYellow, LOW);
        delay(yellowBlinkTime);
        digitalWrite(westYellow, HIGH);
        delay(yellowBlinkTime);
      }

      digitalWrite(westYellow, LOW);  // turns off west yellow
      digitalWrite(westRed, LOW);     // turns off west red
      digitalWrite(westGreen, HIGH);  // turns on west green
    }
  }

  if (digitalRead(eastButton) == HIGH)  // check if button is pressed
  {
    if (trafficWest == true)  // since trafficWest is initially true this code will run
    {
      trafficWest = false;  // sets trafficWest to false
      delay(flowTime);
      digitalWrite(westGreen, LOW);    // turns west green off
      digitalWrite(westYellow, HIGH);  // turns west yellow on
      delay(changeDelay);              //
      digitalWrite(westYellow, LOW)    // turns west yellow off
        digitalWrite(westRed, HIGH);   //
      delay(changeDelay);

      // blinks the east yellow light 5 times
      for (int a = 0; a < 5; a++) {
        digitalWrite(eastYellow, LOW);
        delay(yellowBlinkTime);
        digitalWrite(eastYellow, HIGH);
        delay(yellowBlinkTime);
      }

      digitalWrite(eastYellow, LOW);  // turns off east yellow
      digitalWrite(eastRed, LOW);     // turns off east red
      digitalWrite(eastGreen, HIGH);  // turns east red
    }
  }
}
