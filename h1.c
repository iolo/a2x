#include <stdint.h>

uint16_t HB[]={
0x2000, 0x2400, 0x2800, 0x2C00, 0x3000, 0x3400, 0x3800, 0x3C00,
0x2080, 0x2480, 0x2880, 0x2C80, 0x3080, 0x3480, 0x3880, 0x3C80,
0x2100, 0x2500, 0x2900, 0x2D00, 0x3100, 0x3500, 0x3900, 0x3D00,
0x2180, 0x2580, 0x2980, 0x2D80, 0x3180, 0x3580, 0x3980, 0x3D80,
0x2200, 0x2600, 0x2A00, 0x2E00, 0x3200, 0x3600, 0x3A00, 0x3E00,
0x2280, 0x2680, 0x2A80, 0x2E80, 0x3280, 0x3680, 0x3A80, 0x3E80,
0x2300, 0x2700, 0x2B00, 0x2F00, 0x3300, 0x3700, 0x3B00, 0x3F00,
0x2380, 0x2780, 0x2B80, 0x2F80, 0x3380, 0x3780, 0x3B80, 0x3F80,
0x2028, 0x2428, 0x2828, 0x2C28, 0x3028, 0x3428, 0x3828, 0x3C28,
0x20A8, 0x24A8, 0x28A8, 0x2CA8, 0x30A8, 0x34A8, 0x38A8, 0x3CA8,
0x2128, 0x2528, 0x2928, 0x2D28, 0x3128, 0x3528, 0x3928, 0x3D28,
0x21A8, 0x25A8, 0x29A8, 0x2DA8, 0x31A8, 0x35A8, 0x39A8, 0x3DA8,
0x2228, 0x2628, 0x2A28, 0x2E28, 0x3228, 0x3628, 0x3A28, 0x3E28,
0x22A8, 0x26A8, 0x2AA8, 0x2EA8, 0x32A8, 0x36A8, 0x3AA8, 0x3EA8,
0x2328, 0x2728, 0x2B28, 0x2F28, 0x3328, 0x3728, 0x3B28, 0x3F28,
0x23A8, 0x27A8, 0x2BA8, 0x2FA8, 0x33A8, 0x37A8, 0x3BA8, 0x3FA8,
0x2050, 0x2450, 0x2850, 0x2C50, 0x3050, 0x3450, 0x3850, 0x3C50,
0x20D0, 0x24D0, 0x28D0, 0x2CD0, 0x30D0, 0x34D0, 0x38D0, 0x3CD0,
0x2150, 0x2550, 0x2950, 0x2D50, 0x3150, 0x3550, 0x3950, 0x3D50,
0x21D0, 0x25D0, 0x29D0, 0x2DD0, 0x31D0, 0x35D0, 0x39D0, 0x3DD0,
0x2250, 0x2650, 0x2A50, 0x2E50, 0x3250, 0x3650, 0x3A50, 0x3E50,
0x22D0, 0x26D0, 0x2AD0, 0x2ED0, 0x32D0, 0x36D0, 0x3AD0, 0x3ED0,
0x2350, 0x2750, 0x2B50, 0x2F50, 0x3350, 0x3750, 0x3B50, 0x3F50,
0x23D0, 0x27D0, 0x2BD0, 0x2FD0, 0x33D0, 0x37D0, 0x3BD0, 0x3FD0};

#define ASC_BEGIN 0x20
#define KOR_BEGIN 0xAC00
#define NUM_CHO 19
#define NUM_JUNG 21
#define NUM_JONG 28 // with filler
#define CHO_KIND 3
#define JUNG_KIND 1
#define JONG_KIND 1
#define ASC_WIDTH 7
#define ASC_WIDTH_BYTE 1
#define KOR_WIDTH 14
#define KOR_WIDTH_BYTE 2
#define FONT_HEIGHT 12

#include "font.c"

const uint8_t cho_kind_by_jung[NUM_JONG] = {
//ㅏ,ㅐ,ㅑ,ㅒ,ㅓ,ㅔ,ㅕ,ㅖ,ㅗ,ㅘ,ㅙ,ㅚ,ㅛ,ㅜ,ㅝ,ㅞ,ㅟ,ㅠ,ㅡ,ㅢ,ㅣ
  0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 2, 2, 1, 1, 2, 2, 2, 1, 1, 2, 0,
};

