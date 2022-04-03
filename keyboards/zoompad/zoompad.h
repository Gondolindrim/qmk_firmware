/* Copyright 2020 Gondolindrim
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once
#include "quantum.h"
#define ___ KC_NO

#define LAYOUT_all( \
    K10, K11, K02, K03 , \
    K24, K25, K26, K27 , \
    K34, K35, K36, K37 , \
    K44, K45, K46, K47 , \
    K54, K55, K56, K57 , \
    K64, K65, K66, K67   \
)\
{\
    { ___, ___, K02, K03, ___, ___, ___, ___ }, \
    { K10, K11, ___, ___, ___, ___, ___, ___ }, \
    { ___, ___, ___, ___, K24, K25, K26, K27 }, \
    { ___, ___, ___, ___, K34, K35, K36, K37 }, \
    { ___, ___, ___, ___, K44, K45, K46, K47 }, \
    { ___, ___, ___, ___, K54, K55, K56, K57 }, \
    { ___, ___, ___, ___, K64, K65, K66, K67 }  \
}
