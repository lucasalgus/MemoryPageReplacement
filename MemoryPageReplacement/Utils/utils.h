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
    int row_count,
    int col_count,
    int original_matrix[row_count][col_count],
    int end_matrix[col_count][row_count]
) {
    clear_matrix(col_count, row_count, end_matrix);
    
    for (int i = 0; i < row_count; i++) {
        for (int j = 0; j < col_count; j++) {
            end_matrix[j][i] = original_matrix[i][j];
        }
    }
}

Page* initialize_page_array(int page_count) {
    Page* page_array = calloc(page_count, sizeof(Page));

    for (int i = 0; i < page_count; i++) {
        Page page = {
            .value = 0,
            .end = false,
            .hit = false,
        };
        
        page_array[i] = page;
    }
    
    return page_array;
}

Page** initialize_page_matrix(int page_count, int memory_length) {
    Page** page_matrix = calloc(page_count, sizeof(Page*) * memory_length);
    
    for(int i = 0; i < page_count; i++) {
        page_matrix[i] = calloc(memory_length, sizeof(Page));

        for (int j = 0; j < memory_length; j++) {
            Page page = {
                .value = 0,
                .end = false,
                .hit = false,
            };
            
            page_matrix[i][j] = page;
        }
        
        page_matrix[i][memory_length].end = true;
    }
    
    return page_matrix;
}

bool insert_page_into_state(Page* state, int memory_length, Page page) {
    bool inserted = false;
    
    for (int i = 0; i < memory_length; i++) {
        if (state[i].value == 0) {
            state[i] = page;
            state[i + 1].end = true;
            inserted = true;
            break;
        }
    }
    
    return inserted;
}

bool find_page_by_value(Page* array, int length, int value) {
    bool found = false;
    
    for (int i = 0; i < length; i++) {
        Page current_page = array[i];
        
        if (current_page.value == value) {
            found = true;
        }
    }
    
    return found;
}

Page* initialize_hit_state(int memory_length) {
    Page* hit_state = calloc(memory_length, sizeof(Page));
    Page hit_page = {
        .hit = true
    };
    
    for (int i = 0; i < memory_length; i++) {
        hit_state[i] = hit_page;
    }
    
    return hit_state;
}

void copy_previous_state(Page** matrix, int memory_length, int index) {
    if (index == 0) {
        return;
    }
    Page* previous_state = matrix[0];
    
    for (int i = 0; i < index; i++) {
        if (!matrix[i][0].hit) {
            previous_state = matrix[i];
        }
    }
    
    for (int i = 0; i < memory_length; i++) {
        matrix[index][i] = previous_state[i];
    }
}
