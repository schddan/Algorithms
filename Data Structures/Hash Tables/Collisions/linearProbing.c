//This deals with collision using liner probing, finding the first free index if the designated index is in use

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10
#define DELETED_NODE (person*)(0xFFFFFFFFFFFFFFFFF) //This is useful because if we can differentiate NULL from DELETED_NODES, and if we hit a NULL in lookup function, there's no reason to continue looking
//After DELETED_NODES, it's possible to have the value, but after NULL nodes, it's impossible considering linear probing

typedef struct person{
    char name[MAX_NAME];
    int age;
} person;

person * hash_table[TABLE_SIZE];

//The hash function
unsigned int hash(char *name){ 
    int length = strnlen(name, MAX_NAME);
    unsigned int hash_value = 0;
    for(int i = 0; i < length; i++){
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;

    }

    return hash_value;
}

void init_hash_table(){
    for(int i = 0; i < TABLE_SIZE; i++){
        hash_table[i] = NULL;
    }
}

bool hash_table_insert(person *p){
    if(p == NULL) return false;
    int index = hash(p->name);
    for(int i = 0; i < TABLE_SIZE; i++){
        int try = (i + index) % TABLE_SIZE; //The module is important because if we hit the highest index (in this example 10), 10 % 10 == 0, so we can put the value in a previous index
        //If index == 1 and i == 10, 11 % 10 would be 1, looping all the hash again. That's why TABLE_SIZE must be bigger than i
        if (hash_table[try] == NULL || hash_table[try] == DELETED_NODE){
            
            hash_table[try] = p;
            return true;
        }
    }
    return false;
}

person *hash_table_lookup(char *name){
    int index = hash(name);
    for(int i = 0; i < TABLE_SIZE; i ++){
        int try = (index + 1) % TABLE_SIZE;
        if(hash_table[try] == NULL){
            return false;
        }
        if(hash_table[try] == DELETED_NODE){
            continue;
        }
        if(strcmp(hash_table[try] -> name, name) == 0){ 
            return hash_table[try]; 
        } 
    }
    return NULL;
}

person *hash_table_delete(char *name){
    int index = hash(name);
    for(int i = 0; i < TABLE_SIZE; i ++){
        int try = (index + 1) % TABLE_SIZE;
        if(hash_table[try] == NULL){
            return NULL;
        }
        if(hash_table[try] == DELETED_NODE){
            continue;
        }
        if(strcmp(hash_table[try] -> name, name) == 0){ 
            person *tmp = hash_table[try];
            hash_table[try] = DELETED_NODE;
            return tmp; 
        } 
    }
    return NULL;
}

void print_table(){
    printf("START\n");
    for(int i = 0; i < TABLE_SIZE; i++){
        if(hash_table[i] == NULL){
            printf("%i -> ---\n", i);
        } else if(hash_table[i] == DELETED_NODE){
            printf("%i -> --- (deleted)\n", i);
        } else{
            printf("%i -> %s\n", i, hash_table[i] -> name);
        }
    }
    printf("END\n");
}

int main(){
    

    person jacob = {.name="Jacob", .age = 25};
    person kate = {.name="Kate", .age = 18};
    person mpho = {.name="Mpho", .age = 14};
    person sarah = {.name="Sarah", .age = 14};
    person edna = {.name="Edna", .age = 14};
    person maren = {.name="Maren", .age = 14};
    person eliza = {.name="Eliza", .age = 14};
    person robert = {.name="Robert", .age = 14};
    person jane = {.name="Jane", .age = 14};
    person jessica = {.name="Jessica", .age = 14};

    hash_table_insert(&jacob);
    hash_table_insert(&kate);
    hash_table_insert(&mpho);
    hash_table_insert(&sarah);
    hash_table_insert(&edna);
    hash_table_insert(&maren);
    hash_table_insert(&eliza);
    hash_table_insert(&robert);
    hash_table_insert(&jane);
    hash_table_insert(&jessica);

    hash_table_delete("Robert");

    print_table();

    return 0;
}

