//carro
#define VERDE 0
#define AMARELO 1
#define VERMELHO 2
//pedestre
#define VERDE_P 4
#define VERMELHO_P 5

int i;
bool estado = true;

void setup(){
  pinMode(VERDE, OUTPUT);
  pinMode(AMARELO, OUTPUT);
  pinMode(VERMELHO, OUTPUT);
  pinMode(VERDE_P, OUTPUT);
  pinMode(VERMELHO_P, OUTPUT);
}
void loop(){
  digitalWrite(VERMELHO_P, HIGH);
  digitalWrite(VERMELHO, HIGH);
  delay(2000);
    while(estado == true){
    digitalWrite(VERMELHO_P, HIGH);
    digitalWrite(VERMELHO, LOW);
    digitalWrite(VERDE, HIGH);
    delay(5000);
    digitalWrite(VERDE, LOW);
    digitalWrite(AMARELO, HIGH);
    delay(3000);
    digitalWrite(AMARELO, LOW);
    digitalWrite(VERMELHO, HIGH);
    digitalWrite(VERMELHO_P, LOW);
    digitalWrite(VERDE_P, HIGH);
    delay(2000);
    digitalWrite(VERDE_P, LOW);
    for(i= 1; i<=4; i++){
      digitalWrite(VERMELHO_P, HIGH);
      delay(500);
      digitalWrite(VERMELHO_P, LOW);
      delay(500);
      delay(500);
    }
    }
    
  




}
