#!/bin/bash

# 1. PRÜFE SPEICHER (mit C-Programm)
/path/to/memory_monitor || {
    echo "$(date) - Backup abgebrochen: Zu wenig RAM!" >> /var/log/backup.log
    exit 1
}

# 2. BACKUP-ORDNER PRÜFEN
if [ ! -d "/backups" ]; then
    echo "$(date) - Ordner /backups existiert nicht. Erstelle Ordner." >> /var/log/backup.log
    mkdir -p /backups || {
        echo "$(date) - Fehler beim Erstellen des Ordners /backups." >> /var/log/backup.log
        exit 1
    }
fi

# 3. BACKUP ERSTELLEN
backup_file="/backups/backup_$(date +"%Y%m%d").tar.gz"
tar -czf "$backup_file" "/wichtige_dateien" || {
    echo "$(date) - Fehler beim Erstellen des Backups!" >> /var/log/backup.log
    exit 1
}

# 4. ERFOLG LOGGEN
size=$(du -h "$backup_file" | cut -f1)
echo "$(date) - Backup erfolgreich erstellt: $backup_file ($size)" >> /var/log/backup.log
