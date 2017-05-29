/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Graphical representation is available using serial plotter (Tools > Serial Plotter menu)
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.
*/
#include <LiquidCrystal.h>
#define btnRIGHT 0
#define btnUP 1
#define btnDOWN 2
#define btnLEFT 3
#define btnSELECT 4
#define btnNONE 5
#define WEB

void serialPrintf(char *text, ...);
void serialScanf(char *text);
int read_LCD_buttons(void);

char msgs[5][15] = {"Right","Up","Down","Left","Select" };

//libreria para manejar el lcd
int milisegundos;
int milisegundosBotones;
int segundos;
int minutos;
int horas;
int decimas;
int flag=0;
int flagBoton=1;

LiquidCrystal lcd(8,9,4,5,6,7);

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
}


void loop() {

  milisegundos = millis();
  milisegundosBotones = millis();

if(flag==1)
{
  if(milisegundos % 100 == 0)
  {
    decimas++;
    lcd.setCursor(10,0);
    lcd.print(decimas);

  }
  if(decimas > 9)
  {
    segundos++;
    lcd.setCursor(7,0);
    lcd.print(segundos);
    decimas=0;
  }
  if(segundos > 59)
  {
    minutos++;
    lcd.setCursor(4,0);
    lcd.print(minutos);
    segundos=0;
    if(minutos>0)
    {
     lcd.setCursor(8,0);
     lcd.print(" ");
     lcd.setCursor(7,0);
    }

  }
  if(minutos > 59)
  {
    horas++;
    lcd.setCursor(0,0);
    lcd.print(horas);
    minutos=0;
  }
}

   

  int sensorValue = analogRead(A0);

  if(milisegundosBotones % 1000 == 0)
    flagBoton=1;

  if(sensorValue>=0&&sensorValue<100 && flagBoton==1){
    
      if(flag==0)
        flag=1; 
      else
        flag=0;

      flagBoton=0;
        //lcd.print("right"); 
        
    }else if(sensorValue>=110&&sensorValue<=190){

        if(flag==0)
          


        //lcd.print("up   ");
        
      }else if(sensorValue>=290&&sensorValue<=360){

           //lcd.print("down ");
           
        }else if(sensorValue>=480&&sensorValue<=530 && flagBoton==1){
 
            milisegundos=0;
            decimas=0;
            segundos=0;
            minutos=0;
            horas=0;

            lcd.setCursor(7,0);
            lcd.print(0);
            lcd.setCursor(10,0);
            lcd.print(0);
            lcd.setCursor(4,0);
            lcd.print(0);
            lcd.setCursor(0,0);
            lcd.print(0);
            
            flagBoton=0;

             
          }else if(sensorValue>=700&&sensorValue<=780){

            }
            

  // delay in between reads for stability
}