/*
// 1 x 8
uint8_t font8[] = {
  0b0000000,
  0b0011110,
  0b0100010,
  0b0011110,
  0b0100010,
  0b0100010,
  0b0011110,
  0b0000000,
};

// 2 x 16
uint8_t font16[] = {
  0b0000000, 0b0000000,
  0b0001000, 0b0000100,
  0b0111110, 0b0000100,
  0b0010100, 0b0000100,
  0b0100010, 0b0000100,
  0b0100010, 0b0111100,
  0b0011100, 0b0000100,
  0b0000000, 0b0000100,
  0b0000000, 0b0000100,
  0b0000000, 0b0000100,
  0b0001000, 0b0000100,
  0b0001000, 0b0000000,
  0b0001000, 0b0000000,
  0b1111000, 0b0001111,
  0b0000000, 0b0000000,
  0b0000000, 0b0000000,
};
*/

void putbyte(uint8_t x, uint8_t y, uint8_t c) {
  uint8_t* vaddr = (uint8_t*)(HB[y] + x);
  *vaddr = c;
}

void put2byte(uint8_t x, uint8_t y, uint8_t byte1, uint8_t byte2) {
  uint8_t* vaddr = (uint8_t*)(HB[y] + x);
  *vaddr = byte1;
  *(vaddr + 1) = byte2;
}

void putbyte_or(uint8_t x, uint8_t y, uint8_t c) {
  uint8_t* vaddr = (uint8_t*)(HB[y] + x);
  *vaddr |= c;
}

void put2byte_or(uint8_t x, uint8_t y, uint8_t byte1, uint8_t byte2) {
  uint8_t* vaddr = (uint8_t*)(HB[y] + x);
  *vaddr |= byte1;
  *(vaddr + 1) |= byte2;
}

void putfont8(uint8_t x, uint8_t y, uint8_t* font) {
  uint8_t i;
  for(i = 0; i < 8; i++) {
    putbyte(x, y + i, font[i]);
  }
}

void putfont16(uint8_t x, uint8_t y, uint8_t* font) {
  uint8_t i, p;
  for(i = 0, p = 0; i < 16; i++) {
    put2byte(x, y + i, font[p++], font[p++]);
  }
}

void putasc(uint8_t x, uint8_t y, uint8_t* font) {
  uint8_t i;
  for(i = 0; i < FONT_HEIGHT; i++) {
    putbyte(x, y + i, font[i]);
  }
}

void puthan(uint8_t x, uint8_t y, uint8_t* cho, uint8_t* jung, uint8_t* jong) {
  uint8_t i, p;
  for(i = 0, p = 0; i < FONT_HEIGHT; i++, p+=2) {
    if (cho) {
      put2byte(x, y + i, cho[p], cho[p+1]);
    }
    if (jung) {
      put2byte_or(x, y + i, jung[p], jung[p+1]);
    }
    if (jong) {
      put2byte_or(x, y + i, jong[p], jong[p+1]);
    }
  }
}

int8_t putucs2(uint8_t x, uint8_t y, uint16_t code) {
  uint16_t index, i, p;
  uint8_t cho, jung, jong, cho_index, jung_index, jong_index;
  if (code < 0x20) {
    return 0;
  }
  if (code < 0x80) {
    for(i = 0; i < 12; i++) {
      putbyte(x, y + i, asc[code - ASC_BEGIN][i]);
    }
    return 1;
  }
  index = code - KOR_BEGIN;
  cho = index / (NUM_JUNG * NUM_JONG);
  jung = (index % (NUM_JUNG * NUM_JONG)) / NUM_JONG;
  jong = index % NUM_JONG;
  cho_index = NUM_CHO * cho_kind_by_jung[jung] + cho;
  jung_index = CHO_KIND*NUM_CHO + jung;
  jong_index = CHO_KIND*NUM_CHO + JUNG_KIND*NUM_JUNG + jong;
  for(i = 0, p = 0; i < FONT_HEIGHT; i++, p+=2) {
    put2byte(x, y + i, han[cho_index][p] | han[jung_index][p] | han[jong_index][p], han[cho_index][p + 1] | han[jung_index][p + 1] | han[jong_index][p + 1]);
  }
  return 2;
}

void putucs2str(uint8_t x, uint8_t y, uint16_t* str) {
  uint16_t* p = str;
  while(*p != 0) {
    x += putucs2(x, y, *p++);
    if (x > 38) {
      x = 0;
      y += 12;
    }
  }
}

