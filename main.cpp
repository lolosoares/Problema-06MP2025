#include <Keypad.h>
#include <LiquidCrystal.h>

// Configuração do LCD (pinos: RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, A4, A3, A2, A1);

// Configuração do teclado
const byte LINHAS = 4;
const byte COLUNAS = 4;
char teclas[LINHAS][COLUNAS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte pinosLinha[LINHAS] = {6,7,8,9};     //Ligacoes
byte pinosColuna[COLUNAS] = {2,3,4,5};

Keypad teclado = Keypad(makeKeymap(teclas), pinosLinha, pinosColuna, LINHAS, COLUNAS);

String valorDigitado = ""; // Variável interna para armazenar valor

void setup() {
  lcd.begin(16, 2); //numero de linhas do display
  lcd.print("Digite:");
}

void loop() {
  char tecla = teclado.getKey();
  
  if (tecla) {
    if (tecla == '#') {
      // Mostra valor final ao pressionar #
      lcd.clear();
      lcd.print("Valor:");
      lcd.setCursor(0,1);
      lcd.print(valorDigitado);
      delay(2000);
      lcd.clear();
      lcd.print("Digite:");
      valorDigitado = "";
    } else if (tecla == '*') {
      // Limpa entrada com *
      valorDigitado = "";
      lcd.clear();
      lcd.print("Digite um valor:");
    } else {
      // Adiciona caracter e mostra na tela
      valorDigitado += tecla;
      lcd.setCursor(0,1);
      lcd.print(valorDigitado);
    }
  }
}
