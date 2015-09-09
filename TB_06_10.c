/*

+------------------------------------------------------------------------------------------+
|      ___         ___         ___         ___         ___         ___         ___         |
|     /__/\       /  /\       /__/\       /  /\       /__/\       /  /\       /__/\        |
|     \  \:\     /  /::\      \  \:\     /  /:/_     |  |::\     /  /::\      \  \:\       |
|      \__\:\   /  /:/\:\      \  \:\   /  /:/ /\    |  |:|:\   /  /:/\:\      \  \:\      |
|  ___ /  /::\ /  /:/~/::\ _____\__\:\ /  /:/_/::\ __|__|:|\:\ /  /:/~/::\ _____\__\:\     |
| /__/\  /:/\:/__/:/ /:/\:/__/::::::::/__/:/__\/\:/__/::::| \:/__/:/ /:/\:/__/::::::::\    |
| \  \:\/:/__\\  \:\/:/__\\  \:\~~\~~\\  \:\ /~~/:\  \:\~~\__\\  \:\/:/__\\  \:\~~\~~\/    |
|  \  \::/     \  \::/     \  \:\  ~~~ \  \:\  /:/ \  \:\      \  \::/     \  \:\  ~~~     |
|   \  \:\      \  \:\      \  \:\      \  \:\/:/   \  \:\      \  \:\      \  \:\         |
|    \  \:\      \  \:\      \  \:\      \  \::/     \  \:\      \  \:\      \  \:\        |
|     \__\/       \__\/       \__\/       \__\/       \__\/       \__\/       \__\/        |
|                                                                                          |
+------------------------------------------------------------------------------------------+

PENGGUNA
---------
Data pengguna disimpan didalam file eksternal user.db yang berisi:
- username pengguna
- highest score pengguna
- setting personal pengguna (tingkat kesulitan, dan state/kondisi
                             permainan terakhir pengguna)

HANG-MAN-USER-FILE
[username] [totscore] [difficulities] [state:Y/N] [state:word] [state:progress] [state:curscore]

PROSEDUR PERMAINAN
------------------
- Kata yang harus ditebak dipilih secara random berdasar tingkat kesulitan
  yang ditentukan oleh pengguna di menu settings.
- Kategori dapat dipilih sebelum pengguna memulai permainan. Tetapi
  juga terdapat kategori acak yang mengacak kategori kata yang akan
  dimainkan pengguna.
- Interface tebak kata dengan bantuan garis bawah. Tanda sambung dan
  spasi sudah ditampilkan untuk mempermudah pengguna.
- Terdapat prosedur Pencari posisi huruf pada kata
- Jika user salah input, akan digambar hangman, ada prosedur untuk
  menggambar hangman
- Kesempatan maksimal 8 kali kesalahan (skor 0), dengan penghitungan skor
  100 - S^2. Banyaknya kesalahan maks disimpan sebagai konstanta, dan skor
  dihitung menggunakan fungsi.
- Skor yang disimpan hanyalah skor tertinggi yang dicapai oleh user.
  Sistem perhitungan skor total adalah penjumlahan skor dari setiap
  game yang dimainkan (1 kata yg ditebak = 1 game).
- Program akan terus memberi kata baru sampai user menyatakan berhenti
- High score dimuat 10 skor tertinggi dengan tanggal pencapaian skor.
  Skor tertinggi disimpan di file eksternal hs.db yang berisi user peraih
  total skor serta tanggal pencapaian. Jika ada user dengan skor tertinggi
  yang sama, maka akan diurutkan berdasar username pengguna. Jika terdapat
  10 atau lebih skor tertinggi yang sama, tetap diurutkan berdasar username
  pengguna, dan hanya ditampilkan 10 saja.
- Karena terdapat Mode easy normal dan hard, perhitungan skor dihitung juga
  berdasar mode yang dipilih user. Cara perhitungan skor tetap sama yaitu
  100-S^2, namun jika memilih mode easy skor akhir akan dikalikan setengahnya
  sedangkan jika memilih mode hard, skor akhir akan dikalikan dengan dua.
- Panjang kata maksimal adalah 50 Kata. Disimpan sebagai konstanta program.
- Database kata disimpan dalam file eksternal, lalu dimuat dengan menggunakan
  dynamic array, sehingga indeks maksimal tabel ditentukan oleh program saat
  runtime berlangsung.

RANCANGAN SEDERHANA GAME
------------------------
1. MULAI PROGRAM
2. MENU UTAMA, terdiri dari
    a. MAIN SENDIRI
    b. BERDUA LEBIH ASIK
    c. HIGHSCORE
    d. BANTUAN?
    e. KELUAR

   a. MAIN SENDIRI
   ---------------
    Main sendiri adalah mode single player yang bersifat adventure.
    Terdapat sub menu:
        - NEW GAME
        - LOAD GAME
    Jika user memilih NEW GAME, user akan meregister username baru yang bersifat unik.
    Jika user memilih load game, user akan memulai game dengan kondisi:
      a. Game baru jika user memilih untuk memulai game baru
      b. Game lama jika user memilih untuk meneruskan kata yang sebelumnya sedang
         user tebak

    Pada permainan terdapat pause menu yang dapat user akses dengan menekan tombol Esc
    pada pause menu terdapat:
      a. Kembali ke Game
      b. Simpan Proses
      c. Ulang Game Baru
      d. Pengaturan Personal
      e. Menu Utama
      f. Keluar

   b. BERDUA LEBIH ASIK
   ---------------------
    Berdua lebih asik adalah mode multiplayer dengan dua pemain.
    Pada mode ini satu pengguna akan menginput kata yang harus ditebak oleh pengguna
    lainnya, kemudian setelah tertebak/kalah, pengguna satunya melakukan hal yang sama.
    Pada mode ini skor tetap dihitung, namun tidak disimpan ke highscore (mengantisipasi
    kecurangan untuk memperebutkan highscore).

    Pada permainan terdapat pause menu yang dapat user akses dengan menekan tombol Esc
    pada pause menu terdapat:
      a. Kembali ke Game
      b. Ulang Game Baru
      c. Menu Utama
      d. Keluar

   c. HIGHSCORE
   -------------
     Berisi highscore user

   d. BANTUAN
   -----------
     Berisi bantuan singkat bagaimana bermain game.

   e. KELUAR
   ---------
     keluar dari game


INTERFACE
---------
Lebar interface yang digunakan  : 80 char (WINDOWS CMD)
Panjang interface yang digunakan: 22 line (WINDOWS CMD)

  KONDISI IDEAL INTERFACE
  -----------------------
    Interface dibuat dengan menyesuaikan standar CMD Windows dengan pengaturan sbb:
        Font    :   Lucida Console 12pt
        Layout  :   Buffer W : 80
                    Buffer H : 25

                    Window W : 80
                    Window H : 25

Diasumsikan pengguna menggunakan microsoft windows dan menyesuaikan ukuran
window sesuai dengan interface program yang sudah ditentukan, sehingga
tampilan program akan diasumsikan baik (tidak terpengaruh size window dan resolusi pengguna).
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <windows.h> // WINDOWS ONLY

/////////////////////// KONSTANTA GLOBAL /////////////////////////

#define PANAH_UP 1
#define PANAH_DOWN 2
#define PANAH_LEFT 3
#define PANAH_RIGHT 4

#define BLACK 0,
#define DARK_BLUE 1
#define DARK_GREEN 2
#define TEAL 3
#define DARK_RED 4
#define DARK_PURPLE 5
#define GOLD 6
#define GREY 7
#define DARK_WHITE 8
#define BLUE 9
#define GREEN 10
#define CYAN 11
#define RED 12
#define PURPLE 13
#define YELLOW 14
#define WHITE 15

#define CLEARCMD "CLS"

#define MaxGagal 8
#define MaxHuruf 50
// SOAL BONUS, PENGGUNAAN ARRAY DINAMIK UNTUK MEMBUAT BATAS USER DINAMIS #define MaxUser 100

//typedef enum {FALSE, TRUE} BOOL;

//////////////////////////////////////  T I P E   B E N T U K A N////////////////////////////////////////
typedef struct {char Uname[25];
                int HS;
                int Gori;
                int ST;
                char STWrd[MaxHuruf];
                char STProg[27];
                int STScr;
                int STSlh;} USR; //user

typedef struct {int UID;
                char Tanggal[30];
                int Score;} HScr; // highscore

typedef char* HGM[8]; // hangman

typedef struct {int level;
                char Cat [MaxHuruf];
                char Quest[300];
                char Wrd[MaxHuruf];} WL; //word list

////////////////////////////////VARIABEL GLOBAL PENDUKUNG PERMAINAN//////////////////////////////////
WL * WList;
BOOL * WPlayed;
USR * user;

int TotUser;
int TotWord;
int ActiveUser = -1;

BOOL Login = FALSE;
HScr HiScore[10];
char WorkingDir[MAX_PATH];

///////////////////////////////////////DEKLARASI PROTOTIPE FUNGSI/////////////////////////////////

// 1. Fungsi yang berhubungan dengan interface program
        void setupinterface();
        void SetColor(const int foreground, const int background);
        void PrintKeluar();
        void PrintMenuUtama(int Menu);
        void PrintBantuan();
        void PrintMainSendiri(int Menu);
        void PrintNewGame (char* Username, char* errs, int CurPos);
        void PrintError(char* msg);
        void PrintHangman(int Salah, HGM Hangman);
        void PrintGame(char* usr, int skor, int level, char* cat, char quest[], char kata[], BOOL prgs[], int salah, char* msg);
        void PrintSingleSetup(int level, char* cat, int pos,BOOL NoCat, BOOL Err);
        void PrintHome(int Menu, int HS, char* tglHs, char* Uname);
        void PrintPauseSingle(int mPos);
        void PrintTawarSave(int Menu);
        void PrintGameFinished(BOOL Tamat, int Menu);
        void PrintTawarHS (int Menu, int mUrut, int Skor);
        void PrintGameOver(int Menu);
        void PrintUserList (int sCursor, int sPage, int TotPage, int TotUL , char UList[20][25]);
        void PrintMultiSetup(char* Username, int Player, char* errs, int CurPos);
        void PrintBuatPertanyaan(char* Username, int Skor, char* Pertanyaan, char* Jawaban, char* errs, int CurPos, int TexPos);
        void PrintGameMulti(char* usr, int skor , char quest[], char kata[], BOOL prgs[], int salah, char* msg);
        void PrintNoGame();
        void PrintGameOverMulti(int Menu, USR Winner, USR Loser);
        void PrintHighscore();
        void PrintPauseMulti(int mPos);
        void PrintDraw();
        BOOL TawarSaveHS(int UserID, int mUrut, int mSkor);
        void SimpanGameInterface(int UserID);
        void TawarSaveGame(int UserID);

    //2. Fungsi yang berhubungan dengan file eksternal
        void LoadWordUser(int UserID);
        void LoadWordList();
        void LoadUser();
        void SaveUser(BOOL NewUser, char* username, int HighScore, int Gori, int ST, char* STWrd, char* STProg, int CurScore, int Salah);
        int HowMuchLine(FILE* Fp);
        void ReloadCat(int level, char CAT[300][50]);
        void ProsesHighscore(int UserID, int Score);
        void LoadHighscore();

    //3. Fungsi pendukung lainnya
        inline void Logout();
        inline int HitungSkor(int Salah, int Level);
        int IntLen(int number);
        void PosisiHurufPadaKata(char Kata[MaxHuruf], char Huruf, int Posisi[]);
        void replace (char *string, char new_char, char old_char, int convert_flag);

//////////////////////////////////////////////////////////////////////////////////
////                            PROGRAM MAIN                                //////
////               DIKERJAKAN OLEH : ANDRE SUSANTO (16512246)               //////
//////////////////////////////////////////////////////////////////////////////////

int main() {
	// Konstanta untuk menu Program
    const int mmAwal = 1;
    const int mmAkhir = 5;
    const int msAwal = 1;
    const int msAkhir = 2;
    const int mpAwal = 1;
    const int mpAkhir = 6;

	// Variabel untuk mode single player
    const int MaxUsername = 24;
    BOOL NewUser = FALSE;
    int level;
    int Gori;
    int Remain;
    int PN;
    char Category[300][50];
    char tmp[50];
    char sPath[MAX_PATH];
    int mmPos = 1;
    int i,j;
    int CSkor;
    int ManyPages;
    int CPage;
    int UserInPage;
    char UserLoad[20][25];

	// Variabel untuk mode multiplayer
    USR MPlayer[2];
    int CurPlayer;
    int CurTex;
    int TexPos[3];
    int TCurMax [3];
    char Quest[55];
    char Ans[MaxHuruf];
    int MultiSender;
    int Winner, Loser;

	// Variabel umum
    int posisi[MaxHuruf];
    char ch1, ch2;
    BOOL prgs[27];
    BOOL Tamat = FALSE;
    int Salah = 0;
    char username[25];
    int CurMax;
    DWORD Length = GetModuleFileName(NULL, sPath, MAX_PATH );


    /////////////////////////////////////////////////////////////////////////////////
    if(Length > 0) {
        i = Length;
        while ((i > 0) && (sPath[i] != 92))
            i--;
        strncpy(WorkingDir, sPath, i);
    }

	///////////////////////////////PERSIAPAN//////////////////////////////////////////
    setupinterface();
    LoadUser();
    LoadWordList();
    LoadHighscore();


///////////////////////////////////////////////////////////////////////////////////////
MainMenu:
    ch1 ='\0'; ch2='\0';
    mmPos = 1;
    HSTrig:
    PrintMenuUtama(mmPos);
    do {
        if (kbhit()){
            ch1 = getch();
            if (ch1 <= 0) {
                ch2 = getch();
                int whichkey = 0;
                switch(ch2){
                    case 'H':   whichkey = PANAH_UP; break;
                    case 'P':   whichkey = PANAH_DOWN; break;
                    default:    break;
                }
                if (whichkey) {
                    if ((whichkey == PANAH_UP) && mmPos > mmAwal) {
                        mmPos--;
                        PrintMenuUtama(mmPos);
                    }else if ((whichkey == PANAH_DOWN) && mmPos < mmAkhir){
                        mmPos++;
                        PrintMenuUtama(mmPos);
                    }
                }
            }
        }
    }while(ch1 != 0x0D);
    switch(mmPos) {
        case 1: mmPos = 1; goto MenuSendiri; break;
        case 2: goto MultiPlayerSetup;break;
        case 3: PrintHighscore(); getch(); goto MainMenu; break;
        case 4: goto Bantuan; break;
        case 5: goto Keluar; break;
    }
    goto akhir;
    ///////////////////////////////////////////////////////////////////////////////////////////
MenuSendiri:
    ch1 = '\0';
    PrintMainSendiri(mmPos);
    do {
        if (kbhit()){
            ch1 = getch();
            if (ch1 <= 0) {
                ch2 = getch();
                int whichkey = 0;
                switch(ch2){
                    case 'H':   whichkey = PANAH_UP; break;
                    case 'P':   whichkey = PANAH_DOWN; break;
                    default:    break;
                }
                if (whichkey) {
                    if ((whichkey == PANAH_UP) && mmPos > msAwal) {
                        mmPos--;
                        PrintMainSendiri(mmPos);
                    }else if ((whichkey == PANAH_DOWN) && mmPos < msAkhir){
                        mmPos++;
                        PrintMainSendiri(mmPos);
                    }
                }
            } else {
                if (ch1 == 27) {
                    mmPos = 1;
                    goto MainMenu;
                }
            }
        }
    }while(ch1 != 0x0D);
    switch(mmPos) {
        case 1: goto NewGame; break;
        case 2: goto LoadGame; break;
    }
    goto akhir;
///////////////////////////////////////////////////////////////////////////////////////
NewGame:
    mmPos = 0; ch1 = '\0'; CurMax = 1;
    strcpy(username, "");
    PrintNewGame(username, "", 1);
    RequestUname:
    do {
        if (kbhit()){
            ch1 = getch();
            if (ch1 <= 0) {
                ch2 = getch();
            } else {
                if (ch1 >= 97 && ch1 <= 122)
                    ch1 = ch1 - 32;

                if (ch1 == 27) {
                    mmPos = 1;
                    goto MenuSendiri;
                } else if ((ch1 >= 65 && ch1<= 90) || ch1 == 32 || ch1 == 45 || (ch1 >= 48 && ch1<= 57) || ch1 == 46) {
                    if (mmPos < MaxUsername) {
                        *(username + mmPos++) = (char)ch1;
                        *(username + mmPos) = '\0';
                        PrintNewGame(username,"",mmPos + 1);
                        CurMax = strlen(username) + 1;
                    }else{
                        PrintNewGame(username,"Panjang username maksimal 24 char",mmPos + 1);
                    }
                } else if (ch1 == 8) {
                    if (CurMax > 1) {
                        username[mmPos - 1] = '\0';
                        mmPos--;
                        CurMax--;
                        PrintNewGame(username,"",mmPos + 1);
                    }
                }
            }
        }
    }while(ch1 != 0x0D);
    if (strcmp(username, "")==0) {
        PrintNewGame(username,"Username tidak boleh kosong!", mmPos+1);
        ch1='\0';
        goto RequestUname;
    }
    for(i = 0; i<TotUser; i++){
        if(strcmp(user[i].Uname,username)==0) {
            PrintNewGame(username,"Username sudah digunakan, coba username lain!", mmPos+1);
            ch1='\0';
            goto RequestUname;
        }
    }
    NewUser = TRUE;
    goto SinglePlayerSetup;
///////////////////////////////////////////////////////////////////////////////////////
PauseMenuSingle:
    mmPos = 1;
    PrintPauseSingle(mmPos);
    do {
        if (kbhit()){
            ch1 = getch();
            if (ch1 <= 0) {
                ch2 = getch();
                int whichkey = 0;
                switch(ch2){
                    case 'H':   whichkey = PANAH_UP; break;
                    case 'P':   whichkey = PANAH_DOWN; break;
                    default:    break;
                }
                if (whichkey) {
                    if ((whichkey == PANAH_UP) && mmPos > mpAwal) {
                        mmPos--;
                        PrintPauseSingle(mmPos);
                    }else if ((whichkey == PANAH_DOWN) && mmPos < mpAkhir){
                        mmPos++;
                        PrintPauseSingle(mmPos);
                    }
                }
            }
        }
    }while(ch1 != 0x0D);
    switch(mmPos) {
        case 1: goto SinglePlayerPlay; break;
        case 2: SimpanGameInterface(ActiveUser); getch(); goto PauseMenuSingle; break;
        case 3: ProsesHighscore(ActiveUser,CSkor); goto SinglePlayerSetup; break;
        case 4: TawarSaveGame(ActiveUser); goto HomeUser; break;
        case 5: TawarSaveGame(ActiveUser); Logout(); goto MainMenu; break;
        case 6: TawarSaveGame(ActiveUser); goto Keluar; break;
    }
    goto akhir;
///////////////////////////////////////////////////////////////////////////////////////
SingleGameOver:
    mmPos = 1; ch1 = '\0'; ch2='\0';
    SaveUser(FALSE, user[ActiveUser].Uname,user[ActiveUser].HS,level,0,"#","#",0, 0);
    PrintGameOver(mmPos);
    do {
        if (kbhit()){
            ch1 = getch();
            if (ch1 <= 0) {
                ch2 = getch();
                int whichkey = 0;
                switch(ch2){
                    case 'H':   whichkey = PANAH_UP; break;
                    case 'P':   whichkey = PANAH_DOWN; break;
                    default:    break;
                }
                if (whichkey) {
                    if ((whichkey == PANAH_UP) && mmPos > 1) {
                        mmPos--;
                        PrintGameOver(mmPos);
                    }else if ((whichkey == PANAH_DOWN) && mmPos < 2){
                        mmPos++;
                        PrintGameOver(mmPos);
                    }
                }
            }
        }
    }while(ch1 != 0x0D);
    switch(mmPos) {
        case 1: if (CSkor >= 50) CSkor -= 50;
                goto SinglePlayer;
                break;
        case 2: goto HomeUser; break;
    }
    goto akhir;
///////////////////////////////////////////////////////////////////////////////////////
SingleGameFinished:
    if(Tamat) ProsesHighscore(ActiveUser,CSkor);
    SaveUser(FALSE, user[ActiveUser].Uname,user[ActiveUser].HS,1,0,"#","#",0, 0);
    mmPos = 1; ch1 ='\0'; ch2='\0';
    PrintGameFinished(Tamat, mmPos);
    do {
        if (kbhit()){
            ch1 = getch();
            if (ch1 <= 0) {
                ch2 = getch();
                int whichkey = 0;
                switch(ch2){
                    case 'H':   whichkey = PANAH_UP; break;
                    case 'P':   whichkey = PANAH_DOWN; break;
                    default:    break;
                }
                if (whichkey) {
                    if ((whichkey == PANAH_UP) && mmPos > 1) {
                        mmPos--;
                        PrintGameFinished(Tamat, mmPos);
                    }else if ((whichkey == PANAH_DOWN) && mmPos < 2){
                        mmPos++;
                        PrintGameFinished(Tamat, mmPos);
                    }
                }
            }
        }
    }while(ch1 != 0x0D);
    Tamat = FALSE;
    switch(mmPos) {
        case 1: goto SinglePlayerSetup; break;
        case 2: goto HomeUser; break;
    }
    goto akhir;
///////////////////////////////////////////////////////////////////////////////////////
SinglePlayer:
    j = 0;
    for (i = 0; i<TotWord; i++) {
        if(WList[i].level == level && WPlayed[i] == FALSE){
            if (!Gori){
                j++;
            }else{
                if(strcmp(WList[i].Cat,Category[Gori])==0)
                    j++;
            }
        }
    }
    if(j==0) {
        goto SingleGameFinished;
    }

    if (Gori == 0){
        PN = RandomWord(level,"");
    }else{
        PN = RandomWord(level,Category[Gori]);
    }

    strcpy(user[ActiveUser].STProg, "AAAAAAAAAAAAAAAAAAAAAAAAAA");
    Salah = 0;
    SaveUser(FALSE, user[ActiveUser].Uname, user[ActiveUser].HS, level, 1, WList[PN].Wrd, "AAAAAAAAAAAAAAAAAAAAAAAAAA", CSkor , 0);

    Remain = 0;
    for(i=1;i<=26;i++)
        prgs[i] = FALSE;

    for (i=0;i<strlen(WList[PN].Wrd);i++) {
        if (prgs[WList[PN].Wrd[i] - 64] == FALSE && (WList[PN].Wrd[i] >= 65 && WList[PN].Wrd[i] <= 90)) {
            Remain++;
            prgs[WList[PN].Wrd[i] - 64] = TRUE;
        }
    }

    for(i=1;i<=26;i++)
        prgs[i] = FALSE;

    SinglePlayerPlay:
    //----------------
    WPlayed[PN] = TRUE;
    PrintGame(user[ActiveUser].Uname,CSkor,level,WList[PN].Cat,WList[PN].Quest,WList[PN].Wrd, prgs, Salah, "");
    do {
        if (kbhit()){
            ch1 = getch();
            if (ch1 <= 0) {
                ch2 = getch();
            } else {
                if (ch1 == 27) {
                    mmPos = 1;
                    WPlayed[PN] = FALSE;
                    goto PauseMenuSingle;
                }else if (ch1 >= 97 && ch1 <= 122) {
                    ch1 -= 32;
                }
                if (ch1 >= 65 && ch1<= 90) {
                    PosisiHurufPadaKata(WList[PN].Wrd, ch1, posisi);
                    if (posisi[0] > 0) {
                        if (prgs[ch1 - 64]) {
                            Salah++;
                        }else{
                            Remain--;
                            if(Remain == 0) {
                                prgs[ch1 - 64] = TRUE;
                                PrintGame(user[ActiveUser].Uname,CSkor,level,WList[PN].Cat,WList[PN].Quest,WList[PN].Wrd, prgs, Salah, "Selamat! Tekan apapun untuk melanjutkan!");
                                CSkor += HitungSkor(Salah,level);
                                Salah = 0;
                                user[ActiveUser].STSlh = 0;
                                getch();
                                Tamat = TRUE;
                                goto SinglePlayer;
                            }
                        }
                    }else{
                        Salah++;
                    }
                    user[ActiveUser].STSlh = Salah;
                    prgs[ch1 - 64] = TRUE;
                    user[ActiveUser].STProg[ch1 - 65] = 'B';

                    if (Salah == 7) {
                        PrintGame(user[ActiveUser].Uname,CSkor,level,WList[PN].Cat,WList[PN].Quest,WList[PN].Wrd, prgs, Salah, "Semangat Kaka! Kesempatan terakhir!");
                    }else if (Salah == 8){
                        WPlayed[PN] = FALSE;
                        PrintGame(user[ActiveUser].Uname,CSkor,level,WList[PN].Cat,WList[PN].Quest,WList[PN].Wrd, prgs, Salah, "Maaf! Anda Kalah! Tekan Tombol apapun untuk melanjutkan");
                        getch();
                        Salah = 0;
                        ProsesHighscore(ActiveUser,CSkor);
                        goto SingleGameOver;
                    }else{
                        PrintGame(user[ActiveUser].Uname,CSkor,level,WList[PN].Cat,WList[PN].Quest,WList[PN].Wrd, prgs, Salah, "");
                    }
                }
            }
        }
    }while(1);
    goto akhir;
///////////////////////////////////////////////////////////////////////////////////////
HomeUser:
    mmPos = 1; ch1 ='\0'; ch2='\0';
    Login = TRUE;
    strcpy(tmp, "N/A");
    for (i=0;i<=9;i++){
        if (HiScore[i].UID == -1) break;
        if (HiScore[i].UID == ActiveUser && HiScore[i].Score == user[ActiveUser].HS) {
            strcpy(tmp, HiScore[i].Tanggal);
        }
    }
    PrintHome(mmPos, user[ActiveUser].HS, tmp, user[ActiveUser].Uname);
    do {
        if (kbhit()){
            ch1 = getch();
            if (ch1 <= 0) {
                ch2 = getch();
                int whichkey = 0;
                switch(ch2){
                    case 'H':   whichkey = PANAH_UP; break;
                    case 'P':   whichkey = PANAH_DOWN; break;
                    default:    break;
                }
                if (whichkey) {
                    if ((whichkey == PANAH_UP) && mmPos > 1) {
                        mmPos--;
                        PrintHome(mmPos, user[ActiveUser].HS, tmp, user[ActiveUser].Uname);
                    }else if ((whichkey == PANAH_DOWN) && mmPos < 4){
                        mmPos++;
                        PrintHome(mmPos, user[ActiveUser].HS, tmp, user[ActiveUser].Uname);
                    }
                }
            }
        }
    }while(ch1 != 0x0D);
    Tamat = FALSE;
    switch(mmPos) {
        case 1: goto LoadLastGame; break;
        case 2: goto SinglePlayerSetup; break;
        case 3: Logout(); mmPos = 1; goto MenuSendiri; break;
        case 4: Logout(); goto MainMenu; break;
    }
    goto akhir;
///////////////////////////////////////////////////////////////////////////////////////
LoadLastGame:
    if (user[ActiveUser].ST == 1) {
        for (i=0;i<TotWord;i++){
            if (strcmp(WList[i].Wrd,user[ActiveUser].STWrd)==0) {
                level = WList[i].level;
                ReloadCat(level, Category);
                PN = i;
                break;
            }
        }
        j = 0;
        Gori = 0;

        for (i = 0; i<TotWord; i++) {
            if(WList[i].level == level && WPlayed[i] == FALSE){
                j++;
            }
        }

        if(j==0) {
            goto SingleGameFinished;
        }

        WPlayed[PN] = TRUE;

        Remain = 0;

        for (i=1;i<=26;i++) {
            if (user[ActiveUser].STProg[i-1] == 'B') {
                prgs[i] = TRUE;
            }else{
                prgs[i] = FALSE;
            }
        }

        for (i=0;i<strlen(WList[PN].Wrd);i++) {
            if (prgs[WList[PN].Wrd[i] - 64] == FALSE && (WList[PN].Wrd[i] >= 65 && WList[PN].Wrd[i] <= 90)) {
                Remain++;
                prgs[WList[PN].Wrd[i] - 64] = TRUE;
            }
        }

        for (i=1;i<=26;i++) {
            if (user[ActiveUser].STProg[i-1] == 'B') {
                prgs[i] = TRUE;
            }else{
                prgs[i] = FALSE;
            }
        }

        Salah = user[ActiveUser].STSlh;

        goto SinglePlayerPlay;


    }else{
        PrintNoGame();
        getch();
        goto HomeUser;
    }
    goto akhir;
///////////////////////////////////////////////////////////////////////////////////////
LoadGame:
    mmPos = 1;
    ManyPages = TotUser / 20;
    if (TotUser % 20 != 0 || TotUser < 20) ManyPages++;

    if (!TotUser){
        PrintError("User File Kosong!");
    }

    CPage = 1;
    PageChange:
    ch1='\0'; ch2='\0';
    if(CPage == ManyPages) {
        UserInPage = TotUser - (CPage - 1) * 20;
    }else{
        UserInPage = 20;
    }

    for (i=0;i<20;i++){
        strcpy(UserLoad[i], "");
    }
    for (i=0;i<UserInPage;i++){
        strcpy(UserLoad[i], user[i + (CPage-1) * 20].Uname);
    }
    PrintUserList (mmPos, CPage, ManyPages, UserInPage , UserLoad);
    do {
        if (kbhit()){
            ch1 = getch();
            if (ch1 <= 0) {
                ch2 = getch();
                int whichkey = 0;
                switch(ch2){
                    case 'H':   whichkey = PANAH_UP; break;
                    case 'P':   whichkey = PANAH_DOWN; break;
                    case 'M':   whichkey = PANAH_RIGHT; break;
                    case 'K':   whichkey = PANAH_LEFT; break;
                    default:    break;
                }
                if (whichkey) {
                    if ((whichkey == PANAH_UP) && mmPos != 1 && mmPos != 11) {
                        if (mmPos >= 21){
                            mmPos = UserInPage;
                        }else{
                            mmPos--;
                        }
                        PrintUserList (mmPos, CPage, ManyPages, UserInPage , UserLoad);
                    }else if ((whichkey == PANAH_DOWN) && mmPos < 21){
                        if (mmPos == 10 || mmPos == 20 || mmPos == UserInPage){
                            mmPos=21;
                        }else{
                            mmPos++;
                        }
                        PrintUserList (mmPos, CPage, ManyPages, UserInPage , UserLoad);
                    }else if ((whichkey == PANAH_LEFT) && mmPos > 10) {
                        if (mmPos >= 21) {
                            if (mmPos > 21) mmPos--;
                        }else{
                            mmPos-=10;
                        }
                        PrintUserList (mmPos, CPage, ManyPages, UserInPage , UserLoad);
                    }else if ((whichkey == PANAH_RIGHT) && (mmPos <= 10 || mmPos >= 21)) {
                        if (mmPos >= 21 && mmPos < 24) {
                            mmPos++;
                        }else{
                            if (mmPos + 10 <= UserInPage)
                                mmPos+=10;
                        }
                        PrintUserList (mmPos, CPage, ManyPages, UserInPage , UserLoad);
                    }
                }
            }else if(ch1 == 27) {
                mmPos = 2;
                goto MenuSendiri;
            }
        }
    }while(ch1 != 0x0D);
    switch(mmPos) {
        case 21: CPage = 1;goto PageChange; break;
        case 22: if (CPage > 1) CPage--; goto PageChange; break;
        case 23: if (CPage < ManyPages) CPage++; goto PageChange; break;
        case 24: CPage = ManyPages; goto PageChange; break;
        default: ActiveUser = mmPos - 1 + (CPage-1) * 20;
                 LoadWordUser(ActiveUser);
                 goto HomeUser; break;
    }
    goto akhir;
///////////////////////////////////////////////////////////////////////////////////////
SinglePlayerSetup:
    mmPos = 1; ch1 = '\0'; level = 2; Gori = 0;
    ReloadCat(level, Category);
    PrintSingleSetup(level, "ACAK KATEGORI", mmPos, FALSE, FALSE);
    ReqCat:
    do {
        if (kbhit()){
            ch1 = getch();
            if (ch1 <= 0) {
                ch2 = getch();
                int whichkey = 0;
                switch(ch2){
                    case 'H':   whichkey = PANAH_UP; break;
                    case 'P':   whichkey = PANAH_DOWN; break;
                    case 'M':   whichkey = PANAH_RIGHT; break;
                    case 'K':   whichkey = PANAH_LEFT; break;
                    default:    break;
                }
                if (whichkey) {
                    if ((whichkey == PANAH_UP) && mmPos > 1) {
                        mmPos--;
                        if (!Gori) {
                            if(Category[0][0]==0) {
                                PrintSingleSetup(level, "ACAK KATEGORI", mmPos, TRUE, FALSE);
                            }else{
                                PrintSingleSetup(level, "ACAK KATEGORI", mmPos, FALSE, FALSE);
                            }
                        }else{
                            PrintSingleSetup(level, Category[Gori], mmPos, FALSE, FALSE);
                        }

                    }else if ((whichkey == PANAH_DOWN) && mmPos < 3){
                        mmPos++;
                        if (!Gori) {
                            if(Category[0][0]==0) {
                                PrintSingleSetup(level, "ACAK KATEGORI", mmPos, TRUE, FALSE);
                            }else{
                                PrintSingleSetup(level, "ACAK KATEGORI", mmPos, FALSE, FALSE);
                            }
                        }else{
                            PrintSingleSetup(level, Category[Gori], mmPos, FALSE, FALSE);
                        }
                    }else if (whichkey == PANAH_LEFT) {
                        if (mmPos == 1) {
                            if (level > 1){
                                level--;
                                strcpy(tmp, Category[Gori]);
                                ReloadCat(level,Category);
                                Gori = 0;
                                for(i=1;i<=Category[0][0];i++){
                                    if(strcmp(Category[i], tmp)==0)
                                        Gori = i;
                                }
                                if (!Gori) {
                                    if(Category[0][0]==0) {
                                        PrintSingleSetup(level, "ACAK KATEGORI", mmPos, TRUE, FALSE);
                                    }else{
                                        PrintSingleSetup(level, "ACAK KATEGORI", mmPos, FALSE, FALSE);
                                    }
                                }else{
                                    PrintSingleSetup(level, Category[Gori], mmPos, FALSE, FALSE);
                                }
                            }
                        }else if(mmPos ==2) {
                            if (Gori > 0) {
                                Gori--;
                                if (!Gori) {
                                    if(Category[0][0]==0) {
                                        PrintSingleSetup(level, "ACAK KATEGORI", mmPos, TRUE, FALSE);
                                    }else{
                                        PrintSingleSetup(level, "ACAK KATEGORI", mmPos, FALSE, FALSE);
                                    }
                                }else{
                                    PrintSingleSetup(level, Category[Gori], mmPos, FALSE, FALSE);
                                }
                            }
                        }
                    }else if (whichkey == PANAH_RIGHT) {
                        if (mmPos == 1) {
                            if (level < 3){
                                level++;
                                strcpy(tmp, Category[Gori]);
                                ReloadCat(level,Category);
                                Gori = 0;
                                for(i=1;i<=Category[0][0];i++){
                                    if(strcmp(Category[i], tmp)==0)
                                        Gori = i;
                                }
                                if (!Gori) {
                                    if(Category[0][0]==0) {
                                        PrintSingleSetup(level, "ACAK KATEGORI", mmPos, TRUE, FALSE);
                                    }else{
                                        PrintSingleSetup(level, "ACAK KATEGORI", mmPos, FALSE, FALSE);
                                    }
                                }else{
                                    PrintSingleSetup(level, Category[Gori], mmPos, FALSE, FALSE);
                                }
                            }
                        }else if(mmPos ==2) {
                            if (Gori < Category[0][0]) {
                                Gori++;
                                if (!Gori) {
                                    if(Category[0][0]==0) {
                                        PrintSingleSetup(level, "ACAK KATEGORI", mmPos, TRUE, FALSE);
                                    }else{
                                        PrintSingleSetup(level, "ACAK KATEGORI", mmPos, FALSE, FALSE);
                                    }
                                }else{
                                    PrintSingleSetup(level, Category[Gori], mmPos, FALSE, FALSE);
                                }
                            }
                        }
                    }
                }
            } else if(ch1 == 27) {
                if (Login) {
                    mmPos = 1;
                    goto HomeUser;
                }else {
                    mmPos = 1;
                    goto NewGame;
                }
            }
        }
    }while(ch1 != 0x0D || mmPos != 3);
    if (Category[0][0] == 0) {
        PrintSingleSetup(level, Category[Gori], mmPos, TRUE, TRUE);
        ch1 = '\0';
        goto ReqCat;
    }
    if (NewUser){
        Login = TRUE;
        for(i=0;i<TotWord;i++)
            WPlayed[i] = FALSE;
        SaveUser(TRUE,username,0,level,0,"#","#",0, 0);
        LoadUser();
        ActiveUser = TotUser - 1;
    }
    NewUser = FALSE;
    CSkor = 0;
    goto SinglePlayer;
///////////////////////////////////////////////////////////////////////////////////////
MultiPlayerSetup:
    mmPos = 0; ch1 = '\0'; CurMax = 1; CurPlayer = 1;
    strcpy(username, "");
    strcpy(Ans, "");
    strcpy(Quest, "");
    NextMUser:
    PrintMultiSetup(username,CurPlayer, "", 1);
    RequestMultiname:
    do {
        if (kbhit()){
            ch1 = getch();
            if (ch1 <= 0) {
                ch2 = getch();
            } else {
                if (ch1 >= 97 && ch1 <= 122)
                    ch1 = ch1 - 32;

                if (ch1 == 27) {
                    mmPos = 1;
                    goto MainMenu;
                } else if ((ch1 >= 65 && ch1<= 90) || ch1 == 32 || ch1 == 45 || (ch1 >= 48 && ch1<= 57) || ch1 == 46) {
                    if (mmPos < MaxUsername) {
                        *(username + mmPos++) = (char)ch1;
                        *(username + mmPos) = '\0';
                        PrintMultiSetup(username,CurPlayer, "", mmPos + 1);
                        CurMax = strlen(username) + 1;
                    }else{
                        PrintMultiSetup(username,CurPlayer, "Panjang username maksimal 24 char", mmPos + 1);
                    }
                } else if (ch1 == 8) {
                    if (CurMax > 1) {
                        username[mmPos - 1] = '\0';
                        mmPos--;
                        CurMax--;

                        PrintMultiSetup(username,CurPlayer, "", mmPos + 1);
                    }
                }
            }
        }
    }while(ch1 != 0x0D);
    if (strcmp(username, "")==0) {
        PrintMultiSetup(username,CurPlayer, "Username tidak boleh kosong!", mmPos + 1);
        ch1='\0';
        goto RequestMultiname;
    }
    if (CurPlayer == 1) {
        strcpy(MPlayer[0].Uname, username);
        MPlayer[0].HS = 0;
        CurPlayer = 2;
        ch1 = '\0';
        mmPos = 0;
        CurMax = 1;
        strcpy(username,"");
        goto NextMUser;
    }else{
        if(strcmp(MPlayer[0].Uname, username)==0) {
            PrintMultiSetup(username,CurPlayer, "Username tidak boleh sama!", mmPos + 1);
            ch1='\0';
            goto RequestMultiname;
        }
        strcpy(MPlayer[1].Uname, username);
        MPlayer[1].HS = 0;
        CurPlayer = 0;
        goto BuatPertanyaan;
    }

    goto akhir;
///////////////////////////////////////////////////////////////////////////////////////
BuatPertanyaan:
    TexPos[1] = 0; TexPos[2] = 0; ch1 = '\0'; TCurMax[1] = 1; TCurMax[2] = 1; CurTex = 1;
    ContTanya:
    PrintBuatPertanyaan(MPlayer[CurPlayer].Uname, MPlayer[CurPlayer].HS, Quest, Ans, "", TexPos[CurTex] + 1, CurTex);
    RequestPertanyaan:
    do {
        if (kbhit()){
            ch1 = getch();
            if (ch1 <= 0) {
                ch2 = getch();
                int whichkey = 0;
                switch(ch2){
                    case 'H':   whichkey = PANAH_UP; break;
                    case 'P':   whichkey = PANAH_DOWN; break;
                    default:    break;
                }
                if (whichkey) {
                    if ((whichkey == PANAH_UP) && CurTex == 2) {
                        CurTex = 1;
                        PrintBuatPertanyaan(MPlayer[CurPlayer].Uname, MPlayer[CurPlayer].HS, Quest, Ans, "", TexPos[CurTex] + 1, CurTex);
                    }else if ((whichkey == PANAH_DOWN) && CurTex == 1){
                        CurTex = 2;
                        PrintBuatPertanyaan(MPlayer[CurPlayer].Uname, MPlayer[CurPlayer].HS, Quest, Ans, "", TexPos[CurTex] + 1, CurTex);
                    }
                }
            } else {
                if (ch1 >= 97 && ch1 <= 122 && CurTex == 2)
                    ch1 = ch1 - 32;

                if (ch1 == 27) {
                    mmPos = 1;
                    MultiSender = 1;
                    goto MultiPlayerPause;
                }else if (ch1==9){
                    if (CurTex == 1) {
                        CurTex = 2;
                        PrintBuatPertanyaan(MPlayer[CurPlayer].Uname, MPlayer[CurPlayer].HS, Quest, Ans, "", TexPos[CurTex] + 1, CurTex);
                    }else{
                        CurTex = 1;
                        PrintBuatPertanyaan(MPlayer[CurPlayer].Uname, MPlayer[CurPlayer].HS, Quest, Ans, "", TexPos[CurTex] + 1, CurTex);
                    }
                } else if ((ch1 >= 65 && ch1<= 90) || ch1 == 32 || ch1 == 45 || (ch1 >= 48 && ch1<= 57) || ch1 == 46 || (CurTex == 1 && ch1 != 8 && ch1 != 9 && ch1 != 10 && ch1 != 13)) {
                    if (TexPos[CurTex] < 50) {
                        if(CurTex==1){
                            *(Quest + TexPos[1]++) = (char)ch1;
                            *(Quest + TexPos[1]) = '\0';
                            TCurMax[1] = strlen(Quest) + 1;
                        }else{
                            *(Ans + TexPos[2]++) = (char)ch1;
                            *(Ans + TexPos[2]) = '\0';
                            TCurMax[2] = strlen(Ans) + 1;
                        }
                        PrintBuatPertanyaan(MPlayer[CurPlayer].Uname, MPlayer[CurPlayer].HS, Quest, Ans, "", TexPos[CurTex] + 1, CurTex);
                    }else{
                        PrintBuatPertanyaan(MPlayer[CurPlayer].Uname, MPlayer[CurPlayer].HS, Quest, Ans, "Panjang kata tidak boleh melebihi 50 karakter!", TexPos[CurTex] + 1, CurTex);
                    }
                } else if (ch1 == 8) {
                    if (TCurMax[CurTex] > 1) {
                        if(CurTex==1){
                            Quest[TexPos[1] - 1] = '\0';
                            TexPos[1]--;
                            TCurMax[1]--;
                        }else{
                            Ans[TexPos[2] - 1] = '\0';
                            TexPos[2]--;
                            TCurMax[2]--;
                        }
                        PrintBuatPertanyaan(MPlayer[CurPlayer].Uname, MPlayer[CurPlayer].HS, Quest, Ans, "", TexPos[CurTex] + 1, CurTex);
                    }
                }
            }
        }
    }while(ch1 != 0x0D);
    if (strcmp(Quest, "")==0) {
        CurTex = 1;
        PrintBuatPertanyaan(MPlayer[CurPlayer].Uname, MPlayer[CurPlayer].HS, Quest, Ans, "Pertanyaan tidak boleh kosong!", TexPos[CurTex] + 1, CurTex);
        ch1='\0';
        goto RequestPertanyaan;
    }
    if (strcmp(Ans, "")==0) {
        CurTex = 2;
        PrintBuatPertanyaan(MPlayer[CurPlayer].Uname, MPlayer[CurPlayer].HS, Quest, Ans, "Jawaban tidak boleh kosong!", TexPos[CurTex] + 1, CurTex);
        ch1='\0';
        goto RequestPertanyaan;
    }
    if (CurPlayer == 0) {
        CurPlayer = 1;
    }else{
        CurPlayer = 0;
    }
    goto MultiPlayerPlay;
///////////////////////////////////////////////////////////////////////////////////////
MultiPlayerPause:
    mmPos = 1;
    PrintPauseMulti(mmPos);
    do {
        if (kbhit()){
            ch1 = getch();
            if (ch1 <= 0) {
                ch2 = getch();
                int whichkey = 0;
                switch(ch2){
                    case 'H':   whichkey = PANAH_UP; break;
                    case 'P':   whichkey = PANAH_DOWN; break;
                    default:    break;
                }
                if (whichkey) {
                    if ((whichkey == PANAH_UP) && mmPos > 1) {
                        mmPos--;
                        PrintPauseMulti(mmPos);
                    }else if ((whichkey == PANAH_DOWN) && mmPos < 4){
                        mmPos++;
                        PrintPauseMulti(mmPos);
                    }
                }
            }
        }
    }while(ch1 != 0x0D);
    switch(mmPos) {
        case 1: if (MultiSender==1) goto BuatPertanyaan;
                else goto MultiPlayerPlay; break;
        case 2: goto MultiPlayerSetup; break;
        case 3: Logout(); goto MainMenu; break;
        case 4: goto Keluar; break;
    }
    goto akhir;
///////////////////////////////////////////////////////////////////////////////////////
MultiPlayerOver:
    mmPos = 1; ch1 = '\0'; ch2='\0';
    if (MPlayer[0].HS > MPlayer[1].HS) {
        Winner = 0;
        Loser = 1;
    }else if (MPlayer[0].HS == MPlayer[1].HS) {
        PrintDraw();
        getch();
        goto MultiPlayerSetup;
    }else{
        Winner = 1;
        Loser = 0;
    }
    PrintGameOverMulti(mmPos, MPlayer[Winner], MPlayer[Loser]);
    do {
        if (kbhit()){
            ch1 = getch();
            if (ch1 <= 0) {
                ch2 = getch();
                int whichkey = 0;
                switch(ch2){
                    case 'H':   whichkey = PANAH_UP; break;
                    case 'P':   whichkey = PANAH_DOWN; break;
                    default:    break;
                }
                if (whichkey) {
                    if ((whichkey == PANAH_UP) && mmPos > 1) {
                        mmPos--;
                        PrintGameOverMulti(mmPos, MPlayer[Winner], MPlayer[Loser]);
                    }else if ((whichkey == PANAH_DOWN) && mmPos < 2){
                        mmPos++;
                        PrintGameOverMulti(mmPos, MPlayer[Winner], MPlayer[Loser]);
                    }
                }
            }
        }
    }while(ch1 != 0x0D);
    switch(mmPos) {
        case 1: goto MultiPlayerSetup;break;
        case 2: Logout();goto MainMenu; break;
    }
    goto akhir;
///////////////////////////////////////////////////////////////////////////////////////
MultiPlayerPlay:
    Salah = 0;
    Remain = 0;
    for(i=1;i<=26;i++)
        prgs[i] = FALSE;

    for (i=0;i<strlen(Ans);i++) {
        if (prgs[Ans[i] - 64] == FALSE && (Ans[i] >= 65 && Ans[i] <= 90)) {
            Remain++;
            prgs[Ans[i] - 64] = TRUE;
        }
    }

    for(i=1;i<=26;i++)
        prgs[i] = FALSE;

    ContMulti:
    PrintGameMulti(MPlayer[CurPlayer].Uname,MPlayer[CurPlayer].HS ,Quest, Ans, prgs, Salah, "");
    do {
        if (kbhit()){
            ch1 = getch();
            if (ch1 <= 0) {
                ch2 = getch();
            } else {
                if (ch1 == 27) {
                    mmPos = 1;
                    MultiSender = 2;
                    goto MultiPlayerPause;
                }else if (ch1 >= 97 && ch1 <= 122) {
                    ch1 -= 32;
                }
                if (ch1 >= 65 && ch1<= 90) {
                    posisi[0] = 0;
                    for (i=0;i<strlen(Ans);i++){
                        if (Ans[i] == ch1)
                            posisi[0] = 1;
                    }
                    if (posisi[0] > 0) {
                        if (prgs[ch1 - 64]) {
                            Salah++;
                        }else{
                            Remain--;
                            if(Remain == 0) {
                                prgs[ch1 - 64] = TRUE;
                                PrintGameMulti(MPlayer[CurPlayer].Uname,MPlayer[CurPlayer].HS ,Quest, Ans, prgs, Salah, "Selamat! Tekan apapun untuk melanjutkan!");
                                MPlayer[CurPlayer].HS += HitungSkor(Salah,1);
                                Salah = 0;
                                strcpy(Ans, "");
                                strcpy(Quest, "");
                                getch();
                                goto BuatPertanyaan;
                            }
                        }
                    }else{
                        Salah++;
                    }
                    prgs[ch1 - 64] = TRUE;

                    if (Salah == 7) {
                        PrintGameMulti(MPlayer[CurPlayer].Uname,MPlayer[CurPlayer].HS ,Quest, Ans, prgs, Salah, "Semangat Kaka! Last Chance!");
                    }else if (Salah == 8){
                        PrintGameMulti(MPlayer[CurPlayer].Uname,MPlayer[CurPlayer].HS ,Quest, Ans, prgs, Salah, "Maaf! Anda Kalah! Tekan Tombol apapun untuk melanjutkan");
                        getch();
                        Salah = 0;
                        if (MPlayer[CurPlayer].HS >= 50) MPlayer[CurPlayer].HS -= 50;
                        strcpy(Ans, "");
                        strcpy(Quest, "");
                        goto MultiPlayerOver;
                    }else{
                        PrintGameMulti(MPlayer[CurPlayer].Uname,MPlayer[CurPlayer].HS ,Quest, Ans, prgs, Salah, "");
                    }
                }
            }
        }
    }while(1);
    goto akhir;
///////////////////////////////////////////////////////////////////////////////////////
Bantuan:
    PrintBantuan(0);
    do {
        ch1 = getch();

    }while(ch1 != 27);

    goto MainMenu;
    ///////////////////////////////////////////////////////////////////////////////////////////
Keluar:
    PrintKeluar();
    getch();
akhir:
    return 0;
}


/*//////////////////////////////////////////////////////////////////////////////////
                             BAGIAN FILE EXTERNAL
       Bagian ini berisi prosedur prosedur yang berhubungan dengan file external
       Dikerjakan oleh : Muhammad Lathieful Haq (16512186)
