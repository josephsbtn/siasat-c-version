#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Matkul
{
    char namaMatkul[100];
    char namaDosen[100];
    char kodeMatkul[10];
    int sks;
    int indexPilih;
} matkuls[10000], temp;

int jumlahMatkul = 0;
int matkulPilih = 0;

void deleteMatkul()
{
    char yangDihapus[100];
    char lnjut;
    int index;
    int check = 0;
    do
    {
        listMatkul();
        printf("MATA KULIAH YANG INGIN DIHAPUS :");
        scanf(" %[^\n]", yangDihapus);
        for (int i = 0; i < jumlahMatkul; i++)
        {
            printf("bjir");
            if (strcmp(matkuls[i].namaMatkul, yangDihapus) == 0)
            {
                check = 1;
                index = i;
                for (int j = index; j < jumlahMatkul; j++)
                {
                    matkuls[j] = matkuls[j + 1];
                }
                jumlahMatkul--;
                printf("BERHASIL DIHAPUS\n");
                getch();
                break;
            }
        }
        if (check == 0)
        {
            printf("mata kuliah tidak ditemukan");
            getch();
        }

        printf("Hapus lagi? (y/n) ");
        scanf("%c", &lnjut);
    } while (lnjut == 'y' || lnjut == 'Y');
}

void pilihMatkul()
{
    char matkulpilihan[100];
    char nambah;
    int check = 0;
    do
    {
        system("cls");
        printf("===========================\n");
        printf("-----Pilih Mata Kuliah-----\n");
        printf("===========================\n");
        listMatkul();
        printf("nama mata kuliah : ");
        scanf(" %s", &matkulpilihan);
        for (int i = 0; i < jumlahMatkul; i++)
        {
            if (strcmp(matkulpilihan, matkuls[i].namaMatkul) == 0)
            {
                check = 1;
                matkuls[i].indexPilih = i;
                matkulPilih++;
                printf("MATA KULIAH BERHASIL DI TAMBAH\n");
                getch();
                break;
            }
        }
        if (check == 0)
        {
            printf("MATA KULIAH TIDAK DITEMUKAN\n");
            getch();
        }
        printf("nambah lagi ga? (y/n)");
        scanf(" %c", nambah);

    } while (nambah == 'y' || nambah == 'Y');
}

void KST()
{

    printf("==========Kartu Studi Tetap==========\n");
    for (int i = 0; i < matkulPilih; i++)
    {
        int a = matkuls[i].indexPilih;
        printf("%d. %s   |   %s   |   %s   |   %d\n", i + 1, matkuls[a].namaMatkul, matkuls[a].namaDosen, matkuls[a].kodeMatkul, matkuls[a].sks);
    }
    getch();
}

void listMatkul()
{
    if (jumlahMatkul < 1)
    {
        printf("MATA KULIAH BELUM ADA YANG TERDAFTAR!!");
        getch();
    }
    else
    {
        printf("===============DAFTAR MATA KULIAH===============\n");
        printf("    Kode Matkul | Nama Matkul | Nama Dosen | SKS\n");
        for (int i = 0; i < jumlahMatkul; i++)
        {
            printf("%d. %s \t| %s |\t %s \t|\t %d \n", i + 1, matkuls[i].kodeMatkul, matkuls[i].namaMatkul, matkuls[i].namaDosen, matkuls[i].sks);
        }
        getch();
    }
}

void addMatkul()
{
    char lanjut;
    do
    {
        system("cls");

        printf("---INPUT DATA MATA KULIAH---\n");
        printf(" Nama mata kuliah : ");
        scanf(" %[^\n]", &matkuls[jumlahMatkul].namaMatkul);

        printf(" Nama Dosen : ");
        scanf(" %[^\n]", &matkuls[jumlahMatkul].namaDosen);

        printf(" Kode mata kuliah : ");
        scanf(" %s", &matkuls[jumlahMatkul].kodeMatkul);

        int check = strlen(matkuls[jumlahMatkul].kodeMatkul);
        if (check < 5)
        {
            printf("SALAH ISI CUY (cnth : TC555)");
            getch();
        }
        else
        {
            printf(" SKS : ");
            scanf("%d", &matkuls[jumlahMatkul].sks);
            jumlahMatkul++;
        }
        printf("nambah lagi nda? (y/n)");
        scanf(" %c", &lanjut);
    } while (lanjut == 'y' || lanjut == 'Y');
}

void menuGuest()
{
    char choice;
    do
    {
        system("cls");
        printf("=====SIASAT=====\n");
        printf("Nama : Joseph Sebastian\n");
        printf("NIM : 672023095\n");
        printf("================\n");
        printf("1. List Mata kuliah \n");
        printf("2. Pilih Mata Kuliah\n");
        printf("3. Liat KST \n");
        printf("4. LOG OUT\n");
        printf("choice :");
        scanf(" %c", &choice);

        switch (choice)
        {
        case '1':
            system("cls");
            listMatkul();
            break;
        case '2':
            system("cls");
            pilihMatkul();
            break;
        case '3':
            system("cls");
            KST();
        default:
            break;
        }
    } while (choice != '4');
}

void menuAdmin()
{
    char milih;
    do
    {
        system("cls");
        printf("================================\n");
        printf("\t KELOLA MATKUL \n");
        printf("================================\n");
        printf("Selamat Datang ADMIN\n\n");
        printf("TOTAL MATKUL : %d\n", jumlahMatkul);
        printf("LIST :\n");
        printf("1. liat list matkul\n");
        printf("2. Add matkul \n");
        printf("3. hapus matkul\n");
        printf("4.  LOG OUT\n");
        printf("milih cuy : ");
        scanf("%c", &milih);

        switch (milih)
        {
        case '1':
            system("cls");
            listMatkul();
            break;
        case '2':
            system("cls");
            addMatkul();
            break;
        case '3':
            system("cls");
            deleteMatkul();

        default:
            break;
        }
    } while (milih != '4');
}

void login()
{
    char username[100];
    char password[100];
    int check;
    do
    {
        system("cls");
        printf("=====LOGIN===== \n");
        printf("Username : ");
        scanf("%s", &username);
        printf("Password : ");
        scanf("%s", &password);

        if (strcmp(username, "admin") == 0 && strcmp(password, "admin") == 0)
        {
            menuAdmin();
            check = 1;
            system("cls");
        }
        else if (strcmp(username, "joseph") == 0 && strcmp(password, "095") == 0)
        {
            menuGuest();
            check = 1;
            system("cls");
        }
        else
        {
            check = 0;
            printf("Password / Username salah\n");
        }

    } while (check == 0);
}

int main(int argc, char const *argv[])
{
    char pilihan;
    do
    {
        system("cls");
        printf("=====================\n");
        printf("-----SIASAT HOME-----\n");
        printf("=====================\n");
        printf("1. login\n");
        printf("2. Exit \n");
        printf("masukan pilihan : ");
        scanf(" %c", &pilihan);
        switch (pilihan)
        {
        case '1':
            login();
            break;
        case '2':
            exit(0);
            break;
        default:
            printf("PILIHAN E GA ONO\n");
            break;
        }

    } while (pilihan != '2');

    return 0;
}
