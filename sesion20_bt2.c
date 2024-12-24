#include<stdio.h>
struct Store{
	int id,x;
	int sl;
	char name[50];
	float inputPrice;
	float outputPrice;
};
void addSt(struct Store st[],int size);
void displaySt(struct Store st[],int size);
void moreSt(struct Store st[],int size,int x);
int findProductIndexById(int id, int size, struct Store st[]);
void searchProduct(struct Store st[], int size);
void sellProduct(struct Store st[], int *size);
void sapXep(struct Store st[], int size, int choice);
void sapXep(struct Store *st, int size, int choice);
void editSt(struct Store *st, int *size, int x);
void showRevenue(int revenue);
int main(){
	int x;
	int revenue =0.0;
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
        printf("8. Doanh thu hien tai");
        printf("9. Thoat\n");
        printf("Hay chon chuc nang (1-9): ");
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
        		moreSt(st,&size,x);
        		break;
        	case 4:
        		editSt(&st,&size,x);
        		break;
        	case 5:
        		sapXep(st,size,choice);
        		break;
        	case 6:
        		searchProduct(st,&size);
        		break;
        	case 7:
        		sellProduct(st,&size);
        		break;
        	case 8:
        		showRevenue(revenue);
        		break;	
        	case 9:
        		printf("Da thoat chuong trinh");
        		break;
        	default:
        		return 0;
		}
	}while(choice != 9);
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
		int moreSl;
		printf("Them so luong san phan : ");
		scanf("%d", &moreSl);
		st[x].sl += moreSl;
}
int findProductIndexById(int id, int size, struct Store st[]) {
    for (int i = 0; i < size; i++) {
        if (st[i].id == id) {
            return i; 
        }
    }
    return -1;  
}

void searchProduct(struct Store st[], int size) {
    int id;
    printf("Nhap ma san pham can tim: ");
    scanf("%d", &id);

    int index = findProductIndexById(id, size, st);
    if (index != -1) {
        printf("Ma san pham: %d, Ten san pham: %s, Gia nhap: %.2f, Gia ban: %.2f, So luong: %d\n",
               st[index].id, st[index].name, st[index].inputPrice, st[index].outputPrice, st[index].sl);
    } else {
        printf("San pham khong ton tai.\n");
    }
}

void sellProduct(struct Store st[], int *size) {
    int id, quantity,revenue=0.0;
    printf("Nhap ma san pham can ban: ");
    scanf("%d", &id);

    int index = findProductIndexById(id, *size, st);
    if (index != -1) {
        printf("Nhap so luong can ban: ");
        scanf("%d", &quantity);

        if (quantity > st[index].sl) {
            printf("Khong con du hang.\n");
        } else {
            st[index].sl -= quantity;
            revenue += quantity * st[index].outputPrice;
            printf("Ban thanh cong. Doanh thu hien tai: %.2f\n", revenue);
        }
    } else {
        printf("San pham khong ton tai.\n");
    }
}

void showRevenue(int revenue) {
    printf("Doanh thu hien tai: %.2f\n", revenue);
}
void sapXep(struct Store *st, int size, int choice) {
    int sortChoice;
    printf("1. Sap xep tang dan\n");
    printf("2. Sap xep giam dan\n");
    printf("Hay chon chuc nang (1-2): ");
    scanf("%d", &sortChoice);

    switch (sortChoice) {
        case 1:
            for (int i = 0; i < size - 1; i++) {
                for (int j = i + 1; j < size; j++) {
                    if (st[i].outputPrice > st[j].outputPrice) {
                        struct Store temp = st[i];
                        st[i] = st[j];
                        st[j] = temp;
                    }
                }
            }
            displaySt(st, size);
            break;
        case 2:
            for (int i = 0; i < size - 1; i++) {
                for (int j = i + 1; j < size; j++) {
                    if (st[i].outputPrice < st[j].outputPrice) {
                        struct Store temp = st[i];
                        st[i] = st[j];
                        st[j] = temp;
                    }
                }
            }
            displaySt(st, size);
            break;
        default:
            printf("Du lieu sai, vui long nhap lai.\n");
    }
}
void editSt(struct Store *st, int *size, int x) {
    printf("Moi ban nhap vi tri sua (1-%d): ", *size);
    scanf("%d", &x);
    if (x < 1 || x > *size) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    printf("Nhap ten san pham moi: ");
    getchar();  
    fgets(st[x - 1].name, sizeof(st[x - 1].name), stdin);
    st[x - 1].name[strcspn(st[x - 1].name, "\n")] = 0; 
    printf("Nhap gia san pham moi: ");
    scanf("%f", &st[x - 1].outputPrice);
    printf("San pham moi da duoc sua o vi tri %d.\n", x);
}
