#include<iostream>
#include <string>
#include <vector>
using namespace std;

const char liniapion = 0xBA;
const char liniapoz = 0xCD;
const char srodek = 0xCE;
const char rogprawygorny = 0xBB;
const char roglewygorny = 0xC9;
const char rogprawydolny = 0xBC;
const char rogplewydolny = 0xC8;
const char srodekgora = 0xCB;
const char srodekdol = 0xCA;
const char boklewy = 0xCC;
const char bokprawy = 0xB9;

const char liniapion1 = 0xB3;
const char liniapoz1 = 0xC4;
const char srodek1 = 0xC5;
const char rogprawygorny1 = 0xBF;
const char roglewygorny1 = 0xDA;
const char rogprawydolny1 = 0xD9;
const char rogplewydolny1 = 0xC0;
const char srodekgora1 = 0xC2;
const char srodekdol1 = 0xC1;
const char boklewy1 = 0xC3;
const char bokprawy1 = 0xB4;

const int m = 6;
const int n = 6;
const int malaprzerwa = 27; //centrowanie planszy kolko i krzyzyk
const int duzaprzerwa = 6; //"czyszczenie" ekranu
const int spacje = 4;


struct gracz {
    string imie;
    char zeton;
};

struct archiwum_plansz {
    int plansza[4][3][3];
};

pair<string, string> gracze() {  //dodawanie gracza
    pair<string, string> imiona;
    cout << string(spacje, ' ') << "Podaj imiona graczy\n";
    cout << string(spacje, ' ') << "Gracz 1: ";
    cin >> imiona.first;
    cout << string(spacje, ' ') << "Gracz 2: ";
    cin >> imiona.second;
    cout << string(duzaprzerwa, '\n');
    return imiona;
}

pair<char, char> zeton() {  // wybor/zmiana zetonow
    char zeton1;
    char zeton2;
    pair<char, char> zetony;
    cout << string(spacje, ' ') << "Wybierz zeton\n";
    cout << string(spacje, ' ') << "Gracz 1: ";
    cin >> zeton1;
    cout << string(spacje, ' ') << "Gracz 2: ";
    cin >> zeton2;
    cout << string(duzaprzerwa, '\n');
    while (true) {
        if (zeton1 == zeton2) {
            cout << string(spacje, ' ') << "Zeton zajety! Wybierz inny: \n";
            cin >> zeton2;
        }
        else if (zeton2 != zeton1)
            break;
    }
    zetony.first = zeton1;
    zetony.second = zeton2;
    return zetony;
}

void wyswietl_plansze_kolko_i_krzyzyk(int plansza[4][3][3]) {
    int polaczona_plansza[6][6];
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            int nr_planszy;
            if (i < 3 && j < 3) nr_planszy = 0;
            else if (i < 3 && j >= 3) nr_planszy = 1;
            else if (i >= 3 && j < 3) nr_planszy = 2;
            else if (i >= 3 && j >= 3) nr_planszy = 3;
            polaczona_plansza[i][j] = plansza[nr_planszy][i % 3][j % 3];
        }
    }

    cout << string(malaprzerwa, ' ') << roglewygorny1 << liniapoz1 << liniapoz1 << liniapoz1 << srodekgora1 << liniapoz1 << liniapoz1 << liniapoz1 << srodekgora1 << liniapoz1 << liniapoz1 << liniapoz1 << srodekgora1 << liniapoz1 << liniapoz1 << liniapoz1 << srodekgora1 << liniapoz1 << liniapoz1 << liniapoz1 << srodekgora1 << liniapoz1 << liniapoz1 << liniapoz1 << rogprawygorny1 << endl;

    for (int i = 0; i < 6; i++) {
        cout << string(malaprzerwa, ' ') << liniapion1;
        for (int j = 0; j < 6; j++) {
            if (polaczona_plansza[i][j] == 0) cout << " ";
            else if (polaczona_plansza[i][j] == 1) cout << "O";
            else if (polaczona_plansza[i][j] == 2) cout << "X";
            cout << "  " << liniapion1;
        }
        cout << endl;
        if (i == 5) cout << string(malaprzerwa, ' ') << rogplewydolny1 << liniapoz1 << liniapoz1 << liniapoz1 << srodekdol1 << liniapoz1 << liniapoz1 << liniapoz1 << srodekdol1 << liniapoz1 << liniapoz1 << liniapoz1 << srodekdol1 << liniapoz1 << liniapoz1 << liniapoz1 << srodekdol1 << liniapoz1 << liniapoz1 << liniapoz1 << srodekdol1 << liniapoz1 << liniapoz1 << liniapoz1 << rogprawydolny1 << endl;
        else cout << string(malaprzerwa, ' ') << boklewy1 << liniapoz1 << liniapoz1 << liniapoz1 << srodek1 << liniapoz1 << liniapoz1 << liniapoz1 << srodek1 << liniapoz1 << liniapoz1 << liniapoz1 << srodek1 << liniapoz1 << liniapoz1 << liniapoz1 << srodek1 << liniapoz1 << liniapoz1 << liniapoz1 << srodek1 << liniapoz1 << liniapoz1 << liniapoz1 << bokprawy1 << endl;
    }
    cout << string(duzaprzerwa, '\n');
}

