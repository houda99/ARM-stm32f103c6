<<<<<<< HEAD
#ifndef		BIT_MATH_H
#define		BIT_MATH_H

#define		SET_BIT(REG,BIT)		(REG|=  (1<<BIT))
#define		CLR_BIT(REG,BIT)		(REG&= ~(1<<BIT))
#define		TOG_BIT(REG,BIT)		(REG^=  (1<<BIT))
#define		GET_BIT(REG,BIT)		((REG>>BIT)&0x01)

//#define		BIT_LOW					((u8)0)
#define low_nibb(x , data)       (x & 0X0F) | (data << 4 )
#define upp_nibb(x , data )      (x & 0x0F) | (data & 0xF0)
#endif
=======
#ifndef		BIT_MATH_H
#define		BIT_MATH_H

#define		SET_BIT(REG,BIT)		(REG|=  (1<<BIT))
#define		CLR_BIT(REG,BIT)		(REG&= ~(1<<BIT))
#define		TOG_BIT(REG,BIT)		(REG^=  (1<<BIT))
#define		GET_BIT(REG,BIT)		((REG>>BIT)&0x01)

//#define		BIT_LOW					((u8)0)
#define low_nibb(x , data)       (x & 0X0F) | (data << 4 )
#define upp_nibb(x , data )      (x & 0x0F) | (data & 0xF0)
#endif
>>>>>>> 81f24b8ec317b796073e6525e6dd9a2900465ae9
