void write_file(
    int rowCount,
    int colCount,
    Page pages[rowCount][colCount],
    int hits,
    int misses,
    int total_requests,
    float error_rate
) {
    FILE* file;
    char* file_name = "/Users/Lucas/dev/MemoryPageReplacement/MemoryPageReplacement/saida.txt";
    
    file = fopen(file_name, "w");
    
    int memory_progress[rowCount][colCount - 1];
    int transposed_memory_progress[colCount - 1][rowCount];

    clear_matrix(rowCount, colCount - 1, memory_progress);
    
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            Page current_element = pages[i][j];
            
            if (current_element.hit) {
                for (int k = 0; k < colCount; k++) {
                    memory_progress[i][k] = -1;
                }
            }
            
            if (current_element.end) {
                break;
            }
            
            memory_progress[i][j] = current_element.value;
        }
    }
    
    transpose_matrix(rowCount, colCount - 1, memory_progress, transposed_memory_progress);
    
    fputs("EVOLUÇÃO", file);
    fputs("\n", file);
    
    for (int i = 0; i < colCount - 1; i++) {
        for (int j = 0; j < rowCount; j++) {
            int current_value = transposed_memory_progress[i][j];
            
            if (current_value == 0) {
                fputs("  ", file);
                continue;
            }
            if (current_value == -1) {
                fputs("_ ", file);
                continue;
            }
            
            fprintf(file, "%i ", current_value);
        }
        fprintf(file, "\n");
    }
    
    fputs("\n", file);
    fputs("ACERTOS", file);
    fputs("\n", file);
    fprintf(file, "%i", hits);
    
    fputs("\n", file);
    fputs("ERROS", file);
    fputs("\n", file);
    fprintf(file, "%i", misses);
    
    fputs("\n", file);
    fputs("TOTAL REQUISICOES", file);
    fputs("\n", file);
    fprintf(file, "%i", total_requests);
    
    fputs("\n", file);
    fputs("TAXA DE ERRO", file);
    fputs("\n", file);
    fprintf(file, "%.2f", error_rate);
    
    fclose(file);
}