void wyswietl_plansze_pentago(int plansza[4][3][3], gracz gracz1, gracz gracz2) {
    int polaczona_plansza[6][6];
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            int nr_planszy;
            if (i < 3 && j < 3) nr_planszy = 0;
            else if (i < 3 && j >= 3) nr_planszy = 1;
            else if (i >= 3 && j < 3) nr_planszy = 2;
            else if (i >= 3 && j >= 3) nr_planszy = 3;
            polaczona_plansza[i][j] = plansza[nr_planszy][i % 3][j % 3];
        }
    }

    cout << string(malaprzerwa, ' ') << roglewygorny << liniapoz << liniapoz << liniapoz << liniapoz << liniapoz << liniapoz << liniapoz << srodekgora << liniapoz << liniapoz << liniapoz << liniapoz << liniapoz << liniapoz << liniapoz << rogprawygorny << endl;
    cout << string(malaprzerwa, ' ') << liniapion << roglewygorny1 << liniapoz1 << srodekgora1 << liniapoz1 << srodekgora1 << liniapoz1 << rogprawygorny1 << liniapion << roglewygorny1 << liniapoz1 << srodekgora1 << liniapoz1 << srodekgora1 << liniapoz1 << rogprawygorny1 << liniapion << endl;

    for (int i = 0; i < 6; i++) {
        cout << string(malaprzerwa, ' ') << liniapion;
        for (int j = 0; j < 6; j++) {
            if (j % 3 == 0) cout << liniapion1;
            if (polaczona_plansza[i][j] == 0) cout << " ";
            if (polaczona_plansza[i][j] == 1) cout << gracz1.zeton;
            if (polaczona_plansza[i][j] == 2) cout << gracz2.zeton;
            cout << liniapion1;
            if (j % 3 == 2) cout << liniapion;
            if (j / 5 == 1) cout << endl;

        }
        if (i == 2) {
            cout << string(malaprzerwa, ' ') << liniapion << rogplewydolny1 << liniapoz1 << srodekdol1 << liniapoz1 << srodekdol1 << liniapoz1 << rogprawydolny1 << liniapion << rogplewydolny1 << liniapoz1 << srodekdol1 << liniapoz1 << srodekdol1 << liniapoz1 << rogprawydolny1 << liniapion << endl;
            cout << string(malaprzerwa, ' ') << boklewy << liniapoz << liniapoz << liniapoz << liniapoz << liniapoz << liniapoz << liniapoz << srodek << liniapoz << liniapoz << liniapoz << liniapoz << liniapoz << liniapoz << liniapoz << bokprawy << endl;
            cout << string(malaprzerwa, ' ') << liniapion << roglewygorny1 << liniapoz1 << srodekgora1 << liniapoz1 << srodekgora1 << liniapoz1 << rogprawygorny1 << liniapion << roglewygorny1 << liniapoz1 << srodekgora1 << liniapoz1 << srodekgora1 << liniapoz1 << rogprawygorny1 << liniapion << endl;
        }
        if (i == 5) {
            cout << string(malaprzerwa, ' ') << liniapion << rogplewydolny1 << liniapoz1 << srodekdol1 << liniapoz1 << srodekdol1 << liniapoz1 << rogprawydolny1 << liniapion << rogplewydolny1 << liniapoz1 << srodekdol1 << liniapoz1 << srodekdol1 << liniapoz1 << rogprawydolny1 << liniapion << endl;
            cout << string(malaprzerwa, ' ') << rogplewydolny << liniapoz << liniapoz << liniapoz << liniapoz << liniapoz << liniapoz << liniapoz << srodekdol << liniapoz << liniapoz << liniapoz << liniapoz << liniapoz << liniapoz << liniapoz << rogprawydolny << endl;
        }

        if (i < 5 && i != 2) cout << string(malaprzerwa, ' ') << liniapion << boklewy1 << liniapoz1 << srodek1 << liniapoz1 << srodek1 << liniapoz1 << bokprawy1 << liniapion << boklewy1 << liniapoz1 << srodek1 << liniapoz1 << srodek1 << liniapoz1 << bokprawy1 << liniapion << endl;

    }
    cout << string(duzaprzerwa - 2, '\n');
}

