
void fw(int spl, int spr, int _time, char offset)
  {
    last_time = millis();
    while(millis()-last_time < _time)
      {
        if(mcp_f(0) < md_mcp_f(0)-50 && mcp_f(3) > md_mcp_f(3))
              {
                Motor(spl, spr/3, spl, spr/3);
              }
        else if(mcp_f(0) > md_mcp_f(0) && mcp_f(3) < md_mcp_f(3)-50)
              {
                Motor(spl/3, spr, spl/3, spr);
              }
        else if(mcp_f(1) < md_mcp_f(1)-50 && mcp_f(2) < md_mcp_f(2))
              {
                Motor(-20, -20, -20, -20);
                delay(30);
                goto end_time;
              }
        else 
              {
                Motor(spl, spr, spl, spr);
              }
      }
      
    for(int i = spl; i > 10; i -= 1)
      {
        if(mcp_f(0) < md_mcp_f(0)-50 && mcp_f(3) > md_mcp_f(3))
              {
                Motor(spl, spr/3, spl, spr/3);
              }
        else if(mcp_f(0) > md_mcp_f(0) && mcp_f(3) < md_mcp_f(3)-50)
              {
                Motor(spl/3, spr, spl/3, spr);
              }
        else if(mcp_f(1) < md_mcp_f(1)-50 && mcp_f(2) < md_mcp_f(2))
              {
                Motor(-30, -30, -30, -30); delay(50);
                break;
              }
        else 
              {
                Motor(i, i, i, i);
              }
        delay(5);
      }

    

    if(offset == 'l')
      {
        while(1)
          {
            if(mcp_f(0) < md_mcp_f(0)-50 && mcp_f(3) > md_mcp_f(3))
              {
                Motor(spl, spr/3, spl, spr/3);
              }
        else if(mcp_f(0) > md_mcp_f(0) && mcp_f(3) < md_mcp_f(3)-50)
              {
                Motor(spl/3, spr, spl/3, spr);
              }
        else if(mcp_f(1) < md_mcp_f(1)-50 && mcp_f(2) > md_mcp_f(2)) 
              {
                Motor(-50, -50, -50, -50);
                delay(50);
                do{Motor(-10, 40, -10, 40);}while(mcp_f(2) > md_mcp_f(2));
                Motor(0, -50, 0, -50);
                delay(30);
                break;
              }
        else if(mcp_f(1) > md_mcp_f(1) && mcp_f(2) < md_mcp_f(2)-50)
              {
                Motor(-50, -50, -50, -50);
                delay(50);
                do{Motor(40, -10, 40, -10);}while(mcp_f(1) > md_mcp_f(1));
                Motor(-50, 0, -50, 0);
                delay(30);
                break;
              }
        else if(mcp_f(1) < md_mcp_f(1)-50 && mcp_f(2) < md_mcp_f(2))
              {
                Motor(-30, -30, -30, -30); delay(50);
                break;
              }
        else 
              {
                Motor(20, 20, 20, 20);
              }
          }
       
      }
 
    else{}
    end_time:
    delay(10);
    Motor(0, 0, 0, 0);
    delay(100);
     if(offset == 'l')
      {
        none_set_f = false;
      }
     else
      {
        none_set_f = true;
      }
    
  }

void bw(int spl, int spr, int _time, char offset)
  {
    last_time = millis();
    while(millis()-last_time < _time)
      {
        if(mcp_f(0) < md_mcp_f(0)-50 && mcp_f(3) > md_mcp_f(3))
              {
                Motor(-spl, -(spr/5), -spl, -(spr/5));
                delay(20);
              }
        else if(mcp_f(0) > md_mcp_f(0) && mcp_f(3) < md_mcp_f(3)-50)
              {
                Motor(-(spl/5), -spr, -(spl/5), -spr);
                delay(20);
              }
        else if(mcp_f(4) < md_mcp_f(4)-50 && mcp_f(5) < md_mcp_f(5)-50)
              {
                break;
              }
        else 
              {
                Motor(-spl, -spr, -spl, -spr);
              }
      }
    for(int i = spl; i > 10; i -= 1)
      {
        Motor( -i, -i, -i, -i);
        if(mcp_f(4) < md_mcp_f(4)-50 && mcp_f(5) < md_mcp_f(5)-50)
          {
            Motor(40, 40, 40, 40); delay(40);
            break;
          }
        delay(5);
      }
    if(offset == 'l')
      {
        while(1)
          {
            
            if(mcp_f(4) < md_mcp_f(4)-50 && mcp_f(5) < md_mcp_f(5)-50)
              {
                Motor(40, 40, 40, 40);
                delay(30);
                break;
              }
           else if(mcp_f(0) < md_mcp_f(0)-50 && mcp_f(3) > md_mcp_f(3))
              {
                Motor(-spl, -(spr/5), -spl, -(spr/5));
              }
        else if(mcp_f(0) > md_mcp_f(0) && mcp_f(3) < md_mcp_f(3)-50)
              {
                Motor(-(spl/5), -spr, -(spl/5), -spr);
              }
          else if(mcp_f(4) > md_mcp_f(4) && mcp_f(5) > md_mcp_f(5))
              {
                Motor(-25, -25, -25, -25);
              }
          }
       
      }
    else{}
    Motor(0, 0, 0, 0);
    delay(100);
    if(offset == 'l')
      {
        none_set_f = false;
      }
     else
      {
        none_set_f = true;
      }
    
  }
void fw_none(int spl, int spr, int _time, char offset)
  {
    last_time = millis();
    while(millis()-last_time < _time)
      {
        Motor(spl, spr, spl, spr);
      }
    for(int i = spl; i > 10; i -= 1)
      {
        Motor( i, i, i, i);
        if(mcp_f(1) < md_mcp_f(1)-50 && mcp_f(2) < md_mcp_f(2)-50)
              {
                Motor(-20, -20, -20, -20); delay(50);
                break;
              }
        delay(5);
      }
    if(offset == 'l')
      {
        while(1)
          {
            Motor(20, 20, 20, 20);
            if(mcp_f(1) < md_mcp_f(1)-50 && mcp_f(2) < md_mcp_f(2)-50)
              {
                break;
              }
          }
        Motor(0, 0, 0, 0);
        delay(100);
      }
    else
      {
        Motor(0, 0, 0, 0);
        delay(5);
      }
           if(offset == 'l')
      {
        none_set_f = false;
      }
     else
      {
        none_set_f = true;
      }
    
  }
