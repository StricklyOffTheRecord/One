#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<string.h>
#include<dos.h>
#include<stdlib.h>
#include<time.h>

struct pizza_toppings
{
	char toppings[20];

	struct pizza_toppings *pizza_toppings_next;

}*temp_pizza_toppings,*curr_pizza_toppings=NULL,*end_pizza_toppings;



struct pizza
{
	char pizza_name[100];

	struct pizza *pizza_next;
	struct pizza_toppings *pizza_toppings_next;

}*temp_pizza,*curr_pizza=NULL,*end_pizza,*fwd_pizza,*pre_pizza;





struct pizza_size
{
	char size_name[100];
	int price;

	struct pizza_size *pizza_size_next;

}*temp_pizza_size,*curr_pizza_size=NULL,*end_pizza_size;



struct pizza_type
{
	char type[100];

	struct pizza* pizza_next;
	struct pizza_size *pizza_size_next;
	struct pizza_type *pizza_type_next;

}*temp_pizza_type,*curr_pizza_type=NULL,*end_pizza_type,*pre_pizza_type,*fwd_pizza_type;




struct pizza_preference
{
	char preference[100];

	struct pizza_type *pizza_type_next;

}*temp_pizza_preference,*start=NULL,*curr=NULL,*preference_end;





struct bill_order
{
	char bill_order_pizza[100];
	char bill_order_size[100];
	int bill_order_price;

	struct bill_order*bill_order_next;

}*temp_bill_order,*start_bill_order=NULL,*curr_bill_order,*end_bill_order;


struct topping_ud
{
	int sno;
	char name[100];
	int price;

}x[12];

struct stack_ud
{
	struct topping_ud t;
	struct stack_ud *next;

}*top=NULL, *temp;





struct theme_pizza
{
	int priority;
	char theme_name[100];
	char pizza_name[100];
	char description[200];
	struct theme_pizza *link;

}*theme_pizza_front=NULL;



struct emp_stack
{
	 char name[25];
	 int age;
	 int salary;
	 struct emp_stack *next;
} *order_top=NULL, *delivery_top=NULL, *chef_top=NULL;

struct emp_manager
{
	char name[25];
	int age;
	int salary;
	struct emp_stack *link[3];
} **m;




int user_defined_pizza_price=0,totalbill=0,number_of_pizza_type=4,number_of_pizza_size=3,number_of_pizza_toppings=2,number_of_pizza=2;

int view_number_of_pizza=4,display_ud=0,total_input=0;



void front_page_main();

void front_page_text();

int front_page_color(int);

void loading();

void loading_main();

void manager();

void grant_access(int);

void grant_access_1(int);

void login_1();

void login();

void  forward();

void view();

void billing(int);

void user_defined_pizza();

int total_price_ud;

void create_ud();

void push_ud(int);

int pop_ud();

void func_ud();

void create();

int priority();

void display(int);

void theme_pizza();

void working();

int compare_strings(char a[], char b[]);

void add_new_type();

void modify();

void deleting();

void change_password();

int input_date();

void emp_create();

void emp_login(char[]);

void emp_manager(struct emp_manager *);

void emp_employee(struct emp_stack *);

void emp_push(struct emp_stack *);

void emp_pop(struct emp_stack *);

int emp_compare_strings(char[], char[]);

void emp_main();

void accounts();

void home_screen();


void main()
{
	front_page_main();
	loading_main();
	login();

}





void front_page_main()
{
	int gd=DETECT, gm;
	clrscr();
	initgraph(&gd, &gm, "C:\\TC\\BGI");
	//front_page_text();
	home_screen();
	getch();
	closegraph();
}



void home_screen()
{
	int x, y, color, angle = 0;
	int i, j;
	struct arccoordstype a, b;
	cleardevice();

	while(angle<=360)
	{
		setcolor(BLACK);
		arc(getmaxx()/2,getmaxy()/2,angle,angle+2,100);
		setcolor(GREEN);
		getarccoords(&a);
		circle(a.xstart,a.ystart,35);
		setcolor(BLACK);
		arc(getmaxx()/2,getmaxy()/2,angle,angle+2,150);
		getarccoords(&a);
		setcolor(BLUE);
		circle(a.xstart,a.ystart,35);
		angle = angle+5;
		delay(100);
	}
	for(i=0, j=1; i<4&&!kbhit(); i++)
	{
	 while(angle<=360)
	 {
		setcolor(BLACK);
		arc(getmaxx()/2,getmaxy()/2,angle,angle+2,100);
		setcolor(GREEN);
		getarccoords(&a);
		circle(a.xstart,a.ystart,35);
		setcolor(BLACK);
		arc(getmaxx()/2,getmaxy()/2,angle,angle+2,150);
		getarccoords(&a);
		setcolor(BLUE);
		circle(a.xstart,a.ystart,35);
		angle = angle+5;


	 }
		setcolor(front_page_color(j++));
		settextstyle(1, 0, 7);
		outtextxy(265+i*4, 195, "SAK");
		setcolor(4);
		settextstyle(1, 0, 4);
		outtextxy(290, 243, "pizza");
		delay(500);

		if(i==3)
		{
			cleardevice();
			i=0;
			j=1;
		}

	}
}


int front_page_color(int i)
{
	int z;
	switch(i)
	{
		case 1: z=1; return z;
		case 2: z=2; return z;
		case 3: z=9; return z;
		case 4: z=11; return z;

	}
	return 0;
}







void loading_main()
{
	int gd=DETECT, gm;
	initgraph(&gd, &gm, "C:\\TC\\BGI");
	loading();
       //	getch();
	closegraph();
}





