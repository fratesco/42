FROM debian:bullseye

RUN apt-get update && apt-get upgrade -y > my_log

RUN apt-get install -y curl php php7.4-fpm php-mysql mariadb-client >> my_log

COPY ./configurations/wp_conf.sh /

RUN  chmod +x wp_conf.sh

ENTRYPOINT ["./wp_conf.sh"]
