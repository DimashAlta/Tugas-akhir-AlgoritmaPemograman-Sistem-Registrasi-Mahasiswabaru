#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

void mahasiswabaru();
void datamahasiswabaru();
void caridata();
void editdata();
void hapusdata();
int urutkandata();

struct mahasiswa
{
    char nama_lengkap[255];
    int no_pendaftaran;
    char prodi[50];
    char alamat[255];
    int nilaisiswa;
};
typedef struct siswaterdaftar
{
    int nim;
    char nama[100];
    int nilai;
}siswaterdaftar;

siswaterdaftar mhs[100001];

void fill_data(siswaterdaftar *mhs, int size){
    for(int i = 0; i < size; i++){
        printf("Data Mahasiswa ke-%d\n", i + 1);
        printf("NIM       : ");
        scanf("%d", &mhs[i].nim);

        printf("Nama      : ");
        fgets(mhs[i].nama,50,stdin);
        fgets(mhs[i].nama,50,stdin);

        printf("Nilai     : ");
        scanf("%d", &mhs[i].nilai);
        printf("\n");
    }
    printf("input berhasil");
}
void swap(siswaterdaftar *a, siswaterdaftar *b){
    siswaterdaftar temp = *a;
    *a = *b;
    *b = temp;
}
void sort_nim(siswaterdaftar *mhs, int n){
    int i, j;
    for(i = 0; i < n - 1; i++)
    for(j = 0;j < n - i - 1; j++)
    if(mhs[j].nim > mhs[j + 1].nim)
    swap(&mhs[j],&mhs[j + 1]);
}
void sort_nama(siswaterdaftar *mhs, int n){
    int i, j;
    for(i = 0; i < n - 1; i++)
    for(j = 0;j < n - i - 1; j++)
    if(strcmp(mhs[j].nama,mhs[j + 1].nama) > 0)
    swap(&mhs[j],&mhs[j + 1]);
}
void sort_nilai(siswaterdaftar *mhs, int n){
    int i, j;
    for(i = 0; i < n - 1; i++)
    for(j = 0; j < n-i-1; j++)
    if(mhs[j].nilai < mhs[j + 1].nilai)
    swap(&mhs[j],&mhs[j + 1]);
}
void tampil_data(siswaterdaftar *data, int size){
    for(int i = 0; i < size; i++){
        printf("Data mahasiswa ke-%d\n", i + 1);
        printf("NIM        : %d\n", data[i].nim);
        printf("Nama       : %s", data[i].nama);
        printf("Nilai      : %d\n", data[i].nilai);
        printf("\n");
    }
    printf("\n");
}
int urutkandata(){
    int size, pilih, c, choice;
    printf("============================================\n");
    printf("masukan jumlah mahasiswa : ");
    scanf("%d", &size);
    printf("============================================\n");
    fill_data(mhs, size);
    do{
        printf("\n======================================\n");
        printf("urutkan mahasiswa berdasarkan\n1.NIM\n2.Nama\n3.Nilai\n");
        printf("Pilih : ");
        scanf("%d", &pilih);
        switch (pilih)
        {
        case 1 :
            printf("=============================================\n");
            printf("Mengurutkan data berdasarkan NIM (Ascending) \n");
            sort_nim(mhs,size);
            tampil_data(mhs,size);
            break;
        case 2 :
            printf("==============================================\n");
            printf("Mengurutkan data berdasarkan NAMA (Ascending) \n");
            sort_nama(mhs,size);
            tampil_data(mhs,size);
            break;
        case 3 :
            printf("==============================================\n");
            printf("=================== RANKING ==================\n");
            sort_nilai(mhs,size);
            tampil_data(mhs,size);
            break;

            default:
            break;
        }
        printf("\nDO YOU WANT TO CONTINUE ? (pres 1 for 'yes') = ");
        scanf("%d", &c);
    }while (c == 1);
    getchar();
    return 0 ;
}
void main(){
   int pilih;
   char user[10],pass[10];
   printf("\t\t==== SELAMAT DATANG DI ITTS SURABAYA ====\n");
   printf("\n\n");
   printf("\t\t\t=== Opsi Menu ===\n");
   printf("\n");
   printf("\t\t\tAnda Masuk Sebagai :");
   printf("\n\t\t\t1.Admin kampus\n\t\t\t2.Siswa baru\n\t\t\t3.Exit\n");
   printf("\n");
   printf("== Masukkan Pilihan :  ");
   scanf("%d", &pilih);
   if (pilih==1){
printf("\n\n");
   printf("masukkan username:  ");
   scanf("%s",&user);
   printf("\n");
   printf("masukkan password:  ");
   scanf("%s",&pass);
   printf("\n\n\n");

   if((strcmp(user,"admin")==0)&&(strcmp(pass,"ittsadmin")==0)){
    while(pilih!=5){
        printf("\t\t\t=====SISTEM REGISTRASI MAHASISWA BARU====\n");
        printf("\n\n");
        printf("\t\t   1. siswa terdaftar\n");
        printf("\t\t   2. cari siswa\n");
        printf("\t\t   3. perbarui data mahasiswa\n");
        printf("\t\t   4. hapus data mahasiswa\n");
        printf("\t\t   5. urutkan data mahasiswa terdaftar\n");
        printf("\t\t   6. keluar\n");
        printf("\t\t   ========================================\n");
        printf("\t\t   ");
        scanf("%d",&pilih);

       
       switch(pilih){

        case 1:
        datamahasiswabaru();
        printf("\t\t\t\tPress any key to exit\n");
        getch();
        break;
        
        case 2:
        caridata();
        printf("\n\t\t\t\t  Press any key to exit.......\n");
        getch();
        break;

        case 3:
        editdata();
        printf("\n\t\t\t\t  Press any key to exit.......\n");
        getch();
        break;

        case 4:
        hapusdata();
        printf("\n\t\t\t\t   Press any key to exit.......\n");
        getch();
        break;

        case 5:
        urutkandata();
        printf("\n\t\t\t\t   Press any key to exit.......\n");
        getch();
        break;

        case 6:
        printf("\t\t\t==== Terima Kasih ====\n\n");
        main();
        getch();
        break;
       
       


         


  
        
       }
    }
}else{
    printf("username dan password salah");
}
}else if(pilih == 2){
            do{
                printf("\t\t\t=== Menu Pilihan ===\n");
                printf("\n");
                printf("\t\t1.registrasi mahasiswa baru\n\t\t2.perbarui biodata\n\t\t3.keluar\n");
                printf("Pilihan : ");
                scanf("%d",&pilih);
                switch (pilih)
                {
                case 1:
                mahasiswabaru();
                break;
                
                case 2:
                editdata();
                printf("\t\t\t\tPress any key to exit\n");
                getch();
                break;
                case 3:
                printf("\t\t==== terima kasih telah mendaftar ====\n\n");
                main();
                break; 

                }
            }while (pilih != 3);

        }

}

