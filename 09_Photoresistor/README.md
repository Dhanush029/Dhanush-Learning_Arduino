# Buzzer and photoresistor

This project changes the tone of the buzzer when the light hitting  photoresistor increases. 

## How this works
Depending on the analog voltage output value of the photoresistor, the delay in the buzzer's on and off cycle changes. 

I first tested the values of the photoresistor (on a scale of 0-1023) when my room light was on and when I shined a bright light on it. So, I wanted the buzzer to have a delay of 10ms when the value was at 1000 and 1ms when the value was 700. The delay value must vary linearly as the voltage changed. 

This was achieved by finding the equation of a line using two points: (700,1) and (1000,10). Finding the gradient and y-intercept is straightforward after that. I put together an equation which is seen in the code: int dt = output * (3./100.) - 20.;

## Video of working project

[![Watch the demo](https://img.youtube.com/vi/zmjoTXCFESA/maxresdefault.jpg)](https://www.youtube.com/watch?v=zmjoTXCFESA)
