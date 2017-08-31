//echoPin10 es el de adelante, echoPin20 es el de la derecha
const int echoPin10 = 3;
const int trigPin10 = 4;
const int echoPin20 = 5;
const int trigPin20 = 6;
//motorPin10 es el motor de la izquierda y motorPin20 el de la derecha
const int motorPin10 = 9;
const int motorPin11 = 8;
const int motorPin20 = 10;
const int motorPin21 = 11;
const int velMotor = 255 * 0.8;

void setup()
{
  Serial.begin(9600);
  pinMode(motorPin10, OUTPUT);
  pinMode(motorPin11, OUTPUT);
  pinMode(motorPin20, OUTPUT);
  pinMode(motorPin21, OUTPUT);
  pinMode(trigPin10, OUTPUT);
  pinMode(trigPin20, OUTPUT);
  pinMode(echoPin10, INPUT);
  pinMode(echoPin20, INPUT);
}

int ping(int trigPin10, int echoPin10)
{
  long duration, distanceCm;

  digitalWrite(trigPin10, LOW); //para generar un pulso limpio ponemos a 0 4us
  delayMicroseconds(10);
  digitalWrite(trigPin10, HIGH); //generamos Trigger (disparo) de 10us
  delayMicroseconds(10);
  digitalWrite(trigPin10, LOW);

  duration = pulseIn(echoPin10, HIGH); //medimos el tiempo entre pulsos, en microsegundos

  distanceCm = duration * 10 / 292 / 2; //convertimos a distancia, en cm
  return distanceCm;
}

void loop()
{
  //cm10 es el sensor de adelante, cm20 es el sensor de la derecha
  int cm10 = ping(trigPin10, echoPin10);
  Serial.print("Distancia adelante: ");
  Serial.println(cm10);
  // delay(250);
  int cm20 = ping(trigPin20, echoPin20);
  Serial.print("Distancia derecha: ");
  Serial.println(cm20);
  // delay(250);
  if (cm10 > 10)
  {
    //El caso en que no tiene nada adelante pero si a la derecha
    analogWrite(motorPin10, velMotor);
    analogWrite(motorPin11, 0);
    analogWrite(motorPin20, velMotor);
    analogWrite(motorPin21, 0);
  }
  if (cm10 <= 10 && cm20 > 10)
  {
    //El caso en que tiene algo adelante pero no a la derecha
    analogWrite(motorPin10, 0);
    analogWrite(motorPin11, velMotor);
    analogWrite(motorPin20, velMotor);
    analogWrite(motorPin21, 0);
  }

  if (cm10 <= 10 && cm20 <= 10)
  {
    //El caso en que tiene algo a la derecha y adelante
    analogWrite(motorPin10, velMotor);
    analogWrite(motorPin11, 0);
    analogWrite(motorPin20, 0);
    analogWrite(motorPin21, velMotor);
  }
}