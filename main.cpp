#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

void BoucleDuJeu();
int choix_principal;
int choix_secondaire ;

//fonction d'affichage du menu principal
void Menu_Principal(){
    cout <<"______________________________________________________________________________\n";
    cout <<"_|                             CONVERTISSEUR                                |_\n";
    cout <<"_|                              Menu Principal                              |_\n";
    cout <<"_|__________________________________________________________________________|_\n";
    cout <<" |           Choississez l'une des options de conversion ci-dessous!        | \n";
    cout <<"_|__________________________________________________________________________|_\n";
    cout <<" [1. ]                    binaire   --->   decimal                          |_\n";
    cout <<" [2. ]                    binaire   --->   hexadecimal                      |_\n";
    cout <<" [3. ]                    binaire   --->   octal                            |_\n";
    cout <<" [4. ]                    decimal   --->   binaire                          |_\n";
    cout <<" [5. ]                    decimal   --->   hexadecimal                      |_\n";
    cout <<" [6. ]                    decimal   --->   octal                            |_\n";
    cout <<" [7. ]                hexadecimal   --->   binaire                          |_\n";
    cout <<" [8. ]                hexadecimal   --->   decimal                          |_\n";
    cout <<" [9. ]                hexadecimal   --->   octale                           |_\n";
    cout <<" [10.]                      octal   --->   binaire                          |_\n";
    cout <<" [11.]                      octal   --->   decimal                          |_\n";
    cout <<" [12.]                      octal   --->   hexadecimal                      |_\n";
    cout <<"_|__________________________________________________________________________|_\n";
    cout <<" [0.]                                 Quitter                               |_\n";
    cout <<"_|__________________________________________________________________________|_\n \n";
    cout <<"Votre choix : ";
}



void Menu_secondaire(){
    cout <<"______________________________________________________________________________\n";
    cout <<"_|                             CONVERTISSEUR                                |_\n";
    cout <<"_|                             Menu Secondaire                              |_\n";
    cout <<"_|__________________________________________________________________________|_\n";
    cout <<" |                Choississez l'une des options de ci-dessous!              | \n";
    cout <<"_|__________________________________________________________________________|_\n";
    cout <<" [1. ]            Continuer de convertir dans la meme option                |_\n";
    cout <<" [2. ]                    Retourner au menu principal                       |_\n";
    cout <<" [0. ]                              Quitter                                 |_\n";
    cout <<"_|__________________________________________________________________________|__\n";
    cout <<"Votre choix : ";
    cin >> choix_secondaire;
    if (choix_secondaire == 0){
        system("CLS");
        cout <<"A la prochaine\n";
        exit(1);
    }
    
    if (choix_secondaire == 2){
        BoucleDuJeu();
    }
}


//fonction pour convertir un nbre décimal négatif en un nombre décimal positif en utilisant la méthode du complément à 2
int dec_complement(int n){
    n = n * -1;
    string str = to_string(n);
    str = "0" + str;
    //complémenter les chiffre de la chaine obtenue en suivant la logique du complément à 1
    for (size_t i = 0; i < str.length(); i++){
        str[i] = '9'- str[i] + '0';
    }
    int result = stoi(str) + 1 ; //conversion de la nouvelle chaine obtenue en entier
    return result;
}


//fonction pour convertir un nbre binaire négatif en un nombre binaire positif en utilisant la méthode du complément à 2
string bin_complement (string n){
    if ( n[0] == '-'){
        n[0] = '0';   //remplace le premier caractère par 0
        //inverser les 1 et les 0
        for (char &c : n){
            if(c == '0'){c = '1';}
            else if(c == '1'){c = '0';}
        }
        bool retenue = true;
        for(int i = n.size() - 1; i >= 0; --i){
            if(retenue){
                if (n[i] == '0'){
                    n[i] = '1';
                    retenue = false;
                }else {
                n[i] = '0'; 
                }
            }
        }
        n = n ;
    }
    else{
        n = n;
    }
    cout << "L'équivalent de ce nombre négatif est:" <<n <<"\n";
    return n;
}


