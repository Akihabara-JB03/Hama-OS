#include "string.h"
void kernel_main() {
    char *vga = (char *)0xb8000;
    char *mozi = "HAMA OS [Version 1.0.0]";
    int mozisuu = strlen(mozi);
    for (int a = 0; a<((mozisuu * 2) + 2); a+=2) {
        vga[a] = mozi[a/2];
        vga[a+1] = 0x07;
    }
}