#ifndef UTIL_H
#define UTIL_H

char get_c(const char* arr, const int size, const int i, const int j); 
char set_c(char* arr, const int size, const int i, const int j, const char symbol); 
int inputStringPrompt(char* buffer, const char* prompt, const char* afterPrompt);

#endif