void loading()
{
	int i=0;
	int p1[10]={305, 202, 308, 207, 312, 195, 309, 190, 305, 202};
	int p2[10]={343, 180, 348, 185, 347, 173, 342, 168, 343, 180};
	int p3[10]={307, 165, 310, 170, 314, 158, 311, 153, 307, 165};
	int p4[10]={279, 209, 284, 214, 283, 202, 278, 197, 279, 209};
	int p5[10]={253, 236, 250, 231, 254, 219, 257, 224, 253, 236};
	int p6[10]={252, 187, 252-3, 187-5, 252+1, 187-17, 252+4, 187-12, 252, 187};
	int p7[10]={295, 258, 295-1, 258-12, 295+4, 258-7, 295+5, 258+5, 295, 258};
	int p8[10]={265, 283, 265-3, 283-5, 265+1, 283-17, 265+4, 283-12, 265, 283};
	int p9[10]={235, 271, 235-3, 271-5, 235+1, 271-17, 235+4, 271-12, 235, 271};
	int p10[10]={304, 288, 304-1, 288-12, 304+4, 288-7, 304+5, 288+5, 304, 288};
	int p11[10]={318, 320, 318-3, 320-5, 318+1, 320-17, 318+4, 320-12, 318, 320};
	int p12[10]={288, 327, 288-1, 327-12, 288+4, 327-7, 288+5, 327+5, 288, 327};
	int p13[10]={345, 272, 345-1, 272-12, 345+4, 272-7, 345+5, 272+5, 345, 272};
	int p14[10]={375, 275, 375-1, 275-12, 375+4, 275-7, 375+5, 275+5, 375, 275};
	int p15[10]={340, 235, 340-3, 235-5, 340+1, 235-17, 340+4, 235-12, 340, 235};
	int p16[10]={375, 231, 375-1, 231-12, 375+4, 231-7, 375+5, 231+5, 375, 231};
	int p17[10]={397, 218, 397-3, 218-5, 397+1, 218-17, 397+4, 218-12, 397, 218};

	for(i=0; i<=300; i+=60)
	{
		setcolor(WHITE);
		setfillstyle(SOLID_FILL, RED);
		pieslice(320, 240, i, i+60, 110);
		setfillstyle(SOLID_FILL, YELLOW);
		pieslice(320, 240, i, i+60, 100);
		arc(320, 240, i, i+60, 115);

		if(i==0)
		{
			//Olives
			setfillstyle(SOLID_FILL, BLACK);
			circle(358, 227, 7);
			circle(358, 227, 3);
			floodfill(358, 223, 15);

			circle(382, 210, 7);
			circle(382, 210, 3);
			floodfill(382, 206, 15);

			circle(372, 180, 7);
			circle(372, 180, 3);
			floodfill(372, 176, 15);

			circle(404, 227, 7);
			circle(404, 227, 3);
			floodfill(404, 223, 15);

			//Pepperoni
			setfillstyle(SOLID_FILL, RED);
			circle(360, 202, 10);
			floodfill(360, 202, 15);

			circle(390, 190, 10);
			floodfill(390, 190, 15);

			//Capsicum
			setfillstyle(SOLID_FILL, GREEN);

			//drawpoly(10, p15);
			//floodfill(340, 232, 15);

			drawpoly(10, p16);
			floodfill(376, 231, 15);

			drawpoly(10, p17);
			floodfill(397, 215, 15);
		}


		if(i==60)
		{
			//Olives
			circle(320, 220, 7);
			circle(320, 220, 3);
			setfillstyle(SOLID_FILL,BLACK);
			floodfill(320, 216, 15);

			circle(350, 160, 7);
			circle(350, 160, 3);
			floodfill(350, 156, 15);

			circle(307, 180, 7);
			circle(307, 180, 3);
			floodfill(307, 176, 15);

			//Pepperoni
			circle(328, 200, 10);
			setfillstyle(SOLID_FILL, RED);
			floodfill(328, 200, 15);

			circle(292, 160, 10);
			floodfill(292, 160, 15);

			circle(328, 167, 10);
			floodfill(328, 167, 15);

			//Capsicum
			setfillstyle(SOLID_FILL, GREEN);
			drawpoly(10, p1);
			floodfill(306, 202, 15);

			drawpoly(10, p2);
			floodfill(344, 180, 15);

			drawpoly(10, p3);
			floodfill(308, 165, 15);

		}

		if(i==120)
		{
			//Olives
			circle(270, 228, 7);
			circle(270, 228, 3);
			setfillstyle(SOLID_FILL, BLACK);
			floodfill(270, 224, 15);

			circle(236, 220, 7);
			circle(236, 220, 3);
			floodfill(236, 216, 15);

			circle(270, 185, 7);
			circle(270, 185, 3);
			floodfill(270, 181, 15);

			//Pepperoni
			circle(295, 226, 10);
			setfillstyle(SOLID_FILL, RED);
			floodfill(295, 226, 15);

			circle(260, 205, 10);
			floodfill(260, 205, 15);

			//Capsicum
			setfillstyle(SOLID_FILL, GREEN);
			drawpoly(10, p4);
			floodfill(280, 209, 15);

			drawpoly(10, p5);
			floodfill(253, 233, 15);

			drawpoly(10, p6);
			floodfill(252, 184, 15);

		}

		if(i==180)
		{
			//Olives
			setfillstyle(SOLID_FILL, BLACK);
			circle(284, 278, 7);
			circle(284, 278, 3);
			floodfill(284, 274, 15);

			circle(252, 254, 7);
			circle(252, 254, 3);
			floodfill(252, 250, 15);

			circle(247, 283, 7);
			circle(247, 283, 3);
			floodfill(247, 279, 15);

			//Pepperoni
			setfillstyle(SOLID_FILL, RED);
			circle(277, 256, 10);
			floodfill(277, 256, 15);

			circle(265, 300, 10);
			floodfill(265, 300, 15);

			//Capsicum
			setfillstyle(SOLID_FILL, GREEN);
			drawpoly(10, p7);
			floodfill(296, 258, 15);

			drawpoly(10, p8);
			floodfill(265, 280, 15);

			drawpoly(10, p9);
			floodfill(235, 268, 15);
		}

		if(i==240)
		{
			//Olives
			setfillstyle(SOLID_FILL, BLACK);
			circle(330, 295, 7);
			circle(330, 295, 3);
			floodfill(330, 291, 15);

			circle(310, 330, 7);
			circle(310, 330, 3);
			floodfill(315, 326, 15);

			//Pepperoni
			setfillstyle(SOLID_FILL, RED);
			circle(320, 270, 10);
			floodfill(320, 270, 15);

			circle(300, 305, 10);
			floodfill(300, 305, 15);

			circle(345, 320, 10);
			floodfill(345, 320, 15);

			//Capsicum
			setfillstyle(SOLID_FILL, GREEN);
			drawpoly(10, p10);
			floodfill(305, 288, 15);

			drawpoly(10, p11);
			floodfill(318, 316, 15);

			drawpoly(10, p12);
			floodfill(289, 327, 15);
		}


		if(i==300)
		{
			//Olives
			setfillstyle(SOLID_FILL, BLACK);
			circle(338, 250, 7);
			circle(338, 250, 3);
			floodfill(338, 246, 15);

			circle(362, 285, 7);
			circle(362, 285, 3);
			floodfill(362, 281, 15);

			circle(397, 280, 7);
			circle(397, 280, 3);
			floodfill(397, 276, 15);

			//Pepperoni
			setfillstyle(SOLID_FILL, RED);
			circle(362, 255, 10);
			floodfill(362, 255, 15);

			circle(380, 300, 10);
			floodfill(380, 300, 15);

			circle(397, 255, 10);
			floodfill(397, 255, 15);

			//Capsicum
			setfillstyle(SOLID_FILL, GREEN);
			drawpoly(10, p13);
			floodfill(346, 272, 15);

			drawpoly(10, p14);
			floodfill(376, 275, 15);

		}
		delay(250);
	}

}





void login()
{
	char kat_pass[100],kat_id[100],aay_pass[100],aay_id[100],shr_pass[100],shr_id[100];
	char name[100],password[100],temp[]="temp";

	FILE *f_katyayn,*f_shruti,*f_aayush;




	f_katyayn=fopen("PizzaKat.dat","r");
	f_shruti=fopen("PizzaShr.dat","r");
	f_aayush=fopen("PizzaAay.dat","r");





	clrscr();
	textcolor(GREEN);
	gotoxy(18,7);
	cprintf("±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±");
	gotoxy(18,8);
	cprintf("±±");
	gotoxy(56,8);
	cprintf("±±");
	gotoxy(18,9);
	cprintf("±±");
	gotoxy(56,9);
	cprintf("±±");
	gotoxy(18,10);
	cprintf("±±");
	gotoxy(56,10);
	cprintf("±±");
	gotoxy(18,11);
	cprintf("±±");
	gotoxy(56,11);
	cprintf("±±");
	gotoxy(18,12);
	cprintf("±±");
	gotoxy(56,12);
	cprintf("±±");

	gotoxy(18,13);
	cprintf("±±");
	gotoxy(56,13);
	cprintf("±±");
	gotoxy(18,14);
	cprintf("±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±");
	gotoxy(21,9);
	cprintf("Enter user name :");
	gets(name);
	gotoxy(21,11);
	cprintf("Enter password  :");
	gets(password);




	fgets(kat_id,sizeof(kat_id),f_katyayn);
	fgets(kat_pass,sizeof(kat_pass),f_katyayn);

	fgets(aay_id,sizeof(aay_id),f_aayush);
	fgets(aay_pass,sizeof(aay_pass),f_aayush);

	fgets(shr_id,sizeof(shr_id),f_shruti);
	fgets(shr_pass,sizeof(shr_pass),f_shruti);


	if(compare_strings(name,kat_id)==0&&compare_strings(password,kat_pass)==0)
	{
		grant_access(1);
	}

	else if(compare_strings(name,aay_id)==0&&compare_strings(password,aay_pass)==0)
	{
		grant_access(1);
	}

	else if(compare_strings(name,shr_id)==0&&compare_strings(password,shr_pass)==0)
	{
		grant_access(1);
	}

	else if(compare_strings(name,temp)==0&&compare_strings(password,temp)==0)
	{
		grant_access(2);
	}

	else
	{
		grant_access(0);
	}









	fclose(f_aayush);
	fclose(f_shruti);
	fclose(f_katyayn);

}