//fonction pour convertir un nbre octal négatif en un nombre octal positif en utilisant la méthode du complément à 2
string oct_complement (string n){
    if( n[0] == '-'){
       n[0] = '0';   //remplace le premier caractère par 0
        //complémenter les chiffre de la chaine obtenue en suivant la logique du complément à 1
        for (size_t i = 0; i < n.length(); i++){
            n[i] = '7'- n[i] + '0';
        } 
        //ajouter 1
        for (int i = n.size() - 1; i >= 0; --i)
        {
            if (n[i] < '7')
            {
                n[i] = n[i] + 1;
                break;
            }
        }  
    }
    cout << "L'équivalent de ce nombre négatif est:" <<n <<"\n";
    return n;
}


//fonction pour convertir un nbre hexa négatif en un nombre hexa positif en utilisant la méthode du complément à 2
string hexa_complement (string n){
    if( n[0] == '-'){
        n[0] = '0';   //remplace le premier caractère par 0
        //complémenter les chiffre de la chaine obtenue en suivant la logique du complément à 1
        //vérifier si le cractère est un chiffre (0, 1, 2, 3, 4, 5, 6, 7, 8, 9)
        for(char &c : n){
            switch (c)
            {
            case '0': c = 'F';break;
            case '1': c = 'E';break;
            case '2': c = 'D';break;
            case '3': c = 'C';break;
            case '4': c = 'B';break;
            case '5': c = 'A';break;
            case '6': c = '9';break;
            case '7': c = '8';break;
            case '8': c = '7';break;
            case '9': c = '6';break;
            case 'A': c = '5';break;
            case 'B': c = '4';break;
            case 'C': c = '3';break;
            case 'D': c = '2';break;
            case 'E': c = '1';break;
            case 'F': c = '0';break;
            default:
                break;
            }
        }
        bool retenue = true;
        for(int i = n.size() - 1; i >= 1 && retenue; --i){
            if(n[i] >= '0' && n[i] <= '9'){
                n[i] = n[i] + 1;
            }else if(n[i] >= 'A' && n[i] <= 'F'){
                n[i] = n[i] + 1;
            }
            retenue = false;
        }
    }
    cout << "L'équivalent de ce nombre négatif est:" <<n <<"\n";
    return n;
}


//fonction de conversion binaire vers decimal
void bin_vers_dec(){
    string nbre_binaire;
    int nbre_decimal = 0;
    int puissance = 0;
    cout <<"Vous avez choisi l'option de conversion binaire vers decimal.\n";
    //validation de l'entrée
    bool valide = false;
    do
    {
        cout <<"Entrez le nombre binaire que vous souhaitez convertir : ";
        cin >> nbre_binaire;
        valide = true;
        for (size_t i = (nbre_binaire[0] == '-' ? 1 : 0); i < nbre_binaire.length(); i++){
            if (nbre_binaire[i] != '0'&& nbre_binaire[i] != '1'){
                cout << "veillez entrer un nombre contenant uniquement des '0' et des '1' .\n";
                valide = false;
                break;
            }
        }
    } while (!valide);
    if ( nbre_binaire[0] == '-'){
        nbre_binaire = bin_complement(nbre_binaire);
    }
    for(int i = nbre_binaire.length() - 1; i >= 0; i--){
        int bit = nbre_binaire[i] - '0'; //convertir le caractère en entier
        nbre_decimal += bit * pow(2, puissance);
        puissance++;
    }
    cout << "(" << nbre_binaire <<")\u2082 ---> (" <<nbre_decimal <<")\u2081\u2080\n\n";
    Menu_secondaire();
    if (choix_secondaire == 1 && choix_principal != 0){
        bin_vers_dec();
    }
    if(choix_secondaire != 1 && choix_secondaire != 2 && choix_secondaire != 0){
        do
        {
            cout <<"choix invalide. choississez une options parmi celles proposees\n";
            Menu_secondaire();
        } while (choix_secondaire != 1 && choix_secondaire != 2 && choix_secondaire != 0);
        if (choix_secondaire == 1 && choix_principal != 0){
        bin_vers_dec();
        }
    }
}



