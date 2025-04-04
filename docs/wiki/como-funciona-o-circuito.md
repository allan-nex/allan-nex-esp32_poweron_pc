# 🧠 Como Funciona o Circuito

Este circuito utiliza um transistor NPN (BC337) para simular o acionamento do botão "Power" do PC.

## Funcionamento

- O ESP32 aciona um GPIO configurado (ex: GPIO 5).
- Esse sinal passa por um resistor de 1kΩ e vai até a base do transistor.
- O transistor entra em condução, fechando o circuito entre coletor e emissor.
- Isso simula o pressionamento do botão de ligar da placa-mãe.

É uma solução simples, silenciosa e eficiente, que dispensa o uso de relés.