void grant_access(int grant)
{
	int i,j;

	clrscr();

	textcolor(LIGHTRED+BLINK);
	cprintf("\n\n\n\n\n\nVERIFYING  ");

	for(i=0;i<60;i++)
	{
		textcolor(RED);
		cprintf("±");
		delay(50);
	}

	if(grant==1||grant==2)
	{

		clrscr();
		textcolor(LIGHTGREEN+BLINK);
		printf("\n\n\n\n\n\n\n\n\n\t\t\t\t");
		cprintf("±±±±±±±±±±±±±±±±±±±±±±");
		printf("\n\t\t\t\t");
		cprintf("±±                  ±±");
		printf("\n\t\t\t\t");
		cprintf("±± LOGIN SUCCESSFUL ±±");
		printf("\n\t\t\t\t");
		cprintf("±±                  ±±");
		printf("\n\t\t\t\t");
		cprintf("±±±±±±±±±±±±±±±±±±±±±±");

		clrscr();
		textcolor(YELLOW);
		working();

		if(grant==1)
		{
			manager();
		}

		if(grant==2)
		{
			view();
		}
	}

	else
	{

		clrscr();
		textcolor(LIGHTRED+BLINK);
		printf("\n\n\n\n\n\n\n\n\n\t\t\t\t");
		cprintf("±±±±±±±±±±±±±±±±±±±±±±±±");
		printf("\n\t\t\t\t");
		cprintf("±±                    ±±");
		printf("\n\t\t\t\t");
		cprintf("±± LOGIN UNSUCCESSFUL ±±");
		printf("\n\t\t\t\t");
		cprintf("±±                    ±±");
		printf("\n\t\t\t\t");
		cprintf("±±±±±±±±±±±±±±±±±±±±±±±±");

		getch();
		login();

	}

	getch();

}



void manager()
{
	int manager_choice,option;
	clrscr();
	printf("\t\t\t\tWELCOME SIR");
	printf("\n\n\n");
	printf("1) MENU \n\n");
	printf("2) MENU OPTIONS\n\n");
	printf("3) ACCOUNTS\n\n");
	printf("4) EMPLOYEES\n\n");
	printf("5) CHANGE PASSWORD\n\n");
	printf("6) EXIT\n\n");

	printf("Please enter your choice  :");
	scanf("%d",&manager_choice);

	switch(manager_choice)
	{

		case 1:	loading_main();
			view();
			break;

		case 2:	loading_main();
			clrscr();
			printf("\t\t\tMENU OPTIONS\n\n\n");
			printf("1) ADD PIZZA TYPE\n\n");
			printf("2) MODIFY\n\n");
			printf("3) DELETE\n\n");
			printf("4) Back To MANAGER Window\n\n");
			printf("Please Enter Your Choice  :\t");
			scanf("%d",&option);

			if(option==1)
			{
				add_new_type();
				manager();
			}

			if(option==2)
			{
				modify();
				manager();
			}

			if(option==3)
			{
				deleting();
				manager();
			}

			if(option==4)
			{
				manager();
			}
			break;

		case 3:	loading_main();
			accounts();
			manager();
			break;

		case 4:	loading_main();
			emp_main();
			manager();

			break;

		case 5:	loading_main();
			change_password();
			manager();
			break;

		case 6: clrscr();
			printf("\n\nPRESS ANY KEY TO EXIT\n");
			exit(0);
	}

}




void change_password()
{
	char temp_manager_id[100],temp_manager_password[100];


	FILE *f_katyayn,*f_shruti,*f_aayush;

	clrscr();

	printf("\n\nEnter the Manager ID:\t");
	fflush(stdin);
	gets(temp_manager_id);

	if(strcmp(temp_manager_id,"katyayn")==0)
	{
		f_katyayn=fopen("PizzaKat.dat","w");

		fprintf(f_katyayn,"%s\n",temp_manager_id);

		printf("\n\nEnter the NEW PASSWORD:\t");

		fflush(stdin);
		gets(temp_manager_password);

		fprintf(f_katyayn,"%s\n",temp_manager_password);


		fclose(f_katyayn);
	}



	else if(strcmp(temp_manager_id,"shruti")==0)
	{
		f_katyayn=fopen("PizzaShr.dat","w");

		fprintf(f_shruti,"%s\n",temp_manager_id);

		printf("\n\nEnter the NEW PASSWORD:\t");

		fflush(stdin);
		gets(temp_manager_password);

		fprintf(f_shruti,"%s\n",temp_manager_password);


		fclose(f_shruti);
	}




	else if(strcmp(temp_manager_id,"aayush")==0)
	{
		f_katyayn=fopen("PizzaAay.dat","w");

		fprintf(f_aayush,"%s\n",temp_manager_id);

		printf("\n\nEnter the NEW PASSWORD:\t");

		fflush(stdin);
		gets(temp_manager_password);

		fprintf(f_aayush,"%s\n",temp_manager_password);


		fclose(f_aayush);
	}


	else
	{
		printf("\n\n\t\tWrong ID \n\n\t\tPress any key to try again");
		getch();
		change_password();
	}


	printf("\n\nPress any key to Return to MANAGER MENU:\t");

	getch();

	manager();

}


int input_date()
{
	int date;

	clrscr();

	printf("\n\nEnter the Current Month for Theme Access:\t");
	scanf("%d",&date);


	return date;
}




