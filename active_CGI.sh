#!/bin/bash
sudo a2enmod cgi
sudo systemctl restart apache2

CGI_BIN_DIR="/usr/lib/cgi-bin"

if [ ! -d "$CGI_BIN_DIR" ]; then
    sudo mkdir -p "$CGI_BIN_DIR"
fi

#? fichier de configuration apache à configurer
APACHE_CONF_FILE="/etc/apache2/sites-available/000-default.conf"

CONFIG_BLOCK='<Directory "/usr/lib/cgi-bin"
    Options +ExecCGI
    AddHandler cgi-script .cgi
</Directory>'

if ! grep -q '<Directory "/usr/lib/cgi-bin">' "$APACHE_CONF_FILE"; then 
    sudo bash -c "cat << 'EOF' >> $APACHE_CONF_FILE
$CONFIG_BLOCK
EOF"

    sudo systemctl restart apache2
    echo "Bloc de configuration ajouté et redémarré"
else
    echo "Le bloc de config existe déjà dans $APACHE_CONF_FILE"
fi

sudo mv './liste.csv' "$CGI_BIN_DIR" 