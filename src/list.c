#include "../inc/list.h"

List* new_list(void(*destroy)(void* data))
{
    List* list = calloc(sizeof(*list), 1);

    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
    list->destroy = destroy;

    return list;
}

void destroy_list(List* list)
{
    free(list);
}

// if element is 0: add after list head
void add_new_list_element_after_element(List* list, ListElem* element, void* data)
{
    ListElem* new_element = calloc(sizeof(*new_element), 1);
    new_element->data = data;

    if(list->size == 0)
    {
        new_element->next = NULL;
        new_element->prev = NULL;
        list->head = new_element;
        list->tail = new_element;
    }
    else if(element == NULL)
    {
        list->head->prev = new_element;
        new_element->next = list->head;
        new_element->prev = NULL;
        list->head = new_element;
    }
    else
    {
        new_element->next = element->next;
        new_element->prev = element;
        if(element->next == NULL)
        {
            list->tail = new_element;
        }
        else
        {
            element->next->prev = new_element;
        }
        element->next = new_element;
    }

    list->size++;
}

// if element is 0: add before list tail
void add_new_list_element_before_element(List* list, ListElem* element, void* data)
{
    ListElem* new_element = calloc(sizeof(*new_element), 1);
    new_element->data = data;

    if(list->size == 0)
    {
        new_element->next = NULL;
        new_element->prev = NULL;
        list->head = new_element;
        list->tail = new_element;
    }
    else if(element == NULL)
    {
        list->tail->next = new_element;
        new_element->next = NULL;
        new_element->prev = list->tail;
        list->tail = new_element;
    }
    else
    {
        new_element->next = element;
        new_element->prev = element->prev;
        if(element->prev == NULL)
        {
            list->head = new_element;
        }
        else
        {
            element->prev->next = new_element;
        }
        element->prev = new_element;
    }

    list->size++;
}

void add_new_list_element_to_list_end(List* list, void* data)
{
    add_new_list_element_after_element(list, list->tail, data);
}

void remove_list_element(List* list, ListElem* element, int destroy_data)
{
    if(element == list->head)
    {
        list->head = element->next;

        if(list->head == NULL)
        {
            list->tail = NULL;
        }
        else
        {
            element->next->prev = NULL;
        }
    }
    else
    {
        element->prev->next = element->next;

        if(element->next == NULL)
        {
            list->tail = element->prev;
        }
        else
        {
            element->next->prev = element->prev;
        }
    }

    if(destroy_data && list->destroy != NULL)
    {
        list->destroy(element->data);
    }

    free(element);

    list->size--;
}

void remove_list_element_of_data(List* list, void* data, int destroy_data)
{
    for(ListElem* curr_elem = list->head; curr_elem; curr_elem = curr_elem->next)
    {
        if(curr_elem->data == data)
        {
            remove_list_element(list, curr_elem, destroy_data);
            break;
        }
    }
}

void remove_all_list_elements_after_element(List* list, ListElem* element, int destroy_data)
{
    if(element == NULL) return;

    ListElem* curr_element = element->next;

    if(curr_element != NULL)
    {
        element->next = NULL;
        list->tail = element;

        while(curr_element != NULL)
        {
            ListElem* next_element = curr_element->next;
            if(destroy_data && list->destroy != NULL)
            {
                list->destroy(curr_element->data);
            }
            free(curr_element);
            curr_element = next_element;
            list->size--;
        }
    }
}

void remove_all_list_elements(List* list, int destroy_data)
{
    ListElem* curr_element = list->head;

    while(curr_element != NULL)
    {
        ListElem* next_element = curr_element->next;
        if(destroy_data && list->destroy != NULL)
        {
            list->destroy(curr_element->data);
        }
        free(curr_element);
        curr_element = next_element;
    }

    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
}

int is_element_in_list(List* list, ListElem* element)
{
    for(ListElem* elem = list->head; elem != NULL; elem = elem->next)
    {
        if(elem == element) return 1;
    }
    return 0;
}

int is_data_in_list(List* list, void* data)
{
    for(ListElem* elem = list->head; elem != NULL; elem = elem->next)
    {
        if(elem->data == data) return 1;
    }
    return 0;
}

void reverse_list(List* list)
{
    if(list->size <= 1) return;

    ListElem* prev_elem = NULL;
    ListElem* curr_elem = list->head;
    ListElem* next_elem = (curr_elem) ? (curr_elem->next) : (NULL);

    while(curr_elem != NULL)
    {
        curr_elem->prev = next_elem;
        curr_elem->next = prev_elem;

        prev_elem = curr_elem;
        curr_elem = next_elem;
        next_elem = (curr_elem) ? (curr_elem->next) : (NULL);
    }

    ListElem* temp = list->head;
    list->head = list->tail;
    list->tail = temp;
}

ListElem* get_nth_list_element(List* list, int n)
{
    ListElem* list_elem = list->head;
    int count = 0;

    while(list_elem != NULL)
    {
        if(count == n)
        {
            return list_elem;
        }

        list_elem = list_elem->next;
        count++;
    }

    return 0;
}

ListElem* get_list_element_of_data(List* list, void* data)
{
    for(ListElem* elem = list->head; elem != NULL; elem = elem->next)
    {
        if(elem->data == data) return elem;
    }
    return 0;
}

void print_list(List* list)
{
    printf("printing list: %p of size: %i \n", list, list->size);

    for(ListElem* element = list->head; element != NULL; element = element->next)
    {
        printf("data: %p \n", element->data);
    }
}

