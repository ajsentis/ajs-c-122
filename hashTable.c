#include <stdio.h>
#include <string.h>

/* Simple Hash Table

1) Print table
2) Add names to table
3) remove names from table
4) Chain collisions

*/

#define LONGEST_NAME 128
#define TABLE_SIZE 10

typedef struct person{
  char name[LONGEST_NAME];
  int age;
  struct person* next;
}person;


unsigned int hash(char *name){
  int i = 0;
  unsigned int hash_value = 0;
  while (name[i] != '\0'){
    hash_value = (hash_value + name[i]) * 31;
    i++;
  }
  return (hash_value % TABLE_SIZE);
}

void init_hash_table(person *table[]){
  int i = 0;
  while (i<TABLE_SIZE){
    table[i] = NULL;
    i++;    
  }
}

void print_table(person *table[]){
  int i = 0;
  printf("Hash\t Name\n");
  person* current;   
  while (i<TABLE_SIZE){
    if (table[i] == NULL){
      printf("%d\t ---",i);
    } else {
      current = table[i];
      printf("%d\t %s",i,current->name);
      current = current->next;
      while(current != NULL){
        printf("->%s",current->name);
        current = current->next;
       }
    }
    printf("\n");
    i++;
  }
}

int add_entry(person *table[], person *new){
  //return 0 if failed to insert, return 1 on success.
  if (new == NULL) return 0;//bail out on empty pointer.
  
  unsigned int index = hash(new->name);
  printf("%d, %s\n",index, new->name);
  new->next = table[index];
  table[index] = new;
  return 1;
}

person* find_entry(person *table[], char *name){
  //return 0 if name is NULL
  if (name == NULL) return NULL;
  unsigned int index = hash(name);
  person *current = table[index];
  while ((current != NULL) && (strcmp(current->name,name) != 0)){
    current = current->next;
  }
  return current;
}

int delete_entry(person *table[], char *name){
  //first we must find the entry to delete it!
  //we also must keep track of the previous LL node.
  
  //return 0 if name is NULL
  if (name == NULL) return 0;
  unsigned int index = hash(name);
  person *current = table[index];
  person *prev = NULL;
  while ((current != NULL) && (strcmp(current->name,name) != 0)){
    prev = current;
    current = current->next;
  }
  if (current == NULL) return 0;
  if (prev == NULL){
    //item is the front of the list
    table[index] = current->next;
  } else {
    //item is in the middle
    prev->next = current->next;
  }
  return 1;
}

int main() {
  person* hash_table[TABLE_SIZE];
  init_hash_table(hash_table);
  //print_table(hash_table);
  int i = 0;
  int age = 0;
  char name[LONGEST_NAME];  
  person lisa = {.name = "Lisa", .age = 44};
  person julia = {.name = "Julia", .age = 12};
  person thomas = {.name = "Thomas", .age = 22}; 
  person fabian = {.name = "Fabian", .age = 128}; 
  person aaron = {.name = "Aaron", .age = 99};    
  person jordan = {.name = "Jordan", .age = 44};
  person alpha = {.name = "Alpha", .age = 135};
  person caliope = {.name = "caliope", .age = 99}; 
  person margeret= {.name = "Margeret", .age = 983}; 
  person teresa = {.name = "Teresa", .age = 30};  
  
  add_entry(hash_table, &lisa);
  add_entry(hash_table, &julia);
  add_entry(hash_table, &thomas);
  add_entry(hash_table, &fabian);
  add_entry(hash_table, &aaron);
  add_entry(hash_table, &jordan);
  add_entry(hash_table, &alpha);
  add_entry(hash_table, &caliope);
  add_entry(hash_table, &margeret);
  add_entry(hash_table, &teresa);
  // while (i<4){
  //   fgets(name,LONGEST_NAME, stdin);
  //   name[strcspn(name, "\n")] = 0;
  //   printf("%s\n",name);
  //   strcpy(Temp.name, name);
  //   add_entry(hash_table, &Temp);
  //   print_table(hash_table);
  //   i++;
  // }
  print_table(hash_table);

  printf("Finding the details for Aaron!\n");
  person *record = find_entry(hash_table, "Aaron");
  printf("Name: %s,\tAge: %d\n",record->name, record->age);

  printf("Deleting Aaron from Table \n");
  delete_entry(hash_table, "Aaron");
  print_table(hash_table);
  
}      