void wpisz(int plansza[4][3][3], int x, int y, int z, int n) {
    plansza[x][y][z] = n;
}

void wyswietl_plansze_przykladowa(int plansza[4][3][3]) {

    wpisz(plansza, 0, 0, 1, 2);
    wpisz(plansza, 0, 1, 0, 1);
    wpisz(plansza, 0, 1, 1, 1);
    wpisz(plansza, 0, 1, 2, 2);
    wpisz(plansza, 0, 2, 1, 1);

    wpisz(plansza, 1, 0, 1, 1);
    wpisz(plansza, 1, 1, 0, 1);
    wpisz(plansza, 1, 1, 1, 2);

    wpisz(plansza, 2, 0, 0, 1);
    wpisz(plansza, 2, 0, 1, 1);
    wpisz(plansza, 2, 1, 0, 2);
    wpisz(plansza, 2, 1, 2, 1);
    wpisz(plansza, 2, 2, 1, 2);

    wpisz(plansza, 3, 1, 1, 2);
    wpisz(plansza, 3, 2, 1, 2);
    wpisz(plansza, 3, 2, 2, 2);

}

void zresetuj_plansze(int plansza[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            plansza[i][j] = 0;
        }
    }
}

void wyswietl_menu(int plansza[4][3][3], gracz& pierwszy, gracz& drugi) {  //m - wejscie do opcji
    pair<char, char> zetony;
    int w;
    cout << string(3 * duzaprzerwa, '\n');
    cout << string(spacje, ' ') << "Wybierz opcje\n";
    cout << string(spacje, ' ') << "1. Zmien zetony\n";
    cout << string(spacje, ' ') << "2. Wroc do gry\n ";
    cin >> w;
    cout << string(duzaprzerwa, '\n');
    if (w == 1) {
        cout << string(15, '\n');
        zetony = zeton();
        pierwszy.zeton = zetony.first;
        drugi.zeton = zetony.second;
        cout << string(3 * duzaprzerwa, '\n');
    }

    else if (w == 2) {
        cout << string(15, '\n');
        wyswietl_plansze_pentago(plansza, pierwszy, drugi);
    }

    else cout << string(spacje, ' ') << "Niepoprawna opcja!";

};

void menu_help_kolko_i_krzyzyk(int plansza[4][3][3]) {
    char x;
    cout << string(duzaprzerwa, '\n');
    cout << string(4 * spacje, ' ') << "Jak grac:\n";
    cout << string(4 * spacje, ' ') << "q,w,a,s - wybor czesci planszy odpowiednio: lewej gornej,\n" << string(4 * spacje, ' ') << "prawej gornej, lewej dolnej, prawej dolnej\n";
    cout << string(4 * spacje, ' ') << "1..9 - wybor pola na czesci planszy jak na klawiaturze\n" << string(4 * spacje, ' ') << "numerycznej tj. 1 to dolne lewe pole\n";
    cout << string(4 * spacje, ' ') << "p - pauza\n";
    cout << string(4 * spacje, ' ') << "Aby wrocic do gry kliknij dowolny klawisz i enter\n";
    cout << string(10, '\n');
    cin >> x;
    cout << string(duzaprzerwa, '\n');
    wyswietl_plansze_kolko_i_krzyzyk(plansza);
}

void pauza(int plansza[4][3][3], gracz pierwszy, gracz drugi) {
    char x;
    cout << string(10, '\n');
    cout << string(8 * spacje, ' ') << "PAUZA\n";
    cout << string(4 * spacje, ' ') << "Aby wrocic do gry kliknij dowolny klawisz i enter\n";
    cout << string(10, '\n');
    cin >> x;
    cout << string(duzaprzerwa, '\n');
    wyswietl_plansze_pentago(plansza, pierwszy, drugi);
}

void menu_help_pentago(int plansza[4][3][3], gracz pierwszy, gracz drugi) {     //h - opis programu
    char x;
    cout << string(duzaprzerwa, '\n');
    cout << string(4 * spacje, ' ') << "Jak grac:\n";
    cout << string(4 * spacje, ' ') << "q,w,a,s - wybor czesci planszy odpowiednio: lewej gornej,\n" << string(4 * spacje, ' ') << "prawej gornej, lewej dolnej, prawej dolnej\n";
    cout << string(4 * spacje, ' ') << "1..9 - wybor pola na czesci planszy jak na klawiaturze\n" << string(4 * spacje, ' ') << "numerycznej tj. 1 to dolne lewe pole\n";
    cout << string(4 * spacje, ' ') << "p - pauza\n";
    cout << string(4 * spacje, ' ') << "z,x - obrot odpowiednio: zgodnie z ruchem wskazowek zegara,\n" << string(4 * spacje, ' ') << "odwrotnie do ruchu wskazowek\n";
    cout << string(4 * spacje, ' ') << "Aby wrocic do gry kliknij dowolny klawisz i enter\n";
    cout << string(10, '\n');
    cin >> x;
    cout << string(duzaprzerwa, '\n');
    wyswietl_plansze_pentago(plansza, pierwszy, drugi);

}

