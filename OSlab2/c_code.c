#include<linux/list.h>
#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/types.h>
#include<linux/slab.h>

struct birthday {
int day;
int month;
int year;
struct list_head list;
};

static LIST_HEAD(birthday_list);

int simple_init(void){
struct birthday *ptr;
    int i;
    for(i = 0; i < 5; i++) {
        // create 5 birthday structs and add them to the list

        struct birthday *person;
        person = kmalloc(sizeof(*person), GFP_KERNEL);
        person->day = 22+i;
        person->month = 11+i;
        person->year = 1981+i;
        INIT_LIST_HEAD(&person->list);

        list_add_tail(&person->list, &birthday_list);
    }

    list_for_each_entry(ptr, &birthday_list, list) {
        
        printk(KERN_INFO "%d, %d %d \n", ptr->month, ptr->day, ptr->year);
     }

    return 0;
    }

void simple_exit(void){
  struct birthday *ptr, *next;
      list_for_each_entry_safe(ptr, next, &birthday_list, list) {
    // delete structs and return memory
    printk(KERN_INFO "Removing...\n");
    list_del(&ptr->list);
    kfree(ptr);
      }
}


module_init(simple_init);
module_exit(simple_exit);