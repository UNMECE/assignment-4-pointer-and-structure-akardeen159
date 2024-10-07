#include "item.h" 

void add_item(Item *item_list, double price,const char *sku,const char *category,const char *name, int index)
{
    item_list[index].price = price;

    item_list[index].sku = (char *)malloc(strlen(sku) + 1);
    strcpy(item_list[index].sku, sku);

    item_list[index].category = (char *)malloc(strlen(category) + 1);
    strcpy(item_list[index].category, category);

    item_list[index].name = (char *)malloc(strlen(name) + 1);
    strcpy(item_list[index].name, name);
}



void free_items(Item *item_list, int size){
    for (int i = 0; i < size; i++)
    {
        free(item_list[i].sku);
        free(item_list[i].name);
        free(item_list[i].category);
    }
    free(item_list);
}

double average_price(Item *item_list, int size)
{
    double total = 0.0;
    for (int i = 0; i < size; i++)
    {
        total += item_list[i].price;
    }
    return total / size;
}

void print_items(Item *item_list, int size){
    for (int i = 0; i < size; i++){
        if(item_list[i].name == NULL){
            printf("item is empty");
        }else{

        
        printf("###############\n");
        printf("item name = %s\n", item_list[i].name);
        printf("item sku = %s\n", item_list[i].sku);
        printf("item category = %s\n", item_list[i].category);
        printf("item price = %f\n", item_list[i].price);
        }
    }
printf("###############\n");
}
    

int main(int argc, char *argv[]) {

    int size = 5;
    Item *item_list = (Item *)malloc(size * sizeof(Item));

    if (item_list == NULL) {
        printf("memory allocation failed\n");
        return 1;
    }
    
    add_item(item_list,2.50, "12345", "Fruit", "Apples", 0);
    add_item(item_list,3.00, "54321", "Bakery", "Bread", 1);
    add_item(item_list,3.50, "24680", "Protien", "Eggs", 2);
    add_item(item_list,1.50, "13579", "Candy", "Chocolate", 3);
    add_item(item_list,3.00, "98765", "Snacks", "Chips", 4);
    print_items(item_list, size);
    printf("Average price of items = %f\n", average_price(item_list, size));
    
       if (argc == 2)
    {
        char *search_sku = argv[1];
        int ct = 0;
        while (ct < size && strcmp(item_list[ct].sku, search_sku) != 0)
        {
            ct++;
        }

        if (ct < size)
        {
            printf("\nItem found:\n");
            printf("item name = %s\n", item_list[ct].name);
            printf("item sku = %s\n", item_list[ct].sku);
            printf("item category = %s\n", item_list[ct].category);
            printf("item price = %f\n", item_list[ct].price);
        }
        else
        {
            printf("\nItem not found\n");
        }
    }

    free_items(item_list, size);
    return 0;
}

