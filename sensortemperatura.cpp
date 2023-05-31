int sensorPino = A0;
int ledVermelho = 11;
int ledAmarelo = 12;
int ledVerde = 13;

void setup()
{
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int valorPino = analogRead(sensorPino);
  int temperatura = map(valorPino, 20, 358, -40, 125);
  Serial.println(temperatura);
  
  if (temperatura >= 35 && temperatura <=40){
  	analogWrite(ledVermelho, 0);
    analogWrite(ledAmarelo, 255);
    analogWrite(ledVerde, 0);
  } 
    else if (temperatura > 40){
  	analogWrite(ledVermelho, 255);
    analogWrite(ledAmarelo, 0);
    analogWrite(ledVerde, 0);
  }
  else {
  	analogWrite(ledVermelho, 0);
    analogWrite(ledAmarelo, 0);
    analogWrite(ledVerde, 255);
  }
}

/* Os Leds acendem da seguinte forma:
Verde - <35°
Amarelo - 35° - 40°
Vermelho - > 40°*/