////////////////////////////////////////////////////////////////////////////////////*/

void LoadWordUser(int UserID){
    /*FORMAT:
      --------
        USER-WORD-LIST
        [WORD] [STATE:T/F]
    */
    FILE* Fp;
    int i, Byk;
    char tmp[MaxHuruf];
    BOOL tmpS;
    char WD [MAX_PATH];
    char ADDR[30];
    char ERR[50];
    strcpy(ADDR, "\\usr\\");
    strcat(ADDR, user[UserID].Uname);
    strcat(ADDR, ".db");

    strcpy(WD,WorkingDir);
    strcat(WD,ADDR);
    Fp = fopen(WD,"r");

    for(i=0;i<TotWord;i++){
        WPlayed[i] = FALSE;
    }

    if(Fp==NULL) {
        ///////////////// PENANGANAN FILE TIDAK ADA
        for(i=0;i<TotWord;i++){
            WPlayed[i] = FALSE;
        }
    }

    if(fscanf(Fp, "%s", tmp)==1) {
        if (strcmp(tmp, "USER-WORD-LIST")==0) {
            i = 0;
            Byk = HowMuchLine(Fp);
            if (Byk) {
                fseek(Fp, 16, SEEK_SET);
                while (fscanf(Fp,"%s %d",tmp, &tmpS)!=EOF){
                    replace(tmp,' ','_',0);
                    for(i=0;i<TotWord;i++){
                        if (strcmp(tmp, WList[i].Wrd)==0){
                            WPlayed[i] = tmpS;
                        }
                    }
                }
            }
        }else{
            strcpy(ERR, "[ERR:02] File ");
            strcat(ERR, user[UserID].Uname);
            strcat(ERR, " salah/corrupt!");
            PrintError(ERR);
        }
    }else{
        for(i=0;i<TotWord;i++){
            WPlayed[i] = FALSE;
        }
    }
    fclose(Fp);
}

