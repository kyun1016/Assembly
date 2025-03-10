#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define SIZE (0x8000)

int main()
{
    const char* FILENAME = "../bin/program.bin";

    FILE* outfile;
    char bin_out[SIZE] = { 0, };
    size_t program_size;


    // // unsigned char a;
    // // while(true) a=0xFF;
    // const char program[] = {
    //     0xA9, 0xFF,
    //     0x4C, 0x00, 0x80
    // };

    // int* p
    // *p = 0x0A + 0x06;
    // a = *p;
    const char program[] = {
        0x18,               /* clc */
        0xA9, 0x0A,         /* lda #$0A */
        0x69, 0x06,         /* adc #$06 */
        0x8D, 0x00, 0x22,   /* sta $2200, 2200번지에 값을 저장 */
        0xAD, 0x00, 0x22    /* lda $2200, 2200번지의 값을 읽기 */
    };

    program_size = sizeof(program) / sizeof(char);
    assert(program_size < 0x7FFC);

    memcpy(bin_out, program, program_size);

    bin_out[0x7FFC] = 0x00;
    bin_out[0x7FFD] = 0x80;

    outfile = fopen(FILENAME, "wb");

    if(outfile == NULL) 
    {
        fprintf(stderr, "cannot open outfile");

        return -1;
    }

    fwrite(bin_out, sizeof(char), SIZE, outfile);

    fclose(outfile);

    return 0;
}