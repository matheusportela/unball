/*
    @file gameboard.h

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

#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include <Funcoes_gerais.h>
#include <Comunicador_robos.h>
#include <Comunicador.h>
#include <Dados.h>
#include <QPlainTextEdit>
#include <QWidget>
#include <QLabel>
#include <QRadioButton>
#include <QCheckBox>
#include <QVBoxLayout>

class QLCDNumber;
class QGroupBox;
class QPushButton;
class SoccerField;

class GameBoard : public QWidget
{
    Q_OBJECT

public:
    GameBoard(QWidget *parent = 0);
    ~GameBoard();

    int goal;
    QPlainTextEdit *plainText;
    QFile *wfile;
    QString modificado;

protected slots:
    void newGame();
    void endGame();
    void stopped();
    void next();
    void continueGame();
    void writing();
    void reading();
    void timer();
    void modoSimulador();
    void modoArquivo();
    void savePos();
    void loadPosition();
    void configura();
    void Menu();
    void Settings();
    void change();
    void salvar();
    void getGoals();

    // novos
public slots:
    void run();
    void play(bool);
    void reset();
    void controlador_estrategia();
    void controlador_nenhum();
    void fonte_dados_visao();
    void fonte_dados_simulacao();
    void fonte_dados_manual();
    void destino_dados_estrategia(bool);
    void destino_dados_arquivo(bool);
    void destino_dados_robos(bool);
    void salvar_posicoes();
    void carregar_posicoes();
    void desempacotar_dados(Dados_Simulador& dados);
    void empacotar_dados (Dados_Simulador& dados);

private:
    QPushButton * createButton(char str[50], char icn[50], char n);
    QLCDNumber * createLCD();
    QLCDNumber *time1;
    QLCDNumber *time2;
    QLCDNumber *timerSeg;
    QLCDNumber *timerMin;
    QPushButton *quit;
    QGroupBox *groupBox;
    SoccerField *soccerField;
    QTimer *updateTimer;
    int releasedbutton;

    // estados
    bool _play;
    enum Controlador { estrategia, nenhum};
    enum Fonte_dados { visao, simulador, manual};
    Controlador _controlador;
    Fonte_dados _fonte_dados;
    bool _destino_dados_estrategia;
    bool _destino_dados_arquivo;
    bool _destino_dados_robos;

    // novos botoes
    QPushButton* push_play;

    QPushButton* push_reset;
    QPushButton* push_salvar_posicoes;
    QPushButton* push_carregar_posicoes;

    QLabel* texto_controlador;
    QLabel* texto_fonte_dados;
    QLabel* texto_destino_dados;

    QRadioButton* radio_controle_estrategia;
    QRadioButton* radio_controle_nenhum;
    QRadioButton* radio_fonte_visao;
    QRadioButton* radio_fonte_simulador;
    QRadioButton* radio_fonte_manual;

    QCheckBox* check_destino_robos;
    QCheckBox* check_destino_arquivo;
    QCheckBox* check_destino_estrategia;

    QVBoxLayout* caixa_controladores;
    QVBoxLayout* caixa_destino_dados;
    QVBoxLayout* caixa_fonte_dados;
    QVBoxLayout* caixa_estados;
    QVBoxLayout* caixa_salvamento;

    QButtonGroup* grupo_controlador;
    QButtonGroup* grupo_fonte_dados;

    Comunicador* com_visao;
    Comunicador* com_simulador;
    Comunicador* com_estrategia;
    Comunicador_robos* com_robos;
};

#endif