void working()
{


	char temp_type[100],temp_size[100],temp_pizza_name[100],temp_pizza_toppings_1[100];
	int i,j,k,temp_price;



	FILE *f_preference,*f_pizza_type,*f_pizza_size,*f_pizza_price,*f_pizza_toppings,*f_pizza;


	clrscr();

	f_preference=fopen("PizzaPreference.dat","r");
	f_pizza_type=fopen("PizzaType.dat","r");
	f_pizza_size=fopen("PizzaSize.dat","r");
	f_pizza_price=fopen("PizzaPrice.dat","r");
	f_pizza_toppings=fopen("PizzaToppings.dat","r");
	f_pizza=fopen("PizzaName.dat","r");




	temp_pizza_preference=(struct pizza_preference*)malloc(sizeof(struct pizza_preference));
	temp_pizza_preference->pizza_type_next=NULL;
	strcpy(temp_pizza_preference->preference,"MENU");

	if(start==NULL)
	{
		start=temp_pizza_preference;
		preference_end=start;
	}


	for(i=0;i<number_of_pizza_type;i++)
	{
		temp_pizza_type=(struct pizza_type*)malloc(sizeof(struct pizza_type));
		temp_pizza_type->pizza_next=NULL;
		temp_pizza_type->pizza_type_next=NULL;
		temp_pizza_type->pizza_size_next=NULL;

		fgets(temp_type,sizeof(temp_type),f_pizza_type);

		strcpy(temp_pizza_type->type,temp_type);



		if(start->pizza_type_next==NULL)
		{
			start->pizza_type_next=temp_pizza_type;
			end_pizza_type=temp_pizza_type;
		}

		else
		{
			end_pizza_type->pizza_type_next=temp_pizza_type;
			end_pizza_type=temp_pizza_type;
		}




		for(j=0;j<number_of_pizza_size;j++)
		{
			temp_pizza_size=(struct pizza_size*)malloc(sizeof(struct pizza_size));

			temp_pizza_size->pizza_size_next=NULL;

			fgets(temp_size,sizeof(temp_size),f_pizza_size);



			strcpy(temp_pizza_size->size_name,temp_size);



			fscanf(f_pizza_price,"%d",&temp_price);

			temp_pizza_size->price=temp_price;



			if(end_pizza_type->pizza_size_next==NULL)
			{
				end_pizza_type->pizza_size_next=temp_pizza_size;
				end_pizza_size=temp_pizza_size;
			}

			else
			{
				end_pizza_size->pizza_size_next=temp_pizza_size;
				end_pizza_size=temp_pizza_size;
			}



		}

		rewind(f_pizza_size);


		for(j=0;j<number_of_pizza;j++)
		{
			temp_pizza=(struct pizza*)malloc(sizeof(struct pizza));

			temp_pizza->pizza_next=NULL;


			temp_pizza->pizza_toppings_next=NULL;

			fgets(temp_pizza_name,sizeof(temp_pizza_name),f_pizza);

			strcpy(temp_pizza->pizza_name,temp_pizza_name);




			if(end_pizza_type->pizza_next==NULL)
			{
				end_pizza_type->pizza_next=temp_pizza;
				end_pizza=temp_pizza;
			}

			else
			{
				end_pizza->pizza_next=temp_pizza;
				end_pizza=temp_pizza;
			}


			for(k=0;k<number_of_pizza_toppings;k++)
			{
				temp_pizza_toppings=(struct pizza_toppings *)malloc(sizeof(struct pizza_toppings));

				temp_pizza_toppings->pizza_toppings_next=NULL;


				fgets(temp_pizza_toppings_1,sizeof(temp_pizza_toppings_1),f_pizza_toppings);

				strcpy(temp_pizza_toppings->toppings,temp_pizza_toppings_1);

				if(end_pizza->pizza_toppings_next==NULL)
				{
					end_pizza->pizza_toppings_next=temp_pizza_toppings;
					end_pizza_toppings=temp_pizza_toppings;
				}

				else
				{
					end_pizza_toppings->pizza_toppings_next=temp_pizza_toppings;
					end_pizza_toppings=temp_pizza_toppings;
				}




			}




		}


	}



	fclose(f_pizza);
	fclose(f_pizza_toppings);
	fclose(f_pizza_price);
	fclose(f_pizza_size);
	fclose(f_pizza_type);
	fclose(f_preference);

}




int compare_strings(char a[], char b[])
{
	int i,flag=1;

	for(i=0;i<(strlen(a));i++)
	{
		if(a[i]==b[i])
		{
			flag=0;
		}
		else
		{
			flag=1;
			break;
		}
	}

	return flag;

}



void add_new_type()
{


	char temp_type_name[100],new_type_name[100],temp_size[100],new_pizza_name[100],new_pizza_toppings[100];
	int choice,i,j,k,temp_price;

	FILE *f_pizza_size;

	clrscr();

	f_pizza_size=fopen("PizzaSize.dat","r");


	printf("\n\t\t\tADDING NEW TYPE\n");

	printf("\nEnter the name of the new type:\t");
	fflush(stdin);
	gets(new_type_name);



	temp_pizza_type=(struct pizza_type*)malloc(sizeof(struct pizza_type));
	temp_pizza_type->pizza_next=NULL;
	temp_pizza_type->pizza_type_next=NULL;
	temp_pizza_type->pizza_size_next=NULL;


	strcat(new_type_name,"\n");
	strcpy(temp_pizza_type->type,new_type_name);


	if(preference_end->pizza_type_next==NULL)
	{
		preference_end->pizza_type_next=temp_pizza_type;
		end_pizza_type=temp_pizza_type;
	}

	else
	{
		end_pizza_type->pizza_type_next=temp_pizza_type;
		end_pizza_type=temp_pizza_type;
	}


	for(i=1;i<=number_of_pizza;i++)
	{


		temp_pizza=(struct pizza*)malloc(sizeof(struct pizza));

		temp_pizza->pizza_next=NULL;
		temp_pizza->pizza_toppings_next=NULL;



		printf("\nEnter the name of pizza %d of new type:\t",i);
		fflush(stdin);
		gets(new_pizza_name);

		strcat(new_pizza_name,"\n");

		strcpy(temp_pizza->pizza_name,new_pizza_name);


		if(end_pizza_type->pizza_next==NULL)
		{
			end_pizza_type->pizza_next=temp_pizza;
			end_pizza=temp_pizza;
		}

		else
		{
			end_pizza->pizza_next=temp_pizza;
			end_pizza=temp_pizza;
		}


		for(k=1;k<=number_of_pizza_toppings;k++)
		{
			temp_pizza_toppings=(struct pizza_toppings *)malloc(sizeof(struct pizza_toppings));

			temp_pizza_toppings->pizza_toppings_next=NULL;


			printf("\nEnter the topping %d of pizza %d of new type:\t",k,i);
			fflush(stdin);
			gets(new_pizza_toppings);

			strcat(new_pizza_toppings,"\n");

			strcpy(temp_pizza_toppings->toppings,new_pizza_toppings);


			if(end_pizza->pizza_toppings_next==NULL)
			{
				end_pizza->pizza_toppings_next=temp_pizza_toppings;
				end_pizza_toppings=temp_pizza_toppings;
			}

			else
			{
				end_pizza_toppings->pizza_toppings_next=temp_pizza_toppings;
				end_pizza_toppings=temp_pizza_toppings;
			}
		}

	}



	for(j=1;j<=number_of_pizza_size;j++)
	{
		temp_pizza_size=(struct pizza_size*)malloc(sizeof(struct pizza_size));

		temp_pizza_size->pizza_size_next=NULL;

		fgets(temp_size,sizeof(temp_size),f_pizza_size);

		strcpy(temp_pizza_size->size_name,temp_size);

		printf("\nEnter the PRICE of SIZE %d for the NEW TYPE:\t",j);
		scanf("%d",&temp_price);

		temp_pizza_size->price=temp_price;



		if(end_pizza_type->pizza_size_next==NULL)
		{
			end_pizza_type->pizza_size_next=temp_pizza_size;
			end_pizza_size=temp_pizza_size;
		}

		else
		{
			end_pizza_size->pizza_size_next=temp_pizza_size;
			end_pizza_size=temp_pizza_size;
		}


	}

	view_number_of_pizza+=1;

	fclose(f_pizza_size);

}






