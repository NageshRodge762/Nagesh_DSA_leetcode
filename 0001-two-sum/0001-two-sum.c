/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 struct HashNode {
    int key;
    int value;
    struct HashNode* next;
};
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    
    // 1. Initialize the Hash Table
    int capacity = numsSize * 2; // Allocate extra buckets to minimize collisions
    struct HashNode** table = (struct HashNode**)calloc(capacity, sizeof(struct HashNode*));
    
    // Allocate the output array
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 0;

    // 2. Iterate through the array
    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        
        // Compute hash index for the complement (handle negatives safely)
        long long abs_comp = complement;
        if (abs_comp < 0) abs_comp = -abs_comp;
        int comp_bucket = abs_comp % capacity;
        
        // Search for the complement in the hash table
        struct HashNode* curr = table[comp_bucket];
        while (curr != NULL) {
            if (curr->key == complement) {
                // Found the pair! Fill the results
                result[0] = curr->value;
                result[1] = i;
                *returnSize = 2;
                
                // Free the hash table memory before returning
                for (int j = 0; j < capacity; j++) {
                    struct HashNode* node = table[j];
                    while (node != NULL) {
                        struct HashNode* temp = node;
                        node = node->next;
                        free(temp);
                    }
                }
                free(table);
                return result;
            }
            curr = curr->next;
        }
        
        // If complement not found, insert the current number into the hash table
        long long abs_num = nums[i];
        if (abs_num < 0) abs_num = -abs_num;
        int num_bucket = abs_num % capacity;
        
        struct HashNode* newNode = (struct HashNode*)malloc(sizeof(struct HashNode));
        newNode->key = nums[i];
        newNode->value = i;
        newNode->next = table[num_bucket]; // Insert at the front of the chain
        table[num_bucket] = newNode;
    }

    
    free(table);
    return NULL;
    
}