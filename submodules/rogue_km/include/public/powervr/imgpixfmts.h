/*************************************************************************/ /*!
@File           imgpixfmts.h
@Copyright      Copyright (c) Imagination Technologies Ltd. All Rights Reserved
@License        Dual MIT/GPLv2

The contents of this file are subject to the MIT license as set out below.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

Alternatively, the contents of this file may be used under the terms of
the GNU General Public License Version 2 ("GPL") in which case the provisions
of GPL are applicable instead of those above.

If you wish to allow use of your version of this file only under the terms of
GPL, and not to allow others to use your version of this file under the terms
of the MIT license, indicate your decision by deleting the provisions above
and replace them with the notice and other provisions required by GPL as set
out in the file called "GPL-COPYING" included in this distribution. If you do
not delete the provisions above, a recipient may use your version of this file
under the terms of either the MIT license or GPL.

This License is also included in this distribution in the file called
"MIT-COPYING".

EXCEPT AS OTHERWISE STATED IN A NEGOTIATED AGREEMENT: (A) THE SOFTWARE IS
PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
PURPOSE AND NONINFRINGEMENT; AND (B) IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/ /**************************************************************************/

/******************************************************************************
 **
 ** WARNING: File is autogenerated by parsesystable.py - DO NOT EDIT.
 ** Use fmts_systable.txt to add new formats.
 **
 *****************************************************************************/

#if !defined(IMGPIXFMTS_H)
#define IMGPIXFMTS_H

