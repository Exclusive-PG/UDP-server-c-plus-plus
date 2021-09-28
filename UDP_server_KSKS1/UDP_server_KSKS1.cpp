#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#pragma comment ( lib, "ws2_32.lib" )
#include <stdio.h>
#include <winsock2.h>
#include <typeinfo>
#include <iostream>
#include <exception>
#include <string>
#include <locale.h>
#include <Windows.h>
#include "parserCommands.cpp"
#include "parserCMD.h"
#define PORT 7777    // порт сервера

//using namespace N;

char* commandServer(int* buff, int bfsize);

//parserCommands ParserCommands;
parserCMD ParserCommands;
int main(int argc, char* argv[])
{

    char buff[1024];
    setlocale(LC_ALL, "Russian");
    //char buffNEW[100] = "draw pix 200 200 255 255 255";
    //cout << ParserCommands.parserNew(buffNEW)[0]<<endl;
    //cout <<"" << parserNewsss((char*)"clear")[0] << endl;
    // подключение библиотеки 
    if (WSAStartup(0x202, (WSADATA*)&buff[0]))
    {
        printf("WSAStartup error: %d\n", WSAGetLastError());
        return -1;
    };

    // создание сокета
    SOCKET Socket;
    Socket = socket(AF_INET, SOCK_DGRAM, 0);
    if (Socket == INVALID_SOCKET)
    {
        printf("Socket() error: %d\n", WSAGetLastError());
        WSACleanup();
        return -1;
    };

    // связывание сокета с локальным адресом 
    sockaddr_in local_addr;
    local_addr.sin_family = AF_INET;
    local_addr.sin_addr.s_addr = INADDR_ANY;
    local_addr.sin_port = htons(PORT);

    if (bind(Socket, (sockaddr*)&local_addr, sizeof(local_addr)))
    {
        printf("bind error: %d\n", WSAGetLastError());
        system("pause");
        closesocket(Socket);
        WSACleanup();
        return -1;
    };
    printf("\nServer is listening...\n");
    // обработка пакетов, присланных клиентами
    while (1)
    {
        sockaddr_in client_addr;
        int client_addr_size = sizeof(client_addr);
        int bsize = recvfrom(Socket, &buff[0], sizeof(buff) - 1, 0, (sockaddr*)&client_addr, &client_addr_size);
        if (bsize == SOCKET_ERROR) {
            printf("recvfrom() error: %d\n", WSAGetLastError());
        };
        // Получаем IP-адрес клиента 
        HOSTENT* hst;
        hst = gethostbyaddr((char*)&client_addr.sin_addr, 4, AF_INET);
        printf("\n+%s [%s:%d] new message :", (hst) ? hst->h_name : "Unknown host", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // добавление завершающего нуля
        buff[bsize] = 0;

        // Вывод на экран 
        printf("%s\n", &buff);

        //cout << "PARSER:" << &commands[0] << endl;
        sendto(Socket, commandServer(ParserCommands.parserV2(buff), bsize), sizeof(buff), 0, (sockaddr*)&client_addr, sizeof(client_addr));
    }
    return 0;
}

char* commandErrorAlert(string cmd, string action) {

    string answerStr = "Command name: " + cmd + " - " + action;
    char answer[100];
    return (char*)strcpy(answer, answerStr.c_str());
}


char* commandServer(int* arrayWord, int bfsize) {
    COLORREF COLOR;
    HWND myconsole = GetConsoleWindow();
    HDC mydc = GetDC(myconsole);
    char* INPUT_ERROR = (char*)"Input Error";
    char* COMMAND_NOT_FOUND = (char*)"Command not found";
    char AnswerServer[100] = "OK";
    cout << "CMD : " << (int)arrayWord[0] << endl;
    switch ((int)arrayWord[0]) {

    case ParserCommands.CLEAR_DISPLAY:
        system("cls");
        printf("console cleared");
        return (char*)"Console cleared";
        break;

    case ParserCommands.DRAW_PIX:
        COLOR = RGB(arrayWord[3], arrayWord[4], arrayWord[5]);
        SetPixel(mydc, arrayWord[1], arrayWord[2], COLOR);

        ReleaseDC(myconsole, mydc);
        return (char*)"draw pix - success";
        break;
    case ParserCommands.DRAW_LINE:

        return (char*)"draw line - success";
        break;

        break;

    case ParserCommands.DRAW_REACTANGLE:

        return (char*)"DRAW_REACTANGLE - success";
        

        break;
    case ParserCommands.FILL_REACTANGLE:

        return (char*)"FILL_REACTANGLE - success";
        break;

    case ParserCommands.DRAW_ELLIPSE:

        return (char*)"DRAW_ELLIPSE - success";
        break;

    case ParserCommands.FILL_ELLIPSE:

        return (char*)"FILL_ELLIPSE - success";
        break;



    case ParserCommands.DRAW_CIRCLE:

        return (char*)"DRAW_CIRCLE - success";
        break;
    
    case ParserCommands.FILL_CIRCLE:

        return (char*)"FILL_CIRCLE - success";
        break;

    case ParserCommands.DRAW_ROUND_RECTANGLE:

        return (char*)"DRAW_ROUND_RECTANGLE - success";
        break;
    case ParserCommands.FILL_ROUND_RECTANGLE:

        return (char*)"FILL_ROUND_RECTANGLE - success";
        break;
    case ParserCommands.DRAW_TEXT:
        cout << ParserCommands.TEXT << endl;
        return (char*)"DRAW_TEXT - success";
        break;

    case ParserCommands.DRAW_IMG:
        cout << ParserCommands.NAME_IMG << endl;
        return (char*)"DRAW_IMG - success";
        break;

    case ParserCommands.SET_ORIN:

        return (char*)"SET_ORIN - success";
        break;

    case ParserCommands.GET_WIDTH:

        return (char*)"GET_WIDTH - success";
        break;

    case ParserCommands.GET_HEIGHT:

        return (char*)"GET_HEIGHT - success";
        break;

    case -999:
        return INPUT_ERROR;

    case 0:
        return COMMAND_NOT_FOUND;
    }

    ///Команды


       //Очистка консоли
      //if (arrayWord[0] == "clear") {
      //    system("cls");
      // 
      //    printf("console cleared");
      //    return (char*)"Console cleared";
      //}
      //// Рисование пикселя
      //else if (arrayWord[0] == "draw" && arrayWord[1] == "pix") {

      //    int x, y, RedColor, GreenColor, BlueColor;
      //   
      //    try
      //    {
      //        x = stoi(arrayWord[2]);
      //        y = stoi(arrayWord[3]);
      //        RedColor = stoi(arrayWord[4]);
      //        GreenColor = stoi(arrayWord[5]);
      //        BlueColor = stoi(arrayWord[6]);
      //        //printf("Command draw pix(x:%i,y:%i) and RGB(%i,%i,%i)", x, y, RedColor, GreenColor, BlueColor);

      //   
      //     COLOR = RGB(RedColor, GreenColor, BlueColor);

      //     SetPixel(mydc, x, y, COLOR);

      //     ReleaseDC(myconsole, mydc);
      //    // string strAnswer =  "Command draw pix(x:" + to_string(x) +",y:" + to_string(y)+")"+"and (" +to_string(RedColor) + "," + to_string(GreenColor)+ "," + to_string(GreenColor) + ")";
      //    // string strAnswer = "Command draw pix - success";
      //     //cout << strAnswer << endl;
      //    // strcpy(AnswerServer, strAnswer.c_str());
      //     return commandErrorAlert("draw pix", "success");
      //    }

      //    catch (const std::exception& ex)
      //    {
      //        cout << ex.what() << endl;
      //        cout << INPUT_ERROR << endl;
      //        return INPUT_ERROR;
      //    }
      //}
      //else if (arrayWord[0] == "draw" && arrayWord[1] == "line") {
      //    return commandErrorAlert("draw line","success");
      //}


      //else if (arrayWord[0] == "draw" && arrayWord[1] == "rectangle") {
      //    return commandErrorAlert("draw rectangle", "success");
      //}

      //else if (arrayWord[0] == "fill" && arrayWord[1] == "rectangle") {
      //    return commandErrorAlert("fill rectangle", "success");
      //}


      //else if (arrayWord[0] == "draw" && arrayWord[1] == "ellipse") {
      //    return commandErrorAlert("draw rectangle", "success");
      //}



      //else if (arrayWord[0] == "fill" && arrayWord[1] == "ellipse") {
      //    return commandErrorAlert("fill ellipse", "success");
      //}


      ////Расширенные команды
      //else if (arrayWord[0] == "draw" && arrayWord[1] == "circle") {
      //    return commandErrorAlert("draw circle", "success");
      //}
      //
      //else if (arrayWord[0] == "fill" && arrayWord[1] == "circle") {
      //    return commandErrorAlert("fill circle", "success");
      //}

      //else if (arrayWord[0] == "draw" && arrayWord[1]== "round" &&arrayWord[2] == "rectangle") {
      //    return commandErrorAlert("draw round rectangle", "success");
      //}

      //else if (arrayWord[0] == "fill" && arrayWord[1] == "round" && arrayWord[2] == "rectangle") {
      //    return commandErrorAlert("fill round rectangle", "success");
      //}

      //else if (arrayWord[0] == "draw" && arrayWord[1] == "text") {
      //    return commandErrorAlert("draw text", "success");
      //}
      //
      //else if (arrayWord[0] == "draw" && arrayWord[1] == "image") {
      //    return commandErrorAlert("draw image", "success");
      //}



      ////Продвинутый набор
      //else if (arrayWord[0] == "set" && arrayWord[1] == "orin") {
      //    return commandErrorAlert("set orin", "success");
      //}

      //else if (arrayWord[0] == "get" && arrayWord[1] == "w") {
      // return commandErrorAlert("get w", "success");
      //}

      //else if (arrayWord[0] == "get" && arrayWord[1] == "h") {
      //return commandErrorAlert("get h", "success");
      //}

      //else {
      //    printf(COMMAND_NOT_FOUND);
      //    return COMMAND_NOT_FOUND;
      //}


    return AnswerServer;
}