void modify()
{
	int choice,change_price,i,j;

	char temp_type_name[100],change_type_name[100],temp_size_name[100],temp_pizza_name[100],change_pizza_name[100];





	printf("\n\nWhat do you want to modify:\t\n");

	printf("\n1.TYPE NAME");
	printf("\n2.PRICE");
	printf("\n3.PIZZA NAME");


	printf("\n\nEnter your choice:\t");
	scanf("%d",&choice);


	switch(choice)
	{
		case 1:	printf("\n\nCHANGING TYPE NAME");

			printf("\n\nEnter the TYPE Name you want to change:\t");
			fflush(stdin);
			gets(temp_type_name);

			printf("\n\nEnter the NEW TYPE name:\t");
			fflush(stdin);
			gets(change_type_name);

			curr_pizza_type=preference_end->pizza_type_next;

			for(i=0;i<number_of_pizza_type;i++)
			{
				if(compare_strings(temp_type_name,curr_pizza_type->type)==0)
				{
					strcpy(curr_pizza_type->type,change_type_name);
				}

				curr_pizza_type=curr_pizza_type->pizza_type_next;
			}



			break;


		case 2:	printf("\n\nCHANGING PRICE");

			printf("\n\nEnter the TYPE whose PRICE you want to change:\t");
			fflush(stdin);
			gets(temp_type_name);

			printf("\n\nEnter the SIZE whose PRICE you want to change:\t");
			fflush(stdin);
			gets(temp_size_name);

			printf("\n\nEnter the New Price :\t");
			scanf("%d",&change_price);



			curr_pizza_type=preference_end->pizza_type_next;

			for(i=0;i<number_of_pizza_type;i++)
			{
				if(compare_strings(temp_type_name,curr_pizza_type->type)==0)
				{
					curr_pizza_size=curr_pizza_type->pizza_size_next;

					for(j=0;j<number_of_pizza_size;j++)
					{
						if(compare_strings(temp_size_name,curr_pizza_size->size_name)==0)
						{
							curr_pizza_size->price=change_price;
						}

						curr_pizza_size=curr_pizza_size->pizza_size_next;
					}


				}

				curr_pizza_type=curr_pizza_type->pizza_type_next;
			}


			break;



		case 3: printf("\n\nEnter the TYPE in which Pizza Name is to be changed:\t");
			fflush(stdin);
			gets(temp_type_name);

			printf("\n\nEnter the PIZZA NAME to be changed:\t");
			fflush(stdin);
			gets(temp_pizza_name);

			printf("\n\nEnter new PIZZA NAME:\t");
			fflush(stdin);
			gets(change_pizza_name);

			curr_pizza_type=preference_end->pizza_type_next;

			for(i=0;i<number_of_pizza_type;i++)
			{


				if(compare_strings(temp_type_name,curr_pizza_type->type)==0)
				{


					curr_pizza=curr_pizza_type->pizza_next;

					for(j=0;j<number_of_pizza;j++)
					{


						if(compare_strings(temp_pizza_name,curr_pizza->pizza_name)==0)
						{
							strcpy(curr_pizza->pizza_name,change_pizza_name);
						}

						curr_pizza=curr_pizza->pizza_next;
					}
				}

				curr_pizza_type=curr_pizza_type->pizza_type_next;

			}

			break;

	}

}










void deleting()
{
	int choice,i,j;

	char temp_type_name[100],temp_pizza_name[100];



	printf("\n\nWhat do you want to modify:\t\n");

	printf("\n1.TYPE NAME");
	printf("\n2.PIZZA NAME");


	printf("\n\nEnter your choice:\t");
	scanf("%d",&choice);


	switch(choice)
	{
		case 1:	printf("\n\nEnter the TYPE NAME you want to remove:\t");
			fflush(stdin);
			gets(temp_type_name);

			curr_pizza_type=preference_end->pizza_type_next;

			while(curr_pizza_type!=NULL)
			{
				fwd_pizza_type=curr_pizza_type->pizza_type_next;

				if(!compare_strings(temp_type_name,curr_pizza_type->type))
				{
					if(curr_pizza_type==preference_end->pizza_type_next)
					{
						preference_end->pizza_type_next=curr_pizza_type->pizza_type_next;

						curr_pizza_type->pizza_type_next=NULL;

						free(curr_pizza_type);
					}

					else
					{
						curr_pizza_type->pizza_type_next=NULL;
						pre_pizza_type->pizza_type_next=fwd_pizza_type;

						curr_pizza_type=fwd_pizza_type;
						fwd_pizza_type=curr_pizza_type->pizza_type_next;

						free(curr_pizza_type);
					}
				}

				pre_pizza_type=curr_pizza_type;
				curr_pizza_type=fwd_pizza_type;
			}


			view_number_of_pizza-=1;

			break;


		case 2:	printf("\n\nEnter the TYPE of the PIZZA to be removed:\t");
			fflush(stdin);
			gets(temp_type_name);

			printf("\n\nEnter the PIZZA NAME to be removed:\t");
			fflush(stdin);
			gets(temp_pizza_name);

			curr_pizza_type=preference_end->pizza_type_next;

			while(curr_pizza_type!=NULL)
			{
				if(!compare_strings(temp_type_name,curr_pizza_type->type))
				{
					curr_pizza=curr_pizza_type->pizza_next;

					while(curr_pizza!=NULL)
					{
						fwd_pizza=curr_pizza->pizza_next;

						if(!compare_strings(temp_pizza_name,curr_pizza->pizza_name))
						{
							if(curr_pizza==curr_pizza_type->pizza_next)
							{
								curr_pizza_type->pizza_next=curr_pizza->pizza_next;

								curr_pizza->pizza_next=NULL;

								free(curr_pizza);
							}

							else
							{
								curr_pizza->pizza_next=NULL;
								pre_pizza->pizza_next=fwd_pizza;

								curr_pizza=fwd_pizza;
								fwd_pizza=curr_pizza->pizza_next;
							}
						}

						pre_pizza=curr_pizza;
						curr_pizza=fwd_pizza;
					}
				}
			}

			break;
	}

}




void create_ud()
{
	int i=0;

	FILE *fp;

	fp=fopen("toppings.txt", "r");

	rewind(fp);

	while(!feof(fp))
	{
		x[i].sno=i+1;
		fscanf(fp, "%s%d", x[i].name, &x[i].price);
		i++;
	}

	fclose(fp);
}




void func_ud()
{
	int i, no;

	char ch;

	total_price_ud=0;

	do
	{
		printf("\n MAKE YOUR OWN PIZZA ");

		printf("\n\n Select Toppings from the list below: \n");

		for(i=0; i<12; i++)
		{
			printf("\n %d. %s - Rs %d ", x[i].sno, x[i].name, x[i].price);
		}

		printf("\n\n Enter the appropriate serial no: ");
		fflush(stdin);
		scanf("%d", &no);

		push_ud(no);

		printf("\n Do you want to add more topping? (y/n)");
		fflush(stdin);
		scanf("%c", &ch);

		clrscr();

	}while(ch!='n');

	while(top!=NULL)
	{
		total_price_ud=total_price_ud+pop_ud();
		user_defined_pizza_price=total_price_ud;
	}

	printf("\n\t Your Pizza Costs: Rs %d", total_price_ud);
	printf("\n\t Pizza Size      : MEDIUM ");

}





void push_ud(int no)
{
	int i;

	temp=(struct stack_ud *)malloc(sizeof(struct stack_ud));

	temp->t.sno=no;

	for(i=0; i<12; i++)
	{
		if(temp->t.sno==x[i].sno)
		{
			strcpy(temp->t.name, x[i].name);

			temp->t.price=x[i].price;

			break;
		}
	}

	temp->next=NULL;


	if(top==NULL)
	{
		top=temp;
	}

	else
	{
		temp->next=top;
		top=temp;
	}

	return;
}




int pop_ud()
{
	struct stack_ud *y;
	int p;

	y=top;

	p=y->t.price;

	top=top->next;

	free(y);

	return p;
}




