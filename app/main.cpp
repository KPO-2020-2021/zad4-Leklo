// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <string>

#include "exampleConfig.h"
#include "example.h"
#include "vector3D.hh"
#include "matrix3x3.hh"
#include "cuboid.hh"
#include "../inc/lacze_do_gnuplota.hh"


void zapiswspldostru(std::ostream& out, Cuboid C)
{
       out << std::setw(16) << std::fixed << std::setprecision(10) << C[0][0]<< std::setw(16) << C[0][1] << std::setw(16) << C[0][2] << std::endl;
       out << std::setw(16) << std::fixed << std::setprecision(10) << C[1][0]<< std::setw(16) << C[1][1] << std::setw(16) << C[1][2] << std::endl;
       out << std::setw(16) << std::fixed << std::setprecision(10) << C[2][0]<< std::setw(16) << C[2][1] << std::setw(16) << C[2][2] << std::endl;
       out << std::setw(16) << std::fixed << std::setprecision(10) << C[3][0]<< std::setw(16) << C[3][1] << std::setw(16) << C[3][2] << std::endl;
       out << std::setw(16) << std::fixed << std::setprecision(10) << C[0][0]<< std::setw(16) << C[0][1] << std::setw(16) << C[0][2] << std::endl;

       out << std::setw(16) << std::fixed << std::setprecision(10) << C[4][0]<< std::setw(16) << C[4][1] << std::setw(16) << C[4][2] << std::endl;
       out << std::setw(16) << std::fixed << std::setprecision(10) << C[5][0]<< std::setw(16) << C[5][1] << std::setw(16) << C[5][2] << std::endl;
       out << std::setw(16) << std::fixed << std::setprecision(10) << C[1][0]<< std::setw(16) << C[1][1] << std::setw(16) << C[1][2] << std::endl;
       out << std::setw(16) << std::fixed << std::setprecision(10) << C[5][0]<< std::setw(16) << C[5][1] << std::setw(16) << C[5][2] << std::endl;

       out << std::setw(16) << std::fixed << std::setprecision(10) << C[6][0]<< std::setw(16) << C[6][1] << std::setw(16) << C[6][2] << std::endl;
       out << std::setw(16) << std::fixed << std::setprecision(10) << C[2][0]<< std::setw(16) << C[2][1] << std::setw(16) << C[2][2] << std::endl;
       out << std::setw(16) << std::fixed << std::setprecision(10) << C[6][0]<< std::setw(16) << C[6][1] << std::setw(16) << C[6][2] << std::endl;
       out << std::setw(16) << std::fixed << std::setprecision(10) << C[7][0]<< std::setw(16) << C[7][1] << std::setw(16) << C[7][2] << std::endl;

       out << std::setw(16) << std::fixed << std::setprecision(10) << C[3][0]<< std::setw(16) << C[3][1] << std::setw(16) << C[3][2] << std::endl;
       out << std::setw(16) << std::fixed << std::setprecision(10) << C[7][0]<< std::setw(16) << C[7][1] << std::setw(16) << C[7][2] << std::endl;
       out << std::setw(16) << std::fixed << std::setprecision(10) << C[4][0]<< std::setw(16) << C[4][1] << std::setw(16) << C[4][2] << std::endl;
}

bool ZapisWspolrzednychDoPliku( const char  *sNazwaPliku, Cuboid C)
{
  std::ofstream  StrmPlikowy;

  StrmPlikowy.open(sNazwaPliku);
  if (!StrmPlikowy.is_open())  {
    std::cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << std::endl
	 << ":(  nie powiodla sie." << std::endl;
    return false;
  }

  zapiswspldostru(StrmPlikowy, C);

  StrmPlikowy.close();
  return !StrmPlikowy.fail();
}

