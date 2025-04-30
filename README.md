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
