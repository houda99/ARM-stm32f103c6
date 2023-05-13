#ifndef		RCC_PRIVATE_H
#define		RCC_PRIVATE_H

#define		RCC_BASE_ADD		(0x40021000)

#define		RCC_CR				*((u32 *)(RCC_BASE_ADD+0x00))
#define		RCC_CFGR			*((u32 *)(RCC_BASE_ADD+0x04))
#define		RCC_CIR				*((u32 *)(RCC_BASE_ADD+0x08))
#define		RCC_APB2RSTR		*((u32 *)(RCC_BASE_ADD+0x0C))
#define		RCC_APB1RSTR		*((u32 *)(RCC_BASE_ADD+0x10))
#define		RCC_AHBENR			*((u32 *)(RCC_BASE_ADD+0x14))
#define		RCC_APB2ENR			*((u32 *)(RCC_BASE_ADD+0x18))
#define		RCC_APB1ENR			*((u32 *)(RCC_BASE_ADD+0x1C))
#define		RCC_BDCR			*((u32 *)(RCC_BASE_ADD+0x20))
#define		RCC_CSR				*((u32 *)(RCC_BASE_ADD+0x24))

// Clocks macros
#define    RCC_HSI 		        0
#define    RCC_HSE			    1
#define    RCC_PLL			    2

// HSI configurations
#define RCC_CR_HSI_ON			SET_BIT(RCC_CR,0)
#define RCC_CR_HSI_ON_RDY		GET_BIT(RCC_CR,1)
#define RCC_CFGR_SW_HSI1		CLR_BIT(RCC_CFGR,0)
#define RCC_CFGR_SW_HSI2		CLR_BIT(RCC_CFGR,1)
#define RCC_CFGR_SWS_HSI1		GET_BIT(RCC_CFGR,0)
#define RCC_CFGR_SWS_HSI2		GET_BIT(RCC_CFGR,1)
// HSE configurations
#define RCC_CR_HSE_ON			SET_BIT(RCC_CR,16)
#define RCC_CR_HSE_ON_RDY		GET_BIT(RCC_CR,17)
#define RCC_CFGR_SW_HSE1		SET_BIT(RCC_CFGR,0)
#define RCC_CFGR_SW_HSE2		SET_BIT(RCC_CFGR,1)
#define RCC_CFGR_SWS_HSE 		GET_BIT(RCC_CFGR,2)
// PLL configurations
#define RCC_CFGR_PLL_SRC		SET_BIT(RCC_CFGR,16)
#define RCC_CFGR_PLL_XTPRE		SET_BIT(RCC_CFGR,17)
#define RCC_CR_PLL_ON			SET_BIT(RCC_CR,24)
#define RCC_CR_PLL_ON_RDY		GET_BIT(RCC_CR,25)
#define RCC_CFGR_SW_PLL1		SET_BIT(RCC_CFGR,1)
#define RCC_CFGR_SW_PLL2		CLR_BIT(RCC_CFGR,0)
#define RCC_CFGR_SWS_PLL		GET_BIT(RCC_CFGR,2)


#endif
