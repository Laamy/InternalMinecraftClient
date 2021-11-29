#pragma once

#include <wchar.h>

extern char BASE_CHARACTER[2]; // who the fuck cpo[y [pasted this from horion
extern char BLACK[4];
extern char DARK_BLUE[4];
extern char DARK_GREEN[4];
extern char DARK_AQUA[4];
extern char DARK_RED[4];
extern char DARK_PURPLE[4];
extern char GOLD[4];
extern char GRAY[4];
extern char DARK_GRAY[4];
extern char BLUE[4];
extern char GREEN[4];
extern char AQUA[4];
extern char RED[4];
extern char LIGHT_PURPLE[4];
extern char YELLOW[4];
extern char WHITE[4];

extern char OBFUSCATED[4];
extern char BOLD[4];
extern char STRIKETHROUGH[4];
extern char UNDERLINE[4];
extern char ITALIC[4];
extern char RESET[4];

extern void initColor(char* character, char color) {
	character[0] = BASE_CHARACTER[0];
	character[1] = BASE_CHARACTER[1];
	character[2] = color;
	character[3] = 0x0;
}

extern void init() {
	BASE_CHARACTER[0] = (char)(0xC2);
	BASE_CHARACTER[1] = (char)(0xA7);
	initColor(BLACK, '0');
	initColor(DARK_BLUE, '1');
	initColor(DARK_GREEN, '2');
	initColor(DARK_AQUA, '3');
	initColor(DARK_RED, '4');
	initColor(DARK_PURPLE, '5');
	initColor(GOLD, '6');
	initColor(GRAY, '7');
	initColor(DARK_GRAY, '8');
	initColor(BLUE, '9');
	initColor(GREEN, 'a');
	initColor(AQUA, 'b');
	initColor(RED, 'c');
	initColor(LIGHT_PURPLE, 'd');
	initColor(YELLOW, 'e');
	initColor(WHITE, 'f');

	initColor(OBFUSCATED, 'k');
	initColor(BOLD, 'l');
	initColor(STRIKETHROUGH, 'm');
	initColor(UNDERLINE, 'n');
	initColor(ITALIC, 'o');
	initColor(RESET, 'r');
}