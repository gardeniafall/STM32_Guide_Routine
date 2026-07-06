#include "user.h"

uint8_t ElapsedCounter = 0;
uint16_t CompareValue = 0;
uint8_t Direction = 1;

/**
  * @brief initialize user-defined peripherals and settings.
  * @retval None
  */
void user_init(void)
{
  HAL_TIM_Base_Start_IT(&htim8);
  HAL_TIM_PWM_Start(&htim8, TIM_CHANNEL_1);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  if(htim->Instance == TIM8)
  {
    if(ElapsedCounter < 15)
    {
      ElapsedCounter++;
    }
    else
    {
      ElapsedCounter = 0;
      if(Direction)
      {
        CompareValue += 1;
        if(CompareValue >= 2047)
        {
          CompareValue = 2047;
          Direction = 0;
        }
      }
      else
      {
        CompareValue -= 1;
        if(CompareValue <= 0)
        {
          CompareValue = 0;
          Direction = 1;
        }
      }
      __HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_1, CompareValue);
    }
  }
}