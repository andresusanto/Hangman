# Hangman
![Hangman](http://c11.incisozluk.com.tr/res/incisozluk/11000/1/72091_oba40.jpg)

Permainan Klasik "Hangman" yang dikemas ulang kedalam game windows. Dikembangkan dengan bahasa C.

## Intro
Semua orang pasti pernah memainkan game Tebak Kata, dari yang sederhana sampai kompleks, dari media lisan hingga media elektronik. Salah satu game tebak kata yang populer adalah _HANGMAN_. Game _HANGMAN_ memiliki alur proses cerita yang runut dan sistematis sehingga permainan _HANGMAN_ menjadi teratur dan menarik.

## Cara Kerja
Game HANGMAN memiliki cara kerja yang sederhana. Pertama pemain akan disuguhkan dengan sejumlah garis bawah yang mewakili tiap huruf dari kata yang akan ditebak. Jika huruf yang ditebak benar, maka huruf yang ditebak itu akan ditampilkan. Namun, jika pemain salah menjawab, maka satu persatu bagian tubuh manusia (mulai dari kepala hingga kaki) akan digambar. Pemain akan kalah jika manusia sudah tergambar dengan sempurna (lengkap tergantung di tiang).

Program yang kami buat memiliki prinsip kerja yang sama dengan kasus diatas, namun kami mengemasnya dalam bentuk program sehingga dapat dimainkan di komputer.

## Kompilasi
Program dikompilasi menggunakan GNU GCC untuk windows dengan menggunakan MinGW. Untuk melakukan kompilasi, silahkan install **MinGW/Cygwin**. Setelah itu, buka terminal MinGW/Cygwin lalu gunakan perintah berikut ini:
```
gcc -o hangman TB_06_10.c
```
Setelah itu anda dapat menjalankan game dengan perintah `./hangman`.

## Hasil Kompilasi dan Sampel File Input
Program menggunakan beberapa file input (seperti database pengguna, high score, dll). Sampel file input dan program yang sudah terkompilasi dapat ditemui pada folder `BIN`.

## Fitur-fitur
Pendaftaran/registrasi user:

![Pendaftaran User](/../screenshoot/screenshoots/newgame.jpg?raw=true)

Pilih player yang sudah ada:

![Pilih Player](/../screenshoot/screenshoots/selectplayer.jpg?raw=true)

Pilih Kategori Permainan:

![Pilih Kategori](/../screenshoot/screenshoots/categoryselect.jpg?raw=true)

**SINGLE PLAYER MODE**:

![Single Player Mode](/../screenshoot/screenshoots/singleplayer.jpg?raw=true)

High Score (TOP 10):

![High Scores](/../screenshoot/screenshoots/hiscores.jpg?raw=true)

Change User:

![Change User](/../screenshoot/screenshoots/changeuser.jpg?raw=true)

Info User:

![Info User](/../screenshoot/screenshoots/infouser.jpg?raw=true)

**TWO PLAYER MODE**:

![Two Players Mode](/../screenshoot/screenshoots/twoplayers.jpg?raw=true)

## License
MIT License.
