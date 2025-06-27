// Motores
#define IN1 2 // Motor Direito para frente
#define IN2 3 // Motor Direito para trás
#define IN3 4 // Motor Esquerdo para frente
#define IN4 5 // Motor Esquerdo para trás


// Sensores
#define SensorE 10 // Sensor Esquerdo
#define SensorC 11 // Sensor Central
#define SensorD 12 // Sensor Direito


void setup() {
// Configura motores como saída
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);
 // Configura sensores como entrada
 pinMode(SensorE, INPUT);
 pinMode(SensorC, INPUT);
 pinMode(SensorD, INPUT);
}

void loop() {
 // Lê sensores (ativo baixo, por isso usamos !)
 bool esquerda = !digitalRead(SensorE);
 bool centro = !digitalRead(SensorC);
 bool direita = !digitalRead(SensorD);
 if (centro && !esquerda && !direita) {
 // Vai em frente
 frente();
 }
 else if (esquerda && !centro) {
 // Curva para a esquerda
 curvaEsquerda();
 }
 else if (direita && !centro) {
 // Curva para a direita
 curvaDireita();
 }
 else {
 // Linha perdida - parar ou girar pra procurar
 parar();
 }
}


// Funções auxiliares
void frente() {
 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, LOW);
 digitalWrite(IN3, HIGH);
 digitalWrite(IN4, LOW);
}
void curvaEsquerda() {
 digitalWrite(IN1, HIGH); // Direito vai pra frente
 digitalWrite(IN2, LOW);
 digitalWrite(IN3, LOW); // Esquerdo para
 digitalWrite(IN4, LOW);
}
void curvaDireita() {
 digitalWrite(IN1, LOW); // Direito para
 digitalWrite(IN2, LOW);
 digitalWrite(IN3, HIGH); // Esquerdo vai pra frente
 digitalWrite(IN4, LOW);
}
void parar() {
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, LOW);
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, LOW);
}
