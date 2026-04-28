/* xsh_uptime.c - xsh_uptime */

#include <xinu.h>

/*------------------------------------------------------------------------
 * xsh_uptime  -  Shell command to display system uptime
 *                Also calls chname() syscall as demonstration
 *------------------------------------------------------------------------
 */
shellcmd xsh_uptime(int nargs, char *args[])
{
        uint32  now;
        uint32  days, hrs, mins, secs;

        now  = clktime;
        days = now / 86400;
        now  = now % 86400;
        hrs  = now / 3600;
        now  = now % 3600;
        mins = now / 60;
        secs = now % 60;

        printf("Xinu has been up ");

        if (days > 0) {
                printf(" %d day(s) ", days);
        }

        if (hrs > 0) {
                printf(" %d hour(s) ", hrs);
        }

        if (mins > 0) {
                printf(" %d minute(s) ", mins);
        }

        if (secs > 0) {
                printf(" %d second(s) ", secs);
        }

        printf("\n");
        chname(1, 20);      /* Call new chname() syscall */

        return 0;
}