bool sprawdz_ruch(int plansza[3][3], int wiersz, int kolumna) {
    return plansza[wiersz][kolumna] == 0;
}

void ruch_kolko_i_krzyzyk(int plansza[4][3][3], int nr_gracza) {
    string ruch, obrot;

    while (true) {
        cout << string(spacje, ' ') << "Podaj swoj ruch: \n";
        cin >> ruch;
        cout << string(duzaprzerwa, '\n');
        if (ruch[0] == 'h' && ruch.size() == 1) {
            menu_help_kolko_i_krzyzyk(plansza);
            continue;
        }

        if ((ruch[0] != 'q' && ruch[0] != 'w' && ruch[0] != 'a' && ruch[0] != 's') || int(ruch[1]) < 49 || int(ruch[1]) > 57) {
            cout << string(spacje, ' ') << "Nieprawidlowy ruch! \n";
            continue;
        }

        int czesc_pola = int(ruch[1]) - 48;
        int wiersz = 2 - ((czesc_pola - 1) / 3);
        int kolumna = (czesc_pola - 1) % 3;

        int nr_planszy;
        if (ruch[0] == 'q') nr_planszy = 0;
        else if (ruch[0] == 'w') nr_planszy = 1;
        else if (ruch[0] == 'a') nr_planszy = 2;
        else if (ruch[0] == 's') nr_planszy = 3;

        if (sprawdz_ruch(plansza[nr_planszy], wiersz, kolumna)) {
            plansza[nr_planszy][wiersz][kolumna] = nr_gracza;
            break;
        }
        else cout << string(spacje, ' ') << "Pole zajete!\n";

    }
}

bool wygrana_kolko_i_krzyzyk(int plansza[4][3][3]) {
    int polaczona_plansza[6][6];
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            int nr_planszy;
            if (i < 3 && j < 3) nr_planszy = 0;
            else if (i < 3 && j >= 3) nr_planszy = 1;
            else if (i >= 3 && j < 3) nr_planszy = 2;
            else if (i >= 3 && j >= 3) nr_planszy = 3;
            polaczona_plansza[i][j] = plansza[nr_planszy][i % 3][j % 3];
        }
    }

    //deklaracja flag
    bool zero_lub_dwa = false;
    bool zero_lub_jeden = false;
    bool brak_zer = true;
    //gracz 1
    for (int i = 0; i < 6; i++) { //sprawdzanie po wierszach
        zero_lub_dwa = false;
        for (int j = 0; j < 6; j++) {
            if (polaczona_plansza[i][j] == 2 || polaczona_plansza[i][j] == 0) zero_lub_dwa = true;
        }
        if (!zero_lub_dwa) {
            cout << "Gracz pierwszy wygral!\n\n";
            return true;
        }
    }
    for (int i = 0; i < 6; i++) {  //sprawdzanie po kolumnach
        zero_lub_dwa = false;
        for (int j = 0; j < 6; j++) {
            if (polaczona_plansza[j][i] == 2 || polaczona_plansza[j][i] == 0) zero_lub_dwa = true;
        }
        if (!zero_lub_dwa) {
            cout << "Gracz pierwszy wygral!\n\n";
            return true;
        }
    }

    zero_lub_dwa = false;
    for (int i = 0; i < 6; i++) {  //po ukosie w prawo
        if (polaczona_plansza[i][i] == 0 || polaczona_plansza[i][i] == 2) zero_lub_dwa = true;
    }
    if (!zero_lub_dwa) {
        cout << "Gracz pierwszy wygral!\n\n";
        return true;
    }

    zero_lub_dwa = false;
    for (int i = 0; i < 6; i++) {   // po ukosie w lewo
        if (polaczona_plansza[i][5 - i] == 0 || polaczona_plansza[i][5 - i] == 2)zero_lub_dwa = true;
    }
    if (!zero_lub_dwa) {
        cout << "Gracz pierwszy wygral!\n\n";
        return true;
    }

    //gracz 2
    for (int i = 0; i < 6; i++) {      //sprawdzanie po wierszach
        zero_lub_jeden = false;
        for (int j = 0; j < 6; j++) {
            if (polaczona_plansza[i][j] == 1 || polaczona_plansza[i][j] == 0) zero_lub_jeden = true;
        }
        if (!zero_lub_jeden) {
            cout << "Gracz drugi wygral!\n\n";
            return true;
        }
    }
    for (int i = 0; i < 6; i++) {  //sprawdzanie po kolumnach
        zero_lub_dwa = false;
        for (int j = 0; j < 6; j++) {
            if (polaczona_plansza[j][i] == 1 || polaczona_plansza[j][i] == 0) zero_lub_jeden = true;
        }
        if (!zero_lub_jeden) {
            cout << "Gracz drugi wygral!\n\n";
            return true;
        }
    }

    zero_lub_jeden = false;
    for (int i = 0; i < 6; i++) {     // po ukosie w prawo
        if (polaczona_plansza[i][i] == 1 || polaczona_plansza[i][i] == 0) zero_lub_jeden = true;
    }
    if (!zero_lub_jeden) {
        cout << "Gracz drugi wygral!\n\n";
        return true;
    }

    zero_lub_jeden = false;
    for (int i = 0; i < 6; i++) {    // po ukosie w lewo
        if (polaczona_plansza[i][5 - i] == 1 || polaczona_plansza[i][5 - i] == 0)zero_lub_jeden = true;
    }
    if (!zero_lub_jeden) {
        cout << "Gracz drugi wygral!\n\n";
        return true;
    }

    for (int i = 0; i < 6; i++) {   //jesli na zadnym polu nie ma 0 to znaczy ze wszystkie sa zajete
        for (int j = 0; j < 6; j++) {
            if (polaczona_plansza[i][i] == 0)brak_zer = false;
        }
    }
    if (brak_zer) {
        cout << "Remis!\n\n";
        return true;
    }
    return false;

}

