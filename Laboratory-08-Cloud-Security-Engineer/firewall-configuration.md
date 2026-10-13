# Firewall Configuration Documentation

## Default Policy Applied
- Incoming traffic: **Deny**
- Outgoing traffic: **Allow**

## Allowed Ports
| Port   | Protocol | Purpose                  |
|--------|----------|--------------------------|
| 22     | TCP      | SSH (remote access)      |
| 8080   | TCP      | HTTP (Nginx web server)  |

## Commands Used
- `sudo ufw default deny incoming`
- `sudo ufw default allow outgoing`
- `sudo ufw allow 22/tcp`
- `sudo ufw allow 8080/tcp`
- `sudo ufw enable`
- `sudo ufw status verbose`

## Explanation
By setting a Default Deny policy, only the ports that I explicitly allowed (SSH and HTTP) can receive incoming traffic. This follows the Principle of Least Privilege and reduces the server’s attack surface.
