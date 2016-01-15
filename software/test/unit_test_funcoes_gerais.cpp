/*
    @file unit_test_funcoes_gerais.cpp

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
#include <Funcoes_gerais.h>
#define _USE_MATH_DEFINES
#include <math.h>
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
BOOST_AUTO_TEST_SUITE (unit_test_compartilhado)
BOOST_AUTO_TEST_CASE (unit_test_Funcoes_gerais)
{
	BOOST_CHECK (aparar_valor (1, 2, 5) == 2);
	BOOST_CHECK (aparar_valor (1, 2, 1.5) == 1.5);
	BOOST_CHECK (aparar_valor (1, 2, 0) == 1);
	BOOST_CHECK_CLOSE (restringe_0_2PI (M_PI), M_PI, 0.00001);
	BOOST_CHECK_CLOSE (restringe_0_2PI (3 * M_PI), M_PI, 0.00001);
	BOOST_CHECK_CLOSE (restringe_0_2PI (-M_PI), M_PI, 0.00001);
	BOOST_CHECK_CLOSE (restringe_0_2PI (-3 * M_PI), M_PI, 0.00001);
	BOOST_CHECK_CLOSE (para_graus (2 * M_PI), 360., 0.00001);
	BOOST_CHECK_CLOSE (para_graus (M_PI), 180., 0.00001);
	BOOST_CHECK_CLOSE (para_rad (360), 2 * M_PI, 0.00001);
	BOOST_CHECK_CLOSE (para_rad (180), M_PI, 0.00001);
}
BOOST_AUTO_TEST_SUITE_END ()