void graj_w_kolo_i_krzyzyk() {
    cout << string(5 * spacje, ' ') << "Witaj w grze kolko i krzyzyk!\n" << string(5 * spacje, ' ') << "Aby uzyskac podpowiedz wcisnij h\n";
    cout << string(2 * duzaprzerwa, '\n');
    gracz pierwszy;
    gracz drugi;
    pair<string, string> imiona = gracze();
    pierwszy.imie = imiona.first;
    drugi.imie = imiona.second;
    int plansza[4][3][3];
    for (int i = 0; i < 4; i++) {
        zresetuj_plansze(plansza[i]);
    }
    wyswietl_plansze_kolko_i_krzyzyk(plansza);
    while (true) {
        cout << string(spacje, ' ') << "Tura gracza " << pierwszy.imie << " (kolko)\n";
        ruch_kolko_i_krzyzyk(plansza, 1);

        wyswietl_plansze_kolko_i_krzyzyk(plansza);
        if (wygrana_kolko_i_krzyzyk(plansza)) break;
        cout << string(spacje, ' ') << "Tura gracza " << drugi.imie << " (krzyzyk)\n";
        ruch_kolko_i_krzyzyk(plansza, 2);

        wyswietl_plansze_kolko_i_krzyzyk(plansza);
        if (wygrana_kolko_i_krzyzyk(plansza)) break;
    }
}

void obroc_w_prawo(int plansza[3][3]) {
    int nowa_plansza[3][3];
    zresetuj_plansze(nowa_plansza);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            nowa_plansza[i][j] = plansza[3 - j - 1][i];
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            plansza[i][j] = nowa_plansza[i][j];
        }
    }

}

void obroc_w_lewo(int plansza[3][3]) {
    int nowa_plansza[3][3];
    zresetuj_plansze(nowa_plansza);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            nowa_plansza[i][j] = plansza[j][3 - i - 1];
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            plansza[i][j] = nowa_plansza[i][j];
        }
    }
}