void pututf8str(uint8_t x, uint8_t y, uint8_t* str) {
  uint8_t* p = str;
  uint8_t byte1, byte2, byte3, byte4;
  uint16_t code;
  while(*p != 0) {
    byte1 = *p++;
    if (byte1 < 0b10000000) {
      // 0xxxxxxx -> 0x00..0x7f
      code = byte1;
    } else if (byte1 < 0b11000000) {
      byte2 = *p++;
      // 110xxxxx 10xxxxxx -> 0x80..0x07ff (11bits)
      code = ((byte1 & 0b00011111) << 6) | (byte2 & 0b00111111);
    } else if (byte1 < 0b11110000) {
      byte2 = *p++;
      byte3 = *p++;
      // 1110xxxx 10xxxxxx 10xxxxxx -> 0x800..0xffff (16bits)
      code = ((byte1 & 0b00001111) << 12) | ((byte2 & 0b00111111) << 6) | (byte3 & 0b00111111);
    } else if (byte1 < 0b11111000) {
      byte2 = *p++;
      byte3 = *p++;
      byte4 = *p++;
      // 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx -> 0x10000..0x10ffff (21bits)
      //code = ((byte1 & 0b00000111) << 18) | ((byte2 & 0b00111111) << 12) | ((byte3 & 0b00111111) << 6) | (byte4 & 0b00111111);
      // unsupported!
      code = 0x7f;
    } else {
      // 10xxxxxx -> 0x80..0xbf???
      // unsupported!
      code = 0x7f;
    }
    // utf8 -> ucs2 -> split cho+jung+jong -> put
    x += putucs2(x, y, code);
    if (x > 38) {
      x = 0;
      y += FONT_HEIGHT;
    }
  }
}




void color_test() {
  uint8_t x, y, palette, color, byte1, byte2, yb = 0;
  // palette = 0, color = 00 black(00,00), 01 green(2a,55), 10 megenta(55,aa), 11 white(7f,7f)
  // palette = 1, color = 00 black(80,80), 01 cyan(aa,d5), 10 red(d5,aa), 11 white(ff,ff)
  // byte1 = p aa bb cc d
  // byte2 = p gg ff ee d
  for(palette = 0; palette < 2; palette++) {
    for (color = 0; color < 4; color++) {
      //color = 0b00
      //byte1 = 0b0 00 00 00 0;
      //byte2 = 0b0 00 00 00 0;
      //color = 0b01
      //byte1 = 0b0 01 01 01 0;
      //byte2 = 0b0 10 10 10 1;
      //color = 0b10
      //byte1 = 0b0 10 10 10 1;
      //byte2 = 0b0 01 01 01 0;
      //color = 0b11
      //byte1 = 0b0 11 11 11 1;
      //byte2 = 0b0 11 11 11 1;
      byte1 = (color << 5) | (color << 3) | (color << 1) | (color >> 1);
      byte2 = (color << 6) | (color << 4) | (color << 2) | color;
      if (palette) {
        byte1 |= 0x80;
        byte2 |= 0x80;
      } else {
        byte1 &= 0x7f;
        byte2 &= 0x7f;
      }
      for (x = 0; x < 40; x+=2) {
        for (y = yb; y < yb+20; y++) {
          putbyte(x, y, byte1);
          putbyte(x+1, y, byte2);
        }
      }
      yb += 20;
    }
  }
}

#define NUM_ASC_FONT (0x7f-0x20)
void font8_test() {
  uint8_t x, y, n;
  n = 0;
  for (y = 0; y < 72; y+=12) {
    for (x = 0; x < 40; x++) {
      //putfont8(x, y, asc[n]);
      putasc(x, y, asc[n]);
      if (++n > NUM_ASC_FONT) {
        n = 0;
      }
    }
  }
}

#define NUM_HAN_FONT (NUM_CHO*CHO_KIND + NUM_JUNG*JUNG_KIND + NUM_JONG*JONG_KIND)

void font16_test() {
  uint8_t x, y, n;
  n = 0;
  for (y = 72; y < 160; y+=12) {
    for (x = 0; x < 40; x+=2) {
      putfont16(x, y, han[n]);
      if (++n > 20) {
        n = 0;
      }
    }
  }
}

uint16_t ucs2_sample[] = {
  'H', 'e', 'l', 'l', 'o', ',', 'W', 'o', 'r', 'l', 'd', '!', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
  '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '=', '+', '[', ']', '{', '}', ';', ':', '\'', '"', ',', '.', '/', '?',
  0xd55c, 0xae00, 0xc740, 0x20, 0xc544, 0xb984, 0xb2f5, 0xb2e4, 0x20, 0xadf8, 0xb7ec, 0xb098, 0x20, 0xace8, 0xce58, 0xc544, 0xd504, 0xb2e4, 0x2e,
  0,
};

uint8_t* utf8_sample = "Hello,World! 1234567890!@#$%^&*()-=_+[]{};:<>,./?한글은 아름답다 그러나 골치아프다!";

int main() {
  //color_test();
  //font8_test();
  //font16_test();
  putucs2str(0, 0, (uint16_t*)ucs2_sample);
  putucs2str(0, 30, (uint16_t*)ucs2_sample);
  pututf8str(0, 60, utf8_sample);
  pututf8str(0, 90, utf8_sample);
  return 0;
}