//fonction de conversion binaire vers hexadecimal
void bin_vers_hex(){
    string nbre_binaire;
    cout <<"Vous avez choisi l'option de conversion binaire vers hexadecimal.\n";
    bool valide = false;
    do
    {
        cout <<"Entrez le nombre binaire que vous souhaitez convertir : ";
        cin >> nbre_binaire;
        valide = true;
        for (size_t i = (nbre_binaire[0] == '-' ? 1 : 0); i < nbre_binaire.length(); i++){
            if (nbre_binaire[i] != '0'&& nbre_binaire[i] != '1'){
                cout << "veillez entrer un nombre contenant uniquement des '0' et des '1' .\n";
                valide = false;
                break;
            }
        }
    } while (!valide);
    if ( nbre_binaire[0] == '-'){
        nbre_binaire = bin_complement(nbre_binaire);
    }//conversion en positif si necessaire
    cout << "(" << nbre_binaire <<")\u2082 ---> (";
    string nbre_hexadecimal = "";
    int longueur_nbre_binaire = nbre_binaire.size();
    // on determine le nombre de chiffres manquants pour pouvoir diviser notre chaine en blocs de 4 chiffres.
    int reste = 4 - (longueur_nbre_binaire % 4);
    if (reste == 4){reste = 0;}
    // on ajoute des zéros à gauche de la chaine pour combler les chiffres manquants
    nbre_binaire.insert(0, reste, '0');
    //diviser le nouveau nombre binaire obtenu en bloc de 4 bits
    for (size_t i = 0; i < nbre_binaire.size(); i += 4){
        string groupe = nbre_binaire.substr(i, 4);
        //conversion des blocs binaires en entiers
        for (size_t j = 0; j < groupe.size(); j++){
            if (groupe == "0000"){nbre_hexadecimal = '0';}
            if (groupe == "0001"){nbre_hexadecimal = '1';}
            if (groupe == "0010"){nbre_hexadecimal = '2';}
            if (groupe == "0011"){nbre_hexadecimal = '3';}
            if (groupe == "0100"){nbre_hexadecimal = '4';}
            if (groupe == "0101"){nbre_hexadecimal = '5';}
            if (groupe == "0110"){nbre_hexadecimal = '6';}
            if (groupe == "0111"){nbre_hexadecimal = '7';}
            if (groupe == "1000"){nbre_hexadecimal = '8';}
            if (groupe == "1001"){nbre_hexadecimal = '9';}
            if (groupe == "1010"){nbre_hexadecimal = 'A';}
            if (groupe == "1011"){nbre_hexadecimal = 'B';}
            if (groupe == "1100"){nbre_hexadecimal = 'C';}
            if (groupe == "1101"){nbre_hexadecimal = 'D';}
            if (groupe == "1110"){nbre_hexadecimal = 'E';}
            if (groupe == "1111"){nbre_hexadecimal = 'F';}
        }
        cout <<nbre_hexadecimal;
    }
    cout <<")\u2081\u2086\n\n"; 
    Menu_secondaire();
    if (choix_secondaire == 1){
        bin_vers_hex();
    }
    if(choix_secondaire != 1 && choix_secondaire != 2 && choix_secondaire != 0){
        do
        {
            cout <<"choix invalide. choississez une options parmi celles proposees\n";
            Menu_secondaire();
        } while (choix_secondaire != 1 && choix_secondaire != 2 && choix_secondaire != 0);
        if (choix_secondaire == 1 && choix_principal != 0){
        bin_vers_hex();
        }
    }
}



