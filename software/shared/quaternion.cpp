/*
    @file quaternion.cpp

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
#include "quaternion.h"

Quaternion::Quaternion()
{
}
Vetor3 Quaternion::toEuler()
{
    Vetor3 v;
    v(0) = atan2 (2 * ((*this)(0) * (*this)(1) + (*this)(2) * (*this)(3)), 1 - 2 * ((*this)(1) * (*this)(1) + (*this)(2) * (*this)(2)));
    v(1) = asin (2 * ((*this)(0) * (*this)(2) - (*this)(3) * (*this)(1)));
    v(2) = atan2 (2 * ((*this)(0) * (*this)(3) + (*this)(1) * (*this)(2)), 1 - 2 * ((*this)(2) * (*this)(2) + (*this)(3) * (*this)(3)));
    return v;
}
double Quaternion::operator ()(int ind) const
{
    return this->_dados[ind];
}

double &Quaternion::operator ()(int ind)
{
    return this->_dados[ind];
}
