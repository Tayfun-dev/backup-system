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
39| gcc memory_monitor.c -o memory_monitor
40| ```
41| 
42| Führe dann das Programm aus, um den freien Speicher zu prüfen:
43| ```bash
44| ./memory_monitor
45| ```
46| 
47| ### 2. **Backup-Skript ausführen**
48| Stelle sicher, dass das Bash-Skript ausführbar ist:
49| ```bash
50| chmod +x backup.sh
51| ```
52| 
53| Starte das Skript:
54| ```bash
55| ./backup.sh
56| ```
57| 
58| ### 3. **Logs überprüfen**
59| Nach der Ausführung kannst du die Logs ansehen, um sicherzustellen, dass das Backup erfolgreich war:
60| ```bash
61| cat /var/log/backup.log
62| ```
63| 
64| ---
65| 
66| ## 📋 Voraussetzungen
67| 
68| - **GCC**: Zum Kompilieren des C-Programms (`memory_monitor.c`).
69| - **Bash**: Für das Ausführen des Skripts.
70| - Zugriff auf die Verzeichnisse `/wichtige_dateien` und `/backups`.
71| 
72| ---
73| 
74| ## 🌟 Features
75| 
76| - Automatische Speicherprüfung, um sicherzustellen, dass genügend RAM für das Backup vorhanden ist.
77| - Erstellung von Backups mit Datumsstempel im Dateinamen.
78| - Logging für Fehler- und Erfolgsberichte.
79| 
80| ---
81| 
82| ## 🛡️ Sicherheitshinweise
83| 
84| - Stelle sicher, dass nur autorisierte Benutzer Zugriff auf das Skript und die Backups haben.
85| - Vermeide, sensible Daten in den Logs zu speichern.
86| - Falls das Skript `sudo`-Berechtigungen benötigt, stelle sicher, dass die `sudoers`-Datei korrekt konfiguriert ist.
87| 
88| ---
89| 
90| ## 🔧 Anpassungen
91| 
92| - **Backup-Quelle ändern**: Bearbeite die Variable `/wichtige_dateien` im Skript, um die Dateien oder Verzeichnisse zu ändern, die gesichert werden sollen.
93| - **Speichergrenze anpassen**: Ändere die Mindestanforderung im C-Programm, um die gewünschte RAM-Grenze festzulegen.
94| 
95| ---
96| 
97| ## 🤝 Beiträge
98| 
99| Beiträge sind willkommen! Öffne einfach einen Issue oder erstelle einen Pull-Request.
100| 
101| ---
102| 
103| ## 📜 Lizenz
104| 
105| Dieses Projekt steht unter der MIT-Lizenz. Weitere Informationen findest du in der Datei `LICENSE`.
