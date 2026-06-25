static inline unsigned char inb(unsigned short port) {
    unsigned char ret;

    __asm__ __volatile__(
        "inb %1, %0"
        : "=a"(ret)
        : "Nd"(port)
    );

    return ret;
}
char scancode_table[128] = {
    0,
    27,
    '1','2','3','4','5','6','7','8','9','0',
    '-','=',
    '\b',
    '\t',
    'q','w','e','r','t','y','u','i','o','p',
    '[',']',
    '\n',
    0,
    'a','s','d','f','g','h','j','k','l',
    ';','\'','`',
    0,
    '\\',
    'z','x','c','v','b','n','m',
    ',','.','/'
};

char get_char() {
    unsigned char sc = inb(0x60);

    if (sc >= 128)
        return 0;

    return scancode_table[sc];
}
