struct gate_desc {
    uint        base_lo :16;        // low address
    uint        sel     :16;        // selector
    uint        always0 :8;         // reserved
    uint        type    :4;         // type(STS_{TG,IG32,TG32})
    uint        sys     :1;         // must be 0 (system)
    uint        dpl     :2;         // descriptor(meaning new) privilege level
    uint        p       :1;         // Present
    uint        base_hi :16;        // high address
} __attribute__((packed));

struct idt_desc {
    ushort      limit;
    uint        base;
} __attribute__((packed));     

struct trap_frame {
    uint        gs, fs, es, ds;                             /* pushed the segs last */
    uint        edi, esi, ebp, _esp, ebx, edx, ecx, eax;    /* pushed by 'pusha' */
    uint        int_no, err_code;                           /* our 'push byte #' and ecodes do this */
    uint        eip, cs, eflags, esp, ss;                   /* pushed by the processor automatically */ 
} __attribute__((packed));

#define IRQ0 32