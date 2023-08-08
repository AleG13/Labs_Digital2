#include <xc.h>
#include <stdint.h>
#include "I2C.h" // Header que contiene las funciones para la comunicación I2C

// Dirección I2C del módulo RTC DS3231
#define RTC_I2C_ADDRESS 0x68

// Registro que contiene los segundos en el módulo RTC DS3231
#define RTC_SECONDS_REGISTER 0x00

void I2C_Init() {
    // Configurar el módulo I2C en el PIC16F887 (ajusta los valores según sea necesario)
    // Consulta el datasheet del PIC para obtener más información sobre estos registros.
    SSPCON = 0b00101000;   // Habilitar el modo I2C maestro, velocidad de 100 kHz
    SSPADD = 49;            // Valor para una frecuencia de reloj de 4 MHz
    SSPSTAT = 0;
    TRISC3 = 1;             // Configurar los pines de SCL y SDA como entradas
    TRISC4 = 1;
}

void I2C_Start() {
    SEN = 1;                // Iniciar condición de inicio
    while (SEN);            // Esperar hasta que se complete el inicio
}

void I2C_Stop() {
    PEN = 1;                // Iniciar condición de parada
    while (PEN);            // Esperar hasta que se complete la parada
}

void I2C_Write(uint8_t data) {
    SSPBUF = data;          // Escribir un byte en el registro de búfer de transmisión
    while (SSPIF == 0);     // Esperar hasta que se complete la transmisión
    SSPIF = 0;              // Borrar la bandera de interrupción de I2C
}

uint8_t I2C_Read() {
    RCEN = 1;               // Habilitar la recepción de datos
    while (!BF);            // Esperar hasta que se reciba un byte
    return SSPBUF;          // Leer el byte recibido desde el búfer de recepción
}

void RTC_GetTime(uint8_t *seconds) {
    I2C_Start();                        // Iniciar la comunicación I2C
    I2C_Write(RTC_I2C_ADDRESS << 1);    // Dirección de escritura del módulo RTC
    I2C_Write(RTC_SECONDS_REGISTER);    // Seleccionar el registro de segundos en el RTC
    I2C_Stop();                         // Detener la transmisión
    
    I2C_Start();                        // Iniciar la comunicación I2C nuevamente
    I2C_Write((RTC_I2C_ADDRESS << 1) | 1); // Dirección de lectura del módulo RTC
    
    *seconds = I2C_Read();              // Leer los segundos del RTC
    
    I2C_Stop();                         // Detener la transmisión
}

void main() {
    uint8_t seconds;
    
    I2C_Init();     // Inicializar el módulo I2C del PIC16F887
    
    // Bucle principal
    while (1) {
     RTC_GetTime(&seconds);  // Obtener los segundos del RTC
        // Aquí puedes realizar cualquier acción con los segundos leídos.
     PORTD = I2C_Read();   
    }
}