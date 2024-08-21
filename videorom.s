; enable 65c02 instruction set
.PC02

; zero page usages
VADDR   = $75

        .ORG $6000

; dump all characters
;
; for y in range(16):
;   for x in range(16):
;     putch(c++, x, y)
;
        LDA #0
        LDY #0 ; loop y
@LOOP_Y:
        LDX #0 ; loop x
@LOOP_X:
        PHA
        PHX
        PHY
        JSR PUTCH
        PLY
        PLX
        PLA

        INA

        INX
        CPX #16
        BNE @LOOP_X ; while (++x != 16)

        INY
        CPY #16
        BNE @LOOP_Y ; while (++y != 16)

        RTS

; putch(c, x, y)
;
; input:
; A register: c character
; X register: x position
; Y register: y position
PUTCH:
        PHA ; save c in Areg

        TYA ; y -> Areg
        ASL ; Areg = Areg*2
        TAY ; Areg -> Yreg for index
        LDA VOFFSET,Y
        STA VADDR
        LDA VOFFSET+1,Y
        STA VADDR+1     ; VADDR = OFFSET_TABLE[y << 1]
        TXA ; x -> Areg
        TAY ; Areg -> Yreg for indirect index
        PLA ; restore c -> Areg
        STA (VADDR),Y   ; ram[VADDR + x] = c
        RTS

; n1 = n1 + n2
.MACRO ADD_INT n1,n2
        LDA n1
        CLC
        ADC #<n2
        STA n1
        LDA n1+1
        ADC #>n2
        STA n1+1
.ENDMACRO

VOFFSET:
        .word $0400, $0480, $0500, $0580
        .word $0600, $0680, $0700, $0780
        .word $0428, $04A8, $0528, $05A8
        .word $0628, $06A8, $0728, $07A8
        .word $0450, $04D0, $0550, $05D0
        .word $0650, $06D0, $0750, $07D0
