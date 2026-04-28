/* resume.c - resume */

#include <xinu.h>

/*------------------------------------------------------------------------
 * resume  -  Unsuspend a process, making it ready
 *------------------------------------------------------------------------
 */
pri16   resume(
        pid32   pid     /* ID of process to unsuspend   */
        )
{
        intmask mask;               /* Saved interrupt mask         */
        struct  procent *prptr;     /* Ptr to process's table entry */
        pri16   prio;               /* Priority to return           */

        mask = disable();           /* 1. Disable interrupts        */
        if (isbadpid(pid)) {
                restore(mask);      /* 2. Restore before error return */
                return (pri16)SYSERR;
        }
        prptr = &proctab[pid];
        if (prptr->prstate != PR_SUSP) {
                restore(mask);      /* 3. Restore before error return */
                return (pri16)SYSERR;
        }
        prio = prptr->prprio;       /* Record priority to return    */
        ready(pid);                 /* 4. Make process ready        */
        restore(mask);              /* 5. Restore interrupts        */
        return prio;                /* 6. Return recorded priority  */
}
