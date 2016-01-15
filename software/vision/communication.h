/*
    @file communication.h

	@autor			Andr� Luiz Siega Nepomuceno		@email andrelsn@live.com
    @contributor	William Batista Aguiar Motta	@email yosoyninja@gmail.com

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

#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include "tracker.h"
//#include "Communicator.h"
#include <Comunicador.h>
#include <Dados.h>
#include "output_data.h"

class Communication
{
public:
    Communication();
    ~Communication();

    void Send(OutputData& data);
protected:
private:
    void Init();
    //Communicator* com_write;
    Comunicador* _com_write;
};

#endif // COMMUNICATION_H