typedef enum _IMG_PIXFMT_
{
	IMG_PIXFMT_UNKNOWN = 0,
	IMG_PIXFMT_RESERVED_1 = 1,
	IMG_PIXFMT_RESERVED_2 = 2,
	IMG_PIXFMT_RESERVED_3 = 3,
	IMG_PIXFMT_RESERVED_4 = 4,
	IMG_PIXFMT_RESERVED_5 = 5,
	IMG_PIXFMT_RESERVED_6 = 6,
	IMG_PIXFMT_RESERVED_7 = 7,
	IMG_PIXFMT_RESERVED_8 = 8,
	IMG_PIXFMT_RESERVED_9 = 9,
	IMG_PIXFMT_RESERVED_10 = 10,
	IMG_PIXFMT_RESERVED_11 = 11,
	IMG_PIXFMT_RESERVED_12 = 12,
	IMG_PIXFMT_RESERVED_13 = 13,
	IMG_PIXFMT_RESERVED_14 = 14,
	IMG_PIXFMT_RESERVED_15 = 15,
	IMG_PIXFMT_RESERVED_16 = 16,
	IMG_PIXFMT_RESERVED_17 = 17,
	IMG_PIXFMT_RESERVED_18 = 18,
	IMG_PIXFMT_RESERVED_19 = 19,
	IMG_PIXFMT_RESERVED_20 = 20,
	IMG_PIXFMT_RESERVED_21 = 21,
	IMG_PIXFMT_RESERVED_22 = 22,
	IMG_PIXFMT_RESERVED_23 = 23,
	IMG_PIXFMT_RESERVED_24 = 24,
	IMG_PIXFMT_R10G10B10A2_UNORM = 25,
	IMG_PIXFMT_RESERVED_26 = 26,
	IMG_PIXFMT_RESERVED_27 = 27,
	IMG_PIXFMT_B10G10R10A2_UNORM = 28,
	IMG_PIXFMT_RESERVED_29 = 29,
	IMG_PIXFMT_RESERVED_30 = 30,
	IMG_PIXFMT_RESERVED_31 = 31,
	IMG_PIXFMT_R8G8B8A8_UNORM = 32,
	IMG_PIXFMT_R8G8B8A8_UNORM_SRGB = 33,
	IMG_PIXFMT_RESERVED_34 = 34,
	IMG_PIXFMT_RESERVED_35 = 35,
	IMG_PIXFMT_RESERVED_36 = 36,
	IMG_PIXFMT_R8G8B8X8_UNORM = 37,
	IMG_PIXFMT_RESERVED_38 = 38,
	IMG_PIXFMT_RESERVED_39 = 39,
	IMG_PIXFMT_RESERVED_40 = 40,
	IMG_PIXFMT_RESERVED_41 = 41,
	IMG_PIXFMT_RESERVED_42 = 42,
	IMG_PIXFMT_RESERVED_43 = 43,
	IMG_PIXFMT_RESERVED_44 = 44,
	IMG_PIXFMT_RESERVED_45 = 45,
	IMG_PIXFMT_RESERVED_46 = 46,
	IMG_PIXFMT_RESERVED_47 = 47,
	IMG_PIXFMT_RESERVED_48 = 48,
	IMG_PIXFMT_RESERVED_49 = 49,
	IMG_PIXFMT_RESERVED_50 = 50,
	IMG_PIXFMT_RESERVED_51 = 51,
	IMG_PIXFMT_D32_FLOAT = 52,
	IMG_PIXFMT_RESERVED_53 = 53,
	IMG_PIXFMT_RESERVED_54 = 54,
	IMG_PIXFMT_RESERVED_55 = 55,
	IMG_PIXFMT_RESERVED_56 = 56,
	IMG_PIXFMT_RESERVED_57 = 57,
	IMG_PIXFMT_RESERVED_58 = 58,
	IMG_PIXFMT_D24_UNORM_X8_TYPELESS = 59,
	IMG_PIXFMT_RESERVED_60 = 60,
	IMG_PIXFMT_RESERVED_61 = 61,
	IMG_PIXFMT_RESERVED_62 = 62,
	IMG_PIXFMT_R8G8_UNORM = 63,
	IMG_PIXFMT_RESERVED_64 = 64,
	IMG_PIXFMT_RESERVED_65 = 65,
	IMG_PIXFMT_RESERVED_66 = 66,
	IMG_PIXFMT_RESERVED_67 = 67,
	IMG_PIXFMT_RESERVED_68 = 68,
	IMG_PIXFMT_RESERVED_69 = 69,
	IMG_PIXFMT_D16_UNORM = 70,
	IMG_PIXFMT_RESERVED_71 = 71,
	IMG_PIXFMT_RESERVED_72 = 72,
	IMG_PIXFMT_RESERVED_73 = 73,
	IMG_PIXFMT_RESERVED_74 = 74,
	IMG_PIXFMT_RESERVED_75 = 75,
	IMG_PIXFMT_RESERVED_76 = 76,
	IMG_PIXFMT_R8_UNORM = 77,
	IMG_PIXFMT_RESERVED_78 = 78,
	IMG_PIXFMT_RESERVED_79 = 79,
	IMG_PIXFMT_RESERVED_80 = 80,
	IMG_PIXFMT_RESERVED_81 = 81,
	IMG_PIXFMT_S8_UINT = 82,
	IMG_PIXFMT_RESERVED_83 = 83,
	IMG_PIXFMT_RESERVED_84 = 84,
	IMG_PIXFMT_RESERVED_85 = 85,
	IMG_PIXFMT_B5G6R5_UNORM = 86,
	IMG_PIXFMT_R5G6B5_UNORM = 87,
	IMG_PIXFMT_B5G5R5A1_UNORM = 88,
	IMG_PIXFMT_B5G5R5X1_UNORM = 89,
	IMG_PIXFMT_B8G8R8A8_UNORM = 90,
	IMG_PIXFMT_B8G8R8X8_UNORM = 91,
	IMG_PIXFMT_B8G8R8A8_UINT = 92,
	IMG_PIXFMT_B8G8R8A8_SNORM = 93,
	IMG_PIXFMT_B8G8R8A8_SINT = 94,
	IMG_PIXFMT_B8G8R8A8_UNORM_SRGB = 95,
	IMG_PIXFMT_RESERVED_96 = 96,
	IMG_PIXFMT_RESERVED_97 = 97,
	IMG_PIXFMT_RESERVED_98 = 98,
	IMG_PIXFMT_RESERVED_99 = 99,
	IMG_PIXFMT_RESERVED_100 = 100,
	IMG_PIXFMT_RESERVED_101 = 101,
	IMG_PIXFMT_RESERVED_102 = 102,
	IMG_PIXFMT_RESERVED_103 = 103,
	IMG_PIXFMT_RESERVED_104 = 104,
	IMG_PIXFMT_RESERVED_105 = 105,
	IMG_PIXFMT_RESERVED_106 = 106,
	IMG_PIXFMT_RESERVED_107 = 107,
	IMG_PIXFMT_RESERVED_108 = 108,
	IMG_PIXFMT_RESERVED_109 = 109,
	IMG_PIXFMT_RESERVED_110 = 110,
	IMG_PIXFMT_RESERVED_111 = 111,
	IMG_PIXFMT_RESERVED_112 = 112,
	IMG_PIXFMT_RESERVED_113 = 113,
	IMG_PIXFMT_RESERVED_114 = 114,
	IMG_PIXFMT_RESERVED_115 = 115,
	IMG_PIXFMT_RESERVED_116 = 116,
	IMG_PIXFMT_RESERVED_117 = 117,
	IMG_PIXFMT_RESERVED_118 = 118,
	IMG_PIXFMT_RESERVED_119 = 119,
	IMG_PIXFMT_RESERVED_120 = 120,
	IMG_PIXFMT_RESERVED_121 = 121,
	IMG_PIXFMT_RESERVED_122 = 122,
	IMG_PIXFMT_RESERVED_123 = 123,
	IMG_PIXFMT_RESERVED_124 = 124,
	IMG_PIXFMT_RESERVED_125 = 125,
	IMG_PIXFMT_RESERVED_126 = 126,
	IMG_PIXFMT_RESERVED_127 = 127,
	IMG_PIXFMT_RESERVED_128 = 128,
	IMG_PIXFMT_RESERVED_129 = 129,
	IMG_PIXFMT_RESERVED_130 = 130,
	IMG_PIXFMT_RESERVED_131 = 131,
	IMG_PIXFMT_RESERVED_132 = 132,
	IMG_PIXFMT_RESERVED_133 = 133,
	IMG_PIXFMT_RESERVED_134 = 134,
	IMG_PIXFMT_RESERVED_135 = 135,
	IMG_PIXFMT_RESERVED_136 = 136,
	IMG_PIXFMT_RESERVED_137 = 137,
	IMG_PIXFMT_RESERVED_138 = 138,
	IMG_PIXFMT_L8_UNORM = 139,
	IMG_PIXFMT_RESERVED_140 = 140,
	IMG_PIXFMT_L8A8_UNORM = 141,
	IMG_PIXFMT_RESERVED_142 = 142,
	IMG_PIXFMT_RESERVED_143 = 143,
	IMG_PIXFMT_RESERVED_144 = 144,
	IMG_PIXFMT_RESERVED_145 = 145,
	IMG_PIXFMT_RESERVED_146 = 146,
	IMG_PIXFMT_RESERVED_147 = 147,
	IMG_PIXFMT_B4G4R4A4_UNORM = 148,
	IMG_PIXFMT_RESERVED_149 = 149,
	IMG_PIXFMT_RESERVED_150 = 150,
	IMG_PIXFMT_RESERVED_151 = 151,
	IMG_PIXFMT_RESERVED_152 = 152,
	IMG_PIXFMT_RESERVED_153 = 153,
	IMG_PIXFMT_RESERVED_154 = 154,
	IMG_PIXFMT_RESERVED_155 = 155,
	IMG_PIXFMT_RESERVED_156 = 156,
	IMG_PIXFMT_RESERVED_157 = 157,
	IMG_PIXFMT_RESERVED_158 = 158,
	IMG_PIXFMT_RESERVED_159 = 159,
	IMG_PIXFMT_RESERVED_160 = 160,
	IMG_PIXFMT_RESERVED_161 = 161,
	IMG_PIXFMT_RESERVED_162 = 162,
	IMG_PIXFMT_R8G8B8_UNORM = 163,
	IMG_PIXFMT_R8G8B8_UNORM_SRGB = 164,
	IMG_PIXFMT_RESERVED_165 = 165,
	IMG_PIXFMT_RESERVED_166 = 166,
	IMG_PIXFMT_RESERVED_167 = 167,
	IMG_PIXFMT_RESERVED_168 = 168,
	IMG_PIXFMT_RESERVED_169 = 169,
	IMG_PIXFMT_RESERVED_170 = 170,
	IMG_PIXFMT_RESERVED_171 = 171,
	IMG_PIXFMT_RESERVED_172 = 172,
	IMG_PIXFMT_RESERVED_173 = 173,
	IMG_PIXFMT_UYVY = 174,
	IMG_PIXFMT_VYUY = 175,
	IMG_PIXFMT_YUYV = 176,
	IMG_PIXFMT_YVYU = 177,
	IMG_PIXFMT_YVU420_2PLANE = 178,
	IMG_PIXFMT_YUV420_2PLANE = 179,
	IMG_PIXFMT_YVU420_2PLANE_MACRO_BLOCK = 180,
	IMG_PIXFMT_YUV420_3PLANE = 181,
	IMG_PIXFMT_YVU420_3PLANE = 182,
	IMG_PIXFMT_RESERVED_183 = 183,
	IMG_PIXFMT_RESERVED_184 = 184,
	IMG_PIXFMT_RESERVED_185 = 185,
	IMG_PIXFMT_RESERVED_186 = 186,
	IMG_PIXFMT_RESERVED_187 = 187,
	IMG_PIXFMT_RESERVED_188 = 188,
	IMG_PIXFMT_RESERVED_189 = 189,
	IMG_PIXFMT_RESERVED_190 = 190,
	IMG_PIXFMT_RESERVED_191 = 191,
	IMG_PIXFMT_RESERVED_192 = 192,
	IMG_PIXFMT_RESERVED_193 = 193,
	IMG_PIXFMT_RESERVED_194 = 194,
	IMG_PIXFMT_RESERVED_195 = 195,
	IMG_PIXFMT_RESERVED_196 = 196,
	IMG_PIXFMT_RESERVED_197 = 197,
	IMG_PIXFMT_RESERVED_198 = 198,
	IMG_PIXFMT_RESERVED_199 = 199,
	IMG_PIXFMT_RESERVED_200 = 200,
	IMG_PIXFMT_RESERVED_201 = 201,
	IMG_PIXFMT_RESERVED_202 = 202,
	IMG_PIXFMT_RESERVED_203 = 203,
	IMG_PIXFMT_YVU8_422_2PLANE_PACK8 = 204,
	IMG_PIXFMT_RESERVED_205 = 205,
	IMG_PIXFMT_YVU10_444_1PLANE_PACK10 = 206,
	IMG_PIXFMT_YVU10_420_2PLANE_PACK16 = 207,
	IMG_PIXFMT_RESERVED_208 = 208,
	IMG_PIXFMT_RESERVED_209 = 209,
	IMG_PIXFMT_YUV8_422_2PLANE_PACK8 = 210,
	IMG_PIXFMT_YUV8_444_3PLANE_PACK8 = 211,
	IMG_PIXFMT_RESERVED_212 = 212,
	IMG_PIXFMT_RESERVED_213 = 213,
	IMG_PIXFMT_RESERVED_214 = 214,
	IMG_PIXFMT_RESERVED_215 = 215,
	IMG_PIXFMT_RESERVED_216 = 216,
	IMG_PIXFMT_RESERVED_217 = 217,
	IMG_PIXFMT_RESERVED_218 = 218,
	IMG_PIXFMT_RESERVED_219 = 219,
	IMG_PIXFMT_RESERVED_220 = 220,
	IMG_PIXFMT_RESERVED_221 = 221,
	IMG_PIXFMT_RESERVED_222 = 222,
	IMG_PIXFMT_RESERVED_223 = 223,
	IMG_PIXFMT_RESERVED_224 = 224,
	IMG_PIXFMT_RESERVED_225 = 225,
	IMG_PIXFMT_RESERVED_226 = 226,
	IMG_PIXFMT_RESERVED_227 = 227,
	IMG_PIXFMT_RESERVED_228 = 228,
	IMG_PIXFMT_RESERVED_229 = 229,
	IMG_PIXFMT_RESERVED_230 = 230,
	IMG_PIXFMT_RESERVED_231 = 231,
	IMG_PIXFMT_RESERVED_232 = 232,
	IMG_PIXFMT_RESERVED_233 = 233,
	IMG_PIXFMT_RESERVED_234 = 234,
	IMG_PIXFMT_RESERVED_235 = 235,
	IMG_PIXFMT_RESERVED_236 = 236,
	IMG_PIXFMT_RESERVED_237 = 237,
	IMG_PIXFMT_RESERVED_238 = 238,
	IMG_PIXFMT_RESERVED_239 = 239,
	IMG_PIXFMT_RESERVED_240 = 240,
	IMG_PIXFMT_RESERVED_241 = 241,
	IMG_PIXFMT_RESERVED_242 = 242,
	IMG_PIXFMT_RESERVED_243 = 243,
	IMG_PIXFMT_RESERVED_244 = 244,
	IMG_PIXFMT_RESERVED_245 = 245,
	IMG_PIXFMT_RESERVED_246 = 246,
	IMG_PIXFMT_RESERVED_247 = 247,
	IMG_PIXFMT_YVU8_420_2PLANE_PACK8_P = 248,
	IMG_PIXFMT_RESERVED_249 = 249,
	IMG_PIXFMT_RESERVED_250 = 250,
	IMG_PIXFMT_RESERVED_251 = 251,
	IMG_PIXFMT_YUV8_420_2PLANE_PACK8_P = 252,
	IMG_PIXFMT_RESERVED_253 = 253,
	IMG_PIXFMT_RESERVED_254 = 254,
	IMG_PIXFMT_UYVY10_422_1PLANE_PACK10_CUST1 = 255,
	IMG_PIXFMT_RESERVED_256 = 256,
	IMG_PIXFMT_RESERVED_257 = 257,
	IMG_PIXFMT_RESERVED_258 = 258,
	IMG_PIXFMT_RESERVED_259 = 259,
	IMG_PIXFMT_RESERVED_260 = 260,
	IMG_PIXFMT_RESERVED_261 = 261,
	IMG_PIXFMT_RESERVED_262 = 262,
	IMG_PIXFMT_RESERVED_263 = 263,
	IMG_PIXFMT_RESERVED_264 = 264,
	IMG_PIXFMT_RESERVED_265 = 265,
	IMG_PIXFMT_RESERVED_266 = 266,
	IMG_PIXFMT_RESERVED_267 = 267,
	IMG_PIXFMT_R10G10B10X2_UNORM = 268,
#define IMG_PIXFMT_ENUM_COUNT 269
} IMG_PIXFMT;

#endif /* IMGPIXFMTS_H */
