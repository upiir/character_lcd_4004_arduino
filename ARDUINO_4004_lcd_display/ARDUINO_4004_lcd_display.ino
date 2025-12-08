// using 40x4 LCD Character Display from Surenoo with Arduino UNO
// created by upir, 2025
// youtube channel: https://www.youtube.com/upir_upir

// Youtube Video: https://youtu.be/H3GYU58Y6GM

// Links related to this project:
// Do you like this video? You can buy me a coffee ☕: https://www.buymeacoffee.com/upir
// 4004 LCD Display: https://s.click.aliexpress.com/e/_c3HKMqvJ
// Arduino UNO - https://s.click.aliexpress.com/e/_AXDw1h
// 4004 LCD Library: https://www.surenoo.com/products/6791632?variant_sku_code=6791632-5772717-26634711-5803041-26634714-0-0
// LCD Smartie: https://github.com/LCD-Smartie/LCDSmartie/releases
// Supported Characters: https://docs.wokwi.com/parts/wokwi-lcd1602#a00-variant

// Related videos with character displays:
// 3D on 16x2 Character Display: https://youtu.be/IvMauAxWPkQ
// Smooth Gauge - No Custom Characters: https://youtu.be/MEhJtpkjwnc
// small display - BIG DIGITS: https://youtu.be/SXSujfeN_QI
// 1 DISPLAY 3 SENSORS: https://youtu.be/lj_7UmM0EPY
// DIY Battery Indicator (Arduino Project): https://youtu.be/Mq0WBPKGRew
// Smooth Arduino 16x2 Gauge: https://youtu.be/cx9CoGqpsfg
// Arduino Gauge in 11 Minutes ???: https://youtu.be/upE17NHrdPc


// library downloaded from https://www.surenoo.com/products/6791632?variant_sku_code=6791632-5772717-26634711-5803041-26634714-0-0
#include "LiquidCrystal_I2C_4004.h" // this is not a library, but rather another file in the same folder, modification of the LiquidCrystal_I2C library to support big displays

const byte lcdAddr = 0x27;  // Address of I2C backpack
const byte lcdCols = 40;    // Number of character in a row
const byte lcdRows = 4;     // Number of lines
LiquidCrystal_I2C lcd(lcdAddr, lcdCols, lcdRows); // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup() {

  lcd.begin(); // the begin function is needed
  delay(200); // it´s not clear if this delay is really needed
  lcd.home(); // move the cursor to the top left of the screen
  lcd.backlight(); // enable backlight
}

// content for custom characters
// automatically created from this website:
// https://mateusznowak.dev/projects/charlcd-designer/?initial=&w=40&h=4&x=40&y=0&text=%5Cx01+Batt.++%5CxFF%5CxFF%5CxFF%5CxFF------++%5Cx02+Brig.++%5CxFF%5CxFF%5CxFF%5CxFF%5CxFF-----%0A%5Cx7E+Speed++%5CxFF%5CxFF%5CxFF%5CxFF%5CxFF%5CxFF%5CxFF---++%5Cx03+Sound++%5CxFF%5CxFF--------%0A%5Cx04+Music++%5CxFF%5CxFF%5CxFF%5CxFF%5CxFF%5CxFF%5CxFF%5CxFF--++%5Cx05+Wifi+++%5CxFF%5CxFF%5CxFF%5CxFF%5CxFF%5CxFF%5CxFF----%0A%5Cx06+BT+++++%5CxFF%5CxFF%5CxFF%5CxFF------++%5Cx07+Chrg.++%5CxFF%5CxFF--------&data=0%2C510616666111%2C23051326464%2C109305193635%2C117349592952%2C1112725173%2C491554039086%2C355393386628
byte custom_char_0[8] =  {0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000}; 
byte custom_char_1[8] =  {0b01110, 0b11011, 0b10001, 0b10001, 0b11111, 0b11111, 0b11111, 0b11111}; 
byte custom_char_2[8] =  {0b00000, 0b10101, 0b01110, 0b11111, 0b01110, 0b10101, 0b00000, 0b00000}; 
byte custom_char_3[8] =  {0b00011, 0b00101, 0b11001, 0b10001, 0b10001, 0b11001, 0b00101, 0b00011}; 
byte custom_char_4[8] =  {0b00011, 0b01101, 0b01001, 0b01001, 0b01001, 0b01011, 0b11011, 0b11000}; 
byte custom_char_5[8] =  {0b00000, 0b00001, 0b00001, 0b00101, 0b00101, 0b10101, 0b10101, 0b10101}; 
byte custom_char_6[8] =  {0b01110, 0b01001, 0b11001, 0b01110, 0b01110, 0b11001, 0b01001, 0b01110}; 
byte custom_char_7[8] =  {0b01010, 0b01010, 0b11111, 0b10001, 0b10001, 0b01110, 0b00100, 0b00100}; 


void loop() {

  // create 8 custom characters, first parameter is the index (0-7), second parameter is the content of the custom character
  lcd.createChar(0, custom_char_0);
  lcd.createChar(1, custom_char_1);
  lcd.createChar(2, custom_char_2);
  lcd.createChar(3, custom_char_3);
  lcd.createChar(4, custom_char_4);
  lcd.createChar(5, custom_char_5);
  lcd.createChar(6, custom_char_6);
  lcd.createChar(7, custom_char_7);  

  // clear the screen
  lcd.clear(0);
  lcd.clear(1);
  // set cursor to the first line
  lcd.setCursor(0, 0);
  lcd.print("\x01 Batt.  \xFF\xFF\xFF\xFF------  \x02 Brig.  \xFF\xFF\xFF\xFF\xFF-----");
  // set cursor to the second line  
  lcd.setCursor(0, 1);
  lcd.print("\x7E Speed  \xFF\xFF\xFF\xFF\xFF\xFF\xFF---  \x03 Sound  \xFF\xFF--------");
  // set cursor to the third line  
  lcd.setCursor(0, 2);
  lcd.print("\x04 Music  \xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF--  \x05 Wifi   \xFF\xFF\xFF\xFF\xFF\xFF\xFF----");  
  // set cursor to the fourth line  
  lcd.setCursor(0, 3);
  lcd.print("\x06 BT     \xFF\xFF\xFF\xFF------  \x07 Chrg.  \xFF\xFF--------");  

  // long delay, just because we don´t have anything dynamic on the screen displayed
  delay(10000);
}