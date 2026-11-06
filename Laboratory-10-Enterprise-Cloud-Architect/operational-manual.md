# Infrastructure Documentation & Operational Manual
---

## 1. Overview
This document describes the complete infrastructure designed and deployed for Laboratory Activity 10. The system is a multi-tier private cloud application consisting of a web frontend (Nextcloud) and a database backend (MariaDB), deployed using Docker Compose on an Ubuntu Server virtual machine[cite: 2].

---

## 2. Base Infrastructure

### Virtual Machine Specification
- **Hypervisor:** Oracle VirtualBox / VMware  
- **Operating System:** Ubuntu Server 22.04 LTS / 24.04 LTS  
- **Purpose:** Host Docker containers, enforce UFW network policies, and manage disaster recovery cron jobs[cite: 2, 3].

### Networking Configuration
The virtual machine network adapter is configured in Bridged / NAT Network mode, exposing Nextcloud directly to the host machine's web browser on standard **Port 80**[cite: 2].

---

## 3. Multi-Tier Application Stack

### Deployed Container Services

| Service | Image | Role | Host Port | Container Port |
| :--- | :--- | :--- | :--- | :--- |
| **app** | `nextcloud:latest` | Web Application Frontend | `80` | `80` |
| **db** | `mariadb:10.11` | Relational Database Backend | None (Isolated) | `3306` |

*Note: The database service is strictly isolated within the internal Docker bridge network (`nextcloud-network`) and has no directly exposed host ports.*[cite: 2]

### Storage Architecture & Persistent Volumes
- `db_data` → Maps to `/var/lib/mysql` to preserve database state and user accounts[cite: 2].
- `nextcloud_data` → Maps to `/var/www/html` to store configuration files, user uploads, and application data[cite: 2].

---

## 4. Operational Deployment Steps

### Step 1: Install Engine Dependencies
Update package indexes and install Docker Engine alongside the Compose plugin:

```bash
sudo apt update && sudo apt upgrade -y
sudo apt install -y docker.io docker-compose-v2
sudo systemctl enable --now docker
sudo usermod -aG docker $USER