void ProsesHighscore(int UserID, int Score) {
    int i,j, k, l, tmp, cntr ,urut;
    char tgl[30];
    char* tmps;
    time_t rawtime;
    struct tm * timeinfo;
    int lmin;
    int mmin;
    FILE * Fp;
    HScr STmp;
    char WD [MAX_PATH];
    char* ADDR = "\\master.db";
    strcpy(WD,WorkingDir);
    strcat(WD,ADDR);

    time (&rawtime);
    timeinfo = localtime (&rawtime);
    strftime (tgl,20,"%d %b %y, %I:%M%p",timeinfo);
    if (Score > user[UserID].HS) user[UserID].HS = Score;
    if (HiScore[0].Score == HiScore[9].Score && HiScore[9].Score == Score){
        for (i = 0; i<= 9; i++) {
            if (strOrder(user[HiScore[i].UID].Uname,user[HiScore[i + 1].UID].Uname)==1) {
                for (j=9; j> i; j--) {
                    HiScore[j].UID = HiScore[j-1].UID;
                    HiScore[j].Score = HiScore[j-1].Score;
                    strcpy(HiScore[j].Tanggal, HiScore[j-1].Tanggal);
                }
                // end for
                HiScore[i].UID = UserID;
                HiScore[i].Score = Score;
                strcpy(HiScore[i].Tanggal, tgl);

                urut = i;

                if (TawarSaveHS(UserID, urut + 1, Score)) {
                    Fp = fopen(WD, "w");
                    fprintf(Fp,"HANG-MAN-TOP-MASTERS\n");
                    for (i=0;i<=9; i++) {
                        if(HiScore[i].UID != -1) {
                            strcpy(tgl, HiScore[i].Tanggal);
                            replace(tgl,'_',' ',0);
                            fprintf(Fp, "%d %d %s\n", HiScore[i].UID, HiScore[i].Score, tgl);
                        }else{
                            fprintf(Fp, "-1 0 X\n");
                        }
                    }
                    fclose(Fp);
                }else{
                    LoadHighscore();
                }
                break;
            }
        }
    }else{
        for (i = 0; i<= 9; i++) {
            if (HiScore[i].UID == -1) {
                HiScore[i].UID = UserID;
                HiScore[i].Score = Score;
                strcpy(HiScore[i].Tanggal, tgl);
                urut = i;
                goto UrutNama;
            }
            if (Score > HiScore[i].Score) {
                for (j=9; j> i; j--) {
                    HiScore[j].UID = HiScore[j-1].UID;
                    HiScore[j].Score = HiScore[j-1].Score;
                    strcpy(HiScore[j].Tanggal, HiScore[j-1].Tanggal);
                }
                // end for
                HiScore[i].UID = UserID;
                HiScore[i].Score = Score;
                strcpy(HiScore[i].Tanggal, tgl);
                urut = i;
                UrutNama:
                lmin = i;
                for (j=0;j<=i;j++){
                    if (HiScore[i].Score == HiScore[j].Score){
                        lmin = j;
                        goto CekNama;
                    }
                }
                CekNama:
                if (lmin != i) {
                    cntr = 0;
                    for(j=lmin;j<i;j++){
                        for (k=i;k>j;k--){
                            if (strOrder(user[HiScore[k].UID].Uname,user[HiScore[k - 1].UID].Uname)==2) {
                                cntr = 0;
                                strcpy(STmp.Tanggal, HiScore[k].Tanggal);
                                STmp.UID = HiScore[k].UID;
                                STmp.Score = HiScore[k].Score;
                                strcpy(HiScore[k].Tanggal,  HiScore[k - 1].Tanggal);
                                HiScore[k].UID = HiScore[k - 1].UID;
                                HiScore[k].Score = HiScore[k - 1].Score;
                                strcpy(HiScore[k - 1].Tanggal, STmp.Tanggal);
                                HiScore[k - 1].UID = STmp.UID;
                                HiScore[k - 1].Score = STmp.Score;
                            }
                        }
                    }
                    for(j=lmin;j<i;j++) {
                        if (HiScore[j].UID == UserID && strcmp(HiScore[j].Tanggal, tgl)==0) {
                            urut = j;
                        }
                    }
                }
                if (TawarSaveHS(UserID, urut + 1, Score)) {
                    Fp = fopen(WD, "w");
                    fprintf(Fp,"HANG-MAN-TOP-MASTERS\n");
                    for (i=0;i<=9; i++) {
                        if(HiScore[i].UID != -1) {
                            strcpy(tgl, HiScore[i].Tanggal);
                            replace(tgl,'_',' ',0);
                            fprintf(Fp, "%d %d %s\n", HiScore[i].UID, HiScore[i].Score, tgl);
                        }else{
                            fprintf(Fp, "-1 0 X\n");
                        }
                    }
                    fclose(Fp);
                }else{
                    LoadHighscore();
                }
                break;
            }
        }
    }
}