//fonction de conversion binaire vers octal
void bin_vers_oct(){
    string nbre_binaire;
    cout <<"Vous avez choisi l'option de conversion binaire vers octal.\n";
    bool valide = false;
    do
    {
        cout <<"Entrez le nombre binaire que vous souhaitez convertir : ";
        cin >> nbre_binaire;
        valide = true;
        for (size_t i = (nbre_binaire[0] == '-' ? 1 : 0); i < nbre_binaire.length(); i++){
            if (nbre_binaire[i] != '0'&& nbre_binaire[i] != '1'){
                cout << "veillez entrer un nombre contenant uniquement des '0' et des '1' .\n";
                valide = false;
                break;
            }
        }
    } while (!valide);
    if ( nbre_binaire[0] == '-'){
        nbre_binaire = bin_complement(nbre_binaire);
    }
    cout << "(" << nbre_binaire <<")\u2082 ---> (";
    string nbre_octal = "";
    while (nbre_binaire.length() % 3 != 0) 
    {nbre_binaire = "0" + nbre_binaire;}  //ajouter des zéros à gauche du nombre binaire
    //diviser le nouveau nombre binaire obtenu en bloc de 3 bits
    for (size_t i = 0; i < nbre_binaire.length(); i += 3){
        string groupe = nbre_binaire.substr(i, 3);
        //conversion des blocs binaires en entiers
        for (size_t j = 0; j < groupe.size(); j++){
            if (groupe == "000"){nbre_octal = '0';}
            if (groupe == "001"){nbre_octal = '1';}
            if (groupe == "010"){nbre_octal = '2';}
            if (groupe == "011"){nbre_octal = '3';}
            if (groupe == "100"){nbre_octal = '4';}
            if (groupe == "101"){nbre_octal = '5';}
            if (groupe == "110"){nbre_octal = '6';}
            if (groupe == "111"){nbre_octal = '7';}
        }
        cout <<nbre_octal;
    }
    cout <<")\u2088\n\n";
    Menu_secondaire();
    if (choix_secondaire == 1){
        bin_vers_oct();
    }
    if(choix_secondaire != 1 && choix_secondaire != 2 && choix_secondaire != 0){
        do
        {
            cout <<"choix invalide. choississez une options parmi celles proposees\n";
            Menu_secondaire();
        } while (choix_secondaire != 1 && choix_secondaire != 2 && choix_secondaire != 0);
        if (choix_secondaire == 1 && choix_principal != 0){
        bin_vers_oct();
        }
    }
}



//fonction de conversion decimal vers binaire
void dec_vers_bin() {
    int nbre_decimal;
    string nbre_binaire = "";
    cout << "Vous avez choisi l'option de conversion decimal vers binaire.\n";
    // Boucle pour garantir une entrée valide
    while (true) {
        cout << "Entrez le nombre decimal que vous souhaitez convertir : ";
        cin >> nbre_decimal;
        // Vérification de l'entrée
        if (cin.fail()) {
            cin.clear(); // Réinitialise les flags d'erreur
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore le reste de l'entrée
            cout << "Erreur : Veuillez entrer un nombre entier valide.\n";
        } else if (nbre_decimal < 0 ) {
            nbre_decimal = dec_complement(nbre_decimal);
            cout <<"L'équivalent de ce nombre négatif est:" <<nbre_decimal <<"\n";
            break;
        } else {
            break; // L'entrée est correcte, sortir de la boucle
        }
    }
    cout << "(" << nbre_decimal << ")\u2081\u2080 ---> (";
    // Gestion du cas spécial 0
    if (nbre_decimal == 0) {
        nbre_binaire = "0";
    } else {
        // Conversion décimal vers binaire
        while (nbre_decimal > 0) {
            int reste = nbre_decimal % 2;
            nbre_binaire = to_string(reste) + nbre_binaire;
            nbre_decimal /= 2;
        }
    }

    cout << nbre_binaire;
    cout << ")\u2082\n\n";

    Menu_secondaire();

    // Gestion du choix secondaire
    if (choix_secondaire == 1) {
        dec_vers_bin();
    } else if (choix_secondaire != 2 && choix_secondaire != 0) {
        do {
            cout << "Choix invalide. Choisissez une option parmi celles proposées.\n";
            Menu_secondaire();
        } while (choix_secondaire != 1 && choix_secondaire != 2 && choix_secondaire != 0);

        if (choix_secondaire == 1 && choix_principal != 0) {
            dec_vers_bin();
        }
    }
}



