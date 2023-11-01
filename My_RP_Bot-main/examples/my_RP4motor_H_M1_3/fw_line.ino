void fw_encoder(int spl, int spr, volatile int pw,  char slr)
  {    
    calibration_Yak(); 
    encoderPoss=0;
    if(pw > 0)
      {
        while(encoderPoss < pw)      
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
            PID_output = (6 * P) + (0.00015 * I) +(8* D); 
            
            Motor(spl - PID_output, spr + PID_output, spl - PID_output, spr + PID_output); 
            if(mcp_f(0)<md_sensors(0)-150||mcp_f(1)<md_sensors(1)-150)
                {
                   Motor(-80,-80,-80,-80);delay(100);
                   Motor(0,0,0,0);delay(300);
                   
                   break;
                }             
           }
      }
     else
      {
        while(1)      
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
            PID_output = (6 * P) + (0.00015 * I) +(8* D); 
            
            Motor(spl - PID_output, spr + PID_output, spl - PID_output, spr + PID_output); 
            if(mcp_f(0)<md_sensors(0)-150||mcp_f(1)<md_sensors(1)-150)
                {
                   Motor(-80,-80,-80,-80);delay(100);
                   Motor(0,0,0,0);delay(300);
                   set_bl(3);
                   break;
                }             
           }
      }
    
      if(slr == 'r')
         {
            Motor(-61,-61,-61,-61);delay(400);
            Motor(0,0,0,0);delay(200);
             calibration_Yak(); 
             do{Motor(61,-61,61,-61);}while(error_Yaw_float()< 87);
             Motor(-61,61,-61,61);delay(100);
             Motor(0,0,0,0);delay(200);
         }
      else if(slr == 'l')
         {
             Motor(-61,-61,-61,-61);delay(400);
            Motor(0,0,0,0);delay(200);
             calibration_Yak(); 
             do{Motor(-61,61,-61,61);}while(error_Yaw_float()> -87);
             Motor(61,-61,61,-61);delay(100);
             Motor(0,0,0,0);delay(200);
         }
       else if(slr == 's')
         {
             Motor(-61,-61,-61,-61);delay(20);
             Motor(0,0,0,0);delay(200);
         }
  }

void bw_encoder(int spl, int spr, volatile int pw,  char slr)
  {    
    calibration_Yak(); 
    encoderPoss=0;
    if(pw > 0)
      {
        while(encoderPoss > -pw)      
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
            PID_output = (6 * P) + (0.00015 * I) +(8* D); 
            
            Motor(-(spl - PID_output), -(spr + PID_output), -(spl - PID_output), -(spr + PID_output)); 
            if(mcp_f(2)<md_sensors(0)-150||mcp_f(3)<md_sensors(1)-150)
                {
                   Motor(80,80,80,80);delay(100);
                   Motor(0,0,0,0);delay(300);
                   
                   break;
                }             
           }
      }
     else
      {
        while(1)      
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
            PID_output = (6 * P) + (0.00015 * I) +(8* D); 
            
             Motor(-(spl - PID_output), -(spr + PID_output), -(spl - PID_output), -(spr + PID_output)); 
            if(mcp_f(2)<md_sensors(0)-150||mcp_f(3)<md_sensors(1)-150)
                {
                   Motor(80,80,80,80);delay(100);
                   Motor(0,0,0,0);delay(300);
                   
                   break;
                }             
           }
      }
    
      if(slr == 'r')
         {
            Motor(-61,-61,-61,-61);delay(400);
            Motor(0,0,0,0);delay(200);
             calibration_Yak(); 
             do{Motor(61,-61,61,-61);}while(error_Yaw_float()< 87);
             Motor(-61,61,-61,61);delay(100);
             Motor(0,0,0,0);delay(200);
         }
      else if(slr == 'l')
         {
             Motor(-61,-61,-61,-61);delay(400);
            Motor(0,0,0,0);delay(200);
             calibration_Yak(); 
             do{Motor(-61,61,-61,61);}while(error_Yaw_float()> -87);
             Motor(61,-61,61,-61);delay(100);
             Motor(0,0,0,0);delay(200);
         }
       else if(slr == 's')
         {
             Motor(-61,-61,-61,-61);delay(20);
             Motor(0,0,0,0);delay(200);
         }
  }
