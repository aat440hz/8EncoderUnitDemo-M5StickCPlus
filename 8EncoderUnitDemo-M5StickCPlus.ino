#include <M5StickCPlus.h>
#include "UNIT_8ENCODER.h"
#include <M5GFX.h>

M5GFX display;
M5Canvas canvas(&display);
UNIT_8ENCODER sensor;

// Function to map encoder values to colors
uint32_t valueToColor(int value) {
    // Example mapping: 
    // 1-10: Red, 11-20: Green, 21-30: Blue, 31-40: Yellow, 41-50: Purple, 51-59: Cyan
    if (value >= 1 && value <= 10) return 0xFF0000; // Red
    if (value >= 11 && value <= 20) return 0x00FF00; // Green
    if (value >= 21 && value <= 30) return 0x0000FF; // Blue
    if (value >= 31 && value <= 40) return 0xFFFF00; // Yellow
    if (value >= 41 && value <= 50) return 0xFF00FF; // Purple
    if (value >= 51) return 0x00FFFF; // Cyan
    return 0x000000; // Off
}

void show_encoder_value(void) {
    int32_t encoder[8] = {0};
    uint8_t btn_status[8] = {0};
    bool switch_status = sensor.getSwitchStatus();

    // Set the power switch LED to blue when switched on
    sensor.setLEDColor(8, switch_status ? 0x0000FF : 0x000000); // Assuming LED 8 is above the power switch

    canvas.clear(BLACK);
    canvas.setRotation(1);
    canvas.setTextSize(1);

    canvas.setCursor(5, 0);
    canvas.setTextColor(YELLOW);
    canvas.println("8Encoder Demo");

    int yOffset = 20;
    for (int i = 0; i < 8; i++) {
        encoder[i] = sensor.getEncoderValue(i);
        int displayedValue = ((encoder[i] % 60) + 60) % 60; // Ensures positive values
        btn_status[i] = sensor.getButtonStatus(i);

        sensor.setLEDColor(i, displayedValue == 0 ? 0x000000 : valueToColor(displayedValue));

        int x = 5 + (i % 4) * 40;
        int y = yOffset + (i / 4) * 30;
        
        canvas.setCursor(x, y);
        canvas.setTextColor(WHITE);
        canvas.printf("E%d: %d", i + 1, displayedValue);

        canvas.setCursor(x, y + 15);
        canvas.setTextColor(GREEN);
        canvas.printf("B%d: %d", i + 1, btn_status[i]);
    }

    // Display Switch Status
    canvas.setCursor(5, 120); // Adjust position as needed
    canvas.setTextColor(WHITE);
    canvas.printf("Switch: %s", switch_status ? "ON" : "OFF");

    canvas.pushSprite(0, 0);
}

void setup() {
    M5.begin();
    display.begin();
    sensor.begin(&Wire, ENCODER_ADDR, 32, 33, 100000UL);
    canvas.setColorDepth(8);
    canvas.createSprite(display.width(), display.height());
}

void loop() {
    show_encoder_value();
    M5.update();
    // Keeping the loop simple, just updating display and LEDs
}