//fonction de conversion decimal vers hexadecimal
void dec_vers_hex(){
    int nbre_decimal;
    string nbre_hex = "";
    string char_hex = "0123456789ABCDEF";
    cout <<"Vous avez choisi l'option de conversion decimal vers hexadecimal.\n";
    // Boucle pour garantir une entrée valide
    while (true) {
        cout << "Entrez le nombre decimal que vous souhaitez convertir : ";
        cin >> nbre_decimal;

        // Vérification de l'entrée
        if (cin.fail()) {
            cin.clear(); // Réinitialise les flags d'erreur
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore le reste de l'entrée
            cout << "Erreur : Veuillez entrer un nombre entier valide.\n";
        } else if (nbre_decimal < 0) {
            nbre_decimal = dec_complement(nbre_decimal);
            cout <<"L'équivalent de ce nombre négatif est:" <<nbre_decimal <<"\n";
            break;
        } else {
            break; // L'entrée est correcte, sortir de la boucle
        }
    }
    cout << "(" << nbre_decimal <<")\u2081\u2080 ---> (";
    if(nbre_decimal == 0){nbre_hex = "0";}
    while (nbre_decimal > 0){
        int reste = nbre_decimal % 16;
        nbre_hex = char_hex[reste] + nbre_hex;
        nbre_decimal /= 16;
    }
    cout <<nbre_hex;
    cout <<")\u2081\u2086\n\n";
    Menu_secondaire();
    if (choix_secondaire == 1){
        dec_vers_hex();
    }
    if(choix_secondaire != 1 && choix_secondaire != 2 && choix_secondaire != 0){
        do
        {
            cout <<"choix invalide. choississez une options parmi celles proposees\n";
            Menu_secondaire();
        } while (choix_secondaire != 1 && choix_secondaire != 2 && choix_secondaire != 0);
        if (choix_secondaire == 1 && choix_principal != 0){
        dec_vers_hex();
        }
    }
}



//fonction de conversion decimal vers octal
void dec_vers_oct(){
    int nbre_decimal;
    string nbre_octal = "";
    cout <<"Vous avez choisi l'option de conversion decimal vers octal.\n";
    // Boucle pour garantir une entrée valide
    while (true) {
        cout << "Entrez le nombre decimal que vous souhaitez convertir : ";
        cin >> nbre_decimal;
        // Vérification de l'entrée
        if (cin.fail()) {
            cin.clear(); // Réinitialise les flags d'erreur
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore le reste de l'entrée
            cout << "Erreur : Veuillez entrer un nombre entier valide.\n";
        } else if (nbre_decimal < 0) {
            nbre_decimal = dec_complement(nbre_decimal);
            cout <<"L'équivalent de ce nombre négatif est:" <<nbre_decimal <<"\n";
            break;
        } else {
            break; // L'entrée est correcte, sortir de la boucle
        }
    }
    cout << "(" << nbre_decimal <<")\u2081\u2080 ---> (";
    if(nbre_decimal == 0){nbre_octal = "0";}
    while (nbre_decimal > 0){
        int reste = nbre_decimal % 8;
        nbre_octal = to_string(reste) + nbre_octal;
        nbre_decimal /= 8;
    }
    cout <<nbre_octal;
    cout <<")\u2088\n\n";
    Menu_secondaire();
    if (choix_secondaire == 1){
        dec_vers_oct();
    }
    if(choix_secondaire != 1 && choix_secondaire != 2 && choix_secondaire != 0){
        do
        {
            cout <<"choix invalide. choississez une options parmi celles proposees\n";
            Menu_secondaire();
        } while (choix_secondaire != 1 && choix_secondaire != 2 && choix_secondaire != 0);
        if (choix_secondaire == 1 && choix_principal != 0){
        dec_vers_oct();
        }
    }
}



