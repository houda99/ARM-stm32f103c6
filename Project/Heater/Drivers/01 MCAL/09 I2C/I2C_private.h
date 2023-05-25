/*
 * I2C_private.h
 *
 *  Created on: May 17, 2023
 *      Author: Mohamed Dwedar
 */

#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_

typedef struct{
	u32 CR1;
	u32 CR2;
	u32 OAR1;
	u32 ORA2;
	u32 DR;
	u32 SR1;
	u32 SR2;
	u32 CCR;
	u32 TRISE;
}I2C_type;

#define I2C1          ((volatile I2C_type *)(0x40005400))


// I2C CR1 register
#define CR1_PE            0
#define CR1_SMBUS         1
#define CR1_SMBTYPE       3
#define CR1_ENAARP        4
#define CR1_ENPEC         5
#define CR1_ENGC          6
#define CR1_NOSTRETCH     7
#define CR1_START         8
#define CR1_STOP          9
#define CR1_ACK           10
#define CR1_POS           11
#define CR1_PEC           12
#define CR1_ALERT         13
#define CR1_SWRST         15

// I2C CR2 register
#define CR2_FREQ         0
#define CR2_ITERREN      8
#define CR2_ITEVTEN      9
#define CR2_ITBUFEN      10
#define CR2_DMAEN        11
#define CR2_LAST         12


// I2C OAR1
#define OAR1_ADD0         0
#define OAR1_ADD          1
#define OAR1_ADDMODE      15

// I2C OAR2
#define OAR1_ENDUAL       0
#define OAR1_ADD2         1




// I2C SR1
#define SR1_SB           0
#define SR1_ADDR         1
#define SR1_BTF          2
#define SR1_ADD10        3
#define SR1_STOPF        4
#define SR1_RXEN         6
#define SR1_TXE          7
#define SR1_BERR         8
#define SR1_ARLO         9
#define SR1_AF           10
#define SR1_OVR          11
#define SR1_PECERR       12
#define SR1_TIMEOUT      14
#define SR1_SMBALERT     15

// I2C SR2
#define SR2_MSL          0
#define SR2_BUZY         1
#define SR2_TRA          2
#define SR2_GENCALL      4
#define SR2_SMBDEFAULT   5
#define SR2_SMBHOST      6
#define SR2_DUALF        7
#define SR2_PEC          8

// I2C CCR
#define CCR_CCR          0
#define CCR_DUTY         14
#define CCR_FS           15




#endif /* 01_MCAL_09_I2C_I2C_PRIVATE_H_ */
