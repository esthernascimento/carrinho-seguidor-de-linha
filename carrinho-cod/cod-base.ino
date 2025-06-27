int IN1 = 2 ;
int IN2 = 3 ;
int IN3 = 4 ;
int IN4 = 5 ;


void setup () {
 pinMode (IN1, OUTPUT);
 pinMode (IN2, OUTPUT);
 pinMode (IN3, OUTPUT);
 pinMode (IN4, OUTPUT);
 
}


void loop () {
 //Roda 1 ou direita
 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, LOW);
 
 //Roda 2 esquerda
 digitalWrite(IN3, HIGH);
 digitalWrite(IN4, LOW);
 
}