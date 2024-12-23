#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Library {
	char id[20];
	char name[50];
	char author[50];
	float price;
};
void addBook(struct Library *book[100],int size);
int main(){
	char name[50];
	int size;
	int choice;
	char x;
	struct Library book[100];
	do{
		printf("*********MENU***********\n");
		printf("1.Moi ban nhap so luong va thong tin sach\n");
		printf("2.Hien thi thong tin sach \n");
		printf("3.them sach vao vi tri \n");
		printf("4.xoa sach theo ma \n");
		printf("5.cap nhat thong tin theo ma sach \n");
		printf("6.sap xep tang giam\n");	
		printf("7.tim kiem theo ten sach\n");
		printf("8.thoat\n");
		printf("Moi ban chon chuc nang tu 1-8 : ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("Moi ban nhap so luong sach : ");
				scanf("%d", &size);
//				fflush(stdin);
				addBook(book,size);
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				break;
				default:
					printf("du lieu sai ,hay nhap lai du lieu");
					return 0;
		}
	}while(choice !=8);
  return 0;
}
	addBook(struct Library *book[100],int size){
				for(int i=0;i<size;i++){
					fflush(stdin);
//					printf("Moi ban nhap thong tin sach so %d",i+1);
					printf("Ma sach : ");		
					getchar();
					fgets(book[i]->id,sizeof(book[i]->id),stdin);
//					book[i]->id[strcspn(book[i]->id, "\n")] = '\0';
					printf("Ten sach : ");
//					getchar();
					fgets(book[i]->name,sizeof(book[i]->name),stdin);
					printf("Ten tac gia : ");
					fgets(book[i]->author,sizeof(book[i]->author),stdin);
		}
	}
