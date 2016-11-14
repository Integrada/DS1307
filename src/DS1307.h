#ifndef DS1307_H_

#define DS1307_H_

#define DS1307_SECOND    0x00
#define DS1307_MINUTE    0x01
#define DS1307_HOUR      0x02
#define DS1307_WEEK      0x03
#define DS1307_DAY       0x04
#define DS1307_MONTH     0x05
#define DS1307_YEAR      0x06

typedef struct
{
  unsigned short year;      //0..99
  unsigned short month;     //1..12
  unsigned short day;       //1..31
  unsigned short week;      //1..7
  unsigned short hour;      //0..23
  unsigned short min;       //0..59
  unsigned short sec;       //0..59
} TIME_STRUCT;

void DS1307_Init();

void DS1307_SetDate(TIME_STRUCT *);

void DS1307_GetDate(TIME_STRUCT *);

TIME_STRUCT DS1307_Now();

TIME_STRUCT DS1307_GetNow();

#endif
