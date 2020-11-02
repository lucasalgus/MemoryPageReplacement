#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <strings.h>

#include "Structs/page.h"
#include "Structs/read_model.h"
#include "Structs/write_model.h"

#include "Algorithms/algorithms.h"

#include "utils.h"
#include "reader.h"
#include "writer.h"

int main(int argc, const char * argv[]) {
    char file_path[128];
    
    printf("Digite o caminho do diretório do arquivo de entrada: \n");
    scanf("%s", file_path);
    
    ReadModel data = read_file(file_path);
    printf("%i\n", data.memory_length);
    
    Page pages[6][6] = {
        {
            { .arrival_position = 0, .value = 2 },
            { .end = true },
        },
        {
            { .arrival_position = 0, .value = 2 },
            { .arrival_position = 1, .value = 3 },
            { .end = true },
        },
        {
            { .arrival_position = 0, .value = 2 },
            { .arrival_position = 1, .value = 3 },
            { .arrival_position = 2, .value = 4 },
            { .end = true },
        },
        {
            { .arrival_position = 0, .value = 2 },
            { .arrival_position = 1, .value = 3 },
            { .arrival_position = 2, .value = 4 },
            { .arrival_position = 3, .value = 6 },
            { .end = true },
        },
        {
            { .end = true, .hit = true },
        },
        {
            { .arrival_position = 0, .value = 2 },
            { .arrival_position = 1, .value = 3 },
            { .arrival_position = 2, .value = 4 },
            { .arrival_position = 3, .value = 6 },
            { .arrival_position = 4, .value = 7 },
            { .end = true },
        },
    };
    
    WriteModel wm = {
        .rowCount = 6,
        .colCount = 6,
        .hits = 6,
        .misses = 5,
        .total_requests = 6,
        .error_rate = 0.83,
    };
    
    write_file(wm, pages);
    
    return 0;
}
