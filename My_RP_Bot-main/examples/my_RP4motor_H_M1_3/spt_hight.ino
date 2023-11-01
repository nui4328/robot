void fw_ch_r(int sp, volatile int encoderPoss_fw)
  {
    //------------->>  ตรวจสอบนับการวางกล่องสี
    if(red_box == 1 && green_box == 1 && blue_box == 1 && yello_box == 1)
      {
        bz(300);bz(300);bz(300);
        servo(28, 20);
        goto end_line;        
      }
     if(bg_st == 1)
      {
        goto bridge_ch; 
      }
    //-------------->>
    //------------------>> เดินหน้าที่ละแผ่น
    while(encoderPoss < encoderPoss_fw)      
        {          
          check_color_roll();   
          errors = error_Yaw_float();
          I = 0;
          previous_I = 0;
          previous_error = 0;
          P = errors;
          I = I + previous_I;
          D = errors - previous_error ;            
          previous_I=I;
          previous_error=errors  ;  
          PID_output = (6 * P) + (0.00015 * I) +(8* D); 
          
          Motor(sp - PID_output, sp + PID_output, sp - PID_output, sp + PID_output); 

          //---------------------------------->> ตรวจสอบลิมิทสวิต ด้านหน้า
          if(digitalRead(27)==0)
            {
              Motor(0,0,0,0);delay(10);
               encoderPoss=0; 
               while(encoderPoss < 450)
                  { 
                    errors = error_Yaw_float();
                    I = 0;
                    previous_I = 0;
                    previous_error = 0;
                    P = errors;
                    I = I + previous_I;
                    D = errors - previous_error ;            
                    previous_I=I;
                    previous_error=errors  ;  
                    PID_output = (8 * P) + (0.00015 * I) +(15* D); 
                    
                    Motor(70 - PID_output, 70 + PID_output, 70 - PID_output, 70 + PID_output); 
                    if(digitalRead(26)==0)
                      {
                        chopsticks = 1;    //-------> chopsticks = 1 คือ ตะเกียบ
                      }
                  }
               Motor(0,0,0,0);delay(100);
               encoderPoss=0;               
               
               bridge(60, time_bridge);  ///---------------------->>  ขึ้นสะพานและตะเกียบ   1000 คือค่าที่วิ่งขึ้นไปกลางสะพาน หรือผ่านตะเกียบ
               
               goto bridge_ch;             
            }   
          if(mcp_f(0) < md_sensors(0)+150||mcp_f(1) < md_sensors(1)+150)  //------->> ตวจสอบเส้นด้านหน้า
            {              
               color_ch="none";
               Motor(-80,-80,-80,-80);delay(100);
               Motor(0,0,0,0);delay(300);
               check_color_roll_bz();
               if(color_ch=="yello")  //------>> ตรวจสอบสีเหลือง
                  {
                     servo_yello(); 
                     yello_box =1;
                     encoderPoss=0; 
                     ch_line_r = 0;
                     calibration_Yak();
                     bw(61, 461);
                     slide_l_online();
                     color_ch="none";
                     goto end_line;
                  }
               else if(color_ch=="red"||color_ch=="green"||color_ch=="blue")  //------>> ตรวจสอบสี
                  {                            
                     set_bl(1);
                     check_color_roll_bz();
                     if(color_ch=="red"||color_ch=="green"||color_ch=="blue")
                       {                   
                         check_color_roll_bz();
                         if(color_ch=="red")
                            {
                              servo_red(); 
                              red_box =1; 
                            }
                         else if(color_ch=="green")
                            {
                              servo_green();
                              green_box =1;  
                            }
                         else if(color_ch=="blue")
                            {
                              servo_blue();
                              blue_box =1; 
                            }
                         else if(color_ch=="yello")
                            {
                              servo_yello(); 
                              yello_box =1;
                            }
                         mydisplay_background(black);
                         mydisplay(color_ch, 20, 10, 2, white); 
                         do{Motor(-40,-40,-40,-40);}while(mcp_f(1)<md_sensors(1));
                         set_bl(1);
                       }                    
                    
                     encoderPoss=0; 
                     ch_line_r = 0;
                     calibration_Yak();
                     bw(61, 461);
                     slide_l_online();
                     color_ch="none";
                     goto end_line; 
                  }
               else
                  {                      
                     set_cop();
                     if(digitalRead(27)==0)
                        {
                           chopsticks = 1;
                           encoderPoss=0; 
                           while(encoderPoss < 550)
                              { 
                                errors = error_Yaw_float();
                                I = 0;
                                previous_I = 0;
                                previous_error = 0;
                                P = errors;
                                I = I + previous_I;
                                D = errors - previous_error ;            
                                previous_I=I;
                                previous_error=errors  ;  
                                PID_output = (5 * P) + (0.00015 * I) +(15* D); 
                                
                                Motor(50 - PID_output, 50 + PID_output, 50 - PID_output, 50 + PID_output); 
                                if(digitalRead(26)==0)
                                  {
                                    chopsticks = 1;    //-------> chopsticks = 1 คือ ตะเกียบ
                                  }
                              }
                          
                           Motor(0,0,0,0);delay(200);
                           encoderPoss=0;               
                           
                           bridge(60, 1000);  ///---------------------->>  ขึ้นสะพานและตะเกียบ   1000 คือค่าที่วิ่งขึ้นไปกลางสะพาน หรือผ่านตะเกียบ
                           
                           goto bridge_ch;                   
                        } 
                     encoderPoss=0; 
                     ch_line_r = 0;
                     calibration_Yak();
                     
                     bw(61, 150);
                     slide_l_online();
                     goto end_line;
                  }               
            }  
          
          if(color_ch=="yello")
            {
               Motor(-40,-40,-40,-40);delay(40);
               Motor(0,0,0,0);delay(30);
               check_color_roll_bz();
               do{Motor(40,40,40,40);}while(mcp_f(0)<md_sensors(0));
               set_bl(1);
               encoderPoss=0; 
               calibration_Yak(); 
               bw(61, 80);
               check_color_roll_bz();
               if(color_ch == "yello")
                  {
                    encoderPoss=0; 
                    bw(61, 200);
                    servo_yello();
                    yello_box =1;
                  }
                encoderPoss=0;
                calibration_Yak();  
                bw(61, 461);
                slide_l_online();
                color_ch="none";
                goto end_line;      
            }
         if(color_ch=="red"||color_ch=="green"||color_ch=="blue")
                  {                            
                     set_bl(1);
                     check_color_roll_bz();
                     if(color_ch=="red"||color_ch=="green"||color_ch=="blue")
                       {                   
                         check_color_roll_bz();
                         if(color_ch=="red")
                            {
                              servo_red(); 
                              red_box =1; 
                            }
                         else if(color_ch=="green")
                            {
                              servo_green();
                              green_box =1;  
                            }
                         else if(color_ch=="blue")
                            {
                              servo_blue();
                              blue_box =1; 
                            }
                         else if(color_ch=="yello")
                            {
                              servo_yello(); 
                              yello_box =1;
                            }
                         mydisplay_background(black);
                         mydisplay(color_ch, 20, 10, 2, white); 
                         do{Motor(-40,-40,-40,-40);}while(mcp_f(1)<md_sensors(1));
                         set_bl(1);
                       }                    
                    
                     encoderPoss=0; 
                     ch_line_r = 0;
                     calibration_Yak();
                     bw(61, 461);
                     slide_l_online();
                     color_ch="none";
                     goto end_line; 
                  }
                
       }
    Motor(-60,-60,-60,-60);delay(70);
    Motor(0,0,0,0);delay(300);

    bridge_ch:delay(10); //------------>> เมื่อมีการขึ้นสะพานมา
    bg_st = 0;
    
    //--------------------------------->> สไลข้างขวาพร้อมเช็ค เส้นดำ
    encoderPoss=0;
    while(encoderPoss > -455)           
        {          
          errors = error_Yaw_float();
          I = 0;
          previous_I = 0;
          previous_error = 0;
          P = errors;
          I = I + previous_I;
          D = errors - previous_error ;            
          previous_I=I;
          previous_error=errors  ;  
          PID_output = (4 * P) + (0.00015 * I) +(8* D); 
          
          Motor(70-PID_output, -(70 - PID_output),-(70 + PID_output), 70 + PID_output); 
         // Motor(61, -61,-61, 61); 
          if(mcp_f(1)<md_sensors(1) || mcp_f(3)<md_sensors(3)) //----------------->> ถ้ามีเส้นดำด้านข้าง
            {
              Motor(-80,80,80,-80);delay(100);
              if(mcp_f(1)<md_sensors(1)&& mcp_f(3)>md_sensors(3))
                {
                  do{Motor(70,20,-70,70);}while(mcp_f(3)>md_sensors(3));
                  Motor(-70,0,70,-70);delay(61);
                  Motor(0,0,0,0);delay(200);
                }
              else if(mcp_f(3)<md_sensors(3)&& mcp_f(1)>md_sensors(1))
                {
                  do{Motor(70,-70,-70,-20);}while(mcp_f(1)>md_sensors(1));
                  Motor(-70,70,70,0);delay(61);   
                  Motor(0,0,0,0);delay(200);               
                }
              else
                {                   
                   //Motor(0,0,0,0);delay(200);
                }
              ch_line_r = 1;
              //Motor(-60,60,60,-60);delay(70);
              Motor(0,0,0,0);delay(300);
               
              encoderPoss=0;
              while(encoderPoss < dis_line_r)      //----------------->> สไลออกมา 
                {                  
                  errors = error_Yaw_float();
                  I = 0;
                  previous_I = 0;
                  previous_error = 0;
                  P = errors;
                  I = I + previous_I;
                  D = errors - previous_error ;            
                  previous_I=I;
                  previous_error=errors  ;  
                  PID_output = (4 * P) + (0.00015 * I) +(10* D); 
                  
                  //Motor(-61, 61, 61, -61);
                  Motor(-(70 + PID_output), 70+PID_output, 70 - PID_output, -(70 - PID_output));
                 
               }
              Motor(61,-61,-61,61);delay(70);
              Motor(0,0,0,0);delay(300);
              break;   
            }          
       }
     if(ch_line_r == 0)  //------------------>>  ด้านข้างไม่มีเส้น
      {
        Motor(-60,60,60,-60);delay(70);
        Motor(0,0,0,0);delay(300);
        encoderPoss=0;
        while(encoderPoss < 530)          
           {                  
             errors = error_Yaw_float();
             I = 0;
             previous_I = 0;
             previous_error = 0;
             P = errors;
             I = I + previous_I;
             D = errors - previous_error ;            
             previous_I=I;
             previous_error=errors  ;  
             PID_output = (5 * P) + (0.00015 * I) +(10* D); 
                  
             Motor(-(61 + PID_output), 61+PID_output, 61 - PID_output, -(61 - PID_output));
             //Motor(-61, 61, 61, -61);    
           }
         Motor(61,-61,-61,61);delay(30);
         Motor(0,0,0,0);delay(200);

         //-------------------------------------------->>> หมุน 90 องศา
         calibration_Yak(); 
         do{Motor(61,-61,61,-61);}while(error_Yaw_float()< 87);
         Motor(-61,61,-61,61);delay(100);
         Motor(0,0,0,0);delay(200);
            
      } 

    end_line:delay(10);
    encoderPoss=0; 
    ch_line_r = 0;
    calibration_Yak();
    ch_bridge = 0;

    
  }

