# Watchdog
![Arduino IDE](https://img.shields.io/badge/Arduino_IDE-00979D?style=flat&logo=arduino&logoColor=white)
![C++](https://img.shields.io/badge/C++-00599C?style=flat&logo=cplusplus&logoColor=white)
![Wokwi](https://img.shields.io/badge/Wokwi-Simulator-blue)
![IIoT](https://img.shields.io/badge/IIoT-Industrial_Internet_of_Things-darkgreen)

## Sobre
Projeto desenvolvido com o objetivo de aplicar conceitos de HTTP em IoT, considerando o seguinte cenário:

A fábrica TechMec Automação migrou o monitoramento de suas máquinas injetoras para um servidor na nuvem. Caso o servidor fique indisponível ou a conexão com a internet da fábrica falhe, os operadores devem ser notificados imediatamente para evitar a perda de dados críticos de produção.

Nesse contexto, a aplicação realiza testes contínuos de conectividade com a rede Wi-Fi e com o servidor.

Disciplina ministrada pela professora [Yuri Komuta](https://www.linkedin.com/in/yurikomuta/)

## Descrição
O projeto consiste em um circuito físico que reage ao estado da conexão Wi-Fi e ao resultado de requisições HTTP.

Quando há conexão com a rede e a requisição é bem-sucedida, o LED verde é acionado. Caso não haja conexão com o Wi-Fi ou a requisição falhe, o LED vermelho é acionado.

## Demostração
Funcionamento do projeto em vídeo:
- [Vídeo](https://youtube.com/shorts/UQCQxwXQ4ss?si=CWd65OeMCK_BbvBV)

## Ferramentas
- C++
- Arduino IDE
- Wokwi
- ESP32


## Autor
- [Breno Reis](https://www.linkedin.com/in/breno-oliveira-assis-reis-203010351/)
