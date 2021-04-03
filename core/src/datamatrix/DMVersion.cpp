/*
* Copyright 2016 Nu-book Inc.
* Copyright 2016 ZXing authors
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#include "DMVersion.h"

namespace ZXing::DataMatrix {

const Version* VersionForDimensions(int height, int width)
{
	if ((height & 0x01) != 0 || (width & 0x01) != 0 || height < 8 || height > 144)
		return nullptr;

	/**
	* See ISO 16022:2006 5.5.1 Table 7
	* See ISO 21471:2020 (DMRE) 5.5.1 Table 7
	*/
	static const Version allVersions[] = {
		// clang-format off
		{1, 10, 10, 8, 8,      {5,  {{1, 3  }, {0, 0}}}},
		{2, 12, 12, 10, 10,    {7,  {{1, 5  }, {0, 0}}}},
		{3, 14, 14, 12, 12,    {10, {{1, 8  }, {0, 0}}}},
		{4, 16, 16, 14, 14,    {12, {{1, 12 }, {0, 0}}}},
		{5, 18, 18, 16, 16,    {14, {{1, 18 }, {0, 0}}}},
		{6, 20, 20, 18, 18,    {18, {{1, 22 }, {0, 0}}}},
		{7, 22, 22, 20, 20,    {20, {{1, 30 }, {0, 0}}}},
		{8, 24, 24, 22, 22,    {24, {{1, 36 }, {0, 0}}}},
		{9, 26, 26, 24, 24,    {28, {{1, 44 }, {0, 0}}}},
		{10, 32, 32, 14, 14,   {36, {{1, 62 }, {0, 0}}}},
		{11, 36, 36, 16, 16,   {42, {{1, 86 }, {0, 0}}}},
		{12, 40, 40, 18, 18,   {48, {{1, 114}, {0, 0}}}},
		{13, 44, 44, 20, 20,   {56, {{1, 144}, {0, 0}}}},
		{14, 48, 48, 22, 22,   {68, {{1, 174}, {0, 0}}}},
		{15, 52, 52, 24, 24,   {42, {{2, 102}, {0, 0}}}},
		{16, 64, 64, 14, 14,   {56, {{2, 140}, {0, 0}}}},
		{17, 72, 72, 16, 16,   {36, {{4, 92 }, {0, 0}}}},
		{18, 80, 80, 18, 18,   {48, {{4, 114}, {0, 0}}}},
		{19, 88, 88, 20, 20,   {56, {{4, 144}, {0, 0}}}},
		{20, 96, 96, 22, 22,   {68, {{4, 174}, {0, 0}}}},
		{21, 104, 104, 24, 24, {56, {{6, 136}, {0, 0}}}},
		{22, 120, 120, 18, 18, {68, {{6, 175}, {0, 0}}}},
		{23, 132, 132, 20, 20, {62, {{8, 163}, {0, 0}}}},
		{24, 144, 144, 22, 22, {62, {{8, 156}, {2, 155}}}},
		{25, 8, 18, 6, 16,     {7,  {{1, 5  }, {0, 0}}}},
		{26, 8, 32, 6, 14,     {11, {{1, 10 }, {0, 0}}}},
		{27, 12, 26, 10, 24,   {14, {{1, 16 }, {0, 0}}}},
		{28, 12, 36, 10, 16,   {18, {{1, 22 }, {0, 0}}}},
		{29, 16, 36, 14, 16,   {24, {{1, 32 }, {0, 0}}}},
		{30, 16, 48, 14, 22,   {28, {{1, 49 }, {0, 0}}}},

		// DMRE
		{31, 8, 48, 6, 22,     {15, {{1, 18 }, {0, 0}}}},
		{32, 8, 64, 6, 14,     {18, {{1, 24 }, {0, 0}}}},
		{33, 8, 80, 6, 18,     {22, {{1, 32 }, {0, 0}}}},
		{34, 8, 96, 6, 22,     {28, {{1, 38 }, {0, 0}}}},
		{35, 8, 120, 6, 18,    {32, {{1, 49 }, {0, 0}}}},
		{36, 8, 144, 6, 22,    {36, {{1, 63 }, {0, 0}}}},
		{37, 12, 64, 10, 14,   {27, {{1, 43 }, {0, 0}}}},
		{38, 12, 88, 10, 20,   {36, {{1, 64 }, {0, 0}}}},
		{39, 16, 64, 14, 14,   {36, {{1, 62 }, {0, 0}}}},
		{40, 20, 36, 18, 16,   {28, {{1, 44 }, {0, 0}}}},
		{41, 20, 44, 18, 20,   {34, {{1, 56 }, {0, 0}}}},
		{42, 20, 64, 18, 14,   {42, {{1, 84 }, {0, 0}}}},
		{43, 22, 48, 20, 22,   {38, {{1, 72 }, {0, 0}}}},
		{44, 24, 48, 22, 22,   {41, {{1, 80 }, {0, 0}}}},
		{45, 24, 64, 22, 14,   {46, {{1, 108}, {0, 0}}}},
		{46, 26, 40, 24, 18,   {38, {{1, 70 }, {0, 0}}}},
		{47, 26, 48, 24, 22,   {42, {{1, 90 }, {0, 0}}}},
		{48, 26, 64, 24, 14,   {50, {{1, 118}, {0, 0}}}},
		// clang-format on
	};

	for (auto& version : allVersions)
		if (version.symbolHeight == height && version.symbolWidth == width)
			return &version;

	return nullptr;
}

} // namespace ZXing::DataMatrix