#include <iostream>
#include <string>

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
    Hero H{'H', 0, 0};

    char map[map_size_x * map_size_y] = {   '.', '.', '.', '.', '.',
                                            '.', '.', '.', '.', '.',
                                            '.', '.', '.', '.', '.',
                                            '.', '.', '.', '.', '.',
                                            '.', '.', '.', '.', '.', };

    char* p = map;

    while (ingame) {

        for (int i = 0; i < map_size_x; i++) {
            for (int j = 0; j < map_size_y; j++) {
                if (i + (j * map_size_y) == H.pos_x + (H.pos_y * map_size_y)) {
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
            H.pos_x--;
        }
        else if(direction == 's') {
            H.pos_x++;
        }
        else if (direction == 'q') {
            H.pos_y--;
        }
        else if (direction == 'd') {
            H.pos_y++;
        }

        H.pos_x = (H.pos_x + map_size_x) % map_size_x;
        H.pos_y = (H.pos_y + map_size_y) % map_size_y;

        direction = ' ';
    }
}
