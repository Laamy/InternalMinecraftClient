#include "../Utils/Math.h"

/*struct FontEntry {
public:
	class BitmapFont* font;
};

struct FontList {
public:
	FontEntry fontEntries[7];
};

struct FontRepos {
private:
	char pad_0x000[0x28];  //0x0000
public:
	FontList* fontList;   //0x0028
};*/

class MinecraftGame {
private:
	char pad_0x000[0x108];  //0x0000
public:
	class BitmapFont* defaultGameFont; //0x0108

	//FontRepos* fontRepos; // 0xF8

/*public: // Custom voids
	class BitmapFont* Font1() {
		return fontRepos->fontList->fontEntries[7].font;
	};

	class BitmapFont* Font2() {
		return fontRepos->fontList->fontEntries[3].font;
	}*/
}; // 0x110