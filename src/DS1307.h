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
  unsigned short ss;       // seconds
  unsigned short mn;       // minutes
  unsigned short hh;       // hours
  unsigned short md;       // day in month, from 1 to 31
  unsigned short wd;       // day in week, sunday=1, monday=2, .... sunday=7
  unsigned short mo;       // month number, from 1 to 12 (and not from 0 to 11 as with unix C time !)
  unsigned short yy;       // year Y2K compliant, from 1892 to 2038
} TimeStruct;

void DS1307_Init();
void DS1307_SetDate(TimeStruct *);
void DS1307_GetDate(TimeStruct *);
void DS1307_Loop(unsigned short);
TimeStruct DS1307_Now();
long DS1307_Timestamp();


#endif
