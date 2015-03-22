// TemperatureFahrenheitCelsiusWhileLoop.cpp
//
// Purpose: Print two columns on the screen with the temperature in 
//			degrees Celsius and the equivalent temperature in degrees Fahrenheit, using a for loop.
//
// @author Fulin Li
// @version 1.0 9/27/14

#include <stdio.h>

void main()
{
	double start_temperature_Celsius = 0.0; // start degrees Celsius temperature
	double end_temperature_Celsius = 19.0; // end degrees Celsius temperature
	double step_Celsius = 1.0; // step size of the degrees Celsius temperature
	double temperature_Celsius; // temperature in Celsius
	double temperature_Fahrenheit; // temperature in Fahrenheit

	// Print header text.
	printf("%10s%15s\n", "Celsius", "Fahrenheit");

	for (temperature_Celsius = start_temperature_Celsius; temperature_Celsius <= end_temperature_Celsius; temperature_Celsius++)
	{
		// Convert temperature in Celsius to temperature in Fahrenheit.
		temperature_Fahrenheit = temperature_Celsius * 9.0 / 5.0 + 32.0;

		// Print both temperatures.
		printf("%10.0f%15.1f\n", temperature_Celsius, temperature_Fahrenheit);
	}
}