//fonction de conversion hexadecimal vers
void hex_vers_bin(){
    string nbre_hex = "";
    string nbre_binaire = "";
    cout <<"Vous avez choisi l'option de conversion hexadecimal vers binaire.\n";
    cout <<"Entrez le nombre hexadecimal que vous souhaitez convertir : ";
    cin >> nbre_hex;
    if ( nbre_hex[0] == '-'){
        nbre_hex = hexa_complement(nbre_hex);
    }
    cout << "(" << nbre_hex <<")\u2081\u2086 ---> (";
    for(int i = 0; nbre_hex[i] != '\0'; i++ ){
        if(nbre_hex[i] == '0'){nbre_binaire = "0000";}
        else if(nbre_hex[i] == '1'){nbre_binaire = "0001";}
        else if(nbre_hex[i] == '2'){nbre_binaire = "0010";}
        else if(nbre_hex[i] == '3'){nbre_binaire = "0011";}
        else if(nbre_hex[i] == '4'){nbre_binaire = "0100";}
        else if(nbre_hex[i] == '5'){nbre_binaire = "0101";}
        else if(nbre_hex[i] == '6'){nbre_binaire = "0110";}
        else if(nbre_hex[i] == '7'){nbre_binaire = "0111";}
        else if(nbre_hex[i] == '8'){nbre_binaire = "1000";}
        else if(nbre_hex[i] == '9'){nbre_binaire = "1001";}
        else if(nbre_hex[i] == 'A'){nbre_binaire = "1010";}
        else if(nbre_hex[i] == 'B'){nbre_binaire = "1O11";}
        else if(nbre_hex[i] == 'C'){nbre_binaire = "1100";}
        else if(nbre_hex[i] == 'D'){nbre_binaire = "1101";}
        else if(nbre_hex[i] == 'E'){nbre_binaire = "1110";}
        else if(nbre_hex[i] == 'F'){nbre_binaire = "1111";}
        else{
            throw
            invalid_argument("Caractere hexa invalide");
        }
        cout <<nbre_binaire;
    }
    cout <<")\u2082\n\n";
    Menu_secondaire();
    if (choix_secondaire == 1){
        hex_vers_bin();
    }
    if(choix_secondaire != 1 && choix_secondaire != 2 && choix_secondaire != 0){
        do
        {
            cout <<"choix invalide. choississez une options parmi celles proposees\n";
            Menu_secondaire();
        } while (choix_secondaire != 1 && choix_secondaire != 2 && choix_secondaire != 0);
        if (choix_secondaire == 1 && choix_principal != 0){
        hex_vers_bin();
        }
    }
}



//fonction de conversion hexadecimal vers decimal
void hex_vers_dec(){
    string nbre_hex = "";
    int nbre_decimal = 0;
    int puissance = 0;
    cout <<"Vous avez choisi l'option de conversion hexadecimal vers decimal.\n";
    cout <<"Entrez le nombre hexadecimal que vous souhaitez convertir : ";
    cin >> nbre_hex;
    if ( nbre_hex[0] == '-'){
        nbre_hex = hexa_complement(nbre_hex);
    }
    cout << "(" << nbre_hex <<")\u2081\u2086 ---> (";
    for(int i = nbre_hex.length() - 1 ; i >= 0; i--){
        char caractere = nbre_hex[i];
        int valeur;
        //vérifier si le cractère est un chiffre (0, 1, 2, 3, 4, 5, 6, 7, 8, 9)
        if (caractere >= '0' && caractere <= '9'){
            valeur = caractere - '0';   //conversion du caractère en entier
        }
        else if(caractere >= 'A' && caractere <= 'F'){
            valeur = 10 + (caractere - 'A');   //conversion du caractère en entier 
        }
        else{
            throw
            invalid_argument("Caractere hexa invalide : " + string(1, caractere));
        }
        nbre_decimal += valeur * static_cast <int>(pow(16, puissance));
        puissance++;
    }
    cout <<nbre_decimal;
    cout <<")\u2081\u2080\n\n";
    Menu_secondaire();
    if (choix_secondaire == 1){
        hex_vers_dec();
    }
    if(choix_secondaire != 1 && choix_secondaire != 2 && choix_secondaire != 0){
        do
        {
            cout <<"choix invalide. choississez une options parmi celles proposees\n";
            Menu_secondaire();
        } while (choix_secondaire != 1 && choix_secondaire != 2 && choix_secondaire != 0);
        if (choix_secondaire == 1 && choix_principal != 0){
        hex_vers_dec();
        }
    }
}



