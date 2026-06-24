#include "strong.h"
#include "std.h"
void shell() {
    char *cmd = "help";
    while (1) {
        

        if(strcmp(cmd, "help") == 0) {
            print("help:このヘルプを表示する。");
        }
    }
}
void kernel_main() {
    shell();
}
