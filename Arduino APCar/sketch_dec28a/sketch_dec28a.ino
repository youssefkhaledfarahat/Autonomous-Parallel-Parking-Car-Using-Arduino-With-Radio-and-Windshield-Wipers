const int IN1 = 8;
const int IN2 = 7;
const int IN3 = 5;
const int IN4 = 4;
const int ENA = 9;
const int ENB = 3;
#define SENSOR1 10
#define SENSOR2 A7
#define SENSOR3 12
#define SENSOR4 13
#define ACTION 2
#include <Arduino_FreeRTOS.h>
const int IN11 = 42;
const int IN22 = 51;
const int IN33 = 50;
const int IN44 = 44;
const int ENA1 = 52;
const int ENB1 = 45;
const int buzz = 2;


// Include the Servo library 
#include <Servo.h> 
// Declare the Servo pin and the rain sensor pins
int servoPin = 35; 
const int capteur_D = 31;
const int capteur_A = A0;
int val_analogique;
// Create a servo object 
Servo Servo1; 



//fuel sensor pins
#define sensorPower 18
#define sensorPin A2
#include "SevSeg.h"
SevSeg sevseg; 
#define sevenSegPwrPin 24



#include <Adafruit_GFX.h>        
#include <Adafruit_TFTLCD.h>  
#include <TouchScreen.h>
#include <TEA5767.h>
#include <Wire.h>
#define radioPower 41
//constants
TEA5767 Radio; //Pinout SLC and SDA - Arduino pins 20 and 21
// Variables
int val = 0;
double old_frequency;
double frequency;
int search_mode = 0;
int search_direction;
unsigned long last_pressed;
unsigned char buf[5];
int stereo;
int signal_level;
double current_freq;
unsigned long current_millis = millis();


void setup() {

 
  pinMode(radioPower, OUTPUT);
  digitalWrite(radioPower, LOW);
  Wire.begin();
  Radio.init();
  Radio.set_frequency(104.2); //On power on go to station 104.2
  //water sensor setup
  // Set D7 as an OUTPUT
  // Set to LOW so no power flows through the sensor, sevenseg code
   pinMode(sevenSegPwrPin, OUTPUT);
    digitalWrite(sevenSegPwrPin, HIGH);
    byte numDigits = 1; //we are using a single digit display
    byte digitPins[] = {}; //leave empty for a single digit display
    byte segmentPins[] = {27, 25, 23, 39, 22, 28, 26, 53}; //choose any 8 pins
    bool resistorsOnSegments = true;
    byte hardwareConfig = COMMON_ANODE; 
    sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  pinMode(sensorPower, OUTPUT);
  digitalWrite(sensorPower, LOW);
  
  //rain sensor setup
  pinMode(capteur_D, INPUT);
  pinMode(capteur_A, INPUT);
    Serial.begin(9600);
   // We need to attach the servo to the used pin number 
   Servo1.attach(servoPin); 
  Servo1.write(0);
  
  
  
  //motor power pins
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
  pinMode (ENA, OUTPUT);
  pinMode (ENB, OUTPUT);
  //back motors
  pinMode (IN11, OUTPUT);
  pinMode (IN22, OUTPUT);
  pinMode (IN33, OUTPUT);
  pinMode (IN44, OUTPUT);
  pinMode (ENA1, OUTPUT);
  pinMode (ENB1, OUTPUT);
  //buzzer
  pinMode (buzz, OUTPUT);
  digitalWrite(buzz,LOW);

  
  //IR sensors
  pinMode(SENSOR1, INPUT_PULLUP);// define pin as Input  sensor
  pinMode(SENSOR2, INPUT_PULLUP);// define pin as Input  sensor
  pinMode(SENSOR3, INPUT_PULLUP);// define pin as Input  sensor
  pinMode(SENSOR4, INPUT_PULLUP);// define pin as Input  sensor

  pinMode(ACTION, OUTPUT);// define pin as OUTPUT for ACTION

//  xTaskCreate(RadioTask, "Radio_LCD_Display",1000,NULL,1,NULL);
//  xTaskCreate(LiquidTask, "Rain_and_Fuel",1000,NULL,1,NULL);
//  xTaskCreate(AssistedParking, "Assisted_Parking_System",1000,NULL,1,NULL);

}

