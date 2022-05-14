// TODO: add your code to this file
#include <stdio.h>
#include <math.h>

int main () {	
	float hours, overTime, houRate, overRate, regPay, overPay, grossSal;

	//Ask user for input for variable hours
	printf("Enter your hours: ");
	scanf("%f", &hours);
	
	//Ask user for input for variable Hourly_Rate
	printf("Enter your hourly rate: ");
	scanf("%f", &houRate);
	
	
	// If hours are less than or equal to 40 then there is no overtime pay
	if (hours < 40)
		
	{ 	
	// Calculate regular pay
		regPay = houRate * hours;	
		overPay = 0;
		overRate = houRate * 1.5;
		overTime = 0;
		grossSal = regPay;
		
		printf("Number of hours worked: %.2fh\n", hours);
		printf("Hourly rate: $%.2f\n", houRate);
		printf("Overtime hours: %.2f\n", overTime);
		printf("Overtime rate: $%.2f\n", overRate);
		printf("Regular pay: $%.2f\n", regPay);
		printf("Overtime pay: $%.2f\n", overPay);
		printf("Gross salary: $%.2f", grossSal);
	}
	// Else, there is overtime pay
	else
	{
		// Calculate overtime hours
		overTime = hours - 40;
	
		// Calculate overtime pay rate
		overRate = houRate * 1.5;
	
		// Calculate regular pay
		regPay = houRate * 40;
	
		// Calculate overtime pay
		overPay = overRate * overTime;
	
		// Calculate Gross salary
		grossSal = overPay + regPay;
	
	  	printf("Number of hours worked: %.2fh\n", hours);
		printf("Hourly rate: $%.2f\n", houRate);
		printf("Overtime hours: %.2fh\n", overTime);
		printf("Overtime rate: $%.2f\n", overRate);
		printf("Regular pay: $%.2f\n", regPay);
		printf("Overtime pay: $%.2f\n", overPay);
		printf("Gross salary: $%.2f\n", grossSal);

	}
	
	return 0;
}