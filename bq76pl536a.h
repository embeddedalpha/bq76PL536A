/*
 * bq76pl536a.h
 *
 *  Created on: Feb 27, 2021
 *      Author: Kunal Salvi
 *     Company: Blackshield Engineering
 */

#ifndef BQ76PL536A_BQ76PL536A_H_
#define BQ76PL536A_BQ76PL536A_H_

//PINS
/*
 * CONV_H	OUTPUT
 * DRDY_H	INPUT
 * ALERT_H	INPUT
 * FAULT_H	INPUT
 * SCLK_H	OUTPUT
 * MOSI_H	OUTPUT
 * MISO_H	INPUT
 * CS_H	    OUTPUT
 *
 * CONV_N	OUTPUT
 * DRDY_N	INPUT
 * ALERT_N	INPUT
 * FAULT_N	INPUT
 * SCLK_N	OUTPUT
 * MOSI_N	OUTPUT
 * MISO_N	INPUT
 * CS_N  	OUTPUT
 *
 * CONV_S	OUTPUT
 * DRDY_S	INPUT
 * ALERT_S	INPUT
 * FAULT_S	INPUT
 * SCLK_S	OUTPUT
 * MOSI_S	OUTPUT
 * MISO_S	INPUT
 * CS_S  	OUTPUT
 *
 */



//REGISTERS

#define DEVICE_STATUS	      0x00
#define GPAI_1                0x01
#define GPAI_2                0x02
#define VCELL1_1              0x03
#define VCELL1_2              0x04
#define VCELL2_1              0x05
#define VCELL2_2              0x06
#define VCELL3_1              0x07
#define VCELL3_2              0x08
#define VCELL4_1              0x09
#define VCELL4_2              0x0A
#define VCELL5_1              0x0B
#define VCELL5_2              0x0C
#define VCELL6_1              0x0D
#define VCELL6_2              0x0E
#define TEMP_1                0x0F
#define TEMP_2                0x10

#define ALERT_STATUS          0x20
#define FAULT_STATUS          0x21
#define COV_FAULT             0x22
#define CUV_FAULT             0x23
#define PRESULT_A             0x24
#define PRESULT_B             0x25

#define ADC_CONTROL           0x30
#define IO_CONTROL            0x31
#define CB_CTRL               0x32
#define CB_TIME               0x33
#define ADC_CONVERT           0x34
#define SHDW_CTRL             0x3A
#define ADDRESS_CONTROL       0x3B
#define RESET                 0x3C
#define TEST_SELECT           0x3D
#define E_EN                  0x3F

#define FUNCTION_CONFIG       0x40
#define IO_CONFIG             0x41
#define CONFIG_COV            0x42
#define CONFIG_COVT           0x43
#define CONFIG_CUV            0x44
#define CONFIG_CUVT           0x45
#define CONFIG_OT             0x46
#define CONFIG_OTT            0x47
#define USER1                 0x48
#define USER2                 0x49
#define USER3                 0x4A
#define USER4                 0x4B


void init_BQ76PL(SPI_TypeDef *SPI);

void read_BQ76PL(SPI_TypeDef *SPI, uint8_t address, uint8_t reg_addr, uint8_t count, uint8_t *buffer);

void write_BQ76PL(SPI_TypeDef *SPI, uint8_t address, uint8_t reg_adde, uint8_t data);


void broadcast_BQ76PL(SPI_TypeDef *SPI, uint8_t inst, uint8_t data);


//Application

//Device Address Discovery and Assignment
//Returns the number of devices in the stack and assigns address to each one of them
uint8_t assign_address_BQ76PL(SPI_TypeDef *SPI, uint8_t *address);

uint16_t read_GPAI_BQ76PL(SPI_TypeDef *SPI, uint8_t address);

uint16_t read_Cell_1_BQ76PL(SPI_TypeDef *SPI, uint8_t address);
uint16_t read_Cell_2_BQ76PL(SPI_TypeDef *SPI, uint8_t address);
uint16_t read_Cell_3_BQ76PL(SPI_TypeDef *SPI, uint8_t address);
uint16_t read_Cell_4_BQ76PL(SPI_TypeDef *SPI, uint8_t address);
uint16_t read_Cell_5_BQ76PL(SPI_TypeDef *SPI, uint8_t address);
uint16_t read_Cell_6_BQ76PL(SPI_TypeDef *SPI, uint8_t address);


uint16_t read_Temp_1_BQ76PL(SPI_TypeDef *SPI, uint8_t address);
uint16_t read_Temp_2_BQ76PL(SPI_TypeDef *SPI, uint8_t address);

//To be used within ISR and ALERT_H pin as Interrupt pin
//This function gives the ID of cell which goes faulty.
uint16_t COV_fault_cell(SPI_TypeDef *SPI);
uint16_t CUV_fault_cell(SPI_TypeDef *SPI);



#endif /* BQ76PL536A_BQ76PL536A_H_ */
