/*
 Name:		GemmaM0_SuperSketcherz.ino
 Created:	2/3/2021 2:35:24 AM
 Author:	aalbert
*/

#include <exception>
#include <Adafruit_DotStar.h>

constexpr auto dot_Numpixels = 1;
constexpr auto dot_Datapin = 7;
constexpr auto dot_Clockpin = 8;
constexpr auto dot_ColorChangeIntervalMillis = 5;
constexpr auto touch_T1_Pin = 1;
constexpr auto touch_T1_DblClickTolerance = 250;
constexpr auto touch_T1_ChangeTolerance = 500;
constexpr auto led_AuxPin1 = 0;
constexpr auto led_AuxPin2 = 2;

bool lights_RequestedState = false;

//https://learn.adafruit.com/adafruit-dotstar-leds/arduino-library-use
Adafruit_DotStar dot(dot_Numpixels, dot_Datapin, dot_Clockpin, DOTSTAR_BRG);
byte dot_Brightness = (byte)(255 * .2);
byte dot_ColorWheelArr[3];
bool dot_CurrentLightState = false;
byte dot_CurrentColorIndex = 0;
unsigned long dot_LastColorChange = 0;

bool led_CurrentLightState = false;

unsigned long touch_T1_LastTouchInit = 0;
unsigned long touch_T1_LastPress = 0;
unsigned long touch_T1_LastChange = 0;
bool touch_BtnDown = false;


// the setup function runs once when you press reset or power the boar+d
void setup() {
	Serial.begin(9600);
	dot.clear();
	dot.show();
	pinMode(LED_BUILTIN, OUTPUT);
	pinMode(led_AuxPin1, OUTPUT);
	pinMode(led_AuxPin2, OUTPUT);
	pinMode(touch_T1_Pin, INPUT_PULLUP);
}

// the loop function runs over and over again until power down or reset
void loop() {
	bool didChange = DetectTouchButton();
	if (didChange)
	{
		RenderLED();
	}
	RenderDot();
	delay(1);
}

bool DetectTouchButton()
{
	if (digitalRead(touch_T1_Pin) == LOW) {
		if (!touch_BtnDown)
		{
			touch_T1_LastTouchInit = millis();
			touch_BtnDown = true;
		}
	}
	else if (touch_BtnDown)
	{
		if ((touch_T1_LastTouchInit - touch_T1_LastPress) > touch_T1_DblClickTolerance)
		{
			touch_T1_LastPress = millis();
		}
		else if ((touch_T1_LastTouchInit - touch_T1_LastChange) > touch_T1_ChangeTolerance)
		{
			lights_RequestedState ^= true;
			touch_T1_LastChange = millis();
			touch_BtnDown = false;
			return true;
		}
		touch_BtnDown = false;
	}
	return false;
}

void RenderLED()
{
	if (lights_RequestedState != led_CurrentLightState)
	{
		digitalWrite(LED_BUILTIN, lights_RequestedState);
		digitalWrite(led_AuxPin1, lights_RequestedState);
		digitalWrite(led_AuxPin2, lights_RequestedState);
		led_CurrentLightState = lights_RequestedState;
	}
}

void RenderDot()
{
	if (!lights_RequestedState && !dot_CurrentLightState)
	{
		return;
	}
	else if (!lights_RequestedState)
	{
		dot.clear();
		dot.show();
		dot_CurrentLightState = false;
	}
	else
	{
		dot_CurrentLightState = true;
		if ((millis() - dot_LastColorChange) < dot_ColorChangeIntervalMillis)
		{
			return;
		}
		dot_LastColorChange = millis();
		ColorWheel(dot_CurrentColorIndex++, dot_ColorWheelArr);
		int idx = 0;
		int r = dot_ColorWheelArr[0];
		int g = dot_ColorWheelArr[1];
		int b = dot_ColorWheelArr[2];
		dot.setBrightness(dot_Brightness);
		dot.setPixelColor(idx, r, g, b);
		dot.show();
	}
}

void ColorWheel(int pos, byte colorArr[]) {
	// Input a value 0 to 255 to get a color value.
	// The colours are a transition r - g - b - back to r.

	if (pos < 0 || pos > 255)
	{
		colorArr[0] = 0;
		colorArr[1] = 0;
		colorArr[2] = 0;
	}
	else if (pos < 85)
	{
		colorArr[0] = 255 - pos * 3;
		colorArr[1] = pos * 3;
		colorArr[2] = 0;
	}
	else if (pos < 170)
	{
		pos -= 85;
		colorArr[0] = 0;
		colorArr[1] = 255 - pos * 3;
		colorArr[2] = pos * 3;
	}
	else
	{
		pos -= 170;
		colorArr[0] = pos * 3;
		colorArr[1] = 0;
		colorArr[2] = 255 - (pos * 3);
	}
}

