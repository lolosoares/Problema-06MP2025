#include <Keypad.h>

// Configuração do teclado
const byte LINHAS = 4;
const byte COLUNAS = 4;
char teclas[LINHAS][COLUNAS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte pinosLinha[LINHAS] = {9, 8, 7, 6};
byte pinosColuna[COLUNAS] = {5, 4, 3, 2};

Keypad teclado = Keypad(makeKeymap(teclas), pinosLinha, pinosColuna, LINHAS, COLUNAS);

String valorDigitado = "";

void setup() {
  Serial.begin(9600);
  Serial.println("Digite no teclado:");
}

void loop() {
  char tecla = teclado.getKey();

  if (tecla) {
    if (tecla == '#') {
      Serial.print("Valor final: ");
      Serial.println(valorDigitado);
      valorDigitado = "";
    } else if (tecla == '*') {
      valorDigitado = "";
      Serial.println("Limpo.");
    } else {
      valorDigitado += tecla;
    }
  }
}
