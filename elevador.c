#include <Servo.h> 

// Definindo os pinos dos botões
const int botaoAndar0 = 2;
const int botaoAndar1 = 3;
const int botaoAndar2 = 4;

// Definindo os pinos dos LEDs
const int ledAndar0 = 8;
const int ledAndar1 = 9;
const int ledAndar2 = 10;

// Pino do servo
const int pinoServo = 12;

// Objeto servo
Servo servoElevador;

// Variável para guardar o andar atual
int andarAtual = 0;

// Posições do servo correspondentes a cada andar (ajuste conforme seu projeto)
int posAndar[3] = {0, 90, 180};

void setup() {
  // Configura os botões como entradas
  pinMode(botaoAndar0, INPUT_PULLUP);
  pinMode(botaoAndar1, INPUT_PULLUP);
  pinMode(botaoAndar2, INPUT_PULLUP);

  // Configura os LEDs como saídas
  pinMode(ledAndar0, OUTPUT);
  pinMode(ledAndar1, OUTPUT);
  pinMode(ledAndar2, OUTPUT);

  servoElevador.attach(pinoServo);

  // Inicia no térreo
  irParaAndar(0);
}

void loop() {
  // Verifica se o botão do térreo foi pressionado
  if (digitalRead(botaoAndar0) == LOW) {
    irParaAndar(0);
    delay(500); // pequena pausa para evitar múltiplas leituras
  }

  // Verifica se o botão do 1º andar foi pressionado
  if (digitalRead(botaoAndar1) == LOW) {
    irParaAndar(1);
    delay(500);
  }

  // Verifica se o botão do 2º andar foi pressionado
  if (digitalRead(botaoAndar2) == LOW) {
    irParaAndar(2);
    delay(500);
  }
}

// Função que simula o movimento do elevador
void irParaAndar(int destino) {
  // Apaga todos os LEDs
  digitalWrite(ledAndar0, LOW);
  digitalWrite(ledAndar1, LOW);
  digitalWrite(ledAndar2, LOW);

  // Simula tempo de deslocamento com delay
  if (andarAtual != destino) {
    int tempo = abs(destino - andarAtual) * 1000; // 1 segundo por andar
    moverServo(andarAtual, destino);
    delay(tempo);
  }

  // Acende o LED do andar de destino
  switch (destino) {
    case 0:
      digitalWrite(ledAndar0, HIGH);
      break;
    case 1:
      digitalWrite(ledAndar1, HIGH);
      break;
    case 2:
      digitalWrite(ledAndar2, HIGH);
      break;
  }

  // Atualiza o andar atual
  andarAtual = destino;
}

void moverServo(int origem, int destino) {
  int posOrigem = posAndar[origem];
  int posDestino = posAndar[destino];

  // Movimenta suavemente o servo até o destino
  if (posDestino > posOrigem) {
    for (int pos = posOrigem; pos <= posDestino; pos++) {
      servoElevador.write(pos);
      delay(15);
    }
  } else {
    for (int pos = posOrigem; pos >= posDestino; pos--) {
      servoElevador.write(pos);
      delay(15);
    }
  }
}