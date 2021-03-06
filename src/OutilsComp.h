/**
 * \file OutilsComp.h 
 * 
 * 
 * Cette bibliothèque propose des outils de simulation des comportements de départ
 * en retraite. Elle utilise l'information d'un objet de DroitsRetr pour déterminer,
 * selon le comportement choisi, si l'individu choisit de liquider ses droits directs
 * à l'âge testé ou de reporter son départ.
 * Du fait de la possibilité de liquider en deux fois (liquidation d'abord à la FP puis ensuite hors FP), cette 
 * bibliothèque contient deux fonctions de test de liquidation.
 * 
 * La première, \ref TestLiq , teste la première liquidation. 
 * Si les droits ne sont pas intégralement liquidés à la première liquidation, la seconde fonction, \ref TestSecondeLiq ,
 * teste la seconde liquidation.
 * 
 * Contrairement à DroitsRetr, les fonctions de cette bibliothèque sont des
 * outils généraux qui pourraient être utilisés pour simuler des comportements
 * dans des régimes entièrement différents.
 * 
 */



#pragma once
#include "Retraite.h"
class DroitsRetr;

/**
 * \brief Teste si départ en retraite d'un individu à un âge de test donné.
 * 
 * 
 * Teste si départ en retraite de l'individu X, à un âge de test donné, pour des droits  
 * à la retraite DroitsRetr, selon l'option de comportement choisie. 
 * La mise à la reraite est d'office à 70 ans,
 * quelle que soit l'option choisie.
 * 
 * Exemple d'utilisation :
 * =======================
 * 
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *   double agetest = 60+5/12.0;
 *   Leg l = Legislation(X, agetest); 
 *   DroitsRetr dr = new DroitsRetr(X,l,agetest);
 *   if(dr.TestLiq(X,dr,l,agetest)) {
 *       X.retr.liq = *dr;`
 *   } 
 *   else {
 *       delete dr;
 *   }
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  
 */

bool TestLiq(Indiv & X, DroitsRetr & dr, Leg &l, double agetest);



/**
 * \brief Teste si seconde liquidation d'un individu à un âge de test donné.
 * 
 * Identique à \ref TestLiq mais pour la seconde liquidation.
 *  
 */
bool TestSecondLiq(Indiv & X, DroitsRetr & dr, Leg& l, double agetest);



// Destinie 2
// Copyright © 2005-2018, Institut national de la statistique et des études économiques
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.
