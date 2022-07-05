#include <stdio.h>
unsigned long long int strlen(char *);
unsigned long long int strlen(char *str){
    unsigned long long int size;
    for(size=0;*(str+size)!='\0';size++);
    return size;
}
int main(int argc, char **argv){
    if(argc!=3){
        puts("Invalid arguments. Format is [executable] [key] [data].");
        return 1;
    }
    unsigned long long int _keylen=strlen(argv[1])+1;
    unsigned long long int _datalen=strlen(argv[2])+1;
    if(_keylen>_datalen){
        puts("Sorry. Key length can't be bigger than data length.");
        return 1;
    }
    char new_data[_datalen];
    register unsigned long long int key_counter=0;
    register unsigned long long int data_counter=0;
    while(data_counter<_datalen){
        if(key_counter==_keylen-1){
            key_counter=0;
        }
        int int_ver_k_char=(int)*(argv[1]+key_counter);
        int int_ver_d_char=(int)*(argv[2]+data_counter);
        new_data[data_counter]=int_ver_d_char|int_ver_k_char;
        data_counter++;
        key_counter++;
    }
    *(new_data+(data_counter+1))='\0';
    data_counter=0;
    while(*(new_data+data_counter)!='\0'){
        putchar(new_data[data_counter]);
        data_counter++;
    }
    puts("\n");
    return 0;
}