void user_defined_pizza()
{
	int choice;

	clrscr();




	create_ud();

	func_ud();

	billing(200);

}




void create()
{
	int i;

	char ch;

	struct theme_pizza *temp,*p;


	FILE *fp;

	fp=fopen("Theme.txt", "r");

	for(i=1; i<=3; i++)
	{
		temp=(struct theme_pizza *)malloc(sizeof(struct theme_pizza));

		temp->priority=i;

		fgets(temp->theme_name, 25, fp);

		fgets(temp->pizza_name, 25, fp);

		fgets(temp->description, 256, fp);

		temp->link=NULL;

		if( theme_pizza_front==NULL || temp->priority < theme_pizza_front->priority )
		{
			theme_pizza_front=temp;
		}
		else
		{
			p = theme_pizza_front;

			while( p->link!=NULL && p->link->priority<=temp->priority )
			{
				p=p->link;
			}

			temp->link=p->link;

			p->link=temp;
		}
	}

	fclose(fp);
}




int priority()
{
	int x,month;



	month=input_date();

	x = (month % 3) + 1 ;

	return x;
}

void theme_pizza()
{
	int y,choice;

	clrscr();

	create();

	y=priority();

	display(y);

	printf("\n\nEXTRA LARGE SIZE");

	printf("\nPRICE -> 1000\n\n");

	printf("Press    |1|To ORDER THEME PIZZA    |0|To return to main menu\n:\t");

	scanf("%d",&choice);

	clrscr();

	if (choice==0)
	{
		view();
	}

	if (choice==1)
	{
		billing(100);
	}
}




void display(int p)
{
	int i;

	struct theme_pizza *c;

	c=theme_pizza_front;

	printf("\n Theme for the Current Month: ");

	for(i=1; i<=3; i++)
	{
		if(c->priority==p)
		{
			printf("\n\n THEME: %s \n\n PIZZA: %s \n\n DESCRIPTION: %s \n\n", c->theme_name, c->pizza_name, c->description);
			break;
		}

		else
		{
			c=c->link;
		}
	}
}





void login_1()
{
	char kat_pass[100],kat_id[100],aay_pass[100],aay_id[100],shr_pass[100],shr_id[100];
	char name[100],password[100];

	FILE *f_katyayn,*f_shruti,*f_aayush;




	f_katyayn=fopen("PizzaKat.dat","r");
	f_shruti=fopen("PizzaShr.dat","r");
	f_aayush=fopen("PizzaAay.dat","r");





	clrscr();
	textcolor(GREEN);
	gotoxy(18,7);
	cprintf("±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±");
	gotoxy(18,8);
	cprintf("±±");
	gotoxy(56,8);
	cprintf("±±");
	gotoxy(18,9);
	cprintf("±±");
	gotoxy(56,9);
	cprintf("±±");
	gotoxy(18,10);
	cprintf("±±");
	gotoxy(56,10);
	cprintf("±±");
	gotoxy(18,11);
	cprintf("±±");
	gotoxy(56,11);
	cprintf("±±");
	gotoxy(18,12);
	cprintf("±±");
	gotoxy(56,12);
	cprintf("±±");
	gotoxy(18,13);
	cprintf("±±");
	gotoxy(56,13);
	cprintf("±±");
	gotoxy(18,14);
	cprintf("±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±");
	gotoxy(21,9);
	cprintf("Enter user name :");
	gets(name);
	gotoxy(21,11);
	cprintf("Enter password  :");
	gets(password);


	fgets(kat_id,sizeof(kat_id),f_katyayn);
	fgets(kat_pass,sizeof(kat_pass),f_katyayn);

	fgets(aay_id,sizeof(aay_id),f_aayush);
	fgets(aay_pass,sizeof(aay_pass),f_aayush);

	fgets(shr_id,sizeof(shr_id),f_shruti);
	fgets(shr_pass,sizeof(shr_pass),f_shruti);


	if(compare_strings(name,kat_id)==0&&compare_strings(password,kat_pass)==0)
	{
		grant_access_1(1);
	}

	else if(compare_strings(name,aay_id)==0&&compare_strings(password,aay_pass)==0)
	{
		grant_access_1(1);
	}

	else if(compare_strings(name,shr_id)==0&&compare_strings(password,shr_pass)==0)
	{
		grant_access_1(1);
	}


	else
	{
		grant_access_1(0);
	}


	fclose(f_aayush);
	fclose(f_shruti);
	fclose(f_katyayn);

}


void grant_access_1(int grant)
{
	int i,j;

	clrscr();

	textcolor(LIGHTRED+BLINK);
	cprintf("\n\n\n\n\n\nVERIFYING  ");

	for(i=0;i<60;i++)
	{
		textcolor(RED);
		cprintf("±");
		delay(50);
	}

	if(grant==1)
	{

		clrscr();
		textcolor(LIGHTGREEN+BLINK);
		printf("\n\n\n\n\n\n\n\n\n\t\t\t\t");
		cprintf("±±±±±±±±±±±±±±±±±±±±±±");
		printf("\n\t\t\t\t");
		cprintf("±±                  ±±");
		printf("\n\t\t\t\t");
		cprintf("±± LOGIN SUCCESSFUL ±±");
		printf("\n\t\t\t\t");
		cprintf("±±                  ±±");
		printf("\n\t\t\t\t");
		cprintf("±±±±±±±±±±±±±±±±±±±±±±");

		clrscr();

		textcolor(YELLOW);



	}

	else
	{
		clrscr();

		textcolor(LIGHTRED+BLINK);
		printf("\n\n\n\n\n\n\n\n\n\t\t\t\t");
		cprintf("±±±±±±±±±±±±±±±±±±±±±±±±");
		printf("\n\t\t\t\t");
		cprintf("±±                    ±±");
		printf("\n\t\t\t\t");
		cprintf("±± LOGIN UNSUCCESSFUL ±±");
		printf("\n\t\t\t\t");
		cprintf("±±                    ±±");
		printf("\n\t\t\t\t");
		cprintf("±±±±±±±±±±±±±±±±±±±±±±±±");

		getch();
		login_1();

	}

	getch();

}







