#ifndef LIST_H
#define LIST_H

#include "../inc/common.h"

typedef struct _ListElem ListElem;

struct _ListElem
{
    ListElem* prev;
    ListElem* next;
    void* data;
};

typedef struct
{
    int size;
    ListElem* head;
    ListElem* tail;
    void(*destroy)(void*);

} List;

List* new_list(void(*destroy)(void* data));
void destroy_list(List* list);

void add_new_list_element_after_element(List* list, ListElem* element, void* data);
void add_new_list_element_before_element(List* list, ListElem* element, void* data);
void add_new_list_element_to_list_end(List* list, void* data);

void remove_list_element(List* list, ListElem* element, int destroy_data);
void remove_list_element_of_data(List* list, void* data, int destroy_data);
void remove_all_list_elements_after_element(List* list, ListElem* element, int destroy_data);
void remove_all_list_elements(List* list, int destroy_data);

int is_element_in_list(List* list, ListElem* element);
int is_data_in_list(List* list, void* data);

void reverse_list(List* list);

ListElem* get_nth_list_element(List* list, int n);

void print_list(List* list);

#endif
