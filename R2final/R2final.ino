///codigo para dar vida ao R2-D2 by Sarah Ramos///
//sons daptados do codigo "Project R2D2 Sound Generator - by Marcelo Larios"


#include <Servo.h> //biblioteca do servo
#define SERVO 7 // porta digital do servo
Servo s; //controle do servo

#define PinoSom 13 //porta digital do auto falante
#define PinoLed 11 //porta digital do Led
void setup() {

    pinMode(3, OUTPUT); //pinos dos motores
    pinMode(4, OUTPUT); 
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
  
    s.attach(SERVO); 
    s.write(90); 
    pinMode(PinoSom, OUTPUT);
    pinMode(PinoLed, OUTPUT);
    randomSeed(analogRead(0));
}
void frase1() {
    
    int k = random(1000,2000);
    digitalWrite(PinoLed, HIGH);
     
    for (int i = 0; i <=  random(100,2000); i++){
        
        tone(PinoSom, k+(-i*2));          
        delay(random(.9,2)); 
        s.write(90);  
    } 
    digitalWrite(PinoLed, LOW); 
 
    for (int i = 0; i <= random(100,1000); i++){
        
        tone(PinoSom, k + (i * 10));          
        delay(random(.9,2));  
        s.write(10);          
    } 
}
void frase2() {
    
    int k = random(1000,2000);
    digitalWrite(PinoLed, HIGH); 
    s.write(30); 
    for (int i = 0; i <= random(100,2000); i++){
        
        tone(PinoSom, k+(i*2));          
        delay(random(.9,2));  
        s.write(90);     
    } 
    digitalWrite(PinoLed, LOW);   
    for (int i = 0; i <= random(100,1000); i++){
        
        tone(PinoSom, k + (-i * 10));          
        delay(random(.9,2));     
        s.write(10);        
    } 
}
void loop() {

    digitalWrite(3,LOW); 
    digitalWrite(4,LOW);
    digitalWrite(6,LOW);
    digitalWrite(5,LOW);
    int K = 2000;
    switch (random(1,7)) {
        
        case 1:frase1(); break;
        case 2:frase2(); break;
        case 3:frase1(); frase2(); break;
        case 4:frase1(); frase2(); frase1();break;
        case 5:frase1(); frase2(); frase1(); frase2(); frase1();break;
        case 6:frase2(); frase1(); frase2(); break;
    }
    for (int i = 0; i <= random(3, 9); i++){

      digitalWrite(3,LOW); 
      digitalWrite(4,HIGH);
      digitalWrite(6,HIGH);
      digitalWrite(5,LOW);
      
        digitalWrite(PinoLed, HIGH);  
        tone(PinoSom, K + random(-1700, 2000));          
        delay(random(70, 170));   
        digitalWrite(PinoLed, LOW);           
        noTone(PinoSom);         
        delay(random(0, 30));             
    } 
    noTone(PinoSom);  
     
   delay(random(2000, 4000));    //primeira versao
}
