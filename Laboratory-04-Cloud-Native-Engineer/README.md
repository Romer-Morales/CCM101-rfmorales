# Laboratory Activity 4 – The Cloud-Native Engineer

## Mission Overview
This laboratory activity introduces the concept of containers and Docker. I learned the differences between Virtual Machines and Containers, and successfully deployed and managed an Nginx web server using Docker.

## Objectives
- Differentiate between Virtual Machines and Containers
- Access a Docker-enabled environment using KillerCoda
- Execute basic Docker commands
- Pull, run, manage, and remove a containerized application
- Document the process using Markdown

## Docker Commands Executed
- `docker --version`
- `docker info`
- `docker pull nginx`
- `docker run -d -p 8080:80 --name mynginx nginx`
- `curl http://localhost:8080`
- `docker ps`
- `docker stop mynginx`
- `docker ps -a`
- `docker rm mynginx`

## Skills Learned
- Understanding the difference between VMs and Containers
- Pulling images from Docker Hub
- Running containers in detached mode
- Port mapping
- Managing the full lifecycle of a container (start, stop, remove)

## Challenges Encountered
(Write 2–4 sentences about any difficulty you faced, for example: understanding port mapping, remembering the commands, or taking clear screenshots.)
