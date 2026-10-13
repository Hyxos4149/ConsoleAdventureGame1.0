#include <iostream>
#include <string>

struct Hero {
    char nom;
    int position_x;
    int position_y;
};

int main() {
    bool ingame = true;
    char direction = ' ';
    const int map_size_x = 20;
    const int map_size_y = 10;
    Hero H{ 'H', 0, 0 };

    char map[map_size_x * map_size_y] = { '.', '.', '.', '.', '.','.', '.', '.', '.', '.','.', '.', '.', '.', '.','.', '.', '.', '.', '.',
                                            '.', '.', '.', '.', '.','.', '.', '.', '.', '.','.', '.', '.', '.', '.','.', '.', '.', '.', '.',
                                            '.', '.', '.', '.', '.','.', '.', '.', '.', '.','.', '.', '.', '.', '.','.', '.', '.', '.', '.',
                                            '.', '.', '.', '.', '.','.', '.', '.', '.', '.','.', '.', '.', '.', '.','.', '.', '.', '.', '.',
                                            '.', '.', '.', '.', '.','.', '.', '.', '.', '.','.', '.', '.', '.', '.','.', '.', '.', '.', '.',
                                            '.', '.', '.', '.', '.','.', '.', '.', '.', '.','.', '.', '.', '.', '.','.', '.', '.', '.', '.',
                                            '.', '.', '.', '.', '.','.', '.', '.', '.', '.','.', '.', '.', '.', '.','.', '.', '.', '.', '.',
                                            '.', '.', '.', '.', '.','.', '.', '.', '.', '.','.', '.', '.', '.', '.','.', '.', '.', '.', '.',
                                            '.', '.', '.', '.', '.','.', '.', '.', '.', '.','.', '.', '.', '.', '.','.', '.', '.', '.', '.',
                                            '.', '.', '.', '.', '.','.', '.', '.', '.', '.','.', '.', '.', '.', '.','.', '.', '.', '.', '.', };

    char* p = map;

    while (ingame) {

        for (int i = 0; i < map_size_x; i++) {
            for (int j = 0; j < map_size_y; j++) {
                if (i + (j * map_size_y) == H.position_x + (H.position_y * map_size_y)) {
                    std::cout << H.nom << ' ';
                }
                else {
                    std::cout << p[i + (j * map_size_y)] << ' ';
                }
            }
            std::cout << '\n';
        }

        while (direction != 'z' && direction != 'q' && direction != 's' && direction != 'd') {
            std::cin >> direction;
        }

        if (direction == 'z') {
            H.position_x--;
        }
        else if (direction == 's') {
            H.position_x++;
        }
        else if (direction == 'q') {
            H.position_y--;
        }
        else if (direction == 'd') {
            H.position_y++;
        }

        H.position_x = (H.position_x + map_size_x) % map_size_x;
        H.position_y = (H.position_y + map_size_y) % map_size_y;

        direction = ' ';
    }
}
