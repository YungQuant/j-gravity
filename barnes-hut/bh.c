#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct star
{
	double x;
	double y;
	double z;
	double w;
	struct star *next;
}		t_star;

typedef struct node
{
	t_star stars;
	double xmin;
	double xmax;
	double ymin;
	double ymax;
	double zmin;
	double zmax;
}		t_node;

typedef struct tiles
{
	t_node tile;
	struct tiles *next;
}       t_tile;

int list_length(t_star stars)
{
    int i = 0;
    if(stars.next == NULL)
        return i;
    else
        while(1)
        {
            i++;
            if(stars.next == NULL)
                return i;
            stars = *stars.next;
        }
}

void addBodyToLinkedList(t_node list, t_star star)
{
    t_star *new_star;
    new_star = (struct star *)malloc(sizeof(struct star));
    new_star.x = star.x;
    new_star.y = star.y;
    new_star.z = star.z;
    new_star.w = star.w;
    while(list->stars)
    {
        list->stars = list->stars->next;
        if (list->stars == NULL)
        {
            list->stars = new_star;
            list->stars->next = NULL;
            return;
        }
    }
}

void addToList(t_tile tiles, t_node list)
{
    t_tile new_tile = malloc(sizeof(t_tile));
    new_tile->tile = list;
    new_tile->next = NULL;
    while(tiles)
    {
        tiles = tiles->next;
        if(tiles == NULL)
        {
            tiles = new_tile;
            return;
        }
    }
}

//to do: list_length(), addBodyToLinkedList(), addToList()


