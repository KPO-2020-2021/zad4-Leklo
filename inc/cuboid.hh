#pragma once
/** \brief Definicja klasy Cuboid 
 * Plik zawiera definicje i metody klasy Cuboid
*/
#include <iomanip>
#include "size.hh"
#include "matrix3x3.hh"
#include "vector3D.hh"


class Cuboid
{   
    private:
        Vector3D cub[APICES];
        friend std::ostream &operator <<(std::ostream &out, Cuboid const &c);
    public:
        Cuboid();
        Cuboid(Vector3D v[APICES]);
        Cuboid rotation(const Matrix3x3 m);
        Cuboid translation(Vector3D v);
        const Vector3D &operator[](unsigned int index) const;
        void sides();
        

};
/** \brief Konstruktor bezparametryczny klasy Cuboid 
 * @return Obiekt klasy Cuboid, ktorego elementy maja wartosc 0
*/
Cuboid::Cuboid()
{   
    Vector3D v;
    for(unsigned int i = 0; i < APICES; ++i)
    {
        cub[i] = v;
    }
}

/** \brief Konstruktor parametryczny klasy Cuboid
 * @param v tablica wektorow (wektory odpowiadaja wierzcholkom prostopadloscianu)
 * @return Obiekt klasy Cuboid ktorego elementy maja wartosc elementow tablicy wektorow v 
*/
Cuboid::Cuboid(Vector3D v[APICES])
{
    for(unsigned int i = 0; i < APICES; ++i)
    {
        cub[i] = v[i];
    }
}
/** \brief Realizuje rotacje prostopadloscianu
 * @param m macierz obrotu 
 * @return Prostopadloscian po rotacji
*/
Cuboid Cuboid::rotation(Matrix3x3 m)
{   
    Cuboid result;
    
    for(unsigned int i = 0; i < APICES; ++i)
    {
        result.cub[i] = m * cub[i]; 
    }
    return result;
}
/** \brief Realizuje przesuniecia prostopadloscianu o wektor 
 * @param v wektor przesuniecia
 * @return Prostopadloscian przesuniety o wektor
*/
Cuboid Cuboid::translation(Vector3D v)
{
    Cuboid result;
    for(unsigned int i = 0; i < APICES; ++i)
    {
        result.cub[i] = cub[i] + v;
    }
    return result;
}
/** \brief Funktor prostopadloscianu 
 * @param index numer wierzcholka
 * @return Wektor oznaczajacy wierzcholek prostopadloscianu
*/
const Vector3D &Cuboid::operator[](unsigned int index) const
{
    if(index >= APICES){
        std::cerr << "ERROR: Wektor jest poza zasiegiem!" << std::endl;}
    return cub[index];
}
/** \brief Przeciazenie operatora << 
 * @param out strumien wyjscia
 * @param c prostopadloscian
*/
std::ostream &operator <<(std::ostream &out, Cuboid const &c)
{   
    for(unsigned int i = 0; i < APICES; ++i)
    {
        for(unsigned int j = 0; j < 3; ++j)
        {
            out << std::setw(16) << std::fixed << std::setprecision(10) << c.cub[i][j];
            if(j == 2){out << std:: endl;}
        }
    }
    return out;
}
/** \brief  Oblicza, porownuje i wyswietla wartosci przeciwleglych bokow prostopadloscianu
 * @param this prostopadloscian ktorego boki sa porownywane
 * @return Wyswietla komunikat mowiacy czy boki prostopadloscianu sa rowne czy nie oraz ich wartosci
*/
void Cuboid::sides()
{
    double arr[12];
    for(unsigned int i = 0; i < 3; ++i)
        {arr[i] = cub[i].length(cub[i+1]);}
    arr[3] = cub[3].length(cub[0]);
    for(unsigned int i = 4; i < 7; ++i)
        {arr[i] = cub[i].length(cub[i+1]);}
    arr[7] = cub[7].length(cub[4]);
    for(unsigned int i = 0; i < 4; ++i)
        {arr[i+8] = cub[i].length(cub[i+4]);}

    if(arr[0] < arr[1])
    {
        if(arr[0] - arr[2] < epsilon && arr[0] - arr[4] < epsilon && arr[0] - arr[6] < epsilon)
        {
            std::cout << "Krotsze przeciwlegle boki sa sobie rowne\n"
            << std::setw(16) << std::fixed << std::setprecision(10) << arr[0] << "\n" <<std::setw(16)
            << arr[2] << "\n" <<std::setw(16) << arr[4] << "\n" << std::setw(16) << arr[6] << std::endl;
        }
        else
        {
            std::cout << "Krotsze przeciwlegle boki nie sa sobie rowne!!!" << std::endl
            << std::setw(16) << std::fixed << std::setprecision(10) << arr[0] << "\n" <<std::setw(16)
            << arr[2] << "\n" << std::setw(16) << arr[4] << "\n" << std::setw(16) << arr[6] << std::endl;
        }
        if(arr[1] - arr[3] < epsilon && arr[1] - arr[5] < epsilon && arr[1] - arr[7] < epsilon)
        {
            std::cout << "Dluzsze przeciwlegle boki sa sobie rowne\n"
            << std::setw(16) << std::fixed << std::setprecision(10) << arr[1] << "\n" << std::setw(16)
            << arr[3] << "\n" << std::setw(16) << arr[5] << "\n" << std::setw(16) << arr[7] << std::endl;
        }
        else
        {
            std::cout << "Dluzsze przeciwlegle boki nie sa sobie rowne!!!" << std::endl
            << std::setw(16) << std::fixed << std::setprecision(10) << arr[1] << "\n" << std::setw(16)
            << arr[3] << "\n" << std::setw(16) << arr[5] << "\n" << std::setw(16) << arr[7] << std::endl;
        }
    }
    else
    {   
        if(arr[1] - arr[3] < epsilon && arr[1] - arr[5] < epsilon && arr[1] - arr[7] < epsilon)
        {
            std::cout << "Krotsze przeciwlegle boki sa sobie rowne\n"
            << std::setw(16) << std::fixed << std::setprecision(10) << arr[1] << "\n" << std::setw(16)
            << arr[3] << "\n" << std::setw(16) << arr[5] << "\n" << std::setw(16) << arr[7] << std::endl;
        }
        else
        {
            std::cout << "Krotsze przeciwlegle boki nie sa sobie rowne!!!" << std::endl
            << std::setw(16) << std::fixed << std::setprecision(10) << arr[1] << "\n" << std::setw(16)
            << arr[3] << "\n" << std::setw(16) << arr[5] << "\n" << std::setw(16) << arr[7] << std::endl;
        }
        if(arr[0] - arr[2] < epsilon && arr[0] - arr[4] < epsilon && arr[0] - arr[6] < epsilon)
        {
            std::cout << "Dluzsze przeciwlegle boki sa sobie rowne\n"
            << std::setw(16) << std::fixed << std::setprecision(10) << arr[0] << "\n" << std::setw(16)
            << arr[2] << "\n" << std::setw(16) << arr[4] << "\n" << std::setw(16) << arr[6] << std::endl;
        }
        else
        {
            std::cout << "Dluzsze przeciwlegle boki nie sa sobie rowne!!!" << std::endl
            << std::setw(16) << std::fixed << std::setprecision(10) << arr[0] << "\n" << std::setw(16)
            << arr[2] << "\n" << std::setw(16) << arr[4] << "\n" << std::setw(16) << arr[6] << std::endl;
        }
    }
    if(arr[8] - arr[9] < epsilon && arr[8] - arr[10] < epsilon && arr[8] - arr[11] < epsilon)
        {
            std::cout << "Przekatne przeciwlegle boki sa sobie rowne\n"
            << std::setw(16) << std::fixed << std::setprecision(10) << arr[8] << "\n" << std::setw(16)
            << arr[9] << "\n" << std::setw(16) << arr[10] << "\n" << std::setw(16) << arr[11] << std::endl;
        }
        else
        {
            std::cout << "Przekatne przeciwlegle boki nie sa sobie rowne!!!" << std::endl
            << std::setw(16) << std::fixed << std::setprecision(10) << arr[8] << "\n" << std::setw(16)
            << arr[9] << "\n" << std::setw(16) << arr[10] << "\n" << std::setw(16) << arr[11] << std::endl;
        }
}
/** \brief Przeciazenie operatora == 
 * @param c1 pierwszy skladnik (prostopadloscian)
 * @param c2 drugi skladnik (prostopadloscian)
 * @return wartosc bool mowiaca czy dane prostopadlosciany sa sobie rowne
*/
bool operator ==(const Cuboid &c1, const Cuboid &c2)
{
    for(unsigned int i =0; i < APICES; ++i)
    {
        if(c1[i] == c2[i]){}
        else{return false;}
    }
    return true;
}
/** \brief Przeciazenie operatora == 
 * @param c1 pierwszy skladnik (prostopadloscian)
 * @param array drugi skladnik (tablica wektorow)
 * @return wartosc bool mowiaca czy elementy obiektu Cuboid sa rowne elementom tablicy jednoelementowej typu Vector3D
*/
bool operator ==(const Cuboid &c1, const Vector3D array[8])
{
    for(unsigned int i =0; i < APICES; ++i)
    {
        if(c1[i] == array[i]){}
        else{return false;}
    }
    return true;
}

