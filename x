==8464== Memcheck, a memory error detector
==8464== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==8464== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
==8464== Command: ./linked_list.o
==8464== 
==8464== Conditional jump or move depends on uninitialised value(s)
==8464==    at 0x4E87B83: vfprintf (vfprintf.c:1631)
==8464==    by 0x4E8F898: printf (printf.c:33)
==8464==    by 0x400A0B: main (in /homes/rrr2417/Documents/C-ADTs/linked_list.o)
==8464== 
==8464== Use of uninitialised value of size 8
==8464==    at 0x4E8476B: _itoa_word (_itoa.c:179)
==8464==    by 0x4E8812C: vfprintf (vfprintf.c:1631)
==8464==    by 0x4E8F898: printf (printf.c:33)
==8464==    by 0x400A0B: main (in /homes/rrr2417/Documents/C-ADTs/linked_list.o)
==8464== 
==8464== Conditional jump or move depends on uninitialised value(s)
==8464==    at 0x4E84775: _itoa_word (_itoa.c:179)
==8464==    by 0x4E8812C: vfprintf (vfprintf.c:1631)
==8464==    by 0x4E8F898: printf (printf.c:33)
==8464==    by 0x400A0B: main (in /homes/rrr2417/Documents/C-ADTs/linked_list.o)
==8464== 
==8464== Conditional jump or move depends on uninitialised value(s)
==8464==    at 0x4E881AF: vfprintf (vfprintf.c:1631)
==8464==    by 0x4E8F898: printf (printf.c:33)
==8464==    by 0x400A0B: main (in /homes/rrr2417/Documents/C-ADTs/linked_list.o)
==8464== 
==8464== Conditional jump or move depends on uninitialised value(s)
==8464==    at 0x4E87C59: vfprintf (vfprintf.c:1631)
==8464==    by 0x4E8F898: printf (printf.c:33)
==8464==    by 0x400A0B: main (in /homes/rrr2417/Documents/C-ADTs/linked_list.o)
==8464== 
==8464== Conditional jump or move depends on uninitialised value(s)
==8464==    at 0x4E8841A: vfprintf (vfprintf.c:1631)
==8464==    by 0x4E8F898: printf (printf.c:33)
==8464==    by 0x400A0B: main (in /homes/rrr2417/Documents/C-ADTs/linked_list.o)
==8464== 
==8464== Conditional jump or move depends on uninitialised value(s)
==8464==    at 0x4E87CAB: vfprintf (vfprintf.c:1631)
==8464==    by 0x4E8F898: printf (printf.c:33)
==8464==    by 0x400A0B: main (in /homes/rrr2417/Documents/C-ADTs/linked_list.o)
==8464== 
==8464== Conditional jump or move depends on uninitialised value(s)
==8464==    at 0x4E87CE2: vfprintf (vfprintf.c:1631)
==8464==    by 0x4E8F898: printf (printf.c:33)
==8464==    by 0x400A0B: main (in /homes/rrr2417/Documents/C-ADTs/linked_list.o)
==8464== 
==8464== Use of uninitialised value of size 8
==8464==    at 0x40081E: get_node_value (in /homes/rrr2417/Documents/C-ADTs/linked_list.o)
==8464==    by 0x400987: find (in /homes/rrr2417/Documents/C-ADTs/linked_list.o)
==8464==    by 0x400A3E: main (in /homes/rrr2417/Documents/C-ADTs/linked_list.o)
==8464== 
==8464== Invalid read of size 4
==8464==    at 0x40081E: get_node_value (in /homes/rrr2417/Documents/C-ADTs/linked_list.o)
==8464==    by 0x400987: find (in /homes/rrr2417/Documents/C-ADTs/linked_list.o)
==8464==    by 0x400A3E: main (in /homes/rrr2417/Documents/C-ADTs/linked_list.o)
==8464==  Address 0x0 is not stack'd, malloc'd or (recently) free'd
==8464== 
==8464== 
==8464== Process terminating with default action of signal 11 (SIGSEGV)
==8464==  Access not within mapped region at address 0x0
==8464==    at 0x40081E: get_node_value (in /homes/rrr2417/Documents/C-ADTs/linked_list.o)
==8464==    by 0x400987: find (in /homes/rrr2417/Documents/C-ADTs/linked_list.o)
==8464==    by 0x400A3E: main (in /homes/rrr2417/Documents/C-ADTs/linked_list.o)
==8464==  If you believe this happened as a result of a stack
==8464==  overflow in your program's main thread (unlikely but
==8464==  possible), you can try to increase the size of the
==8464==  main thread stack using the --main-stacksize= flag.
==8464==  The main thread stack size used in this run was 8388608.
==8464== 
==8464== HEAP SUMMARY:
==8464==     in use at exit: 96 bytes in 4 blocks
==8464==   total heap usage: 5 allocs, 1 frees, 1,120 bytes allocated
==8464== 
==8464== LEAK SUMMARY:
==8464==    definitely lost: 0 bytes in 0 blocks
==8464==    indirectly lost: 0 bytes in 0 blocks
==8464==      possibly lost: 0 bytes in 0 blocks
==8464==    still reachable: 96 bytes in 4 blocks
==8464==         suppressed: 0 bytes in 0 blocks
==8464== Rerun with --leak-check=full to see details of leaked memory
==8464== 
==8464== For counts of detected and suppressed errors, rerun with: -v
==8464== Use --track-origins=yes to see where uninitialised values come from
==8464== ERROR SUMMARY: 10 errors from 10 contexts (suppressed: 0 from 0)
