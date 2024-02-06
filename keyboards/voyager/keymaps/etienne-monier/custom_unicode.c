enum unicode_names {
    BANG,
    IRONY,
    SNEK,
    OE_LOWER,
    OE_UPPER,
};

const uint32_t PROGMEM unicode_map[] = {
    [BANG]      = 0x203D,  // ‽
    [IRONY]     = 0x2E2E,  // ⸮
    [SNEK]      = 0x1F40D, // 🐍
    [OE_LOWER]  = 0x0153,  // œ
    [OE_UPPER]   = 0x0152,  // Œ
};

#define UC_OE UP(OE_LOWER, OE_UPPER)