//C++ code
#include <LiquidCrystal.h>

// LCD nos pinos: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, A4, A3, A2, A1);

void setup() {
  lcd.begin(16, 2);  // Inicializa LCD com 16 colunas e 2 linhas

  String dadoInterno1 = "BEM-VINDO AOS";
  String dadoInterno2 ="CONTROLADORES";
  lcd.setCursor(0, 0);
  lcd.print("Projeto LCD");
  delay(2000);

  lcd.clear();
  lcd.setCursor(0, 0);              // Linha 0, coluna 0
  lcd.print(dadoInterno1);

  lcd.setCursor(0, 1);              // Linha 1, coluna 0
  lcd.print(dadoInterno2);
}

void loop() {
  // Nada acontece no loop
}
