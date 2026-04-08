# SISTEMA-LORA-P2P
controle remoto via LoRa em longo alcance

[README.txt](https://github.com/user-attachments/files/26579621/README.txt)
LoRa P2P Automation Project

Descrição:
Sistema simples de automação usando LoRa P2P com múltiplos dispositivos.

Componentes:
- ESP32 + LoRa SX1278
- Relé

Estrutura:
- transmitter.ino → envia comandos
- receiver.ino → recebe e aciona relé

Formato de comando:
ID:COMANDO
Ex: 01:ON

Melhorias futuras:
- ACK (confirmação)
- Interface web
- Segurança com chave
- Integração com sistema AVS
