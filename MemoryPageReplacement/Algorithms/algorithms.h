WriteModel algorithm(ReadModel data, int menu) {
    Page** page_matrix = initialize_page_matrix(data.page_count, data.memory_length);

    WriteModel write_data = {
        .page_count = data.page_count,
        .memory_length = data.memory_length,
        .hits = 0,
        .misses = 0,
        .total_requests = 0,
        .error_rate = 0,
        .pages = page_matrix
    };

    for(int i = 0; i < data.page_count; i++) {
        Page current_page = data.pages[i];
        Page* current_state = page_matrix[i];
        
        copy_previous_state(page_matrix, data.memory_length, i);
        
        write_data.total_requests++;
        
        bool found = find_page_by_value(current_state, data.memory_length, current_page.value);
        if (found) {
            write_data.hits++;
            page_matrix[i] = initialize_hit_state(data.memory_length);
            continue;
        }
        
        write_data.misses++;
        
        bool inserted = insert_page_into_state(current_state, data.memory_length, current_page);
        if (!inserted) {
            if (menu == 0 || i == data.page_count - 1) {
                fifo(page_matrix[i], current_page, data.memory_length);
            } else {
                opt(data.memory_length, page_matrix[i], data.pages, i, data.page_count);
            }
        }
    }
    
    write_data.error_rate = (float)write_data.misses / (float)write_data.total_requests;
    
    return write_data;
}
