#include <iostream>
#include <conio.h>
#include <cstdlib>

struct Hero {
    char nom;
    int position_x;
    int position_y;
};

struct Vilain {
    char nom;
    int position_x;
    int positio_y;
};

int main() {
    bool game = true;

    const int map_size_x = 20;
    const int map_size_y = 10;

    Hero H{ 'H', 0, 4 };
    Vilain X{ 'X', 2, 2};

    char map[map_size_x * map_size_y];

    // Initialisation du terrain
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

    // Boucle principale
    while (game) {

        // Effacer la console (Windows)
        system("cls");

        // Affichage de la carte
        for (int j = 0; j < map_size_y; j++) {
            for (int i = 0; i < map_size_x; i++) {

                if (i == H.position_x && j == H.position_y) {
                    std::cout << H.nom << ' ';
                }
                else {
                    std::cout << map[i + j * map_size_x] << ' ';
                }
            }
            std::cout << '\n';
        }

        std::cout << "\nZ = Haut | S = Bas"
            << "\nQ = Gauche | D = Droite"
            << "\nX = Quitter\n";

        // Lire une touche immédiatement, sans Entrée
        char direction = _getch();

        // Autoriser aussi les majuscules
        if (direction >= 'A' && direction <= 'Z') {
            direction = direction + ('a' - 'A');
        }

        // Quitter le jeu
        if (direction == 'x') {
            game = false;
            continue;
        }

        // Calcul de la prochaine position
        int next_x = H.position_x;
        int next_y = H.position_y;

        if (direction == 'z') {
            next_y--;
        }
        else if (direction == 's') {
            next_y++;
        }
        else if (direction == 'q') {
            next_x--;
        }
        else if (direction == 'd') {
            next_x++;
        }
        else {
            // Ignorer les touches non reconnues
            continue;
        }

        // Gestion des bords de la carte
        next_x = (next_x + map_size_x) % map_size_x;
        next_y = (next_y + map_size_y) % map_size_y;

        // Vérification des montagnes
        int next_index = next_x + next_y * map_size_x;

        if (map[next_index] == 'A') {
            // Le héros reste sur place
            continue;
        }

        if (map[next_index] == '~') {
            continue;
        }

        // Déplacement autorisé
        H.position_x = next_x;
        H.position_y = next_y;
    }

    // Message de fin
    system("cls");
    std::cout << "Fin du jeu !\n";

    return 0;
}
