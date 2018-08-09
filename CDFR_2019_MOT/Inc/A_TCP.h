/*
 * A_TCP.h
 *
 *  Created on: 5 août 2018
 *      Author: guillaume
 */

#ifndef A_TCP_H_
#define A_TCP_H_

#include "tcp_server.h"

/* structure that represents a command between the Raspberry Pi and the STM32*/
struct tcp_command
{

	uint32_t id;
	uint8_t nb_octet;
	uint8_t nb_param;
	uint16_t params[4];
};


void F_TCP_paquetTocmd(struct pbuf *p, struct tcp_command *s_cmd_received);
void F_TCP_cmdTotab(uint8_t *array, struct tcp_command *s_cmd_to_send);
uint8_t F_send_TCP_command(struct tcp_command s_cmd, struct tcp_pcb *tcp_server_pcb);

#endif /* A_TCP_H_ */
