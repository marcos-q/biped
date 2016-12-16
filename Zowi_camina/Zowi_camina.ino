
// Zowi_camina v 0.3
//
// CC By SA  Marcos Quílez 2016-12

// Ejemplo que mueve a Zowi caminando de frente usando únicamente la libreria servo.h
// Parte de posición parado, camina de frente haciendo una parada cada

/*
 El número 1 hace referencia al pie izquierdo
 El número 2 hace referencia al pie derecho
 El número 3 hace referencia a la pierna izquierda
 El número 4 hace referencia a la pierna derecha
 */

#include <Servo.h>


#define numeroPasos 2  //numero de pasos (con cada pie) que da el robot entre parada y parada

#define pinServo1 2 //pie izquierdo
#define pinServo2 3 //pie derecho
#define pinServo3 4 //pierna izquierda
#define pinServo4 5 //pierna derecha


#define offset1  -2   //calibración pie izquierdo
#define offset2 -3  //calibración pie derecho
#define offset3 -5  //calibración pierna izquierda
#define offset4 -5   //calibración pierna derecha

#define anguloPie 16   // ángulo que gira el pie para ladear el robot
#define anguloPierna 20 // ángulo que gira la pierna para avanzar el robot 
#define pasoPie 4       // el pie gira hasta "anguloPie" en incrementos de "pasoPie"
#define pasoPierna 5    // la pierna gira hasta "anguloPierna" en incrementos de "pasoPierna"

#define pausa 50  //pausa entre maniobras de servos, determina la velocidad de avance

Servo myservo1;   // servo pie izquierdo
Servo myservo2;   //servo pie derecho
Servo myservo3;   // servo pierna izquierda
Servo myservo4;   // servo pierna derecha

int posicion1 = 90;    // variable to store the servo position
int posicion2 = 90;    // variable to store the servo position
int posicion3 = 90;    // variable to store the servo position
int posicion4 = 90;    // variable to store the servo position


void setup() {
  myservo1.attach(pinServo1);  // asigna los pines a los servos
  myservo2.attach(pinServo2);
  myservo3.attach(pinServo3); 
  myservo4.attach(pinServo4);

  firmes();
  
  delay (5000);
  
}

void loop() {
  
  preparaIzquierdo();
    
  for (int i=0;i<numeroPasos;i++){
    pasoIzquierdo();
    pasoDerecho();
  }

  cierraIzquierdo();
  
  delay(1000);
  

}

void pasoIzquierdo(){
    //partimos con zowi ladeado al lado izquiedo, después de haber llamado a preparaIzquierdo() 
    //Avanza un paso con el pie izquierdo

   for (int incremento=0;incremento<=anguloPierna;incremento=incremento+pasoPierna){
    posicion3=posicion3-pasoPierna; 
    myservo3.write(posicion3+offset3);
    posicion4=posicion4-pasoPierna; 
    myservo4.write(posicion4+offset4);
    delay(pausa);
   }

   for (int incremento=0;incremento<=anguloPie;incremento=incremento+pasoPie){
    posicion2=posicion2-pasoPie; 
    myservo2.write(posicion2+offset2);
    posicion1=posicion1-pasoPie*2; 
    myservo1.write(posicion1+offset1);
    delay(pausa);
   }
   for (int incremento=0;incremento<=anguloPie;incremento=incremento+pasoPie){
    posicion2=posicion2-pasoPie*2; 
    myservo2.write(posicion2+offset2);
    posicion1=posicion1-pasoPie; 
    myservo1.write(posicion1+offset1);
    delay(pausa);
   }   

   
   for (int incremento=0;incremento<=anguloPierna;incremento=incremento+pasoPierna){
    posicion3=posicion3+pasoPierna; 
    myservo3.write(posicion3+offset3);
    posicion4=posicion4+pasoPierna; 
    myservo4.write(posicion4+offset4);
    delay(pausa);
   }     
     
}


void pasoDerecho(){
    // avanza un paso con el pie derecho
    
   for (int incremento=0;incremento<=anguloPierna;incremento=incremento+pasoPierna){
    
    posicion3=posicion3+pasoPierna; 
    myservo3.write(posicion3+offset3);
    posicion4=posicion4+pasoPierna; 
    myservo4.write(posicion4+offset4);
    delay(pausa);
   }

  

   for (int incremento=0;incremento<=anguloPie;incremento=incremento+pasoPie){
    
    posicion2=posicion2+pasoPie*2; 
    myservo2.write(posicion2+offset2);
    posicion1=posicion1+pasoPie; 
    myservo1.write(posicion1+offset1);
    delay(pausa);
   }
   for (int incremento=0;incremento<=anguloPie;incremento=incremento+pasoPie){
    posicion2=posicion2+pasoPie; 
    myservo2.write(posicion2+offset2);
    posicion1=posicion1+pasoPie*2; 
    myservo1.write(posicion1+offset1);
    delay(pausa);
   }   

     
   
   for (int incremento=0;incremento<=anguloPierna;incremento=incremento+pasoPierna){
    posicion3=posicion3-pasoPierna; 
    myservo3.write(posicion3+offset3);
    posicion4=posicion4-pasoPierna; 
    myservo4.write(posicion4+offset4);
    delay(pausa);
   }     

}


void preparaIzquierdo(){

    // Ladea el robot y lo deja preparado para pasoIzquierdo()
    
    for (int incremento=0;incremento<=anguloPie;incremento=incremento+pasoPie){
    posicion2=posicion2+pasoPie; 
    myservo2.write(posicion2+offset2);
    posicion1=posicion1+pasoPie*2; 
    myservo1.write(posicion1+offset1);
    delay(pausa);
   }
}

void cierraIzquierdo(){

    //descansa el pie derecho para terminar en la posición de reposo

   for (int incremento=0;incremento<=anguloPie;incremento=incremento+pasoPie){
    posicion2=posicion2-pasoPie; 
    myservo2.write(posicion2+offset2);
    posicion1=posicion1-pasoPie*2; 
    myservo1.write(posicion1+offset1);
    delay(pausa);
   } 

}

void firmes(){

    // pone el robot en la posición de reposo
    
    posicion1=90+offset1;
    posicion2=90+offset2;
    posicion3=90+offset3;
    posicion4=90+offset4;
    
    myservo1.write(posicion1);
    delay(20);
    myservo2.write(posicion2);
    delay(20);
    myservo3.write(posicion3);
    delay(20);
    myservo4.write(posicion4);
    delay(20);
  
}


