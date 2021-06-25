#pragma once
/** \file 
 * \brief Szablon klasy matrix 
 * Plik zawiera odpowiednie metody szablonu klasy matrix
*/
#include "size.hh"
#include "vector.hh"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

template< unsigned int SIZE>
class Matrix {

private:
    double value[SIZE][SIZE];               // Wartosci macierzy

public:
    Matrix(double [SIZE][SIZE]);            // Konstruktor klasy

    Matrix();                               // Konstruktor klasy

    Matrix(double degr);

    Matrix(char axis, double degr);

    Vector<SIZE> operator * (const Vector<SIZE> tmp);           // Operator mnożenia przez wektor

    Matrix operator + (const Matrix tmp);

    Matrix operator *(const Matrix tmp);

    double  &operator () (unsigned int row, unsigned int column);
    
    const double &operator () (unsigned int row, unsigned int column) const;
};




/** \brief Konstruktor bezparametryczny klasy Matrix  
 *  @return Zwraca macierz wypelniona wartioscia 0
*/
template< unsigned int SIZE>
Matrix< SIZE>::Matrix() {
    for (unsigned int i = 0; i < SIZE; ++i) {
        for (unsigned int j = 0; j < SIZE; ++j) {
            value[i][j] = 0;
        }
    }
}



/** \brief Konstruktor parametryczny klasy Matrix
 *  @param tmp Tablica dwuwymiarowa z elementami typu double
 *  @return Zwraca macierz wypelniona wartioscia podanymi w argumencie
*/
template< unsigned int SIZE>
Matrix< SIZE>::Matrix(double tmp[SIZE][SIZE]) {
    for (unsigned int i = 0; i < SIZE; ++i) {
        for (unsigned int j = 0; j < SIZE; ++j) {
            value[i][j] = tmp[i][j];
        }
    }
}

/** \brief Konstruktor parametryczny klasy Matrix  
 *  @param degr Wartosc typu double (kat podany w stopniach)
 *  @return Zwraca macierz 2x2 obrotu wypelniona wartosciami odpowiednimi dla danego kata
*/
template< unsigned int SIZE>
Matrix< SIZE>::Matrix(double degr)
{   
    if(SIZE != 2)
    { std::cerr << "ERROR: Uzyto nielasciwego konstruktora macierzy obrotu. Wymiary macierzy nie odpowiadaja temu konstruktorowi"; exit(0);}
    value[0][0]= cos(degr*PID); value[0][1]= -sin(degr*PID);
    value[1][0]= sin(degr*PID); value[1][1]= cos(degr*PID);
}

/** \brief Konstruktor parametryczny klasy Matrix  
 *  @param axis Wartosc typu char (znak symbolizujacy os obrotu macierzy)
 *  @param degr Wartosc typu double (kat podany w stopniach)
 *  @return Zwraca macierz 3x3 obrotu wypelniona wartosciami odpowiednimi dla danej osi obrotu i kata
*/
template< unsigned int SIZE>
Matrix< SIZE>::Matrix(char axis, double degr)
{   
    if(SIZE != 3)
    {std::cerr << "ERROR: Uzyto nielasciwego konstruktora macierzy obrotu. Wymiary macierzy nie odpowiadaja temu konstruktorowi"; exit(0);}
    switch (axis)
    {
    case 'x':
        value[0][0] = 1; value[0][1] = 0;             value[0][2] = 0;
        value[1][0] = 0; value[1][1] = cos(degr*PID); value[1][2] = -sin(degr*PID);
        value[2][0] = 0; value[2][1] = sin(degr*PID); value[2][2] = cos(degr*PID);
        break;
    case 'y':
        value[0][0] = cos(degr*PID);  value[0][1] = 0;  value[0][2] = sin(degr*PID);
        value[1][0] = 0;              value[1][1] = 1;  value[1][2] = 0;
        value[2][0] = -sin(degr*PID); value[2][1] = 0;  value[2][2] = cos(degr*PID);
        break;
    case 'z':
        value[0][0] = cos(degr*PID); value[0][1] = -sin(degr*PID); value[0][2] = 0;
        value[1][0] = sin(degr*PID); value[1][1] = cos(degr*PID);  value[1][2] = 0;
        value[2][0] = 0;             value[2][1] = 0;              value[2][2] = 1;
        break;
    default:
    std::cerr << "ERROR: Podano niepoprawny znak"; exit(0);
        break;
    }
}



