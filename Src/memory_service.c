/*
 * memory_service.c
 *
 *  Created on: 21 mar 2020
 *      Author: USER
 */
#include "i2c.h"
#include "main.c"
#include "main.h"
#include "gpio.h"

int memory_service()
{
	HAL_I2C_Mem_Write(&hi2c1, 0xa0, (uint16_t*)&mem_addres, 2, (uint16_t*)&test, sizeof(test), HAL_MAX_DELAY);
		  HAL_Delay(20);
		  HAL_I2C_Mem_Read(&hi2c1, 0xa0, (uint16_t*)&mem_addres, 2, (uint16_t*)&result, sizeof(result), HAL_MAX_DELAY);
		  HAL_Delay(20);
		  sprintf(buff_mem, "mem addres nr %d =", mem_addres);
		  sprintf(buff_data, " %d\r\n", result);
		  HAL_UART_Transmit(&huart2, buff_mem, strlen(buff_mem), 20);
		  HAL_UART_Transmit(&huart2, buff_data, strlen(buff_data), 20);
		  if(mem_addres >= 0x80)
		  {
			  test++;
			  mem_addres = 0;
		  }
		  else
		  {
			mem_addres++;
		  }
		  HAL_Delay(10);
}

