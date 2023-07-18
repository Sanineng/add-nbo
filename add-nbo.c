#include <stdio.h>  
#include <stdlib.h>
#include <stdint.h>
uint32_t read_file(char* file_name){
    uint32_t result;

    FILE* fs;
    fs = fopen(file_name, "rb");
    fread(&result, sizeof(uint32_t), 1, fs);
    
    return result;
}

int main(int argc, char * argv[])
{
    uint32_t result = ntohl(read_file(argv[2])) + ntohl(read_file(argv[1]));

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", ntohl(read_file(argv[1])),ntohl(read_file(argv[1])),ntohl(read_file(argv[2])),ntohl(read_file(argv[2])),result,result);
}