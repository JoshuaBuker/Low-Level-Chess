char get_c(const char* arr, const int size, const int i, const int j) {
  return *((arr+i*size) + j);
} 

char set_c(char* arr, const int size, const int i, const int j, const char symbol) {
  return *((arr+i*size) + j) = symbol;
} 