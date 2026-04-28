/* template_syscall.c - template untuk membuat syscall baru di Xinu */

/*------------------------------------------------------------------------
 * function_name  -  Deskripsi singkat fungsi syscall ini
 *------------------------------------------------------------------------
 */
syscall function_name(/* args */)
{
        intmask mask;       /* Saved interrupt mask                     */

        mask = disable();   /* Disable interrupts at start of function  */

        if (/* args are incorrect */) {
                restore(mask);  /* Restore interrupts before error return */
                return SYSERR;
        }

        /* ... other processing ... */

        if (/* an error occurs */) {
                restore(mask);  /* Restore interrupts before error return */
                return SYSERR;
        }

        /* ... more processing ... */

        restore(mask);          /* Restore interrupts before normal return */
        return /* appropriate value */;
}
