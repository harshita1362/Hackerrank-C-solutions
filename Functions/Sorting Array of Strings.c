// Problem
// To sort a given array of strings into lexicographically increasing order or into an order in which the string with the lowest length appears first, a sorting function with a flag indicating the type of comparison strategy can be written. The disadvantage with doing so is having to rewrite the function for every new comparison strategy.

// A better implementation would be to write a sorting function that accepts a pointer to the function that compares each pair of strings. Doing this will mean only passing a pointer to the sorting function with every new comparison strategy.

// Given an array of strings, you need to implement a sorting_sort function which sorts the strings according to a comparison function, i.e, you need to implement the function :

// void string_sort(const char **arr,const int cnt, int (*cmp_func)(const char* a, const char* b)){
    
// }
// The arguments passed to this function are:

// an array of strings : arr
// length of string array: count
// pointer to the string comparison function: cmp_func
// You also need to implement the following four string comparison functions:

//  int lexicographic_sort(char*, char*) to sort the strings in lexicographically non-decreasing order.
//  int lexicographic_sort_reverse(char*, char*) to sort the strings in lexicographically non-increasing order.
//  int sort_by_number_of_distinct_characters(char*, char*) to sort the strings in non-decreasing order of the number of distinct characters present in them. If two strings have the same number of distinct characters present in them, then the lexicographically smaller string should appear first.
//  int sort_by_length(char*, char*) to sort the strings in non-decreasing order of their lengths. If two strings have the same length, then the lexicographically smaller string should appear first.
// Input Format
// You just need to complete the function string\_sort and implement the four string comparison functions.

// Constraints
//  1 <= No. of Strings <= 50 
//  1 <= Total Length of all the strings <= 2500 
// You have to write your own sorting function and you cannot use the inbuilt qsort function
// The strings consists of lower-case English Alphabets only.
// Output Format
// The locked code-stub will check the logic of your code. The output consists of the strings sorted according to the four comparsion functions in the order mentioned in the problem statement.

// Sample Input 0

// 4
// wkue
// qoi
// sbv
// fekls
// Sample Output 0

// fekls
// qoi
// sbv
// wkue

// wkue
// sbv
// qoi
// fekls

// qoi
// sbv
// wkue
// fekls

// qoi
// sbv
// wkue
// fekls

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lexicographic_sort(const char* a, const char* b){
    return strcmp(a, b);
}

int lexicographic_sort_reverse(const char* a, const char* b){
    return strcmp(b, a);
    
}
int characters_count(const char *s){
    int n = 0;
    int count[128] = {0};
    if (NULL == s){
        return -1;
    }
    while(*s != '\0'){
        if (!count[*s]){
            count[*s]++;
            n++;
        }
        s++;
    }
    return n;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b){
    int con = characters_count(a) - characters_count(b);
    return (con ? con : lexicographic_sort(a, b));
}

int sort_by_length(const char* a, const char* b) {
    int len = strlen(a) - strlen(b);
    return (len ? len : lexicographic_sort(a, b));
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    int con = 0;
    while(!con){
        con = 1;
        for(int i = 0; i < len - 1; i++){
            if(cmp_func(arr[i], arr[i + 1]) > 0) {
                char *temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                con = 0;
            }
        }
    }
}
// 2nd method
// int sort_by_number_of_distinct_characters(const char* a, const char* b) {
//     int count_a = 0, count_b = 0;
//     int freq_a[26] = {0}, freq_b[26] = {0};

//     for (int i = 0; i < strlen(a); i++) {
//         if (freq_a[a[i] - 'a'] == 0) {
//             count_a++;
//             freq_a[a[i] - 'a'] = 1;
//         }
//     }

//     for (int i = 0; i < strlen(b); i++) {
//         if (freq_b[b[i] - 'a'] == 0) {
//             count_b++;
//             freq_b[b[i] - 'a'] = 1;
//         }
//     }

//     if (count_a == count_b) {
//         return strcmp(a, b);
//     } else {
//         return (count_a - count_b);
//     }
// }

// int sort_by_length(const char* a, const char* b) {
//     int len_a = strlen(a);
//     int len_b = strlen(b);

//     if (len_a == len_b) {
//         return strcmp(a, b);
//     } else {
//         return (len_a - len_b);
//     }
// }
// void string_sort(char** arr, const int len, int (*cmp_func)(const char* a, const char* b)) {
//     for (int i = 0; i < len; i++) {
//         for (int j = i + 1; j < len; j++) {
//             if (cmp_func(arr[i], arr[j]) > 0) {
//                 char* temp = arr[i];
//                 arr[i] = arr[j];
//                 arr[j] = temp;
//             }
//         }
//     }
// }

int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
    arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}