//fonction de conversion hexadecimal vers decimal
void hex_vers_oct(){
    string nbre_hex = "";
    string nbre_octal = "";
    int nbre_decimal = 0;
    int puissance = 0;
    cout <<"Vous avez choisi l'option de conversion hexadecimal vers octal.\n";
    cout <<"Entrez le nombre hexadecimal que vous souhaitez convertir : ";
    cin >> nbre_hex;
    if ( nbre_hex[0] == '-'){
        nbre_hex = hexa_complement(nbre_hex);
    }
    cout << "(" << nbre_hex <<")\u2081\u2086 ---> (";
    //Etapes 1 : coversion hexadecimal vers decimal
    for(int i = nbre_hex.length() - 1 ; i >= 0; i--){
        char caractere = nbre_hex[i];
        int valeur;
        //vérifier si le cractère est un chiffre (0, 1, 2, 3, 4, 5, 6, 7, 8, 9)
        if (caractere >= '0' && caractere <= '9'){
            valeur = caractere - '0';   //conversion du caractère en entier
        }
        
        else if(caractere >= 'A' && caractere <= 'F'){
            valeur = 10 + (caractere - 'A');   //conversion du caractère en entier 
        }
        else{
            throw
            invalid_argument("Caractere hexa invalide : " + string(1, caractere));
        }
        nbre_decimal += valeur * static_cast <int>(pow(16, puissance));
        puissance++;
    }
    //Etapes 2 : coversion decimal vers octal
    if(nbre_decimal == 0){nbre_hex = "0";}
    while (nbre_decimal > 0){
        int reste = nbre_decimal % 8;
        nbre_octal = to_string(reste) + nbre_octal;
        nbre_decimal /= 8;
    }
    cout << nbre_octal;
    cout <<")\u2088\n\n";
    Menu_secondaire();
    if (choix_secondaire == 1){
        hex_vers_oct();
    }
    if(choix_secondaire != 1 && choix_secondaire != 2 && choix_secondaire != 0){
        do
        {
            cout <<"choix invalide. choississez une options parmi celles proposees\n";
            Menu_secondaire();
        } while (choix_secondaire != 1 && choix_secondaire != 2 && choix_secondaire != 0);
        if (choix_secondaire == 1 && choix_principal != 0){
        hex_vers_oct();
        }
    }
}



void oct_vers_bin(){
    string nbre_oct = "";
    string nbre_binaire = "";
    cout <<"Vous avez choisi l'option de conversion octal vers binaire.\n";
    cout <<"Entrez le nombre octal que vous souhaitez convertir : ";
    cin >> nbre_oct;
    if (nbre_oct[0] == '-'){
        nbre_oct = oct_complement(nbre_oct);
    }
    cout << "(" << nbre_oct <<")\u2088 ---> (";
    for(int i = 0; nbre_oct[i] != '\0'; i++ ){
        if(nbre_oct[i] == '0'){nbre_binaire = "000";}
        else if(nbre_oct[i] == '1'){nbre_binaire = "001";}
        else if(nbre_oct[i] == '2'){nbre_binaire = "010";}
        else if(nbre_oct[i] == '3'){nbre_binaire = "011";}
        else if(nbre_oct[i] == '4'){nbre_binaire = "100";}
        else if(nbre_oct[i] == '5'){nbre_binaire = "101";}
        else if(nbre_oct[i] == '6'){nbre_binaire = "110";}
        else if(nbre_oct[i] == '7'){nbre_binaire = "111";}
        else{
            throw
            invalid_argument("Caractere octal invalide");
        }
        cout <<nbre_binaire;
    }
    cout <<")\u2082\n\n";
    Menu_secondaire();
    if (choix_secondaire == 1){
        oct_vers_bin();
    }
    if(choix_secondaire != 1 && choix_secondaire != 2 && choix_secondaire != 0){
        do
        {
            cout <<"choix invalide. choississez une options parmi celles proposees\n";
            Menu_secondaire();
        } while (choix_secondaire != 1 && choix_secondaire != 2 && choix_secondaire != 0);
        if (choix_secondaire == 1 && choix_principal != 0){
        oct_vers_bin();
        }
    }
}



