    .PROCESSOR 6502
    .ORG $8000

    clc
    lda #$0A
    adc #$06
    sta $2200