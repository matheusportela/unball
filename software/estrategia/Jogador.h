/*
    @file Jogador.h

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
#ifndef JOGADOR_H
#define JOGADOR_H

#include <Estados_jogador.h>
#include <Robo.h>
#include <Regioes.h>
#include <Vetor.h>

class Jogador;
class Equipe;
class Campo;

class Jogador : public Robo
{
public:
	Jogador ();
	~Jogador ();
	//-- Inicializa��o
	void Init (Equipe * e);
	//-- Execu��o da rotina.
	void roda ();

	//-- Acesso �s vari�veis.
	Regiao regiao_base ();
	Campo * campo ();
	Equipe * equipe ();
	enum_Estado estado_atual ();
	enum_Estado estado_anterior ();

	//-- Modifica��o das vari�veis.
	void setRegiao_base (Regiao r);
	void setEquipe (Equipe * e);
	void troca_estado (enum_Estado);
	void troca_regiao_base (Regiao);

	// Perguntas do tipo o que.
	Vetor3 normal_parede_proxima ();

	// perguntas do tipo sim/n�o.
	bool dentro_campo_visao (Vetor3 alvo);
	bool estou_em (Vetor3 v);
	bool perto_demais_parede ();
	bool controla_bola ();
	bool pode_passar ();
	bool pode_chutar_gol ();

	// controle
	bool alinha (Vetor3 v);
	bool olhe_para (Vetor3 v);
	bool espera ();
	bool mover_ate (Vetor3 v);

	

private:
	bool seguir_caminho;
	Equipe * e_Equipe;
	Campo * c_campo;

	Regiao r_base;

	const static int num_estados = 10;
	Estado * e_estado[num_estados];
	enum_Estado _estado_atual;
	enum_Estado _estado_anterior;
};

#endif // !JOGADOR_H
