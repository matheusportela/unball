/*
    @file Temporizador.cpp

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
#include <Temporizador.h>

Temporizador::Temporizador (double dt)
{
	Dt = 1000 * dt;
	Hora_zero = boost::posix_time::microsec_clock::local_time ();
}
void Temporizador::reset ()
{
	Hora_zero = boost::posix_time::microsec_clock::local_time ();
}
bool Temporizador::zerou ()
{
	boost::posix_time::ptime Hora_atual;
	Hora_atual = boost::posix_time::microsec_clock::local_time ();
	if ((Hora_atual - Hora_zero).total_milliseconds () > Dt)
	{
		return true;
	}
	else
	{
		return false;
	}
}
