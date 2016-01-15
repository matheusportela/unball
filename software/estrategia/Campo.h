/*
    @file Campo.h

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
#ifndef CAMPO_H
#define CAMPO_H

#include <Objetos.h>

class Gol;
class Jogador;
class Equipe;
class Campo;

class Gol : public Objeto
{
public:
	Gol ();
	Gol (Vetor3 v_dir, Vetor3 v_esq);
	double largura ();
	double comprimento ();
	Vetor3 poste_dir ();
	Vetor3 poste_esq ();
private:
	double _largura, _comprimento;
	Vetor3 v_dir, v_esq;
	Vetor3 v_meio;
};

class Campo
{
public:
	Campo ();
	~Campo ();

	//-- Fun��es de acesso
	double largura ();
	double comprimento ();
	Objeto * bola ();
	Gol * g_roxo ();
	Gol * g_verde ();
	Equipe * e_roxo ();
	Equipe * e_verde ();
	Jogador ** jogador ();
	Objeto * parede ();

private:
	Objeto o_parede[4];
	Gol g_Roxo;
	Gol g_Verde;
	Objeto * o_Bola;
	Equipe * e_Roxo;
	Equipe * e_Verde;
	Jogador * j_jogador[6];
	double f_largura, f_comprimento;
};

#endif // !CAMPO_H
