#include "strong.h"
#include "std.h"
void kernel_main() {
    shell()
}
void shell() {
    cmd = "help";
    while (1) {
        

        if(strcmp(cmd, "help") == 0) {
            print("help:このヘルプを表示する。")
        }
    }
}