# DS1307

Manipulação do [RTC DS1307](https://datasheets.maximintegrated.com/en/ds/DS1307.pdf) com PIC16F ou PIC18F

### Como utilizar

Inclua os arquivos fontes no seu projeto e faça a chamada no seu código:

```c
#include "DS1307.h"
```

Não esqueça de adicionar o `DS1307.c` na compilação.

### Documentação

:1234: __TIME_STRUCT__

- `year` - ano.
- `month` - mês (1 até 12).
- `day` - dia (1 até 31).
- `week` - semana (1 = domingo até 7 = sábado).
- `hour` - hora (0 a 23).
- `min` - minuto (0 a 59).
- `sec` - segundo (0 a 59).

Todos os campos são do tipo `unsigned short`.

:arrow_forward: __DS1307_Init()__

Inicia o barramento __I2C__ e realiza a primeira chamada para __DS1307_GETDATE()__.

:twisted_rightwards_arrows: __DS1307_SetDate(TIME_STRUCT *)__

Recebe um parâmetro que é um ponteiro para um TIME_STRUCT.

Configura a hora do relógio conforme o TIME_STRUCT passado.

:arrow_heading_up: __DS1307_GetDate()__

Recebe um parâmetro que é um ponteiro para o TIME_STRUCT.

Lê o relógio e atualiza as informações no TIME_STRUCT.

:arrows_counterclockwise: __DS1307_GetNow()__

Não recebe parâmetros.

Chama o __DS1307_GetDate()__ passando o ponteiro para um TIME_STRUCT interno da biblioteca (__DS1307_instance__) e após atualização retorna o TIME_STRUCT.

:repeat_one: __DS1307_Now()__

Não recebe parâmetros.

Retorna o TIME_STRUCT interno da biblioteca (__DS1307_instance__).

> É recomendo criar um intervalo para consultar o relógio (\_GetNow()), uma vez que o mesmo apresentou mal funcionamento se consultado durante cada ciclo. Nesse cenário, utilize o \_Now() fora dos intervalo para consultar o TIME_STRUCT interno.

### Agradecimentos

- [Relógio e Calendário Digital com RTC DS1307](http://microcontrolandos.blogspot.com.br/2012/12/relogio-e-calendario-digital-com-rtc.html)

### Autores

| ![](https://avatars0.githubusercontent.com/u/8146112?s=100) | ![](https://avatars2.githubusercontent.com/u/9325152?s=100) |
| ----- | ----- |
| [Felipe Pontes](//github.com/felipemfp) | [Francisco Bento](//github.com/chicobentojr) |

### Licença

Este projeto é licenciado pela Licença MIT, veja [LICENSE](LICENSE) para mais detalhes.
