// TemperatureFahrenheitCelsiusWhileLoop.cpp
//
// Purpose: Print two columns on the screen with the temperature in 
//			degrees Fahrenheit and the equivalent temperature in degrees Celsius, using a while loop.
//
// @author Fulin Li
// @version 1.0 9/27/14

#include <stdio.h>

void main()
{
	double start_temperature_Fahrenheit = 0.0; // start degrees Fahrenheit temperature
	double end_temperature_Fahrenheit = 300.0; // end degrees Fahrenheit temperature
	double step_Fahrenheit = 20.0; // step size of the degrees Fahrenheit temperature
	double temperature_Fahrenheit = NULL; // temperature in Fahrenheit
	double temperature_Celsius = NULL; // temperature in Celsius

	// Start the loop from the start temperature in Fahrenheit.
	temperature_Fahrenheit = start_temperature_Fahrenheit;

	// Print header text.
	printf("%10s%10s\n","Fahrenheit", "Celsius");

	while (temperature_Fahrenheit <= end_temperature_Fahrenheit)
	{
		// Convert temperature in Fahrenheit to temperature in Celsius.
		temperature_Celsius = (5.0 / 9.0) * (temperature_Fahrenheit - 32.0);

		// Print both temperatures.
		printf("%10.0f%10.1f\n", temperature_Fahrenheit, temperature_Celsius);

		// Move on to the next temperature in Fahrenheit.
		temperature_Fahrenheit += step_Fahrenheit;
	}
}