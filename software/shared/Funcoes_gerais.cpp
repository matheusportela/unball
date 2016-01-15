/*
    @file Funcoes_gerais.cpp

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
Vetor3 aparar_Vetor3 (const Vetor3 & quina_superior_esquerda, const Vetor3 & quina_inferior_direita, const Vetor3 & v)
{
    Vetor3 r;
    r (0) = aparar_valor (quina_superior_esquerda (0), quina_inferior_direita (0), v (0));
    r (1) = aparar_valor (quina_superior_esquerda (1), quina_inferior_direita (1), v (1));
    r (2) = aparar_valor (quina_superior_esquerda (2), quina_inferior_direita (2), v (2));
    return r;
}
double aparar_valor (double inicio, double fim, double valor)
{
    double min, max;
    min = inicio < fim ? inicio : fim;
    max = fim > inicio ? fim : inicio;
    if (valor < min)
    {
        return min;
    }
    else
    {
        if (valor > max)
        {
            return max;
        }
        else
        {
            return valor;
        }
    }
}
double restringe_0_2PI (double valor)
{
    int i_n;
    double f_resto;
    i_n = (int) fabs (valor) / (2. * M_PI);
    f_resto = fabs (valor) - i_n * 2. * M_PI;
    if (valor > 0)
    {
        return f_resto;
    }
    else
    {
        return 2. * M_PI - f_resto;
    }
}
double para_rad (double a)
{
    return ((2. * M_PI) / 360.) * a;
}
double para_graus (double a)
{
    return (360. / (2. * M_PI)) * a;
}
