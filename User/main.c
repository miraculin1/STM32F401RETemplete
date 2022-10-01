#include "stm32f4xx.h"
#include <stdint.h>

#define RCC_Base 0x40023800
#define RCC_ENR *(uint32_t *)(RCC_Base + 0x30)

#define GPIOA_Base 0x40020000
#define GPIOA_MODER *(uint32_t *)(GPIOA_Base + 0x00)
#define GPIOA_OType *(uint32_t *)(GPIOA_Base + 0x04)
#define GPIOA_Speed *(uint32_t *)(GPIOA_Base + 0x08)
#define GPIOA_PPMode *(uint32_t *)(GPIOA_Base + 0x0C)
#define GPIOA_OData *(uint32_t *)(GPIOA_Base + 0x14)

int main() {

  RCC_ENR |= 0x01;

  GPIOA_MODER &= ~(0x01 << 2 * 5);
  GPIOA_MODER |= (0x01 << 2 * 5);

  GPIOA_OType &= ~(0x1 << 5);

  GPIOA_Speed &= ~(0x01 << 2 * 5);
  GPIOA_Speed |= (0x01 << 2 * 5);

  GPIOA_PPMode &= ~(0x01 << 2 * 5);
  GPIOA_PPMode |= (0x01 << 2 * 5);

  GPIOA_OData &= ~(0x01 << 5);
  GPIOA_OData |= (0x01 << 5);

  while (1) {
    RCC_ENR |= 0x01;
  }
}
