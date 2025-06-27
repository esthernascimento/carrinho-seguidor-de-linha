# 🚗😻 Pussycat – O Carro da Penelope Charmosa

Projeto de robô seguidor de linha baseado em Arduino, batizado de **Pussycat** em homenagem ao icônico carro da Penelope Charmosa. Este carrinho é capaz de detectar e seguir linhas pretas no chão usando sensores infravermelhos, e pode corrigir sua trajetória automaticamente com curvas suaves.

---

## 🧠 Funcionalidades

- Detecção de linha com 3 sensores IR (esquerda, centro, direita)
- Ajuste dinâmico de curvas à esquerda e à direita
- Controle de velocidade com PWM para maior precisão nas curvas
- Modo de calibração para leitura dos sensores
- Estrutura compatível com ponte H (ex: L298N)

---

## ⚙️ Componentes Utilizados

- Arduino Uno (ou similar)
- Driver Ponte H L298N
- 2 Motores DC com rodas
- 3 Sensores Infravermelhos de reflexão
- Protoboard e jumpers
- Fonte de energia (ex: 2S Li-Ion ou pack de pilhas)

---

## 🔌 Esquema de Ligação (exemplo)

| Pino Arduino | Componente         |
|--------------|--------------------|
| A0           | Sensor direito     |
| A1           | Sensor central     |
| A2           | Sensor esquerdo    |
| 2,3          | IN1/IN2 (motor A)  |
| 4,5          | IN3/IN4 (motor B)  |
| 9            | ENA (PWM motor A)  |
| 10           | ENB (PWM motor B)  |

---

## 🛠️ Instalação e Uso

1. Conecte todos os componentes conforme o esquema acima.
2. Abra o arquivo `.ino` no Arduino IDE.
3. Selecione a placa correta (ex: **Arduino Uno**) e a porta COM.
4. Carregue o código na placa.
5. Coloque o carrinho sobre uma linha preta com fundo branco e **divirta-se!**

---

## 🐾 Inspiração

Este projeto é uma homenagem ao icônico carro **Pussycat** da personagem **Penelope Charmosa**, da série "Corrida Maluca". Assim como ela, o carrinho busca ser elegante, inteligente e... sempre na frente! 💅

---


## 📄 Licença

Este projeto é de código aberto e pode ser usado livremente para fins educacionais ou pessoais. Contribuições são bem-vindas!

E ele foi realizado com a colaboração de:
- Esther Nascimento
- Gisele Nunes
- Gabriel Sampaio
- Kauã Amorim
- Hyago Inácio
- Gabriel Arruda

---
