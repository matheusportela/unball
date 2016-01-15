/*
    @file Temporizador.h

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
/*
	Simula um temporizador simples. O tempo deve estar em segundos. Possui precis�o de 10^-3 segundos.
*/
#ifndef TIMER_H
#define TIMER_H

#include <boost/date_time/posix_time/posix_time.hpp>

class Temporizador
{
public:
	Temporizador () {}
	Temporizador (double);
	void reset ();
	bool zerou ();
private:
	boost::posix_time::ptime Hora_zero;
	double Dt;
};

#endif