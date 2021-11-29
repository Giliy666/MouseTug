#include <Arduino.h>
#include <Mouse.h>
#include <Keyboard.h>

#define pin_button PB10
#define led PC13

bool start_stop;
bool work = 1 ;
int slideX=0;
int slideY=0;
int scrol=0;


void setup() 
{  
  pinMode(pin_button,INPUT_PULLUP);
  pinMode(led,OUTPUT);

  Mouse.begin();
  Keyboard.begin();
}

void loop() 
{
  slideX=random(-200,200);  
  
  slideY=random(-200,200);

  scrol=random(-5,5);


  start_stop=digitalRead(pin_button);
  delay(50);
  start_stop=digitalRead(pin_button);
  if (start_stop==0)
  {
    work=!work;
  }
  digitalWrite(led,work);  
  if (work==0)
  {
   /*
   Keyboard.print(slideX);
   Keyboard.print("+");
   Keyboard.print(slideY);
   Keyboard.print("+"); 
   Keyboard.print(scrol);   
   Keyboard.print("\n");  
   */
   Mouse.move(slideX,slideY,scrol);
   //Mouse.move(slideX,slideY,0);
  }  
  
  delay(5000);
  
}


