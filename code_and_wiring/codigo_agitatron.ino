/* 
 Agitatron versión 1 con switch
 Pablo Zárate
 Para tanques AP
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

unsigned long tempo1; //variable para el temporizador

int pos = 0;    // variable to store the servo position

const int switchConstante = 4;    // switch constante
const int switchProgram = 5;      // switch program

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
  pinMode(switchConstante, INPUT);
  pinMode(switchProgram, INPUT);

}

void loop() {

tempo1 = millis (); //asigna el valor del temporizador

          Serial.print("tiempo sistema: "); //monitoreo
          Serial.println(tempo1); //monitoreo

int velocidad = analogRead(A0)/5;

          Serial.print("potencia: "); //monitoreo
          Serial.println(velocidad); //monitoreo
  

if(digitalRead(switchProgram) == HIGH){  
   
  Serial.println("program on"); //aviso de modo program
   
  if (tempo1 <=60000){ //1 minuto - constant 1 minute 

                        giro();
                        
                        }

          else //superado el primer minuto, pasa a agitar cada 14 segundos 

                        { 

                        myservo.detach(); //desconecta el servo
                        delay (14000); //espera 14 segundos-waits 14 seconds
                        myservo.attach(9); //reconecta el servo
                      
                      
                       giro();
 
  
           } //termina el ELSE de program
} else if (digitalRead(switchConstante) == HIGH){

Serial.println("continuo on");
giro();
  
}


}  //fin completo loop

//declaración función de giro

int giro(){
   /* inicio de ida */  
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    int velocidad = analogRead(A0)/5; //this reads the pot
     if (velocidad <=4){
    velocidad = 4; //this part establish the minimum for the pot
  }
    delay(velocidad);                      
  }                                   
 /* fin de ida */
 /* inicio de vuelta - servo returns */
 for (int posR = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    posR = pos;
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    int velocidad = analogRead(A0)/5;
     if (velocidad <=4){
    velocidad = 4;
  }
    delay(velocidad);                      
  }
/*fin de vuelta*/

}
