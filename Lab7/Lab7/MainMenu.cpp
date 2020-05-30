#include "MainMenu.h"
void Menu()
{
    printf("1) Order a book(s)\n");
    printf("2) Get new book(s)\n");
    printf("3) Show stock information\n");
    printf("0) Exit\n");
    printf("Please,choose the number: ");
}
int check_borders(int left_border, int right_border)
{
    int ch;
    while (!scanf("%d", &ch) || ch < left_border || ch > right_border)
    {
        rewind(stdin);
        printf("Wrong input try again: ");
    }
    return ch;
}
void check_string(char* f)
{
    rewind(stdin);
    fgets(f, max_str_length, stdin);
    if (strlen(f) > max_str_length)
    {
        printf("The word is too long (> 20 characters)\n Try again : ");
        check_string(f);
    }
}
struct Book* get_book(struct ListBook* list, char* s)
{
   struct Book* temp;
    for (temp = list->head; temp != NULL; temp = temp->next)
        if (!strcmp(temp->name, s)) return temp;
    return NULL;
}
void delete_book(struct ListBook* list, char* s)
{
    struct Book* temp = NULL;
    temp = get_book(list, s);
    if (temp == NULL) exit(5);
    if (temp->prev) temp->prev->next = temp->next;
    if (temp->next) temp->next->prev = temp->prev;
    if (!temp->prev) list->head = temp->next;
    if (!temp->next) list->tail = temp->prev;

    free(temp);
    books_file_rewrite(list);
    list->size--;
}
int get_sum(struct ListBook* list, int fl)
{
    struct Book* tmp = list->head;
    int sum = 0;
    while (tmp) {

        if (fl == 1) sum += tmp->cost_in * tmp->books_amount;
        else if (fl == 2) sum += tmp->cost_out * tmp->books_amount;
        else sum += tmp->books_amount;
        tmp = tmp->next;
    }
    return sum;
}
void order_history()
{
   struct  ListBook* order = read_books(2);
   struct Book* temp = order->head;
    printf("Ordered books:\n");
    while (temp) {
        printf("\n%s%s", "Author: ", temp->author);
        printf("%s%s", "Name: ", temp->name);
        printf("%s%d\n", "Amount: ", temp->books_amount);
        printf("%s%d%s\n", "The price of one book: ", temp->cost_out, " $");
        printf("%s%d%s\n", "Purchased for: ", temp->cost_out * temp->books_amount, " $");
        temp = temp->next;
    }
    int sum = 0, ord_count = 0;
    int benefit = 0, sum_in = 0;
    int purchase_amount = 0;
    temp = order->head;
    while (temp) {
        ord_count++;
        purchase_amount += temp->books_amount;
        sum += temp->cost_out * temp->books_amount;
        sum_in += temp->cost_in * temp->books_amount;
        temp = temp->next;
    }
    benefit = sum - sum_in;
    printf("\n%s%d\n", "Total amount of orders: ", ord_count);
    printf("%s%d\n", "Total amount of sold books: ", purchase_amount);
    printf("%s%d%s\n", "Total storage`s profit from sale is: ", sum, " $");
    printf("%s%d%s\n", "Total storage`s benefit from sale is: ", benefit, " $");
    printf("\n");
    delete_book_list(order);
}
void make_order(struct ListBook* lst)
{
    int y_or_n;
    char* string = (char*)malloc(max_str_length * sizeof(char));
   struct Book* temp;
    do
    {
        print_books(lst);
        printf("Please,choose book to order: ");
        do {
            printf("\nEnter book`s name: ");
            rewind(stdin);
            scanf("%s", string);
            strcat(string, "\n");
            temp = get_book(lst, string);
        } while (temp == NULL);
        printf("Enter count of chosen book to order: ");
        int count = check_borders(0, temp->books_amount);
        int price = count * temp->cost_out;
        load_book_to_file(temp, 2, count);
        printf("%s%d%s\n", "Price: ", price, " $");
        temp->books_amount -= count;
        if (temp->books_amount == 0) delete_book(lst, string);
        books_file_rewrite(lst);
        printf("Do you want to order more books? (1 - yes, 0 - no)\n");
        rewind(stdin);
        y_or_n = check_borders(0, 1);
    } while (y_or_n != 0);
}
void print_info(struct ListBook* lst)
{
    printf("\n%s%d\n", "Total number of books in storage: ", get_sum(lst, 3));
    printf("%s%d%s\n", "Total cost from purchase: ", get_sum(lst, 1), " $");
    printf("%s%d%s\n", "Total cost for sale: ", get_sum(lst, 2), " $");
    print_books(lst);
    order_history();
}