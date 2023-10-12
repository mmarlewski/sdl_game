#include "../inc/list.h"

List* new_list(void(*destroy)(void* data))
{
	List* list = malloc(sizeof(*list));

	list->size = 0;
	list->head = 0;
	list->tail = 0;
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
    ListElem* new_element = malloc(sizeof(*new_element));
    new_element->data = data;

    if(list->size == 0)
    {
        new_element->next = 0;
        new_element->prev = 0;
        list->head = new_element;
        list->tail = new_element;
    }
    else if(element == 0)
    {
        list->head->prev = new_element;
        new_element->next = list->head;
        new_element->prev = 0;
        list->head = new_element;
    }
    else
    {
        new_element->next = element->next;
        new_element->prev = element;
        if(element->next == 0)
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
    ListElem* new_element = malloc(sizeof(*new_element));
    new_element->data = data;

    if(list->size == 0)
    {
        new_element->next = 0;
        new_element->prev = 0;
        list->head = new_element;
        list->tail = new_element;
    }
    else if(element == 0)
    {
        list->tail->next = new_element;
        new_element->next = 0;
        new_element->prev = list->tail;
        list->tail = new_element;
    }
    else
    {
        new_element->next = element;
        new_element->prev = element->prev;
        if(element->prev == 0)
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

		if(list->head == 0)
		{
			list->tail = 0;
		}
		else
		{
			element->next->prev = 0;
		}
	}
	else
	{
		element->prev->next = element->next;

		if(element->next == 0)
		{
			list->tail = element->prev;
		}
		else
		{
			element->next->prev = element->prev;
		}
	}

    if(destroy_data && list->destroy != 0)
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
    ListElem* curr_element = element->next;

    if(curr_element != 0)
    {
        element->next = 0;
        list->tail = element;

        while(curr_element != 0)
        {
            ListElem* next_element = curr_element->next;
            if(destroy_data && list->destroy != 0)
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

	while(curr_element != 0)
    {
        ListElem* next_element = curr_element->next;
        if(destroy_data && list->destroy != 0)
        {
            list->destroy(curr_element->data);
        }
        free(curr_element);
        curr_element = next_element;
    }
    
    list->size = 0;
    list->head = 0;
    list->tail = 0;
}

void print_list(List* list)
{
    printf("printing list: %i of size: %i \n", list, list->size);

    for(ListElem* element = list->head; element != 0; element = element->next)
    {
        printf("data: %i \n", element->data);
    }
}

