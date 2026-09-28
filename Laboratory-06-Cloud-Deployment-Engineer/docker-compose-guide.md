# Docker Compose Guide

## What is Docker Compose?
Docker Compose is a tool that allows us to define and run multi-container applications using a single YAML file (`docker-compose.yml`). Instead of running many separate `docker run` commands, we can start the entire application stack with one command.

## The docker-compose.yml File
In this laboratory, the file defines two services:

- **database** → MariaDB container (stores user data and file metadata)
- **app** → Nextcloud container (the web application users interact with)

## Important Commands Used

| Command                    | Purpose                                      |
|---------------------------|----------------------------------------------|
| `docker-compose up -d`    | Starts all services in the background        |
| `docker-compose ps`       | Shows the status of the running containers   |
| `docker-compose down`     | Stops and removes the containers             |

## How the Two Containers Connect
The Nextcloud container connects to the MariaDB container using the service name `database` as the hostname (`MYSQL_HOST=database`). Docker Compose automatically creates a private network so the containers can communicate with each other.