void ruch_pentago(int plansza[4][3][3], int nr_gracza, gracz& pierwszy, gracz& drugi) {//wektor
    string ruch, obrot;

    while (true) {
        cout << string(spacje, ' ') << "Podaj swoj ruch: ";
        cin >> ruch;
        cout << string(duzaprzerwa + 2, '\n');
        if (ruch[0] == 'h' && ruch.size() == 1) {
            menu_help_pentago(plansza, pierwszy, drugi);
            continue;
        }

        if (ruch[0] == 'p' && ruch.size() == 1) {
            pauza(plansza, pierwszy, drugi);
            continue;
        }

        if (ruch[0] == 'm' && ruch.size() == 1) {
            wyswietl_menu(plansza, pierwszy, drugi);
            cout << pierwszy.zeton;
            continue;
        }
        if ((ruch[0] != 'q' && ruch[0] != 'w' && ruch[0] != 'a' && ruch[0] != 's') || int(ruch[1]) < 49 || int(ruch[1]) > 57) {
            cout << string(spacje, ' ') << "Nieprawidlowy ruch!\n";
            continue;
        }

        int czesc_pola = int(ruch[1]) - 48;
        int wiersz = 2 - ((czesc_pola - 1) / 3);
        int kolumna = (czesc_pola - 1) % 3;

        int nr_planszy;
        if (ruch[0] == 'q') nr_planszy = 0;
        else if (ruch[0] == 'w') nr_planszy = 1;
        else if (ruch[0] == 'a') nr_planszy = 2;
        else if (ruch[0] == 's') nr_planszy = 3;


        if (sprawdz_ruch(plansza[nr_planszy], wiersz, kolumna)) {
            plansza[nr_planszy][wiersz][kolumna] = nr_gracza;
            break;
        }
        else cout << string(spacje, ' ') << "Pole zajete!\n";
    }
    wyswietl_plansze_pentago(plansza, pierwszy, drugi);
    while (true) {
        cout << string(spacje, ' ') << "Obrot planszy: ";
        cin >> obrot;
        cout << string(duzaprzerwa + 2, '\n');
        if (ruch[0] == 'h' && ruch.size() == 1) {
            menu_help_pentago(plansza, pierwszy, drugi);
            continue;
        }
        if (ruch[0] == 'm' && ruch.size() == 1) {
            wyswietl_menu(plansza, pierwszy, drugi);
            continue;
        }
        if ((obrot[0] != 'q' && obrot[0] != 'w' && obrot[0] != 'a' && obrot[0] != 's') || (obrot[1] != 'z' && obrot[1] != 'x')) {
            cout << string(spacje, ' ') << "Nieprawidlowy ruch!\n";
            continue;
        }

        int nr_planszy;
        if (obrot[0] == 'q') nr_planszy = 0;
        else if (obrot[0] == 'w') nr_planszy = 1;
        else if (obrot[0] == 'a') nr_planszy = 2;
        else if (obrot[0] == 's') nr_planszy = 3;

        if (obrot[1] == 'z') obroc_w_prawo(plansza[nr_planszy]);
        else obroc_w_lewo(plansza[nr_planszy]);
        break;
    }
}

bool wygrana_pentago(int plansza[4][3][3]) {
    int polaczona_plansza[6][6];
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            int nr_planszy;
            if (i < 3 && j < 3) nr_planszy = 0;
            else if (i < 3 && j >= 3) nr_planszy = 1;
            else if (i >= 3 && j < 3) nr_planszy = 2;
            else if (i >= 3 && j >= 3) nr_planszy = 3;
            polaczona_plansza[i][j] = plansza[nr_planszy][i % 3][j % 3];
        }
    }

    // gracz 1
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            bool prawo = true;
            bool dol = true;
            bool prawo_skos = true;
            bool lewo_skos = true;
            for (int k = 0; k < 5; k++) {
                if (j + k > 5 || polaczona_plansza[i][j + k] != 1) prawo = false;
                if (i + k > 5 || polaczona_plansza[i + k][j] != 1)dol = false;
                if (i + k > 5 || j + k > 5 || polaczona_plansza[i + k][j + k] != 1) prawo_skos = false;
                if (i - k > 0 || j - k < 0 || polaczona_plansza[i - k][j - k] != 1) lewo_skos = false;
            }
            if (prawo || dol || prawo_skos || lewo_skos) {
                cout << "Gracz pierwszy wygral";
                return true;
            }
        }
    }

    //gracz 2
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            bool prawo = true;
            bool dol = true;
            bool prawo_skos = true;
            bool lewo_skos = true;
            for (int k = 0; k < 5; k++) {
                if (j + k > 5 || polaczona_plansza[i][j + k] != 2) prawo = false;
                if (i + k > 5 || polaczona_plansza[i + k][j] != 2)dol = false;
                if (i + k > 5 || j + k > 5 || polaczona_plansza[i + k][j + k] != 2) prawo_skos = false;
                if (i - k < 0 || j - k < 0 || polaczona_plansza[i - k][j - k] != 2) lewo_skos = false;
            }
            if (prawo || dol || prawo_skos || lewo_skos) {
                cout << "Gracz drugi wygral";
                return true;
            }
        }
    }
    bool sa_zera = false;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (polaczona_plansza[i][j] == 0) sa_zera = true;
        }
    }
    if (!sa_zera) {
        cout << "Remis!\n";
        return true;
    }
    return false;
}

