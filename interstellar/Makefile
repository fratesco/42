WP_DATA = ~/data/wordpress 
DB_DATA = ~/data/mariadb 

all: up

up: build
	@mkdir -p $(WP_DATA)
	@mkdir -p $(DB_DATA)
	docker compose -f ./src/docker-compose.yaml up -d

down:
	docker compose -f ./src/docker-compose.yaml down

stop:
	docker compose -f ./src/docker-compose.yaml stop

start:
	docker compose -f ./src/docker-compose.yaml start

build:
	bash ./script.sh
	docker compose -f ./src/docker-compose.yaml build

exec_wp:
	docker exec -it wordpress bash

exec_db:
	docker exec -it mariadb bash

exec_nginx:
	docker exec -it nginx bash

status:
	docker ps

clean:
	@docker stop $$(docker ps -qa) || true
	@docker rm $$(docker ps -qa) || true
	@docker rmi -f $$(docker images -qa) || true
	@docker volume rm $$(docker volume ls -q) || true
	@docker network rm $$(docker network ls -q) || true
	@sudo rm -rf $(WP_DATA) || true
	@sudo rm -rf $(DB_DATA) || true
	@rm ./src/.env

re: clean up

prune: clean
	@docker system prune -a --volumes -f
