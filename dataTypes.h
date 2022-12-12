// Data Types

typedef unsigned int u32;
typedef unsigned short int u16;
typedef signed int s32;
typedef signed short int s16;
typedef unsigned char u8;

typedef struct patients patient;

struct patients {
	u32 id;
	u8 *name[50];
	u8 age;
	u8 *gender[10];
	patient *next;
};



