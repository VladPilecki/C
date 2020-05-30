#pragma once
#include "Books.h"

void make_order(struct ListBook* lst);
int get_sum(struct ListBook* lst, int fl);
struct Book* get_book(struct ListBook* lst, char* str);
int check_borders(int l_b, int r_b);
void check_string(char* str);
void order_history();
void Menu();
void print_info(struct ListBook* lst);
