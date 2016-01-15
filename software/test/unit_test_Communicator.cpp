/*
    @file unit_test_Communicator.cpp

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
#define BOOST_TEST_DYN_LINK

#include <Communicator.h>
#include <ProcessLogger.h>

#include <boost/test/unit_test.hpp>
BOOST_AUTO_TEST_SUITE (unit_test_shared)
BOOST_AUTO_TEST_CASE(CommunicatorInOrder)
{
	using namespace std;    

	Communicator* com_read;
	Communicator* com_write;
	bool can_write = false;

	// ProcessLogger::setPrintLevel (LEVEL_VERBOSE);
	// LOG_INIT2("unit_test_Communicator_log",LEVEL_VERBOSE,LEVEL_DEBUG);

	com_write = new Communicator(string("Program2"),string("Program3"),WRITE, true);
	com_read = new Communicator(string("Program2"),string("Program3"),READ);

    LOG(LEVEL_INFO) << "Lets test if we have the permission to write in the shared memory";
    BOOST_CHECK_EQUAL(com_write->getMode(),true);
    LOG(LEVEL_INFO) << "Ok, we may write in the shared memory";
    
    LOG(LEVEL_INFO) << "Lets test if we have the permission to read from the shared memory";
    BOOST_CHECK_EQUAL(com_read->getMode(),false);
    LOG(LEVEL_INFO) << "Ok, we may read from the shared memory";
    
    LOG(LEVEL_INFO) << "Now I must see if i know between which programs I must exchange messages";
    BOOST_CHECK_EQUAL(com_write->name(),"Program2->Program3");    
    BOOST_CHECK_EQUAL(com_read->name(),"Program2->Program3");    
    LOG(LEVEL_INFO) << "Good! I understand what people tell me to do!";
    
    LOG(LEVEL_INFO) << "I understand the commands given. Lets see if I know how to execute them";
    string shared_x("1");
    string shared_y("2");
    BOOST_CHECK_EQUAL(com_write->ready(),true);
    BOOST_CHECK_EQUAL(com_read->ready(),false);
    LOG(LEVEL_INFO) << "Great, I am ready to write and read!";
    
    if(com_write->ready())
    {
        //com_write->create("shared_x");
        //com_write->create("shared_y");

        //(*com_write) << OUT("shared_x",shared_x);
        //(*com_write) << OUT("shared_y",shared_y);
        //com_write->done();
    }

    //BOOST_CHECK_EQUAL(,);
}
BOOST_AUTO_TEST_SUITE_END ()
    
    
