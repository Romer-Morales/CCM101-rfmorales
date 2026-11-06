# Infrastructure Documentation

**Student:** Romer Fredrick G. Morales  
**Laboratory:** Activity 10 – The Enterprise Cloud Architect  
**Project:** Private Cloud File Sharing System (Nextcloud + MariaDB)

## 1. Overview
This document describes the complete infrastructure that was designed and deployed for the final laboratory activity. The system is a multi-tier private cloud application consisting of a web frontend (Nextcloud) and a database backend (MariaDB), running on an Ubuntu Server virtual machine.

## 2. Base Infrastructure

### Virtual Machine
- **Hypervisor:** Oracle VirtualBox
- **Operating System:** Ubuntu Server
- **Purpose:** Host the Docker containers and provide the foundation for the entire stack

### Networking
The virtual machine was configured so that the Nextcloud web interface can be accessed from the host laptop’s browser using the VM’s IP address on port 8080.

## 3. Application Stack

### Services Deployed
| Service   | Image            | Role                  | Port  |
|-----------|------------------|-----------------------|-------|
| app       | nextcloud        | Web Application       | 8080  |
| db        | mariadb:10.11    | Database              | Internal |

### Persistent Volumes
- `db_data` → Stores MariaDB database files
- `nextcloud_data` → Stores Nextcloud files and user data

Using Docker volumes ensures that data is not lost when containers are stopped or restarted.

## 4. Deployment Steps

### Step 1: Install Docker and Docker Compose
```bash
sudo apt update
sudo apt install -y docker.io docker-compose-v2
sudo systemctl enable --now docker
