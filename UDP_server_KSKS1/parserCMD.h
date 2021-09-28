#pragma once
#include <string>
using namespace std;

//namespace N {
class parserCMD
{
public:
	//string* parser(char buff[]);
	int* parserV2(char buff[]);
	static constexpr int CLEAR_DISPLAY = 1;
	static constexpr int DRAW_PIX = 2;
	static constexpr int DRAW_LINE = 3;
	static constexpr int DRAW_REACTANGLE = 4;
	static constexpr int FILL_REACTANGLE = 5;
	static constexpr int DRAW_ELLIPSE = 6;
	static constexpr int FILL_ELLIPSE = 7;


	//2nd LVL
	static constexpr int DRAW_CIRCLE = 8;
	static constexpr int FILL_CIRCLE = 9;
	static constexpr int DRAW_ROUND_RECTANGLE = 10;
	static constexpr int FILL_ROUND_RECTANGLE =11;
	static constexpr int DRAW_TEXT = 12;
	static constexpr int DRAW_IMG = 13;


	//ADVANCED LVL
	static constexpr int SET_ORIN = 14;
	static constexpr int GET_WIDTH = 15;
	static constexpr int GET_HEIGHT = 16;

	 string NAME_IMG = "";
	 string TEXT = "";


};

//}
