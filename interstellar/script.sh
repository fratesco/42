#!/bin/bash

random_string()
{
	chars='abcdefghijklmnopqrstuvwxyz0123456789'
	str=
	n=20

	for ((i = 0; i < n; i++));
	do
		str+=${chars:RANDOM%${#chars}:1}
	done
}

echo > ./src/.env "MYSQL_DB=park
MYSQL_USER=bench "
random_string
echo "MYSQL_PASSWORD="$str >> ./src/.env
random_string
echo "MYSQL_ROOT_PASSWORD="$str >> ./src/.env

echo >> ./src/.env

random_string
echo "DOMAIN_NAME=fgolino.42.fr
WP_ADMIN_N=boss
WP_ADMIN_P="$str >> ./src/.env
echo "WP_TITLE=Inception
WP_ADMIN_E=fgolino.42.fr" >> ./src/.env
echo >> ./src/.env

random_string
echo -n "WP_U_NAME=Stefano_Tamiano
WP_U_PASS=$str 
WP_U_ROLE=fastidio
WP_U_EMAIL=Stamiano.42.fr" >> ./src/.env