/** \brief Realizuje mnozenie macierzy przez wektor 
 * @param this Pierwszy skladnik mnozenia (macierz)
 * @param tmp drugi skladnik mnozenia (wektor)
 * @return Iloczyn dwoch skladnikow przekazany jako wektor
*/
template< unsigned int SIZE>
Vector<SIZE> Matrix< SIZE>::operator * (const Vector< SIZE> tmp) {
    Vector<SIZE> result;
    for (unsigned int i = 0; i < SIZE; ++i) {
        for (unsigned int j = 0; j < SIZE; ++j) {
            result[i] += value[i][j] * tmp[j];
        }
    }
    return result;
}



/** \brief Funktor macierz 
 * @param row numer wiersza
 * @param column numer kolumny
 * @return Wartosc macierzy w danym miejscu tablicy
*/
template< unsigned int SIZE>
double &Matrix<SIZE>::operator()(unsigned int row, unsigned int column) {

    if (row >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem"; 
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return value[row][column];
}



/** \brief Funktor macierz 
 * @param row numer wiersza
 * @param column numer kolumny
 * @return Wartosc macierzy w danym miejscu tablicy jako stala
*/
template< unsigned int SIZE>
const double &Matrix<SIZE>::operator () (unsigned int row, unsigned int column) const {

    if (row >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return value[row][column];
}


/** \brief Realizuje dodawanie dwoch macierzy
 * @param this Skladnik pierwszy (macierz)
 * @param tmp Skladnik drugi (macierz)
 * @return Suma dwoch skladnikow przekazana jako macierz
*/
template< unsigned int SIZE>
Matrix<SIZE> Matrix< SIZE>::operator + (const Matrix tmp) {
    Matrix result;
    for (unsigned int i = 0; i < SIZE; ++i) {
        for (unsigned int j = 0; j < SIZE; ++j) {
            result(i, j) = this->value[i][j] + tmp(i, j);
        }
    }
    return result;
}

/** \brief Realizuje iloczyn dwoch macierzy
 * @param this Skladnik pierwszy (macierz)
 * @param tmp Skladnik drugi (macierz)
 * @return Iloczyn dwoch skladnikow przekazana jako macierz
*/
template< unsigned int SIZE>
Matrix< SIZE> Matrix< SIZE>::operator *( const Matrix tmp)
{  
    Matrix result;
    for(unsigned int i = 0; i < SIZE; ++i){
        for(unsigned int j = 0; j < SIZE; ++j){
            for(unsigned int k = 0; k < SIZE; ++k){
                result.value[i][j] += this->value[i][k] * tmp.value[k][j]; 
            }
        }
    }
    return result;
}


/** \brief Przeciazenie operatora >> 
 * @param in Strumien wyjsciowy
 * @param mat macierz
*/
template< unsigned int SIZE>
std::istream &operator>>(std::istream &in, Matrix<SIZE> &mat) {
    for (unsigned int i = 0; i < SIZE; ++i) {
        for (unsigned int j = 0; j < SIZE; ++j) {
            in >> mat(i, j);
        }
    }
    return in;
}



/** \brief Przeciazenie operatora <<
 * @param out Strumien wejsciowy
 * @param mat macierz
*/
template< unsigned int SIZE>
std::ostream &operator<<(std::ostream &out, const Matrix<SIZE> &mat) {
    for (unsigned int i = 0; i < SIZE; ++i) {
        for (unsigned int j = 0; j < SIZE; ++j) {
            out << "| " << std::fixed << std::setprecision(10) << mat(i, j) << " | "; //warto ustalic szerokosc wyswietlania dokladnosci liczb
        }
        std::cout << std::endl;
    }
    return out;
}

/** \brief przeciazenie operatora == 
 * @param m1 pierwszy skladnik (macierz)
 * @param m2 drugi skladnik (macierz)
 * @return wartosc typu bool przekazujaca czy macierze posiadaja takie same elementy
*/
template< unsigned int SIZE>
bool operator ==(const Matrix< SIZE> &m1, const Matrix< SIZE> &m2)
{   
    for(unsigned int i = 0; i < SIZE; i++)
    {
        for(unsigned int j = 0; j < SIZE; j++)
        {
            if(m1(i, j) - m2(i, j) > epsilon){return false;}
        }
    }
    return true;
}


/** \brief przeciazenie operatora == 
 * @param m1 pierwszy skladnik (macierz)
 * @param m2 drugi skladnik (dwuwymiarowa tablica z elementami typu double)
 * @return wartosc typu bool przekazujaca czy macierz i tablica posiadaja takie same elementy
*/
template< unsigned int SIZE>
bool operator ==(const Matrix< SIZE> &m1, const double m2[SIZE][SIZE])
{
    for(unsigned int i = 0; i < SIZE; i++)
    {
        for(unsigned int j = 0; j < SIZE; j++)
        {
            if(m1(i, j) - m2[i][j] > epsilon){return false;}
        }
    }
    return true;
}

