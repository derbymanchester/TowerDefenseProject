#pragma once

#include "cpoint.h"
#include "define.h"
#include <mutex>
#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")

class ctool 
{
    enum class Color {
        BLACK = 0,
        BLUE = 1,
        GREEN = 2,
        CYAN = 3,
        RED = 4,
        PURPLE = 5,
        BROWN = 6,
        LIGHT_GRAY = 7,
        DARK_GRAY = 8,
        LIGHT_BLUE = 9,
        LIGHT_GREEN = 10,
        LIGHT_CYAN = 11,
        LIGHT_RED = 12,
        LIGHT_PURPLE = 13,
        YELLOW = 14,
        WHITE = 15
    };
public:
    static mutex mtx;
    static bool sound_is_open;
    static void ShowConsoleCursor(bool showFlag);
    static void GotoXY(int x, int y);
    static void Draw(string str, int i, const vector<cpoint>& path, cpoint& _p);
    static bool printExit();
    static void printMenu();
	static void Settings();
    static void printAbout();
	static void drawAboutText();
    static void drawSettingText();
    static void drawEndGameText();
    static void drawSplash(int delayTime);
	static void drawTowerDefenseText();
    static void drawMapLevelText();
    static void drawGoodByeText(int delayTime);
    // static void drawReturningText();
   /* static void  printSave();
    static void printLoad();*/
    static void printRectangle(int, int, int, int);	
    void printCharactors(
        std::wstring content,
        COORD spot,
        Color text_color,
        Color background_color,
        short maxLength = -1
    );
    /*static bool saveGame(const string& playerName, const string& mapName, const vector<cenemy>& enemies);
    static bool loadGame(string& playerName, string& mapName, vector<cenemy>& enemies);*/
};

void setUpWindow();
void setWindowSize();
void setColor(int background, int text);
void setDefaultColor();
void hideScrollBar();
void hideCursor();
void setTitle();

void playSound(int audio_pos, int volume);
void stopSound();
void adjustSound(int& volume);
