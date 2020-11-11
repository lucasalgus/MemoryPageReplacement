#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <strings.h>

#include "Structs/page.h"
#include "Structs/read_model.h"
#include "Structs/write_model.h"

#include "Utils/utils.h"
#include "Utils/reader.h"
#include "Utils/writer.h"

#include "Algorithms/fifo.h"
#include "Algorithms/algorithms.h"

int main(int argc, const char * argv[]) {
    char file_path[128] = "/Users/Lucas/dev/MemoryPageReplacement/MemoryPageReplacement";
    int menu = 0;
    
//    printf("Digite o caminho do diretório do arquivo de entrada: \n");
//    scanf("%s", file_path);

    ReadModel data = read_file(file_path);
    
    WriteModel wm = algorithm(data, menu);

//    WriteModel wm = {
//        .rowCount = 6,
//        .colCount = 6,
//        .hits = 6,
//        .misses = 5,
//        .total_requests = 6,
//        .error_rate = 0.83,
//    };
    
    write_file(wm, file_path);
    
    return 0;
}
