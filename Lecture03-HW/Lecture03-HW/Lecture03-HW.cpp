#include <iostream>

enum ForeColour {
    Default = 0,
    Black = 30,
    Red = 31,
    Green = 32,
    Yellow = 33,
    Blue = 34,
    Magenta = 35,
    Cyan = 36,
    White = 37,
};

void changeColor(int colorCode) {
    std::cout << "\x1b[" << colorCode << "m";
}

void DrawBlock() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << "# ";
        }
        std::cout << std::endl;
    }
}

int main() {
    const int WHITE_MASK = 0b1;
    const int RED_MASK = 0b10;
    const int GREEN_MASK = 0b100;
    const int YELLOW_MASK = 0b1000;
    const int CYAN_MASK = 0b10000;
    const int MAGENTA_MASK = 0b100000;
    const int EXIT_FLAG = 64;

    std::cout << "화면에 그림을 그리는 프로그램입니다.\n";
    std::cout << "학번 : 202327006\n";
    std::cout << "이름 : 최동환\n";

    while (true) {
        changeColor(ForeColour::Default);
        std::cout << "화면에 그릴 물체코드를 입력하세요 : ";
        int input = 0;
        std::cin >> input;

        if (input > 64 || input < 0) {
            std::cout << "오류, 다시 입력해주세요.\n";
            continue;
        }
        if (input == EXIT_FLAG) {
            std::cout << "종료하겠습니다.";
            break;
        }
        if (input & WHITE_MASK) {
            changeColor(ForeColour::White);
            DrawBlock();
        }
        if (input & RED_MASK) {
            changeColor(ForeColour::Red);
            DrawBlock();
        }
        if (input & GREEN_MASK) {
            changeColor(ForeColour::Green);
            DrawBlock();
        }
        if (input & YELLOW_MASK) {
            changeColor(ForeColour::Yellow);
            DrawBlock();
        }
        if (input & CYAN_MASK) {
            changeColor(ForeColour::Cyan);
            DrawBlock();
        }
        if (input & MAGENTA_MASK) {
            changeColor(ForeColour::Magenta);
            DrawBlock();
        }
    }

    return 0;
}
