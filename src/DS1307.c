#include "DS1307.h"

TIME_STRUCT DS1307_instance = { 16, 9, 15, 5, 11, 15, 13 };

void DS1307_Init()
{
  I2C1_Init(100000);
  DS1307_GetDate(&DS1307_instance);
}

void DS1307_SetDate(TIME_STRUCT *Pts)
{
  I2C1_Stop();
  I2C1_Start();
  I2C1_Wr(0xD0);
  I2C1_Wr(DS1307_SECOND);
  I2C1_Wr(Dec2Bcd(Pts->sec));
  I2C1_Stop();
  I2C1_Start();
  I2C1_Wr(0xD0);
  I2C1_Wr(DS1307_MINUTE);
  I2C1_Wr(Dec2Bcd(Pts->min));
  I2C1_Stop();
  I2C1_Start();
  I2C1_Wr(0xD0);
  I2C1_Wr(DS1307_HOUR);
  I2C1_Wr(Dec2Bcd(Pts->hour));
  I2C1_Stop();
  I2C1_Start();
  I2C1_Wr(0xD0);
  I2C1_Wr(DS1307_WEEK);
  I2C1_Wr(Dec2Bcd(Pts->week));
  I2C1_Stop();
  I2C1_Start();
  I2C1_Wr(0xD0);
  I2C1_Wr(DS1307_DAY);
  I2C1_Wr(Dec2Bcd(Pts->day));
  I2C1_Stop();
  I2C1_Start();
  I2C1_Wr(0xD0);
  I2C1_Wr(DS1307_MONTH);
  I2C1_Wr(Dec2Bcd(Pts->month));
  I2C1_Stop();
  I2C1_Start();
  I2C1_Wr(0xD0);
  I2C1_Wr(DS1307_YEAR);
  I2C1_Wr(Dec2Bcd(Pts->year));
  I2C1_Stop();            //envia um sinal de STOP
}

void DS1307_GetDate(TIME_STRUCT *Pts)
{
  I2C1_Start();                     // envia um sinal de START
  I2C1_Wr(0xD0);                    // endereco no barramento e indicacao de escrita
  I2C1_Wr(0x00);                    // endereco inicial
  I2C1_Repeated_Start();            // restart no barramento
  I2C1_Wr(0xD1);                    // endereco no barramento e indicacao de leitura
  Pts->sec = Bcd2Dec(I2C1_Rd(1));   // le o 1o endereco e informa que ira continuar a leitura
  Pts->min = Bcd2Dec(I2C1_Rd(1));   // le o 2o endereco e informa que ira continuar a leitura
  Pts->hour = Bcd2Dec(I2C1_Rd(1));  // le o 3o endereco e informa que ira continuar a leitura
  Pts->week = Bcd2Dec(I2C1_Rd(1));  // le o 4o endereco e informa que ira continuar a leitura
  Pts->day = Bcd2Dec(I2C1_Rd(1));   // le o 5o endereco e informa que ira continuar a leitura
  Pts->month = Bcd2Dec(I2C1_Rd(1)); // le o 6o endereco e informa que ira continuar a leitura
  Pts->year = Bcd2Dec(I2C1_Rd(0));  // le o 7o endereco e informa que nÃ£o ira mais ler
  I2C1_Stop();                      // envia um sinal de STOP
}

TIME_STRUCT DS1307_GetNow()
{
  DS1307_GetDate(&DS1307_instance);
  return DS1307_instance;
}

TIME_STRUCT DS1307_Now()
{
  return DS1307_instance;
}