void set_bl(int num)
  {
    for(int i=0; i< num; i++)
      {      
        encoderPoss=0;
        do{Motor(-55,-55,-55,-55);}while(encoderPoss > -50);
        Motor(61,61,61,61);delay(61);
        while(1)
          {
            if(mcp_f(0)<md_sensors(0) && mcp_f(1)>md_sensors(1))
              {
                do{Motor(-20,50,-20,50);}while(mcp_f(1)>md_sensors(1));
                Motor(0,-70,0,-70);delay(61);
                break;
              }
            else if(mcp_f(0)> md_sensors(0) && mcp_f(1)<md_sensors(1))
              {
                do{Motor(50,-20,50,-20);}while(mcp_f(0)>md_sensors(0));
                Motor(-70,0,-70,0);delay(61);
                break;
              }
            else if(mcp_f(0)< md_sensors(0) && mcp_f(1)<md_sensors(1))
              {
                break;
              }
            else
              {
                Motor(40,40,40,40);
              }
          }
         Motor(0,0,0,0);delay(300);
      }
  }

void set_cop()
  {
    while(1)
          {
            if(mcp_f(0)<md_sensors(0) && mcp_f(1)>md_sensors(1))
              {
                do{Motor(-20,60,-20,60);}while(mcp_f(1)>md_sensors(1));
                Motor(30,-70,30,-70);delay(61);
                break;
              }
            else if(mcp_f(0)> md_sensors(0) && mcp_f(1)<md_sensors(1))
              {
                do{Motor(60,-20,60,-20);}while(mcp_f(0)>md_sensors(0));
                Motor(-70,30,-70,30);delay(61);
                break;
              }
            else if(mcp_f(0)< md_sensors(0) && mcp_f(1)<md_sensors(1))
              {
                break;
              }
            else
              {
                Motor(45,45,45,45);
              }
          }
         Motor(0,0,0,0);delay(300);
     
  }
