//echoPin10 es el de adelante, echoPin20 es el de la derecha
const int echoPin10 = 3;
const int trigPin10 = 4;
const int echoPin20 = 5;
const int trigPin20 = 6;
//motorPin10 es el motor de la izquierda y motorPin20 el de la derecha
const int motorPin10 = 8;
const int motorPin11 = 9;
const int motorPin20 = 10;
const int motorPin21 = 11;
const int velMotorIzq = 255 * 0.90;
const int velMotorDer = 255 * 0.90;

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

void loop()
{
  //cm10 es el sensor de adelante, cm20 es el sensor de la derecha
  // int cm10 = ping(trigPin10, echoPin10);
  // Serial.print("Distancia adelante: ");
  // Serial.println(cm10);
  // delay(250);
  // int cm20 = ping(trigPin20, echoPin20);
  // Serial.print("Distancia derecha: ");
  // Serial.println(cm20);
  // delay(250);
  int dirBot = direccionBot();
  switch (dirBot)
  {
  case 0:
    Adelante();
    break;
  case 1:
    Derecha();
    break;
  case 2:
    Izquierda();
    break;
  case 3:
    Atras();
    delay(800);
    Derecha();
    delay(800);
    break;
  default:
    Derecha();
    break;
  }
}

int direccionBot()
{
  int direccion;
  int cm10 = ping(trigPin10, echoPin10);
  int cm20 = ping(trigPin20, echoPin20);
  if (cm10 > 3 && cm10 > 10 && cm20 < 15)
  {
    //El caso en que no tiene nada adelante pero si a la derecha.
    direccion = 0;
    return direccion;
  }
  if (cm10 > 3 && cm10 <= 10 && cm20 > 15)
  {
    //El caso en que tiene algo adelante pero no a la derecha.
    direccion = 1;
    return direccion;
  }
  if (cm10 > 3 && cm10 <= 10 && cm20 <= 15)
  {
    //El caso en que tiene algo a la derecha y adelante.
    direccion = 2;
    return direccion;
  }
  if (cm10 > 10 && cm20 > 15)
  //Prioriza girar a la derecha antes de seguir adelante.
  {
    direccion = 1;
    return direccion;
  }
  if (cm10 <= 3)
  {
    //Si esta muy cerca de la pared, vuelve hacia atrás.
    direccion = 3;
    return direccion;
  }
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

void Adelante()
{
  analogWrite(motorPin10, velMotorIzq);
  analogWrite(motorPin11, 0);
  analogWrite(motorPin20, velMotorDer);
  analogWrite(motorPin21, 0);
}
void Derecha()
{
  analogWrite(motorPin10, 0);
  analogWrite(motorPin11, velMotorIzq);
  analogWrite(motorPin20, velMotorDer);
  analogWrite(motorPin21, 0);
}
void Izquierda()
{
  analogWrite(motorPin10, velMotorIzq);
  analogWrite(motorPin11, 0);
  analogWrite(motorPin20, 0);
  analogWrite(motorPin21, velMotorDer);
}
void Atras()
{
  analogWrite(motorPin10, 0);
  analogWrite(motorPin11, velMotorIzq);
  analogWrite(motorPin20, 0);
  analogWrite(motorPin21, velMotorDer);
}