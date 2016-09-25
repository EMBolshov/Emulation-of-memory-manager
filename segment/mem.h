void init();
int alloc(int size);
void free(int handle);
int read(int handle, int offset, int size, void *Data);
int write(int handle, int offset, int size, void *Data);
void dump();