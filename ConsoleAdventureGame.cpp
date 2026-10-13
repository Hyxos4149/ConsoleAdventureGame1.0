#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>

struct Hero {
    char nom;
    int position_x;
    int position_y;
    int vies;
    char direction;
};

struct Enemy {
    char nom;
    int position_x;
    int position_y;
    bool vivant;
};

int main() {
    bool game = true;

    const int map_size_x = 20;
    const int map_size_y = 10;
    const int enemy_count = 5;

    srand(time(0));

    Hero H{ 'H', 0, 4, 1, 'd' };

    char map[map_size_x * map_size_y];

    // Initialisation de la carte
    for (int i = 0; i < map_size_x * map_size_y; i++) {
        map[i] = '.';
    }

    // Ajout de l'eau
    map[3 + 2 * map_size_x] = '~';
    map[4 + 2 * map_size_x] = '~';
    map[5 + 2 * map_size_x] = '~';

    map[10 + 4 * map_size_x] = '~';
    map[11 + 4 * map_size_x] = '~';

    // Ajout des montagnes
    map[8 + 1 * map_size_x] = 'A';
    map[8 + 2 * map_size_x] = 'A';
    map[8 + 3 * map_size_x] = 'A';

    map[15 + 6 * map_size_x] = 'A';
    map[16 + 6 * map_size_x] = 'A';

    // Creation des cinq ennemis immobiles
    Enemy enemies[enemy_count] = {
        { 'X', 2, 2, true },
        { 'X', 11, 4, true },
        { 'X', 11, 6, true },
        { 'X', 8, 8, true },
        { 'X', 16, 8, true }
    };

    // Boucle principale du jeu
    while (game) {

        // Affichage de la carte
        system("cls");

        for (int y = 0; y < map_size_y; y++) {
            for (int x = 0; x < map_size_x; x++) {

                if (x == H.position_x && y == H.position_y) {
                    std::cout << H.nom << ' ';
                }
                else {
                    bool enemy_found = false;

                    for (int i = 0; i < enemy_count; i++) {
                        if (enemies[i].vivant &&
                            x == enemies[i].position_x &&
                            y == enemies[i].position_y) {

                            std::cout << enemies[i].nom << ' ';
                            enemy_found = true;
                            break;
                        }
                    }

                    if (!enemy_found) {
                        std::cout << map[x + y * map_size_x] << ' ';
                    }
                }
            }

            std::cout << '\n';
        }

        // Affichage des informations
        int ennemis_restants = 0;

        for (int i = 0; i < enemy_count; i++) {
            if (enemies[i].vivant) {
                ennemis_restants++;
            }
        }

        std::cout << "\nVies : " << H.vies << '\n';
        std::cout << "Ennemis restants : "
            << ennemis_restants << '\n';

        std::cout << "\nZ = Haut | S = Bas\n";
        std::cout << "Q = Gauche | D = Droite\n";

        // Lecture d'une touche sans appuyer sur Entree
        char touche = _getch();

        // Conversion des majuscules en minuscules
        if (touche >= 'A' && touche <= 'Z') {
            touche = touche + ('a' - 'A');
        }

        // Variables pour le deplacement du heros
        int next_x = H.position_x;
        int next_y = H.position_y;

        bool action_valide = false;

        // Deplacement du heros
        if (touche == 'z' || touche == 'q' ||
            touche == 's' || touche == 'd') {

            action_valide = true;

            if (touche == 'z') {
                next_y--;
            }
            else if (touche == 's') {
                next_y++;
            }
            else if (touche == 'q') {
                next_x--;
            }
            else if (touche == 'd') {
                next_x++;
            }

            // Passage d'un bord a l'autre de la carte
            next_x = (next_x + map_size_x) % map_size_x;
            next_y = (next_y + map_size_y) % map_size_y;

            int next_index = next_x + next_y * map_size_x;

            // Verification du terrain
            if (map[next_index] != 'A' &&
                map[next_index] != '~') {

                H.position_x = next_x;
                H.position_y = next_y;
            }

            // Collision avec un ennemi immobile
            for (int i = 0; i < enemy_count; i++) {

                if (enemies[i].vivant &&
                    H.position_x == enemies[i].position_x &&
                    H.position_y == enemies[i].position_y) {

                    H.vies--;
                    game = false;
                    break;
                }
            }
        }

        // Ignorer les touches non reconnues
        if (!action_valide) {
            continue;
        }

        // Verification : le heros a-t-il encore une vie ?
        if (!game) {
            break;
        }
    }

    // Ecran de Game Over
    system("cls");

    std::cout << "========================\n";
    std::cout << "       GAME OVER        \n";
    std::cout << "========================\n\n";

    std::cout << "Le heros a perdu sa vie !\n";
    std::cout << "Vies restantes : " << H.vies << '\n';

    std::cout << "\nAppuie sur une touche pour fermer...";
    _getch();

    return 0;
}
