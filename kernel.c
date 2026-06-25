#include "strong.h"
#include "std.h"
#include "key.h"
void shell() {
    char cmd[1024];
    
    int pos = 0;
    while (1) {
        char *c = get_char();
        if (c) {
            cmd[pos] = c;
            pos++;
            cmd[pos] = '\0';

            print(c);
        }
        if(strcmp(cmd, "help") == 0) {
            print("help:このヘルプを表示する。");
        }
    }
}
void kernel_main() {
    shell();
}
