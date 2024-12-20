// ctool.cpp
#include "ctool.h"
#include "cenemy.h"
#include "ctower.h"
#include "cpoint.h"
#include "cbullet.h"
#include "cmap.h"
#include "windows.h"
#include "iomanip"

HANDLE consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
HWND consoleWindow = GetConsoleWindow();
std::mutex ctool::mtx;

bool ctool::sound_is_open;
void ctool::ShowConsoleCursor(bool showFlag) {
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleOutput, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(consoleOutput, &cursorInfo);
}

void ctool::GotoXY(int x, int y) {

    COORD crd = { x, y };
    SetConsoleCursorPosition(consoleOutput, crd);
}

void ctool::Draw(string str, int i, const vector<cpoint>& p, cpoint& _p) {
    std::lock_guard<std::mutex> lock(mtx);
    _p = p[i];
    ctool::GotoXY(_p.getX(), _p.getY());
    cout << str << TEXT_BLACK_BG_LIGHT_YELLOW;
}

void ctool::drawSettingText() {
    int x, y;
    x = 35;
    y = 2;

	ctool tool;

    tool.printCharactors(L"░██████╗███████╗████████╗████████╗██╗███╗░░██╗░██████╗░", { short(x),short(y) }, Color::BLACK, Color::YELLOW);
    tool.printCharactors(L"██╔════╝██╔════╝╚══██╔══╝╚══██╔══╝██║████╗░██║██╔════╝░", { short(x),short(y + 1) }, Color::BLACK, Color::YELLOW);
    tool.printCharactors(L"╚█████╗░█████╗░░░░░██║░░░░░░██║░░░██║██╔██╗██║██║░░██╗░", { short(x),short(y + 2) }, Color::BLACK, Color::YELLOW);
    tool.printCharactors(L"░╚═══██╗██╔══╝░░░░░██║░░░░░░██║░░░██║██║╚████║██║░░╚██╗", { short(x),short(y + 3) }, Color::BLACK, Color::YELLOW);
    tool.printCharactors(L"██████╔╝███████╗░░░██║░░░░░░██║░░░██║██║░╚███║╚██████╔╝", { short(x),short(y + 4) }, Color::BLACK, Color::YELLOW);
    tool.printCharactors(L"╚═════╝░╚══════╝░░░╚═╝░░░░░░╚═╝░░░╚═╝╚═╝░░╚══╝░╚═════╝░", { short(x),short(y + 5) }, Color::BLACK, Color::YELLOW);

}

void ctool::drawEndGameText() {
    int x, y;
    x = 30;
    y = 13;  

    ctool tool;

    tool.printCharactors(L"███████╗███╗░░██╗██████╗░░░░░██████╗░░█████╗░░███╗░░░███╗░███████╗", { short(x), short(y) }, Color::RED, Color::YELLOW);
    tool.printCharactors(L"██╔════╝████╗░██║██╔══██╗░░░██╔════╝░██╔══██╗░████╗░████║░██╔════╝", { short(x), short(y + 1) }, Color::RED, Color::YELLOW);
    tool.printCharactors(L"█████╗░░██╔██╗██║██║░░██║░░░██║░░██╗░███████║░██╔████╔██║░█████╗░░", { short(x), short(y + 2) }, Color::RED, Color::YELLOW);
    tool.printCharactors(L"██╔══╝░░██║╚████║██╔══██║░░░██║░░╚██╗██╔══██║░██║╚██╔╝██║░██╔══╝░░", { short(x), short(y + 3) }, Color::RED, Color::YELLOW);
    tool.printCharactors(L"███████╗██║░╚███║██████╔╝░░░╚██████╔╝██║░░██║░██║░╚═╝░██║░███████╗", { short(x), short(y + 4) }, Color::RED, Color::YELLOW);

}

