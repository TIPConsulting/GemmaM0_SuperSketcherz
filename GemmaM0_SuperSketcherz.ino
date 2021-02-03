/*
 Name:		GemmaM0_SuperSketcherz.ino
 Created:	2/3/2021 2:35:24 AM
 Author:	aalbert
*/

#include <Adafruit_DotStar.h>

constexpr auto dot_NUMPIXELS = 1;
constexpr auto dot_DATAPIN = 7;
constexpr auto dot_CLOCKPIN = 8;
constexpr auto touch_T1 = 3;
constexpr auto touch_T1_DblClickTolerance = 300;
constexpr auto touch_T1_ChangeTolerance = 500;

//https://learn.adafruit.com/adafruit-dotstar-leds/arduino-library-use
Adafruit_DotStar dot(dot_NUMPIXELS, dot_DATAPIN, dot_CLOCKPIN, DOTSTAR_BRG);
unsigned long touch_T1_LastPress = 0;
unsigned long touch_T1_LastChange = 0;


// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(9600);
	dot.clear();
	dot.show();
	pinMode(LED_BUILTIN, OUTPUT);
	pinMode(touch_T1, INPUT);
}

// the loop function runs over and over again until power down or reset
void loop() {
	if (digitalRead(touch_T1) == HIGH) {
		if ((millis() - touch_T1_LastPress) < touch_T1_DblClickTolerance && (millis() - touch_T1_LastChange) > touch_T1_ChangeTolerance)
		{
			digitalWrite(LED_BUILTIN, digitalRead(LED_BUILTIN) ^ 1);
			touch_T1_LastChange = millis();
		}
		else
		{
			while (digitalRead(touch_T1)) {
				delay(1);
			}
			touch_T1_LastPress = millis();
		}
	}
	delay(10);
}
