#include "smallfont.h"

//#define LCD_MOSI  PINB2
//#define LCD_SCK   PINB4
//#define LCD_CD    PINB1
//#define LCD_RESET PINB0
#define WAIT_INNER (F_CPU / 6000)
#define LCD_COL 84
#define LCD_ROW 6

class Nokia5110LCD {
  public:
    void lcdData(uint8_t data);
    void lcdCommand(uint8_t cmd);
    void lcdInit();
    void lcdInit(uint8_t _mosi, uint8_t _sck, uint8_t _cd, uint8_t _reset);
    void lcdClear(bool invert);
    void lcdClearRow(uint8_t row, bool invert);
    void lcdPrintChar(uint8_t row, uint8_t col, char ch, bool invert);
    void lcdPrint(uint8_t row, uint8_t col, const char *str, bool invert);
    void lcdPrintP(uint8_t row, uint8_t col, const char *str, bool invert);
    void lcdImageP(uint8_t row, uint8_t col, const uint8_t *img, bool invert);
  private:
    uint8_t LCD_MOSI;
    uint8_t LCD_SCK;
    uint8_t LCD_CD;
    uint8_t LCD_RESET;
    
    void wait(uint16_t millis);
    //soft spi
    void sspiInit(uint8_t sck, uint8_t mosi, uint8_t miso);
    void sspiOutMSB(uint8_t sck, uint8_t mosi, uint16_t data, uint8_t bits);
    uint16_t sspiInMSB(uint8_t sck, uint8_t miso, uint8_t bits);
    uint16_t sspiInOutMSB(uint8_t sck, uint8_t mosi, uint8_t miso, uint16_t data, uint8_t bits);
    void sspiOutLSB(uint8_t sck, uint8_t mosi, uint16_t data, uint8_t bits);
    uint16_t sspiInLSB(uint8_t sck, uint8_t miso, uint8_t bits);
    uint16_t sspiInOutLSB(uint8_t sck, uint8_t mosi, uint8_t miso, uint16_t data, uint8_t bits);

};
