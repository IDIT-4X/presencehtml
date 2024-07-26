#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Entête CGI
    printf("Content-Type: text/html\n\n");
    printf("<html><head><title>Liste Etudiant</title></head><body>");
        
    printf("<form action=\"/cgi-bin/reception.cgi\" method=\"post\">");
    printf("<label for=\"date\">Date:</label>");
    printf("<input type=\"text\" id=\"date\" name=\"date\" placeholder=\"YYYY-MM-dd...\">");
    printf("<br/>");
    printf("<br/>");
    printf("<ol><li>Oui</li><li>Non</li><li>Perso</li><li>Absent</li></ol>");
    printf("<label for=\"choix\">Choix:</label>");
    printf("<input type=\"text\" id=\"choix\" name=\"choix\">");
    printf("<br/>");
    printf("<br/>");
    printf("<input type=\"submit\" value=\"Envoyer\">");
    printf("</form>");

    printf("</body></html>");
    
    return 0;
}
