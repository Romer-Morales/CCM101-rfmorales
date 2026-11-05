# Architecture Diagram

## System Design
This project uses a multi-tier architecture consisting of the following components:

- **Host Machine** → Physical laptop
- **Hypervisor** → Oracle VirtualBox
- **Virtual Machine** → Ubuntu Server
- **Firewall** → UFW (Default Deny)
- **Containers**:
  - Nextcloud (Web Tier)
  - MariaDB (Database Tier)
- **Persistent Volumes**:
  - `db_data`
  - `nextcloud_data`

## Why This Design?
Separating the web application and database improves security, scalability, and maintainability. Using Docker volumes ensures that data is not lost when containers are restarted.
