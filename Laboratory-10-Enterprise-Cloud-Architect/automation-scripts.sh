#!/bin/bash
# ==============================================================================
# Enterprise Disaster Recovery & Automated Backup Script
# Stack: Nextcloud + MariaDB
# ==============================================================================

# Define absolute paths for Cron stability
BACKUP_DIR="/var/backups/nextcloud"
LOG_FILE="/var/log/nextcloud_backup.log"
DATE=$(date +%Y-%m-%d_%H-%M-%S)

# Create backup directory if it does not exist
mkdir -p "$BACKUP_DIR"

echo "[$DATE] --- Starting Nextcloud Automated Backup ---" >> "$LOG_FILE"

# 1. Backup Nextcloud Data Volume
echo "[$DATE] Backing up Nextcloud data volume..." >> "$LOG_FILE"
docker run --rm \
  -v nextcloud-stack_nextcloud_data:/data \
  -v "$BACKUP_DIR":/backup \
  alpine tar czf "/backup/nextcloud-data-$DATE.tar.gz" -C /data . 2>> "$LOG_FILE"

# 2. Backup Database Dump (Assuming MariaDB container name is 'nextcloud-db')
echo "[$DATE] Dumping MariaDB database..." >> "$LOG_FILE"
docker exec nextcloud-db mysqldump -u root -pSecureRootPassword123! nextcloud_db > "$BACKUP_DIR/nextcloud-db-$DATE.sql" 2>> "$LOG_FILE"

# Compress database dump
gzip "$BACKUP_DIR/nextcloud-db-$DATE.sql"

# 3. Retention Cleanup (Delete backups older than 7 days)
echo "[$DATE] Removing backups older than 7 days..." >> "$LOG_FILE"
find "$BACKUP_DIR" -type f -mtime +7 -exec rm -f {} \; >> "$LOG_FILE" 2>&1

echo "[$DATE] Backup completed successfully." >> "$LOG_FILE"
```[cite: 2, 3]

---

### Step 3: Deployment & Scheduling Steps

Execute the following commands on your Ubuntu VM server to enable and test the automation[cite: 2, 3]:

1. **Make the script executable:**
   ```bash
   chmod +x automation-script.sh
   ```

2. **Test run manually and verify log output:**
   ```bash
   sudo ./automation-script.sh
   cat /var/log/nextcloud_backup.log
   ls -la /var/backups/nextcloud
   ```[cite: 3]

3. **Schedule the Cron Job:**
   Open crontab[cite: 3]:
   ```bash
   crontab -e
