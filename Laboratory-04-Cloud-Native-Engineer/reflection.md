# Reflection – Laboratory Activity 4

1. How does the boot time and setup process of a Docker container compare to installing an operating system on a Virtual Machine?
A Docker container starts in just a few seconds, whereas installing and booting a full Virtual Machine can take several minutes. Containers share the host OS kernel and isolate application processes, eliminating the heavy overhead of running an entire guest operating system and virtualized hardware.

2. Why is port mapping (-p 8080:80) necessary when running a web server inside a container?
Port mapping is necessary because Docker containers run in isolated network environments with their own internal IP addresses. Mapping `-p 8080:80` routes incoming traffic from port 8080 on the host machine to port 80 inside the container, making the containerized web server accessible to external web browsers.

3. What happens to the data inside a container when you use the docker rm command?
When you remove a container using `docker rm`, all temporary data stored inside the container's writable layer is permanently deleted. To persist data across container life cycles, host paths or persistent Docker volumes must be mounted to the container.

4. How do you think containerization changes the way software developers and IT operations teams work together (DevOps)?
Containerization bridge the gap between development and operations by packaging software alongside all its dependencies, runtime environments, and configuration files into a standardized container image. This eliminates environment mismatches ("it works on my machine" issues) and enables consistent deployment across development, staging, and production environments.

5. How is your GitHub portfolio evolving?
My GitHub portfolio continues to grow and mature. It now features four structured laboratory activities complete with detailed documentation, setup instructions, output screenshots, and clean repository structures that showcase practical hands-on skills in cloud-native tools and virtualization.
