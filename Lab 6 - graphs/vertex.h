#pragma once
 
class Vertex {
public:
		int index;
        int kolor;
        int* sasiedzi;
		int c;
        int ilosc_sasiadow;
        Vertex() : kolor(-1) {};
};
 