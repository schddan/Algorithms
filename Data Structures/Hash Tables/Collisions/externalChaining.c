//This deals with collision using external chaining, meaning that the elements in the array are the first element of a linked list with the colided elements

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct person{
    char name[MAX_NAME];
    int age;
    struct person * next;
    
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
    p->next = hash_table[index];
    hash_table[index] = p;
    return true;
}

person *hash_table_lookup(char *name){
    int index = hash(name);
    person *tmp = hash_table[index];
    while (tmp != NULL && strcmp(tmp->name, name) != 0){
        tmp = tmp -> next;
    }
    return tmp;
}

person *hash_table_delete(char *name){
    int index = hash(name);
    person *tmp = hash_table[index];
    person *prev = NULL;
    while (tmp != NULL && strcmp(tmp->name, name) != 0){
        prev = tmp;
        tmp = tmp -> next;
    }
    if(tmp == NULL) return NULL;
    if(prev == NULL) {
        hash_table[index] = tmp->next;
    } else {
        prev->next = tmp->next;
    }
    return tmp;
}

void print_table(){
    printf("START\n");
    for(int i = 0; i < TABLE_SIZE; i++){
        if(hash_table[i] == NULL){
            printf("%i -> ---\n", i);
        } else{
            printf("%i -> ", i);
            person *tmp = hash_table[i];
            while(tmp != NULL){
                printf("%s - ", tmp->name);
                tmp = tmp -> next;
            }
            printf("\n");
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

    print_table();

    return 0;
}

