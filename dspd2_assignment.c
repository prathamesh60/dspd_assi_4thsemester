#include <stdio.h>
#include <string.h>
typedef enum{FAILURE,SUCCESS} statuscode;
typedef enum{FALSE,TRUE} boolean;
typedef struct item_tag
{ char itemname[100];
  float price;
  int category; // if 1 then north indian if 2 then south indian if 3 then continental
}items;
typedef struct menu_tag
{
   items item[100]; 
}menu;
typedef struct restaurant_tag
{  char name[50];
   char address[100];
   char zone[50];
   int no_of_seats;
   menu res_menu;
   int category; // 1 if restaurant 2 if cafe 3 if pub
   struct restaurant_tag *next_res;
}restaurant;
typedef struct agent_tag
{ char id[21];
  char name[50];
  char phone_no[11];
  float curr_accu_commi;
  struct agent_tag *next_agen;
}agent;
typedef user_tag
{ char us_id[21];
  char name[50];
  char address[50];
  char phone_no[11];
  struct user_tag *next_user;
}user;
typedef order_tag
{ char res_name[50];
  char res_address[50];
  int no_of_items;
  int item_index[100];
  char ag_id[21];
  char ag_phone[11];
  struct order_tag *next_order;
}orders;
void search_res_category(restaurant* res}
{ 
  int y,flag;
  printf("ENTER THE CATEGORY YOU WANT:(1)Restaurant (2)Cafe (3)Pub \n");
  scanf("%d",&y);
  if(y>=1 && y<=3)
  { flag=0;
    restaurant* nptr=res;
    while(nptr!=NULL)
    {
      { if(nptr->category==y)
        { if(flag==0)
           { printf("The eating locations are:\n");
             printf("%s\n",nptr->name); 
             flag=1;        
           }
          else
           {  printf("%s\n",nptr->name);   
           }
        }
       
       }
       nptr=nptr->next_res;
    }
    if(flag==0)
      { printf("NO Locations available\n");
      }
  }
  else
   { printf("Enter proper choice\n");
   }
}
void search_res_cuisine(restaurant* res)
{ int flag=0;
  char x[100],y[50];
  printf("Enter area: ");
  scanf("%s",x);
  printf("Enter zone: ");
  scanf("%s",y);
  restaurant* nptr=res;
  while(nptr!=NULL)
   { if(strcmp(nptr->address,x)==0)
      { if(flag==0)
         { printf("Restaurant in area:\n");
           printf("%s\n",nptr->address);
           flag=1;
         }
        else
         {
            printf("%s\n",nptr->address);
         }
      }
     nptr=nptr->next_res;
   }
  if(flag==0)
   printf("No restaurant found in area\n");
  flag=0;
  restaurant* nptr=res;
  while(nptr!=NULL)
   { if(strcmp(nptr->zone,y)==0)
      { if(flag==0)
         { printf("Restaurant in nearby area:\n");
           printf("%s\n",nptr->address);
           flag=1;
         }
        else
         {
            printf("%s\n",nptr->address);
         }
      }
     nptr=nptr->next_res;
   }
   if(flag==0)
   printf("No restaurant found in nearby areas\n");
} 
