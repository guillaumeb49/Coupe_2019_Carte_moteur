/*
 * A_TCP.c
 *
 *  Created on: 5 August 2018
 *      Author: guillaume
 */

#include "A_TCP.h"





void F_TCP_paquetTocmd(struct pbuf *p, struct tcp_command *s_cmd_received)
{
	uint8_t *tempPtr;
	uint8_t i = 0;
	tempPtr = (uint8_t *)p->payload;
	volatile uint8_t tab_reveived[20] = {0};

	for(i=0; i<(p->len);i++)
	{

		tab_reveived[i] = (uint8_t) *(tempPtr++);

	}

	s_cmd_received->id = (uint32_t)((tab_reveived[0] << 24) + (tab_reveived[1] << 16) + (tab_reveived[2] << 8) + tab_reveived[3]);
	s_cmd_received->nb_octet = tab_reveived[4];
	s_cmd_received->nb_param = tab_reveived[5];
	s_cmd_received->params[0] = (uint16_t)((tab_reveived[6] << 8) + tab_reveived[7]);
	s_cmd_received->params[1] = (uint16_t)((tab_reveived[8] << 8) + tab_reveived[9]);
	s_cmd_received->params[2] = (uint16_t)((tab_reveived[10] << 8) +tab_reveived[11]);
	s_cmd_received->params[3] = (uint16_t)((tab_reveived[12] << 8) + tab_reveived[13]);

}

void F_TCP_cmdTotab(uint8_t *array, struct tcp_command *s_cmd_to_send)
{
	uint8_t i = 0, j = 0;

	array[0] = (uint8_t)(0x000F & (s_cmd_to_send->id >> 24));
	array[1] = (uint8_t)(0x000F & (s_cmd_to_send->id >> 16));
	array[2] = (uint8_t)(0x000F & (s_cmd_to_send->id >> 8));
	array[3] = (uint8_t)(0x000F & s_cmd_to_send->id);
	array[4] = s_cmd_to_send->nb_octet;
	array[5] = s_cmd_to_send->nb_param;

	for(i=0;i<s_cmd_to_send->nb_param;i++)
	{
		array[6+j] = (uint8_t)(0x000F & (s_cmd_to_send->params[i] >> 8));
		array[6+j+1] = (uint8_t)(0x000F & s_cmd_to_send->params[i]);

		j+=2;
	}


}


/*void F_TCP_cmdTopaquet(struct pbuf *p, struct tcp_command *s_cmd_to_send)
{

	s_cmd_received->id = ((u8_t *)(p->payload) <<  24) + ((u8_t *)(p->payload + 1) <<  16) ((u8_t *)(p->payload + 2) <<  8) + ((u8_t *)(p->payload + 3));
	s_cmd_received->nb_octet = ((u8_t *)(p->payload + 4));
	s_cmd_received->nb_param = ((u8_t *)(p->payload + 5));
	s_cmd_received->params[0] = ((u8_t *)(p->payload + 6) << 8) + ((u8_t *)(p->payload + 7));
	s_cmd_received->params[1] = ((u8_t *)(p->payload + 8) << 8) + ((u8_t *)(p->payload + 9));
	s_cmd_received->params[2] = ((u8_t *)(p->payload + 10) << 8) + ((u8_t *)(p->payload + 11));
	s_cmd_received->params[3] = ((u8_t *)(p->payload + 12) << 8) + ((u8_t *)(p->payload + 13));


}*/

uint8_t F_TCP_send_command(struct tcp_command s_cmd)
{
	uint8_t err = 0;

	uint8_t data_to_send[14] = {0};

	F_TCP_cmdTotab(data_to_send, &s_cmd);

	err = tcp_write(tcp_echoserver_pcb, data_to_send, 14, 1);

	return err;
}
