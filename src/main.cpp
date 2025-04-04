#include <Arduino.h>

// Definições dos pinos
#define POWER_PIN 5  // GPIO para acionar o botão Power
#define RESET_PIN 4  // GPIO para acionar o botão Reset

// Tempo de acionamento dos botões (em milissegundos)
#define PRESS_TIME 500

void pressButton(int pin) {
  digitalWrite(pin, LOW);   // Simula o pressionar do botão (GND)
  delay(PRESS_TIME);        // Tempo de pressionamento
  digitalWrite(pin, HIGH);  // Solta o botão
}

void setup() {
  pinMode(POWER_PIN, OUTPUT);
  pinMode(RESET_PIN, OUTPUT);

  digitalWrite(POWER_PIN, HIGH);  // Inicialmente desligado
  digitalWrite(RESET_PIN, HIGH);

  Serial.begin(115200);
  Serial.println("ESP32 Power & Reset pronto!");
}

void loop() {
  // Exemplo: Pressionar o botão Power a cada 10 segundos
  // pressButton(POWER_PIN);
  // delay(10000);

  // Exemplo: Pressionar Reset (comente ou apague se não for usar)
  // pressButton(RESET_PIN);
  // delay(30000);
}
