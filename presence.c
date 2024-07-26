#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "presence.h"

Use utilisation_machine(char* use) {
    if (strcmp(use, "OUI") == 0) {
        return OUI;
    } else if (strcmp(use, "NON") == 0) {
        return NON;
    } else if (strcmp(use, "PERSO") == 0) {
        return PERSO;
    }
    return ABSENT;
}

void filtre_machine(Etudiant* etudiants, int nb_eleve, Use utilisation, char* date) {
    for (int i = 0; i < nb_eleve; i++) {
        if (etudiants[i].utilisation == utilisation && strcmp(etudiants[i].date, date) == 0) {
            printf("<tr><td>%d</td><td>%s</td><td>%s</td></tr>", etudiants[i].numero, etudiants[i].nom, etudiants[i].prenom);
        }
    }
}

void rond_point(int choix, char* date) {
    FILE* f = fopen("./liste.csv", "r");
    if (f == NULL) {
        printf("Erreur d'ouverture du fichier.\n");
        return;
    }

    char ligne[MAX_LENGTH_CHAINE];
    char* section;
    int i = 0;
    Etudiant etudiants[NB_MAX_ETU];

    while (fgets(ligne, 256, f) != NULL) {
        section = strtok(ligne, "/");
        if (section != NULL) {
            etudiants[i].numero = atoi(section);
        }
        section = strtok(NULL, "/");
        if (section != NULL) {
            strncpy(etudiants[i].nom, section, MAX_LENGTH_CHAINE - 1);
            etudiants[i].nom[MAX_LENGTH_CHAINE - 1] = '\0';
        }
        section = strtok(NULL, "/");
        if (section != NULL) {
            strncpy(etudiants[i].prenom, section, MAX_LENGTH_CHAINE - 1);
            etudiants[i].prenom[MAX_LENGTH_CHAINE - 1] = '\0';
        }
        section = strtok(NULL, "/");
        if (section != NULL) {
            etudiants[i].utilisation = utilisation_machine(section);
        }
        section = strtok(NULL, "/");
        if (section != NULL) {
            strncpy(etudiants[i].date, section, DATE_LENGTH - 1);
            etudiants[i].date[DATE_LENGTH - 1] = '\0';
        }
        i++;
        if (i >= NB_MAX_ETU) {
            break;
        }
    }

    fclose(f);

    switch (choix) {
        case 1:
            filtre_machine(etudiants, i, OUI, date);
            break;
        case 2:
            filtre_machine(etudiants, i, NON, date);
            break;
        case 3:
            filtre_machine(etudiants, i, PERSO, date);
            break;
        case 4:
            filtre_machine(etudiants, i, ABSENT, date);
            break;
        default:
            exit(0);
    }
}
