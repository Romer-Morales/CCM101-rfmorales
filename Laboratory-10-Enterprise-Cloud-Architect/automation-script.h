#!/bin/bash
# ==============================================================================
# Enterprise Disaster Recovery & Automated Backup Script
# Stack: Nextcloud + MariaDB
# ==============================================================================

BACKUP_DIR="/home/ubuntu/backups"
LOG_FILE="/var/log/nextcloud_backup.log"
DATE=$(date +%Y-%m-%d_%H-%M-%S)

# Create backup directory if missing
mkdir -p "$BACKUP_DIR"

echo "[$DATE] Starting automated backup process..." >> "$LOG_FILE"

# 1. Back up Nextcloud Data Volume
# Note: Ensure the volume name matches 'docker volume ls' output
echo "[$DATE] Compressing Nextcloud data volume..." >> "$LOG_FILE"
docker run --rm \
  -v nextcloud-stack_nextcloud_data:/data \
  -v "$BACKUP_DIR":/backup \
  alpine tar czf "/backup/nextcloud-data-$DATE.tar.gz" -C /data . 2>> "$LOG_FILE"

# 2. Dump MariaDB Database
echo "[$DATE] Dumping MariaDB database..." >> "$LOG_FILE"
docker exec nextcloud-db mysqldump -u root -pRootPassword123 nextcloud > "$BACKUP_DIR/nextcloud-db-$DATE.sql" 2>> "$LOG_FILE"

# Compress SQL dump
gzip -f "$BACKUP_DIR/nextcloud-db-$DATE.sql"

# 3. Retention Cleanup (Remove backups older than 7 days)
echo "[$DATE] Cleaning up backups older than 7 days..." >> "$LOG_FILE"
find "$BACKUP_DIR" -type f \( -name "*.tar.gz" -o -name "*.sql.gz" \) -mtime +7 -exec rm -f {} \; >> "$LOG_FILE" 2>&1

echo "[$DATE] Backup completed successfully." >> "$LOG_FILE"
```[cite: 2, 3]

---

### Step 2: Fix File Name & Commit to GitHub

Run these commands in your Git terminal inside your local repository to rename the file from plural (`automation-scripts.sh`) to singular (`automation-script.sh`) and push the changes[cite: 3, 6]:

<Steps>
  <Step subtitle="Terminal Command" title="Navigate to Lab Directory">
    Change directory into your Laboratory 10 folder[cite: 3]:

    ```bash
    cd CCM101-rfmorales/Laboratory-10-Enterprise-Cloud-Architect
    ```
  </Step>

  <Step subtitle="Git Rename" title="Rename File to Singular Form">
    Use Git to rename the file so GitHub tracks the change cleanly[cite: 3]:

    ```bash
    git mv automation-scripts.sh automation-script.sh
    ```

    *Verification:* Run `ls` and confirm the file is now listed as `automation-script.sh`[cite: 3].
  </Step>

  <Step subtitle="Git Push" title="Commit and Push to GitHub">
    Commit the filename fix and push to your main repository branch[cite: 3]:

    ```bash
    git add automation-script.sh
    git commit -m "Fix file name to singular automation-script.sh and update backup logic"
    git push origin main
    ```

    *Verification:* Refresh your GitHub repository page (`CCM101-rfmorales/Laboratory-10-Enterprise-Cloud-Architect`) and verify `automation-script.sh` appears without the trailing "s"[cite: 3, 6].
  </Step>
</Steps>
