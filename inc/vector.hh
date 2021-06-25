#pragma once
/** \file 
 * \brief Szablon klasy vector 
 * Plik zawiera odpowiednie metody szablonu klasy vector
*/
#include "size.hh"
#include <iostream>
#include <iomanip>
#include <cmath>

template < unsigned int SIZE>
class Vector
{
private:
    double coor[SIZE];
public:

    Vector();

    Vector(double [SIZE]);

    Vector operator +(const Vector &v);

    Vector operator -(const Vector &v);

    Vector operator *(const double &mul);

    Vector operator /(const double &div);

    double length(const Vector &v);

    const double &operator [] (unsigned int index) const;

    double &operator [] (unsigned int index);

};



/** \brief Konstruktor klasy Vector bezparametryczny
 * @return Tablice wypelniona wartoscia 0
*/
template<unsigned int SIZE>
Vector<SIZE>::Vector() {
    for (unsigned int i = 0; i < SIZE; ++i) {
        coor[i] = 0;
    }
}


/** \brief Konstruktor klasy Vector
 * @param tmp tablica jednowymiarowa typu double
 * @return Tablice wypelniona wartosciami podanymi w argumencie
*/

template< unsigned int SIZE>
Vector< SIZE>::Vector(double tmp[SIZE]) {
    for (unsigned int i = 0; i < SIZE; ++i) {
        coor[i] = tmp[i];
    }
}


/** \brief Realizuje dodawanie dwoch wektorow
 * @param this pierwszy skladnik dodawania
 * @param v drugi skladnik dodawania
 *  
 * @return Sume dwoch skladnikow przekazanych jako wskaznik na parametr
*/
template< unsigned int SIZE>
Vector< SIZE> Vector< SIZE>::operator + (const Vector &v) {
    Vector result;
    for (unsigned int i = 0; i < SIZE; ++i) {
        result[i] = coor[i] += v[i];
    }
    return result;
}



/** \brief Realizuje odejmowanie dwoch wektorow
 * @param this pierwszy skladnik odejmowania
 * @param v drugi skladnik odejmowania
 *  
 * @return Roznice dwoch skladnikow przekazanych jako wskaznik na parametr
*/
template< unsigned int SIZE>
Vector< SIZE> Vector< SIZE>::operator - (const Vector &v) {
    Vector result;
    for (unsigned int i = 0; i < SIZE; ++i) {
        result[i] = coor[i] -= v[i];
    }
    return result;
}


/** \brief Realizuje mnozenie wektora przez liczbe zmiennoprzecinkowa
 * @param this pierwszy skladnik mnozenia (wektor)
 * @param mul drugi skladnik mnozenia (liczba typu double)
 *  
 * @return Iloczyn dwoch skladnikow przekazanych jako wskaznik na parametr
*/
template< unsigned int SIZE>
Vector< SIZE> Vector< SIZE>::operator * (const double &mul) {
    Vector result;
    for (unsigned int i = 0; i < SIZE; ++i) {
        result[i] = coor[i] *= mul;
    }
    return result;
}


/** \brief Realizuje dzielenie wektora przez liczbe zmiennoprzecinkowa
 * @param this pierwszy skladnik dzielenie (wektor)
 * @param div drugi skladnik dzielenie (liczba typu double)
 *  
 * @return Iloraz dwoch skladnikow przekazanych jako wskaznik na parametr
*/
template< unsigned int SIZE>
Vector< SIZE> Vector< SIZE>::operator / (const double &div) {
    Vector result;

    for (unsigned int i = 0; i < SIZE; ++i) {
        result[i] = coor[i] / div;
    }

    return result;
}



/** \brief Funktor wektora
 * @param index index wektora
 * 
 * @return Wartosc  wektora w danym miejscu tablicy jako stala
*/
template< unsigned int SIZE>
const double &Vector< SIZE>::operator [] (unsigned int index) const {
    if ( index >= SIZE) {
        std::cerr << "Error: Wektor jest poza zasiegiem!" << std::endl;
    }
    return coor[index];
}



/** \brief Funktor wektora
 * @param index index wektora
 * 
 * @return Wartosc  wektora w danym miejscu tablicy
*/
template< unsigned int SIZE>
double &Vector< SIZE>::operator[](unsigned int index) {
    return const_cast<double &>(const_cast<const Vector *>(this)->operator[](index));
}



/** \brief Przeciazenie operatora <<
 * @param out Strumien wyjsciowy
 * @param tmp Wektor 
 * 
*/
template< unsigned int SIZE>
std::ostream &operator << (std::ostream &out, Vector< SIZE> const &tmp) {
    for (unsigned int i = 0; i < SIZE; ++i) {
        out << "[ " << std::fixed << std::setprecision(10) << tmp[i] << " ]\n";
    }
    return out;
}



/** \brief Przeciazenie operatora >>
 * @param in Strumien wejsciowy
 * @param tmp Wektor 
 * 
*/
template< unsigned int SIZE>
std::istream &operator >> (std::istream &in, Vector< SIZE> &tmp) {
    for (unsigned int i = 0; i < SIZE; ++i) {
        in >> tmp[i];
    }
    std::cout << std::endl;
    return in;
}

/** \brief Przeciazenie operatora ==
 * @param v1 Pierwszy skladnik operatora (wektor)
 * @param v2 Drugi skladnik operatora (wektor) 
 * @see Plik size.hh odnosnie epsilon
 * @return zwraca wartosc typu double przekazujaca czy wektory posiadaja te same wartosci
*/
template< unsigned int SIZE>
bool operator ==(const Vector< SIZE> &v1, const Vector< SIZE> &v2)
{
    for(unsigned int i = 0; i < SIZE; ++i) {
        if(fabs(v1[i] - v2[i]) > epsilon)
        {return false;}
    }
    return true;
}

/** \brief Przeciazenie operatora ==
 * @param v1 Pierwszy skladnik operatora (wektor)
 * @param tmp Drugi skladnik operatora (tablica jednowymiarowa typu double) 
 * @see Plik size.hh odnosnie epsilon
 * @return zwraca wartosc typu bool przekazujaca czy wektory i tablica posiadaja te same wartosci
*/
template< unsigned int SIZE>
bool operator ==(const Vector< SIZE> &v1, const double tmp[SIZE])
{
    for(unsigned int i = 0; i < SIZE; ++i) {
        if(fabs(v1[i] - tmp[i]) > epsilon)
        {return false;}
    }
    return true;
}

/** \brief Funkcja obliczajaca dlugosc wektora bedacego roznica dwoch wektorow
 * @param this pierwszy skladnik (wektor)
 * @param v drugi skladnik (wektor) 
 * @return liczba zmiennoprzecinkowa typu double
*/
template<unsigned int SIZE>
double Vector<SIZE>::length(const Vector &v)
{   
    double result = 0;
    Vector<SIZE> v3;
    for(unsigned int i = 0; i < SIZE; ++i)
    {
        v3.coor[i] = std::abs(coor[i] - v.coor[i]);
    }
    for(unsigned int i = 0; i < SIZE; ++i)
    {
        result += (v3.coor[i] * v3.coor[i]);
    }
    return std::sqrt(result);
}
