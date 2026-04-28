/* prototypes.h - function prototypes (snippet relevant to Modul 9) */

/* Tambahkan baris berikut ke file ./include/prototypes.h di Xinu */

/* in file ascdate.c */
extern  status  ascdate(uint32, char *);

/* in file bufinit.c */
extern  status  bufinit(void);

/* in file chprio.c */
extern  pri16   chprio(pid32, pri16);

/* in file chname.c */        /* <-- TAMBAHKAN INI */
extern  pri16   chname(pid32, pri16);

/* in file clkupdate.S */
extern  uint32  clkcount(void);

/* in file clkhandler.c */
extern  interrupt clkhandler(void);
