void pid_F(int sl, int sr, float kp, int tm,  int ofset)
  {
     lasts_time = millis();
     //while(millis() - lasts_time < tm)  
     while(encoderPos < tm)      
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
          PID_output = (kp * P) + (0.00015 * I) + (kp* D); 
          
          Motor(sl - PID_output, sr + PID_output,sl - PID_output, sr + PID_output); 
                
       }
    if(ofset > 0)
       {
          Motor(-sl,-sr,-sl,-sr);delay(ofset);
          Motor(0,0,0,0);delay(200);
       }
     else
       {
        delay(50);
       }           
  }

void pid_B(int sl, int sr, float kp, int tm,  int ofset)
  {
     lasts_time = millis();
     while(encoderPos > tm)     
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
          PID_output = (kp * P) + (0.00015 * I) + (kp* D); 
          
          Motor(-(sl + PID_output), -(sr - PID_output), -(sl + PID_output), -(sr - PID_output));
                 
       }
    if(ofset > 0)
       {
          Motor(sl,sr,sl,sr);delay(ofset);
          Motor(0,0,0,0);delay(200);
       }
     else
       {
       }           
  }
void pid_R(int sl, int sr, float kp, int tm,  int ofset)
  {
     lasts_time = millis();
     while(millis() - lasts_time < tm)        
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
          PID_output = (kp * P) + (0.00015 * I) + (kp* D); 
          
          Motor(sl-PID_output, -(sr - PID_output),-(sl + PID_output), sr + PID_output);        
       }
    if(ofset > 0)
       {
          Motor(-sl,sr,sl,-sr);delay(ofset);
          Motor(0,0,0,0);delay(200);
       }
     else
       {
       }           
  }

void pid_L(int sl, int sr, float kp, int tm,  int ofset)
  {
     lasts_time = millis();
     while(millis() - lasts_time < tm)    
     //while(1)  
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
          PID_output = (kp * P) + (0.00015 * I) + (kp* D); 
          Motor(-(sl + PID_output), sr+PID_output, sl - PID_output, -(sr - PID_output));
               
       }
    if(ofset > 0)
       {
          Motor(sl,-sr,-sl,sr);delay(ofset);
          Motor(0,0,0,0);delay(200);
       }
     else
       {
       }           
  }

void encoder_cout()
  {
    String sen_en = String (encoderPos);  
    mydisplay_background(black);
    mydisplay(sen_en, 20, 30, 2, white);
  }
void display_error()
  {
         String sen_mpu = String (error_Yaw());
         String sen_en = String (encoderPos);    
         mydisplay_background(black);
         mydisplay("mpu "+ sen_mpu, 20, 10, 2, white);
         mydisplay("en "+ sen_en, 20, 40, 2, white);
  }

void test_line_r()
  {
    encoderPos=0;
    while(encoderPos < 350)        
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
          PID_output = (5 * P) + (0.00015 * I) + (5* D); 
          
          Motor(45-PID_output, -(45 - PID_output),-(45 + PID_output), 45 + PID_output); 
          
          if(mcp_f(6)<md_mcp_f(6))
            {
              Motor(-40,40,40,-40);delay(30);
              Motor(0,0,0,0);delay(200);  
              break;           
            }
        }
     while(digitalRead(9)==1)
        {

          //Serial.println(my_tcs('r'));
 
          String sen_mpu = String (error_Yaw());
          String sen_en = String (encoderPos);    
          mydisplay_background(black);
          mydisplay("mpu "+ sen_mpu, 20, 10, 2, white);
          mydisplay("en "+ sen_en, 20, 40, 2, white);
          Serial.print(mcp_f(6));
          Serial.print("  ");
          Serial.println(md_mcp_f(6));
         
            
        } 
     bz(300);
  }
