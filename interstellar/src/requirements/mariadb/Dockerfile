FROM debian:11

RUN apt-get update && apt-get upgrade -y > my_log

RUN apt-get install -y mariadb-server >> my_log

COPY ./configurations/mdb-conf.sh /mdb-conf.sh

RUN chmod +x /mdb-conf.sh

ENTRYPOINT ["./mdb-conf.sh"]