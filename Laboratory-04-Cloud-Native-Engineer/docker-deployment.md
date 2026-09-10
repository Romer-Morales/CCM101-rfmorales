# Docker Deployment Documentation

## Commands Used and What They Do

1. **`docker pull nginx`**  
   Downloads the official Nginx image from Docker Hub.

2. **`docker run -d -p 8080:80 --name mynginx nginx`**  
   Creates and starts a new container named “mynginx” in the background and maps port 8080 on the host to port 80 inside the container.

3. **`curl http://localhost:8080`**  
   Tests if the Nginx web server is working by requesting the page.

4. **`docker ps`**  
   Lists all currently running containers.

5. **`docker stop mynginx`**  
   Stops the running container named “mynginx”.

6. **`docker ps -a`**  
   Shows all containers (running and stopped).

7. **`docker rm mynginx`**  
   Completely removes the container from the system.
