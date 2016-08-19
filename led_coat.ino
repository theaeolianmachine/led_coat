#include <FastLED.h>

#define CLOCK_PIN 0
#define DATA_PIN 2

#define DEFAULT_BRIGHTNESS 191
#define DEFAULT_SAT 223
#define FPS 120
#define LED_GROUP_SIZE ((NUM_LEDS) / (NUM_GROUPS))
#define MAX_BRIGHTNESS 191
#define MAX_SAT 255
#define MIN_BRIGHTNESS 63
#define MIN_SAT 191
#define NUM_GROUPS 9
#define NUM_LEDS 90
#define RGB_ORDER BRG
#define NUM_PALETTES 4

CRGB leds[NUM_LEDS];
uint8_t rainbowHue = 0;     // Global value for cycling through hues


const CHSVPalette16 SKFiveHSVPalette_p(
    CHSV(43, 255, 255),
    CHSV(85, 255, 255),
    CHSV(124, 255, 255),
    CHSV(158, 255, 255),
    CHSV(117, 204, 255),
    CHSV(190, 204, 255),
    CHSV(43, 255, 255),
    CHSV(85, 255, 255),
    CHSV(124, 255, 255),
    CHSV(158, 255, 255),
    CHSV(117, 204, 255),
    CHSV(190, 204, 255),
    CHSV(43, 255, 255),
    CHSV(85, 255, 255),
    CHSV(124, 255, 255),
    CHSV(158, 255, 255)
);

void smoothGradientPattern() {
    uint8_t colorIndex = rainbowHue;
    for (uint16_t i = 0; i < NUM_LEDS; ++i) {
        leds[i] = ColorFromPalette(
            SKFiveHSVPalette_p, colorIndex, DEFAULT_BRIGHTNESS);
        colorIndex += 3;
    }
}

void setup() {
    FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN, RGB_ORDER>(
        leds, NUM_LEDS).setCorrection(TypicalSMD5050);
    FastLED.setTemperature(Halogen);
    FastLED.setBrightness(DEFAULT_BRIGHTNESS);
    FastLED.setMaxPowerInVoltsAndMilliamps(5, 313);
}

void loop() {
    smoothGradientPattern();
    ++rainbowHue;
    FastLED.show();
    FastLED.delay(1000 / FPS);
}
