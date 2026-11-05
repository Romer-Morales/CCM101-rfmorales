# Security Configuration

## Firewall Policy
- Default Incoming: **Deny**
- Default Outgoing: **Allow**

## Allowed Ports
| Port | Protocol | Purpose              |
|------|----------|----------------------|
| 22   | TCP      | SSH (remote access)  |
| 8080 | TCP      | Nextcloud Web Access |

## Commands Used
```bash
sudo ufw default deny incoming
sudo ufw default allow outgoing
sudo ufw allow 22/tcp
sudo ufw allow 8080/tcp
sudo ufw enable
sudo ufw status verbose
