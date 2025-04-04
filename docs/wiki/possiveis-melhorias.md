# 🚀 Possíveis Melhorias

Algumas ideias para aprimorar o projeto:

## 📴 Desligamento via ESP32
- Pressionar o botão por mais de 4 segundos simula um "force shutdown".
- Pode-se programar o ESP32 para enviar esse sinal longo com um segundo comando Alexa.

## 📶 Leitura do Estado do PC
- Use uma linha 5V (ex: USB) para detectar se o PC está ligado.
- Um divisor de tensão pode proteger o GPIO do ESP32.
- Isso permite atualizar o status real do PC na Alexa.

## 🔁 Feedback Inteligente para Alexa
- Com Sinric Pro, é possível atualizar o estado do dispositivo remotamente (`device.setPowerState()`).
- Isso melhora a interação com a Alexa e evita comandos redundantes.