void mahasiswabaru(){
    char another;
    FILE *fp;
    struct mahasiswa info;

    do{
        printf("\t\t\t\t======Tambahkan Data Mahasiswa======\n\n\n");
        fp=fopen("datamahasiswa.txt","a");
        printf("\n\t\t\tMasukkan nama lengkap : ");
        fflush(stdin);
        scanf("%[^\n]s",&info.nama_lengkap);
        printf("\n\t\t\tMasukkan no pendaftaran : ");
        scanf("%d",&info.no_pendaftaran);
        printf("\n\t\t\tMasukkan prodi : ");
        scanf("%s",&info.prodi);
        printf("\n\t\t\tMasukkan alamat : ");
        fflush(stdin);
        scanf("%[^\n]s",&info.alamat);
        printf("\n\t\t\tMasukkan nilai : ");
        scanf("%d",&info.nilaisiswa);
        printf("\n\t\t\t___________________________\n");

        if(fp==NULL){
            fprintf(stderr,"\t\t\tTidak dapat dibuka\n");
        }else{
            printf("\t\t\tData mahasiswa dapat dibuka\n");
        }
        fwrite(&info,sizeof(struct mahasiswa), 1, fp);
        fclose(fp);

        printf("\t\tApakah kamu mau melakukan registrasi lagi ?(y\n)");
        scanf("%s",&another); 
    }while(another=='y'||another=='Y');
    printf("\t\t\tregistrasi telah berhasil,terimaksih\n\n");
}
void datamahasiswabaru(){
        FILE *fp;
        struct mahasiswa info;
        fp=fopen("datamahasiswa.txt","r");

        printf("\t\t\t\t======Data Mahasiswa Baru======\n\n\n");

        if(fp==NULL){
            fprintf(stderr,"\t\t\t\tTidak dapat dibuka\n");
        }else{
            printf("\t\t\t\tterdaftar\n");
            printf("\t\t\t\t_____________\n\n");
        }
        while(fread(&info,sizeof(struct mahasiswa), 1, fp)){
            printf("\n\t\t\t\tNama mahasiswa : %s",info.nama_lengkap);
            printf("\n\t\t\t\tNo pendaftaran : %d",info.no_pendaftaran);
            printf("\n\t\t\t\tProdi          : %s",info.prodi);
            printf("\n\t\t\t\tAlamat         : %s",info.alamat);
            printf("\n\t\t\t\tNilai          : %d",info.nilaisiswa);
            printf("\n\t\t\t\t______________________________________\n");
        }
        fclose(fp);
        getch();
    
};
void caridata(){
        struct mahasiswa info;
        FILE *fp;
        int no_pendaftaran,found=0;
        fp=fopen("datamahasiswa.txt","r");

        printf("\t\t\t\t======Cari mahasiswa======\n\n\n");
        printf("\t\t\tmasukkan no pendaftaran  : ");
        scanf("%d",&no_pendaftaran);

        while(fread(&info,sizeof(struct mahasiswa), 1, fp)){
            if(info.no_pendaftaran==no_pendaftaran){
            found=1;
            printf("\n\t\t\t\tNama mahasiswa : %s",info.nama_lengkap);
            printf("\n\t\t\t\tNo pendaftaran : %d",info.no_pendaftaran);
            printf("\n\t\t\t\tProdi          : %s",info.prodi);
            printf("\n\t\t\t\tAlamat         : %s",info.alamat);
            printf("\n\t\t\t\tNilai          : %d",info.nilaisiswa);
            printf("\n\t\t\t\t______________________________________\n");
         }
        }

        if(!found){
            printf("\n\t\t\tData tidak ada\n");
        }
        

        fclose(fp);
        getch();
}

