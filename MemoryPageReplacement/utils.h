#define MAX_LINE_SIZE 128

char* normalize_string(char string[]) {
    char* normalized_string = malloc(MAX_LINE_SIZE * sizeof(char*));;
    
    for (int i = 0; i < strlen(string) - 1; i++) {
        char current_char = string[i];
        
        if (
            current_char != ',' &&
            current_char != ' ' &&
            current_char != '\n' &&
            current_char != '\0'
        ) {
            strncat(normalized_string, &current_char, 1);
        }
    }
    
    return normalized_string;
}

int count_numbers(char string[]) {
    char* normalized_string = normalize_string(string);

    return (int)strlen(normalized_string);
}

int* string_to_numbers_array(char string[]) {
    char* normalized_string = normalize_string(string);
    int* numbers_array = calloc(count_numbers(string), sizeof(int));
    
    for (int i = 0; i < strlen(normalized_string); i++) {
        numbers_array[i] = normalized_string[i] - '0';
    }
    
    return numbers_array;
}

Page* string_to_page_array(char string[]) {
    int* numbers = string_to_numbers_array(string);
    int numbers_count = count_numbers(string);
    Page* pages = calloc(128, sizeof(Page*));
    
    for (int i = 0; i < numbers_count; i++) {
        Page page = {
            .arrival_position = i,
            .value = numbers[i],
        };
        
        pages[i] = page;
    }
    
    return pages;
}

void clear_matrix(int rowCount, int colCount, int matrix[rowCount][colCount]) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            matrix[i][j] = 0;
        }
    }
}

void transpose_matrix(
        int rowCount,
        int colCount,
        int original_matrix[rowCount][colCount],
        int end_matrix[colCount][rowCount]
) {
    clear_matrix(colCount, rowCount, end_matrix);
    
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            end_matrix[j][i] = original_matrix[i][j];
        }
    }
}