void oct_vers_dec(){
    string nbre_octal = "";
    int nbre_decimal = 0;
    int puissance = 0;
    cout <<"Vous avez choisi l'option de conversion octal vers decimal.\n";
    cout <<"Entrez le nombre octal que vous souhaitez convertir : ";
    cin >> nbre_octal;
    if (nbre_octal[0] == '-'){
        nbre_octal = oct_complement(nbre_octal);
    }
    cout << "(" << nbre_octal <<")\u2088 ---> (";
    for(int i = nbre_octal.length() - 1 ; i >= 0; i--){
        char caractere = nbre_octal[i];
        int valeur;
        //vérifier si le cractère est un chiffre (0, 1, 2, 3, 4, 5, 6, 7)
        if (caractere >= '0' && caractere <= '7'){
            valeur = caractere - '0';   //conversion du caractère en entier
        }
        else{
            throw
            invalid_argument("Caractere hexa invalide : " + string(1, caractere));
        }
        nbre_decimal += valeur * static_cast <int>(pow(8, puissance));
        puissance++;
    }
    cout <<nbre_decimal;
    cout <<")\u2081\u2080\n\n";
    Menu_secondaire();
    if (choix_secondaire == 1){
        oct_vers_dec();
    }
    if(choix_secondaire != 1 && choix_secondaire != 2 && choix_secondaire != 0){
        do
        {
            cout <<"choix invalide. choississez une options parmi celles proposees\n";
            Menu_secondaire();
        } while (choix_secondaire != 1 && choix_secondaire != 2 && choix_secondaire != 0);
        if (choix_secondaire == 1 && choix_principal != 0){
        oct_vers_dec();
        }
    }
}



void oct_vers_hex(){
    string nbre_hex = "";
    string nbre_octal = "";
    int nbre_decimal = 0;
    int puissance = 0;
    cout <<"Vous avez choisi l'option de conversion octal vers hexadecimal.\n";
    cout <<"Entrez le nombre octal que vous souhaitez convertir : ";
    cin >> nbre_octal;
    if (nbre_octal[0] == '-'){
        nbre_octal = oct_complement(nbre_octal);
    }
    cout << "(" << nbre_octal <<")\u2088 ---> (";
    //Etapes 1 : coversion octal vers decimal
    for(int i = nbre_octal.length() - 1 ; i >= 0; i--){
        char caractere = nbre_octal[i];
        //vérifier si le cractère est un chiffre (0, 1, 2, 3, 4, 5, 6, 7, 8, 9)
        if (caractere < '0' || caractere > '7'){
            throw
            invalid_argument("Caractere hexa invalide : " + string(1, caractere)); // message d'erreur
        }
        nbre_decimal += (caractere - '0') * static_cast <int>(pow(8, puissance));
        puissance++;
    }
    //Etape 2 : conversion decimal vers hexadecimal
    if(nbre_decimal == 0){nbre_octal = "0";}
    while (nbre_decimal > 0){
        int reste = nbre_decimal % 16;
        if (reste < 10){
            nbre_hex = to_string(reste) + nbre_hex;
        }
        else{
            nbre_hex = static_cast<char>('A' + (reste - 10)) + nbre_hex;
        }
        nbre_decimal /= 16;
    }
    cout <<nbre_hex;
    cout <<")\u2081\u2086\n\n";
    Menu_secondaire(); //"\u2080"
    if (choix_secondaire == 1){
        oct_vers_hex();
    }
    if(choix_secondaire != 1 && choix_secondaire != 2 && choix_secondaire != 0){
        do
        {
            cout <<"choix invalide. choississez une options parmi celles proposees\n";
            Menu_secondaire();
        } while (choix_secondaire != 1 && choix_secondaire != 2 && choix_secondaire != 0);
        if (choix_secondaire == 1 && choix_principal != 0){
        oct_vers_hex();
        }
    }
}



// fonction qui contient la boucle du programme
void BoucleDuJeu(){
    
    do{
        Menu_Principal();
        cin >> choix_principal;
        switch (choix_principal)
        {
        case 1:
            bin_vers_dec();
            break;
        case 2:
            bin_vers_hex();
            break;
        case 3:
            bin_vers_oct();
            break;
        case 4:
            dec_vers_bin();
            break;
        case 5:
            dec_vers_hex();
            break;
        case 6:
            dec_vers_oct();
            break;
        case 7:
            hex_vers_bin();
            break;
        case 8:
            hex_vers_dec();
            break;
        case 9:
            hex_vers_oct();
            break;
        case 10:
            oct_vers_bin();
            break;
        case 11:
            oct_vers_dec();
            break;
        case 12:
            oct_vers_hex();
            break;
        case 0:
            break;
        default:
            cout <<"choix invalide choississez une option parmi celles proposees\n";
            break;
        }
    }while (choix_principal != 0);
}



//fonction principale du programme
int main(){
    BoucleDuJeu();
    system("CLS");
    cout <<"A la prochaine\n";
    return 0;
}