#ifndef FIREVISUALIZER_H_
#define FIREVISUALIZER_H_

#define FASTLED_INTERNAL

#include "Visualizer.h"
#include "FastLED.h"
#include "defines.h"

class FireVisualizer: public Visualizer {
public:
	FireVisualizer();
	virtual ~FireVisualizer();

	virtual void start();
	virtual void stop();

	virtual boolean onButtonPressed(uint8_t button);

protected:
	virtual void computeImage();
	void computeImage1();
	void computeImage2();
	void computeImage3();

private:
	int8_t rendererId = 0;
	int8_t paletteNo;
	int16_t paletteMax;
	CRGBPalette16 palette[7] = { CRGBPalette16(HeatColors_p), CRGBPalette16(
			HeatColorsGreen_p), CRGBPalette16(HeatColorsBlue_p), CRGBPalette16(
			PartyColors_p), CRGBPalette16(CloudColors_p), CRGBPalette16(
			LavaColors_p), CRGBPalette16(ForestColors_p) };
	byte heat[LEDS_WIDTH][LEDS_HEIGHT * 2];

	int16_t cooling;
	int16_t sparking;

	uint8_t vImageData[LEDS_WIDTH * LEDS_HEIGHT * 2 * 3];

};

#endif /* FIREVISUALIZER_H_ */
