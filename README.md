ARDUINO ANNUAL LED DRIVER

The purpose of this sketch (should you choose to install it) is to drive annual LED display with Arduino. You can find this kind of display on ebay using 'annular led ring display' query.

## Schematics

![annular led ring display](https://raw.githubusercontent.com/mrizvic/arduino-annularLedRingDisplay/master/display.jpg)

![display internals](https://raw.githubusercontent.com/mrizvic/arduino-annularLedRingDisplay/master/display_schematic.jpg)

![arduino schematic](https://raw.githubusercontent.com/mrizvic/arduino-annularLedRingDisplay/master/arduino_schematic.jpg)


## Installation

Upload sketch using Arduino IDE.

## Usage

In order to light the pixels on the display one has to send series of ones and zeros (as ASCII string) over serial port. That is because each pixel on the display has its corresponding index position in the sketch. Lower left LED has index 0 , lower right led has index 14 and dot pixel in between has index 15. For example if you send `1000000000000000` you will end up with first pixel switched on and all others switched off. If you send `0000000000000010` you will see last pixel switched on. If you send `0000000000000001` you will see the dot pixel switched on. Etc. You can also light multiple random pixels, for example send `1100110011001101` and you will light up pixels 1,2,5,6,9,10,13,14,16 - this last one is the dot pixel.

I believe code is simple enough for anybody to figure out how to manipulate with pixels in the sketch itself.

## License

Beerware ;)
