#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define SERVO_PIN 22   
#define LED_PIN 12      
#define PWM_WRAP 20000  // Contador máximo do PWM para 50Hz (20ms)

// Função para configurar o PWM o LED
void inicializador_pwm() {
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);  // Habilita a GPIO como PWM para o servo
    gpio_set_function(LED_PIN, GPIO_FUNC_PWM);    // Habilita a GPIO como PWM para o LED

    uint slice_servo = pwm_gpio_to_slice_num(SERVO_PIN);
    uint slice_led = pwm_gpio_to_slice_num(LED_PIN);

    pwm_set_clkdiv(slice_servo, 125.0);  // Configura o clock PWM para 50Hz (20ms)
    pwm_set_wrap(slice_servo, PWM_WRAP);
    pwm_set_enabled(slice_servo, true);

    pwm_set_clkdiv(slice_led, 125.0);  // Mesmo clock PWM para o LED
    pwm_set_wrap(slice_led, PWM_WRAP);
    pwm_set_enabled(slice_led, true);
}

// Função para definir a posição do servomotor e ajustar o brilho do LED
void posicao_servo(uint slice, uint slice_led, uint16_t pulse_width_us) {
    uint duty_cycle = (pulse_width_us * PWM_WRAP) / 20000;  // Converte o pulso em µs para o ciclo de trabalho do PWM
    pwm_set_gpio_level(SERVO_PIN, duty_cycle);  // Define o PWM do servo

    uint led_brightness = (pulse_width_us - 500) * (PWM_WRAP / 2400); // Mapeia o brilho do LED proporcionalmente ao ângulo do servo
    pwm_set_gpio_level(LED_PIN, led_brightness); // Ajusta o brilho do LED
}

int main() {
    stdio_init_all();   
    inicializador_pwm();  // Configura PWM e LED

    uint slice_servo = pwm_gpio_to_slice_num(SERVO_PIN);
    uint slice_led = pwm_gpio_to_slice_num(LED_PIN);

    while (true) {
        // Ajusta a posição para 180° (pulso de 2400µs)
        posicao_servo(slice_servo, slice_led, 2400);
        sleep_ms(5000);

        // Ajusta a posição para 90° (pulso de 1470µs)
        posicao_servo(slice_servo, slice_led, 1470);
        sleep_ms(5000);

        // Ajusta a posição para 0° (pulso de 500µs)
        posicao_servo(slice_servo, slice_led, 500);
        sleep_ms(5000);

        // Movimentação entre 0° e 180° com ajuste do brilho do LED
        for (int i = 500; i <= 2400; i += 5) {
            posicao_servo(slice_servo, slice_led, i);
            sleep_ms(10);
        }
        for (int i = 2400; i >= 500; i -= 5) {
            posicao_servo(slice_servo, slice_led, i);
            sleep_ms(10);
        }
    }

    return 0;
}