void przegladaj_gre(int archiwum_plansz[1000][4][3][3], int liczbaruchow, gracz pierwszy, gracz drugi) {
    cout << string(spacje, ' ') << "WITAJ W TRYBIE PRZEGLADANIA GRY\n";
    int index_ruchu = 0;
    // opcja x do przodu, z do tylu, w by wyjsc
    wyswietl_plansze_pentago(archiwum_plansz[index_ruchu], pierwszy, drugi);
    while (true) {
        cout << string(spacje, ' ') << "opcja x do przodu, z do tylu, w by wyjsc\n";
        char wybor;
        cin >> wybor;
        if (wybor == 'x') {
            if (index_ruchu + 1 > liczbaruchow) {
                cout << string(spacje, ' ') << "Koniec gry\n";
            }
            else {
                index_ruchu++;
                wyswietl_plansze_pentago(archiwum_plansz[index_ruchu], pierwszy, drugi);
            }
        }
        else if (wybor == 'z') {
            if (index_ruchu - 1 < 0) {
                cout << string(spacje, ' ') << "To byl pierwszy ruch\n";
            }
            else {
                index_ruchu--;
                wyswietl_plansze_pentago(archiwum_plansz[index_ruchu], pierwszy, drugi);
            }
        }
        else if (wybor == 'w') {
            break;
        }
        else cout << string(spacje, ' ') << "Nieprawidlowy wybor\n";
    }

}

