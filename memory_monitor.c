
#include <mach/mach.h>
#include <mach/mach_host.h>
#include <stdio.h>

#define MIN_RAM 524288000 // 500 MB in Bytes

int main() {
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
    long seiten_groesse = vm_kernel_page_size;
    long freier_speicher = freie_seiten * seiten_groesse;

    // Prüfung gegen Mindestanforderung
    if (freier_speicher < MIN_RAM) {
        printf("Zu wenig freier Speicher: %ld Bytes (benötigt: %d Bytes)\n", freier_speicher, MIN_RAM);
        return 1;
    }

    printf("Freier Speicher: %ld Bytes\n", freier_speicher);
    return 0;
}
