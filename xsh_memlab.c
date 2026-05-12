#include <xinu.h>
#include <stdio.h>

int global_data_var = 42;
int global_bss_var;
void text_marker() {}

shellcmd xsh_memlab(int argc, char *argv[]) {
        int stack_var;
        char *heap_ptr;
        uint32 size = 1024;

        printf("\n === Praktikum Sistem Operasi 24-04 ===");

        //Tampilan Alamat Segmen
        printf("\n1. Pemetaan Segmen Statis:\n");
        printf("\n [Text] Alamat Fungsi : %08x", (uint32)&text_marker);
        printf("\n [Data] Variabel Glob : %08x", (uint32)&global_data_var);
        printf("\n [BSS] Variabel Glob  : %08x", (uint32)&global_bss_var);

        //Tampilan Stack vs Heap
        heap_ptr = (char *)getmem(size);
        printf("\n\n2. Alokasi Dinamis");
        printf(" \n[Stack] Alamat Lokal : %08x", (uint32)&stack_var);

        if ((int32)heap_ptr != SYSERR) {
                printf(" \n[Heap] Alamat getmem : %08x", (uint32)heap_ptr);
                freemem(heap_ptr, size);
        }

        printf("\n================================\n\n");
        return 0;
}
