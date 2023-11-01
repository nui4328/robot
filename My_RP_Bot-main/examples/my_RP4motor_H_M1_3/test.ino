//servo_green(); servo_red(); servo_yello(); servo_blue();  servo(28, 20);
void box_1()
  { 
    Motor(50,60,50,60);delay(1300);  //--->> ทดสอบมอเตอร์Motor(0,0,0,0);delay(200);
    fw_encoder(70, 70, 0, 'r');
    fw_encoder(70, 70, 0, 'r');
    
    fw_encoder(70, 70, 0, 'r');
    
    fw_encoder(70, 70, 0, 'l');
    fw_encoder(70, 70, 0, 's');
    
    servo_red();
  }


void box_2()
  {
    bw_encoder(70, 70, 140, 'l');
    fw_encoder(70, 72, 0, 'r');
    fw_encoder(70, 70, 0, 'r');
    fw_encoder(70, 70, 0, 's'); 
    
    servo_green();
  }

void ch_point_1()
  {
    fw_encoder(70, 70, 0, 's');    

  }
void ch_point_2()
  {
    fw_encoder(70, 70, 0, 's');

  }
