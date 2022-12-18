/*
Copyright 2022 Gondolindrim <gondolindrim@acheronproject.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "quantum.h"

#define ___ KC_NO

#define LAYOUT( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E, K0F, K0G, K0H, K0I, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K1E, K1F, K1G, K1H, K1I, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D, K2E, K2F, K2G, K2H, K2I, \
    K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, K3E, K3F, K3G, K3H, K3I, \
    K70, K71, K72, K73, K74, K75, K86, K87, K68, K69, K4A, K4B, K4C, K4D, K4E, K4F, K4G, K4H, K4I, \
    K90, K91, K92,           K95,                     K5A, K5B, K5C, K5D, K5E, K5F, K5G, K5H       \
) { \
    { K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E, K0F, K0G, K0H, K0I }, \
    { K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K1E, K1F, K1G, K1H, K1I }, \
    { K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D, K2E, K2F, K2G, K2H, K2I }, \
    { K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, K3E, K3F, K3G, K3H, K3I }, \
    { ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, K4A, K4B, K4C, K4D, K4E, K4F, K4G, K4H, K4I }, \
    { ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, K5A, K5B, K5C, K5D, K5E, K5F, K5G, K5H, ___ }, \
    { ___, ___, ___, ___, ___, ___, ___, ___, K68, K69, ___, ___, ___, ___, ___, ___, ___, ___, ___ }, \
    { K70, K71, K72, K73, K74, K75, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___ }, \
    { ___, ___, ___, ___, ___, ___, K86, K87, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___ }, \
    { K90, K91, K92, ___, ___, K95, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___ }  \
}
