#include <mach/mach.h>
#include <mach/mach_host.h>
#include <stdio.h>

int main() {
    mach_msg_type_number_t count = HOST_VM_INFO_COUNT;
    vm_statistics64_data_t vm_info;
    kern_return_t kr = host_statistics64(mach_host_self(), HOST_VM_INFO, (host_info64_t)&vm_info, &count);

    if (kr != KERN_SUCCESS) {
        printf("Fehler beim Abrufen der Speicherinformationen.\n");
        return 1;
    }

    long freie_seiten = vm_info.free_count;
    long seiten_groesse = vm_kernel_page_size;
    long freier_speicher = freie_seiten * seiten_groesse;

    printf("Freier Speicher: %ld Bytes\n", freier_speicher);

    return 0;
}
