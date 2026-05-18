#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>

void putchar_mod(char c, int shift) {
    // Si c'est une lettre minuscule
    if (c >= 'a' && c <= 'z') {
        c = 'a' + (c - 'a' + shift) % 26;
    }
    // Si c'est une lettre majuscule
    else if (c >= 'A' && c <= 'Z') {
        c = 'A' + (c - 'A' + shift) % 26;
    }
    // Les autres caractères (espaces, chiffres, etc.) restent inchangés
    write(1, &c, 1);
}

int main(int ac, char **av) {
    if (ac != 2) {
        write(2, "Usage: ./a.out <message>\n", 25);
        return 1;
    }

    // On teste les 26 décalages possibles de l'alphabet
    for (int shift = 0; shift < 26; shift++) {
        // Affichage du numéro du décalage (pour s'y retrouver)
        write(1, "Shift ", 6);
        if (shift >= 10) {
            char dez = '0' + (shift / 10);
            write(1, &dez, 1);
        } else {
            write(1, " ", 1);
        }
        char uni = '0' + (shift % 10);
        write(1, &uni, 1);
        write(1, ": ", 2);

        // Chiffrement/Déchiffrement de la chaîne
        int i = 0;
        while (av[1][i]) {
            putchar_mod(av[1][i], shift);
            i++;
        }
        write(1, "\n", 1);
    }
    return 0;
}
