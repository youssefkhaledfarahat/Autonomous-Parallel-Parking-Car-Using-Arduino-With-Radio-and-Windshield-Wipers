/*
This code is TFTLCD Library Example
*/
#include <Adafruit_GFX.h>        
#include <Adafruit_TFTLCD.h>
#include <MCUFRIEND_kbv.h>
#include <TouchScreen.h>
#include <Wire.h>
#if defined(__SAM3X8E__)
   #undef __FlashStringHelper::F(string_literal)
   #define F(string_literal) string_literal
#endif
#define YP A3  
#define XM A2  
#define YM 9   
#define XP 8   
#define TS_MINX 150
#define TS_MINY 120
#define TS_MAXX 920
#define TS_MAXY 940
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0
#define LCD_RESET A4
#define  BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);
#define BOXSIZE 40
#define PENRADIUS 3
int oldcolor, currentcolor;
void setup(void) {
  
 Serial.begin(9600);
 Wire.begin(700);
 Wire.onRequest(requestEvent);
 tft.reset();
 uint16_t identifier = tft.readID();
 if(identifier == 0x9325) {
   Serial.println(F("Found ILI9325 LCD driver"));
 } else if(identifier == 0x9328) {
   Serial.println(F("Found ILI9328 LCD driver"));
 } else if(identifier == 0x7575) {
   Serial.println(F("Found HX8347G LCD driver"));
 } else if(identifier == 0x9341) {
   Serial.println(F("Found ILI9341 LCD driver"));
 } else if(identifier == 0x8357) {
   Serial.println(F("Found HX8357D LCD driver"));
 } else {
   Serial.print(F("Unknown LCD driver chip: "));
   Serial.println(identifier, HEX);
   Serial.println(F("If using the Adafruit 2.4\" TFT Arduino shield, the line:"));
   Serial.println(F("  #define USE_ADAFRUIT_SHIELD_PINOUT"));
   Serial.println(F("should appear in the library header (Adafruit_TFT.h)."));
   Serial.println(F("If using the breakout board, it should NOT be #defined!"));
   Serial.println(F("Also if using the breakout, double-check that all wiring"));
   Serial.println(F("matches the tutorial."));
   return;
 }
 tft.begin(identifier);
 tft.fillScreen(BLACK);
 tft.drawRect(0, 0, BOXSIZE, BOXSIZE, WHITE);
 tft.drawRect(BOXSIZE*2.5, 0, BOXSIZE, BOXSIZE, WHITE);
 tft.drawRect(BOXSIZE*5, 0, BOXSIZE, BOXSIZE, WHITE);

  tft.drawRect(BOXSIZE*2.5, 250, BOXSIZE, BOXSIZE, WHITE);
 tft.setCursor(110,260);
 tft.setTextColor(WHITE); //setTextColor(uint16_t t)
tft.setTextSize(3);
tft.write("P");


 tft.setCursor(110,10);
 tft.setTextColor(WHITE); //setTextColor(uint16_t t)
tft.setTextSize(3);
tft.write("2");

 tft.setCursor(10,10);
 tft.setTextColor(WHITE); //setTextColor(uint16_t t)
tft.setTextSize(3);
tft.write("1");

 tft.setCursor(210,10);
 tft.setTextColor(WHITE); //setTextColor(uint16_t t)
tft.setTextSize(3);
tft.write("3");






 pinMode(13, OUTPUT);
}

  int state = 0;
