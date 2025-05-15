WP_DATA = ~/data/wordpress 
DB_DATA = ~/data/mariadb 

all: up

up:
	bash ./script.sh
	@sleep 2
	docker compose -f ./src/docker-compose.yaml build
	@mkdir -p $(WP_DATA)
	@mkdir -p $(DB_DATA)
	docker compose -f ./src/docker-compose.yaml up -d



down:
	docker compose -f ./src/docker-compose.yaml down

exec_wp:
	docker exec -it wordpress bash

exec_db:
	docker exec -it mariadb bash

exec_nginx:
	docker exec -it nginx bash

vol_wp:
	docker volume inspect wordpress

vol_db:
	docker volume inspect mariadb

status:
	docker ps

status_all:
	docker compose -f ./src/docker-compose.yaml ps

clean:
	@docker stop $$(docker ps -qa) || true
	@docker rm $$(docker ps -qa) || true
	@docker rmi -f $$(docker images -qa) || true
	@docker volume rm $$(docker volume ls -q) || true
	@docker network rm $$(docker network ls -q) || true
	@sudo rm -rf $(WP_DATA) || true
	@sudo rm -rf $(DB_DATA) || true
	@rm -f ./src/.env

re: clean up

prune: clean
	@docker system prune -a --volumes -f

help:
	@echo "Available Commands:"
	@echo "-------------------"
	@echo "1.  all"
	@echo "2.  up"
	@echo "3.  down"
	@echo "4.  execp_wp"
	@echo "5.  exec_db"
	@echo "6.  exec_nginx"
	@echo "7.  vol_wp"
	@echo "8.  vol_db"
	@echo "9.  status"
	@echo "10. status_all"
	@echo "11. clean"
	@echo "12. re"
	@echo "13. prune"
