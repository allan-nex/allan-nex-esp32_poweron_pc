
// Projeto: Ligar o PC com ESP32 via Alexa (Sinric Pro)
// Autor: ChatGPT + [Seu Nome Aqui]
// Dependência: SinricPro (instalar pela biblioteca do Arduino IDE)

#include <SinricPro.h>
#include <SinricProSwitch.h>

#define WIFI_SSID     "SUA_REDE_WIFI"
#define WIFI_PASS     "SENHA_WIFI"
#define APP_KEY       "SINRICPRO_APP_KEY"
#define APP_SECRET    "SINRICPRO_APP_SECRET"
#define DEVICE_ID     "SINRICPRO_DEVICE_ID"

#define POWER_PIN     5  // GPIO conectado ao transistor (BC337)

void setupWiFi() {
  Serial.print("Conectando ao WiFi...");
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Conectado!");
}

bool onPowerState(const String &deviceId, bool &state) {
  if (deviceId == DEVICE_ID) {
    Serial.print("Comando recebido: ");
    Serial.println(state ? "Ligar PC" : "Desligar (ignorado)");

    if (state) {
      digitalWrite(POWER_PIN, HIGH);
      delay(500); // simula aperto do botão por 0,5s
      digitalWrite(POWER_PIN, LOW);
    }
    return true;
  }
  return false;
}

void setupSinric() {
  SinricProSwitch &meuSwitch = SinricPro[DEVICE_ID];
  meuSwitch.onPowerState(onPowerState);

  SinricPro.onConnected([]() { Serial.println("SinricPro conectado!"); });
  SinricPro.onDisconnected([]() { Serial.println("SinricPro desconectado!"); });

  SinricPro.begin(APP_KEY, APP_SECRET);
  SinricPro.restoreDeviceStates(true);
}

void setup() {
  Serial.begin(115200);
  pinMode(POWER_PIN, OUTPUT);
  digitalWrite(POWER_PIN, LOW);

  setupWiFi();
  setupSinric();
}

void loop() {
  SinricPro.handle();
}
