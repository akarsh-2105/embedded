#include <LiquidCrystal.h> //Load Liquid Crystal Library
LiquidCrystal LCD(2,3,4,5,6,7);  //Create Liquid Crystal Object called LCD
int temppin = A0;
float temp = 0;

void setup()
{
LCD.begin(16,2); //Tell Arduino to start your 16 column 2 row LCD
Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  digitalWrite(8, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(9, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(10, HIGH);    // turn the LED off by making the voltage LOW 
}

void loop()
{
  temp = analogRead(temppin);
  temp = temp * 0.48828125;


LCD.setCursor(0,0);  //Set LCD cursor to upper left corner, column 0, row 0
LCD.print("T:");  //Print Message on First Row
LCD.setCursor(2,0);  //Set LCD cursor to upper left corner, column 0, row 0
LCD.print("    ");  //Print Message on First Row
LCD.setCursor(2,0);  //Set LCD cursor to upper left corner, column 0, row 0
LCD.print(temp);  //Print Message on First Row
if(temp>35)
{
  digitalWrite(8, HIGH);    // turn the LED off by making the voltage LOW
  digitalWrite(9, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(10, LOW);    // turn the LED off by making the voltage LOW 
}
if(temp<35)
{
digitalWrite(8, LOW);    // turn the LED off by making the voltage LOW
digitalWrite(9, LOW);    // turn the LED off by making the voltage LOW
digitalWrite(10, HIGH);    // turn the LED off by making the voltage LOW 
}
delay(1000);
   }   
