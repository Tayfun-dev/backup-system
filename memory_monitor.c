#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    long freie_seiten = sysconf(_SC_AVPHYS_PAGES);
    long seiten_groesse = sysconf(_SC_PAGE_SIZE);

    // Fehlerprüfung
    if (freie_seiten == -1 || seiten_groesse == -1) {
        perror("Fehler bei sysconf");
        return 1;
    }

    long freier_speicher = (freie_seiten * seiten_groesse) / (1024 * 1024); // MB
    printf("Freier Speicher: %ld MB\n", freier_speicher);

    // Speichergrenze (Standard 500 MB)
    long grenze = 500;
    char *env_grenze = getenv("SPEICHERGRENZE");
    if (env_grenze) {
        grenze = atol(env_grenze);
    }

    if (freier_speicher < grenze) { // Warnung bei zu wenig Speicher
        printf("ACHTUNG: Zu wenig Speicher!\n");
        return 1; // Fehlercode fürs Bash-Skript
    }
