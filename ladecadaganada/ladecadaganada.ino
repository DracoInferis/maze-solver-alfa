

long i;
void setup() {


Serial.begin(9600);

 pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
  pinMode( 3 , INPUT );

  pinMode( 2 , OUTPUT );
  pinMode( 12 , INPUT );
  Serial.begin(9600);

  pinMode( 5 , INPUT );

  pinMode( 4 , OUTPUT );

  pinMode(6,OUTPUT);

  pinMode(7,OUTPUT);

  pinMode(8,OUTPUT);

  pinMode(9,OUTPUT);
pinMode(A5,OUTPUT);
pinMode(A4,OUTPUT);
pinMode(A3,OUTPUT);
pinMode(A2,OUTPUT);
pinMode(A1,OUTPUT);
pinMode(A0,OUTPUT);

 }
void loop() {


  long duracion_adelante,adelante,duracion_derecha,derecha;

  digitalWrite(2, LOW); 
     delayMicroseconds(2); 
     digitalWrite(2, HIGH);  
     delayMicroseconds(5);           
     digitalWrite(2, LOW);  
     duracion_adelante = pulseIn(3, HIGH);
     adelante = duracion_adelante/29/2;
        Serial.println("adelante");
    Serial.println(adelante);
 
     digitalWrite(4, LOW); 
     delayMicroseconds(2); 
     digitalWrite(4, HIGH);  
     delayMicroseconds(5);           
     digitalWrite(4, LOW);  
     duracion_derecha = pulseIn(5, HIGH);
     derecha = duracion_derecha/29/2;
          Serial.println("derecha");
     Serial.println(derecha);
  
  
    
   if (adelante>=4){
      if (derecha>0 && derecha<=1){
      analogWrite(11,60);
      analogWrite(10,90);
      digitalWrite(A0,HIGH);
      digitalWrite(8,HIGH);
      digitalWrite(A1,LOW);
         digitalWrite(9,LOW);
         }
             if (derecha>1 && derecha<=2){
      analogWrite(11,70);
      analogWrite(10,90);
      digitalWrite(A0,HIGH);
      digitalWrite(8,HIGH);
      digitalWrite(A1,LOW);
         digitalWrite(9,LOW);
         }
             if (derecha>2 && derecha<=3){
      analogWrite(11,70);
      analogWrite(10,80);
      digitalWrite(A0,HIGH);
      digitalWrite(8,HIGH);
      digitalWrite(A1,LOW);
         digitalWrite(9,LOW);
         }
             if (derecha>3 && derecha<=4){
      analogWrite(11,100);
      analogWrite(10,70);
      digitalWrite(A0,HIGH);
      digitalWrite(8,HIGH);
      digitalWrite(A1,LOW);
         digitalWrite(9,LOW);
         }
             if (derecha>4 && derecha<=5){
      analogWrite(11,90);
      analogWrite(10,70);
      digitalWrite(A0,HIGH);
      digitalWrite(8,HIGH);
      digitalWrite(A1,LOW);
         digitalWrite(9,LOW);
         }
           if (derecha>5 && derecha<=6){
      analogWrite(11,100);
      analogWrite(10,70);
      digitalWrite(A0,HIGH);
      digitalWrite(8,HIGH);
      digitalWrite(A1,LOW);
         digitalWrite(9,LOW);
         }
              if (derecha>6 && derecha<=7){
      analogWrite(11,100);
      analogWrite(10,70);
      digitalWrite(A0,HIGH);
      digitalWrite(8,HIGH);
      digitalWrite(A1,LOW);
         digitalWrite(9,LOW);
         }
        if (derecha>7 && derecha<=8){
      analogWrite(11,100);
      analogWrite(10,70);
      digitalWrite(A0,HIGH);
      digitalWrite(8,HIGH);
      digitalWrite(A1,LOW);
         digitalWrite(9,LOW);
         }
              if (derecha>7 && derecha<=8){
      analogWrite(11,100);
      analogWrite(10,80);
      digitalWrite(A0,HIGH);
      digitalWrite(8,HIGH);
      digitalWrite(A1,LOW);
         digitalWrite(9,LOW);
         }
            
              if (derecha>8 && derecha<=15){
      analogWrite(11,100);
      analogWrite(10,80);
      digitalWrite(A0,HIGH);
      digitalWrite(8,HIGH);
      digitalWrite(A1,LOW);
         digitalWrite(9,LOW);
         }
    
    if (derecha>15){
    
      analogWrite(11,50);
      analogWrite(10,50);
      digitalWrite(A1,HIGH);
      digitalWrite(9,HIGH);
      digitalWrite(A0,LOW);
      digitalWrite(8,LOW);
      delay(50);
  
      
      analogWrite(11,80);
      analogWrite(10,80);
      digitalWrite(A1,HIGH);
      digitalWrite(8,HIGH);
      digitalWrite(A0,LOW);
      digitalWrite(9,LOW);
      delay(100);
      
      analogWrite(11,0);
      analogWrite(10,0);
      digitalWrite(A1,HIGH);
      digitalWrite(8,HIGH);
      digitalWrite(A0,LOW);
      digitalWrite(9,LOW);
      delay(100);
        analogWrite(11,80);
      analogWrite(10,80);
      digitalWrite(A0,HIGH);
      digitalWrite(8,HIGH);
      digitalWrite(A1,LOW);
      digitalWrite(9,LOW);
      delay(400);
    
   
     }
      }
     if(adelante<4)
     {
      if(derecha>=0 && derecha<2){
      
       analogWrite(11,100);
      analogWrite(10,100);
      digitalWrite(A0,HIGH);
      digitalWrite(8,HIGH);
      digitalWrite(A0,LOW);
         digitalWrite(8,LOW);
         delay(200); 
    analogWrite(11,80);
      analogWrite(10,80);
      digitalWrite(A0,HIGH);
      digitalWrite(9,HIGH);
      digitalWrite(A0,LOW);
         digitalWrite(8,LOW);
         delay(200); 
          analogWrite(11,0);
      analogWrite(10,0);
      digitalWrite(A0,LOW);
      digitalWrite(9,HIGH);
      digitalWrite(A1,LOW);
      digitalWrite(8,LOW);
      delay(220); 

   analogWrite(11,90);
      analogWrite(10,90);
      digitalWrite(A0,HIGH);
      digitalWrite(9,HIGH);
      digitalWrite(A1,LOW);
      digitalWrite(8,LOW);
      delay(320); 
              analogWrite(11,0);
      analogWrite(10,0);
      digitalWrite(A0,LOW);
      digitalWrite(9,HIGH);
      digitalWrite(A1,LOW);
      digitalWrite(8,LOW);
      delay(400);
       }
     
       if(derecha>=2  ){
    
    
    analogWrite(11,80);
      analogWrite(10,80);
      digitalWrite(A1,HIGH);
      digitalWrite(9,HIGH);
      digitalWrite(A0,LOW);
         digitalWrite(8,LOW);
         delay(200); 
          analogWrite(11,0);
      analogWrite(10,0);
      digitalWrite(A0,LOW);
      digitalWrite(9,HIGH);
      digitalWrite(A1,LOW);
      digitalWrite(8,LOW);
      delay(220); 

   analogWrite(11,70);
      analogWrite(10,70);
      digitalWrite(A0,HIGH);
      digitalWrite(9,HIGH);
      digitalWrite(A1,LOW);
      digitalWrite(8,LOW);
      delay(420); 
   
   analogWrite(11,0);
      analogWrite(10,0);
      digitalWrite(A0,HIGH);
      digitalWrite(9,HIGH);
      digitalWrite(A1,LOW);
      digitalWrite(8,LOW);
      delay(400);
     
  
   
 }
        
}
        


    }     
     
  
     
     
    

 
