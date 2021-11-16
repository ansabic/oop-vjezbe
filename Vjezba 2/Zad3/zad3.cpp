#include <iostream>
#include<cmath>

using namespace std;

typedef struct {
    float x;
    float y;
} Tocka;

typedef struct {
    float r;
    Tocka centar;
} Kruznica;

typedef struct {
    Tocka dl;
    Tocka gd;
} Pravokutnik;

float udaljenost(Tocka a, Tocka b) {
    return sqrtf(powf(a.x - b.x, 2) + powf(a.y - b.y, 2));
}

bool tockaIzvan(Tocka tocka, Kruznica kruznica) {
    if (udaljenost(tocka, kruznica.centar) > kruznica.r)
        return true;
    else
        return false;
}

Tocka zaXDesno(Tocka tocka, float x) {
    Tocka rezultat;
    rezultat.x = tocka.x + x;
    rezultat.y = tocka.y;
}

Tocka zaXLijevo(Tocka tocka, float x) {
    Tocka rezultat;
    rezultat.x = tocka.x - x;
    rezultat.y = tocka.y;
}

bool sijekuPrekoOsiY(Tocka donja, Tocka gornja, Kruznica k) {
    if (donja.x == gornja.x) {
        if (donja.x >= k.centar.x - k.r && donja.x <= k.centar.x + k.r && donja.y <= k.centar.y &&
            gornja.y >= k.centar.y)
            return true;
        else
            return false;
    }
}

bool sijekuPrekoOsiX(Tocka lijeva, Tocka desna, Kruznica k) {
    if (lijeva.y == desna.y) {
        if (lijeva.y >= k.centar.y - k.r && lijeva.y <= k.centar.y + k.r && lijeva.x <= k.centar.x &&
            desna.x >= k.centar.x)
            return true;
        else
            return false;
    }
}

bool pravokutnikNeSijece(const Pravokutnik pravokutnik, const Kruznica kruznica) {
    Tocka dl = pravokutnik.dl;
    Tocka gd = pravokutnik.gd;

    float a = gd.x - dl.x;

    Tocka dd = zaXDesno(dl, a);
    Tocka gl = zaXLijevo(gd, a);

    bool sveVani = tockaIzvan(dl, kruznica) && tockaIzvan(dd, kruznica) && tockaIzvan(gl, kruznica) &&
                   tockaIzvan(gd, kruznica);
    bool sveUnutra = !tockaIzvan(dl, kruznica) && !tockaIzvan(dd, kruznica) && !tockaIzvan(gl, kruznica) &&
                     !tockaIzvan(gd, kruznica);

    bool lijevoSijece = sijekuPrekoOsiY(dl, gl, kruznica);
    bool desnoSijece = sijekuPrekoOsiY(dd, gd, kruznica);
    bool goreSijece = sijekuPrekoOsiX(gl, gd, kruznica);
    bool doljeSijece = sijekuPrekoOsiX(dl, dd, kruznica);

    if (sveVani && !doljeSijece && !goreSijece && !lijevoSijece && !desnoSijece)
        return true;
    if (sveUnutra)
        return true;
    return false;
}

int brojOnihKojiSijeku(Pravokutnik *const &pravokutnici, Kruznica const &kruznica, int n) {
    int counter = 0;
    for (int i = 0; i < n; i++) {
        Pravokutnik pravokutnik = pravokutnici[i];
        if (!pravokutnikNeSijece(pravokutnik, kruznica))
            counter++;
    }
}

int main() {
    int n;
    cout << "Unesi broj pravokutnika:" << endl;
    cin >> n;
    Pravokutnik *listaPravokutnika;
    listaPravokutnika = new Pravokutnik[n];
    Kruznica kruznica;
    for (int i = 0; i < n; i++) {
        listaPravokutnika[i].dl = *new Tocka;
        listaPravokutnika[i].gd = *new Tocka;
        cout << "Unesi donju lijevu tocku pravokutnika: x, y" << endl;
        cin >> listaPravokutnika[i].dl.x;
        cin >> listaPravokutnika[i].dl.y;
        cout << "Unesi gornju desnu tocku pravokutnika: x, y" << endl;
        cin >> listaPravokutnika[i].gd.x;
        cin >> listaPravokutnika[i].gd.y;
    }
    kruznica.centar = *new Tocka;
    cout << "Unesi tocku sredista kruznice i njen radijus: ( x, y, r)" << endl;
    cin >> kruznica.centar.x;
    cin >> kruznica.centar.y;
    cin >> kruznica.r;
    int counter = brojOnihKojiSijeku(listaPravokutnika, kruznica, n);
    cout << "Broj pravokutnika koji sijece je:" << counter << endl;
}

