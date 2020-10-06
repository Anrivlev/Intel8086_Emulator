#ifndef CPU_H
#define CPU_H
#include <iostream>

#define	RAM_MEMORY	0x100000 ////оперативная память, почему именно таким замещается???????????

//Registers
#define	AX	0x00 //accumulator
#define	CX	0x01 //count register
#define	DX	0x02 //data register
#define	BX	0x03 //base register
#define	SP	0x04 //stek pointer
#define	BP	0x05 //base pointer
#define	SI	0x06 //sourse index
#define	DI	0x07 //destination index

#define	AL	0x00
#define CL	0x01
#define DL	0x02
#define BL	0x03
#define AH	0x04
#define CH	0x05
#define DH	0x06
#define BH	0x07

//segment register
#define ES	0x00
#define CS	0x01
#define SS	0x02
#define DS	0x03


typedef struct _8086_cpu_arch {
	union _reg {
		uint16_t reg16[8]; //AX, CX, DX, BX, SP, BP, SI, DI
		uint8_t  reg8[8];  //[AL, AH], [CL, CH], [DL, DH], [BL, BH]
	} reg;

	uint16_t segreg[4];     // ES, CS, SS, DS
	uint16_t IP;            // Instruction Pointer

	// EFLAGS (состоит из 32 разрядов), младшие 16 разрядов - отдельный регистр FLAGS
	union {
		struct {
			uint8_t CF : 1; //флаг переноса
			uint8_t reserved_2 : 1;

			uint8_t PF : 1; //флаг четности
			uint8_t reserved_4 : 1;

			uint8_t AF : 1; ////флаг доп.переноса (поддерживает специальное двоично-десятичное число?????)
			uint8_t reserved_6 : 1;

			uint8_t ZF : 1; //нуля
			uint8_t SF : 1; //знака
			uint8_t TF : 1; //трассировки
			uint8_t IF : 1; //прерывания
			uint8_t DF : 1; //флаг направления
			uint8_t OF : 1; //переполнения

			uint8_t reserved_13 : 1;
			uint8_t reserved_14 : 1;
			uint8_t reserved_15 : 1;
			uint8_t reserved_16 : 1;

		} bit;

		int16_t value;
	} flags;

//	uint8_t current_op; ////текущий операнд??
//	bool    jmp_taken;
//	bool    unsupported_op; ////неподдерживаемый операнд??
//	bool    hlt_suspend; ////прерывание приостановлено??

	uint8_t *memory;

} _8086_cpu, *i8086_cpu;

i8086_cpu cpu_initialization();

void cpu_reset(i8086_cpu instruction);

void set_segreg(i8086_cpu cpu, size_t reg, uint16_t value);
void set_reg16(i8086_cpu cpu, int reg, uint16_t value);
void set_reg8(i8086_cpu cpu, int reg, uint8_t value);

uint16_t get_segreg(i8086_cpu cpu, size_t reg);
uint16_t get_reg16(i8086_cpu cpu,size_t reg);
uint8_t get_reg8(i8086_cpu cpu, size_t reg);

#endif // CPU_H
