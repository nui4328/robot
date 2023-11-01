#include <my_rp_4wd.h>
#include<Wire.h>
#include <EEPROM.h>
#define EEPROM_ADDR 0x50

unsigned long last_time = millis();
int sensor_maxs[] = {567, 601, 603, 800, 623, 633};
int sensor_mins[] = {650, 200, 109, 200, 150, 140};

bool none_set_f = false;

void setup()
  {
    Serial.begin(9600);
    sensor_set();
    mydisplay_background(black);
    mydisplay("MY-PIPER", 20, 50 ,2, white);
    
    servo(23, 90);
    
    _sw();

    //--------------------------------------------->>>>

  fw_none( 50, 50, 1000, 'l');
  set_f(3);
  tr(90, 210);
  set_b(3);
  fw( 60, 70, 300, 'l');
  //set_f(1);
  tr(90, 210);
  set_b(3);
  fw( 60, 70, 150, 'n');
  tr(90, 190);
  fw( 60, 70, 100, 'l');
  //set_f(1);
  tl( 90, 190);
  set_b(1);
  fw( 60, 70, 400, 'l');
  mission();
  set_f(1);
  bw( 60, 70, 50, 'n');
  tl( 90, 240);
  set_b(2);
  fw_none( 50, 50, 800, 'n');
  set_f(3);
  tl( 90, 210);
  Motor(-30, -30, -30, -30);
  delay(200);
  Motor(0, 0, 0, 0);
  delay(100);
  fw_none( 30, 30, 950, 'n');
  set_f(1);
  tr(90, 180);
  set_b(4);
  fw( 90, 90, 400, 'l');
  //set_f(1);
  tr(90, 190);
  set_b(2);
  fw( 60, 70, 150, 'n');
  tl(90, 240);
  set_b(2);
  fw( 60, 70, 200, 'l');
  mission();
  set_f(3);
  bw( 70, 60, 300, 'n');
  set_b(3);
  tr(90, 200);
  fw( 60, 70, 100, 'n');
  tr(90, 180);
  fw( 60, 70, 100, 'l');
  mission();
  set_f(3);
  bw( 75, 60, 500, 'l');
  set_b(3);
  tl(90, 240);
  set_b(2);
  fw( 60, 70, 200, 'n');
  set_f(2);
  bw( 50, 30, 250, 'n');
  tr(90, 190);
  set_b(3);
  fw( 60, 70, 650, 'n');
  tl(90, 210);
  fw( 60, 70, 100, 'l');
  set_f(3);
  tr(90, 190);
  set_b(3);
  fw( 90, 60, 500, 'l');
  mission();
  set_f(5);
  bw( 80, 50, 500, 'n');
  set_b(2);
  tr(90, 190);
  set_b(4);
  fw( 60, 75, 700, 'l');
  //set_f(1);
  tl(90, 210);
  set_b(4);
  fw( 60, 70, 500, 'l');
  //set_f(1);
  tl(90, 210);
  set_b(4);
  fw_none( 40, 40, 800, 'n');
  set_f(1);
  tr( 90, 210);
  //set_b(3);
  fw_none( 30, 30, 800, 'n');
  set_f(2);
  tr(90, 190);
  fw( 50, 50, 100, 'n');
  set_f(2);
  tr(90, 190);
  set_b(3);
  fw( 60, 70, 150, 'n');
  tl(90, 210);
  fw( 60, 70, 100, 'l');
  //set_f(1);
  tl(90, 200);
  set_b(3);
  fw( 60, 70, 500, 'n');
  set_f(2);
  tl(90, 240);
  set_b(4);
  
  fw_none( 50, 50, 400, 'n');
  fw( 60, 70, 500, 'l');

 ///---------------------------------------------------->>
  }
void loop()
  {
    Serial.println(md_sensors(3));
  }
