# Dynamic-Allocation
So far we learned that:

Malloc:
    It gets a block of size determined by the user and reservates this
    as memory space for the pointer to save whatever info it want
    (The information saved inside the pointer must be the same type as declared pointer).
    It also separate memories in spaces called "chunks". So, you can refer to that chunk and work with a part of memory

    Example can be found in: https://cplusplus.com/reference/cstdlib/malloc/

Free:
    As the name sugests, it free the memory alocated by malloc.
    One important thing to be aware is that when we execute the command free(void*)
    the data inside that memory block is not erased just in time, they will only be erased
    when the OS alocates the memory block for another proccess and the proccess write above the used address

    If the command free do not run and you point to another address the old data will still remain used and the set data
    of the address wont be used by anyone else

Calloc:
    Acts like malloc but it has 2 main differences
    1 - Erases all the data inside the block it reserves and replace it with a 0 (zero)
    2 - You can set how many blocks do you want to be reservated


Realloc (https://www.gnu.org/software/libc/manual/html_node/Changing-Block-Size.html):
    If you need to get more less (NOT RECOMENDED ) memory for a pointer this is the common statment to use.
    When the operation is performed, the content inside the pointer is copied to another address in the memory
    example:
        lets suppose we have address A with values (0,1,2,3,4) and we need to get more memory
        What the system does is check for new address with more space, lets call it B

        Before receive A information B is like that (0,0,0,0,0,0,0,0,0). After realoc B will look like this (0,1,2,3,4,0,0,0,0)
        It is not well described in the text, but I believe after realloc A sets the old address free


Mcheck:
    It validates the heap to see if can find any corruption inside the memory. It is configurable as said here
    https://www.gnu.org/software/libc/manual/html_node/Heap-Consistency-Checking.html

How GNU WORKS (https://www.gnu.org/software/libc/manual/html_node/Memory-Allocation-and-C.html#Dynamic-Memory-Allocation)
As described in the site, 
***The only way to get dynamically allocated memory is via a system call***
This affirmation could be a hint of what I need to do to create my own memory allocator.
Another interesting thing about dynamic allocation is that it requires more computation time
So, just used it when its really need

SBRK:
    This is a instruction that abstracts system calls, the command goes to the system and asks for more HEAP memory.
    In my vision,its not ideal to use this as malloc replace bc it request so many memory to the system. And every time we ask for memory
    the proccess of get this in the system is slow (malloc just points to the new address on the current memory)

    I'll use this strategy in V1 just to construct for the first time things like "malloc" and "free"

-----------------------------------------------------------------------------------
Memory layout
By default when working in C the OS separate the memory in 4 slots

STACK
HEAP
STATIC/GLOBAL
CODE


STACK:
    This part is reserved to call functions and keep they in the memory. Its LIFO (Last in -> First out)style
    that means that the way to remove functions from the stack is to remove the most recent called function.
    
    The famous error "stack overflow" exists because the stack gets full, when this happens it invades other reserved parts (like HEAP)
    as a strategy to protect the computer the error is thrown.

    The reservations occurs top to bottom, which means the first address is 0xFFFF and goes to 0x0000

HEAP:
    This is a dynamic memory, when the program needs to hold an info that not necessarily depends on the LIFO style
    it is recommened to put the data inside HEAP.

    The reservations occurs top to bottom, which means the first address is 0x0000 and goes to 0xFFFF

STATIC/GLOBAL:
    This part of memory holds the information global variables and static variables.
    In C and C++ if you declare static/global variables it will be allocated here and it will
    be destroyed only in the end of the program.

CODE:
    Holds the instructions to run our code 
    (I believe that is correct to say the longer is our code. More memory we use.)


-----------------------------------------------------------------------------------

V1 finished:
    I believe the main goal was reached, I could create a really simple memory manager.
    Even the code been really small it took me more than 7 hours (including POC)
    between the start of studies and the V1 itself.

    The code has a lot of problems of performance and memory management, please do not use it in any important code


-----------------------------------------------------------------------------------

V2 Ideas:
    The code has some parts that could be better, those parts are:
        1 - Check if theres any other way to manipulate heap (sbrk and brk asks more memory for OS and this is bad)
        2 - Create a garbage collector (The applied logic do not have problems with memory leak, but bc it asks everytime for memory its slow.)
        3 - The code run everything but in the end it shows a "Segmentation fault (core dumped)" error. We must fix it.
        4 - Create a CMAKE file