LOG_FILE="/var/log/backup.log"

# PRÜFE SPEICHER
/path/to/memory_monitor || {
    echo "$(date) - Backup abgebrochen: Zu wenig RAM!" >> "$LOG_FILE"
    exit 1
}

# BACKUP-ORDNER PRÜFEN
if [ ! -d "/backups" ]; then
    echo "$(date) - Ordner /backups existiert nicht. Erstelle Ordner." >> "$LOG_FILE"
    mkdir -p /backups || {
        echo "$(date) - Fehler beim Erstellen des Ordners /backups." >> "$LOG_FILE"
        exit 1
    }
fi

# BACKUP ERSTELLEN
backup_file="/backups/backup_$(date +"%Y%m%d").tar.gz"
tar -czf "$backup_file" "/wichtige_dateien" || {
    echo "$(date) - Fehler beim Erstellen des Backups!" >> "$LOG_FILE"
    exit 1
}

# ERFOLG LOGGEN
size=$(du -h "$backup_file" | cut -f1)
echo "$(date) - Backup erfolgreich erstellt: $backup_file ($size)" >> "$LOG_FILE"
