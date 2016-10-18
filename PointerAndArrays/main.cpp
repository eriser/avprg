#include <QDebug>
#include <vector>

float mittelwert(int * array, int length){
    // in Java
    float summe = 0;
    for (int i = 0; i < length; i++){
        summe += array[i];
    }
    return summe / length;
}

int main(int argc, char *argv[])
{
    // Adresse einer int-Variablen
    int * adresse = 0;
    int a = 5;
    adresse = &a;
    qDebug() << adresse;

    int b = *adresse;
    qDebug() << b;

    // Array von 10 int-Werten
    int * array = new int[10];
    // die Elemente des Arrays sind nicht initialisiert
    qDebug() << array[0];
    for(int i = 0; i < 10; i++){
        array[i] = i;
    }
    float mw = mittelwert(array, 10);
    qDebug() << mw;
    // Gefahren bei der Verwendung von Arrays:
    // Zugriff auf ungültigen Index:
    // array[-1] = 10;
    // array[10] = 0;

    // wenn das Array nicht mehr benötigt wird
    delete[] array;
    // Gefahren bei der Verwendung von Arrays:
    // überschreibt freigegebenen Speicher
    // array[0] = 10;

    // Verwendung der Klasse vector
    std::vector<int> array2 (10); // Array der Länge 10
    qDebug() << array2[0]; // Elemente sind mit 0 initialisiert
    qDebug() << array2.size();
    for(int i = 0; i < array2.size(); i++){
        array2[i] = i;
    }
    // Übergabe eines C-Arrays
    float mw2 = mittelwert(&array2[0], array2.size());
    qDebug() << mw2;
    // nachträgliches Verändern der Größe
    array2.resize(11);
    qDebug() << array2[9];
    qDebug() << array2[10];

    return 0;
}
