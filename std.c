void print(char *s) {
    char *vga = (char*)0xb8000;
    int i = 0;

    while (s[i] != '\0') {
        vga[i * 2] = s[i];
        vga[i * 2 + 1] = 0x07;
        i++;
    }
}