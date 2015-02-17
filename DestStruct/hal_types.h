/***********************************************************************************
    Filename: hal_types.h

 
***********************************************************************************/

#ifndef HAL_TYPES_H_
#define HAL_TYPES_H_


#define Big_Endium

//#define Little_Endium

//----------------------------------------------------------------------------------
// Types
//----------------------------------------------------------------------------------


#ifndef TRUE
#define TRUE       1 /*!< It's true in boolean operations. */
#endif

#ifndef FALSE
#define FALSE      0 /*!< It's false in boolean operations. */
#endif

#ifndef NULL
#define NULL ((void *)0 )
#endif

typedef signed   char   int8;
typedef unsigned char   uint8;

typedef signed   short  int16;
typedef unsigned short  uint16;

typedef signed   long   int32;
typedef unsigned long   uint32;

typedef unsigned long	uint64;



typedef unsigned char BOOLEAN;                  /*!<  1 bit  basic type */
typedef unsigned char BYTE;                     /*!<  8 bits basic type */
typedef unsigned short WORD;                    /*!< 16 bits basic type */
typedef unsigned long DWORD;                    /*!< 32 bits basic type */

typedef unsigned char	UBYTE;
typedef unsigned int	UWORD;
typedef unsigned long	ULONG;
typedef signed char		SBYTE;
//typedef signed int		SWORD;  //ÖØ¸´¶¨Òå SWORD
typedef signed long		SLONG;


#ifdef Big_Endium

typedef union {
     uint16 w;
     struct {
       uint8 high,low;    //it is big endium format
     } b;
     
} uuint16;

typedef union {
     uint32 dw;
     struct {
       uint16 highw,loww;    //it is big endium format
     } w;
     struct {
       uint8 hhigh,lhigh, hlow, llow;    //it is big endium format
     } b;
     
} uuint32;

#else		//Little_Endium

typedef union {
     uint16 w;
     struct {
       uint8 low,high;    //it is little endium format
     } b;
    
     
} uuint16;


typedef union {
     uint32 dw;
     struct {
       uint16 loww,highw;    //it is little endium format
     } w;
     struct {
       uint8 llow, hlow, lhigh, hhigh;    //it is little endium format
     } b;
     
     
} uuint32;
#endif


/**********************************************************************************/
#endif
