#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "presence.h"

int main() {
    printf("Content-Type: text/html\n\n");
    printf("<html><head><title>Liste Etudiant</title></head><body>");

    // Traitement des données
    char* content_length_str;
    int content_length;
    char* data;

    content_length_str = getenv("CONTENT_LENGTH");

    if(content_length_str == NULL) {
        printf("<h3>No data received</h3>");
        printf("</body></html>");
        return 1;
    }

    content_length = atoi(content_length_str);

    data = malloc(content_length + 1);
    if(data == NULL) {
        printf("<h3>Erreur d'allocation</h3>");
        printf("</body></html>");
        return 1;
    }

    fread(data, 1, content_length, stdin);
    data[content_length] = '\0';
    char date[100];
    int choix;

    sscanf(data, "date=%98[^&]&choix=%d", date, &choix);

    printf("<h2>Liste des etudiants</h2>");
    printf("<br/>");
    printf("<table border=\"2\">");
        rond_point(choix, date);
    printf("</table>");

    free(data);
    printf("</body></html>");

    return 0;
}
