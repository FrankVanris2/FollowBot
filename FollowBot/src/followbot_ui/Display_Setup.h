/*
By: Frank Vanris
Date: 02/10/2025
Desc: Setup requirements for the ST7796S display that are needed in order for the touch and display to work.
Desc:*/

#pragma once

// Clock Speed
#define SPI_FREQUENCY 23900000

// Can use Ardiuno pin references, arbitrary allocation, TFT_eSPI controls chip select
#define TFT_CS        10
#define TFT_DC         9
#define TFT_RST        8

#define TFT_SCLK      13
#define TFT_MISO      12
#define TFT_MOSI      11

//for touch
#define DCS     5
#define DCLK     6
#define DIN     4
#define DOUT    3

//Touch Configuration
#define HMIN 0
#define HMAX 3840
#define VMIN 0
#define VMAX 3840
#define XYSWAP 1 // 0 or 1

//Display Size
#define HRES 480 /* Default screen resolution for X axis */
#define VRES 320 /* Default screen resolution for Y axis */