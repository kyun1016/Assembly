    .PROCESSOR 6502
    .ORG $8000

    clc         ;Clear Carry Flag
    lda #$FF    ;A9 FF Load Accumulator with FF
    ASL         ;0A Arithmetic Shift Left
    lsr         ;4A Logical Shift Right
    lsr         ;4A Logical Shift Right
    ror         ;6A Rotate Accumulator right
    ror         ;6A Rotate Accumulator right
    rol         ;2A Rotate Accumulator left
    rol         ;2A Rotate Accumulator left

    .ORG $FFFC,0
    .WORD $8000
    .WORD $0000