#include "strong.h"
void kernel_main() {
    char *vga = (char *)0xb8000;
    char *mozi = "HAMA OS [Version 1.0.0]";
    int mozisuu = H_strlen(mozi);
    for (int a = 0; a<mozisuu; a++) {
        vga[a*2] = mozi[a];
        vga[a*2+1] = 0x07;
    }
}