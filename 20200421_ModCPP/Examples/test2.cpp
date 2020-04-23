template<typename T>
void count(T * b, T * e, T v){}

template<typename T, typename Func>
void count_if(T * b, T * e, Func f){}

int *e, *b;
int x;
count_if(b, e, x);