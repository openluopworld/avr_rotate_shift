
/*
 * Implementation of rotate shift left (or right) by several bit positions of MSP
 * The first number is shift bit positions, and the second number is the size(in bits) of a block.
 * For example, rot_left_1_16 means a 16-bit block is rotated shift left  by 1 bit position.
 * 		rot_right_3_32 means a 32-bit block is rotated shift right  by 3 bit positions.
 * 
 * Author: LuoPeng
 * Time:   2016.01.02
 */

/*
 * For 16-bit block.
 * s0:		16-bit registers.
 */
#define ONE #1
#define DZDF #0x00ff
/* ------------------------------------ */
/* 	Basic Operations for 16-bit 	*/
/* ------------------------------------ */
/* 	Instrcutions	Cycles		*/
/* 	2				*/
#define rot_left_1_16(s0)		\
	rla s0			\n\t	\
	adc s0			\n\t

/* 	1				*/
#define rot_left_8_16(s0)		\
	swpb s0			\n\t

/* 	2				*/
#define rot_right_1_16(s0)		\
	bit ONE, s0		\n\t	\
	rrc s0			\n\t

/* 	1				*/
#define rot_right_8_16(s0)		\
	swpb s0			\n\t

/* ------------------------------------ */
/* 	Call 16-bit Basic Operations 	*/
/* ------------------------------------ */
/* 	4				*/
#define rot_left_2_16(s0)		\
	rot_left_1_16(s0)		\
	rot_left_1_16(s0)

/* 	6				*/
#define rot_left_3_16(s0)		\
	rot_left_1_16(s0)		\
	rot_left_1_16(s0)		\
	rot_left_1_16(s0)

/* 	8				*/
#define rot_left_4_16(s0)		\
	rot_left_1_16(s0)		\
	rot_left_1_16(s0)		\
	rot_left_1_16(s0)		\
	rot_left_1_16(s0)

/* 	7				*/
#define rot_left_5_16(s0)		\
	rot_right_8_16(s0)		\
	rot_left_1_16(s0)		\
	rot_left_1_16(s0)		\
	rot_left_1_16(s0)

/* 	5				*/
#define rot_left_6_16(s0)		\
	rot_right_8_16(s0)		\
	rot_left_1_16(s0)		\
	rot_left_1_16(s0)

/* 	3				*/
#define rot_left_7_16(s0)		\
	rot_right_8_16(s0)		\
	rot_left_1_16(s0)

/* 	4				*/
#define rot_right_2_16(s0)		\
	rot_right_1_16(s0)		\
	rot_right_1_16(s0)

/* 	6				*/
#define rot_right_3_16(s0)		\
	rot_right_1_16(s0)		\
	rot_right_1_16(s0)		\
	rot_right_1_16(s0)

/* 	8				*/
#define rot_right_4_16(s0)		\
	rot_right_1_16(s0)		\
	rot_right_1_16(s0)		\
	rot_right_1_16(s0)		\
	rot_right_1_16(s0)

/* 	7				*/
#define rot_right_5_16(s0)		\
	rot_left_8_16(s0)		\
	rot_right_1_16(s0)		\
	rot_right_1_16(s0)		\
	rot_right_1_16(s0)

/* 	5				*/
#define rot_right_6_16(s0)		\
	rot_left_8_16(s0)		\
	rot_right_1_16(s0)		\
	rot_right_1_16(s0)

/* 	3				*/
#define rot_right_7_16(s0)		\
	rot_left_8_16(s0)		\
	rot_right_1_16(s0)
/* ------------------------------------ */
/* 		16-bit End 		*/
/* ------------------------------------ */


/*
 * For 32-bit block.
 * s0, s1:		16-bit registers. s1 is the higher word, and s0 is the lower word. 
 */
/* ------------------------------------ */
/* 	Basic Operations for 32-bit 	*/
/* ------------------------------------ */
/* 	Instrcutions	Cycles		*/
/* 	3				*/
#define rot_left_1_32(s0, s1)		\
	rla s0			\n\t	\
	rlc s1			\n\t	\
	adc s0			\n\t

/* 	7				*/
#define rot_left_8_32(s0, s1, t0)	\
	swpb s0			\n\t	\
	swpb s1			\n\t	\
	mov s1, t0		\n\t	\
	xor s0, t0		\n\t	\
	and DZDF, t0		\n\t	\
	xor t0, s0		\n\t	\
	xor t0, s1		\n\t

/* 	3				*/ 
/* Sometimes, s0 and s1 may be used in place. Therefore, no instructions are needed.*/
#define rot_left_16_32(s0, s1)		\
	xor s0, s1		\n\t	\
	xor s1, s0		\n\t	\
	xor s0, s1		\n\t

/* 	3				*/
#define rot_right_1_32(s0, s1, s2, s3)	\
	bit ONE, s0		\n\t	\
	rrc s1			\n\t	\
	rrc s0			\n\t

/* 	7				*/
#define rot_right_8_32(s0, s1, t0)	\
	rot_left_8_32(s0, s1, t0)	\

/* 	3				*/
#define rot_right_16_32(s0, s1)		\
	rot_left_16_32(s0, s1)		\

/* ------------------------------------ */
/* 	Call 32-bit Basic Operations 	*/
/* ------------------------------------ */

/* ------------------------------------ */
/* 		32-bit End 		*/
/* ------------------------------------ */