int main() {
  std::cout << "Project Rotation 3D based on C++ Boiler Plate v"
            << PROJECT_VERSION_MAJOR /*duże zmiany, najczęściej brak kompatybilności wstecz */
            << "."
            << PROJECT_VERSION_MINOR /* istotne zmiany */
            << "."
            << PROJECT_VERSION_PATCH /* naprawianie bugów */
            << "."
            << PROJECT_VERSION_TWEAK /* zmiany estetyczne itd. */
            << std::endl;
  // std::system("cat ../LICENSE");
  // do zadania Rotacja 2D
  
double a1[3] {20.0, 100.0, 30.0};double a2[3] {20.0, 160.0, 30.0};
double a3[3] {140.0, 160.0, 30.0};double a4[3] {140.0, 100.0, 30.0};
double a5[3] {20.0, 100, 110};double a6[3] {20, 160, 110};
double a7[3] {140, 160, 110};double a8[3] {140, 100, 110};
Vector3D arr[8]; Matrix3x3 M;
  Vector3D v1(a1); Vector3D v2(a2); Vector3D v3(a3); Vector3D v4(a4);
  Vector3D v5(a5); Vector3D v6(a6); Vector3D v7(a7); Vector3D v8(a8);
  arr[0] = v1; arr[1] = v2; arr[2] = v3; arr[3] = v4; arr[4] = v5;
  arr[5] = v6; arr[6] = v7; arr[7] = v8;
  Cuboid C(arr);
    PzG::LaczeDoGNUPlota  Lacze;  // Ta zmienna jest potrzebna do wizualizacji
                                // rysunku prostokata

   //-------------------------------------------------------
   //  Wspolrzedne wierzcholkow beda zapisywane w pliku "prostokat.dat"
   //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
   //  na dwa sposoby:
   //   1. Rysowane jako linia ciagl o grubosci 2 piksele
   //
  Lacze.DodajNazwePliku("../datasets/prostokat.dat",PzG::RR_Ciagly,2);
   //
   //   2. Rysowane jako zbior punktow reprezentowanych przez kwadraty,
   //      których połowa długości boku wynosi 2.
   //
  Lacze.DodajNazwePliku("../datasets/prostokat.dat",PzG::RR_Punktowy,3);

  Lacze.ZmienTrybRys(PzG::TR_3D);

if(!ZapisWspolrzednychDoPliku("../datasets/prostokat.dat", C)) return 1;
  Lacze.Rysuj();
  std::cout << "Nacisnij ENTER aby kontynuowac" << std::endl;
  std::cin.ignore(10000, '\n');

std::cout << "o - obrot prostokata o zadany kat" << std::endl;
std::cout << "t - powtorzenie poprzedniego obrotu" << std::endl;
std::cout << "r - wyswietlenie macierzy rotacji" << std::endl;
std::cout << "p - przesuniecie prostokata o zadany wektor" << std::endl;
std::cout << "w - wyswietlenie wspolrzednych wierzcholkow" << std::endl;
std::cout << "s - sprawdzenie dlugosci przeciwleglych bokow" << std::endl;
std::cout << "m - wyswietl menu" << std::endl;
std::cout << "k - koniec dzialania programu" << std::endl;
  do
  {
    char op;
    std::cin >> op;
    switch (op)
    {
    case 'o':{
      std::cout << "Twoj wybor? (m - menu) > o" << std::endl;
       double degrarr[100]; char axis; double degr; std::string str;
      std::cout << "Podaj sekwencje oznaczen osi oraz katy obrotu w stopniach" << std::endl;
      long unsigned int repetition = 0;do
      {      
             
             std::cin >> axis;
             if(axis == '.'){break;}
             std::cin >> degrarr[repetition];
             if(axis != 'x' && axis != 'y' && axis != 'z')
             {
                    std::cout << "Bledne oznaczenie osi. Dopuszczalne znaki to: x y z .\n Sprobuj jeszcze raz." << std::endl;
                    std::cin >> axis; std::cin >> degrarr[repetition];
             }
             str += axis;
      }while(axis != '.');
      std::cout << std::endl << "Ile razy operacja obrotu ma byc powtorzona?" << std::endl;
      int re;
      std::cin >> re; std::cout << std::endl;
      for(int j = 0; j < re; ++j)
      {      
            for(long unsigned int i = 0; i < str.length(); ++i)
            { 
            axis = str[i]; degr = degrarr[i];
            Matrix3x3 m(axis, degr);
            M = m;
            C = C.rotation(M);
            }
      }
      
      C.sides();

      if(!ZapisWspolrzednychDoPliku("../datasets/prostokat.dat", C)) return 1;
      Lacze.Rysuj();
      std::cout << "Nacisnij ENTER aby kontynuowac" << std::endl;
      std::cin.ignore(10000, '\n');
      break;}
    case 't':{
            std::cout << "Twoj wybor? (r - menu) > r" << std::endl;
            C = C.rotation(M);
            if(!ZapisWspolrzednychDoPliku("../datasets/prostokat.dat", C)) return 1;
            Lacze.Rysuj();
            std::cout << "Nacisnij ENTER aby kontynuowac" << std::endl;
            std::cin.ignore(10000, '\n');

      break;}
    case 'r':{
           std::cout << "Twoj wybor? (r - menu) > r" << std::endl;
           std::cout << M;
      break;}
    case 'p':{
      std::cout << "Twoj wybor? (m - menu) > p" << std::endl 
      << "Wprowadz wspolrzedne wektora translacji w postaci dwoch liczb tzn. wspolrzednej x, y oraz z." << std::endl;
      double tmp[3];
      std::cin >> tmp[0]; std::cin >> tmp[1]; std::cin >> tmp[2]; std::cout << std::endl;
      Vector3D V(tmp);
      C = C.translation( V);
      if(!ZapisWspolrzednychDoPliku("../datasets/prostokat.dat", C)) return 1;
      Lacze.Rysuj();
      std::cout << "Nacisnij ENTER aby kontynuowac" << std::endl;
      std::cin.ignore(10000, '\n');
      break;}
    case 'w':{
      std::cout << "Twoj wybor? (m - menu) > w" << std::endl;
      std::cout << C;
      break;}
    case 's':{
           C.sides();
      break;}
    case 'm':{
       std::cout << "o - obrot prostokata o zadany kat" << std::endl;
       std::cout << "t - powtorzenie poprzedniego obrotu" << std::endl;
       std::cout << "r - wyswietlenie macierzy rotacji" << std::endl;
       std::cout << "p - przesuniecie prostokata o zadany wektor" << std::endl;
       std::cout << "w - wyswietlenie wspolrzednych wierzcholkow" << std::endl;
       std::cout << "s - sprawdzenie dlugosci przeciwleglych bokow" << std::endl;
       std::cout << "m - wyswietl menu" << std::endl;
       std::cout << "k - koniec dzialania programu" << std::endl;
      break;}
    case 'k':{
      return 0;
      break;}
    default:{
      break;}
    }
  }while(1);
}

