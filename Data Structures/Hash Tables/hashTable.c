//This is about a simple implementation of hash tables, without dealing with collisions (which occur in the example)

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct {
    char name[MAX_NAME];
    int age;
} person;

person * hash_table[TABLE_SIZE]; //If the array stores just a pointer for the elements, it needs less storage than allocating every element inside itself

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
    if(hash_table[index] != NULL){
        return false;
    }
    hash_table[index] = p;
    return true;
}

person *hash_table_lookup(char *name){
    int index = hash(name);
    if(hash_table[index] != NULL && strcmp(hash_table[index] -> name, name) == 0){ //If the index is not NULL and the names match
        return hash_table[index]; //Return the value in the index, which is a pointer to the element
    } else {
        return NULL;
    }
}

person *hash_table_delete(char *name){
    int index = hash(name);
    if(hash_table[index] != NULL && strcmp(hash_table[index] -> name, name) == 0){ //If the index is not NULL and the names match
        person *tmp = hash_table[index];
        hash_table[index] = NULL;
        return tmp; //It's just really necessary in a heap allocated case, which doesn't happen here
    } else {
        return NULL;
    }
}

void print_table(){
    printf("START\n");
    for(int i = 0; i < TABLE_SIZE; i++){
        if(hash_table[i] == NULL){
            printf("%i -> ---\n", i);
        } else {
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

    hash_table_insert(&jacob);
    hash_table_insert(&kate);
    hash_table_insert(&mpho);
    hash_table_insert(&sarah);
    hash_table_insert(&edna);
    hash_table_insert(&maren);
    hash_table_insert(&eliza);
    hash_table_insert(&robert);
    hash_table_insert(&jane);

    print_table();
    return 0;
}

