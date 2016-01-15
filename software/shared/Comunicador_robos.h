/*
    @file Comunicador_robos.h

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
#ifndef PC_ROBO_H
#define PC_ROBO_H

#include <Dados.h>
#include <boost/asio.hpp>
#include <Funcoes_gerais.h>

enum _dir {frente, traz};
enum _roda {esquerda, direita};

class Comunicador_robos {
public:
	Comunicador_robos(std::string porta);
	~Comunicador_robos();
	void enviar_velocidades (Dados_Estrategia & _dados);
private:
	unsigned int roda (unsigned int i);
	unsigned int robo (unsigned int i);
	unsigned int direcao (unsigned int i);
	unsigned int velocidade (unsigned int i);
	unsigned char ler_velocidade (Dados_Estrategia & _dados, unsigned int _robo, unsigned int _roda);

	std::string port;
	int baud_rate;
	boost::asio::io_service io;
	boost::asio::basic_serial_port<boost::asio::serial_port_service> serial;
};

#endif