void editdata(){
    struct mahasiswa info;
    FILE *fp;
    int no_pendaftaran,found=0;

    printf("\t\t\t\t======Edit Data Mahasiswa======\n\n\n");
    fp=fopen("datamahasiswa.txt","r");
    printf("\t\t\tmasukkan no pendaftaran  : ");
    scanf("%d",&no_pendaftaran);

      if(fp==NULL){
            fprintf(stderr,"\t\t\t\tTidak dapat dibuka\n");
      }
       while(fread(&info,sizeof(struct mahasiswa), 1, fp)){
            if(info.no_pendaftaran==no_pendaftaran){
            found=1;
         }else{
            fwrite(&info,sizeof(struct mahasiswa), 1, fp);
     }
   }
    

     if(found){
        printf("\t\t\t\t======Tambahkan Data Mahasiswa======\n\n\n");
        fp=fopen("datamahasiswa.txt","w+");
        printf("\n\t\t\tMasukkan nama lengkap : ");
        fflush(stdin);
        scanf("%[^\n]s",&info.nama_lengkap);
        printf("\n\t\t\tMasukkan no pendaftaran : ");
        scanf("%d",&info.no_pendaftaran);
        printf("\n\t\t\tMasukkan prodi : ");
        scanf("%s",&info.prodi);
        printf("\n\t\t\tMasukkan alamat : ");
        fflush(stdin);
        scanf("%[^\n]s",&info.alamat);
        printf("\n\t\t\tMasukkan nilai : ");
        scanf("%d",&info.nilaisiswa);
        printf("\n\t\t\t___________________________\n");
        printf("\t\t\tData mahasiswa telah diperbarui\n");
        }
        fwrite(&info,sizeof(struct mahasiswa), 1, fp);
        fclose(fp);
        if(!found){
            printf("\n\t\t\t\tData tak ditemukan");
        }
        fclose(fp);
        getch();
     }
void hapusdata(){
    struct mahasiswa info;
    FILE *fp, *fp1;

    int no_pendaftaran,found=0;

       printf("\t\t\t\t=======HAPUS DATA MAHASISWA=========\n\n\n");
    fp=fopen("datamahasiswa.txt","r");
    fp1=fopen("template.txt","w");
    printf("\t\t\t\tMasukkan no mahasiswa : ");
    scanf("%d",&no_pendaftaran);
    if(fp==NULL){
        fprintf(stderr,"file tidak bisa dibuka\n");
        
    }
    while(fread(&info,sizeof(struct mahasiswa),1,fp)){
        if(info.no_pendaftaran == no_pendaftaran){

            found=1;
        }else{
            fwrite(&info,sizeof(struct mahasiswa),1,fp1);
        }
    }
    fclose(fp);
    fclose(fp1);

    if(!found){
        printf("\n\t\t\t\tData tidak ditemukan\n");
    }
    if(found){
        remove("datamahasiswa.txt");
          rename("template.txt","datamahasiswa.txt");

          printf("\n\t\t\t\tData telah selesai dihapus\n");
    }
    fclose(fp);
    fclose(fp1);
    getch();
    
    }
    