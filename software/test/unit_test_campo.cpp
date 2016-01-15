/*
    @file unit_test_campo.cpp

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
#include <Campo.h>
#include <Config.h>
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE (unit_test_estrategia)
BOOST_AUTO_TEST_CASE (unit_test_Campo)
{
	ProcessLogger::setPrintLevel (LEVEL_ERROR);
	Config config ("constants.config");
	//-- Checando inicializa��o do gol.
	Gol gol (v3_X (), -1 * v3_X ());
	BOOST_CHECK (gol.poste_dir () == v3_X ());
	BOOST_CHECK (gol.poste_esq () == -1 * v3_X ());
	BOOST_CHECK (gol.v_normal == v3_Y ());
	//-- Checando inicializa��o do campo.
	Campo campo;
	BOOST_CHECK_CLOSE (campo.largura (), atof (config.get ("FIELD_WIDTH").c_str ()), 0.000001);
	BOOST_CHECK_CLOSE (campo.comprimento (), atof (config.get ("FIELD_LENGTH").c_str ()), 0.000001);
	BOOST_CHECK (campo.bola () != 0);
	BOOST_CHECK (campo.e_roxo () != 0);
	BOOST_CHECK (campo.e_verde () != 0);
	BOOST_CHECK (campo.g_verde () != 0);
	BOOST_CHECK (campo.g_roxo () != 0);
	// Checar demais propriedades com auxilio do autocad.
	/*
	Objeto parede[4];
	*/
}
BOOST_AUTO_TEST_SUITE_END ()