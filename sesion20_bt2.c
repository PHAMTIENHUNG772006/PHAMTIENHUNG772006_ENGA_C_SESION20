#include<stdio.h>
struct Store{
	int id;
	int sl;
	char name[50];
	float inputPrice;
	float outputPrice;
};
void addSt(struct Store st[],int size);
void displaySt(struct Store st[],int size);
void moreSt(struct Store st[],int size,int x);
int main(){
	int x;
	int size=0;
	int choice;
	struct Store st[100];
	do{
		printf("\n********MENU*******\n");
        printf("1. Nhap so luong va thong tin san pham\n");
        printf("2. hien thi thong tin san pham\n");
        printf("3. nhap san pham\n");
        printf("4. cap nhat thong tin san pham\n");
        printf("5. Sap xep san pham theo gia\n");
        printf("6. tim kiem san pham\n");
        printf("7. ban san pham\n");
        printf("8. Thoat\n");
        printf("Hay chon chuc nang (1-8): ");
        scanf("%d", &choice);
        switch(choice){
        	case 1:
        		printf("Moi ban nhap so luong san pham : ");
        		scanf("%d",&size);
        		addSt(st ,size);
        		break;
        	case 2:
        		displaySt(st,size);
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
        		return 0;
		}
	}while(choice != 8);
  return 0;
}
	void addSt(struct Store st[],int size){
	for(int i=0;i<size;i++){
		printf("Moi ban nhap thong tin san pham %d \n",i+1);
		printf("Ma san pham : ");
		scanf("%d", &st[i].id);
		fflush(stdin);
		printf("Ten san pham : ");
		fgets(st[i].name,sizeof(st[i].name),stdin);
		printf("So luong san pham: ");
        scanf("%d", &st[i].sl);
        printf("Gia nhap san pham:");
        scanf("%f", &st[i].inputPrice);
        printf("Gia ban san pham: ");
        scanf("%f", &st[i].outputPrice);
        getchar();
	}
}
	void displaySt(struct Store st[],int size){
	for(int i = 0;i < size;i++){
		printf("San phan %d :",i);
		printf("Ma san pham %d ", st[i].id);
		printf("Ten san pham %d ", st[i].name);
		printf("Gia san pham %d ", st[i].outputPrice);
		
	}
}
void moreSt(struct Store st[],int size,int x){
	printf("Moi ban nhap vi tri muon them so luong");
	scanf("%d",&x);
	if(x < 0 || x > size){
		printf("Vi tri ban nhap khong co trong cua hang");
	}
	for(int i=0;i<size;i++){
		x = st;
		printf("Them so luong san phan : ");
		scanf("%d", &st[i].sl);
		}
}
