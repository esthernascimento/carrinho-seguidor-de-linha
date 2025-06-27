// Motores
#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5

// Sensores
#define SensorE 10
#define SensorC 11
#define SensorD 12


void setup() {
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);
 pinMode(SensorE, INPUT);
 pinMode(SensorC, INPUT);
 pinMode(SensorD, INPUT);
}


void loop() {
 int e = digitalRead(SensorE);
 int c = digitalRead(SensorC);
 int d = digitalRead(SensorD);
 if (e == HIGH && c == LOW && d == HIGH) {
 frente();
 } else if (e == HIGH && c == HIGH && d == LOW) {
 curvaEsquerda();
 } else if (e == LOW && c == HIGH && d == HIGH) {
 curvaDireita();
 } else if (e == LOW && c == LOW && d == LOW) {
 frente(); // linha centralizada
 } else if (e == HIGH && c == HIGH && d == HIGH) {
 parar(); // tudo branco = fora da linha
 } else if (e == LOW && c == HIGH && d == LOW) {
 frente(); // em cima da linha apenas com central
 } else {
 parar(); // fallback de segurança
 }
}


// Funções auxiliares
void frente() {
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, HIGH);
 digitalWrite(IN3, HIGH);
 digitalWrite(IN4, LOW);
}
void curvaEsquerda() {
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, HIGH);
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, LOW);
}
void curvaDireita() {
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, LOW);
 digitalWrite(IN3, HIGH);
 digitalWrite(IN4, LOW);
}
void re() {
 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, LOW);
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, HIGH);
}
void parar() {
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, LOW);
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, LOW);
}