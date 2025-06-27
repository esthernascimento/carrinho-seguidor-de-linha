// ===============================
// Robô Seguidor de Linha com Correção Dinâmica + PWM
// ===============================

// Pinos do L298N
#define ENA 9  // Enable motor esquerdo (PWM)
#define ENB 10 // Enable motor direito (PWM)

#define IN1 2  // Motor esquerdo
#define IN2 3
#define IN3 4  // Motor direito
#define IN4 5

// Sensores (invertido E ↔ D)
#define SensorE A2
#define SensorC A1
#define SensorD A0

int velocidade = 80; // Controle da velocidade (0 a 255)

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int valorE = analogRead(SensorE);
  int valorC = analogRead(SensorC);
  int valorD = analogRead(SensorD);

  Serial.print("E: "); Serial.print(valorE);
  Serial.print(" | C: "); Serial.print(valorC);
  Serial.print(" | D: "); Serial.println(valorD);
  
  bool esquerdaAlta = valorE > 300;
  bool centroAlto = valorC > 300;
  bool direitaAlta = valorD > 300;

  bool esquerdaBaixa = valorE < 150;
  bool centroBaixa = valorC < 150;
  bool direitaBaixa = valorD < 150;

  if ((centroAlto && esquerdaBaixa && direitaBaixa) || (esquerdaBaixa && centroBaixa && direitaBaixa)) {
    frente();
  } else if (esquerdaAlta && centroBaixa && direitaBaixa) {
    curvaDireita(); 
  } else if (direitaAlta && centroBaixa && esquerdaBaixa) {
    curvaEsquerda();
  } else {
    parar();
  }

  delay(80);
}

// ===============================
// Funções de Movimento com PWM
// ===============================

void frente() {
  analogWrite(ENA, velocidade);
  analogWrite(ENB, velocidade);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void curvaEsquerda() {
  analogWrite(ENA, velocidade);
  analogWrite(ENB, velocidade / 2); // Reduz velocidade do motor direito

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void curvaDireita() {
  analogWrite(ENA, velocidade / 2); // Reduz velocidade do motor esquerdo
  analogWrite(ENB, velocidade);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void parar() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}