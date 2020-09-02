#include <stdio.h>

void consume_space() {
    int c;
    c = getchar();
    while(1){
        switch(c){
            case ' ':
            case '\t':
            case '.':
            case ',':
            case ';':
                c = getchar();
                continue;
            default:
                ungetc(c,stdin);
                return;
        }
    }
}

int is_space(int c) {
    switch(c) {
    case ' ':
    case '\t':
    case '.':
    case ',':
    case ';':
        return 1;   
    default:
    return 0;
    }
}

int main() {
    int c;
    int count=0;

    c = getchar();
    if ( is_space ( c ) ){
       consume_space();
    }
    c = getchar();
    while ( c != EOF ){
        if ( is_space(c) ){
            count++;
            consume_space();
        }
        c = getchar();
    }
    printf("%d\n", count);
    return 0;
}