
#include <mach/mach.h>
#include <mach/mach_host.h>
#include <stdio.h>

int main() {
    // Datenstruktur, um Speicherinformationen zu speichern
    mach_msg_type_number_t count = HOST_VM_INFO_COUNT;
    vm_statistics64_data_t vm_info;
    kern_return_t kr;

    // Speicherinformationen abrufen
    kr = host_statistics64(mach_host_self(), HOST_VM_INFO, (host_info64_t)&vm_info, &count);
    if (kr != KERN_SUCCESS) {
        printf("Fehler: Speicherinformationen konnten nicht abgerufen werden.\n");
        return 1;
    }

    // Berechnung des freien Speichers
    long freie_seiten = vm_info.free_count;
    long seiten_groesse = vm_kernel_page_size; // Größe einer Seite in Bytes
    long freier_speicher = freie_seiten * seiten_groesse;

    // Ausgabe des freien Speichers
    printf("Freier Speicher: %ld Bytes\n", freier_speicher);

    return 0;
}