void ctool::drawGoodByeText(int delayTime) {
    int x, y;
    x = 25;
    y = 2;

    ctool tool;
    Sleep(delayTime);
    tool.printCharactors(L"--  _____                                                              _____ ", { short(x),short(y + 0) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);
    tool.printCharactors(L"-- ( ___ )                                                            ( ___ )", { short(x),short(y + 1) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);
    tool.printCharactors(L"--  |   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|   | ", { short(x),short(y + 2) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);
    tool.printCharactors(L"--  |   |  ▄▄▄▄▄▄▄▄▄▄▄  ▄         ▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄        ▄  ▄    ▄  |   | ", { short(x),short(y + 3) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);
    tool.printCharactors(L"--  |   | ▐░░░░░░░░░░░▌▐░▌       ▐░▌▐░░░░░░░░░░░▌▐░░▌      ▐░▌▐░▌  ▐░▌ |   | ", { short(x),short(y + 4) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);
    tool.printCharactors(L"--  |   |  ▀▀▀▀█░█▀▀▀▀ ▐░▌       ▐░▌▐░█▀▀▀▀▀▀▀█░▌▐░▌░▌     ▐░▌▐░▌ ▐░▌  |   | ", { short(x),short(y + 5) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);
    tool.printCharactors(L"--  |   |      ▐░▌     ▐░▌       ▐░▌▐░▌       ▐░▌▐░▌▐░▌    ▐░▌▐░▌▐░▌   |   | ", { short(x),short(y + 6) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);
    tool.printCharactors(L"--  |   |      ▐░▌     ▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄█░▌▐░▌ ▐░▌   ▐░▌▐░▌░▌    |   | ", { short(x),short(y + 7) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);
    tool.printCharactors(L"--  |   |      ▐░▌     ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░▌  ▐░▌  ▐░▌▐░░▌     |   | ", { short(x),short(y + 8) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);
    tool.printCharactors(L"--  |   |      ▐░▌     ▐░█▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀█░▌▐░▌   ▐░▌ ▐░▌▐░▌░▌    |   | ", { short(x),short(y + 9) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);
    tool.printCharactors(L"--  |   |      ▐░▌     ▐░▌       ▐░▌▐░▌       ▐░▌▐░▌    ▐░▌▐░▌▐░▌▐░▌   |   | ", { short(x),short(y + 10) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);
    tool.printCharactors(L"--  |   |      ▐░▌     ▐░▌       ▐░▌▐░▌       ▐░▌▐░▌     ▐░▐░▌▐░▌ ▐░▌  |   | ", { short(x),short(y + 11) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);
    tool.printCharactors(L"--  |   |      ▐░▌     ▐░▌       ▐░▌▐░▌       ▐░▌▐░▌      ▐░░▌▐░▌  ▐░▌ |   | ", { short(x),short(y + 12) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);
    tool.printCharactors(L"--  |   |       ▀       ▀         ▀  ▀         ▀  ▀        ▀▀  ▀    ▀  |   | ", { short(x),short(y + 13) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);
    tool.printCharactors(L"--  |   |                                                              |   | ", { short(x),short(y + 14) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);
    tool.printCharactors(L"--  |   |              ▄         ▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄         ▄           |   | ", { short(x),short(y + 15) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);
    tool.printCharactors(L"--  |   |             ▐░▌       ▐░▌▐░░░░░░░░░░░▌▐░▌       ▐░▌          |   | ", { short(x),short(y + 16) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);
    tool.printCharactors(L"--  |   |             ▐░▌       ▐░▌▐░█▀▀▀▀▀▀▀█░▌▐░▌       ▐░▌          |   | ", { short(x),short(y + 17) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);
    tool.printCharactors(L"--  |   |             ▐░▌       ▐░▌▐░▌       ▐░▌▐░▌       ▐░▌          |   | ", { short(x),short(y + 18) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);
    tool.printCharactors(L"--  |   |             ▐░█▄▄▄▄▄▄▄█░▌▐░▌       ▐░▌▐░▌       ▐░▌          |   | ", { short(x),short(y + 19) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);
    tool.printCharactors(L"--  |   |             ▐░░░░░░░░░░░▌▐░▌       ▐░▌▐░▌       ▐░▌          |   | ", { short(x),short(y + 20) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);
    tool.printCharactors(L"--  |   |              ▀▀▀▀█░█▀▀▀▀ ▐░▌       ▐░▌▐░▌       ▐░▌          |   | ", { short(x),short(y + 21) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);
    tool.printCharactors(L"--  |   |                  ▐░▌     ▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄█░▌          |   | ", { short(x),short(y + 22) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);
    tool.printCharactors(L"--  |   |                  ▐░▌     ▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄█░▌          |   | ", { short(x),short(y + 23) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);
    tool.printCharactors(L"--  |   |                  ▐░▌     ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌          |   | ", { short(x),short(y + 24) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime); 
    tool.printCharactors(L"--  |   |                   ▀       ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀           |   | ", { short(x),short(y + 25) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);
    tool.printCharactors(L"--  |___|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|___| ", { short(x),short(y + 26) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);
    tool.printCharactors(L"-- (_____)                                                            (_____)", { short(x),short(y + 27) }, Color::BLACK, Color::YELLOW);
    Sleep(500);
}

void ctool::drawMapLevelText() {
    int x, y;
    x = 35;
    y = 2;

    ctool tool;

    tool.printCharactors(L"██╗     ███████╗██╗   ██╗███████╗██╗     ", { short(x),short(y) }, Color::BLACK, Color::YELLOW);
    tool.printCharactors(L"██║     ██╔════╝██║   ██║██╔════╝██║     ", { short(x),short(y + 1) }, Color::BLACK, Color::YELLOW);
    tool.printCharactors(L"██║     █████╗  ██║   ██║█████╗  ██║     ", { short(x),short(y + 2) }, Color::BLACK, Color::YELLOW);
    tool.printCharactors(L"██║     ██╔══╝  ╚██╗ ██╔╝██╔══╝  ██║     ", { short(x),short(y + 3) }, Color::BLACK, Color::YELLOW);
    tool.printCharactors(L"███████╗███████╗ ╚████╔╝ ███████╗███████╗", { short(x),short(y + 4) }, Color::BLACK, Color::YELLOW);
    tool.printCharactors(L"╚══════╝╚══════╝  ╚═══╝  ╚══════╝╚══════╝", { short(x),short(y + 5) }, Color::BLACK, Color::YELLOW);

}


void ctool::printCharactors(
    std::wstring content,
    COORD spot,
    Color text_color,
    Color background_color,
    short maxLength
) {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD Written;

    // convert text color and background color to WORD that in range of 0-265 in color code table
    int color = (int)text_color + (int)background_color * 16;

    // if the content is too long
    if (maxLength != -1) {
        content = content.substr(0, maxLength) + L"...";
    }

    for (int i = 0; i < content.length(); i++) {
        // set text background color
        FillConsoleOutputAttribute(hOut, color, 1, spot, &Written);

        // print 1 character 
        FillConsoleOutputCharacterW(hOut, content[i], 1, spot, &Written);
        spot.X++;
    }
}



void ctool::drawAboutText() {
    int x, y;
    x = 40;
    y = 2;

    ctool tool;
    tool.printCharactors(L"░█████╗░██████╗░░█████╗░██╗░░░██╗████████╗", { short(x),short(y + 0) }, Color::BLACK, Color::YELLOW);
    tool.printCharactors(L"██╔══██╗██╔══██╗██╔══██╗██║░░░██║╚══██╔══╝", { short(x),short(y + 1) }, Color::BLACK, Color::YELLOW);
    tool.printCharactors(L"███████║██████╦╝██║░░██║██║░░░██║░░░██║░░░", { short(x),short(y + 2) }, Color::BLACK, Color::YELLOW);
    tool.printCharactors(L"██╔══██║██╔══██╗██║░░██║██║░░░██║░░░██║░░░", { short(x),short(y + 3) }, Color::BLACK, Color::YELLOW);
    tool.printCharactors(L"██║░░██║██████╦╝╚█████╔╝╚██████╔╝░░░██║░░░", { short(x),short(y + 4) }, Color::BLACK, Color::YELLOW);
    tool.printCharactors(L"╚═╝░░╚═╝╚═════╝░░╚════╝░░╚═════╝░░░░╚═╝░░░", { short(x),short(y + 5) }, Color::BLACK, Color::YELLOW);
}

void ctool::printAbout() {
    system("cls");
    system("color E3");
	ctool::drawAboutText();
    GotoXY(20, 10);

    // Hiển thị thông tin về game
    setColor(14, 12);
    std::cout << "\n\t\t\t----- TOWER DEFENSE -----\n";
    setColor(14, 0);
    std::cout << "\n\t\t\tTower Defense, also known as Tower Defense Game, is a subgenre of real-time strategy games.\n";
    std::cout << "\t\t\tIn this game, players must defend a structure or area from waves of enemies.\n";
    std::cout << "\t\t\tThe goal is to prevent the enemies from reaching your base.\n";
    std::cout << "\t\t\tIf the enemies reach your base, the game will be end and you LOST. Whearas, you WON the game\n";
    std::cout << "\n\t\t\tPress ESC to go back to the main menu.\n";

    setColor(14, 12);
    std::cout << "\n\t\t\t----- GROUP 4 -----\n";
    setColor(14, 0);
    std::cout << "\n\t\t\t1. Dinh Anh Duong \n";
    std::cout << "\t\t\t2. Nguyen Van Hop\n";
    std::cout << "\t\t\t3. Tran So Vinh\n";
    std::cout << "\t\t\t4. Nguyen Nhat Hoang\n";

    // Thêm thông tin người hướng dẫn
    setColor(14, 12);
    std::cout << "\n\t\t\t----- INSTRUCTOR -----\n";
    setColor(14, 0);
    std::cout << "\n\t\t\tMR Truong Toan Thinh\n";

    setDefaultColor();

    // Chờ người dùng nhấn phím ESC để quay lại
    while (true) {
		setColor(14, 3);
        char ch = _getch();
        if (ch == 27) {  // Phím ESC để quay lại
            system("cls");
            drawTowerDefenseText();
            break;
        }
    }
}

void ctool::printRectangle(int left, int top, int width, int height)
{
    ctool::GotoXY(left, top);
    putchar(218);  // Góc trên bên trái
    for (int i = 0; i < width; i++) {
        putchar(196);  // Dòng ngang trên
    }
    putchar(191);  // Góc trên bên phải

    // Vẽ các dòng bên hông
    for (int i = 0; i < height; i++)
    {
        ctool::GotoXY(left, top + i + 1);
        putchar(179);  // Dòng bên trái
        ctool::GotoXY(left + width + 1, top + i + 1);
        putchar(179);  // Dòng bên phải
    }

    // Vẽ đáy của hình chữ nhật
    ctool::GotoXY(left, top + height + 1);
    putchar(192);  // Góc dưới bên trái
    for (int i = 0; i < width; i++)
        putchar(196);  // Dòng ngang dưới
    putchar(217);  // Góc dưới bên phải

    setColor(14, 3);  // Khôi phục lại màu sắc mặc định
}

bool ctool::printExit()
{
	system("cls");
    std::cout << "Do you want to exit ? [0 == yes / 1 == no]\n";
    int option = _getch();

    while (option != '0' && option != '1')
    {
        std::cout << "Please type 0 or 1.\n";
        option = _getch();
    }

    if (option == '0')
    {
        system("cls");
        std::cout << "Thank you for playing this game !\n";
        drawGoodByeText(100);
        exit(0);
    }
    std::cout << "Returning...\n";
    Sleep(500);
    system("cls");
    drawTowerDefenseText();

    return false;
}



void ctool::drawSplash(int delayTime) {
    int x, y;
    x = 25;
    y = 2;

	ctool tool;
    Sleep(delayTime);
    tool.printCharactors(L"████████╗ ██████╗ ██╗    ██╗███████╗██████╗               ", { short(x),short(y + 0) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);
    tool.printCharactors(L"╚══██╔══╝██╔═══██╗██║    ██║██╔════╝██╔══██╗              ", { short(x),short(y + 1) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);
    tool.printCharactors(L"   ██║   ██║   ██║██║ █╗ ██║█████╗  ██████╔╝              ", { short(x),short(y + 2) }, Color::BLACK, Color::YELLOW);
	Sleep(delayTime);
    tool.printCharactors(L"   ██║   ██║   ██║██║███╗██║██╔══╝  ██╔══██╗              ", { short(x),short(y + 3) }, Color::BLACK, Color::YELLOW);
	Sleep(delayTime);
    tool.printCharactors(L"   ██║   ╚██████╔╝╚███╔███╔╝███████╗██║  ██║              ", { short(x),short(y + 4) }, Color::BLACK, Color::YELLOW);
	Sleep(delayTime);
    tool.printCharactors(L"   ╚═╝    ╚═════╝  ╚══╝╚══╝ ╚══════╝╚═╝  ╚═╝              ", { short(x),short(y + 5) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);
	y += 7;
    tool.printCharactors(L"                 ██████╗ ███████╗███████╗███████╗███╗   ██╗███████╗███████╗", { short(x),short(y + 0) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);
    tool.printCharactors(L"                 ██╔══██╗██╔════╝██╔════╝██╔════╝████╗  ██║██╔════╝██╔════╝", { short(x),short(y + 1) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);   
    tool.printCharactors(L"                 ██║  ██║█████╗  █████╗  █████╗  ██╔██╗ ██║███████╗█████╗  ", { short(x),short(y + 2) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);
    tool.printCharactors(L"                 ██║  ██║██╔══╝  ██╔══╝  ██╔══╝  ██║╚██╗██║╚════██║██╔══╝  ", { short(x),short(y + 3) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);
    tool.printCharactors(L"                 ██████╔╝███████╗██║     ███████╗██║ ╚████║███████║███████╗", { short(x),short(y + 4) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);
    tool.printCharactors(L"                 ╚═════╝ ╚══════╝╚═╝     ╚══════╝╚═╝  ╚═══╝╚══════╝╚══════╝", { short(x),short(y + 5) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);

	y -= 9;

    tool.printCharactors(L"▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░            ▓▒▒░ ░░░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒                 ", { short(x),short(y + 0) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);
    tool.printCharactors(L"▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░    █▒▒ ░░▓   ▓░   ░█░ ░░░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒                 ", { short(x),short(y + 1) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);
    tool.printCharactors(L"▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░   ▒▓▓▒█░░▓▒▒▒░░░▒░░░▒▒▓▓▓█░░░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒                 ", { short(x),short(y + 2) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);
    tool.printCharactors(L"▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░    ▓   ▒▓▒▒▒▒░▒░▒▒░░░█░░▒▓▓   ░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒                 ", { short(x),short(y + 3) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);
    tool.printCharactors(L"▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░      ▒░▒░▒▓▓▓▓▒▒▒▒▓▓▒▓▒ ▒▒▒▒▓    ░░░░░░▒▒▒▒▒▒▒▒▒▒▒                 ", { short(x),short(y + 4) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);

    tool.printCharactors(L"▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░       ▓▒▒▒▒▒▒▒▓▓▓▒░░▓▓▒▒▓▒▒▒▒▓▒    ░░░░░▒▒▒▒▒▒▒▒▒▒▒                 ", { short(x),short(y + 5) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);
    tool.printCharactors(L"▒▒▒▒▒▒▒▒▒▒▒░░░░░░       █▓▓▒▒▒▒▒▒▒▒▒░▓░░░░░▒▒▒▒▒▓▒▒    ░░░░░▒▒▒▒▒▒▒▒▒▒                ", { short(x),short(y + 6) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);
    tool.printCharactors(L"▒▒▒▒▒▒▒▒▒▒▒░░░░░▒       █▒▓▒▒▒▒▒▒▒▒█░░░░░▒▒▒▒▒▓▓▓▓▒     ░░░░░▒▒▒▒▒▒▒▒▒                 ", { short(x),short(y + 7) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);
    tool.printCharactors(L"▒▒▒▒▒▒▒▒▒▒░░░░░▓▒▓     ▒▓▓▓▒▒▒▒▒▒▓▒▓░░░▒▒▒▒▒▓ ░▒▓▒█    ░▒▒▒░░░▒▒▒▒▒▒▒▒                 ", { short(x),short(y + 8) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);
    tool.printCharactors(L"▒▒▒▒▒▒▒▒▒░░░░░▒░▒▒▓░   ▒▒▒▒▒▒▒▒▒▒▓▒▓░▓░   ▓▓▓ ▒▒▒▒▓   ░▒▒▒▓░░░░▒▒▒▒▒▒▒                 ", { short(x),short(y + 9) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);
    tool.printCharactors(L"▒▒▒▒▒▒▒▒░░░░░░▓▒▓▓▓▒   ░▓▒▒▓▒▒▒▒▒▓▒▓░░█░▒▒▓▒░░▒▒▒▒█   ▒░▒▒▓▒░░░░▒▒▒▒▒▒                 ", { short(x),short(y + 10) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);
    tool.printCharactors(L"▒▒▒▒▒▒▒░░░░░░▓░▒▒▒▒▒▓▓ ░▓ ░▒▓▒▒█▒▓▒░░░▓░░▒▒▓▒▒▒▒▒▒█  ▓▒▒▒▒▒▓░░░░▒▒▒▒▒▒                 ", { short(x),short(y + 11) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);
    tool.printCharactors(L"▒▒▒▒▒▒░░░░░░▒▒░░▒▒▒▓ ░░▓▓░ ░▒▒▓▓▒░░▒▒▒░░░░░░▒▒▒▒▒▓▓▒░▒▓▒▒▒▓▓ ░░░▒▒▒▒▒▒                 ", { short(x),short(y + 12) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);
    tool.printCharactors(L"▒▒▒▒▒▒░░░░░░▒░▒▒▒▓▒  ░▓▓▓ ░▓▒░░░░░░░░░░░░░▒▒▒▒▓▓▒▒▓▒  ▒▓▒▒▒▒▓ ░░▒▒▒▒▒▒                 ", { short(x),short(y + 13) }, Color::BLACK, Color::YELLOW);
	Sleep(delayTime);
    tool.printCharactors(L"▒▒▒▒▒▒░░░░▒▒░▒░░▓░ ░▒▒█▒▓  ▒░░░░░░░░░░░░▒▒▒▒▒▒▒▒▒▒▓▓  ░▒▓▒░▓   ░▒▒▒▒▒▒                 ", { short(x),short(y + 14) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);
    tool.printCharactors(L"▒▒▒▒▒▒░░    ░  ▒▒▒▒░░▓█▒▓░ ░░░░░░░░░░░░░▒▒▒▒▒▒▒▓▓▒▒▓░  ░░▓ ░▓   ▒▒▒▒▒▒                    ", { short(x),short(y + 15) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);
    tool.printCharactors(L"▒▒▒▒▒▒░    ▒▓▓▓░░░▓▒▒▓░░░░▓░░░░▒▒░░░░░░▒▒▒▒▒▓▒▓░░▓▒▒▓▓▒▒░░░   ░▒▒▒▒▒▒▒                   ", { short(x),short(y + 16) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);
    tool.printCharactors(L"▒▒▒▒▒▒   ░▒░░░▓▒▒▓░░░▓░ ░▓▓▒▒█▒░░ ░▒▒░▒▓░  ░▒▓▓ ░▒▒▒▓░░▒▓▓▒░░░  ▒▒▒▒▒▒             ", { short(x),short(y + 17) }, Color::BLACK, Color::YELLOW);
	Sleep(delayTime);
    tool.printCharactors(L"▒▒▒▒▒▒ ▓▒░▒▓▒▓░░░▒▓▒░▓   ▒▒░▒▓░░░░▓▓▓▒▒▓ ▓░░░▓▒▓▓▒▒▒▓▒▓▓░▒▒▓▓▓▒ ▒▒▒▒▒▒                 ", { short(x),short(y + 18) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);
    tool.printCharactors(L"▒▒▒▒▒▒▓░░▒▒░░░▓░▒▒▒▒░▓     ░░░░░░░▓▒░░░░▓▒░░░░░█▒▒▒▒▒░▒▒░░▒▒▒░▒▓▒▒▒▒▒▒                 ", { short(x),short(y + 19) }, Color::BLACK, Color::YELLOW);
	Sleep(delayTime);
    tool.printCharactors(L"▒▒▒▒▒▒░▓▒░▒▓░▒▒░░░▒▓░▓   ░░░░░░░░░░░░░░░░▒▒░░░░▒▒▒▒▒▓▒▒▓▒▒▒░▒▒▓▒▒▒▒▒▒▒                 ", { short(x),short(y + 20) }, Color::BLACK, Color::YELLOW);
	Sleep(delayTime);
    tool.printCharactors(L"▒▒▒▒▒▒▓░░░▒░░░▒▒░░▒▒▒▓ ░▓░ ░░░░▓▓░░░░░░░░░░░░░▒▒▒▒▒▒▓░▒▒▓▒▒▒▓▒▒░▒▒▒▒▒▒                 ", { short(x),short(y + 21) }, Color::BLACK, Color::YELLOW);
	Sleep(delayTime);
    tool.printCharactors(L"▒▒▒▒▒▒▓░░▓░░░░▒▒▒▒▒▓▒▓ ▒░▓▒▒░▒▓ ░▒▒░░░░░░░▒▒▒▒▒▒▒▒▒▒▓▒▒▓▒▒▒▒▒▓▓ ▒▒▒▒▒▒                 ", { short(x),short(y + 22) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);
    tool.printCharactors(L"▒▒▒▒▒▒ ▒▓▓▒░░▒▒▓▓▓▓▒░▓ ░▓░░▒░░░░▒▒▒▒░░░░░░░▒▓▒▒▒▒▒▒▒▓▓▓▓▒▒▒▒▒▒  ▒▒▒▒▒▒                  ", { short(x),short(y + 23) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);
    tool.printCharactors(L"▒▒▒▒▒▒  ▓▓▓▓▓▒▒░▒▒▒░░▓░░▓░░▒░░░░▒ ▒▒░░░░░░░▒▒▒▒▒▒▒▒▒▓▒▒▒▒▓▓▓▓   ▒▒▒▒▒▒                ", { short(x),short(y + 24) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);
    tool.printCharactors(L"▒▒▒▒▒▒ ▒▓▓▓▒▒▒░░░░░░░▓▒▒▓▒▒▒▒▒▒▒▒▒▒▓░░░░▒▒▒▒▒▒▒▒▒▒▒▒▓░░░░▒▒▒▒▒█░▒▒▒▒▒▒                ", { short(x),short(y + 25) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);
    tool.printCharactors(L"▒▒▒▒▒▒ ▒▓▒▒▒▓▒░░░░░░░░▓▓▓▒▓▒▒░▒▒▒ ░▓░░░░▒▒▒▒▒▒▒▒▒▓▓▓▒░░░░░▒▓▒▒▓░▒▒▒▒▒▒                 ", { short(x),short(y + 26) }, Color::BLACK, Color::YELLOW);
	Sleep(delayTime);
    tool.printCharactors(L"▒▒▒▒▒▒░░▒▓▒▒▒▒▒▒▓▓░░░░░░▒▓█▓▒░░▒▒░▒▓░░░░▒▒▒▒▒▓▓█▓▒░░░░░▒▓▒▒▒▓▓▓░▒▒▒▒▒▒                 ", { short(x),short(y + 27) }, Color::BLACK, Color::YELLOW);
	Sleep(delayTime);
    tool.printCharactors(L"▒▒▒▒▒▒░░░  ▒█▓▒▒▒▒▒▒▓▒░░░░░░▒▓▓██▓▓▓▓▓▓▓██▓▓▓░░░░░░▓▓▒▒▒▓▓█▓  ░░▒▒▒▒▒▒                 ", { short(x),short(y + 28) }, Color::BLACK, Color::YELLOW);
	Sleep(delayTime);
    tool.printCharactors(L"▒▒▒▒▒▒░░░░░    ▒█▓▒▒▒▒▒▒▓░░░░░░░░░░░░░░░░░░░░░░▓▓▒▒▒▒▓▓▓    ░░░░▒▒▒▒▒▒                ", { short(x),short(y + 29) }, Color::BLACK, Color::YELLOW);
    Sleep(delayTime);
    tool.printCharactors(L"▒▒▒▒▒▒░░░░░░░░     █▓▒▒▒▒▒▒▒▓░░░░░░░░░░░░░░▓▒▒▒▒▒▒▓█▒     ░░░░░░▒▒▒▒▒▒             ", { short(x),short(y + 30) }, Color::BLACK, Color::YELLOW);
    
}

void ctool::drawTowerDefenseText() {
    int x, y;
    x = 35;
    y = 8;

    ctool tool;
    Sleep(300);
    tool.printCharactors(L"████████╗ ██████╗ ██╗    ██╗███████╗██████╗               ", { short(x),short(y + 0) }, Color::BLACK, Color::YELLOW);
    Sleep(100);
    tool.printCharactors(L"╚══██╔══╝██╔═══██╗██║    ██║██╔════╝██╔══██╗              ", { short(x),short(y + 1) }, Color::BLACK, Color::YELLOW);
    Sleep(100);
    tool.printCharactors(L"   ██║   ██║   ██║██║ █╗ ██║█████╗  ██████╔╝              ", { short(x),short(y + 2) }, Color::BLACK, Color::YELLOW);
    Sleep(100);
    tool.printCharactors(L"   ██║   ██║   ██║██║███╗██║██╔══╝  ██╔══██╗              ", { short(x),short(y + 3) }, Color::BLACK, Color::YELLOW);
    Sleep(100);
    tool.printCharactors(L"   ██║   ╚██████╔╝╚███╔███╔╝███████╗██║  ██║              ", { short(x),short(y + 4) }, Color::BLACK, Color::YELLOW);
    Sleep(100);
    tool.printCharactors(L"   ╚═╝    ╚═════╝  ╚══╝╚══╝ ╚══════╝╚═╝  ╚═╝              ", { short(x),short(y + 5) }, Color::BLACK, Color::YELLOW);
    Sleep(100);
    y += 7;
    tool.printCharactors(L"                 ██████╗ ███████╗███████╗███████╗███╗   ██╗███████╗███████╗", { short(x),short(y + 0) }, Color::BLACK, Color::YELLOW);
    Sleep(100);
    tool.printCharactors(L"                 ██╔══██╗██╔════╝██╔════╝██╔════╝████╗  ██║██╔════╝██╔════╝", { short(x),short(y + 1) }, Color::BLACK, Color::YELLOW);
    Sleep(100);
    tool.printCharactors(L"                 ██║  ██║█████╗  █████╗  █████╗  ██╔██╗ ██║███████╗█████╗  ", { short(x),short(y + 2) }, Color::BLACK, Color::YELLOW);
    Sleep(100);
    tool.printCharactors(L"                 ██║  ██║██╔══╝  ██╔══╝  ██╔══╝  ██║╚██╗██║╚════██║██╔══╝  ", { short(x),short(y + 3) }, Color::BLACK, Color::YELLOW);
    Sleep(100);
    tool.printCharactors(L"                 ██████╔╝███████╗██║     ███████╗██║ ╚████║███████║███████╗", { short(x),short(y + 4) }, Color::BLACK, Color::YELLOW);
    Sleep(100);
    tool.printCharactors(L"                 ╚═════╝ ╚══════╝╚═╝     ╚══════╝╚═╝  ╚═══╝╚══════╝╚══════╝", { short(x),short(y + 5) }, Color::BLACK, Color::YELLOW);
}

void playSound(int audio_pos, int volume = 100) {
    // Thêm đường dẫn đến thư mục sounds
    const string soundFile[] = {
        "sounds/background.wav",
        "sounds/button.wav",
        "sounds/collision.wav",
        "sounds/error.wav",
        "sounds/end.wav",
        "sounds/exit.wav"
    };

    // Kiểm tra vị trí file hợp lệ
    if (audio_pos < 0 || audio_pos >= sizeof(soundFile) / sizeof(soundFile[0])) {
        cerr << "Invalid audio position!" << endl;
        return;
    }

    // Điều chỉnh âm lượng
    if (volume < 0) volume = 0;
    if (volume > 100) volume = 100;

    DWORD volumeLevel = static_cast<DWORD>(volume * 65535 / 100);
    waveOutSetVolume(0, volumeLevel | (volumeLevel << 16)); // Thiết lập âm lượng

    // Phát âm thanh
    if (!PlaySoundA(soundFile[audio_pos].c_str(), NULL, SND_FILENAME | SND_ASYNC)) {
        cerr << "Error playing sound: " << soundFile[audio_pos] << endl;
    }
}


void stopSound()
{

    PlaySoundA(NULL, NULL, 0);
}

void adjustSound(int& volume) {
    int boxX = 20;      // Tọa độ X khung
    int boxY = 10;      // Tọa độ Y khung
    int boxWidth = 30;  // Chiều rộng khung
    int boxHeight = 5;  // Chiều cao khung

    system("cls");
    cout << "Use '->' to increase volume, '<-' to decrease volume, 'q' to quit.\n";

    // Vẽ khung cho Current Volume
    ctool::printRectangle(boxX, boxY, boxWidth, boxHeight);

    while (true) {
        // Hiển thị Current Volume ở giữa khung
        int textX = boxX + (boxWidth - 15) / 2; // Căn giữa dòng chữ trong khung
        int textY = boxY + boxHeight / 2;       // Vị trí Y giữa khung
        ctool::GotoXY(textX, textY);            // Đặt vị trí con trỏ
        DWORD volumeLevel = static_cast<DWORD>(volume * 65535 / 100);
        waveOutSetVolume(0, volumeLevel | (volumeLevel << 16));
        cout << "Current Volume: " << setw(3) << volume << "%";

        // Kiểm tra phím mũi tên phải
        if (GetAsyncKeyState(VK_RIGHT) & 0x8000) { // VK_RIGHT là mã phím mũi tên phải
            volume += 10;
            if (volume > 100) volume = 100; // Giới hạn tối đa
            Sleep(200); // Tránh xử lý quá nhanh
        }

        // Kiểm tra phím mũi tên trái
        if (GetAsyncKeyState(VK_LEFT) & 0x8000) { // VK_LEFT là mã phím mũi tên trái
            volume -= 10;
            if (volume < 0) volume = 0; // Giới hạn tối thiểu
            Sleep(200); // Tránh xử lý quá nhanh
        }

        // Kiểm tra phím 'q' để thoát
        if (GetAsyncKeyState('Q') & 0x8000) {
            ctool::GotoXY(boxX + (boxWidth - 22) / 2, boxY + boxHeight + 2); // Vị trí thông báo thoát
            cout << "Exiting volume adjustment...";
            Sleep(1000);
            system("cls");
            break;
        }
    }
}


void ctool::Settings() {
    int option = 0;
    bool soundStatus = ctool::sound_is_open; // Lưu trạng thái âm thanh
    int volume = 100; // Giá trị âm lượng mặc định
    system("color E3");

    while (true) {
        setColor(14, 3);

        // In tiêu đề
        ctool::GotoXY(5, 2);
        drawSettingText();

        // Vẽ các ô cho từng mục
        printRectangle(45, 13, 25, 3);  // Ô cho Sound
        printRectangle(45, 17, 25, 3);  // Ô cho Adjust Volume
        printRectangle(45, 21, 25, 3);  // Ô cho Back to Main Menu

        // In các lựa chọn trong các ô chữ nhật
        for (int i = 0; i < 3; ++i) { // Có 3 mục trong menu
            if (i == option) {
                setColor(12, 3); // Highlight in blue
            }
            else {
                setColor(14, 3); // Màu mặc định
            }

            int x_position = 45 + (30 - (i == 0 ? 15 : (i == 1 ? 14 : 18))) / 2;
            ctool::GotoXY(x_position, 14 + i * 4);

            switch (i) {
            case 0:
                cout << "Sound (" << (soundStatus ? "ON" : "OFF") << ")";
                break;
            case 1:
                ctool::GotoXY(x_position - 4, 14 + i * 4);
                cout << "Adjust Volume (" << volume << "%)";
                break;
            case 2:
                cout << "Back to Main Menu";
                break;
            }
        }

        // Nhận đầu vào từ người dùng
        char ch = _getch();
        if (ch == KEY_UP) {
            option = (option > 0) ? option - 1 : 2; // Vòng lại mục cuối
        }
        else if (ch == KEY_DOWN) {
            option = (option + 1) % 3; // Vòng lại mục đầu
        }
        else if (ch == KEY_ENTER) {
            if (option == 0) { // Toggle âm thanh
                soundStatus = !soundStatus;
                ctool::sound_is_open = soundStatus;

                if (soundStatus) {
                    playSound(0, volume); // Bật nhạc nền với âm lượng hiện tại
                }
                else {
                    stopSound(); // Tắt nhạc nền
                }
            }
            else if (option == 1) { // Điều chỉnh âm lượng
                setColor(14, 3);
                system("cls");
                adjustSound(volume);
            }
            else if (option == 2) { // Quay lại Menu chính
                setColor(14, 3);
                system("cls");
                drawTowerDefenseText();
                break;
            }
        }
        else if (ch == 27) { // ESC để thoát
            setColor(14, 3);
            system("cls");
            drawTowerDefenseText();
            break;
        }
    }
}


void ctool::printMenu()
{
    playSound(BACKGROUND_SOUND);
    
    SetConsoleTextAttribute(consoleOutput, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(consoleOutput, &csbi);
    DWORD consoleSize = csbi.dwSize.X * csbi.dwSize.Y;
    DWORD written;
    FillConsoleOutputAttribute(consoleOutput, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED, consoleSize, { 0, 0 }, &written);
    system("color E0");
    drawSplash(100);
    Sleep(100);
    system("cls");
	system("color E3");
    std::cout << "Loading menu...\n";
    Sleep(200);

	system("cls");
    int menu_option = 0; // Mặc định chọn mục đầu tiên

	drawTowerDefenseText();
    while (true)
    {
		system("color E3");

        // Vẽ các ô cho từng mục
        printRectangle(5, 5, 20, 3); // Cho mục 1: "PLAY"
        printRectangle(5, 9, 20, 3);  // Cho mục 2: "SAVE"
        printRectangle(5, 13, 20, 3); // Cho mục 3: "SETTING"
        printRectangle(5, 17, 20, 3); // Cho mục 4: "ABOUT"
        printRectangle(5, 21, 20, 3); // Cho mục 5: "EXIT"

        // In các lựa chọn menu trong các ô chữ nhật
        for (int i = 0; i < 5; ++i) {
            // Nếu đang chọn mục này, tô màu xanh
            if (i == menu_option) {
                setColor(12, 0);  // Highlight in blue
            }
            else {
                setColor(14, 3);  // Các mục còn lại dùng màu mặc định
            }

            // In các mục menu vào giữa các ô chữ nhật
            ctool::GotoXY(7, 6 + i * 4);
            switch (i) {
            case 0: std::cout << "1. PLAY"; break;
            case 1: std::cout << "2. SAVE"; break;
            case 2: std::cout << "3. SETTING"; break;
            case 3: std::cout << "4. ABOUT"; break;
            case 4: std::cout << "5. EXIT"; break;
            }
        }

        setColor(14, 3); // Reset lại màu sắc

        // Lấy đầu vào từ người dùng (phím mũi tên hoặc Enter)
        char menu_option_input = _getch();

        // Xử lý di chuyển lên/xuống
        if (menu_option_input == 'w' || menu_option_input == KEY_UP) {  // Di chuyển lên
            menu_option = (menu_option > 0) ? menu_option - 1 : 4;  // Nếu đã ở đầu, quay lại cuối
        }
        else if (menu_option_input == 's' || menu_option_input == KEY_DOWN) {  // Di chuyển xuống
            menu_option = (menu_option + 1) % 5;  // Nếu đã ở cuối, quay lại đầu
        }
        // Nếu nhấn phím Enter, mở ra màn hình tương ứng
        else if (menu_option_input == 13) {  // Enter key
            switch (menu_option) {
            case 0:
                system("cls");
                std::cout << "Starting game...\n";
                Sleep(200); // Delay 1 giây
                system("cls");
                std::cout << "Press any key to start demo: ";
                std::cin.get();
                ctool::ShowConsoleCursor(false);
                return;  // Đã chọn "PLAY", thoát menu
            case 1:
                system("cls");
                std::cout << "Loading save...\n";
                Sleep(1000);
                system("cls");
                drawTowerDefenseText();
                break;
            case 2:
                system("cls");
                ctool::Settings(); // Mở menu SETTINGS
                break;
            case 3:
                system("cls");
                ctool::printAbout();  // Mở ABOUT
                break;
            case 4:
                if (printExit()) {
                    Sleep(1000);  // Delay 1 giây
                    return;  // Thoát game khi chọn EXIT
                }
                break;
            default:
                break;
            }
        }
    }
}




void setUpWindow()
{
    setWindowSize();
    setTitle();
    hideCursor();
    hideScrollBar();
}

void setWindowSize()
{
    RECT desktop;

    GetWindowRect(GetDesktopWindow(), &desktop);

    MoveWindow(consoleWindow, 0, 0, desktop.right, desktop.bottom, TRUE);
}

void setColor(int background, int text)
{
    SetConsoleTextAttribute(consoleOutput, background * 16 + text);
}

void setDefaultColor()
{
    SetConsoleTextAttribute(consoleOutput, 3);
}

void hideScrollBar()
{
    ShowScrollBar(consoleWindow, SB_BOTH, 0);
}

void hideCursor()
{
    CONSOLE_CURSOR_INFO ConCurInf;

    ConCurInf.dwSize = 10;
    ConCurInf.bVisible = false;

    SetConsoleCursorInfo(consoleOutput, &ConCurInf);
}

void setTitle()
{
    SetConsoleTitleA("TOEWER-DEFENSE");
}




