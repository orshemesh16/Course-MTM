#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define INDEX_NOT_FOUND -1

char* RemoveFirstAppearance(char* string, char* word);
bool IsValidInput(char* string, char* word);
int FindWordFirstAppearance(char* string, char* word, int string_length, int word_length);

int main() {
    char* string = "averyverylongstring";
    char* word = "very";
    char* new_word = RemoveFirstAppearance(string, word);
    if (!new_word) {
        printf("RemoveFirstAppearance has failed\n");
        return 0;
    }
    printf("%s", new_word);
    free(new_word);
    return 0;
}

// Checks if the given inputs are not NULL
bool IsValidInput(char* string, char* word) {
    return (string && word);
}

// Returns word's first appearance in string
int FindWordFirstAppearance(char* string, char* word, int string_length, int word_length){ 
    bool index_found = false;
    int string_index=0, word_first_appearance_index=INDEX_NOT_FOUND;
    
    // Find the index in 'string' where 'word' starts
    while(string_index <= string_length - word_length && !index_found) {
        if (strncmp(string + string_index, word, word_length) == 0) {
            index_found = true;
            word_first_appearance_index = string_index;
        }
        string_index++;
    }
    return word_first_appearance_index;
}

// The function gets a string and a word, and returns the string with the word first appearance removed
char* RemoveFirstAppearance(char* string, char* word) {
    if(!IsValidInput(string, word)) {
        return NULL;
    }
    
    int string_length, word_length, word_first_appearance_index;
    string_length = strlen(string);
    word_length = strlen(word);
    word_first_appearance_index = FindWordFirstAppearance(string, word, string_length, word_length);
    
    if (word_first_appearance_index == INDEX_NOT_FOUND) {
        printf("Couldn't find word in string\n");
        return NULL;
    }

    int new_string_length = string_length - word_length + 1;
    char* new_string = (char *)malloc(new_string_length*sizeof(char));

    if (!new_string) {
        printf("New string allocation has failed\n");
        return NULL;
    }
    memcpy(new_string, string, word_first_appearance_index);
    int second_part_string_length = new_string_length - word_first_appearance_index;
    memcpy(new_string+word_first_appearance_index, string+word_first_appearance_index+word_length, second_part_string_length);
    return new_string;

}