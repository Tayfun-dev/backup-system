#include <stdio.h>
#include <unistd.h>

int main() {
    long freie_seiten = sysconf(_SC_AVPHYS_PAGES);
    long seiten_groesse = sysconf(_SC_PAGE_SIZE);
    long freier_speicher = (freie_seiten * seiten_groesse) / (1024 * 1024); // MB

    printf("Freier Speicher: %ld MB\n", freier_speicher);
    
    if (freier_speicher < 500) { // Warnung bei < 500 MB frei
        printf("ACHTUNG: Zu wenig Speicher!\n");
        return 1; // Fehlercode fürs Bash-Skript
    }
    return 0;
}