void graj_w_pentago() {
    cout << string(6 * spacje, ' ') << "Witaj w grze pentago!\n" << string(5 * spacje, ' ') << "Aby uzyskac podpowiedz wcisnij h\n" << string(5 * spacje, ' ') << "Aby wejsc do ustawien wcisnij m";
    cout << string(2 * duzaprzerwa, '\n');
    gracz pierwszy;
    gracz drugi;
    pair<string, string> imiona = gracze();
    pierwszy.imie = imiona.first;
    drugi.imie = imiona.second;
    pair<char, char> zetony = zeton();
    pierwszy.zeton = zetony.first;
    drugi.zeton = zetony.second;
    int plansze[4][3][3]; // 0 - q, 1 - w, 2 - a , 3 -s
    int archiwum_plansz[1000][4][3][3];
    char wybor;
    cout << string(5 * spacje, ' ') << "Wybierz plansze (p - pusta, o - przykladowa)\n";
    cin >> wybor;

    if (wybor == 'o') {
        for (int i = 0; i < 4; i++) {
            zresetuj_plansze(plansze[i]);
            wyswietl_plansze_przykladowa(plansze);
        }

        wyswietl_plansze_pentago(plansze, pierwszy, drugi);
        int index_ruchu = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    archiwum_plansz[index_ruchu][i][j][k] = plansze[i][j][k];
                }
            }
        }
        while (true) {
            index_ruchu++;
            if (index_ruchu % 2 == 1) {
                cout << string(spacje, ' ') << "Tura gracza " << pierwszy.imie << endl;
                ruch_pentago(plansze, 1, pierwszy, drugi);
            }
            else {
                cout << string(spacje, ' ') << "Tura gracza " << drugi.imie << endl;
                ruch_pentago(plansze, 2, pierwszy, drugi);
            }



            //zapisz plansze
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        archiwum_plansz[index_ruchu][i][j][k] = plansze[i][j][k];
                    }
                }
            }


            wyswietl_plansze_pentago(plansze, pierwszy, drugi);

            char wybor;
            while (true) {            //cofanie ruchu
                int cofniecia = 0;
                if (index_ruchu - 1 < 0) {
                    cout << string(spacje, ' ') << "Nie mozesz cofnac wiecej ruchow\n";
                    break;
                }
                else if (cofniecia >= 4) {
                    cout << string(spacje, ' ') << "Wykorzystaliscie juz wszystkie cofniecia\n";
                    break;
                }
                cout << string(spacje, ' ') << "Czy chcesz cofnac ruch?  T/N";
                cin >> wybor;
                if (wybor == 'T' || wybor == 't') {
                    index_ruchu--;
                    cofniecia++;
                    cout << string(duzaprzerwa, '\n');
                    for (int i = 0; i < 4; i++) {
                        for (int j = 0; j < 3; j++) {
                            for (int k = 0; k < 3; k++) {
                                plansze[i][j][k] = archiwum_plansz[index_ruchu][i][j][k];
                            }
                        }
                    }
                    wyswietl_plansze_pentago(plansze, pierwszy, drugi);
                }
                else if (wybor == 'N' || wybor == 'n') {
                    break;
                }
                else cout << string(spacje, ' ') << "Nieprawidlowy wybor\n";
            }
            wyswietl_plansze_pentago(plansze, pierwszy, drugi);

            if (wygrana_pentago(plansze)) break;
        }
        while (true) {
            cout << string(spacje, ' ') << "Czy chcesz przejerze gre? T/N\n";
            char wybor;
            cin >> wybor;
            if (wybor == 'T' || wybor == 't') {
                przegladaj_gre(archiwum_plansz, index_ruchu, pierwszy, drugi);
            }
            else if (wybor == 'N' || wybor == 'n') {
                break;
            }
            else cout << string(spacje, ' ') << "Zly wybor\n";
        }
    }

    else if (wybor == 'p') {
        for (int i = 0; i < 4; i++) {
            zresetuj_plansze(plansze[i]);
        }

        wyswietl_plansze_pentago(plansze, pierwszy, drugi);
        int index_ruchu = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    archiwum_plansz[index_ruchu][i][j][k] = plansze[i][j][k];
                }
            }
        }
        while (true) {
            index_ruchu++;
            if (index_ruchu % 2 == 1) {
                cout << string(spacje, ' ') << "Tura gracza " << pierwszy.imie << endl;
                ruch_pentago(plansze, 1, pierwszy, drugi);
            }
            else {
                cout << string(spacje, ' ') << "Tura gracza " << drugi.imie << endl;
                ruch_pentago(plansze, 2, pierwszy, drugi);
            }



            //zapisz plansze
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        archiwum_plansz[index_ruchu][i][j][k] = plansze[i][j][k];
                    }
                }
            }


            wyswietl_plansze_pentago(plansze, pierwszy, drugi);

            char wybor;
            while (true) {            //cofanie ruchu
                int cofniecia = 0;
                if (index_ruchu - 1 < 0) {
                    cout << string(spacje, ' ') << "Nie mozesz cofnac wiecej ruchow\n";
                    break;
                }
                else if (cofniecia >= 4) {
                    cout << string(spacje, ' ') << "Wykorzystaliscie juz wszystkie cofniecia\n";
                    break;
                }
                cout << string(spacje, ' ') << "Czy chcesz cofnac ruch?  T/N";
                cin >> wybor;
                if (wybor == 'T' || wybor == 't') {
                    index_ruchu--;
                    cofniecia++;
                    cout << string(duzaprzerwa, '\n');
                    for (int i = 0; i < 4; i++) {
                        for (int j = 0; j < 3; j++) {
                            for (int k = 0; k < 3; k++) {
                                plansze[i][j][k] = archiwum_plansz[index_ruchu][i][j][k];
                            }
                        }
                    }
                    wyswietl_plansze_pentago(plansze, pierwszy, drugi);
                }
                else if (wybor == 'N' || wybor == 'n') {
                    break;
                }
                else cout << string(spacje, ' ') << "Nieprawidlowy wybor\n";
            }
            wyswietl_plansze_pentago(plansze, pierwszy, drugi);

            if (wygrana_pentago(plansze)) break;
        }
        while (true) {
            cout << string(spacje, ' ') << "Czy chcesz przejerze gre? T/N\n";
            char wybor;
            cin >> wybor;
            if (wybor == 'T' || wybor == 't') {
                przegladaj_gre(archiwum_plansz, index_ruchu, pierwszy, drugi);
            }
            else if (wybor == 'N' || wybor == 'n') {
                break;
            }
            else cout << string(spacje, ' ') << "Zly wybor\n";
        }
    }

}

void rysuj_menu() {
    cout << "    " << string(34, '*') << "MENU" << string(34, '*') << "\n";
    cout << "    *" << string(28, ' ') << "Wybierz opcje:" << string(28, ' ') << "*\n";
    cout << "    *" << string(26, ' ') << "1. Kolko i krzyzyk" << string(26, ' ') << "*\n";
    cout << "    *" << string(31, ' ') << "2.Pentago" << string(30, ' ') << "*\n";
    cout << "    *" << string(25, ' ') << "0. Wyjdz z programu" << string(26, ' ') << "*\n";
    cout << "    " << string(72, '*');
}

int main()
{
    int plansza[4][3][3];
    cout << "\n";
    int opt;

    do {
        rysuj_menu();

        cout << "        Podaj swoj wybor: ";
        cin >> opt;
        cout << string(4 * duzaprzerwa, '\n');


        switch (opt) {
        case 1: graj_w_kolo_i_krzyzyk();
            break;
        case 2: graj_w_pentago();
            break;
        case 0:
            break;
        default:
            cout << "Niepoprawna opcja!\n\n";
            break;
        }

    } while (opt != 0);
}