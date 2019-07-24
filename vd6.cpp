#include <stdio.h>
#include <stdlib.h>
struct sinhvien
{
	char name[30];
	int old;
	float score;
	struct sinhvien* next_ptr=NULL;
};

void setdata(struct sinhvien* data_ptr)
{
	printf("\nMoi ban nhap ten sv:");
	fflush(stdin);
	gets(data_ptr->name);
	printf("Moi ban nhap tuoi sv:");
	scanf("%d",&data_ptr->old);
	printf("Moi ban nhap diem trung binh cua sv:");
	scanf("%f",&data_ptr->score);
	data_ptr->next_ptr = NULL;
}

void getdata(struct sinhvien* data_ptr)
{
	printf("\n\tTen: %s",data_ptr->name);
	printf("\tTuoi: %d",data_ptr->old);
	printf("\tDTB %f",data_ptr->score);
}

struct sinhvien* insert(struct sinhvien* list)
{
	struct sinhvien* temp_ptr;
	temp_ptr = list;
	if(temp_ptr != NULL)
	{
		while(temp_ptr->next_ptr != NULL)
		{
			temp_ptr =temp_ptr->next_ptr;
		}
		temp_ptr->next_ptr = (struct sinhvien*)malloc(sizeof(struct sinhvien));
		setdata(temp_ptr->next_ptr);
	}
	else
	{
		temp_ptr = (struct sinhvien*)malloc(sizeof(struct sinhvien));
		setdata(temp_ptr);
		return temp_ptr;
	}
	return list;
}

void print_data(struct sinhvien* temp_ptr)
{
	if(temp_ptr != NULL)
	{
		getdata(temp_ptr);
		while(temp_ptr->next_ptr!= NULL)
		{
			temp_ptr = temp_ptr->next_ptr;
			getdata(temp_ptr);
		}
	}
	else
	{
		printf("\nDanh sach dang trong");
	}
}

int main()
{
	struct sinhvien* EP0519E = NULL;
	char sel;
	do
	{
		printf("\nChao mung su dung chuong trinh quan ly sinh vien");
		printf("\n-Bam 'p' de in danh sach sinh vien");
		printf("\n-Bam 'i' de them 1 sinh vien vao danh sach");
		printf("\n-Bam 'e' de thoat chuong trinh\n");
		fflush(stdin);
		scanf("%c",&sel);
		
		switch(sel)
		{
			case 'p':
				print_data(EP0519E);
				break;
			case 'i':
				EP0519E = insert(EP0519E);
				break;
			case 'e':
				printf("Good bye!!!");
				break;
		}
				
	}while(sel !='e');	
}
