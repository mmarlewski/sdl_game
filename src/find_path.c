#include "../inc/state.h"

typedef struct _Node Node;

struct _Node
{
    Node* parent;
    Vec2i tilemap_pos;
    int g_val;
    int h_val;

};

Node* new_node(Vec2i tilemap_pos)
{
    Node* node = malloc(sizeof(*node));

    node->parent = 0;
    node->tilemap_pos = tilemap_pos;
    node->g_val = 0;
    node->h_val = 0;

    return node;
}

void destroy_node(Node* node)
{
    free(node);
}

int is_node_tilemap_pos_in_list(List* list, Node* node)
{
    Vec2i tilemap_pos = node->tilemap_pos;
    for(ListElem* curr_elem = list->head; curr_elem != 0; curr_elem = curr_elem->next)
    {
        Node* curr_node = (Node*)curr_elem->data;
        Vec2i curr_tilemap_pos = curr_node->tilemap_pos;
        if(curr_tilemap_pos.x == tilemap_pos.x &&
        curr_tilemap_pos.y == tilemap_pos.y) return 1;
    }
    return 0;
}

void find_path(State* state, Vec2i start_tilemap_pos, Vec2i end_tilemap_pos, List* path, int is_floating, int is_flying)
{
    if(!is_tilemap_pos_in_tilemap(start_tilemap_pos) ||
    !is_tilemap_pos_in_tilemap(end_tilemap_pos) ||
    get_object_on_tilemap_pos(state, end_tilemap_pos) != 0) return;

    List* open = new_list((void(*)(void*))destroy_node);
    List* closed = new_list((void(*)(void*))destroy_node);

    add_new_list_element_to_list_end(open, new_node(start_tilemap_pos));

    int count = 0;
    int found = 0;
    Node* curr_node = 0;
    while(open->size > 0)
    {
        count++;
        if(count > 100)
        {
            found = 0;
            break;
        }
        curr_node = (Node*)open->head->data;
        for(ListElem* elem = open->head; elem != 0; elem = elem->next)
        {
            Node* node = (Node*)elem->data;
            if(node->g_val + node->h_val < curr_node->g_val + curr_node->h_val)
            {
                curr_node = node;
            }
        }
        Vec2i curr_tilemap_pos = curr_node->tilemap_pos;

        if(curr_tilemap_pos.x == end_tilemap_pos.x &&
        curr_tilemap_pos.y == end_tilemap_pos.y)
        {
            found = 1;
            break;
        }

        remove_list_element_of_data(open, curr_node, 0);
        add_new_list_element_to_list_end(closed, curr_node);

        List* neighbors = new_list((void(*)(void*))destroy_node);
        Vec2i up_tilemap_pos = vec2i_move_in_dir4_by(curr_tilemap_pos, DIR4__UP, 1);
        add_new_list_element_to_list_end(neighbors, new_node(up_tilemap_pos));
        Vec2i right_tilemap_pos = vec2i_move_in_dir4_by(curr_tilemap_pos, DIR4__RIGHT, 1);
        add_new_list_element_to_list_end(neighbors, new_node(right_tilemap_pos));
        Vec2i down_tilemap_pos = vec2i_move_in_dir4_by(curr_tilemap_pos, DIR4__DOWN, 1);
        add_new_list_element_to_list_end(neighbors, new_node(down_tilemap_pos));
        Vec2i left_tilemap_pos = vec2i_move_in_dir4_by(curr_tilemap_pos, DIR4__LEFT, 1);
        add_new_list_element_to_list_end(neighbors, new_node(left_tilemap_pos));

        for(ListElem* elem = neighbors->head; elem != 0; elem = elem->next)
        {
            Node* node = (Node*)elem->data;
            Vec2i tilemap_pos = node->tilemap_pos;
            int floor = get_floor_on_tilemap_pos(state, tilemap_pos);

            if(!is_node_tilemap_pos_in_list(closed, node) &&
            get_object_on_tilemap_pos(state, tilemap_pos) == 0)
            {
                if((is_flying && is_floor_traversable_for_flying(floor)) ||
                (is_floating && is_floor_traversable_for_floating(floor)) ||
                is_floor_traversable(floor))
                {
                    int x_distance = abs(curr_tilemap_pos.x - tilemap_pos.x);
                    int y_distance = abs(curr_tilemap_pos.y - tilemap_pos.y);
                    int distance = x_distance + y_distance;
                    int is_node_in_open = is_node_tilemap_pos_in_list(open, node);

                    if(curr_node->g_val + distance < node->g_val || !is_node_in_open)
                    {
                        node->g_val = curr_node->g_val + distance;
                        node->h_val = distance;
                        node->parent = curr_node;

                        if (!is_node_in_open)
                        {
                            add_new_list_element_to_list_end(open, node);
                        }
                    }
                }
            }
        }

        remove_all_list_elements(neighbors, 0);
        destroy_list(neighbors);
    }

    if(!found) return;

    Node* path_node = curr_node;
    while (path_node != 0)
    {
        Vec2i* new_tilemap_pos = new_vec2i_from_vec2i(path_node->tilemap_pos);
        add_new_list_element_to_list_end(path, new_tilemap_pos);
        path_node = path_node->parent;
    }
    reverse_list(path);

    remove_all_list_elements(open, 1);
    destroy_list(open);

    remove_all_list_elements(closed, 1);
    destroy_list(closed);
}
