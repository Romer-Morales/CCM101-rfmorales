# Security Configuration


## Firewall Policy
- **Default Incoming:** Deny (Blocks all unauthorized inbound connections)[cite: 2]
- **Default Outgoing:** Allow (Permits container package updates and downloads)[cite: 2]

---

## Allowed Ports

| Port | Protocol | Purpose | Access Control |
| :--- | :--- | :--- | :--- |
| **22** | TCP | SSH (Remote Server Administration) | System Administrators[cite: 2] |
| **80** | TCP | Nextcloud Web Interface Access | Public / Host Browser[cite: 2] |

*Note: Database Port 3306 (MariaDB) is deliberately NOT allowed through UFW, as it is isolated within the internal Docker bridge network.*[cite: 2]

---

## Configuration Commands Executed

```bash
# Set strict default policies
sudo ufw default deny incoming
sudo ufw default allow outgoing

# Allow required infrastructure ports
sudo ufw allow 22/tcp
sudo ufw allow 80/tcp

# Enable firewall and verify active rules
sudo ufw enable
sudo ufw status verbose
```[cite: 2]
