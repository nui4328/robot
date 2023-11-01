void set_f(int _time)
  {
    for(int i = 0; i<_time; i++)
      {
        Motor(-30, -30, -30, -30); delay(130);
        Motor(0, 0, 0, 0); delay(100);
        while(1)
          {
            if(mcp_f(1) < md_mcp_f(1)+100 && mcp_f(2) > md_mcp_f(2)) 
              {
                do{Motor(0, 30, 0, 30);}while(mcp_f(2) > md_mcp_f(2));
                Motor(0, -30, 0, -30);
                delay(30);
                Motor(0, 0, 0, 0); delay(10);
                break;
              }
            else if(mcp_f(1) > md_mcp_f(1) && mcp_f(2) < md_mcp_f(2)+100)
              {
                do{Motor(30, 0, 30, 0);}while(mcp_f(1) > md_mcp_f(1));
                Motor(-30, 0, -30, 0);
                delay(30);
                Motor(0, 0, 0, 0); delay(10);
                break;
              }
            else if(mcp_f(1) < md_mcp_f(1)+100 && mcp_f(2) < md_mcp_f(2)+100)
              {
                break;
              }
            else
              {
                Motor(20, 20, 20, 20);
              }
          }
         
      }
     Motor(-30, -30, -30, -30); delay(200);
     Motor(0, 0, 0, 0); delay(100);

     none_set_f = true;
  }
void set_b(int _time)
  {
    for(int i = 0; i<_time; i++)
      {
        Motor(30, 30, 30, 30); delay(200);
        Motor(0, 0, 0, 0); delay(100);
      
        while(1)
          {
            if(mcp_f(4) < 300 && mcp_f(5) < 300)
              {
                Motor(45, 45, 45, 45); delay(30);
                Motor(0, 0, 0, 0); delay(10);
                break;
              }
            else if(mcp_f(4) > 300 && mcp_f(5) < 300)
              {
                do{Motor(-35, 10, -35, 10);}while(mcp_f(4) > 300);
                Motor(20, 0, 20, 0);
                delay(50);
                Motor(0, 0, 0, 0); delay(10);
                break;
              }
            else if(mcp_f(4) < 300 && mcp_f(5) > 300)
              {
                do{Motor(20, -45, 20, -45);}while(mcp_f(5) > 300);
                Motor(0, 20, 0, 20);
                delay(50);
                Motor(0, 0, 0, 0); delay(10);
                break;
              }
            else
              {
                Motor(-20, -20, -20, -20);
              }
          }
         
      }
     Motor(20, 20, 20, 20); delay(300);
     Motor(0, 0, 0, 0); delay(2);
     none_set_f = true;
  }
