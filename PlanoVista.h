#ifndef UNTITLED_PLANOVISTA_H
#define UNTITLED_PLANOVISTA_H

#include "Vector3D.h"

class PlanoVista {
public:
    int		hres;			// resolucao horizontal da imagem
    int		vres;			// resolucao vertical da imagem
    float	tamPixel;		// s: tamanho do pixel
    int		numMuestras;	// numero de muestras por pixel
    int		maxProfundidade; // numero maximo de profundidad no raio reflexado

    float	gamma;			// factor de correccion gamma
    float	invGamma;

    // Para vista proyectiva
    // Posicion del Ojo
    Vector3D	ojo;
    // Distancia del ojo
    float	dist;

    //Zoom final
    float		zoom;

    PlanoVista();
    //PlanoVista(const PlanoVista &pv);

    //PlanoVista& operator=(PlanoVista &pv);

    void	setHres(int h_res) { hres = h_res; }
    void	setVres(int v_res) { vres = v_res; }
    void	setTamPixel(float tam) { tamPixel = tam; }
    void	setGamma(float g);
    void	setNumMuestras(int n) {	numMuestras = n; }
    void	setZoom(float z) { zoom = z; }
    void	setMaxProfundidade(int mp) { maxProfundidade = mp; }
};


#endif //UNTITLED_PLANOVISTA_H
