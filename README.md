Etape pour executer le progamme:

**Configurer apache**
sh actice_CGI.sh

**Compiler et déplacer les fichiers sources dans /usr/lib/cgi-bin**

sh compile.sh traitement.c
sh deplace_CGI.sh traitement.cgi

gcc reception.c presence.c -o reception.cgi
sh deplace_CGI.sh reception.cgi

**Aller dans localhost**
[localhost/](http://localhost/cgi-bin/traitement.cgi)
