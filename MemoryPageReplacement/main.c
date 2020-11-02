#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <strings.h>

#include "Structs/page.h"
#include "Structs/read_model.h"

#include "utils.h"
#include "reader.h"
#include "writer.h"

int main(int argc, const char * argv[]) {
//    ReadModel data = read_file();
    
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
    
    write_file(6, 6, pages, 6, 5, 6, 0.83);
    
    return 0;
}
