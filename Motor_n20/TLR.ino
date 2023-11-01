void tl(int pw, int offset)
  {
    if(none_set_f == false)
      {
        Motor(-30, -30, -30, -30); delay(100);
        delay(100);
      }
    else{}
    Motor(0, 0, 0, 0);
    delay(300);
    Motor(-pw, pw, -pw, pw);
    delay(offset);
    Motor(0, 0, 0, 0);
    delay(100);

    none_set_f = false;
  }
void tr(int pw, int offset)
  {
    if(none_set_f == false)
      {
        Motor(-30, -30, -30, -30); delay(120);
        delay(100);
      }
    else{}
    Motor(0, 0, 0, 0);
    delay(300);
    Motor(pw, -pw, pw, -pw);
    delay(offset);
    Motor(0, 0, 0, 0);
    delay(100);

    none_set_f = false;
  }
