typedef struct WriteModel {
    int hits;
    int misses;
    int total_requests;
    float error_rate;
    int page_count;
    int memory_length;
    Page** pages;
} WriteModel;