t_tile	*split(double xmin, double xmax, double ymin, double ymax, double zmin, double zmax, t_star *bodies)
{
    if (bodies == NULL)
    {
    	printf("ERROR: bodies == NULL on initialization\n");
        return 0;
    }
    if (bodies->next == NULL)
    {
        printf("ERROR: bodies->next == NULL on initialization\n");
        return 0;
    }
    else
    {
    t_node list1 = malloc(sizeof(t_node));
    list1->xmin = xmin;
    list1->xmax = (xmin + xmax) / 2;
    list1->ymin = ymin;
    list1->ymax = (ymin + ymax) / 2;
    list1->zmin = zmin;
    list1->zmax = (zmin + zmax) / 2;

    t_node list2 = malloc(sizeof(t_node));
    list2->xmin = (xmin + xmax)/ 2;
    list2->xmax = xmax;
    list2->ymin = ymin;
    list2->ymax = (ymin + ymax) / 2;
    list2->zmin = zmin;
    list2->zmax = (zmin + zmax) / 2;

    t_node list3 = malloc(sizeof(t_node));
    list3->xmin = xmin;
    list3->xmax = (xmin + xmax) / 2;
    list3->ymin = (ymin + ymax) / 2;
    list3->ymax = ymax;
    list3->zmin = zmin;
    list3->zmax = (zmin + zmax) / 2;

    t_node list4 = malloc(sizeof(t_node));
    list4->xmin = (xmin + xmax) / 2;
    list4->xmax = xmax;
    list4->ymin = (ymin + ymax) / 2;
    list4->ymax = ymax;
    list4->zmin = zmin;
    list4->zmax = zmax;

    t_node list5 = malloc(sizeof(t_node));
    list5->xmin = xmin;
    list5->xmax = (xmin + xmax) / 2;
    list5->ymin = ymin;
    list5->ymax = (ymin + ymax) / 2;
    list5->zmin = (zmin + zmax) / 2;
    list5->zmax = zmax;

    t_node list6 = malloc(sizeof(t_node));
    list6->xmin = (xmin + xmax) / 2;
    list6->xmax = xmax;
    list6->ymin = ymin;
    list6->ymax = (ymin + ymax) / 2;
    list6->zmin = (zmin + zmax) / 2;
    list6->zmax = zmax;

    t_node list7 = malloc(sizeof(t_node));
    list7->xmin = xmin;
    list7->xmax = (xmin + xmax) / 2;
    list7->ymin = (ymin + ymax) / 2;
    list7->ymax = ymax;
    list7->zmin = (zmin + zmax / 2);
    list7->zmax = zmax;

    t_node list8 = malloc(sizeof(t_node));
    list8->xmin = (xmin + xmax) / 2;
    list8->xmax = xmax;
    list8->ymin = (ymin + ymax) / 2;
    list8->ymax = ymax;
    list8->zmin = (zmin + zmax) / 2;
    list8->zmax = zmax;

   
    while (bodies->next != NULL)
    {
        if (bodies->pos_x >= list1->xmin &&
            bodies->pos_x <= list1->xmax &&
            bodies->pos_y >= list1->ymin &&
            bodies->pos_y <= list1->ymax &&
            bodies->pos_z >= list1->zmin &&
            bodies->pos_z <= list1->zmax)
        {
            addBodyToLinkedList(list1, bodies);
        }
        else if (bodies->pos_x >= list2->xmin &&
            bodies->pos_x <= list2->xmax &&
            bodies->pos_y >= list2->ymin &&
            bodies->pos_y <= list2->ymax &&
            bodies->pos_z >= list2->zmin &&
            bodies->pos_z <= list2->zmax)
        {
            addBodyToLinkedList(list2, bodies);
        }
        else if (bodies->pos_x >= list3->xmin &&
            bodies->pos_x <= list3->xmax &&
            bodies->pos_y >= list3->ymin &&
            bodies->pos_y <= list3->ymax &&
            bodies->pos_z >= list3->zmin &&
            bodies->pos_z <= list3->zmax)
        {
            addBodyToLinkedList(list3, bodies);
        }
        else if (bodies->pos_x >= list4->xmin &&
            bodies->pos_x <= list4->xmax &&
            bodies->pos_y >= list4->ymin &&
            bodies->pos_y <= list4->ymax &&
            bodies->pos_z >= list4->zmin &&
            bodies->pos_z <= list4->zmax)
        {
            addBodyToLinkedList(list4, bodies);
        }
        else if (bodies->pos_x >= list5->xmin &&
            bodies->pos_x <= list5->xmax &&
            bodies->pos_y >= list5->ymin &&
            bodies->pos_y <= list5->ymax &&
            bodies->pos_z >= list5->zmin &&
            bodies->pos_z <= list5->zmax)
        {
            addBodyToLinkedList(list5, bodies);
        }
        else if (bodies->pos_x >= list6->xmin &&
            bodies->pos_x <= list6->xmax &&
            bodies->pos_y >= list6->ymin &&
            bodies->pos_y <= list6->ymax &&
            bodies->pos_z >= list6->zmin &&
            bodies->pos_z <= list6->zmax)
        {
            addBodyToLinkedList(list6, bodies);
        }
        else if (bodies->pos_x >= list7->xmin &&
            bodies->pos_x <= list7->xmax &&
            bodies->pos_y >= list7->ymin &&
            bodies->pos_y <= list7->ymax &&
            bodies->pos_z >= list7->zmin &&
            bodies->pos_z <= list7->zmax)
        {
            addBodyToLinkedList(list7, bodies);
        }
        else if (bodies->pos_x >= list8->xmin &&
            bodies->pos_x <= list8->xmax &&
            bodies->pos_y >= list8->ymin &&
            bodies->pos_y <= list8->ymax &&
            bodies->pos_z >= list8->zmin &&
            bodies->pos_z <= list8->zmax)
        {
            addBodyToLinkedList(list8, bodies);
        }
        else
        {
            printf("ERROR: could not place x: %lf y: %lf z: %lf\n", bodies->pos_x, bodies->pos_y, bodies->pos_z);
        }

        bodies = bodies->next;
    }
    t_tile tiles = malloc(sizeof(t_tile));
    tiles->node = list1;
    tiles->next = NULL;
    addToList(tiles, list2)
    addToList(tiles, list3)
    addToList(tiles, list4)
    addToList(tiles, list5)
    addToList(tiles, list6)
    addToList(tiles, list7)
    addToList(tiles, list8)

    return tiles;
}

t_tile partition(int n, t_star *stars)
{
    t_tile *head = malloc(sizeof(t_tile));
    t_tile *temp = split(stars, NULLLLLLLLLLLLLLLLLLL);
    while(temp->tile)
    {
        if(list_length(temp->tile->stars) < n)
            addToList(head, temp);
        else
            addToList(temp, split(temp));
        temp = temp->next;
    }
    return head;
}
