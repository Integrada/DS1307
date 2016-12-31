#include "DS1307.h"

unsigned short DS1307_loopControl = 0;
unsigned short DS1307_loopLast = 0;
// Jan 1st, 2017, Sunday, 00:00:00
TimeStruct DS1307_instance = { 0, 0, 0, 1, 1, 1, 2017 };

void DS1307_Init()
{
  I2C1_Init(100000);
  DS1307_GetDate(&DS1307_instance);
}

void DS1307_SetDate(TimeStruct *Pts)
{
  I2C1_Stop();
  I2C1_Start();
  I2C1_Wr(0xD0);
  I2C1_Wr(DS1307_SECOND);
  I2C1_Wr(Dec2Bcd(Pts->ss));
  I2C1_Wr(Dec2Bcd(Pts->mm));
  I2C1_Wr(Dec2Bcd(Pts->hh));
  I2C1_Wr(Dec2Bcd(Pts->wd));
  I2C1_Wr(Dec2Bcd(Pts->md));
  I2C1_Wr(Dec2Bcd(Pts->mo));
  I2C1_Wr(Dec2Bcd(Pts->yy - 2000));
  I2C1_Stop();            //envia um sinal de STOP
}

void DS1307_GetDate(TimeStruct *Pts)
{
  I2C1_Start();                     // envia um sinal de START
  I2C1_Wr(0xD0);                    // endereco no barramento e indicacao de escrita
  I2C1_Wr(0x00);                    // endereco inicial
  I2C1_Repeated_Start();            // restart no barramento
  I2C1_Wr(0xD1);                    // endereco no barramento e indicacao de leitura
  Pts->ss = Bcd2Dec(I2C1_Rd(1));    // le o 1o endereco e informa que ira continuar a leitura
  Pts->mm = Bcd2Dec(I2C1_Rd(1));    // le o 2o endereco e informa que ira continuar a leitura
  Pts->hh = Bcd2Dec(I2C1_Rd(1));    // le o 3o endereco e informa que ira continuar a leitura
  Pts->wd = Bcd2Dec(I2C1_Rd(1));    // le o 4o endereco e informa que ira continuar a leitura
  Pts->md = Bcd2Dec(I2C1_Rd(1));    // le o 5o endereco e informa que ira continuar a leitura
  Pts->mo = Bcd2Dec(I2C1_Rd(1));    // le o 6o endereco e informa que ira continuar a leitura
  Pts->yy = Bcd2Dec(I2C1_Rd(0)) + 2000;    // le o 7o endereco e informa que nÃ£o ira mais ler
  I2C1_Stop();                      // envia um sinal de STOP
}

void DS1307_Loop(unsigned short loopInterval)
{
  if ((unsigned short)(DS1307_loopControl - DS1307_loopLast) >= loopInterval) {
    DS1307_GetDate(&DS1307_instance);
    DS1307_timestamp = Time_dateToEpoch(&DS1307_instance);
  }
  DS1307_loopControl++;
}

TimeStruct DS1307_Now()
{
  return DS1307_instance;
}

long DS1307_Timestamp()
{
  return DS1307_timestamp;
}
