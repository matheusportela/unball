/*
    @file Robo.h

    @autor William Batista Aguiar Motta
    @email yosoyninja@gmail.com

    @attention Copyright (C) 2013
    @attention UnBall Robot Soccer Team

       Este programa � um software livre; voc� pode redistribui-lo e/ou
    modifica-lo dentro dos termos da Licen�a P�blica Geral GNU como
    publicada pela Funda��o do Software Livre (FSF); na vers�o 2 da
    Licen�a, ou (na sua opni�o) qualquer vers�o.

    Este programa � distribuido na esperan�a que possa ser  util,
    mas SEM NENHUMA GARANTIA; sem uma garantia implicita de ADEQUA��O a qualquer
    MERCADO ou APLICA��O EM PARTICULAR. Veja a
    Licen�a P�blica Geral GNU para maiores detalhes.

    Voc� deve ter recebido uma c�pia da Licen�a P�blica Geral GNU
    junto com este programa, se n�o, escreva para a Funda��o do Software
    Livre(FSF) Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

*/
#ifndef ROBO_H
#define ROBO_H

#include <Objetos.h>
#include <Funcoes_gerais.h>
const double MAX_W = 15;
const double MIN_W = 1;
const double MAX_V = 15;
const double MIN_V = 1;

class Robo : public Objeto {
public:
	Robo();
	~Robo() {}
	void aplica_forca (Vetor3 forca);
	void forca_para_vel_rodas();
	void vel_linear_angular_para_vel_rodas();
	void vel_rodas_para_vel_linear_angular();
	void zerar_forcas();
	double vel_roda_dir;
	double vel_roda_esq;
};
#endif
