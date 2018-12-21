/*
Program Antrian Pembuatan Paspor
Kelompok 2
Oleh		: 	Andri Rahadian Fikri 	(1706104501)
				Iqbal Fadlli B.			(1706104546)
Link Github	:	https://github.com/rahadiandri/AntrianPaspor
*/
#include <stdio.h>			//Daftar-daftar library yang dipakai
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include"paspor.h"

typedef struct{					//typedef digunakan untuk memberikan alias/nama baru pada sebuah tipe data
            int data[100];char data1[100][20];
            char data2[100][30];
            int depan;int belakang;}
Queue;Queue antrian;Queue noktp;Queue nama;			//nama-nama baru tipe data

int pilihan, data, i, j,n;
char data1[20], data2[30], data3[30];	//variabel penyimpan sementara data pendaftar

int antrianKosong(){
    if (antrian.belakang==-1)
        return 1;
    else
        return 0;}
        
int antrianTerisi(){
    if(antrian.belakang==100)
        return 1;
    else
        return 0;}

void Enqueue(int data, char data1[20], char data2[30]){
    if(antrianKosong()==1){
        antrian.depan=antrian.belakang=0;
        nama.depan=nama.belakang=0;
    	noktp.depan=noktp.belakang=0;
        antrian.data[antrian.belakang]=data;
        for(i=0;i<20;i++){
            nama.data1[nama.belakang][i]=data1[i];}
        for(i=0;i<15;i++){
			noktp.data2[noktp.belakang][i]=data2[i];}
        printf("\n\t\t\t\t\t    ======DATA TERSIMPAN===== ");   
        jadwal(data);delay(3000);}     
    else if(antrianTerisi()==0){
        antrian.belakang++;
        nama.belakang++;
        noktp.belakang++;             
        antrian.data[antrian.belakang]=data;
        for(i=0;i<20;i++){
		    nama.data1[nama.belakang][i]=data1[i];}
        for(i=0;i<15;i++){
            noktp.data2[noktp.belakang][i]=data2[i];}
    	printf("\n\t\t\t\t\t    ======DATA TERSIMPAN===== ");
		jadwal(data);delay(3000);}}
		
int Dequeue(){
    if(antrianKosong()==0){
        int i,e ;char a[20], b[30];
        e=antrian.data[antrian.depan];
        for(i=0;i<20;i++){
            a[i]=nama.data1[nama.depan][i];}
            
        for(i=antrian.depan;i<antrian.belakang;i++){
            antrian.data[i]=antrian.data[i+1];
            for(j=0;j<20;j++){
				nama.data1[i][j]=nama.data1[i+1][j];}
            for(j=0;j<15;j++){
				noktp.data2[i][j]=noktp.data2[i+1][j];}}
        antrian.belakang--;
        nama.belakang--;
        noktp.belakang--;
		kop();
		printf("\n\t\t\t\tAntrian %i dengan nama %s\n", e, a);
		printf("\n\t\t\t\tSilahkan masuk counter rekam data!\n\n\n");delay(3000);
        return e;
        return a[20];}
    else{
        kop();
		printf("\n\n\n\n\n\n\t\t\t\t\t  ======ANTRIAN KOSONG===== ");}
}

void buat(){
    antrian.depan=antrian.belakang=-1;
    nama.depan=nama.belakang=-1;
    noktp.depan=noktp.belakang=-1;
}

void fullscreen()
{
	keybd_event(VK_MENU,0x38,0,0);
	keybd_event(VK_RETURN,0x1c,0,0);
	keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
	keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}   
 
int main(){
	fullscreen();system("color B0");system("mode 81, 20");				//warna tulisan,warna background,ukuran layar output
	int but=1;int butmax=7;unsigned char ch;int n;int a=1;buat();
	judul();delay(1000);system("CLS");
	back:
	while(but!=-1){
		if(but>butmax){
			but=1;} 										//nilai but berputar dari 1 ke 4 dan kembali lagi ke 1
		else if(but<1){
			but=butmax;}							
			system("CLS");menu(but);ch=getch();
		if (ch==0){											//initial read input char dari keyboard
			ch=getch();} 
		if (ch==72){										//decrement nilai button bila ditekan panah ke atas
			but--;}
		else if (ch==80){									//increment nilai button bila ditekan panah ke bawah
			but++;}		  
		if(ch==77){											//memilih opsi bila ditekan panah kanan
			system("CLS");
		switch (but){
            case 1 :
				system("CLS");kop();
				printf("\n\t\t\t\tAntrian			: %i\n", a);data=a;
                printf("\n\t\t\t\tNama Lengkap		: "); scanf("%[^\n]",&data1);fflush(stdin);
				printf("\n\t\t\t\tNomor KTP		: "); scanf("%s",&data2);fflush(stdin);
                savefile(data,data1,data2);
				Enqueue(data, data1, data2);a++;break;
            case 2 :
                system("CLS");
				Dequeue();delay(1000);break;
	        case 3 :	
				system("CLS");
                if(antrianKosong()==1){
                    kop();
					printf("\n\n\n\n\n\n\t\t\t\t\t  ======ANTRIAN KOSONG===== ");delay(2000);break;}
                kop();
				puts("\nAntrian	Nomor KTP	Nama		Jadwal rekam id");
                for(i=antrian.depan;i<=antrian.belakang;i++){
                    printf("%i       	%s        %s  ", antrian.data[i], noktp.data2[i], nama.data1[i]);
                    n=antrian.data[i];cetak(n);}delay(2000);
                //buka data keseluruhan sumber dari file 
					int tombol=1,tombolmax=2;
					unsigned char ch;FILE *f;char s[5000];char c[1000];
					while(tombol!=-1){
						if(tombol>tombolmax){					//Kalau nilai tombol lebih dari max
							tombol=1;} 							//maka tombol berputar kembali lagi ke 1
						else if(tombol<1){						//Kalau tombol kurang dari 1
							tombol=tombolmax;}					//Tombol berputar ke opsi maksimum		
							system("cls");menureadfile(tombol);ch=getch();
						if (ch==0){								//initial read input char dari keyboard
							ch=getch();} 
						if (ch==72){							//decrement nilai button bila ditekan panah atas
							tombol--;}
						else if (ch==80){						//increment nilai button bila ditekan panah bawah
							tombol++;}		  
						if(ch==77){								//memilih opsi bila ditekan panah kanan
						system("CLS");
						switch (tombol){
							case 1: kop();printf("\nAntrian\t\tNama\tNomor KTP\n");
								    f=fopen("Pengajuan.txt", "r");
								    if(!f)
								    return 1;
								    while (fgets(s,1000,f)!=NULL) {	//Perintah untuk print isi kandungan Pengajuan.txt
								        printf("%s", s);
								    }
								    fclose(f);delay(2000);			//Delay close
									break;
							case 2 : goto back;break;
							}
						}		
					}getche();break;
            case 4 :
            	system("CLS");kop();
            	printf("\n\t\t Cari Data : ");scanf("%s",&data3);fflush(stdin);
            	search(data3);
				break;
            	
			case 5 :
				system("CLS");petunjuk();delay(2000);printf("\n\t\t\t\tTekan tombol apapun untuk melanjutkan..");
				getch();system("CLS");break;
			case 6 :
				system("CLS");judul();delay(2000);printf("\n\n\t\t\t\tTekan tombol apapun untuk melanjutkan..");
				getch();system("CLS");break;
			case 7 :
				kop();
				printf("\n\n\n\n\n\n\n\t\t\t\t\t  ======TERIMA KASIH===== ");delay(1000);exit(0);break;}
			}
	}
getche();
return 0;
}



