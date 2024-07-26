#!/bin/bash
#? traitement du fichier compilé CGI
CGI_BIN_DIR="/usr/lib/cgi-bin"
COMPILED_FILE_CGI="./$1"

sudo mv "$COMPILED_FILE_CGI" "$CGI_BIN_DIR"
sudo chmod 777 "$CGI_BIN_DIR"/"$COMPILED_FILE_CGI"