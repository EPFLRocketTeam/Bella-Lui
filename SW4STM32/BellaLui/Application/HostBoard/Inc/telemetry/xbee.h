/*
 * xbee.h
 *
 *  Created on: 9 Apr 2018
 *      Author: Clément Nussbaumer
 */

#ifndef TELEMETRY_XBEE_XBEE_H_
#define TELEMETRY_XBEE_XBEE_H_

#include "cmsis_os.h"
#include "stm32f4xx_hal.h"

#define XBEE_PAYLOAD_MAX_SIZE 130
#define XBEE_PERFORMANCE_BPS 80000

#ifdef __cplusplus
extern "C" {
#endif

void xbee_freertos_init(UART_HandleTypeDef *huart);
void xbee_change_uart(UART_HandleTypeDef *huart);
void initXbee ();
void TK_xBeeTransmit (const void* args);

void sendData (uint8_t* txData, uint16_t txDataSize);

void sendXbeeFrame ();

void addToBuffer (uint8_t* txData, uint16_t txDataSize);

uint8_t escapedCharacter (uint8_t byte);

/* XBee receive headers */

void TK_xBeeReceive (const void* args);

void xBee_rxCpltCallback ();

void processReceivedPacket ();

void processReceivedByte(uint8_t rxByte);

void resetStateMachine ();

void setPacketSize(uint8_t datagram_id);

#ifdef __cplusplus
}
#endif

#endif /* TELEMETRY_XBEE_XBEE_H_ */
