#include <xinu.h>

/* Variabel global (Shared Resource) */
int32 saldo = 1000; 

/* Fungsi untuk melakukan setor tunai dengan proteksi Mutex */
void deposit_mutex(sid32 m, int32 jumlah, char* nama) {
    /* --- BAGIAN MUTEX (LOCK) --- */
    /* Proses meminta akses. Jika m=0, proses akan di-block (menunggu) */
    wait(m); 
    
    /* --- CRITICAL SECTION --- */
    /* Hanya satu proses yang bisa mengeksekusi blok ini pada satu waktu */
    int32 temp = saldo;
    temp = temp + jumlah;
    
    /* sleepms(50) memaksa context switch. Jika tidak ada mutex, 
       race condition pasti terjadi di sini. */
    sleepms(50); 
    
    saldo = temp;
    kprintf("[%s] Berhasil setor %d. Saldo saat ini: %d\n", nama, jumlah, saldo);
    
    /* --- BAGIAN MUTEX (UNLOCK) --- */
    /* Melepaskan akses (m=1), membiarkan proses lain masuk */
    signal(m); 
}

process main(void) {
    /* --- INISIALISASI MUTEX --- */
    /* Membuat semaphore dengan nilai 1 (berfungsi sebagai binary semaphore / mutex) */
    sid32 m1 = semcreate(1); 

    kprintf("\n--- Simulasi Mutex Dimulai ---\n");
    kprintf("Saldo awal: %d\n\n", saldo);
    
    /* Membuat dan menjalankan (resume) dua proses anak secara bersamaan */
    resume(create(deposit_mutex, 1024, 20, "dep_1", 3, m1, 500, "User_1"));
    resume(create(deposit_mutex, 1024, 20, "dep_2", 3, m1, 300, "User_2"));

    /* Main process tidur sebentar untuk menunggu proses anak selesai.
       Karena proses anak memakan waktu ~50ms, 200ms sudah sangat cukup. */
    sleepms(200); 

    kprintf("\nSaldo akhir: %d\n", saldo);
    kprintf("--- Simulasi Mutex Selesai ---\n\n");

    /* --- CLEANUP RESOURCE --- */
    /* Menghapus semaphore dari sistem untuk mencegah memory leak */
    semdelete(m1); 

    return OK;
}
