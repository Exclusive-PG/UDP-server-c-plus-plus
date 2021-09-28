#include "pch.h"
#include "CppUnitTest.h"
#include "../UDP_server_KSKS1/parserCMD.h";

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		parserCMD parser;

		TEST_METHOD(WRONG_PARAMETR)
		{
			
			Assert::AreEqual(parser.parserV2("draw pix")[0], -999);
		};

		TEST_METHOD(COMMAND_NOT_FOUND)
		{

			Assert::AreEqual(parser.parserV2("asdasd")[0], 0);
		};
		//CLEAR DISPLAY 1
		TEST_METHOD(COMMAND_CLEAR_DISPLAY)
		{

			Assert::AreEqual(parser.parserV2("clear")[0], 1);
		};

		//DRAW PIX	2
		TEST_METHOD(COMMAND_DRAW_PIXEL)
		{

			Assert::AreEqual(parser.parserV2("draw pix 200 200 255 255 255")[0], 2);
		};

		//DRAW LINE 3
		TEST_METHOD(COMMAND_DRAW_LINE)
		{

			Assert::AreEqual(parser.parserV2("draw line 200 200 300 300 255 255 255")[0], 3);
		};

		//DRAW RECTANGLE 4
		TEST_METHOD(COMMAND_DRAW_RECTANGLE)
		{

			Assert::AreEqual(parser.parserV2("draw rectangle 200 200 100 50 255 255 255")[0], 4);
		};


		//FILL RECTANGLE 5
		TEST_METHOD(COMMAND_FILL_RECTANGLE)
		{

			Assert::AreEqual(parser.parserV2("fill rectangle 200 200 150 50 255 255 255")[0], 5);
		};

		//DRAW ELLIPSE 6
		TEST_METHOD(COMMAND_DRAW_ELLIPSE)
		{

			Assert::AreEqual(parser.parserV2("draw ellipse 200 200 50 50 255 255 255")[0], 6);
		};


		//FILL ELLIPSE  7
		TEST_METHOD(COMMAND_FILL_ELLIPSE)
		{

			Assert::AreEqual(parser.parserV2("fill ellipse 200 200 50 50 255 255 255")[0], 7);
		};

		//DRAW CIRCLE  8
		TEST_METHOD(COMMAND_DRAW_CIRCLE)
		{

			Assert::AreEqual(parser.parserV2("draw circle 200 200 50 255 255 255")[0], 8);
		};

		//FILL CIRCLE  9
		TEST_METHOD(COMMAND_FILL_CIRCLE)
		{

			Assert::AreEqual(parser.parserV2("draw circle 200 200 50 255 255 255")[0], 9);
		};

		//DRAW R RECTANGLE  10
		TEST_METHOD(COMMAND_DRAW_R_RECT)
		{

			Assert::AreEqual(parser.parserV2("draw round rectangle 200 200 50 100 50 255 255 255")[0], 10);
		};

		//FILL R RECTANGLE  11
		TEST_METHOD(COMMAND_FILL_R_RECT)
		{

			Assert::AreEqual(parser.parserV2("fill round rectangle 200 200 50 100 50 255 255 255")[0], 11);
		};

		//DRAW TEXT  12
		TEST_METHOD(COMMAND_TEXT)
		{

			Assert::AreEqual(parser.parserV2("draw text 200 200 20 4 hello 255 255 255")[0], 12);
		};
		//DRAW IMG  13
		TEST_METHOD(COMMAND_DRAW_IMG)
		{

			Assert::AreEqual(parser.parserV2("draw image 200 200 250 250 car")[0], 13);
		};

		//COMMAND_SET_ORIN  14
		TEST_METHOD(COMMAND_SET_ORIN)
		{

			Assert::AreEqual(parser.parserV2("set orin 500 500")[0], 14);
		};
		//COMMAND_GET_WIDTH  15
		TEST_METHOD(COMMAND_GET_WIDTH)
		{

			Assert::AreEqual(parser.parserV2("get width")[0], 15);
		};
		//COMMAND_GET_HEIGHT  16
		TEST_METHOD(COMMAND_GET_HEIGHT)
		{

			Assert::AreEqual(parser.parserV2("get height")[0], 16);
		};
	};
}
