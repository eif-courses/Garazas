#include <iostream>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>

struct Gedimas {
    std::string pavadinimas;
    bool arSugedes;
    int id;
    double procentaliai;
};

struct Autoservisas {
    std::vector<Gedimas> gedimai;

    void papildytiGedimuSarasa(Gedimas gedimas);
};


struct Klientas {
    Autoservisas autoservisas;
    std::string vardas;
    std::map<int, Gedimas> gedimai;

    void pateiktiGedima(Gedimas g);

    void gedimuSarasas();
};


struct Automobilis {
    std::string modelis;
    Klientas klientas;
};


struct Ataskaita {

};

struct Meistras {
    void tvarkytiAutomobili(Automobilis automobilis);
};


int main() {

    Autoservisas autoservisas;

    Gedimas variklio;
    variklio.pavadinimas = "Variklio gedimas!";
    variklio.arSugedes = true;
    variklio.id = 1;
    variklio.procentaliai = 0.4;

    Gedimas pakabos;
    pakabos.pavadinimas = "Pakabos gedimas!";
    pakabos.arSugedes = true;
    pakabos.id = 2;
    pakabos.procentaliai = 1.0;

    autoservisas.papildytiGedimuSarasa(variklio);
    autoservisas.papildytiGedimuSarasa(pakabos);

    Klientas klientas;
    klientas.vardas = "Petras";

    std::cout << "=========================================\n";
    int input = 1;
    int index = 1;
    while (input != 0) {
        std::cout << "Pasirinkite gedimus:\n";
        index = 1;
        for (Gedimas g: autoservisas.gedimai) {
            std::cout << "\t" << index << ". " << g.pavadinimas << std::endl;
            index++;
        }
        std::cout << "3. Atspausdinti Gedimu Sarasa.\n";
        std::cout << "0. ISEITI.\n";

        std::cin >> input;

        switch (input) {
            case 0:
                break;
            case 1:
                klientas.pateiktiGedima(autoservisas.gedimai[0]);
                break;
            case 2:
                klientas.pateiktiGedima(autoservisas.gedimai[1]);
                break;
            case 3:
                klientas.gedimuSarasas();
                break;
            default:
                std::cout << "NETINKAMA IVESTIS!\n";
                break;

        }

    }
    // std::cout << "=========================================\n";





    std::cout << "=========================================\n";


    // cout <<


    return 0;
}

void Autoservisas::papildytiGedimuSarasa(Gedimas gedimas) {
    gedimai.push_back(gedimas);
}


void Meistras::tvarkytiAutomobili(Automobilis automobilis) {

}

void Klientas::pateiktiGedima(Gedimas g) {
    gedimai[g.id] = g;

    // map<int, Gedimas>
    gedimai[1] = g;


}

void Klientas::gedimuSarasas() {

    std::cout << "================GEDIMU SARASAS=========================\n";

    for (auto elem: gedimai) {
        std::cout << "pav: " << elem.second.pavadinimas << "arSugedes: " << elem.second.arSugedes << "bukle: " << elem.second.procentaliai
                  << std::endl;
    }

    std::cout << "=========================================\n";


}
