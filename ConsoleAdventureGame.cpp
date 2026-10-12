#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

const int fenetreLongeur = 20;
const int fenetreLargeur = 10;

    struct Hero {
        char nom;
        int pos_x;
        int pos_y;
    };

    int main() {
        bool ingame = true;
        char direction = ' ';
        const int map_size_x = 5;
        const int map_size_y = 5;
        Hero H{ 'H', 0, 0 };

        char map[map_size_x * map_size_y] = { '.', '.', '.', '.', '.',
                                                '.', '.', '.', '.', '.',
                                                '.', '.', '.', '.', '.',
                                                '.', '.', '.', '.', '.',
                                                '.', '.', '.', '.', '.', };

        char* p = map;
}