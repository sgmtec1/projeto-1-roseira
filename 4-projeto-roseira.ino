/*  Open Source
Projeto Roseira
pino A0 = Sinal do sensor de umidade
pino 
*/

#define pino_sinal_analogico A0
int valor_analogico;
int pinRele = 10;

void setup() {
  Serial.begin(9600);
  pinMode(pino_sinal_analogico, INPUT);
  pinMode(pinRele, OUTPUT);
  Serial.print("Umidade: ");
}
void loop() {
  //Le o valor do pino A0 do sensor
  valor_analogico = analogRead(pino_sinal_analogico);

 
  //Mostra o valor da porta analogica no serial monitor
  Serial.println("Porta analogica: ");
  Serial.println(valor_analogico);

  //Solo umido, fonte desligada
  if (valor_analogico > 0 && valor_analogico < 400)
  {
    Serial.println(" Status: Solo umido");
    Serial.println("Umidade: ");
    Serial.println(valor_analogico);
    digitalWrite(pinRele, LOW);
      
  }
 
  //Solo seco, acende led vermelho
  if (valor_analogico > 800 && valor_analogico < 1024)
  {
    Serial.println(" Status: Solo Seco");
    Serial.println("Umidade: ");
    Serial.println(valor_analogico);
    digitalWrite(pinRele, HIGH);
  }
  delay(1000);
}
