#include <stdbool.h>
#include <sys/stat.h>
// This stub function is required by _mainCRTSturtup
void exit(int status)
{
    (void)(status);
    while (true) {}
}

// This stub function is required by stdlib
void _exit()
{
    exit(-1);
}

// This heap allocation stub is required by stdlib
unsigned _sbrk(int inc)
{
    (void)(inc);
    return 0; // The application is not intended to be executed, no need for actual heap.
}

// This stub function is required by stdlib
int _kill(int pid, int sig)
{
    (void)(pid);
    (void)(sig);
    return -1;
}

// This stub function is required by stdlib
int _getpid(void) {
    return 1;
}

// This stub function is required by stdlib
int _write(int file, char *ptr, int len)
{
    (void)(file);
    (void)(ptr);
    return len;
}

// This stub function is required by stdlib
int _read(int file, char *ptr, int len)
{
    (void)(file);
    (void)(ptr);
    (void)(len);
    return 0;
}

// This stub function is required by stdlib
int _close(int file)
{
    (void)(file);
    return -1;
}

// This stub function is required by stdlib
int _fstat(int file, struct stat *st)
{
    (void)(file);
    (void)(st);
    return -1;
}

// This stub function is required by stdlib
int _isatty(int file)
{
    (void)(file);
    return 1;
}

// This stub function is required by stdlib
int _open(const char *name, int flags, int mode)
{
    (void)(name);
    (void)(flags);
    (void)(mode);
    return -1;
}

// This stub function is required by stdlib
int _lseek(int file, int ptr, int dir)
{
    (void)(file);
    (void)(ptr);
    (void)(dir);
    return 0;
}