void LoadHighscore() {
    // HANG-MAN-TOP-MASTERS
    // [uid] [date]
    FILE* Fp;
    int i, j, Byk;
    char tmp[25];
    char WD [MAX_PATH];
    char* ADDR = "\\master.db";
    HScr wtmp;

    strcpy(WD,WorkingDir);
    strcat(WD,ADDR);
    Fp = fopen(WD,"r");

    if(Fp==NULL) {
        ///////////////// PENANGANAN FILE TIDAK ADA
        PrintError("[ERR:01] File master.db tidak dapat ditemukan oleh program!");
    }

    if(fscanf(Fp, "%s", tmp)==1) {
        if (strcmp(tmp, "HANG-MAN-TOP-MASTERS")==0) {
            i = 0;
            Byk = HowMuchLine(Fp);
            if (Byk > 1) {
                fseek(Fp, 20, SEEK_SET);
                while (fscanf(Fp,"%d %d %s", &wtmp.UID, &wtmp.Score, wtmp.Tanggal)!=EOF){
                    replace(wtmp.Tanggal,' ','_',0);

                    strcpy(HiScore[i].Tanggal, wtmp.Tanggal);
                    HiScore[i].UID = wtmp.UID;
                    HiScore[i].Score = wtmp.Score;

                    i++;
                }
                for(j=i; j<=9;j++){
                    HiScore[j].UID = -1;
                    strcpy(HiScore[j].Tanggal, "");
                    HiScore[j].Score = 0;
                }
            } else {
                for (i=0;i<=9;i++){
                    HiScore[i].UID = -1;
                    strcpy(HiScore[i].Tanggal,"");
                    HiScore[i].Score = 0;
                }
            }
        }else{
            PrintError("[ERR:02] File master.db salah/corrupt!");
        }
    }else{
        PrintError("[ERR:03] File master.db kosong/salah!");
    }
    fclose(Fp);
}

inline int HitungSkor(int Salah, int Level){
    if (Salah == 8) return 0;
    return (Level * (100 - Salah * Salah));
}

void PosisiHurufPadaKata(char Kata[MaxHuruf], char Huruf, int Posisi[]) {
    int i = 0;
    int j = 1;

    for (i=0; i<=MaxHuruf;i++)
        Posisi[i] = 0;

    i = 0;
    while (Kata[i] != '\0') {
        if (Kata[i] == Huruf)
            Posisi[j++] = i;
        i++;
    }
    Posisi[0] = j - 1;

}

void ReloadCat(int level, char CAT[300][50]) {
    BOOL Found; int i,j,k;
    k = 1;
    for(i=1;i<=300;i++)
        strcpy(CAT[i],"");
    for(i=0;i<TotWord;i++) {
        Found = FALSE;
        for(j=0;j<=i;j++) {
            if(strcmp(CAT[j], WList[i].Cat) == 0) {
                Found = TRUE;
            }
        }
        if (!Found && level == WList[i].level) {
            strcpy(CAT[k], WList[i].Cat);
            k++;
        }
    }
    CAT[0][0] = k - 1;
}

void LoadUser() {
    /*FORMAT:
      --------
        HANG-MAN-USER-FILE
        [username] [totscore] [difficulities] [state:Y/N] [state:word] [state:progress] [state:curscore]
    */
    FILE* Fp;
    int i, Byk;
    char tmp[25];
    char WD [MAX_PATH];
    char* ADDR = "\\user.db";
    USR utmp;

    strcpy(WD,WorkingDir);
    strcat(WD,ADDR);
    Fp = fopen(WD,"r");

    if(Fp==NULL) {
        ///////////////// PENANGANAN FILE TIDAK ADA
        PrintError("[ERR:01] File user.db tidak dapat ditemukan oleh program!");
    }

    if(fscanf(Fp, "%s", tmp)==1) {
        if (strcmp(tmp, "HANG-MAN-USER-FILE")==0) {
            i = 0;
            Byk = HowMuchLine(Fp);
            if (Byk) {
                user = malloc(sizeof(USR)*(Byk));
                fseek(Fp, 20, SEEK_SET);
                while (fscanf(Fp,"%s %d %d %d %s %s %d %d",utmp.Uname, &utmp.HS, &utmp.Gori, &utmp.ST, utmp.STWrd, utmp.STProg, &utmp.STScr, &utmp.STSlh)!=EOF){
                    replace(utmp.Uname,' ','_',0);
                    strcpy(user[i].Uname, utmp.Uname);
                    user[i].HS = utmp.HS;
                    user[i].Gori = utmp.Gori;
                    user[i].ST = utmp.ST;
                    strcpy(user[i].STWrd, utmp.STWrd);
                    strcpy(user[i].STProg ,utmp.STProg);
                    user[i].STScr = utmp.STScr;
                    user[i].STSlh = utmp.STSlh;
                    i++;
                }
                TotUser = i;
            } else {
                TotUser = 0;
            }
        }else{
            PrintError("[ERR:02] File user.db salah/corrupt!");
        }
    }else{
        PrintError("[ERR:03] File user.db kosong/salah!");
    }
    fclose(Fp);
}

int HowMuchLine(FILE* Fp){
    int Jml, i;
    char* tmp;
    fseek(Fp,0L,SEEK_END);
    Jml = ftell(Fp);
    tmp = malloc(sizeof(char) * Jml);
    fseek(Fp,0,SEEK_SET);
    fread(tmp, sizeof(char),Jml, Fp);
    i = 0; Jml = 0;
    while(tmp[i]){
        if(tmp[i]==10) {
            Jml++;
        }
        i++;
    }
    return Jml;
}

void SaveUser(BOOL NewUser, char* username, int HighScore, int Gori, int ST, char* STWrd, char* STProg, int CurScore, int Salah){
    int i, tmp;
    FILE * Fp;
    FILE * Fd;
    char Wtmp[MAXWORD];
    char Utmp[25];

    char WD [MAX_PATH];
    char* ADDR = "\\user.db";
    char ADD [35];


    strcpy(WD,WorkingDir);
    strcat(WD,ADDR);
    replace(username,'_',' ',0);
    if (NewUser) {
        Fp = fopen(WD, "a");
        fprintf(Fp,"%s %d %d %d %s %s %d %d\n", username, HighScore, Gori, ST, STWrd, STProg, CurScore, Salah);
    }else{
        Fp = fopen(WD, "w");
        for (i=0;i<TotUser; i++) {
            if(user[i].Uname==username) {
                tmp = i;
                break;
            }
        }
        user[tmp].HS = HighScore;
        user[tmp].Gori = Gori;
        user[tmp].ST = ST;
        strcpy(user[tmp].STWrd ,STWrd);
        strcpy(user[tmp].STProg ,STProg);
        user[tmp].STScr = CurScore;
        user[tmp].STSlh = Salah;
        fprintf(Fp,"HANG-MAN-USER-FILE\n");
        for(i=0;i<TotUser;i++) {
            strcpy(Utmp, user[i].Uname);
            strcpy(Wtmp, user[i].STWrd);
            replace(Utmp,'_',' ',0);
            replace(Wtmp,'_',' ',0);
            fprintf(Fp, "%s %d %d %d %s %s %d %d\n", Utmp, user[i].HS, user[i].Gori, user[i].ST, Wtmp, user[i].STProg, user[i].STScr, user[i].STSlh);
        }
        strcpy(ADD, "\\usr\\");
        strcat(ADD, username);
        strcat(ADD, ".db");
        strcpy(WD,WorkingDir);
        strcat(WD,ADD);
        Fd = fopen(WD,"w");
        fprintf(Fd, "USER-WORD-LIST\n");
        for(i=0;i<TotWord;i++){
            strcpy(Wtmp, WList[i].Wrd);
            replace(Wtmp,'_',' ',0);
            fprintf(Fd, "%s %d\n", Wtmp, WPlayed[i]);
        }
        fclose(Fd);
    }
    replace(username,' ','_',0);
    fclose(Fp);
}

void LoadWordList() {
    // HANG-MAN-WORDLIST-FILE
    // [category] [question] [word] [level]
    FILE* Fp;
    int i, Byk;
    char tmp[25];
    char WD [MAX_PATH];
    char* ADDR = "\\wl.db";
    WL wtmp;

    strcpy(WD,WorkingDir);
    strcat(WD,ADDR);
    Fp = fopen(WD,"r");

    if(Fp==NULL) {
        ///////////////// PENANGANAN FILE TIDAK ADA
        PrintError("[ERR:01] File wl.db tidak dapat ditemukan oleh program!");
    }

    if(fscanf(Fp, "%s", tmp)==1) {
        if (strcmp(tmp, "HANG-MAN-WORDLIST-FILE")==0) {
            i = 0;
            Byk = HowMuchLine(Fp);
            if (Byk - 1) {
                WList = malloc(sizeof(WL)*(Byk));
                WPlayed = malloc(sizeof(BOOL) * Byk);

                fseek(Fp, 22, SEEK_SET);
                while (fscanf(Fp,"%s %s %s %d",wtmp.Cat, wtmp.Quest, wtmp.Wrd, &wtmp.level)!=EOF){
                    replace(wtmp.Cat,' ','_',0);
                    replace(wtmp.Quest,' ','_',0);
                    replace(wtmp.Wrd,' ','_',0);

                    strcpy(WList[i].Cat, wtmp.Cat);
                    strcpy(WList[i].Quest, wtmp.Quest);
                    strcpy(WList[i].Wrd, wtmp.Wrd);
                    WList[i].level = wtmp.level;

                    WPlayed[i] = FALSE;
                    i++;
                }
                TotWord = i;
            } else {
                PrintError("[ERR:04] wl.db Kosong! Tidak ada kata yang dapat dimainkan!");
            }
        }else{
            PrintError("[ERR:02] File wl.db salah/corrupt!");
        }
    }else{
        PrintError("[ERR:03] File wl.db kosong/salah!");
    }
    fclose(Fp);
}

/*//////////////////////////////////////////////////////////////////////////////////
                                 BAGIAN PENDUKUNG
                Bagian ini berisi fungsi fugsi pendukung program
                Dikerjakan oleh : Octavianus S P Sinaga (16512060)
////////////////////////////////////////////////////////////////////////////////////*/

// Fungsi untuk mengecek string mana yang lebih besar
int strOrder(char *s1,char *s2) {
    int i;
    if(strcmp(s1,s2)==0)return(0);
    for(i=0;s1[i]!=0;i++){
        if(s1[i] > s2[i])return(1);
        else if(s1[i] < s2[i])return(2);
    }
    return (2);
}

// Fungsi untuk merandom huruf dari daftar huruf
int RandomWord(int Difficulity, char* Category) {
    int i, j, Hsl;
    int divisor;
    int* Acak;
    //BOOL Tamat;

    j=0;

    if(strcmp(Category,"")!=0) {
        for(i=0;i<TotWord;i++){
            if((WList[i].level==Difficulity) && strcmp(WList[i].Cat, Category)==0 && WPlayed[i] == FALSE) {
                j++;
            }
        }
        if(j) {
            Acak = (int*) malloc(j*sizeof(int));
        }else{
            PrintError("[ERR:04] Tidak dapat mengacak huruf sesuai spesifikasi untuk dimainkan.");
        }

        j = 0;
        for(i=0;i<TotWord;i++){
            if((WList[i].level==Difficulity) && strcmp(WList[i].Cat, Category)==0 && WPlayed[i] == FALSE) {
                Acak[j] = i;
                j++;
            }
        }
    }else{
        for(i=0;i<TotWord;i++){
            if(WList[i].level==Difficulity && WPlayed[i] == FALSE) {
                j++;
            }
        }
        if(j) {
            Acak = (int*) malloc(j*sizeof(int));
        }else{
            PrintError("[ERR:04] Tidak dapat mengacak huruf sesuai spesifikasi untuk dimainkan.");
        }
        j = 0;
        for(i=0;i<TotWord;i++){
            if(WList[i].level==Difficulity && WPlayed[i] == FALSE) {
                Acak[j] = i;
                j++;
            }
        }
    }
    srand((unsigned)time(0));
    divisor = RAND_MAX/(j);
    do {
        Hsl = rand() / divisor;
    } while (Hsl > (j - 1));
    return (Acak[Hsl]);
}

// Fungsi untuk mengetahui panjang suatu integer
int IntLen(int number){
	int l=!number;
	while(number){
		l++; number/=10;
	}
	return l;
}

// Fungsi untuk mereplace karakter dalam string
void replace (char *string, char new_char, char old_char, int convert_flag) {
    int c_flag=0;

    while(*string){
       if(*string == old_char)
          c_flag++;

       if(convert_flag == 0 || convert_flag == c_flag)
          if(*string == old_char){
             *string = new_char;
             if(convert_flag > 0)
                break;
             }
       string++;
    }
}

// Fungsi untuk menghapus variabel yang harus dikosongkan jika tdk ada user yg aktif
inline void Logout(){
    int i;
    Login = FALSE;
    ActiveUser = -1;
    for (i=0;i<TotWord;i++)
        WPlayed[i] = FALSE;
}


/*//////////////////////////////////////////////////////////////////////////////////
                             BAGIAN FUNGSI/PROSEDUR INTERFACE
        Bagian ini berisi prosedur prosedur yang berhubungan dengan interface
        program.
        Dikerjakan oleh : Fransiskus Damanik (16512120)
////////////////////////////////////////////////////////////////////////////////////*/

