#include <SoftwareSerial.h>

//Criacao do objeto bluetooth
SoftwareSerial bluetooth(10, 11);

//Define os pinos para os motores
#define motorA 3
#define motorB 4
#define motorC 5
#define motorD 6

//String de recebimento
String comando;

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);

  pinMode(motorA, OUTPUT);
  pinMode(motorB, OUTPUT);
  pinMode(motorC, OUTPUT);
  pinMode(motorD, OUTPUT); 
}

void loop() { 
  comando = "";

  if(bluetooth.available())
  { 
    while(bluetooth.available())
    {
      char caracter = bluetooth.read();

      comando += caracter;

      delay(10);
    }
    
    //Liga motorA
    if(comando.indexOf("motorA") >= 0)
    {
      digitalWrite(motorA, HIGH);
      delay(350);
      digitalWrite(motorA, LOW); 
    }
    
    //Liga motorB
    if(comando.indexOf("motorB") >= 0)
    {
      digitalWrite(motorB, HIGH);
      delay(350);
      digitalWrite(motorB, LOW); 
    }
    
    //Liga motorC
    if(comando.indexOf("motorC") >= 0)
    {
      digitalWrite(motorC, HIGH);
      delay(350);
      digitalWrite(motorC, LOW); 
    }
    
    //Liga motorD
    if(comando.indexOf("motorD") >= 0)
    {
      digitalWrite(motorD, HIGH);
      delay(350);
      digitalWrite(motorD, LOW); 
    }

    //Notificacao
    if(digitalRead(motorA))
    {
      bluetooth.println("MotorA ligado");
    }
    else
    {
      bluetooth.println("MotorA desligado");
    }
    
    if(digitalRead(motorB))
    {
      bluetooth.println("MotorB ligado");
    }
    else
    {
      bluetooth.println("MotorB desligado");
    }
    
    if(digitalRead(motorC))
    {
      bluetooth.println("MotorC ligado");
    }
    else
    {
      bluetooth.println("MotorC desligado");
    }
    
    if(digitalRead(motorD))
    {
      bluetooth.println("MotorD ligado");
    }
    else
    {
      bluetooth.println("MotorD desligado");
    }
  }
}
