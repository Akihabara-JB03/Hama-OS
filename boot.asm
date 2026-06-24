[bits 16]
org 0x7c00

start:
    ; 画面をクリアしてテキストモード（80x25）にする
    mov ax, 0x0003
    int 0x10

    ; ディスクからC言語（カーネル）をメモリ（0x1000:0000 ＝ 0x10000）に読み込む
    mov ax, 0x1000
    mov es, ax
    mov bx, 0x0000

    mov ah, 0x02         ; ディスク読み込み命令
    mov al, 10           ; 10セクタ分（約5KB）多めに読み込む
    mov ch, 0            ; シリンダ 0
    mov dh, 0            ; ヘッド 0
    mov cl, 2            ; 2番目のセクタから読み込み
    mov dl, 0x00         ; フロッピーディスク（0x00）
    int 0x13             ; BIOS実行

    ; 32ビットの本気モードへ切り替える準備
    cli
    lgdt [gdt_descriptor]
    mov eax, cr0
    or eax, 1
    mov cr0, eax

    ; 32ビットモードへジャンプ！
    jmp 0x08:init_pm

[bits 32]
init_pm:
    mov ax, 0x10
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    ; メモリ 0x10000 にあるC言語の kernel_main を直接呼び出す！
    call 0x10000

halt:
    hlt
    jmp halt

; --- GDT（32ビットモード用の秘密の設定） ---
align 4
gdt_start:
    dq 0x0000000000000000
    dq 0x00cf9a000000ffff
    dq 0x00cf92000000ffff
gdt_end:
gdt_descriptor:
    dw gdt_end - gdt_start - 1
    dd gdt_start

; 512バイトの目印
times 510-($-$$) db 0
dw 0xaa55
