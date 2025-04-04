# Como funciona o circuito

Este projeto utiliza o ESP32 para acionar eletronicamente os botões de **Power** e **Reset** de um computador desktop, permitindo que esses comandos sejam disparados remotamente (ex: via Alexa).

## Funcionamento básico

- **GPIO 5** do ESP32 controla o botão **Power**;
- **GPIO 4** controla o botão **Reset**;
- Cada GPIO é ligado a um resistor de base (1kΩ) que aciona a base de um transistor **BC337**;
- O **BC337** atua como chave, permitindo ou não o contato entre o terminal do botão (PWR_SW / RESET_SW) e o **GND** do sistema;
- O botão físico continua funcionando normalmente, pois os transistores estão ligados em paralelo com os botões da placa-mãe.

## Segurança

- O circuito está isolado da alimentação principal do PC;
- Os GPIOs nunca ficam diretamente conectados aos terminais da placa-mãe;
- Os transistores atuam por chaveamento com resistência na base, evitando sobrecorrente.