String trial = "OFF";
String chan = "104.2";
int power = 0;
int channel = 1;
int pCHANGE = 0;
int cCHANGE = 0;
#define MINPRESSURE 10
#define MAXPRESSURE 1000
void loop()
{
  tft.setCursor(90,170);
 tft.setTextColor(WHITE); //setTextColor(uint16_t t)
tft.setTextSize(3);
//if(state = 0){
int trialL = trial.length()+1;
char charArr[trialL];
trial.toCharArray(charArr,trialL);
tft.write(charArr);

 tft.setCursor(90,140);
 tft.setTextColor(WHITE); //setTextColor(uint16_t t)
tft.setTextSize(3);
int chanL = chan.length()+1;
char charArr1[chanL];
chan.toCharArray(charArr1,chanL);
tft.write(charArr1);


 digitalWrite(13, HIGH);
 TSPoint p = ts.getPoint();
 digitalWrite(13, LOW);
 pinMode(XM, OUTPUT);
 pinMode(YP, OUTPUT);
 if (p.z > MINPRESSURE && p.z < MAXPRESSURE) {
  Serial.println("doing pressure");
   p.x = map(p.x, TS_MINX, TS_MAXX, tft.width(), 0);
   p.y = map(p.y, TS_MINY, TS_MAXY, tft.height(), 0);
   if(p.y > 250 && p.y < 290){
    if(p.x < BOXSIZE*4 && p.x > BOXSIZE*3){
      Serial.println("in play box");
       tft.fillRect(BOXSIZE*2.5, 250, BOXSIZE, BOXSIZE, WHITE);
       tft.setCursor(110,260);
       tft.setTextColor(BLACK); //setTextColor(uint16_t t)
       tft.setTextSize(3);
       tft.write("P");
          tft.setCursor(90,170);
          tft.setTextColor(BLACK); //setTextColor(uint16_t t)
          tft.setTextSize(3);
          tft.write(charArr);
      if(trial == "OFF"){
        trial = "ON";
        power = 1;

      }
      else{
        trial = "OFF";
        power = 0;
      }
      pCHANGE = 1;
             
   

    }
       tft.drawRect(BOXSIZE*2.5, 250, BOXSIZE, BOXSIZE, WHITE);
       tft.fillRect(BOXSIZE*2.5+1, 250+1, BOXSIZE-2, BOXSIZE-2, BLACK);
       tft.setCursor(110,260);
       tft.setTextColor(WHITE); //setTextColor(uint16_t t)
       tft.setTextSize(3);
       tft.write("P");
   }
   
   if (p.y < BOXSIZE) {
      if (p.x < BOXSIZE) { 
        //+ freq
        tft.fillRect(0, 0, BOXSIZE, BOXSIZE, WHITE);
  tft.setCursor(10,10);
  tft.setTextColor(BLACK); //setTextColor(uint16_t t)
  tft.setTextSize(3);
  tft.write("1");
  tft.setCursor(90,140);
  tft.setTextColor(BLACK); //setTextColor(uint16_t t)
  tft.setTextSize(3);
  tft.write(charArr1);
  chan = "104.2";
  channel = 1;
  cCHANGE = 1;

      }
      if (p.x < BOXSIZE*4 && p.x > BOXSIZE*3) {
         tft.fillRect(BOXSIZE*2.5, 0, BOXSIZE, BOXSIZE, WHITE);
         tft.setCursor(10,10);
         tft.setTextColor(BLACK); //setTextColor(uint16_t t)
         tft.setTextSize(3);
         tft.write("2");
         tft.setCursor(90,140);
         tft.setTextColor(BLACK); //setTextColor(uint16_t t)
         tft.setTextSize(3);
         tft.write(charArr1);
         chan = "100.6";
         channel = 2;
         cCHANGE = 1;

      } else if (p.x < BOXSIZE*6 && p.x > BOXSIZE*5) {
        tft.fillRect(BOXSIZE*5, 0, BOXSIZE, BOXSIZE, WHITE); 

        tft.setCursor(210,10);
        tft.setTextColor(BLACK); //setTextColor(uint16_t t)
        tft.setTextSize(3);
        tft.write("3");
        tft.setCursor(90,140);
        tft.setTextColor(BLACK); //setTextColor(uint16_t t)
        tft.setTextSize(3);
        tft.write(charArr1);
        chan = "105.3";
        channel = 3;
        cCHANGE = 1;
        } 

         tft.drawRect(0, 0, BOXSIZE, BOXSIZE, WHITE);
         tft.drawRect(BOXSIZE*2.5, 0, BOXSIZE, BOXSIZE, WHITE);
         tft.drawRect(BOXSIZE*5, 0, BOXSIZE, BOXSIZE, WHITE);

         tft.fillRect(1, 1, BOXSIZE-2, BOXSIZE-2, BLACK);
         tft.fillRect(BOXSIZE*2.5+1, 1, BOXSIZE-2, BOXSIZE-2, BLACK);
         tft.fillRect(BOXSIZE*5+1, 1, BOXSIZE-2, BOXSIZE-2, BLACK);

         tft.setCursor(110,10);
         tft.setTextColor(WHITE); //setTextColor(uint16_t t)
         tft.setTextSize(3);
         tft.write("2");
          
         tft.setCursor(10,10);
         tft.setTextColor(WHITE); //setTextColor(uint16_t t)
         tft.setTextSize(3);
         tft.write("1");
          
         tft.setCursor(210,10);
         tft.setTextColor(WHITE); //setTextColor(uint16_t t)
         tft.setTextSize(3);
         tft.write("3");



   }
 }


}

void requestEvent(){
    if(pCHANGE == 1){
      if(power == 1){
        Wire.write("1");
      }
      else{
        Wire.write("0");
      }
    }
    if(cCHANGE == 1){
      if(channel == 1){
        Wire.write("2");
      }
      else if(channel == 2){
        Wire.write("3");
      }
      else if (channel == 3){
        Wire.write("4");
      }
    }
}
