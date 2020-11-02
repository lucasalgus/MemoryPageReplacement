typedef struct ReadModel {
    bool error;
    int memory_length;
    int page_count;
    Page* pages;
} ReadModel;
