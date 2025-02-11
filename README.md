# Controle de Servo Motor e LED com Raspberry Pi Pico W

 ## Sobre o Projeto

Este projeto demonstra o uso do PWM no Raspberry Pi Pico W para controlar um servomotor e um LED azul simultaneamente. O sistema faz com que o servo se mova suavemente entre 0° e 180°, ajustando o brilho do LED de acordo com o ângulo do servo.

 ## Componentes Utilizados

Microcontrolador: Raspberry Pi Pico W

Servomotor padrão Conectado à GPIO 22

LED Azul – Conectado à GPIO 12

Resistor de 330Ω – Limitador de corrente para o LED

 ## Configuração e Funcionamento

 Configuração do PWM na GPIO 22

A frequência do PWM é configurada para 50Hz, resultando em um período de 20ms.

O ciclo ativo do PWM varia para ajustar a posição do servo.

O servo é movido para 180°,90° e  0°, onde permanece por 5 segundos em cada posicao.

Movimento Suave entre 0° e 180°

Após a movimentação inicial, o servo oscila continuamente entre 0° e 180°.

Para garantir suavidade, o ciclo ativo do PWM é incrementado/decrementado em 5µs por iteração.

## Controle do LED Azul com PWM

O LED azul está conectado à GPIO 12 e também é controlado via PWM.

O brilho do LED é ajustado proporcionalmente ao ângulo do servomotor.

## Uso do Projeto

O servomotor se move suavemente entre 0° e 180°.

O LED azul altera seu brilho conforme o ângulo do servo.

O movimento do servo é controlado por PWM com incrementos de 5µs.

O LED e o servo são sincronizados para um efeito visual interativo.

 ## Ferramenta BitDogLab

Para validar o comportamento do sistema, foi realizado um experimento utilizando a BitDogLab, onde se observou:

O comportamento do LED RGB (GPIO 12) variando sua intensidade de brilho conforme o ângulo do servomotor.