void bw(int sp, volatile int tm)
  {
    encoderPoss=0;
    while(encoderPoss > -tm)     
        {
          errors = error_Yaw_float();
          I = 0;
          previous_I = 0;
          previous_error = 0;
          P = errors;
          I = I + previous_I;
          D = errors - previous_error ;            
          previous_I=I;
          previous_error=errors  ;  
          PID_output = (5 * P) + (0.00015 * I) +(15* D); 
          
          Motor(-(sp + PID_output), -(sp - PID_output), -(sp + PID_output), -(sp - PID_output));
                 
       }
     Motor(-sp,-sp,-sp,-sp);delay(70);
     Motor(0,0,0,0);delay(300);
  }

void slide_l_online()
  {
    for(int i=0; i<4; i++)
      {
        sensor_maxs[i] = mcp_f(i);
        delay(10);
      }
    encoderPoss=0;
    while(encoderPoss < 455)         
        {          
          errors = error_Yaw_float();
          I = 0;
          previous_I = 0;
          previous_error = 0;
          P = errors;
          I = I + previous_I;
          D = errors - previous_error ;            
          previous_I=I;
          previous_error=errors  ;  
          PID_output = (6 * P) + (0.00015 * I) +(10* D); 
          
          Motor(-(70 + PID_output), 70+PID_output, 70 - PID_output, -(70 - PID_output));
          if(mcp_f(0)<sensor_maxs[0]-100 && mcp_f(2)<sensor_maxs[2]-100)
            {
              Motor(40,-40,-40,40);delay(40);
              Motor(0,0,0,0);delay(50);
              if(mcp_f(2)<md_sensors(2))
                {
                  ch_line_r = 1;
                  Motor(60,-60,-60,60);delay(70);
                  Motor(0,0,0,0);delay(200);
    
                  encoderPoss=0;
                   while(encoderPos > -dis_line_r)          
                    {                  
                      errors = error_Yaw_float();
                      I = 0;
                      previous_I = 0;
                      previous_error = 0;
                      P = errors;
                      I = I + previous_I;
                      D = errors - previous_error ;            
                      previous_I=I;
                      previous_error=errors  ;  
                      PID_output = (5 * P) + (0.00015 * I) +(15* D); 
                      Motor(61-PID_output, -(61 - PID_output),-(61 + PID_output), 61 + PID_output);
                     
                   }
                  Motor(-61,61,61,-61);delay(30);
                  Motor(0,0,0,0);delay(300);
                  break;  
                }
              else
                {
                  break;
                }
            }          
       }
     if(ch_line_r == 0)
      {
        Motor(60,-60,-60,60);delay(70);
        Motor(0,0,0,0);delay(300);
        encoderPoss=0;
        while(encoderPoss > -435)        
           {                  
             errors = error_Yaw_float();
             I = 0;
             previous_I = 0;
             previous_error = 0;
             P = errors;
             I = I + previous_I;
             D = errors - previous_error ;            
             previous_I=I;
             previous_error=errors  ;  
             PID_output = (7 * P) + (0.00015 * I) +(15* D); 
                  
             Motor(61-PID_output, -(61 - PID_output),-(61 + PID_output), 61 + PID_output);
                 
           }
         Motor(-61,61,61,-61);delay(30);
         Motor(0,0,0,0);delay(300);

         //-------------------------------------------->>> หมุน 90 องศา
         calibration_Yak(); 
         do{Motor(-61,61,-61,61);}while(error_Yaw_float()> -85);
         Motor(61,-61,61,-61);delay(70);
         Motor(0,0,0,0);delay(300);
      }
    else
      {
         //-------------------------------------------->>> หมุน 180 องศา
         calibration_Yak(); 
         do{Motor(61,-61,61,-61);}while(error_Yaw_float()<173);
         Motor(-61,61,-61,61);delay(61);
         Motor(0,0,0,0);delay(300);
      }
  }
