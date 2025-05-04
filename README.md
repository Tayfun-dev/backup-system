# Backup-System

Hey! 👋 Willkommen zu meinem kleinen Backup-System-Projekt.  
Hier geht's darum, den freien Speicher zu checken und ein Backup deiner wichtigen Dateien zu erstellen.

---

## 🛠️ Was macht das Projekt?

1. **Speicherprüfung**  
   Bevor ein Backup erstellt wird, prüft das Programm, ob genug freier RAM vorhanden ist.  
   Wenn der Speicher zu knapp ist, wird das Backup abgebrochen, um Probleme zu vermeiden.

2. **Backup erstellen**  
   Wenn genug Speicher da ist, werden wichtige Dateien in einem `.tar.gz`-Archiv gesichert.  
   Das Backup wird automatisch mit einem Datum versehen, z. B. `backup_20250430.tar.gz`.

---

## 📂 Dateien im Projekt

- **`memory_monitor`**  
  Ein C-Programm, das prüft, wie viel RAM noch frei ist. Gibt eine Warnung aus, wenn es kritisch wird.

- **`backup.sh`**  
  Ein Bash-Skript, das:
  - Den Speicher mit `memory_monitor` checkt.
  - Ein Backup von `/wichtige_dateien` erstellt und es in `/backups` speichert.
  - Logs schreibt, damit du sehen kannst, was passiert ist.

---

## 🚀 So benutzt du das Projekt

### 1. **Speicher prüfen**
Kompiliere zuerst das C-Programm:
```bash
gcc memory_monitor.c -o memory_monitor
 ```
 Führe dann das Programm aus, um den freien Speicher zu prüfen:
 ```bash
 ./memory_monitor
 ```
 ### 2. **Backup-Skript ausführen**
Stelle sicher, dass das Bash-Skript ausführbar ist:
```bash
chmod +x backup.sh
```
 Starte das Skript:
 ```bash
 ./backup.sh
 ```
### 3. **Logs überprüfen**
Nach der Ausführung kannst du die Logs ansehen, um sicherzustellen, dass das Backup erfolgreich war:
```bash
cat /var/log/backup.log
```
 ---
 ## 📋 Voraussetzungen

 - **GCC**: Zum Kompilieren des C-Programms (`memory_monitor.c`).
 - **Bash**: Für das Ausführen des Skripts.
 -   Zugriff auf die Verzeichnisse `/wichtige_dateien` und `/backups`.
 ---
    
 ## 🌟 Features

 - Automatische Speicherprüfung, um sicherzustellen, dass genügend RAM für das Backup vorhanden ist.
 - Erstellung von Backups mit Datumsstempel im Dateinamen.
 - Logging für Fehler- und Erfolgsberichte.
 
 ---
 
 ## 🛡️ Sicherheitshinweise
 
 - Stelle sicher, dass nur autorisierte Benutzer Zugriff auf das Skript und die Backups haben.
 - Vermeide, sensible Daten in den Logs zu speichern.
 - Falls das Skript `sudo`-Berechtigungen benötigt, stelle sicher, dass die `sudoers`-Datei korrekt konfiguriert ist.
 
 ---
 
 ## 🔧 Anpassungen
 
 - **Backup-Quelle ändern**: Bearbeite die Variable `/wichtige_dateien` im Skript, um die Dateien oder Verzeichnisse zu ändern, die gesichert werden sollen.
 - **Speichergrenze anpassen**: Ändere die Mindestanforderung im C-Programm, um die gewünschte RAM-Grenze festzulegen.
 
 ---
 
 ## 🤝 Beiträge
 
 Beiträge sind willkommen! Öffne einfach einen Issue oder erstelle einen Pull-Request.

 ---
 
 ## 📜 Lizenz
 
 Dieses Projekt steht unter der MIT-Lizenz. Weitere Informationen findest du in der Datei `LICENSE`.
