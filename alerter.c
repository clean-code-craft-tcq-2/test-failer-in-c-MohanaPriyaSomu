#include <stdio.h>
#include <assert.h>
#define TEMP_BRINK	170

int alertFailureCount = 0;

float FahrenheitToCelsius(float farenheit)
{
	float celcius = (farenheit - 32) * 5 / 9;
	return celcius;
}

int networkAlertStub(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
	if (celcius < TEMP_BRINK)
	{
		// Return 200 for ok
		// stub always succeeds and returns 200
		return 200;
	}
	else 
	{
		// Return 500 for not-ok
		return 500;
	}
}

void alertInCelcius(float tempFarenheit, float *conversion(float), int *stub(int)) {
    float tempCelcius = conversion(tempFarenheit);
    int returnCode = stub(tempCelcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
    }
}

int main() {
    alertInCelcius(400.5, &FahrenheitToCelsius, &networkAlertStub);
    alertInCelcius(303.6, &FahrenheitToCelsius, &networkAlertStub);  
    alertInCelcius(250.7, &FahrenheitToCelsius, &networkAlertStub);
    alertInCelcius(700.9, &FahrenheitToCelsius, &networkAlertStub);
    assert(alertFailureCount == 3);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