// Menampilkan daftar user untuk Load User
void PrintUserList (int sCursor, int sPage, int TotPage, int TotUL , char UList[20][25]) {
    char UTmp[20][35];
    int lmin;
    int i,j;

    system(CLEARCMD);
    for (i=0;i<TotUL;i++){
        strcpy(UTmp[i], "");
        lmin = 17 - strlen(UList[i])/2;
        for (j=1; j<=lmin;j++)
            strcat(UTmp[i]," ");
        strcat(UTmp[i], UList[i]);
        for(j=1; j<=33-lmin-strlen(UList[i]);j++)
            strcat(UTmp[i]," ");
    }
    for(i=TotUL; i<= 19; i++) {
        strcpy(UTmp[i],"                                 ");
    }
    printf("+-----------------------------------------------------------------------------+\n");
    printf("|       .____                     .___   ________                             |\n");
    printf("|       |    |    _________     __| _/  /  _____/_____    _____   ____        |\n");
    printf("|       |    |   /  _ \\__  \\   / __ |  /   \\  ___\\__  \\  /     \\_/ __ \\       |\n");
    printf("|       |    |__(  <_> ) __ \\_/ /_/ |  \\    \\_\\  \\/ __ \\|  Y Y  \\  ___/       |\n");
    printf("|       |_______ \\____(____  /\\____ |   \\______  (____  /__|_|  /\\___  >      |\n");
    printf("|               \\/         \\/      \\/          \\/     \\/      \\/     \\/       |\n");
    printf("|                                                                             |\n");
    printf("|    +---------------------------------+---------------------------------+    |\n");
    printf("|    |");if(sCursor == 1) SetColor(WHITE,BLUE);printf("%s", UTmp[0]);SetColor(YELLOW,DARK_PURPLE);printf("|");if(sCursor == 11) SetColor(WHITE,BLUE);printf("%s", UTmp[10]);SetColor(YELLOW,DARK_PURPLE);printf("|    |\n");
    printf("|    |");if(sCursor == 2) SetColor(WHITE,BLUE);printf("%s", UTmp[1]);SetColor(YELLOW,DARK_PURPLE);printf("|");if(sCursor == 12) SetColor(WHITE,BLUE);printf("%s", UTmp[11]);SetColor(YELLOW,DARK_PURPLE);printf("|    |\n");
    printf("|    |");if(sCursor == 3) SetColor(WHITE,BLUE);printf("%s", UTmp[2]);SetColor(YELLOW,DARK_PURPLE);printf("|");if(sCursor == 13) SetColor(WHITE,BLUE);printf("%s", UTmp[12]);SetColor(YELLOW,DARK_PURPLE);printf("|    |\n");
    printf("|    |");if(sCursor == 4) SetColor(WHITE,BLUE);printf("%s", UTmp[3]);SetColor(YELLOW,DARK_PURPLE);printf("|");if(sCursor == 14) SetColor(WHITE,BLUE);printf("%s", UTmp[13]);SetColor(YELLOW,DARK_PURPLE);printf("|    |\n");
    printf("|    |");if(sCursor == 5) SetColor(WHITE,BLUE);printf("%s", UTmp[4]);SetColor(YELLOW,DARK_PURPLE);printf("|");if(sCursor == 15) SetColor(WHITE,BLUE);printf("%s", UTmp[14]);SetColor(YELLOW,DARK_PURPLE);printf("|    |\n");
    printf("|    |");if(sCursor == 6) SetColor(WHITE,BLUE);printf("%s", UTmp[5]);SetColor(YELLOW,DARK_PURPLE);printf("|");if(sCursor == 16) SetColor(WHITE,BLUE);printf("%s", UTmp[15]);SetColor(YELLOW,DARK_PURPLE);printf("|    |\n");
    printf("|    |");if(sCursor == 7) SetColor(WHITE,BLUE);printf("%s", UTmp[6]);SetColor(YELLOW,DARK_PURPLE);printf("|");if(sCursor == 17) SetColor(WHITE,BLUE);printf("%s", UTmp[16]);SetColor(YELLOW,DARK_PURPLE);printf("|    |\n");
    printf("|    |");if(sCursor == 8) SetColor(WHITE,BLUE);printf("%s", UTmp[7]);SetColor(YELLOW,DARK_PURPLE);printf("|");if(sCursor == 18) SetColor(WHITE,BLUE);printf("%s", UTmp[17]);SetColor(YELLOW,DARK_PURPLE);printf("|    |\n");
    printf("|    |");if(sCursor == 9) SetColor(WHITE,BLUE);printf("%s", UTmp[8]);SetColor(YELLOW,DARK_PURPLE);printf("|");if(sCursor == 19) SetColor(WHITE,BLUE);printf("%s", UTmp[18]);SetColor(YELLOW,DARK_PURPLE);printf("|    |\n");
    printf("|    |");if(sCursor == 10) SetColor(WHITE,BLUE);printf("%s", UTmp[9]);SetColor(YELLOW,DARK_PURPLE);printf("|");if(sCursor == 20) SetColor(WHITE,BLUE);printf("%s", UTmp[19]);SetColor(YELLOW,DARK_PURPLE);printf("|    |\n");
    printf("|    +---------------------------------+---------------------------------+    |\n");
    printf("|");
    for(i=1;i<=59-IntLen(sPage) - IntLen(TotPage);i++)
        printf(" ");
    SetColor(WHITE,DARK_PURPLE);if(sCursor == 21) SetColor(WHITE,BLUE);printf("<<");SetColor(WHITE,DARK_PURPLE);printf(" ");if(sCursor == 22) SetColor(WHITE,BLUE);printf("<");SetColor(WHITE,DARK_PURPLE);printf(" %d OF %d ", sPage, TotPage);if(sCursor == 23) SetColor(WHITE,BLUE);printf(">");SetColor(WHITE,DARK_PURPLE);printf(" ");if(sCursor == 24) SetColor(WHITE,BLUE);printf(">>");SetColor(YELLOW,DARK_PURPLE);printf("    |\n");
    printf("|                                                                             |\n");
    printf("|                 USE ARROW FOR NAVIGATION AND ENTER TO SELECT                |\n");
    printf("+-----------------------------------------------------------------------------+\n");
}

