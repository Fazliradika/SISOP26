/* xsh_mycmd.c - xsh_mycmd */

#include <xinu.h>
#include <stdio.h>
#include <string.h>
// deklarasi nama fungsi
static void    printMemUse(void);

shellcmd xsh_mycmd(int nargs, char *args[]) {

    /* For argument '--help', emit help about the 'ping' command   */
    // mycmd --help
    // jika perintah adalah "mycmd --help" tampilkan help
    if (nargs == 2 && strncmp(args[1], "--help", 7) == 0) {
        printf("Use: %s  argumentdd1 argumen2\n\n", args[0]);
        printf("Description:\n");
        printf("\tMy own command with 2 argument\n");
        printf("Options:\n");
        printf("\t--help\t display this help and exit\n");
        return 0;
    }

    /* Check for valid number of arguments */
    // banyaknya argument harus 2; args[0] = nama_perintah args[1]= argumen 1 args[2] = argumen 2
    if (nargs != 3) {
        fprintf(stderr, "%s: jumlah argumen tidak cocok\n", args[0]);
        fprintf(stderr, "Try '%s --help' for more information\n",
            args[0]);
        return 1;
    }

    printMemUse();
    printf("Nama perintah adalah: %s \n", args[0]);
    printf("Argumen pertama adalah: %s \n", args[1]); // 123
    printf("Argumen kedua adalah: %s \n", args[2]); // xxx
    return 0;
}

/*------------------------------------------------------------------------
 * printMemUse - Print statistics about memory use
 *------------------------------------------------------------------------
 */
void printMemUse(void){
    printf("My memory usage is xxxx\n");
}