void loop() {

  int FrontSensor =digitalRead(SENSOR1);// read the sensor 
  int LeftSensor =digitalRead(SENSOR2);// read the sensor 
  int BackSensor =digitalRead(SENSOR3);// read the sensor 
  int RightSensor =digitalRead(SENSOR4);// read the sensor 



  if(FrontSensor == 0 && BackSensor == 0){
         //front wheels
  analogWrite(ENA, 255);
  analogWrite(ENB, 255); 
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
  
  //back wheels
  analogWrite(ENA1, 255);
  analogWrite(ENB1, 255);   
  digitalWrite(IN11, HIGH);
  digitalWrite(IN22, HIGH);
  digitalWrite(IN33, HIGH);
  digitalWrite(IN44, HIGH);
  }
  else{
    if(LeftSensor == 0){
    Serial.println("left detecting");
          //front wheels
  analogWrite(ENA, 255);
  analogWrite(ENB, 255); 
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  
  //back wheels
  analogWrite(ENA1, 255);
  analogWrite(ENB1, 255);   
  digitalWrite(IN11, LOW);
  digitalWrite(IN22, LOW);
  digitalWrite(IN33, LOW);
  digitalWrite(IN44, HIGH);
  delay(300);
   analogWrite(ENA, 255);
  analogWrite(ENB, 255); 
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  
  //back wheels
  analogWrite(ENA1, 255);
  analogWrite(ENB1, 255);   
  digitalWrite(IN11, HIGH);
  digitalWrite(IN22, LOW);
  digitalWrite(IN33, LOW);
  digitalWrite(IN44, HIGH);
  delay(300);
   analogWrite(ENA, 255);
  analogWrite(ENB, 255); 
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  
  //back wheels
  analogWrite(ENA1, 255);
  analogWrite(ENB1, 255);   
  digitalWrite(IN11, HIGH);
  digitalWrite(IN22, LOW);
  digitalWrite(IN33, LOW);
  digitalWrite(IN44, LOW);
  
  
  
  
    }
        if(FrontSensor == 0){
    Serial.println("front detecting");
  //front wheels
//  analogWrite(ENA, 255);
//  analogWrite(ENB, 255); 
//  digitalWrite(IN1, LOW);
//  digitalWrite(IN2, HIGH);
//  digitalWrite(IN3, HIGH);
//  digitalWrite(IN4, LOW);
//  
//  //back wheels
//  analogWrite(ENA1, 255);
//  analogWrite(ENB1, 255);   
//  digitalWrite(IN11, HIGH);
//  digitalWrite(IN22, LOW);
//  digitalWrite(IN33, LOW);
//  digitalWrite(IN44, HIGH);
//  delay(300);
//   analogWrite(ENA, 255);
//  analogWrite(ENB, 255); 
//  digitalWrite(IN1, LOW);
//  digitalWrite(IN2, HIGH);
//  digitalWrite(IN3, LOW);
//  digitalWrite(IN4, LOW);
//  
//  //back wheels
//  analogWrite(ENA1, 255);
//  analogWrite(ENB1, 255);   
//  digitalWrite(IN11, HIGH);
//  digitalWrite(IN22, LOW);
//  digitalWrite(IN33, LOW);
//  digitalWrite(IN44, LOW);
//  
//  
    }
  }
  

  
 
  

}
//static void AssistedParking(void* pvParameters){
//
//  while(1){
//    int FrontSensor =digitalRead(SENSOR1);// read the sensor 
//  int LeftSensor =digitalRead(SENSOR2);// read the sensor 
//  int BackSensor =digitalRead(SENSOR3);// read the sensor 
//  int RightSensor =digitalRead(SENSOR4);// read the sensor 
//
//
//
//  if(FrontSensor == 0 && BackSensor == 0){
//         //front wheels
//  analogWrite(ENA, 120);
//  analogWrite(ENB, 120); 
//  digitalWrite(IN1, HIGH);
//  digitalWrite(IN2, HIGH);
//  digitalWrite(IN3, HIGH);
//  digitalWrite(IN4, HIGH);
//  
//  //back wheels
//  analogWrite(ENA1, 120);
//  analogWrite(ENB1, 120);   
//  digitalWrite(IN11, HIGH);
//  digitalWrite(IN22, HIGH);
//  digitalWrite(IN33, HIGH);
//  digitalWrite(IN44, HIGH);
//  }
//  else{
//    if(LeftSensor == 0){
//    Serial.println("left detecting");
//          //front wheels
//  analogWrite(ENA, 150);
//  analogWrite(ENB, 150); 
//  digitalWrite(IN1, LOW);
//  digitalWrite(IN2, LOW);
//  digitalWrite(IN3, HIGH);
//  digitalWrite(IN4, LOW);
//  
//  //back wheels
//  analogWrite(ENA1, 150);
//  analogWrite(ENB1, 150);   
//  digitalWrite(IN11, LOW);
//  digitalWrite(IN22, LOW);
//  digitalWrite(IN33, LOW);
//  digitalWrite(IN44, HIGH);
//  
//  
//    }
//        if(FrontSensor == 0){
//    Serial.println("left detecting");
//          //front wheels
//  analogWrite(ENA, 150);
//  analogWrite(ENB, 150); 
//  digitalWrite(IN1, LOW);
//  digitalWrite(IN2, HIGH);
//  digitalWrite(IN3, HIGH);
//  digitalWrite(IN4, LOW);
//  
//  //back wheels
//  analogWrite(ENA1, 150);
//  analogWrite(ENB1, 150);   
//  digitalWrite(IN11, HIGH);
//  digitalWrite(IN22, LOW);
//  digitalWrite(IN33, LOW);
//  digitalWrite(IN44, HIGH);
//  delay(300);
//   analogWrite(ENA, 150);
//  analogWrite(ENB, 150); 
//  digitalWrite(IN1, LOW);
//  digitalWrite(IN2, HIGH);
//  digitalWrite(IN3, LOW);
//  digitalWrite(IN4, LOW);
//  
//  //back wheels
//  analogWrite(ENA1, 150);
//  analogWrite(ENB1, 150);   
//  digitalWrite(IN11, HIGH);
//  digitalWrite(IN22, LOW);
//  digitalWrite(IN33, LOW);
//  digitalWrite(IN44, LOW);
//  
//  
//    }
//  }
//  
//
//  
// }
//  
//  
//
//    
//  vTaskDelay(500);
//}
static void LiquidTask(void* pvParameters){
  int level = readSensor();
  if(level == 0){
    sevseg.setNumber(0, 1);  //Print 8, 0 means Decimal point is active, 1 turns it off.     
   sevseg.refreshDisplay(); //Needed to continue displaying the number 
  }
  if(level > 0 && level<750){
    sevseg.setNumber(1, 1);  //Print 8, 0 means Decimal point is active, 1 turns it off.     
   sevseg.refreshDisplay(); //Needed to continue displaying the number 
  }
  if(level >= 750){
    sevseg.setNumber(2, 1);  //Print 8, 0 means Decimal point is active, 1 turns it off.     
   sevseg.refreshDisplay(); //Needed to continue displaying the number 
  }
  Serial.print("Fuel level: ");
  Serial.println(level);
  
  vTaskDelay(1000);
//  
//  
  //rain checking and servo motor activation
  
  if(digitalRead(capteur_D) == LOW) 
  {
    Serial.println("Digital value : wet"); 
    vTaskDelay(10); 
   vTaskDelay(600); 
   // Make servo go to 120 degrees 
   Servo1.write(120);
   vTaskDelay(600);
    Servo1.write(0); 
  }
else
  {
    Serial.println("Digital value : dry");
    vTaskDelay(10); 
  }
val_analogique=analogRead(capteur_A); 
 Serial.print("Analog value : ");
 Serial.println(val_analogique); 
 Serial.println("");
  vTaskDelay(1000);
}
static void RadioTask(void* pvParameters){
  while(1){
   if (Radio.read_status(buf) == 1) {
    current_freq =  floor (Radio.frequency_available (buf) / 100000 + .5) / 10;
    stereo = Radio.stereo(buf);
    signal_level = Radio.signal_level(buf);

  }
  String dataSent = "";
  Wire.requestFrom(700,1);
  if(Wire.available()){
  while(Wire.available()){
    char c = Wire.read();
    dataSent += c;
    Serial.println(dataSent);
  }
  if(dataSent == "0"){
    digitalWrite(radioPower, LOW);
  }
  if(dataSent == "1"){
    digitalWrite(radioPower, HIGH);
  }
  if(dataSent == "2"){
    Radio.set_frequency(104.2);
  }
  if(dataSent == "3"){
    Radio.set_frequency(105.3);
  }
  if(dataSent == "4"){
    Radio.set_frequency(100.6);
  }
  
  }
  }
    vTaskDelay(100);
}


//This is a function used to get the reading on the fuel level indicator
int readSensor() {
  digitalWrite(sensorPower, HIGH);  // Turn the sensor ON
  delay(10);              // wait 10 milliseconds
  val = analogRead(sensorPin);    // Read the analog value form sensor
  digitalWrite(sensorPower, LOW);   // Turn the sensor OFF
  return val;             // send current reading
}
