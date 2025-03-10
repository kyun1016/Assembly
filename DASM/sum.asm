    .PROCESSOR 6502
    .ORG $8000

    clc         ;Clear Carry Flag
    lda #$0A    ;Load Accumulator with 0A
    adc #$06    ;Add 06 to Accumulator
    sta $2200   ;Store Accumulator in memory location 2200

    .ORG $FFFC,0
    .WORD $8000
    .WORD $0000