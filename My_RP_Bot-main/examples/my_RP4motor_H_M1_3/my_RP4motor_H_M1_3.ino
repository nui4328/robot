#include <my_rp_4wd.h>
#include <Wire.h>
#include <my_TCS34725.h>  
#include <my_mpu6050.h> 
#include <EEPROM.h>
#define EEPROM_ADDR 0x50
  
unsigned long lasts_time=millis();
//------------------------->>
// กำหนดพินอินพุตตัวเข้ารหัส
const int pinA = 1;
const int pinB = 0;

const int encoderPinA = 0; 
const int encoderPinB = 1; 

// กำหนดตัวแปรเพื่อติดตามตำแหน่งและทิศทางของตัวเข้ารหัส
volatile int encoderPos = 0;
volatile int encoderPos_r = 0;
int encoderDir = 1;
int prevAVal;

volatile int encoderPoss = 0;  // Variable to store the encoder position
int encoderPinALast = LOW;  
int n = LOW;
//------------------------->>

int ch_line_r = 0;
int dis_line_r = 120;  /////////////////------->>  สไลออกมา
volatile int time_bridge = 850;
volatile int time_chopsticks = 900;
int ch_bridge;
int chopsticks;
int bg_st;
String color_ch;

int sensor_maxs[] = {803, 805, 811, 835}; 
int sensor_mins[] = {200, 218, 217, 190}; 
int red_box, green_box, blue_box, yello_box;
my_TCS34725 tcss = my_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);
void setup()
  {    
     Serial.begin(9600);
     sensor_set();              // ค่าเริ่มต้น eeprom, bit_analogRead=>12   
     setup_mpu();
     setup_encoder();
     setup_encoder_fw();
     calibration_Yak();   
     mydisplay_background(black);
     mydisplay("MY-MAKERS", 20, 30, 2, white);
     pinMode(27,INPUT_PULLUP);
     pinMode(26,INPUT_PULLUP);

     servo(22, 90);
     servo(23, 90);
     //servo(28, 20);

   
     sw_start_n();    
         //cal_censor(0, 0);sw();
         //test_line_r();
         
//\\------------------------------------------->>>>>  เขียนโค๊ดที่นี้ 

box_1();
box_2();
//box_3()
//box_4()
servo(28, 20);


/*
    Motor(50,60,50,60);delay(1300);  //--->> ทดสอบมอเตอร์
    Motor(0,0,0,0);delay(200);

    bg_st = 1;
    for(int i = 0; i<100; i++)
      {
        fw_ch_r(50, 700);
      }
  */
//\\------------------------------------------->>>>>   เขียนโค๊ดที่นี้ 
     
      
  }

void loop() 
  {  
    Serial.println(digitalRead(27));

   /*
    float red, green, blue;
     uint16_t r, g, b, c;
     tcss.getRawData(&r, &g, &b, &c);     
     float averag = (r+g+b)/3;
     red = r/averag; ;
     green = g/averag; 
     blue = b/averag;
    float color[3] = {red, green, blue};
    for(int i = 0; i<3; i++)
      {
        Serial.print(color[i]);Serial.print("  ");
      }
     Serial.println(" ");
     delay(4);
     check_color_roll_bz();
   */
   delay(10);
  }
