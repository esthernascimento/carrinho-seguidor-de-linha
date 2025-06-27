// Motores
#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5

// Sensores analógicos
#define SensorE A0
#define SensorC A1
#define SensorD A2


// Limiar para detectar linha (ajuste conforme necessário)
int threshold = 500;
void setup() {
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);
 // Não é necessário configurar analog pins como INPUT no Arduino
 Serial.begin(9600); // Útil para debug
}
void loop() {
 int valorE = analogRead(SensorE);
 int valorC = analogRead(SensorC);
 int valorD = analogRead(SensorD);
// Debug para calibração (pode remover depois de ajustar o threshold)
 Serial.print("E: "); Serial.print(valorE);
 Serial.print(" | C: "); Serial.print(valorC);
 Serial.print(" | D: "); Serial.println(valorD);
 bool e = valorE < threshold;
 bool c = valorC < threshold;
 bool d = valorD < threshold;
 if (e && !c && d) {
 frente();
 } else if (e && c && !d) {
 curvaEsquerda();
 } else if (!e && c && d) {
 curvaDireita();
 } else if (!e && !c && !d) {
 frente(); // linha centralizada
 } else if (e && c && d) {
 parar(); // fora da linha
 } else if (!e && c && !d) {
 frente(); // em cima da linha
 } else {
 parar(); // fallback
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