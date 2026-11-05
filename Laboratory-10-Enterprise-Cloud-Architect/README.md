# Laboratory Activity 10 – The Enterprise Cloud Architect

**Student:** Romer Fredrick G. Morales  
**Repository:** CCM101-rfmorales

## Project Overview
This is the final laboratory activity of CCM101 – Cloud Computing. I designed, deployed, secured, and automated a complete multi-tier private cloud infrastructure using Nextcloud and MariaDB on Ubuntu Server.

## Architecture
- **Web Application:** Nextcloud
- **Database:** MariaDB
- **Persistent Storage:** Docker Volumes
- **Security:** UFW Firewall (Default Deny)
- **Automation:** Daily backup script scheduled with Cron

## Key Features
- Multi-tier architecture (Web + Database)
- Persistent data volumes
- Host-based firewall protection
- Automated daily backups
- Fully documented operational procedures

## How to Deploy
1. Install Ubuntu Server
2. Install Docker and Docker Compose
3. Use the provided `docker-compose.yml`
4. Configure UFW
5. Deploy the automation script and Cron job

## Files Included
- `docker-compose.yml` – Infrastructure as Code
- `automation-script.sh` – Backup automation
- `operational-manual.md` – Complete handover documentation
- `final-reflection.md` – Personal reflection
- `architecture-diagram.png` – System design

## Skills Demonstrated
- Linux server administration
- Docker & Docker Compose
- Multi-tier application deployment
- Firewall security
- Bash scripting and Cron automation
- Technical documentation