// Prosedur simpan game dengan pesan sukses
void SimpanGameInterface(int UserID){
    system(CLEARCMD);
    SaveUser (FALSE, user[UserID].Uname, user[UserID].HS, user[UserID].Gori, user[UserID].ST, user[UserID].STWrd, user[UserID].STProg, user[UserID].STScr, user[UserID].STSlh);
    printf("+-----------------------------------------------------------------------------+\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                            ");SetColor(RED,DARK_PURPLE);printf("S I M P A N    G A M E");SetColor(YELLOW,DARK_PURPLE);printf("                           |\n");
    printf("|                          --------------------------                         |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                           Data anda telah disimpan!                         |\n");
    printf("|                        Tekan apapun untuk melanjutkan                       |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("+-----------------------------------------------------------------------------+\n");
}

// Prosedur untuk memprint Game over ke layar
void PrintGameOver(int Menu){
    system(CLEARCMD);
    printf("+-----------------------------------------------------------------------------+\n");
    printf("|         ________                        ________                            |\n");
    printf("|        /  _____/_____    _____   ____   \\_____  \\___  __ ___________        |\n");
    printf("|       /   \\  ___\\__  \\  /     \\_/ __ \\   /   |   \\  \\/ // __ \\_  __ \\       |\n");
    printf("|       \\    \\_\\  \\/ __ \\|  Y Y  \\  ___/  /    |    \\   /\\  ___/|  | \\/       |\n");
    printf("|        \\______  (____  /__|_|  /\\___  > \\_______  /\\_/  \\___  >__|          |\n");
    printf("|               \\/     \\/      \\/     \\/          \\/          \\/              |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                              Maaf anda kalah!                               |\n");
    printf("|                       Apakah anda ingin mencoba lagi?                       |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    if (Menu == 1){
        printf("|                             ");SetColor(WHITE, BLUE);printf("       Y O I       ");SetColor(YELLOW, DARK_PURPLE);printf("                             |\n");
        printf("|                                  N G G A K                                  |\n");
    }else{
        printf("|                                    Y O I                                    |\n");
        printf("|                             ");SetColor(WHITE, BLUE);printf("     N G G A K     ");SetColor(YELLOW, DARK_PURPLE);printf("                             |\n");
    }
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("+-----------------------------------------------------------------------------+\n");
}

// Prosedur untuk memprint penawaran simpan highscore
void PrintTawarHS (int Menu, int mUrut, int Skor){
    system(CLEARCMD);
    char teks[76];
    int i, len;
    printf("+-----------------------------------------------------------------------------+\n");
    printf("|             _   _    _    _   _  ____ __  __    _    _   _                  |\n");
    printf("|            | | | |  / \\  | \\ | |/ ___|  \\/  |  / \\  | \\ | |                 |\n");
    printf("|            | |_| | / _ \\ |  \\| | |  _| |\\/| | / _ \\ |  \\| |                 |\n");
    printf("|            |  _  |/ ___ \\| |\\  | |_| | |  | |/ ___ \\| |\\  |                 |\n");
    printf("|            |_| |_/_/   \\_|_| \\_|\\____|_|  |_/_/   \\_|_| \\_|                 |\n");
    printf("|            -----------------------------------------------------            |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    strcpy(teks, "Selamat ");
    strcat(teks,user[ActiveUser].Uname);
    strcat(teks,"! Anda masuk ke daftar highscore!");
    len = 38 - (strlen(teks)/2);
    printf("|");
    for (i=1;i<=len;i++)
        printf(" ");
    printf("%s", teks);
    for (i=0;i<=76-len-strlen(teks);i++)
        printf(" ");
    printf("|\n");
////////////////////////////////////////////////////////////////////
    len = 40 - (strlen(teks)/2) - (IntLen(mUrut)/2) - (IntLen(Skor)/2);
    printf("|");
    for (i=1;i<=len;i++)
        printf(" ");
    printf("Anda masuk ke urutan-%d dengan skor %d.", mUrut, Skor);
    for (i=0;i<=39-len-IntLen(mUrut)-IntLen(Skor);i++)
        printf(" ");
    printf("  |\n");
////////////////////////////////////////////////////////////////
    printf("|           Apakah anda ingin nama anda dimuat di tabel HighScore?            |\n");
    printf("|                                                                             |\n");
    if (Menu == 1){
        printf("|                             ");SetColor(WHITE, BLUE);printf("       I Y A       ");SetColor(YELLOW, DARK_PURPLE);printf("                             |\n");
        printf("|                                  N G G A K                                  |\n");
    }else{
        printf("|                                    I Y A                                    |\n");
        printf("|                             ");SetColor(WHITE, BLUE);printf("     N G G A K     ");SetColor(YELLOW, DARK_PURPLE);printf("                             |\n");
    }
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("+-----------------------------------------------------------------------------+\n");
}

// Prosedur untuk memprint informasi bahwa game sudah berakhir
void PrintGameFinished(BOOL Tamat, int Menu){
    system(CLEARCMD);
    char teks[76];
    int i, len;

    printf("+-----------------------------------------------------------------------------+\n");
    printf("|             _   _    _    _   _  ____ __  __    _    _   _                  |\n");
    printf("|            | | | |  / \\  | \\ | |/ ___|  \\/  |  / \\  | \\ | |                 |\n");
    printf("|            | |_| | / _ \\ |  \\| | |  _| |\\/| | / _ \\ |  \\| |                 |\n");
    printf("|            |  _  |/ ___ \\| |\\  | |_| | |  | |/ ___ \\| |\\  |                 |\n");
    printf("|            |_| |_/_/   \\_|_| \\_|\\____|_|  |_/_/   \\_|_| \\_|                 |\n");
    printf("|            -----------------------------------------------------            |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");


    if (Tamat){
        strcpy(teks, "Selamat ");
        strcat(teks,user[ActiveUser].Uname);
        strcat(teks,"! Anda telah menyelesaikan game ini!");
        len = 38 - (strlen(teks)/2);
        printf("|");
        for (i=1;i<=len;i++)
            printf(" ");
        printf("%s", teks);
        for (i=0;i<=76-len-strlen(teks);i++)
            printf(" ");
        printf("|\n");

    }else{
        printf("|            Maaf, tapi kategori ini sudah pernah anda selesaikan.            |\n");
    }
    printf("|              Apakah anda ingin mencoba kategori/level lainnya?              |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    if (Menu == 1){
        printf("|                             ");SetColor(WHITE, BLUE);printf("       I Y A       ");SetColor(YELLOW, DARK_PURPLE);printf("                             |\n");
        printf("|                                  N G G A K                                  |\n");
    }else{
        printf("|                                    I Y A                                    |\n");
        printf("|                             ");SetColor(WHITE, BLUE);printf("     N G G A K     ");SetColor(YELLOW, DARK_PURPLE);printf("                             |\n");
    }
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("+-----------------------------------------------------------------------------+\n");
}

// Prosedur untuk menawarkan save game ke user
void PrintTawarSave(int Menu){
    system(CLEARCMD);
    printf("+-----------------------------------------------------------------------------+\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                            ");SetColor(RED,DARK_PURPLE);printf("S I M P A N    G A M E");SetColor(YELLOW,DARK_PURPLE);printf("                           |\n");
    printf("|                          --------------------------                         |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|              Apakah anda ingin menyimpan progress anda sebelum              |\n");
    printf("|               meninggalkan permainan yang sedang berlangsung?               |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    if (Menu == 1){
        printf("|                             ");SetColor(WHITE, BLUE);printf("       I Y A       ");SetColor(YELLOW, DARK_PURPLE);printf("                             |\n");
        printf("|                                  N G G A K                                  |\n");
    }else{
        printf("|                                    I Y A                                    |\n");
        printf("|                             ");SetColor(WHITE, BLUE);printf("     N G G A K     ");SetColor(YELLOW, DARK_PURPLE);printf("                             |\n");
    }
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("+-----------------------------------------------------------------------------+\n");
}

// Fungsi untuk menanyakan apakah user mau mensave highscorenya atau tidak
BOOL TawarSaveHS(int UserID, int mUrut, int mSkor){
    char ch1, ch2;
    int mmPos = 1;
    PrintTawarHS(mmPos, mUrut, mSkor);
    do {
        if (kbhit()){
            ch1 = getch();
            if (ch1 <= 0) {
                ch2 = getch();
                int whichkey = 0;
                switch(ch2){
                    case 'H':   whichkey = PANAH_UP; break;
                    case 'P':   whichkey = PANAH_DOWN; break;
                    default:    break;
                }
                if (whichkey) {
                    if ((whichkey == PANAH_UP) && mmPos > 1) {
                        mmPos--;
                        PrintTawarHS(mmPos, mUrut, mSkor);
                    }else if ((whichkey == PANAH_DOWN) && mmPos < 2){
                        mmPos++;
                        PrintTawarHS(mmPos, mUrut, mSkor);
                    }
                }
            }
        }
    }while(ch1 != 0x0D);
    switch(mmPos) {
        case 1: return TRUE; break;
        case 2: return FALSE; break;
    }
}

// Fungsi untuk menawarkan ke user apakah ia mau mensave gamenya atau tidak
void TawarSaveGame(int UserID){
    char ch1, ch2;
    int mmPos = 1;
    PrintTawarSave(mmPos);
    do {
        if (kbhit()){
            ch1 = getch();
            if (ch1 <= 0) {
                ch2 = getch();
                int whichkey = 0;
                switch(ch2){
                    case 'H':   whichkey = PANAH_UP; break;
                    case 'P':   whichkey = PANAH_DOWN; break;
                    default:    break;
                }
                if (whichkey) {
                    if ((whichkey == PANAH_UP) && mmPos > 1) {
                        mmPos--;
                        PrintTawarSave(mmPos);
                    }else if ((whichkey == PANAH_DOWN) && mmPos < 2){
                        mmPos++;
                        PrintTawarSave(mmPos);
                    }
                }
            }
        }
    }while(ch1 != 0x0D);
    switch(mmPos) {
        case 1: SaveUser (FALSE, user[UserID].Uname, user[UserID].HS, user[UserID].Gori, user[UserID].ST, user[UserID].STWrd, user[UserID].STProg, user[UserID].STScr, user[UserID].STSlh); break;
        case 2: break;
    }
}

// Memprint menu pause multiplayer
void PrintPauseMulti(int mPos) {
    system(CLEARCMD);
    printf("+-----------------------------------------------------------------------------+\n");
    printf("|             __________  _____   ____ ___  ____________________              |\n");
    printf("|             \\______   \\/  _  \\ |    |   \\/   _____/\\_   _____/              |\n");
    printf("|              |     ___/  /_\\  \\|    |   /\\_____  \\  |    __)_               |\n");
    printf("|              |    |  /    |    \\    |  / /        \\ |        \\              |\n");
    printf("|              |____|  \\____|__  /______/ /_______  //_______  /              |\n");
    printf("|                              \\/                 \\/         \\/               |\n");
    printf("|                   APAAN? PAUS? BUKAN PAUS COY! TAPI PAUSE!                  |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                             P A U S E   M E N U                             |\n");
    printf("|                            ---------------------                            |\n");
    switch (mPos) {
        case 1  :   printf("|");SetColor(WHITE,DARK_PURPLE);printf("                             -> Lanjutkan Game <-                            ");SetColor(YELLOW,DARK_PURPLE);printf("|\n");
                    printf("|                                Buat Game Baru                               |\n");
                    printf("|                            Kembali ke  MENU Utama                           |\n");
                    printf("|                                 KELUAR  GAME                                |\n");break;
        case 2  :   printf("|                                Lanjutkan Game                               |\n");
                    printf("|");SetColor(WHITE,DARK_PURPLE);printf("                             -> Buat Game Baru <-                            ");SetColor(YELLOW,DARK_PURPLE);printf("|\n");
                    printf("|                            Kembali ke  MENU Utama                           |\n");
                    printf("|                                 KELUAR  GAME                                |\n");break;
        case 3  :   printf("|                                Lanjutkan Game                               |\n");
                    printf("|                                Buat Game Baru                               |\n");
                    printf("|");SetColor(WHITE,DARK_PURPLE);printf("                         -> Kembali ke  MENU Utama <-                        ");SetColor(YELLOW,DARK_PURPLE);printf("|\n");
                    printf("|                                 KELUAR  GAME                                |\n");break;
        case 4  :   printf("|                                Lanjutkan Game                               |\n");
                    printf("|                                Buat Game Baru                               |\n");
                    printf("|                            Kembali ke  MENU Utama                           |\n");
                    printf("|");SetColor(WHITE,DARK_PURPLE);printf("                              -> KELUAR  GAME <-                             ");SetColor(YELLOW,DARK_PURPLE);printf("|\n");break;
    }
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                USE UP AND DOWN ARROW AND ENTER TO SELECT MENU               |\n");
    printf("+-----------------------------------------------------------------------------+\n");
}

// memprint menu pause single player
void PrintPauseSingle(int mPos) {
    system(CLEARCMD);
    printf("+-----------------------------------------------------------------------------+\n");
    printf("|             __________  _____   ____ ___  ____________________              |\n");
    printf("|             \\______   \\/  _  \\ |    |   \\/   _____/\\_   _____/              |\n");
    printf("|              |     ___/  /_\\  \\|    |   /\\_____  \\  |    __)_               |\n");
    printf("|              |    |  /    |    \\    |  / /        \\ |        \\              |\n");
    printf("|              |____|  \\____|__  /______/ /_______  //_______  /              |\n");
    printf("|                              \\/                 \\/         \\/               |\n");
    printf("|                   APAAN? PAUS? BUKAN PAUS COY! TAPI PAUSE!                  |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                             P A U S E   M E N U                             |\n");
    printf("|                            ---------------------                            |\n");
    switch (mPos) {
        case 1  :   printf("|");SetColor(WHITE,DARK_PURPLE);printf("                             -> Lanjutkan Game <-                            ");SetColor(YELLOW,DARK_PURPLE);printf("|\n");
                    printf("|                                Simpan Progres                               |\n");
                    printf("|                                Buat Game Baru                               |\n");
                    printf("|                             Kembali ke HOME User                            |\n");
                    printf("|                            Kembali ke  MENU Utama                           |\n");
                    printf("|                                 KELUAR  GAME                                |\n");break;
        case 2  :   printf("|                                Lanjutkan Game                               |\n");
                    printf("|");SetColor(WHITE,DARK_PURPLE);printf("                             -> Simpan Progres <-                            ");SetColor(YELLOW,DARK_PURPLE);printf("|\n");
                    printf("|                                Buat Game Baru                               |\n");
                    printf("|                             Kembali ke HOME User                            |\n");
                    printf("|                            Kembali ke  MENU Utama                           |\n");
                    printf("|                                 KELUAR  GAME                                |\n");break;
        case 3  :   printf("|                                Lanjutkan Game                               |\n");
                    printf("|                                Simpan Progres                               |\n");
                    printf("|");SetColor(WHITE,DARK_PURPLE);printf("                             -> Buat Game Baru <-                            ");SetColor(YELLOW,DARK_PURPLE);printf("|\n");
                    printf("|                             Kembali ke HOME User                            |\n");
                    printf("|                            Kembali ke  MENU Utama                           |\n");
                    printf("|                                 KELUAR  GAME                                |\n");break;
        case 4  :   printf("|                                Lanjutkan Game                               |\n");
                    printf("|                                Simpan Progres                               |\n");
                    printf("|                                Buat Game Baru                               |\n");
                    printf("|");SetColor(WHITE,DARK_PURPLE);printf("                          -> Kembali ke HOME User <-                         ");SetColor(YELLOW,DARK_PURPLE);printf("|\n");
                    printf("|                            Kembali ke  MENU Utama                           |\n");
                    printf("|                                 KELUAR  GAME                                |\n");break;
        case 5  :   printf("|                                Lanjutkan Game                               |\n");
                    printf("|                                Simpan Progres                               |\n");
                    printf("|                                Buat Game Baru                               |\n");
                    printf("|                             Kembali ke HOME User                            |\n");
                    printf("|");SetColor(WHITE,DARK_PURPLE);printf("                         -> Kembali ke  MENU Utama <-                        ");SetColor(YELLOW,DARK_PURPLE);printf("|\n");
                    printf("|                                 KELUAR  GAME                                |\n");break;
        case 6  :   printf("|                                Lanjutkan Game                               |\n");
                    printf("|                                Simpan Progres                               |\n");
                    printf("|                                Buat Game Baru                               |\n");
                    printf("|                             Kembali ke HOME User                            |\n");
                    printf("|                            Kembali ke  MENU Utama                           |\n");
                    printf("|");SetColor(WHITE,DARK_PURPLE);printf("                              -> KELUAR  GAME <-                             ");SetColor(YELLOW,DARK_PURPLE);printf("|\n");break;
    }
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                USE UP AND DOWN ARROW AND ENTER TO SELECT MENU               |\n");
    printf("+-----------------------------------------------------------------------------+\n");
}

// Memprint Single Setup (Setup permainan sebelum dimulai)
void PrintSingleSetup(int level, char* cat, int pos, BOOL NoCat, BOOL Err){
    int lebar, i,j;
    char cats[24];
    strcpy(cats, "");

    system(CLEARCMD);
    printf("+-----------------------------------------------------------------------------+\n");
    printf("|                                   ___                                       |\n");
    printf("|                                  (   .-.          .-.                       |\n");
    printf("|          .--.    .--. ___ .-.  .-.| ( __)___ .-. ( __) .---. ___ .-.        |\n");
    printf("|        /  _  \\  /    (   )   \\/   \\ ('' (   )   \\('' )/ .-, (   )   \\       |\n");
    printf("|       . .' `. ;|  .-. |  .-. |  .-. || | | ' .-. ;| |(__) ; ||  .-. .       |\n");
    printf("|       | '   | ||  | | | |  | | |  | || | |  / (___| |  .'`  || |  | |       |\n");
    printf("|       _\\_`.(___|  |/  | |  | | |  | || | | |      | | / .'| || |  | |       |\n");
    printf("|      (   ). '. |  ' _.| |  | | |  | || | | |      | || /  | || |  | |       |\n");
    printf("|       | |  `\\ ||  .'.-| |  | | '  | || | | |      | |; |  ; || |  | |       |\n");
    printf("|       ; '._,' ''  `-' | |  | ' `-'  /| | | |      | |' `-'  || |  | |       |\n");
    printf("|        '.___.'  `.__.(___)(___`.__,'(___(___)    (___`.__.'_(___)(___)      |\n");
    printf("|                                                                             |\n");
    printf("|                                GAME OPTIONS                                 |\n");
    printf("|                               --------------                                |\n");
    printf("|                                                                             |\n");

    printf("|              TINGKAT KESULITAN  :   ");if (pos == 1) {
                                                        SetColor(WHITE,BLUE);
                                                        switch (level) {
                                                            case 1: printf("<          GAMPIL         >"); break;
                                                            case 2: printf("<     BIASA AJA/NORMAL    >"); break;
                                                            case 3: printf("<          SABLENG        >"); break;
                                                        }
                                                        SetColor(YELLOW,DARK_PURPLE);
                                                    }else{
                                                        switch (level) {
                                                            case 1: printf("           GAMPIL          "); break;
                                                            case 2: printf("      BIASA AJA/NORMAL     "); break;
                                                            case 3: printf("           SABLENG         "); break;
                                                        }
                                                    }printf("             |\n");
    printf("|                       KATEGORI  :   ");if (NoCat) {
                                                        SetColor(WHITE, RED);
                                                        printf("   NO CATEGORY AVAILABLE   ");
                                                        SetColor(YELLOW,DARK_PURPLE);
                                                    }else{
                                                        lebar = strlen(cat);
                                                        j = 11 - (lebar/2);
                                                        for(i=1;i<=j;i++)
                                                            strcat(cats, " ");
                                                        //end for
                                                        strcat(cats,cat);
                                                        for (i=1;i<=23-j-lebar;i++)
                                                            strcat(cats, " ");
                                                        if (pos == 2) {
                                                            SetColor(WHITE,BLUE);
                                                            printf("< %s >", cats);
                                                            SetColor(YELLOW,DARK_PURPLE);
                                                        }else{
                                                            printf("  %s  ", cats);
                                                        }
                                                    }printf("             |\n");

    printf("|                                                                             |\n");
    printf("|                                  ");if(pos==3)SetColor(WHITE,BLUE); printf("[LANJUT]");SetColor(YELLOW,DARK_PURPLE);printf("                                   |\n");
    printf("|                                                                             |\n");
    printf("|                        ");
        if (Err) {
            SetColor(WHITE,RED);
            printf("Please select Valid Category");
            SetColor(YELLOW,DARK_PURPLE);
        }else{
            printf("                            ");
        }printf("                         |\n");
    printf("|         Gunakan UP/DOWN untuk navigasi dan LEFT/RIGHT untuk memilih         |\n");
    printf("+-----------------------------------------------------------------------------+\n");
}

// menset interface awal (warna dan kursor)
void setupinterface() {
  CONSOLE_CURSOR_INFO cursor = {1, FALSE};
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
  system("color 5e");
}

// memprint form new game / new user
void PrintNewGame (char* Username, char* errs, int CurPos){
    int lebar, i;
    system(CLEARCMD);
    printf("+-----------------------------------------------------------------------------+\n");
    printf("|                                   ___                                       |\n");
    printf("|                                  (   .-.          .-.                       |\n");
    printf("|          .--.    .--. ___ .-.  .-.| ( __)___ .-. ( __) .---. ___ .-.        |\n");
    printf("|        /  _  \\  /    (   )   \\/   \\ ('' (   )   \\('' )/ .-, (   )   \\       |\n");
    printf("|       . .' `. ;|  .-. |  .-. |  .-. || | | ' .-. ;| |(__) ; ||  .-. .       |\n");
    printf("|       | '   | ||  | | | |  | | |  | || | |  / (___| |  .'`  || |  | |       |\n");
    printf("|       _\\_`.(___|  |/  | |  | | |  | || | | |      | | / .'| || |  | |       |\n");
    printf("|      (   ). '. |  ' _.| |  | | |  | || | | |      | || /  | || |  | |       |\n");
    printf("|       | |  `\\ ||  .'.-| |  | | '  | || | | |      | |; |  ; || |  | |       |\n");
    printf("|       ; '._,' ''  `-' | |  | ' `-'  /| | | |      | |' `-'  || |  | |       |\n");
    printf("|        '.___.'  `.__.(___)(___`.__,'(___(___)    (___`.__.'_(___)(___)      |\n");
    printf("|                                                                             |\n");
    printf("|                               NEW SINGLE GAME                               |\n");
    printf("|                               ---------------                               |\n");
    printf("|                                                                             |\n");
    printf("|                               +--------------------------+                  |\n");
    printf("|           Pilih username   :  | ");

    lebar = 24 - strlen(Username);
    if (CurPos > strlen(Username)){
        printf("%s",Username);
        SetColor(WHITE,WHITE);printf(" ");SetColor(YELLOW,DARK_PURPLE);
    }else{
        for(i=0;i<strlen(Username);i++){
            if(CurPos == (i + 1)) {
                SetColor(YELLOW,WHITE);
                printf("%c", Username[i]);
                SetColor(YELLOW,DARK_PURPLE);
            }else{
                printf("%c", Username[i]);
            }
        }
        printf(" ");
    }
    for (i=1;i<=lebar;i++)
        printf(" ");
    printf("|                  |\n");
    printf("|                               +--------------------------+                  |\n");
    printf("|                                                                             |\n");
    if (strlen(errs) > 0) {
        printf("|");
        lebar = 38 - (strlen(errs)/2);
        for (i=1;i<=lebar;i++) {
            printf(" ");
        }
        SetColor(WHITE,RED);
        printf("%s", errs);
        SetColor(YELLOW,DARK_PURPLE);
        for (i=1;i<=(77-lebar-strlen(errs));i++) {
            printf(" ");
        }
        printf("|\n");
    }else{
        printf("|                                                                             |\n");
    }
    printf("|                                                                             |\n");
    printf("|                        Tekan enter untuk melanjutkan                        |\n");
    printf("+-----------------------------------------------------------------------------+\n");
}

// membuat gambar hangman sesuai jumlah kesalahan user
void PrintHangman(int Salah, HGM Hangman){
    switch(Salah) {
        case 0  : Hangman[0] = " ------ ";
                  Hangman[1] = " |      ";
                  Hangman[2] = " |      ";
                  Hangman[3] = " |      ";
                  Hangman[4] = " |      ";
                  Hangman[5] = " |      ";
                  Hangman[6] = " |      ";
                  Hangman[7] = " |      "; break;
        case 1  : Hangman[0] = " ------ ";
                  Hangman[1] = " |    | ";
                  Hangman[2] = " |      ";
                  Hangman[3] = " |      ";
                  Hangman[4] = " |      ";
                  Hangman[5] = " |      ";
                  Hangman[6] = " |      ";
                  Hangman[7] = " |      "; break;
        case 2  : Hangman[0] = " ------ ";
                  Hangman[1] = " |    | ";
                  Hangman[2] = " |    O ";
                  Hangman[3] = " |      ";
                  Hangman[4] = " |      ";
                  Hangman[5] = " |      ";
                  Hangman[6] = " |      ";
                  Hangman[7] = " |      "; break;
        case 3  : Hangman[0] = " ------ ";
                  Hangman[1] = " |    | ";
                  Hangman[2] = " |    O ";
                  Hangman[3] = " |    | ";
                  Hangman[4] = " |      ";
                  Hangman[5] = " |      ";
                  Hangman[6] = " |      ";
                  Hangman[7] = " |      "; break;
        case 4  : Hangman[0] = " ------ ";
                  Hangman[1] = " |    | ";
                  Hangman[2] = " |    O ";
                  Hangman[3] = " |   -| ";
                  Hangman[4] = " |      ";
                  Hangman[5] = " |      ";
                  Hangman[6] = " |      ";
                  Hangman[7] = " |      "; break;
        case 5  : Hangman[0] = " ------ ";
                  Hangman[1] = " |    | ";
                  Hangman[2] = " |    O ";
                  Hangman[3] = " |   -|-";
                  Hangman[4] = " |      ";
                  Hangman[5] = " |      ";
                  Hangman[6] = " |      ";
                  Hangman[7] = " |      "; break;
        case 6  : Hangman[0] = " ------ ";
                  Hangman[1] = " |    | ";
                  Hangman[2] = " |    O ";
                  Hangman[3] = " |   -|-";
                  Hangman[4] = " |    | ";
                  Hangman[5] = " |      ";
                  Hangman[6] = " |      ";
                  Hangman[7] = " |      "; break;
        case 7  : Hangman[0] = " ------ ";
                  Hangman[1] = " |    | ";
                  Hangman[2] = " |    O ";
                  Hangman[3] = " |   -|-";
                  Hangman[4] = " |    | ";
                  Hangman[5] = " |   /  ";
                  Hangman[6] = " |      ";
                  Hangman[7] = " |      "; break;
        case 8  : Hangman[0] = " ------ ";
                  Hangman[1] = " |    | ";
                  Hangman[2] = " |    O ";
                  Hangman[3] = " |   -|-";
                  Hangman[4] = " |    | ";
                  Hangman[5] = " |   / \\";
                  Hangman[6] = " |      ";
                  Hangman[7] = " |      "; break;
    }
}

// memprint game over untuk multiplayer
void PrintGameOverMulti(int Menu, USR Winner, USR Loser){
    int len, i;
    system(CLEARCMD);
    printf("+-----------------------------------------------------------------------------+\n");
    printf("|         ________                        ________                            |\n");
    printf("|        /  _____/_____    _____   ____   \\_____  \\___  __ ___________        |\n");
    printf("|       /   \\  ___\\__  \\  /     \\_/ __ \\   /   |   \\  \\/ // __ \\_  __ \\       |\n");
    printf("|       \\    \\_\\  \\/ __ \\|  Y Y  \\  ___/  /    |    \\   /\\  ___/|  | \\/       |\n");
    printf("|        \\______  (____  /__|_|  /\\___  > \\_______  /\\_/  \\___  >__|          |\n");
    printf("|               \\/     \\/      \\/     \\/          \\/          \\/              |\n");
    printf("|                                                                             |\n");

    printf("|                            WORD WAR DUEL MATCH                              |\n");
    printf("|              ------------------------------------------------               |\n");
    printf("|");
    len = 28-strlen(Winner.Uname)/2;
    for (i=1;i<=len;i++)
        printf(" ");
    printf("DIMENANGKAN OLEH %s", Winner.Uname);
    for (i=1;i<=60-len-strlen(Winner.Uname);i++)
        printf(" ");printf("|\n");

    printf("|");
    len = 31-IntLen(Winner.HS)/2;
    for (i=1;i<=len;i++)
        printf(" ");
    printf("DENGAN SKOR %d", Winner.HS);
    for (i=1;i<=65-len-IntLen(Winner.HS);i++)
        printf(" ");printf("|\n");

    printf("|");
    len = 29-strlen(Loser.Uname)/2-IntLen(Loser.HS)/2;
    for (i=1;i<=len;i++)
        printf(" ");
    printf("MENGALAHKAN %s (%d)", Loser.Uname , Loser.HS);
    for (i=1;i<=62-len-strlen(Loser.Uname)-IntLen(Loser.HS);i++)
        printf(" ");printf("|\n");

    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                             Ingin bermain lagi?                             |\n");
    if (Menu == 1){
        printf("|                             ");SetColor(WHITE, BLUE);printf("       Y O I       ");SetColor(YELLOW, DARK_PURPLE);printf("                             |\n");
        printf("|                                  N G G A K                                  |\n");
    }else{
        printf("|                                    Y O I                                    |\n");
        printf("|                             ");SetColor(WHITE, BLUE);printf("     N G G A K     ");SetColor(YELLOW, DARK_PURPLE);printf("                             |\n");
    }
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("+-----------------------------------------------------------------------------+\n");
}

// memprint mode multiplayer (buat pertanyaan)
void PrintBuatPertanyaan(char* Username, int Skor, char* Pertanyaan, char* Jawaban, char* errs, int CurPos, int TexPos){
    int lebar, i;
    system(CLEARCMD);
    printf("+-----------------------------------------------------------------------------+\n");
    printf("|                                BUAT PERTANYAAN                              |\n");
    printf("|  Giliran : %s ", Username);
    for(i=1;i<=46-strlen(Username);i++)
        printf(" ");
    printf("Skor : %d ", Skor);
    for(i=1;i<=10-IntLen(Skor);i++)
        printf(" ");
    printf("|\n");
    printf("+-----------------------------------------------------------------------------+\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                              P E R T A N Y A A N                            |\n");
    printf("|            +----------------------------------------------------+           |\n");
    printf("|            | ");

    lebar = 50 - strlen(Pertanyaan);
    if (TexPos == 1) {
        if (CurPos > strlen(Pertanyaan)){
            printf("%s",Pertanyaan);
            SetColor(WHITE,WHITE);printf(" ");SetColor(YELLOW,DARK_PURPLE);
        }else{
            for(i=0;i<strlen(Pertanyaan);i++){
                if(CurPos == (i + 1)) {
                    SetColor(YELLOW,WHITE);
                    printf("%c", Pertanyaan[i]);
                    SetColor(YELLOW,DARK_PURPLE);
                }else{
                    printf("%c", Pertanyaan[i]);
                }
            }
            printf(" ");
        }
    }else{
        printf("%s",Pertanyaan);
        printf(" ");
    }
    for (i=1;i<=lebar;i++)
        printf(" ");
    printf("|           |\n");
    printf("|            +----------------------------------------------------+           |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                J A W A B A N                                |\n");
    printf("|            +----------------------------------------------------+           |\n");
    printf("|            | ");

    lebar = 50 - strlen(Jawaban);
    if (TexPos == 2) {
        if (CurPos > strlen(Jawaban)){
            printf("%s",Jawaban);
            SetColor(WHITE,WHITE);printf(" ");SetColor(YELLOW,DARK_PURPLE);
        }else{
            for(i=0;i<strlen(Jawaban);i++){
                if(CurPos == (i + 1)) {
                    SetColor(YELLOW,WHITE);
                    printf("%c", Jawaban[i]);
                    SetColor(YELLOW,DARK_PURPLE);
                }else{
                    printf("%c", Jawaban[i]);
                }
            }
            printf(" ");
        }
    }else{
        printf("%s",Jawaban);
        printf(" ");
    }
    for (i=1;i<=lebar;i++)
        printf(" ");
    printf("|           |\n");
    printf("|            +----------------------------------------------------+           |\n");
    printf("|                                                                             |\n");
    if (strlen(errs) > 0) {
        printf("|");
        lebar = 38 - (strlen(errs)/2);
        for (i=1;i<=lebar;i++) {
            printf(" ");
        }
        SetColor(WHITE,RED);
        printf("%s", errs);
        SetColor(YELLOW,DARK_PURPLE);
        for (i=1;i<=(77-lebar-strlen(errs));i++) {
            printf(" ");
        }
        printf("|\n");
    }else{
        printf("|                                                                             |\n");
    }
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|          GUNAKAN UP/DOWN/TAB UNTUK PINDAH, ENTER UNTUK MELANJUTKAN          |\n");
    printf("+-----------------------------------------------------------------------------+\n");
}

// memprint form input user untuk mode multiplayer
void PrintMultiSetup(char* Username, int Player, char* errs, int CurPos){
    int lebar, i;
    system(CLEARCMD);
    printf("+-----------------------------------------------------------------------------+\n");
    printf("|                _       __               __   _       __                     |\n");
    printf("|               | |     / /___  _________/ /  | |     / /___ ______           |\n");
    printf("|               | | /| / / __ \\/ ___/ __  /   | | /| / / __ `/ ___/           |\n");
    printf("|               | |/ |/ / /_/ / /  / /_/ /    | |/ |/ / /_/ / /               |\n");
    printf("|               |__/|__/\\____/_/   \\__,_/     |__/|__/\\__,_/_/                |\n");
    printf("|                                                                             |\n");
    printf("|                                        HANG-MAN MULTIPLAYER 1.0             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                   PLAYER %d                                  |\n", Player);
    printf("|                               ---------------                               |\n");
    printf("|                                                                             |\n");
    printf("|                               +--------------------------+                  |\n");
    printf("|           Pilih username   :  | ");

    lebar = 24 - strlen(Username);
    if (CurPos > strlen(Username)){
        printf("%s",Username);
        SetColor(WHITE,WHITE);printf(" ");SetColor(YELLOW,DARK_PURPLE);
    }else{
        for(i=0;i<strlen(Username);i++){
            if(CurPos == (i + 1)) {
                SetColor(YELLOW,WHITE);
                printf("%c", Username[i]);
                SetColor(YELLOW,DARK_PURPLE);
            }else{
                printf("%c", Username[i]);
            }
        }
        printf(" ");
    }
    for (i=1;i<=lebar;i++)
        printf(" ");
    printf("|                  |\n");
    printf("|                               +--------------------------+                  |\n");
    printf("|                                                                             |\n");
    if (strlen(errs) > 0) {
        printf("|");
        lebar = 38 - (strlen(errs)/2);
        for (i=1;i<=lebar;i++) {
            printf(" ");
        }
        SetColor(WHITE,RED);
        printf("%s", errs);
        SetColor(YELLOW,DARK_PURPLE);
        for (i=1;i<=(77-lebar-strlen(errs));i++) {
            printf(" ");
        }
        printf("|\n");
    }else{
        printf("|                                                                             |\n");
    }
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                        Tekan enter untuk melanjutkan                        |\n");
    printf("+-----------------------------------------------------------------------------+\n");
}

// memprint daftar top 10 highscore
void PrintHighscore(){
    int i, j,  len;
    system(CLEARCMD);
    printf("+-----------------------------------------------------------------------------+\n");
    printf("|     ___                                                                     |\n");
    printf("|    -   ---___- ,,                  /\\\\,/\\\\,               ,                 |\n");
    printf("|       (' ||    ||                 /| || ||    _          ||                 |\n");
    printf("|      ((  ||    ||/\\\\  _-_         || || ||   < \\,  _-_, =||=  _-_  ,._-_    |\n");
    printf("|     ((   ||    || || || \\\\        ||=|= ||   /-|| ||_.   ||  || \\\\  ||      |\n");
    printf("|      (( //     || || ||/         ~|| || ||  (( ||  ~ ||  ||  ||/    ||      |\n");
    printf("|        -____-  \\\\ |/ \\\\,/         |, \\\\,\\\\,  \\/\\\\ ,-_-   \\\\, \\\\,/   \\\\,     |\n");
    printf("|                  _/              _-                                         |\n");
    printf("|                                                                             |\n");
    printf("|    ");SetColor(WHITE,0);printf("  #  |        USER NAME         |    SCORE    |       TANGGAL        ");SetColor(YELLOW,DARK_PURPLE);printf("    |\n");
    for (i=0;i<=9;i++){
        printf("|    ");SetColor(0,GREY);
        if (i<9) printf("  %d  |", i + 1);
        else printf("  %d |", i + 1); ;
        if(HiScore[i].UID != -1){
            len = 12 - strlen(user[HiScore[i].UID].Uname)/2;
            for (j=1;j<=len;j++)
                printf(" ");
            printf("%s", user[HiScore[i].UID].Uname);
            for (j=1;j<=26-len-strlen(user[HiScore[i].UID].Uname);j++)
                printf(" ");

            printf("|");

            len = 6 - IntLen(HiScore[i].Score)/2;
            for (j=1;j<=len;j++)
                printf(" ");
            printf("%d", HiScore[i].Score);
            for (j=1;j<14-len-IntLen(HiScore[i].Score);j++)
                printf(" ");

            printf("|");

            len = 11 - strlen(HiScore[i].Tanggal)/2;
            for (j=1;j<=len;j++)
                printf(" ");
            printf("%s", HiScore[i].Tanggal);
            for (j=1;j<=22-len-strlen(HiScore[i].Tanggal);j++)
                printf(" ");

            SetColor(YELLOW,DARK_PURPLE);printf("    |\n");
        }else{
            printf("        BELUM ADA         |     N/A     |         N/A          ");SetColor(YELLOW,DARK_PURPLE);printf("    |\n");
        }
    }
    printf("|                                                                             |\n");
    printf("|                      Tekan tombol apa aja untuk keluar                      |\n");
    printf("+-----------------------------------------------------------------------------+\n");
}

// memprint error dan keluar dari program
void PrintError(char* msg) {
    int len, mid, i;
    system(CLEARCMD);
    SetColor(WHITE,RED);
    system(CLEARCMD);
    printf("+-----------------------------------------------------------------------------+\n");
    printf("|                       TERJADI SEBUAH ERROR YANG FATAL                       |\n");
    printf("|                       -------------------------------                       |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|");
    len = strlen(msg);
    mid = 38 - (len/2);
    for(i=1;i<=mid;i++){
        printf(" ");
    }
    printf("%s",msg);
    for(i=1;i<=(77-len-mid);i++){
        printf(" ");
    }
    printf("|\n");
    //printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                   Tekan tombol apapun untuk keluar aplikasi                 |\n");
    printf("+-----------------------------------------------------------------------------+\n");
    getch();
    exit (1);
}

// memprint mode permainan multiplayer (gameplay)
void PrintGameMulti(char* usr, int skor, char quest[], char kata[], BOOL prgs[], int salah, char* msg) {
    int i, len, baris, j;
    char * tokn = NULL;
    char * dl = " ";
    char str[300];
    HGM Hangman;
    char helper[3][55];
    int cntr[3];
    i = 0;
    while(quest[i]!='\0'){
        str[i] = quest[i];
        i++;
    }
    str[i]='\0';
    system(CLEARCMD);
    printf("+-----------------------------------------------------------------------------+\n");
    printf("|                               WORD WAR MODE                                 |\n");
    printf("| USER       :    %s", usr);
    for (i=1;i<=34-strlen(usr);i++)
        printf(" ");
    // end for
    printf("                          |\n");

    printf("| SKOR       :    %d",skor);
    for(i=1;i<=60 - IntLen(skor);i++)
        printf(" ");
    printf("|\n");

    printf("+-----------------------------------------------------------------------------+\n");
    printf("| PERTANYAAN :    ");
    len = 1; baris = 1;
    tokn = strtok(str,dl);
    while(tokn!=NULL) {
        if (len + strlen(tokn) + 1 <= 59) {
            printf("%s ", tokn);
            len += strlen(tokn) + 1;
            i++;
            tokn = strtok(NULL, dl);
        }else{
            for (i=1;i<=61 - len;i++)
                printf(" ");
            printf("|\n|                 ");
            baris++;
            len = 1;
        }
    }
    for (i=1;i<=61 - len;i++)
        printf(" ");
    printf("|\n");
    for (i = 1; i<=4 - baris; i++)
        printf("|                                                                             |\n");
    //end for
    PrintHangman(salah,Hangman);
    printf("|                                                                             |\n");
    printf("|                                                              %s       |\n", Hangman[0]);
    i = 0;
    while(kata[i]!='\0'){
        str[i] = kata[i];
        i++;
    }
    str[i]='\0';
    strcpy(helper[0],"");
    strcpy(helper[1],"");
    strcpy(helper[2],"");


    len = 0; baris = 0;
    tokn = strtok(str,dl);
    while(tokn!=NULL) {
        if (len + strlen(tokn) * 2 <= 52) {
            len += strlen(tokn) * 2 + 2;
            i++;
            tokn = strtok(NULL, dl);
        }else{
            cntr[baris] = 26 - (len / 2);
            baris++;
            len = 1;
        }
    }
    cntr[baris] = 26 - (len / 2);
    i = 0;
    while(kata[i]!='\0'){
        str[i] = kata[i];
        i++;
    }
    str[i]='\0';

    len = 0; baris = 0;
    tokn = strtok(str,dl);
    char tmp[2];

   for(i=0;i<=cntr[baris];i++)
       strcat(helper[baris]," ");

    while(tokn!=NULL) {
        if (len + strlen(tokn) * 2 <= 52) {
            for (i=0; i<strlen(tokn); i++){
                j = (int) tokn[i];
                if (prgs[j - 64] == TRUE || salah == 8){
                    tmp[0] = tokn[i];
                    tmp[1] = '\0';
                    strcat(helper[baris], tmp);
                    strcat(helper[baris], " ");
                }else if (tokn[i] == 45){
                    strcat(helper[baris], "- ");
                }else{
                    strcat(helper[baris], "_ ");
                }

            }
            strcat(helper[baris],"  ");
            len = strlen(helper[baris]);

            i++;
            tokn = strtok(NULL, dl);
        }else{
            for (i=len;i<=53;i++)
                strcat(helper[baris], " ");
            baris++;
            for(i=0;i<=cntr[baris];i++)
                strcat(helper[baris]," ");

            len = 1;
        }
    }
    for (i=len;i<=53;i++)
        strcat(helper[baris], " ");

    if (baris<2){
        for(i=baris + 1;i<=2;i++)
            strcpy(helper[i] , "                                                      ");
    }

    printf("|   %s     %s       |\n", helper[0], Hangman[1]);
    printf("|   %s     %s       |\n", helper[1], Hangman[2]);
    printf("|   %s     %s       |\n", helper[2], Hangman[3]);

    printf("|   ");
    len = strlen(msg);
    j = 28 - (len/2);
    for(i=1;i<=j;i++)
        printf(" ");
    SetColor(WHITE,RED);
    printf("%s", msg);
    SetColor(YELLOW,DARK_PURPLE);
    for(i=1;i<=56-len-j;i++)
        printf(" ");
    printf("   %s       |\n", Hangman[4]);

    printf("|                                                              %s       |\n", Hangman[5]);
    printf("|         +---------------------------------------+            %s       |\n", Hangman[6]);
    printf("|         |");if(prgs[17]==TRUE) SetColor(WHITE, RED);printf(" Q ");SetColor(YELLOW,DARK_PURPLE);printf("|");if(prgs[23]==TRUE) SetColor(WHITE, RED);printf(" W ");SetColor(YELLOW,DARK_PURPLE);printf("|");if(prgs[5]==TRUE) SetColor(WHITE, RED);
    printf(" E ");SetColor(YELLOW,DARK_PURPLE);printf("|");if(prgs[18]==TRUE) SetColor(WHITE, RED);printf(" R ");SetColor(YELLOW,DARK_PURPLE);printf("|");if(prgs[20]==TRUE) SetColor(WHITE, RED);printf(" T ");SetColor(YELLOW,DARK_PURPLE);printf("|");if(prgs[25]==TRUE) SetColor(WHITE, RED);printf(" Y ");SetColor(YELLOW,DARK_PURPLE);printf("|");if(prgs[21]==TRUE) SetColor(WHITE, RED);
    printf(" U ");SetColor(YELLOW,DARK_PURPLE);printf("|");if(prgs[9]==TRUE) SetColor(WHITE, RED);printf(" I ");SetColor(YELLOW,DARK_PURPLE);printf("|");if(prgs[15]==TRUE) SetColor(WHITE, RED);printf(" O ");SetColor(YELLOW,DARK_PURPLE);printf("|");if(prgs[16]==TRUE) SetColor(WHITE, RED);printf(" P ");SetColor(YELLOW,DARK_PURPLE);printf("|            %s       |\n", Hangman[7]);
    printf("|         +-+-----------------------------------+-+             |             |\n");
    printf("|           |");if(prgs[1]==TRUE) SetColor(WHITE, RED);printf(" A ");SetColor(YELLOW,DARK_PURPLE);printf("|");if(prgs[19]==TRUE) SetColor(WHITE, RED);printf(" S ");SetColor(YELLOW,DARK_PURPLE);printf("|");if(prgs[4]==TRUE) SetColor(WHITE, RED);printf(" D ");SetColor(YELLOW,DARK_PURPLE);printf("|");if(prgs[6]==TRUE) SetColor(WHITE, RED);
    printf(" F ");SetColor(YELLOW,DARK_PURPLE);printf("|");if(prgs[7]==TRUE) SetColor(WHITE, RED);printf(" G ");SetColor(YELLOW,DARK_PURPLE);printf("|");if(prgs[8]==TRUE) SetColor(WHITE, RED);printf(" H ");SetColor(YELLOW,DARK_PURPLE);printf("|");if(prgs[10]==TRUE) SetColor(WHITE, RED);printf(" J ");SetColor(YELLOW,DARK_PURPLE);printf("|");if(prgs[11]==TRUE) SetColor(WHITE, RED);
    printf(" K ");SetColor(YELLOW,DARK_PURPLE);printf("|");if(prgs[12]==TRUE) SetColor(WHITE, RED);printf(" L ");SetColor(YELLOW,DARK_PURPLE);printf("|               |             |\n");
    printf("|           +---+---------------------------+---+               |             |\n");
    printf("|               |");if(prgs[26]==TRUE) SetColor(WHITE, RED);printf(" Z ");SetColor(YELLOW,DARK_PURPLE);printf("|");if(prgs[24]==TRUE) SetColor(WHITE, RED);printf(" X ");SetColor(YELLOW,DARK_PURPLE);printf("|");if(prgs[3]==TRUE) SetColor(WHITE, RED);printf(" C ");SetColor(YELLOW,DARK_PURPLE);printf("|");if(prgs[22]==TRUE) SetColor(WHITE, RED);
    printf(" V ");SetColor(YELLOW,DARK_PURPLE);printf("|");if(prgs[2]==TRUE) SetColor(WHITE, RED);printf(" B ");SetColor(YELLOW,DARK_PURPLE);printf("|");if(prgs[14]==TRUE) SetColor(WHITE, RED);printf(" N ");SetColor(YELLOW,DARK_PURPLE);printf("|");if(prgs[13]==TRUE) SetColor(WHITE, RED);printf(" M ");SetColor(YELLOW,DARK_PURPLE);printf("|                   |             |\n");
    printf("|               +---------------------------+                  /_\\            |\n");
    printf("+-----------------------------------------------------------------------------+\n");
}

//memprint mode permainan single player (gameplay)
void PrintGame(char* usr, int skor, int level, char* cat, char quest[], char kata[], BOOL prgs[], int salah, char* msg) {
    int i, len, baris, j;
    char * tokn = NULL;
    char * dl = " ";
    char str[300];
    HGM Hangman;
    char helper[3][55];
    int cntr[3];
    i = 0;
    while(quest[i]!='\0'){
        str[i] = quest[i];
        i++;
    }
    str[i]='\0';
    system(CLEARCMD);
    printf("+-----------------------------------------------------------------------------+\n");
    printf("|                             SINGLE PLAYER MODE                              |\n");
    printf("| USER       :    %s", usr);
    for (i=1;i<=34-strlen(usr);i++)
        printf(" ");
    // end for
    switch(level){
        case 1: printf("DIFFICULTY    :   EASY    |\n"); break;
        case 2: printf("DIFFICULTY    :   NORMAL  |\n"); break;
        case 3: printf("DIFFICULTY    :   HARD!   |\n"); break;
    }

    printf("| SKOR       :    %d",skor);
    for(i=1;i<=60 - IntLen(skor);i++)
        printf(" ");
    printf("|\n");

    printf("+-----------------------------------------------------------------------------+\n");
    printf("| KATEGORI   :    %s", cat);
    for(i=1;i<=60-strlen(cat);i++)
        printf(" ");
    printf("|\n");

    printf("| PERTANYAAN :    ");
    len = 1; baris = 1;
    tokn = strtok(str,dl);
    while(tokn!=NULL) {
        if (len + strlen(tokn) + 1 <= 59) {
            printf("%s ", tokn);
            len += strlen(tokn) + 1;
            i++;
            tokn = strtok(NULL, dl);
        }else{
            for (i=1;i<=61 - len;i++)
                printf(" ");
            printf("|\n|                 ");
            baris++;
            len = 1;
        }
    }
    for (i=1;i<=61 - len;i++)
        printf(" ");
    printf("|\n");
    for (i = 1; i<=3 - baris; i++)
        printf("|                                                                             |\n");
    //end for
    PrintHangman(salah,Hangman);
    printf("|                                                                             |\n");
    printf("|                                                              %s       |\n", Hangman[0]);
    i = 0;
    while(kata[i]!='\0'){
        str[i] = kata[i];
        i++;
    }
    str[i]='\0';
    strcpy(helper[0],"");
    strcpy(helper[1],"");
    strcpy(helper[2],"");


    len = 0; baris = 0;
    tokn = strtok(str,dl);
    while(tokn!=NULL) {
        if (len + strlen(tokn) * 2 <= 52) {
            len += strlen(tokn) * 2 + 2;
            i++;
            tokn = strtok(NULL, dl);
        }else{
            cntr[baris] = 26 - (len / 2);
            baris++;
            len = 1;
        }
    }
    cntr[baris] = 26 - (len / 2);
    i = 0;
    while(kata[i]!='\0'){
        str[i] = kata[i];
        i++;
    }
    str[i]='\0';

    len = 0; baris = 0;
    tokn = strtok(str,dl);
    char tmp[2];

   for(i=0;i<=cntr[baris];i++)
       strcat(helper[baris]," ");

    while(tokn!=NULL) {
        if (len + strlen(tokn) * 2 <= 52) {
            for (i=0; i<strlen(tokn); i++){
                j = (int) tokn[i];
                if (prgs[j - 64] == TRUE || salah == 8){
                    tmp[0] = tokn[i];
                    tmp[1] = '\0';
                    strcat(helper[baris], tmp);
                    strcat(helper[baris], " ");
                }else if (tokn[i] == 45){
                    strcat(helper[baris], "- ");
                }else{
                    strcat(helper[baris], "_ ");
                }

            }
            strcat(helper[baris],"  ");
            len = strlen(helper[baris]);

            i++;
            tokn = strtok(NULL, dl);
        }else{
            for (i=len;i<=53;i++)
                strcat(helper[baris], " ");
            baris++;
            for(i=0;i<=cntr[baris];i++)
                strcat(helper[baris]," ");

            len = 1;
        }
    }
    for (i=len;i<=53;i++)
        strcat(helper[baris], " ");

    if (baris<2){
        for(i=baris + 1;i<=2;i++)
            strcpy(helper[i] , "                                                      ");
    }

    printf("|   %s     %s       |\n", helper[0], Hangman[1]);
    printf("|   %s     %s       |\n", helper[1], Hangman[2]);
    printf("|   %s     %s       |\n", helper[2], Hangman[3]);

    printf("|   ");
    len = strlen(msg);
    j = 28 - (len/2);
    for(i=1;i<=j;i++)
        printf(" ");
    SetColor(WHITE,RED);
    printf("%s", msg);
    SetColor(YELLOW,DARK_PURPLE);
    for(i=1;i<=56-len-j;i++)
        printf(" ");
    printf("   %s       |\n", Hangman[4]);

    printf("|                                                              %s       |\n", Hangman[5]);
    printf("|         +---------------------------------------+            %s       |\n", Hangman[6]);
    printf("|         |");if(prgs[17]==TRUE) SetColor(WHITE, RED);printf(" Q ");SetColor(YELLOW,DARK_PURPLE);printf("|");if(prgs[23]==TRUE) SetColor(WHITE, RED);printf(" W ");SetColor(YELLOW,DARK_PURPLE);printf("|");if(prgs[5]==TRUE) SetColor(WHITE, RED);
    printf(" E ");SetColor(YELLOW,DARK_PURPLE);printf("|");if(prgs[18]==TRUE) SetColor(WHITE, RED);printf(" R ");SetColor(YELLOW,DARK_PURPLE);printf("|");if(prgs[20]==TRUE) SetColor(WHITE, RED);printf(" T ");SetColor(YELLOW,DARK_PURPLE);printf("|");if(prgs[25]==TRUE) SetColor(WHITE, RED);printf(" Y ");SetColor(YELLOW,DARK_PURPLE);printf("|");if(prgs[21]==TRUE) SetColor(WHITE, RED);
    printf(" U ");SetColor(YELLOW,DARK_PURPLE);printf("|");if(prgs[9]==TRUE) SetColor(WHITE, RED);printf(" I ");SetColor(YELLOW,DARK_PURPLE);printf("|");if(prgs[15]==TRUE) SetColor(WHITE, RED);printf(" O ");SetColor(YELLOW,DARK_PURPLE);printf("|");if(prgs[16]==TRUE) SetColor(WHITE, RED);printf(" P ");SetColor(YELLOW,DARK_PURPLE);printf("|            %s       |\n", Hangman[7]);
    printf("|         +-+-----------------------------------+-+             |             |\n");
    printf("|           |");if(prgs[1]==TRUE) SetColor(WHITE, RED);printf(" A ");SetColor(YELLOW,DARK_PURPLE);printf("|");if(prgs[19]==TRUE) SetColor(WHITE, RED);printf(" S ");SetColor(YELLOW,DARK_PURPLE);printf("|");if(prgs[4]==TRUE) SetColor(WHITE, RED);printf(" D ");SetColor(YELLOW,DARK_PURPLE);printf("|");if(prgs[6]==TRUE) SetColor(WHITE, RED);
    printf(" F ");SetColor(YELLOW,DARK_PURPLE);printf("|");if(prgs[7]==TRUE) SetColor(WHITE, RED);printf(" G ");SetColor(YELLOW,DARK_PURPLE);printf("|");if(prgs[8]==TRUE) SetColor(WHITE, RED);printf(" H ");SetColor(YELLOW,DARK_PURPLE);printf("|");if(prgs[10]==TRUE) SetColor(WHITE, RED);printf(" J ");SetColor(YELLOW,DARK_PURPLE);printf("|");if(prgs[11]==TRUE) SetColor(WHITE, RED);
    printf(" K ");SetColor(YELLOW,DARK_PURPLE);printf("|");if(prgs[12]==TRUE) SetColor(WHITE, RED);printf(" L ");SetColor(YELLOW,DARK_PURPLE);printf("|               |             |\n");
    printf("|           +---+---------------------------+---+               |             |\n");
    printf("|               |");if(prgs[26]==TRUE) SetColor(WHITE, RED);printf(" Z ");SetColor(YELLOW,DARK_PURPLE);printf("|");if(prgs[24]==TRUE) SetColor(WHITE, RED);printf(" X ");SetColor(YELLOW,DARK_PURPLE);printf("|");if(prgs[3]==TRUE) SetColor(WHITE, RED);printf(" C ");SetColor(YELLOW,DARK_PURPLE);printf("|");if(prgs[22]==TRUE) SetColor(WHITE, RED);
    printf(" V ");SetColor(YELLOW,DARK_PURPLE);printf("|");if(prgs[2]==TRUE) SetColor(WHITE, RED);printf(" B ");SetColor(YELLOW,DARK_PURPLE);printf("|");if(prgs[14]==TRUE) SetColor(WHITE, RED);printf(" N ");SetColor(YELLOW,DARK_PURPLE);printf("|");if(prgs[13]==TRUE) SetColor(WHITE, RED);printf(" M ");SetColor(YELLOW,DARK_PURPLE);printf("|                   |             |\n");
    printf("|               +---------------------------+                  /_\\            |\n");
    printf("+-----------------------------------------------------------------------------+\n");
}

// memprint menu single player login
void PrintMainSendiri(int Menu) {
    system(CLEARCMD);
    printf("+-----------------------------------------------------------------------------+\n");
    printf("|                                   ___                                       |\n");
    printf("|                                  (   .-.          .-.                       |\n");
    printf("|          .--.    .--. ___ .-.  .-.| ( __)___ .-. ( __) .---. ___ .-.        |\n");
    printf("|        /  _  \\  /    (   )   \\/   \\ ('' (   )   \\('' )/ .-, (   )   \\       |\n");
    printf("|       . .' `. ;|  .-. |  .-. |  .-. || | | ' .-. ;| |(__) ; ||  .-. .       |\n");
    printf("|       | '   | ||  | | | |  | | |  | || | |  / (___| |  .'`  || |  | |       |\n");
    printf("|       _\\_`.(___|  |/  | |  | | |  | || | | |      | | / .'| || |  | |       |\n");
    printf("|      (   ). '. |  ' _.| |  | | |  | || | | |      | || /  | || |  | |       |\n");
    printf("|       | |  `\\ ||  .'.-| |  | | '  | || | | |      | |; |  ; || |  | |       |\n");
    printf("|       ; '._,' ''  `-' | |  | ' `-'  /| | | |      | |' `-'  || |  | |       |\n");
    printf("|        '.___.'  `.__.(___)(___`.__,'(___(___)    (___`.__.'_(___)(___)      |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                         S I N G L E   P L A Y E R                           |\n");
    printf("|                         -------------------------                           |\n");
    if (Menu == 1) {
        printf("|");SetColor(WHITE, DARK_PURPLE);printf("                              -> NEW GAME <-                                 ");SetColor(YELLOW, DARK_PURPLE);printf("|\n");
        printf("|                            LOAD PREVIOUS GAME                               |\n");
    }else{
        printf("|                                 NEW GAME                                    |\n");
        printf("|");SetColor(WHITE, DARK_PURPLE);printf("                         -> LOAD PREVIOUS GAME <-                            ");SetColor(YELLOW, DARK_PURPLE);printf("|\n");
    }
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                USE UP AND DOWN ARROW AND ENTER TO SELECT MENU               |\n");
    printf("+-----------------------------------------------------------------------------+\n");
}

// memprint menu utama
void PrintMenuUtama(int Menu) {
    system(CLEARCMD);
    printf("+-----------------------------------------------------------------------------+\n");
	printf("|             _   _    _    _   _  ____ __  __    _    _   _                  |\n");
    printf("|            | | | |  / \\  | \\ | |/ ___|  \\/  |  / \\  | \\ | |                 |\n");
    printf("|            | |_| | / _ \\ |  \\| | |  _| |\\/| | / _ \\ |  \\| |                 |\n");
    printf("|            |  _  |/ ___ \\| |\\  | |_| | |  | |/ ___ \\| |\\  |                 |\n");
    printf("|            |_| |_/_/   \\_|_| \\_|\\____|_|  |_/_/   \\_|_| \\_|                 |\n");
    printf("|                                                VERSI 1.0.0                  |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    switch (Menu) {
        case 1  :   printf("|");SetColor(WHITE, DARK_PURPLE); printf("                            -=[MAIN SENDIRI]=-                               ");SetColor(YELLOW, DARK_PURPLE);printf("|\n");
                    printf("|                             BERDUA LEBIH ASIK                               |\n");
                    printf("|                          SKOR PARA TOP 10 MASTER                            |\n");
                    printf("|                                 BANTUAN?                                    |\n");
                    printf("|                                  KELUAR                                     |\n");
                    break;
        case 2  :   printf("|                               MAIN SENDIRI                                  |\n");
                    printf("|");SetColor(WHITE, DARK_PURPLE);printf("                          -=[BERDUA LEBIH ASIK]=-                            ");SetColor(YELLOW, DARK_PURPLE);printf("|\n");
                    printf("|                          SKOR PARA TOP 10 MASTER                            |\n");
                    printf("|                                 BANTUAN?                                    |\n");
                    printf("|                                  KELUAR                                     |\n");
                    break;
        case 3  :   printf("|                               MAIN SENDIRI                                  |\n");
                    printf("|                             BERDUA LEBIH ASIK                               |\n");
                    printf("|");SetColor(WHITE, DARK_PURPLE);printf("                       -=[SKOR PARA TOP 10 MASTER]=-                         ");SetColor(YELLOW, DARK_PURPLE);printf("|\n");
                    printf("|                                 BANTUAN?                                    |\n");
                    printf("|                                  KELUAR                                     |\n");
                    break;
        case 4  :   printf("|                               MAIN SENDIRI                                  |\n");
                    printf("|                             BERDUA LEBIH ASIK                               |\n");
                    printf("|                          SKOR PARA TOP 10 MASTER                            |\n");
                    printf("|");SetColor(WHITE, DARK_PURPLE);printf("                              -=[BANTUAN?]=-                                 ");SetColor(YELLOW, DARK_PURPLE);printf("|\n");
                    printf("|                                  KELUAR                                     |\n");
                    break;
        case 5  :   printf("|                               MAIN SENDIRI                                  |\n");
                    printf("|                             BERDUA LEBIH ASIK                               |\n");
                    printf("|                          SKOR PARA TOP 10 MASTER                            |\n");
                    printf("|                                 BANTUAN?                                    |\n");
                    printf("|");SetColor(WHITE, DARK_PURPLE);printf("                               -=[KELUAR]=-                                  ");SetColor(YELLOW, DARK_PURPLE);printf("|\n");
                    break;
    }
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                USE UP AND DOWN ARROW AND ENTER TO SELECT MENU               |\n");
    printf("+-----------------------------------------------------------------------------+\n");
}

// memprint jika game draw (multi player)
void PrintDraw() {
    system(CLEARCMD);
    printf("+-----------------------------------------------------------------------------+\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                              ");SetColor(WHITE,DARK_PURPLE);printf("    D R A W !   ");SetColor(YELLOW,DARK_PURPLE);printf("                               |\n");
    printf("|                              ");SetColor(WHITE,DARK_PURPLE);printf("  -------------   ");SetColor(YELLOW,DARK_PURPLE);printf("                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                   ROUNDE TIDAK DIMENANGKAN OLEH SIAPAPUN!!                  |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                         Is this easter egg? YEAH!                           |\n");
    printf("|                                 CONGRATS!                                   |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                   Tekan tombol apa aja untuk melanjutkan                    |\n");
    printf("+-----------------------------------------------------------------------------+\n");
}

// memprint jika tidak ada game yang tersedia (jika user memilih lanjutkan game terakhir)
void PrintNoGame() {
    system(CLEARCMD);
    printf("+-----------------------------------------------------------------------------+\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                              ");SetColor(WHITE,DARK_PURPLE);printf("    M A A F !   ");SetColor(YELLOW,DARK_PURPLE);printf("                               |\n");
    printf("|                              ");SetColor(WHITE,DARK_PURPLE);printf("  -------------   ");SetColor(YELLOW,DARK_PURPLE);printf("                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|            Maaf! Tidak ada game yang bisa anda lanjutkan saat ini           |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                   Tekan tombol apa aja untuk melanjutkan                    |\n");
    printf("+-----------------------------------------------------------------------------+\n");
}

// memprint pesan sebelum keluar permainan
void PrintKeluar() {
    system(CLEARCMD);
    printf("+-----------------------------------------------------------------------------+\n");
    printf("|                                                                             |\n");
    printf("|                   _____ _              _    __   __                         |\n");
    printf("|                  |_   _| |_  __ _ _ _ | |__ \\ \\ / ___ _  _                  |\n");
    printf("|                    | | | ' \\/ _` | ' \\| / /  \\ V / _ | || |                 |\n");
    printf("|                    |_| |_||_\\__,_|_||_|_\\_\\   |_|\\___/\\_,_|                 |\n");
    printf("|                                                                             |\n");
    printf("|                    Terima kasih telah bermain bersama kami                  |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                              SAMPAI JUMPA LAGI!                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                      Tekan tombol apa aja untuk keluar                      |\n");
    printf("+-----------------------------------------------------------------------------+\n");
}

// memprint halaman home user
void PrintHome(int Menu, int HS, char* tglHs, char* Uname) {
    char tmpU[100];
    char HST[30];
    int i;
    system(CLEARCMD);
    printf("+-----------------------------------------------------------------------------+\n");
	printf("|             _   _    _    _   _  ____ __  __    _    _   _                  |\n");
    printf("|            | | | |  / \\  | \\ | |/ ___|  \\/  |  / \\  | \\ | |                 |\n");
    printf("|            | |_| | / _ \\ |  \\| | |  _| |\\/| | / _ \\ |  \\| |                 |\n");
    printf("|            |  _  |/ ___ \\| |\\  | |_| | |  | |/ ___ \\| |\\  |                 |\n");
    printf("|            |_| |_/_/   \\_|_| \\_|\\____|_|  |_/_/   \\_|_| \\_|                 |\n");
    printf("|                                                VERSI 1.0.0                  |\n");
    printf("|                                                                             |\n");
    printf("|                                BERANDA USER                                 |\n");
    printf("|                               --------------                                |\n");
    strcpy(tmpU,Uname);
    strcat(tmpU,".");
    for (i=1;i<=48-strlen(Uname);i++)
        strcat(tmpU," ");
    printf("|                                                                             |\n");
    printf("|    Selamat Datang kembali, %s|\n", tmpU);
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|    ---------------------------       -------------------------------------  |\n");
    printf("|             USER MENU                            STATISTIK USER             |\n");
    printf("|    ---------------------------       -------------------------------------  |\n");
    printf("|    ");
    if(Menu == 1) {
        SetColor(WHITE, DARK_PURPLE);
        printf("{ Lanjutkan Game Terakhir }");
        SetColor(YELLOW, DARK_PURPLE);
    }else{
        printf("  Lanjutkan Game Terakhir  ");
    }

    printf("         Highscore   :  %d", HS);
    for(i=1;i<=22-IntLen(HS);i++)
        printf(" ");
    printf("|\n");
    strcpy(HST,tglHs);
    for (i=1;i<=22-strlen(tglHs);i++)
        strcat(HST," ");
    printf("|    ");
    if (Menu == 2){
        SetColor(WHITE, DARK_PURPLE);
        printf("     { Main Game Baru }    ");
        SetColor(YELLOW, DARK_PURPLE);
    }else{
        printf("       Main Game Baru      ");
    }
    printf("         Tanggal HS  :  %s", HST);printf("|\n");
    printf("|    ");
    if (Menu == 3){
        SetColor(WHITE, DARK_PURPLE);
        printf("      { Ganti User }    ");
        SetColor(YELLOW, DARK_PURPLE);
    }else{
        printf("        Ganti User      ");
    }
    printf("                                                 |\n");
    printf("|    ");
    if (Menu == 4){
        SetColor(WHITE, DARK_PURPLE);
        printf("      { Menu Utama }    ");
        SetColor(YELLOW, DARK_PURPLE);
    }else{
        printf("        Menu Utama      ");
    }
    printf("                                                 |\n");
    printf("|                                                                             |\n");
    printf("|                 Sekolah Teknik Elektro dan Informatika 2012                 |\n");
    printf("+-----------------------------------------------------------------------------+\n");
}

// memprint bantuan untuk user
void PrintBantuan() {
    system(CLEARCMD);
    printf("+-----------------------------------------------------------------------------+\n");
    printf("| HANGMAN THE GAME                                                            |\n");
    printf("| ----------------                                                            |\n");
    printf("|    1. Apa itu permainan HANGMAN?                                            |\n");
    printf("|       Permainan hangman adalah permainan tebak kata yang seru dan menarik   |\n");
    printf("|    2. Bagaimana saya memulai permainan?                                     |\n");
    printf("|       Pilih MAIN SENDIRI, lalu buat akun baru untuk memulai                 |\n");
    printf("|    3. Apa saya bisa menyimpan proses permainan saya?                        |\n");
    printf("|       Bisa dong! Akses pause menu (ESC), lalu pilih simpan progress         |\n");
    printf("|    4. Bagaimana saya memainkan mode multiplayer?                            |\n");
    printf("|       Pertama akses menu BERDUA LEBIH ASIK, lalu masukan nama PALYER 1      |\n");
    printf("|       dan PLAYER 2. Setelah itu masing-masing player saling bergantian      |\n");
    printf("|       mengetik pertanyaan satu sama lain.                                   |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                               SELAMAT BERMAIN!                              |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|                     Tekan Esc untuk kembali ke Main Menu                    |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("+-----------------------------------------------------------------------------+\n");
}

// mengeset warna sesusai dengan konstanta yang telah ditentukan
void SetColor(const int foreground, const int background) {

    int Color = foreground + (background * 16);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, Color);

    return;
}