void billing(int no_of_loops)
{
	int size,i,choice,choice_pay;
	char theme_pizza_name[]="THEME PIZZA\n",theme_pizza_size[]="EXTRA LARGE\n",make_your_own_name[]="MAKE YOU OWN PIZZA\n",make_your_own_size[]="MEDIUM\n";
	int theme_pizza_price=1000,extra_discount=0,discount_choice;

	int VAT,service_charge,discounted_price,credit_discount;

	FILE *f_total_input;

	display_ud+=1;



	temp_bill_order=(struct bill_order*)malloc(sizeof(struct bill_order));
	temp_bill_order->bill_order_next=NULL;

	if(no_of_loops==100)
	{
		strcpy(temp_bill_order->bill_order_pizza,theme_pizza_name);
		strcpy(temp_bill_order->bill_order_size,theme_pizza_size);

		temp_bill_order->bill_order_price=theme_pizza_price;

		totalbill+=theme_pizza_price;
	}


	else if(no_of_loops==200)
	{
		strcpy(temp_bill_order->bill_order_pizza,make_your_own_name);
		strcpy(temp_bill_order->bill_order_size,make_your_own_size);

		temp_bill_order->bill_order_price=user_defined_pizza_price;

		totalbill=totalbill+user_defined_pizza_price;
		user_defined_pizza_price=0;
	}




	else
	{

		curr_pizza_size=curr_pizza_type->pizza_size_next;
		curr_pizza=curr_pizza_type->pizza_next;


		for(i=0;i<no_of_loops-1;i++)
		{
			curr_pizza=curr_pizza->pizza_next;
		}

		printf("\t\t\t BILLING\n\n");
		printf("Your Selected Pizza -> %s\n",curr_pizza->pizza_name);
		printf("\nSelect The Size You Want To Have :\n\n");
		printf("Press 1 For Small  :\n");
		printf("Press 2 For Medium :\n");
		printf("Press 3 For Large  :\n");
		printf("\n");
		printf("Enter Your Choice  :\t");

		scanf("%d",&size);

		for(i=0;i<size-1;i++)
		{
			curr_pizza_size=curr_pizza_size->pizza_size_next;

		}

		printf("\nYour Selected Pizza Size -> %s ",curr_pizza_size->size_name);

		totalbill=curr_pizza_size->price+totalbill;

		strcpy(temp_bill_order->bill_order_pizza,curr_pizza->pizza_name);
		strcpy(temp_bill_order->bill_order_size,curr_pizza_size->size_name);

		temp_bill_order->bill_order_price=curr_pizza_size->price;
	}


	if(start_bill_order==NULL)
	{
		start_bill_order=temp_bill_order;
		end_bill_order=temp_bill_order;
	}

	else
	{
		end_bill_order->bill_order_next=temp_bill_order;
		end_bill_order=temp_bill_order;
	}

	printf("\nPress |0| to RETURN to MENU  |1| to PAY and EXIT ");
	scanf("%d",&choice);

	if(choice==0)
	{
		view();
	}
	if(choice==1)
	{

		printf("\n\nEnter The mode of payment");
		printf("\nPress |1| for CASH");
		printf("\nPress |2| for CREDIT CARD\n:\t");
		scanf("%d",&choice_pay);

		if(choice_pay==1)
		{
			extra_discount=0;
		}

		if(choice_pay==2)
		{
			extra_discount=2;
		}

		clrscr();

		curr_bill_order=start_bill_order;

		printf("\t\t\t FINAL BILL\n\n");

		for(i=0;i<display_ud;i++)
		{

			puts(curr_bill_order->bill_order_pizza);
			puts(curr_bill_order->bill_order_size);
			printf("\t\t%d\n",curr_bill_order->bill_order_price);



			curr_bill_order=curr_bill_order->bill_order_next;
		}


		printf("\nTOTAL AMOUNT DUE     :\t\t%d",totalbill);
		printf("\n\nEnter DISCOUNT CODE or PRESS |0|:\t");
		scanf("%d",&discount_choice);

		if(discount_choice!=0)
		{

			login_1();

			discounted_price=totalbill*discount_choice/100;

			printf("\n\n\t\t\t\tDiscounted Bill:\t");
			printf("\nTOTAL AMOUNT DUE     :\t\t%d",totalbill);
			printf("\nDiscounted Amount    :\t\t%d",discounted_price);


		}


		VAT=totalbill*14/100;
		service_charge=totalbill*10/100;
		credit_discount=totalbill*extra_discount/100;



		printf("\n14 %% VAT            :\t\t%d",VAT);
		printf("\n10 %% SERVICE CHARGE :\t\t%d",service_charge);
		printf("\nCREDIT CARD DISCOUNT :\t\t%d\n",credit_discount);


		total_input=totalbill+VAT+service_charge-credit_discount-discounted_price;

		printf("\nTOTAL AMOUNT TO PAY  :\t\t%d",total_input);



		//ACCOUNTS


		f_total_input=fopen("PizzaInput.dat","w");

		fprintf(f_total_input,"%d",total_input);

		fclose(f_total_input);



		start_bill_order=NULL;

		display_ud=0;

		totalbill=0;

		getch();

		view();

	}


	getch();


}



void forward()
{
	int i,j=1,k,choice;
	clrscr();

	curr_pizza_size=NULL;


	printf("\t\t\t\t%s",curr_pizza_type->type);

	curr_pizza=curr_pizza_type->pizza_next;


	while(curr_pizza!=NULL)
	{

		if(curr_pizza_size==NULL)
		{
			curr_pizza_size=curr_pizza_type->pizza_size_next;

		}

		if(curr_pizza==NULL)
		{
			curr_pizza=curr_pizza_type->pizza_next;

		}
		printf("\nPizza:%d-> %s\n",j,curr_pizza->pizza_name);
		j++;


		curr_pizza_toppings=curr_pizza->pizza_toppings_next;

		for(k=0;k<2;k++)
		{
			printf("%s",curr_pizza_toppings->toppings);

			curr_pizza_toppings=curr_pizza_toppings->pizza_toppings_next;
		}

		printf("\n");

		printf("PRICE\t SIZE\n");

		for(i=0;i<3;i++)
		{
			printf("%d\t %s",curr_pizza_size->price,curr_pizza_size->size_name);

			curr_pizza_size=curr_pizza_size->pizza_size_next;
		}

		printf("\n");
		curr_pizza=curr_pizza->pizza_next;

	}
	printf("\nPress    |1|To order pizza:1    |2|To order pizza:2    |0|To return to main menu\n:\t");
	scanf("%d",&choice);

	clrscr();

	if (choice==0)
	{
		view();
	}

	if (choice==1)
	{
		billing(choice);
	}

	if (choice==2)
	{
		billing(choice);
	}
}


void view()
{

	int c,i,j=1,k=0,y;

	clrscr();

	curr=preference_end;

	printf("\t\t\t\t");
	puts(curr->preference);

	curr_pizza_type=curr->pizza_type_next;

	for(i=0;i<view_number_of_pizza;i++)
	{
		printf("%d -> %s\n",j,curr_pizza_type->type);
		curr_pizza_type=curr_pizza_type->pizza_type_next;
		j++;
		k++;
	}
	printf("%d -> THEME PIZZA\n\n",j);
	j++;

	printf("%d -> MAKE YOUR OWN PIZZA\n\n",j);
	j++;

	printf("%d -> ACCESS MANAGER MENU\n\n",j);
	j++;

	printf("%d -> EXIT\n",j);

	printf("\nEnter your CHOICE :\t");

	scanf("%d",&c);

	curr_pizza_type=curr->pizza_type_next;

	if(c==1)
	{
		forward();
	}

	else if(c==k+1)
	{
		theme_pizza();

	}
	else if(c==k+2)
	{
		user_defined_pizza();


	}

	else if(c==k+3)
	{
		login();
	}

	else if(c==k+4)
	{
		 exit(0);
	}


	else

	{
		for(i=1;i<c;i++)
		{
			curr_pizza_type=curr_pizza_type->pizza_type_next;
		}
		forward();
	}

	getch();
}



void accounts()
{
	int earnings,raw_material_price=1000,profit;

	FILE *f_total_input;

	f_total_input=fopen("PizzaInput.dat","r");

	clrscr();

	printf("\t\t\t ACCOUNTS SECTION\n\n");

	fscanf(f_total_input,"%d",&earnings);

	printf("\n\nTotal Earnings:\t%d",earnings);

	printf("\n\nAmount Spent on Raw Materials This year:\t%d",raw_material_price);

	profit=earnings-raw_material_price;

	printf("\n\nCurrent Profit:\t%d",profit);


	fclose(f_total_input);

	getch();
}





int emp_compare_strings(char a[], char b[])
{
	int i,flag=1;
	for(i=0;i<(strlen(a));i++)
	{
		if(a[i]==b[i])
		{
		 flag=0;
		}
		else
		{
		 flag=1;
		 break;
		}
	}
 return flag;
}

