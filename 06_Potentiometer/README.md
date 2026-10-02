# Potentiometer

The circuit here also reads analog voltage, but from a potentiometer. The potentiometer comprises of 3 pins where the first two connect to the power supply and ground. The third pin provides the analog voltage depending on how far the potentiometer is turned. So, the voltage produced by a potentiometer can vary.

## Simple Circuit
This is the circuit. Turning the knob on the potentiometer changes the voltage.

![Circuit](simple-potentiometer-circuit.gif) 

This gif shows the view of the serial monitor where the voltage reading from the potentiometer is printed.

![voltges](changing-voltages.gif)

## Circuit with an led warning
Using the program potentiometer_ledwarning.ino, I added an extra condition where if the voltage reading was more than 4V, an LED will flash as a warning.

![ledwarning](led-warning.jpeg)


