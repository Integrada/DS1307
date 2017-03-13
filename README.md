# DS1307

_Manipulação do [RTC DS1307](https://datasheets.maximintegrated.com/en/ds/DS1307.pdf) com PIC16F ou PIC18F_

### Como utilizar

Inclua os arquivos fontes no seu projeto e faça a chamada no seu código:

```c
#include "DS1307.h"
```

Dentro no seu método em loop, realize a chamada do __DS1307_Loop()__, passando um intervalo coerente com seu projeto.

```c
int main()
{
  // ...
  DS1307_Init();

  while (1)
  {
    DS1307_Loop(1000);
    // ...
  }
}
```

Não esqueça de adicionar os `DS1307.h` e `DS1307.c` na compilação.

#### Dependências

Este projeto depende das bibliotecas [`I2C`](https://download.mikroe.com/documents/compilers/mikroc/pic/help/i2c_library.htm),  [`Conversions`](https://download.mikroe.com/documents/compilers/mikroc/pic/help/conversions_library.htm) e [`Time`](https://download.mikroe.com/documents/compilers/mikroc/pic/help/time_library.htm) oferecidas pelo MikroC, não esqueça de ativá-las.

### Documentação

:information_source: __TimeStruct__

- `yy` - ano (2000 até 2099).
- `mm` - mês (1 até 12).
- `md` - dia do mês (1 até 31).
- `wd` - dia da semana (1 é domingo, 2 é segunda... 7 é sábado).
- `hh` - horas (0 a 23).
- `mm` - minutos (0 a 59).
- `ss` - segundos (0 a 59).

Todos os campos são do tipo `unsigned short`.

:arrow_forward: __DS1307_Init()__

Inicia o barramento __I2C__ e realiza a primeira chamada para __DS1307_GetDate()__.

:twisted_rightwards_arrows: __DS1307_SetDate(TimeStruct \*)__

Recebe um parâmetro que é um ponteiro para um TimeStruct.

Configura a hora do relógio conforme o TimeStruct passado.

:arrow_heading_up: __DS1307_GetDate(TimeStruct \*)__

Recebe um parâmetro que é um ponteiro para o TimeStruct.

Lê o relógio e atualiza as informações no TimeStruct.

:arrows_counterclockwise: __DS1307_Loop(unsigned short)__

Verifica se o intervalo passado por parâmetro, foi alcançado, então chama o __DS1307_GetDate()__ passando o ponteiro para um TimeStruct interno da biblioteca (__DS1307_instance__) e em seguida atualiza o _timestamp_ interno (__DS1307_timestamp__).

:repeat_one: __DS1307_Now()__

Não recebe parâmetros.

Retorna o TimeStruct interno da biblioteca (__DS1307_instance__).

:1234: __DS1307_Timestamp()__

Não recebe parâmetros.

Retorna o _timestamp_ interno da biblioteca (__DS1307_timestamp__).

### Agradecimentos

- [Relógio e Calendário Digital com RTC DS1307](http://microcontrolandos.blogspot.com.br/2012/12/relogio-e-calendario-digital-com-rtc.html)

### Autores

| ![](https://avatars0.githubusercontent.com/u/8146112?s=100) | ![](https://avatars2.githubusercontent.com/u/9325152?s=100) |
| ----- | ----- |
| [Felipe Pontes](//github.com/felipemfp) | [Francisco Bento](//github.com/chicobentojr) |

### Licença

Este projeto é licenciado pela Licença MIT, veja [LICENSE](LICENSE) para mais detalhes.
