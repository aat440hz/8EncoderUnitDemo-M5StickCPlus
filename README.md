# 8EncoderUnitDemo-M5StickCPlus

This repository contains the `8EncoderUnitDemo-M5StickCPlus` project, designed for displaying and interacting with the UNIT_8ENCODER module using the M5StickC Plus. It's an excellent resource for those looking to integrate encoders into their M5StickC Plus projects, providing real-time visual feedback and interactive capabilities.

## Features

- **Real-time Encoder Display:** View the values of 8 encoders in real-time on the M5StickC Plus display.
- **Color-Coded Feedback:** Each encoder value corresponds to a specific color for easy identification and visual appeal.
- **Button Status Monitoring:** Check the status of buttons linked to each encoder on the display.
- **Power Switch Indicator:** A visual indicator shows the power switch status.
- **User-Friendly Interface:** Simple yet effective layout for clear and immediate understanding of encoder and button statuses.

## Hardware Requirements

- M5StickC Plus
- UNIT_8ENCODER module

## Software Dependencies

- M5StickC Plus Library
- M5GFX Library
- UNIT_8ENCODER Library

## Installation

1. **Environment Setup:** Ensure your Arduino IDE is set up for M5StickC Plus development.
2. **Repository Download:** Clone or download this repository to your local machine.
3. **Sketch Upload:** Open the provided Arduino sketch and upload it to your M5StickC Plus.

## Usage

Upon uploading the sketch, the M5StickC Plus display will activate, showing the encoder values and button statuses. Rotate the encoders to see the corresponding value and color changes on the display. Button presses will be reflected in real-time on the screen.

## Customization

- **Color Schemes:** Alter the `valueToColor` function in the sketch for different color mappings based on encoder values.
- **Display Adjustments:** Customize the display layout, including text positions and sizes, in the `show_encoder_value` function.

## Contributing

We welcome contributions to enhance this project. Feel free to fork the repository, make improvements, and submit pull requests.

## License

This project is available under the [MIT License](LICENSE.md).
