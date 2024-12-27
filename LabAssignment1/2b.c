#include <stdio.h>
#include <string.h>
int main() {
    FILE *input_pointer, *output_pointer;
    char sentence[200];
    char *result_s[150];
    char *word;
    int i = 0;

    input_pointer = fopen("2b_input.txt", "r");
    output_pointer = fopen("2b_output.txt", "w");


    fgets(sentence, sizeof(sentence), input_pointer);

    word = strtok(sentence, " ");
    while (word != NULL) {
        result_s[i] = word;
        word = strtok(NULL, " ");
        i++;
    }

    for (int j = 0; j < i; j++) {
        fprintf(output_pointer, "%s ", result_s[j]);
    }

    fclose(input_pointer);
    fclose(output_pointer);

    return 0;
}