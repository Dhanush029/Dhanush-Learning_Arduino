# Pushbuttons

I have done a total of three projects using pushbuttons. The first (Pushbutton.ino), is a very basic circuit where an LED switches on if the pushbutton is pressed. The second (pushbutton-toggle.ino) is slightly more complicated as it requires the use of more advanced logic in the code to get it working. The third (dimmable-led-with-buttons.ino), uses two pushbuttons to control the brighness of the LED.

Now I will describe each project separately.

## Pushbutton.ino
This project was easy to program. The default value of the pushbutton is 1. So, the only thing I needed to look out for was the turn changing to a 0 when pressed. A simple digitalRead() command and if statement finished the job. Here is a gif of the working project:

![pushbutton](pushbutton.gif)

## pushbutton-toggle.ino
Now this project was very interesting. I did get it to work pretty easily, but I quickly realised an issue. Luckily I resolved it after understanding how to look at the solution in a different way.

### Initial mistake
Initially, when i pressed

