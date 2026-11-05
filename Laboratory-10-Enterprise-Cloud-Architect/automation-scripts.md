# Automation Scripts

**Student:** Romer Fredrick G. Morales  
**Laboratory:** Activity 10 – The Enterprise Cloud Architect

## Overview
This document explains the automation implemented in the project. A Bash script was created to perform daily backups of the Nextcloud data volume, and the script is scheduled to run automatically using Cron.

## Backup Script

### Script Name
`backup-nextcloud.sh`

### Purpose
The script creates a compressed backup (`.tar.gz`) of the Nextcloud data volume so that important files can be restored in case of failure.

### Script Content
```bash
#!/bin/bash

DATE=$(date +%Y-%m-%d_%H-%M)
BACKUP_DIR="$HOME/backups"

mkdir -p $BACKUP_DIR

docker run --rm \
  -v nextcloud-stack_nextcloud_data:/data \
  -v $BACKUP_DIR:/backup \
  alpine tar czf /backup/nextcloud-backup-$DATE.tar.gz -C /data .

echo "Backup completed successfully: nextcloud-backup-$DATE.tar.gz"
