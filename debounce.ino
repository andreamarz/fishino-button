int ledPin = 9;
int pulsantePin = 2;
int ledStato = LOW;
int pulsanteStato = LOW;
int attesaDebounce = 50;
unsigned long ultimoTempoDebounce = 0;
int ultimaLettura = LOW;

void setup(){
  pinMode(ledPin, OUTPUT);
  pinMode(pulsantePin, INPUT);
  digitalWrite(ledPin, ledStato);
}

void loop(){
  int lettura = digitalRead(pulsantePin);
  if(lettura != ultimaLettura){
    ultimoTempoDebounce = millis();
  }

  if((millis() - ultimoTempoDebounce) > attesaDebounce){
    if(lettura != pulsanteStato and lettura == HIGH){
      ledStato = !ledStato;
      digitalWrite(ledPin, ledStato);
    }
    pulsanteStato = lettura;
  }

  ultimaLettura = lettura;
  delay(10);
}
