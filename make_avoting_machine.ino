#include<LiquidCrystal.h>
#include<EEPROM.h>

LiquidCrystal l(12, 13, 11, 10, 9, 8);
int c1 = 0, c2 = 0;
void setup() {
  Serial.begin(9600);
  l.begin(16, 2);
  //pinMode(A0, INPUT_PULLUP);
  pinMode(2 ,1);
  pinMode(3 , 1);
  pinMode(4 , INPUT_PULLUP);
  pinMode(5 , INPUT_PULLUP);
  pinMode(6 , INPUT_PULLUP);
  pinMode(7 ,INPUT_PULLUP);
}

void loop() {
  if (digitalRead(4) == 0)
  {
    c1++;
    delay(500);
    l.setCursor(3, 0);
    l.print("P1:");
    l.setCursor(6, 0);
    l.print(c1);
    delay(500);
    Serial.print("a=");
    Serial.println(c1);
  }


  if (digitalRead(5) == 0)
  {
    c2++;
    delay(500);
    l.setCursor(3, 1);
    l.print("P2:");
    l.setCursor(6, 1);
    l.print(c2);
    delay(500);
    Serial.print("b=");
    Serial.println(c2);
  }
  l.clear();

  if (digitalRead(6) == 0)
  {
    if (c1 > c2)
    {
      l.setCursor(3, 0);
      l.print("P1 wins");
      delay(5000);
      c2 = 0;
      c1 = 0;
    }
    if (c2 > c1)
    {
      l.setCursor(3, 0);
      l.print("P2 wins");
      delay(5000);
      c1 = 0;
      c2 = 0;
    }
    else
      //if(c1==c2)
    {
      l.setCursor(3, 0);
      l.print("its a tie");
      delay(5000);
      c1 = 0;
      c2 = 0;
    }
  }
  if (digitalRead(7) == 0)
  {

  }

}