void emp_create()
{
	int i, j;
	struct emp_stack *t1, *t2, *t3, *c1, *c2, *c3;
	FILE *fm, *fo, *fd, *fc;
	fm=fopen("Managers.txt", "r");
	m=(struct emp_manager **)malloc(sizeof(struct emp_manager *)*3);
	for(i=0; i<3; i++)
	{
		fscanf(fm, "%s", m[i]->name);
		fscanf(fm, "%d%d", &m[i]->age, &m[i]->salary);
		for(j=0; j<3; j++)
			m[i]->link[j]=NULL;
	}
	fclose(fm);

	fo=fopen("Order.txt", "r");
	for(j=0; j<2; j++)
	{
		t1=(struct emp_stack *)malloc(sizeof(struct emp_stack));
		fscanf(fo, "%s", t1->name);
		fscanf(fo, "%d%d", &t1->age, &t1->salary);
		t1->next=NULL;
		if(order_top==NULL)
		 {
			order_top=t1;
		 }
		else
		{
			c1=order_top;
			while(c1->next!=NULL)
				c1=c1->next;
			c1->next=t1;
		}
	}
	fclose(fo);

	fd=fopen("Delivery.txt", "r");
	for(j=0; j<4; j++)
	{
		t2=(struct emp_stack *)malloc(sizeof(struct emp_stack));
		fscanf(fd, "%s", t2->name);
		fscanf(fd, "%d%d", &t2->age, &t2->salary);
		t2->next=NULL;
		if(delivery_top==NULL)
		{
			delivery_top=t2;
		}
		else
		{
			c2=delivery_top;
			while(c2->next!=NULL)
				c2=c2->next;
			c2->next=t2;
		}
	}
	fclose(fd);

	fc=fopen("Chef.txt", "r");
	for(j=0; j<2; j++)
	{
		t3=(struct emp_stack *)malloc(sizeof(struct emp_stack));
		fscanf(fc, "%s", t3->name);
		fscanf(fc, "%d%d", &t3->age, &t3->salary);
		t3->next=NULL;
		if(chef_top==NULL)
		{
			chef_top=t3;
		}
		else
		{
			c3=chef_top;
			while(c3->next!=NULL)
				c3=c3->next;
			c3->next=t3;
		}
	}
	fclose(fc);

	for(i=0; i<3; i++)
	{
		m[i]->link[0]=order_top;
		m[i]->link[1]=delivery_top;
		m[i]->link[2]=chef_top;
	}
}

void emp_login( char user_id[25] )
{
	int i, j, c=0;
	struct emp_stack *e;
	for(i=0; i<3; i++)
	{
		if(emp_compare_strings(user_id, m[i]->name)==0)
		{
			emp_manager(m[i]);
			c=1;
			break;
		}
	}

	for(j=0; j<3; j++)
	{
		e=m[0]->link[j];
		while(e!=NULL)
		{
			if(emp_compare_strings(user_id, e->name)==0)
			{
				emp_employee(e);
				c=1;
				break;
			}
			else
			{
				e=e->next;
			}
		}
	}
	if(c!=1)
	{
		printf("\n Invalid User ID! ");
	}
	return;
}

void emp_manager(struct emp_manager *mm)
{
	int ch;
	int c;
	struct emp_stack *temp, *top;
	time_t t;
	clrscr();
	do
	{
		time(&t);
		printf("\n \t\t\t SAK PIZZA - Manager ");
		printf("\n Welcome! ");
		printf("\n %s \n", ctime(&t));
		printf("\n 1. View Personal Details ");
		printf("\n 2. View Employee Details ");
		printf("\n 3. Hire an Employee ");
		printf("\n 4. Fire an Employee ");
		printf("\n 5. Exit \n");
		printf("\n Enter your choice(1-5): ");
		scanf("%d", &ch);

		if(ch==1)
		{
			printf("\n\n \t\t\t PERSONAL DETAILS \n");
			printf("\n NAME: %s", mm->name);
			printf("\n AGE: %d", mm->age);
			printf("\n SALARY: Rs %d", mm->salary);
			getch();
		}
		else if(ch==2)
		{
			printf("\n\n \t\t\t EMPLOYEE DETAILS \n");
			printf("\n Select Department (1-3): \n");
			printf("\n 1. Order ");
			printf("\n 2. Delivery ");
			printf("\n 3. Kitchen \n");
			scanf("%d", &c);
			temp=mm->link[c-1];
			while(temp!=NULL)
			{
				printf("\n NAME: %s", temp->name);
				printf("\n AGE: %d", temp->age);
				printf("\n SALARY: %d", temp->salary);
				temp=temp->next;
			}
			getch();
		}

		else if(ch==3)
		{
			printf("\n\n \t\t\t HIRE AN EMPLOYEE \n");
			printf("\n Select Department (1-3): \n");
			printf("\n 1. Order ");
			printf("\n 2. Delivery ");
			printf("\n 3. Kitchen \n");
			scanf("%d", &c);
			top=mm->link[c-1];
			emp_push(top);
			printf("\n Hired! ");
			getch();
		}

		else if(ch==4)
		{
			printf("\n\n \t\t\t FIRE AN EMPLOYEE \n");
			printf("\n Select Department (1-3): \n");
			printf("\n 1. Order ");
			printf("\n 2. Delivery ");
			printf("\n 3. Kitchen \n");
			scanf("%d", &c);
			top=mm->link[c-1];
			if(top!=NULL)
				emp_pop(top);
			getch();
		}
		delay(1000);
		clrscr();
	}while(ch!=5);
}

void emp_push(struct emp_stack *top)
{
	struct emp_stack *emp, *p;
	emp=(struct emp_stack *)malloc(sizeof(struct emp_stack));
	printf("\n Enter the details of new emp_employee: \n");
	printf("\n NAME: ");
	scanf("%s", emp->name);
	printf("\n AGE: ");
	scanf("%d", &emp->age);
	printf("\n SALARY: ");
	scanf("%d", &emp->salary);
	emp->next=NULL;
	if(top==NULL)
	{
		top=emp;
	}
	else
	{
		p=top;
		while(p->next!=NULL)
			p=p->next;
		p->next=emp;
	}
}

void emp_pop(struct emp_stack *top)
{
	struct emp_stack *p, *c;
	p=top;
	while(p->next!=NULL)
	{
		c=p;
		p=p->next;
	}
	c->next=NULL;
	printf("\n %s is fired! ", p->name);
	free(p);
}

void emp_employee(struct emp_stack *ee)
{
	int ch;
	time_t t;
	clrscr();
	do
	{
		time(&t);
		printf("\n \t\t\t SAK PIZZA - Employee ");
		printf("\n Welcome, %s ", ee->name);
		printf("\n %s \n", ctime(&t));
		printf("\n 1. View Personal Details ");
		printf("\n 2. Exit \n");
		printf("Enter your choice (1-2): ");
		fflush(stdin);
		scanf("%d", &ch);
		if(ch==1)
		{
			printf("\n\n \t\t\t PERSONAL DETAILS \n");
			printf("\n NAME: %s", ee->name);
			printf("\n AGE: %d", ee->age);
			printf("\n SALARY: Rs %d", ee->salary);
			getch();
		}
		delay(1000);
		clrscr();
	}while(ch!=2);
}


void emp_main()
{
	char uid[25];
	clrscr();
	emp_create();
	printf("\n Enter User ID: ");
	scanf("%s", uid);
	emp_login(uid);
	getch();
}



