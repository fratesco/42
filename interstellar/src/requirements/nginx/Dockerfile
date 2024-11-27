FROM debian:bullseye

RUN apt-get update && apt-get upgrade -y > my_log

RUN apt-get install -y nginx openssl >> my_log

RUN mkdir -p /etc/nginx/ssl

RUN openssl req -x509 -nodes -out /etc/nginx/ssl/inception.crt -keyout \
    /etc/nginx/ssl/inception.key -subj "/C=IT/ST=RM/L=RM/O=42/OU=42/CN=fgolino.42.fr/UID=Srapuano(per_sgherzo)"

COPY ./configurations/nginx.conf /etc/nginx/nginx.conf

RUN mkdir -p /var/www/wordpress

RUN chown -R www-data:www-data /var/www/wordpress

CMD ["nginx", "-g", "daemon off;"]
