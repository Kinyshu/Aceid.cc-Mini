﻿/*
				░█████╗░░█████╗░███████╗██╗██████╗░░░░░█████╗░░█████╗░
				██╔══██╗██╔══██╗██╔════╝██║██╔══██╗░░░██╔══██╗██╔══██╗
				███████║██║░░╚═╝█████╗░░██║██║░░██║░░░██║░░╚═╝██║░░╚═╝
				██╔══██║██║░░██╗██╔══╝░░██║██║░░██║░░░██║░░██╗██║░░██╗
				██║░░██║╚█████╔╝███████╗██║██████╔╝██╗╚█████╔╝╚█████╔╝
				╚═╝░░╚═╝░╚════╝░╚══════╝╚═╝╚═════╝░╚═╝░╚════╝░░╚════╝░

				  Ｔｈｅ ｃｏｄｅ ｗａｓ ｗｒｉｔｔｅｎ ｂｙ Ｋｉｎｙｓｈｕ

				  Links to Aceid.
				   - Website:	https://aceid.cc/
				   - Telegram:  https://t.me/aceid_cc
				   - VK:		https://vk.me/join/AJQ1dwO39CRYputL5JFysaY6

				  Contacts with Coder.
				   - VK:		https://vk.com/kinyshu
				   - Discord:   Kinyshu#5558

				  Github link:  https://github.com/Kinyshu

				  Donate.
				   - QIWI:      https://qiwi.com/n/KINYSHUACEID

				  Used in the project.
				   - HookLib:	https://github.com/HoShiMin/HookLib
				   - ImGui:		https://github.com/ocornut/imgui
				   - stb_image:	https://github.com/planetack/stb_image
				   - termcolor: https://github.com/ikalnytskyi/termcolor
*/#pragma once

#ifndef BYTES_HPP
#define BYTES_HPP

std::uint8_t bglogo[] = {
	0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A, 0x00, 0x00, 0x00, 0x0D, 0x49, 0x48, 0x44, 0x52,
	0x00, 0x00, 0x00, 0xC8, 0x00, 0x00, 0x00, 0xC8, 0x04, 0x03, 0x00, 0x00, 0x00, 0x5F, 0x76, 0xB3,
	0xAD, 0x00, 0x00, 0x00, 0x04, 0x67, 0x41, 0x4D, 0x41, 0x00, 0x00, 0xB1, 0x8F, 0x0B, 0xFC, 0x61,
	0x05, 0x00, 0x00, 0x00, 0x01, 0x73, 0x52, 0x47, 0x42, 0x00, 0xAE, 0xCE, 0x1C, 0xE9, 0x00, 0x00,
	0x00, 0x18, 0x50, 0x4C, 0x54, 0x45, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x16,
	0x11, 0x11, 0xFF, 0x2C, 0x33, 0x32, 0x11, 0x11, 0x7F, 0x18, 0x1B, 0xC7, 0x22, 0x27, 0xF7, 0x53,
	0x9D, 0x09, 0x00, 0x00, 0x00, 0x03, 0x74, 0x52, 0x4E, 0x53, 0xF0, 0x02, 0x60, 0x30, 0x36, 0xB4,
	0xD4, 0x00, 0x00, 0x08, 0xE7, 0x49, 0x44, 0x41, 0x54, 0x78, 0xDA, 0xED, 0x5C, 0x0B, 0x72, 0xDB,
	0x38, 0x0C, 0x75, 0x93, 0x0B, 0x6C, 0x7B, 0x82, 0xA6, 0x7B, 0x81, 0xCC, 0x32, 0xB0, 0x0F, 0x10,
	0xD9, 0x3A, 0x00, 0xC2, 0xF6, 0x00, 0x76, 0xB2, 0x07, 0xB0, 0x9B, 0x5C, 0x7F, 0x49, 0x00, 0xFC,
	0x49, 0xE2, 0x47, 0x6A, 0x9D, 0xC9, 0x76, 0xC4, 0x6E, 0xE3, 0x74, 0x13, 0xF1, 0x11, 0x78, 0x00,
	0x08, 0x02, 0x1C, 0x6D, 0x3E, 0x9B, 0xF1, 0x6D, 0x73, 0xB5, 0xF1, 0xCD, 0xCE, 0xBF, 0x31, 0x7F,
	0xBF, 0xAA, 0x8D, 0xBA, 0xD2, 0xD8, 0xA8, 0x1B, 0x06, 0xF9, 0x7A, 0xAF, 0xAE, 0x39, 0x6E, 0x2C,
	0xC8, 0x97, 0xDB, 0xAB, 0x62, 0xDC, 0x6F, 0xEE, 0x0C, 0xC8, 0x57, 0x75, 0xE5, 0x71, 0x63, 0x40,
	0x6E, 0xAF, 0x0D, 0xB2, 0xF9, 0xBC, 0xF9, 0x72, 0x6D, 0x0C, 0x75, 0x7F, 0xB7, 0xF9, 0xEB, 0xFA,
	0x20, 0x9F, 0x36, 0x7F, 0x5F, 0x1D, 0x44, 0xFD, 0xF3, 0x3E, 0x20, 0xB7, 0xD7, 0x07, 0x51, 0xEF,
	0x01, 0xB2, 0x79, 0x0F, 0x90, 0xFB, 0x15, 0x64, 0x05, 0x59, 0x41, 0x56, 0x90, 0x15, 0x64, 0x05,
	0x59, 0x41, 0x56, 0x90, 0x15, 0x64, 0x05, 0xF9, 0xE3, 0x40, 0xF0, 0x37, 0x80, 0x00, 0xFD, 0x29,
	0x61, 0xC0, 0x2F, 0x82, 0x60, 0x65, 0xBD, 0x08, 0xAD, 0xD2, 0x34, 0xAA, 0x0B, 0x64, 0xD5, 0x6E,
	0x42, 0x44, 0xFE, 0x56, 0x04, 0x85, 0x45, 0x20, 0xFC, 0x30, 0xCD, 0x0B, 0x43, 0xF9, 0xD0, 0xC3,
	0x41, 0x40, 0x87, 0xA5, 0x92, 0x60, 0x98, 0xD7, 0xCD, 0x07, 0x2A, 0x2C, 0x1C, 0x19, 0x4A, 0x64,
	0xC2, 0xB9, 0x20, 0xFE, 0x81, 0xEF, 0x3C, 0x1F, 0x46, 0x2A, 0x41, 0xAF, 0x3F, 0x83, 0x02, 0x16,
	0x09, 0x19, 0x07, 0x97, 0x48, 0x62, 0x1F, 0xEA, 0xD2, 0xB9, 0xDD, 0x17, 0x3B, 0xBB, 0xD1, 0x1A,
	0x38, 0x30, 0x46, 0xC9, 0x1B, 0x62, 0xC9, 0xBA, 0x60, 0xDB, 0x61, 0x58, 0x3B, 0x3A, 0x69, 0x68,
	0x72, 0xA4, 0x7F, 0x1A, 0x30, 0xC2, 0x73, 0x28, 0xED, 0x20, 0xF4, 0xEB, 0x34, 0xC9, 0x43, 0x77,
	0x46, 0x90, 0x25, 0x62, 0x84, 0x40, 0x3F, 0x05, 0x1A, 0xE6, 0x5B, 0x44, 0xC7, 0xDA, 0x22, 0x3F,
	0x39, 0x75, 0x8F, 0x9E, 0x65, 0x9E, 0x1B, 0x78, 0xF9, 0x2C, 0x03, 0x6B, 0x4E, 0xFE, 0xB7, 0x7C,
	0x99, 0x01, 0x22, 0x46, 0xD4, 0x75, 0x07, 0x12, 0xC2, 0x2E, 0x56, 0x21, 0x62, 0x10, 0xC2, 0xCE,
	0x8E, 0x5A, 0xD9, 0xFF, 0xEC, 0xEC, 0x44, 0x52, 0xBB, 0x24, 0xE0, 0x3F, 0x51, 0xED, 0x2C, 0x88,
	0xAC, 0x4E, 0x28, 0x10, 0x3A, 0x10, 0x18, 0x07, 0x14, 0x01, 0x69, 0xAB, 0x2D, 0xF9, 0xE1, 0x0C,
	0x13, 0x26, 0xAC, 0x53, 0xD7, 0x75, 0x4E, 0xFB, 0xAC, 0x25, 0xFB, 0x3D, 0xD2, 0xCC, 0x88, 0xDA,
	0x7E, 0x4B, 0xE4, 0x69, 0x01, 0x65, 0x61, 0xB1, 0x5D, 0x5D, 0x56, 0x05, 0x9D, 0x05, 0x71, 0x93,
	0xAB, 0xA0, 0x36, 0xF6, 0x0E, 0xF3, 0x09, 0x0C, 0xC5, 0xA3, 0xA0, 0xB1, 0x09, 0x10, 0xC7, 0xF4,
	0xCE, 0x82, 0x1C, 0xED, 0xA4, 0x62, 0x45, 0xF6, 0x67, 0xC8, 0x64, 0x33, 0x19, 0x7E, 0x38, 0x33,
	0x83, 0x26, 0x75, 0xA1, 0xE3, 0xC3, 0x7C, 0xFB, 0x64, 0x41, 0x1E, 0x95, 0x7B, 0x9C, 0x71, 0xD8,
	0x6E, 0x2D, 0x13, 0x10, 0x0D, 0x46, 0xE1, 0x3F, 0x13, 0x3E, 0x39, 0x92, 0x44, 0xE4, 0x30, 0xF3,
	0x5D, 0x2C, 0xC8, 0x9E, 0x9E, 0xF6, 0x48, 0x8C, 0x66, 0xA8, 0x86, 0xA9, 0xE1, 0xE2, 0x58, 0xBB,
	0x9F, 0x6C, 0x2D, 0x46, 0xD7, 0x13, 0xEF, 0x2C, 0x8A, 0x48, 0x91, 0xAA, 0x8A, 0xE1, 0xD0, 0x49,
	0x3B, 0x89, 0x32, 0xC9, 0x89, 0x7D, 0x56, 0x91, 0xB6, 0xBA, 0x4E, 0x56, 0x68, 0xFD, 0x42, 0x08,
	0x77, 0xEB, 0xD6, 0x34, 0xCC, 0xA7, 0xB8, 0xA0, 0xFC, 0x26, 0xCC, 0x91, 0xE4, 0xC2, 0x20, 0x47,
	0x76, 0x0B, 0xF4, 0x1F, 0x1E, 0xC5, 0xE8, 0xCC, 0x4D, 0xAF, 0xF5, 0xCB, 0xCB, 0xDB, 0x59, 0x22,
	0xF2, 0xD8, 0xEF, 0xC7, 0xC4, 0xB3, 0x73, 0xB3, 0x01, 0x9B, 0x71, 0x56, 0x61, 0xE6, 0x20, 0x05,
	0xFD, 0x83, 0x9E, 0xA0, 0xF9, 0x3B, 0xA1, 0x4F, 0x42, 0x7F, 0x51, 0x12, 0x0E, 0xB4, 0x1C, 0x03,
	0x1F, 0x04, 0x64, 0x0F, 0xEC, 0x14, 0x91, 0x08, 0x7E, 0xFD, 0x66, 0xFA, 0xB7, 0xCE, 0x8F, 0x9E,
	0x84, 0x8B, 0x76, 0xA0, 0x32, 0x27, 0x76, 0x49, 0x27, 0x79, 0xD4, 0x44, 0xAF, 0x88, 0x69, 0xE5,
	0xD5, 0xF3, 0xEF, 0xA5, 0x1B, 0x0E, 0xF2, 0x1E, 0x68, 0xB4, 0x2E, 0x0A, 0x4B, 0x7E, 0x7D, 0x1C,
	0x42, 0x1C, 0x9F, 0x56, 0x3B, 0x13, 0xF3, 0x33, 0x7D, 0x1C, 0x7F, 0xEA, 0x7E, 0xE2, 0x72, 0x83,
	0x07, 0xFF, 0xA8, 0x58, 0xAA, 0x68, 0x3F, 0x33, 0x3F, 0xD3, 0x97, 0xC1, 0x98, 0x74, 0xC6, 0x58,
	0x5B, 0xB2, 0x3E, 0xD8, 0x16, 0xA7, 0xEF, 0x3C, 0xF3, 0xB2, 0xD1, 0x54, 0x39, 0xA1, 0xC0, 0x1B,
	0xAD, 0x8F, 0x39, 0xAF, 0x63, 0x74, 0x07, 0xB7, 0x57, 0x0E, 0xA9, 0x8F, 0x41, 0x5C, 0xB2, 0x65,
	0xC2, 0xC6, 0x2E, 0x3C, 0xFA, 0x28, 0x96, 0x55, 0x07, 0xE9, 0x94, 0x18, 0x07, 0xD6, 0x39, 0xB1,
	0xF1, 0xE1, 0x29, 0x5D, 0x9F, 0x71, 0x6A, 0xDC, 0xD5, 0x41, 0x8E, 0x2E, 0x5C, 0x0F, 0x6C, 0x2C,
	0xE3, 0xF1, 0xD1, 0x93, 0x3D, 0xED, 0x7D, 0x09, 0x4D, 0x59, 0xE6, 0x65, 0x5F, 0xC1, 0xAA, 0x09,
	0xDB, 0x5F, 0xDC, 0xC6, 0x8F, 0xDA, 0xDD, 0x9C, 0xF8, 0xAC, 0xD2, 0xB2, 0x57, 0x64, 0xED, 0xD8,
	0xE0, 0x8C, 0x6E, 0x2B, 0xF1, 0x4A, 0x30, 0x0F, 0x5A, 0x18, 0xB5, 0x6B, 0x63, 0x1E, 0x94, 0x24,
	0x49, 0x05, 0x4E, 0xEC, 0x4A, 0x46, 0xE6, 0xCF, 0x0F, 0x3F, 0x55, 0x40, 0x7A, 0x17, 0x89, 0x0B,
	0xEA, 0x02, 0x6F, 0x62, 0x97, 0x54, 0x09, 0x12, 0xD3, 0xA1, 0xAA, 0xB0, 0x23, 0x2B, 0x16, 0x11,
	0xB3, 0x26, 0xEC, 0x1C, 0x1E, 0x53, 0xC5, 0x90, 0x12, 0xB4, 0x89, 0x57, 0xA0, 0xB6, 0x0D, 0xE6,
	0x25, 0xB9, 0x51, 0x9D, 0x93, 0xC4, 0x29, 0x7A, 0x24, 0x49, 0xD0, 0xA2, 0x3C, 0xD5, 0x7C, 0x5E,
	0x43, 0x48, 0x90, 0xF3, 0x20, 0x9C, 0x03, 0x25, 0xE6, 0x6A, 0x4C, 0xC6, 0x42, 0x98, 0xBF, 0x35,
	0xC7, 0x3F, 0xB8, 0x70, 0x9D, 0xF2, 0x32, 0x61, 0xC2, 0x56, 0x63, 0xDB, 0x54, 0x09, 0x56, 0x0A,
	0x92, 0x07, 0xCB, 0x0A, 0xEB, 0x41, 0x87, 0x7C, 0x02, 0xA7, 0x41, 0x38, 0xAE, 0x90, 0x4A, 0xE3,
	0x15, 0x3F, 0x6A, 0x19, 0xD6, 0x09, 0x7E, 0x14, 0x51, 0x8C, 0xD0, 0x36, 0x62, 0xD7, 0x24, 0x91,
	0x7C, 0xFA, 0x29, 0xD5, 0xB4, 0x1F, 0xA8, 0x8A, 0x0A, 0x3B, 0x03, 0x0A, 0xF3, 0x58, 0x0E, 0xF5,
	0x74, 0xF0, 0x84, 0xC4, 0xBC, 0x22, 0x51, 0xCA, 0x91, 0xD2, 0xAE, 0x67, 0x1C, 0x89, 0xC7, 0x9C,
	0xF0, 0x59, 0x21, 0xA6, 0xBE, 0x57, 0x3A, 0x1A, 0xF8, 0xA3, 0xC8, 0xBC, 0x76, 0x89, 0x51, 0xDE,
	0xBA, 0x38, 0x39, 0xB7, 0x5F, 0x62, 0x57, 0x41, 0xED, 0x65, 0x31, 0xDF, 0x94, 0x22, 0x65, 0x0F,
	0x92, 0x85, 0x97, 0x3D, 0x9E, 0x8D, 0x18, 0x92, 0x40, 0x7C, 0x74, 0xCA, 0xE2, 0x8F, 0x92, 0xC2,
	0x8E, 0x3A, 0x64, 0xE0, 0x25, 0x4E, 0x2C, 0x96, 0x31, 0xA3, 0xB0, 0xCB, 0x77, 0x3F, 0x41, 0xB7,
	0x2A, 0xEC, 0x88, 0x4C, 0x4A, 0x3D, 0x5B, 0x21, 0xE6, 0x20, 0xA1, 0x13, 0x49, 0x55, 0xC0, 0xF2,
	0x14, 0x14, 0xB6, 0xE7, 0xE4, 0x38, 0xCA, 0x6F, 0xB2, 0xD6, 0x85, 0xE9, 0x26, 0x75, 0x48, 0x25,
	0x31, 0x70, 0x97, 0x42, 0xB4, 0x4F, 0x01, 0xC6, 0x20, 0x18, 0xEA, 0x27, 0x49, 0x94, 0x8C, 0x40,
	0xA0, 0xEC, 0xF8, 0xEC, 0xF3, 0x9A, 0x8D, 0x18, 0x0A, 0x79, 0x97, 0x3D, 0x80, 0x98, 0x05, 0x45,
	0x6E, 0xA7, 0x87, 0x23, 0xAF, 0x30, 0xB6, 0x2D, 0x4C, 0xB2, 0xFB, 0x4C, 0xEC, 0xA2, 0xA5, 0x04,
	0xAF, 0x3F, 0x8B, 0x65, 0x81, 0xFB, 0x9A, 0x8F, 0x94, 0x67, 0x0D, 0x6E, 0x0F, 0x86, 0x29, 0x10,
	0x0C, 0xBC, 0x13, 0xCC, 0x36, 0x7A, 0xD2, 0xF1, 0xEE, 0x14, 0x97, 0x55, 0xD8, 0x5E, 0xB2, 0xFF,
	0x38, 0x63, 0xC9, 0x9C, 0x7E, 0x39, 0x00, 0x9D, 0xF2, 0xCC, 0xEB, 0xDC, 0xD6, 0xC2, 0x3E, 0x9F,
	0x66, 0x5F, 0xE3, 0x00, 0x89, 0xE1, 0xB0, 0xB6, 0xCB, 0x82, 0x58, 0xB1, 0x2E, 0x19, 0xE6, 0x6D,
	0x20, 0x4E, 0xA3, 0xD7, 0x84, 0x75, 0x91, 0xA4, 0x2C, 0xCA, 0x60, 0x73, 0x4C, 0x5D, 0x32, 0xA3,
	0x30, 0xCA, 0xA0, 0x2A, 0x92, 0x48, 0x3A, 0xC1, 0x20, 0x97, 0x41, 0x60, 0x69, 0x71, 0xFC, 0xA3,
	0xD6, 0x92, 0x4B, 0x40, 0x89, 0x93, 0x70, 0xAA, 0x4A, 0xA3, 0x17, 0x26, 0xBE, 0xA2, 0x33, 0x39,
	0xE5, 0x23, 0xCA, 0x3E, 0x5F, 0x31, 0x61, 0x39, 0xB6, 0x47, 0xE9, 0xAF, 0xDB, 0xB7, 0xA0, 0xAE,
	0x30, 0x93, 0x46, 0x6A, 0x44, 0x8C, 0xF7, 0xAD, 0x71, 0x4A, 0x44, 0x5B, 0x01, 0x0B, 0x1C, 0x0C,
	0x68, 0x3F, 0x98, 0x9F, 0x01, 0x27, 0x15, 0xE6, 0xF6, 0x79, 0x28, 0x6D, 0x5A, 0x62, 0x62, 0x3A,
	0xA6, 0xC4, 0x3E, 0x39, 0x35, 0x26, 0x15, 0x86, 0xC0, 0x95, 0x83, 0xB0, 0x7B, 0x4C, 0x11, 0xCF,
	0x15, 0xA1, 0x98, 0x12, 0x73, 0xF4, 0x50, 0x28, 0xC2, 0xB8, 0x88, 0x6C, 0xF5, 0x35, 0xB9, 0xB5,
	0x1C, 0x63, 0x1B, 0xCE, 0x4B, 0x42, 0x15, 0x99, 0xF4, 0x44, 0xF2, 0xFA, 0x6C, 0x0F, 0x47, 0x4D,
	0x76, 0x7C, 0x76, 0x59, 0x24, 0x4E, 0xAB, 0x0B, 0x22, 0x5E, 0x46, 0xE9, 0xE2, 0xDB, 0x8B, 0x26,
	0xF9, 0x12, 0x13, 0x9B, 0x50, 0x18, 0x67, 0x78, 0x65, 0xEB, 0xE2, 0x42, 0x36, 0x7B, 0x49, 0xDF,
	0x0D, 0x71, 0x9E, 0x35, 0x1D, 0xE3, 0x43, 0xFE, 0x32, 0x76, 0x7C, 0x3A, 0x94, 0x53, 0xF2, 0x55,
	0xF4, 0x13, 0x41, 0x31, 0xEA, 0x1D, 0x87, 0x8E, 0xFE, 0x25, 0x51, 0x1C, 0x4C, 0x28, 0xCC, 0xF1,
	0x8E, 0xB5, 0x42, 0x27, 0x1D, 0xB7, 0x7E, 0xC6, 0x1B, 0x7D, 0x24, 0x8F, 0x25, 0xC8, 0x57, 0x89,
	0xF0, 0x34, 0x95, 0xDB, 0xEB, 0x38, 0x78, 0x4D, 0x13, 0x4F, 0x3F, 0x7B, 0x3A, 0x28, 0xC8, 0x26,
	0x26, 0x86, 0x20, 0xCD, 0x40, 0xE3, 0x53, 0x8B, 0x3D, 0x2F, 0x9B, 0x7D, 0xAF, 0xEC, 0x27, 0xC8,
	0xE9, 0xCA, 0xC5, 0x92, 0x57, 0xC8, 0xB1, 0xAC, 0x21, 0x58, 0x82, 0x46, 0x0A, 0xA3, 0x2D, 0x45,
	0x41, 0x65, 0x3F, 0xE1, 0x7D, 0xED, 0xA8, 0x74, 0xED, 0x60, 0xFD, 0x66, 0x09, 0x1A, 0x25, 0xE1,
	0xBD, 0x92, 0xDA, 0x2A, 0x56, 0x8A, 0x6A, 0xBE, 0x26, 0x5F, 0x3B, 0xC1, 0xF5, 0xAF, 0xCF, 0x23,
	0x3B, 0xA6, 0x0C, 0x01, 0x43, 0xEB, 0x66, 0xBA, 0xD0, 0xC9, 0x0D, 0x00, 0x72, 0xA9, 0x87, 0x86,
	0x4A, 0xC4, 0xEB, 0xF7, 0xA1, 0xCF, 0x27, 0xF1, 0x31, 0xDB, 0xA4, 0xA1, 0x94, 0x39, 0x0D, 0xF7,
	0xED, 0x83, 0x7C, 0x1E, 0xF3, 0x26, 0x1C, 0xC5, 0x48, 0xE0, 0x0C, 0xFD, 0x34, 0x1F, 0x64, 0xAF,
	0xD0, 0xF5, 0xA1, 0xA0, 0x94, 0x48, 0x28, 0x5F, 0xD6, 0xDC, 0xCD, 0x07, 0x39, 0x28, 0x80, 0xE2,
	0xC1, 0x34, 0x74, 0xB0, 0xA4, 0xF6, 0x58, 0xA5, 0x7E, 0x32, 0xC3, 0x43, 0xA8, 0x71, 0x12, 0x9A,
	0x6F, 0x98, 0x6C, 0x5D, 0xCD, 0xE3, 0x98, 0x16, 0x58, 0x72, 0x5D, 0x07, 0x69, 0x8F, 0x8D, 0xAA,
	0x39, 0x8D, 0xCC, 0x63, 0xD2, 0xE4, 0x2A, 0x76, 0xE7, 0x24, 0x25, 0x98, 0x4F, 0xFD, 0xDE, 0x15,
	0x88, 0xA1, 0x54, 0x4D, 0x95, 0xCC, 0x9E, 0x5D, 0x65, 0xB7, 0x84, 0xF9, 0x6A, 0xB1, 0xC0, 0x4B,
	0x22, 0xD4, 0xCF, 0x06, 0xE9, 0x55, 0x52, 0xEB, 0x2E, 0x77, 0xB1, 0xE5, 0xD8, 0x34, 0x9F, 0xFA,
	0x63, 0x22, 0x4A, 0x0E, 0xC4, 0xB5, 0xA8, 0x70, 0x19, 0xF5, 0xE7, 0x7A, 0x58, 0x09, 0xAE, 0x22,
	0xE5, 0x98, 0xD3, 0x7C, 0x9F, 0x87, 0xA8, 0xC7, 0x9A, 0x57, 0x17, 0xF8, 0xE8, 0x05, 0x73, 0xBD,
	0xBE, 0x7F, 0x41, 0x98, 0xD1, 0xF4, 0x77, 0x8D, 0x86, 0x39, 0x10, 0x6F, 0xCF, 0xE8, 0xCA, 0x0E,
	0x0D, 0x7E, 0x22, 0x8D, 0x99, 0x96, 0xEA, 0x63, 0x9C, 0xA0, 0x45, 0x36, 0x0A, 0x8D, 0x92, 0xE0,
	0x1C, 0xEA, 0xFB, 0x57, 0x8C, 0x43, 0x46, 0x65, 0xFB, 0x05, 0xD7, 0xD6, 0x1F, 0x9D, 0x54, 0xCA,
	0x54, 0xA8, 0xD0, 0xBD, 0x6D, 0xBF, 0xBE, 0xE0, 0xF5, 0xB5, 0x6B, 0x83, 0xA0, 0x23, 0x7C, 0x74,
	0x51, 0xA3, 0x45, 0x5D, 0xA8, 0xDC, 0x09, 0xB2, 0x46, 0x7D, 0xFF, 0xEC, 0x9A, 0xC4, 0xE8, 0xFB,
	0x69, 0x0D, 0x20, 0xDC, 0x35, 0xF4, 0x85, 0xE7, 0x53, 0x8D, 0x6D, 0xD7, 0x72, 0x94, 0x6E, 0x23,
	0xB6, 0x9A, 0x30, 0x84, 0xD3, 0x5D, 0x81, 0xFA, 0xFE, 0x45, 0xFB, 0xDF, 0x4A, 0x3A, 0x9A, 0x30,
	0x7D, 0xFA, 0x1D, 0xD4, 0x25, 0xA4, 0x71, 0x8D, 0xC5, 0x0D, 0xD2, 0x42, 0x24, 0x9D, 0xC1, 0x71,
	0xDF, 0xA1, 0xC6, 0x89, 0x92, 0x93, 0x1D, 0xE2, 0x43, 0x81, 0xED, 0xA8, 0x4D, 0xAB, 0x70, 0xDC,
	0x01, 0xAE, 0xF8, 0x89, 0xB4, 0xFB, 0x33, 0x5E, 0xCF, 0x89, 0x37, 0x84, 0x16, 0x30, 0x37, 0x6F,
	0xF9, 0xCC, 0x09, 0x8D, 0x20, 0x49, 0x9C, 0x1C, 0x51, 0x6F, 0xD9, 0x4E, 0xD4, 0x84, 0xDC, 0x67,
	0x44, 0x9C, 0x7B, 0xF5, 0x4A, 0x21, 0x55, 0x8C, 0xEC, 0x05, 0x82, 0x94, 0xFA, 0x57, 0x4F, 0x05,
	0xD9, 0x6C, 0x72, 0xBD, 0x00, 0x06, 0xE7, 0x90, 0x2C, 0x88, 0x54, 0xBB, 0xA5, 0x17, 0x4C, 0x4E,
	0x7C, 0x49, 0xA9, 0x48, 0x7A, 0xE5, 0xFE, 0x58, 0x2D, 0x2D, 0xFB, 0x79, 0xC4, 0x73, 0xA5, 0x85,
	0xD6, 0xE8, 0xA8, 0x3F, 0x3C, 0xFB, 0x4D, 0x93, 0xD4, 0xA4, 0x3D, 0x9C, 0x1A, 0x15, 0xB7, 0x9B,
	0xEE, 0x77, 0xC9, 0xAD, 0x02, 0xAE, 0x61, 0x45, 0x10, 0x3C, 0x2B, 0x37, 0x0A, 0xC2, 0xC5, 0x02,
	0x88, 0x2F, 0x61, 0x41, 0x33, 0x88, 0xBF, 0x14, 0x67, 0x33, 0xE8, 0x93, 0x09, 0xB3, 0xC1, 0xF1,
	0x34, 0x1F, 0xDA, 0xBC, 0x13, 0x2A, 0x81, 0x80, 0xD1, 0x35, 0xB9, 0x2A, 0x08, 0x3F, 0xC9, 0xCE,
	0xB2, 0x7D, 0xC5, 0xC4, 0xF1, 0x20, 0xBA, 0x2B, 0x41, 0xED, 0xE1, 0xCC, 0xB5, 0x92, 0x12, 0x08,
	0xF8, 0xC2, 0x27, 0x28, 0x7F, 0x2F, 0xC5, 0x4F, 0x6A, 0x0D, 0x4E, 0x24, 0x71, 0xD7, 0xBC, 0xD0,
	0x35, 0x75, 0x97, 0xDC, 0xB9, 0x93, 0xEC, 0x9B, 0x4A, 0xDF, 0x9E, 0x64, 0x22, 0xDA, 0xB1, 0xCF,
	0x8D, 0x19, 0x58, 0x20, 0x49, 0x22, 0x0F, 0x46, 0x57, 0xAD, 0xC8, 0xA0, 0x38, 0xAA, 0x0B, 0xE1,
	0x2A, 0x7B, 0x9D, 0xA4, 0x65, 0xFB, 0x8D, 0xC3, 0xA9, 0xDC, 0x5B, 0x09, 0xFE, 0x11, 0x5D, 0x6A,
	0xE0, 0x0A, 0x03, 0xC6, 0x95, 0x80, 0x39, 0x92, 0xA0, 0x94, 0xBF, 0x34, 0xDB, 0x68, 0x7A, 0xF5,
	0x26, 0x9A, 0x19, 0x87, 0x57, 0xF2, 0x16, 0x5E, 0x1B, 0x45, 0xB1, 0x01, 0x6F, 0xB5, 0xE8, 0x6E,
	0xCD, 0xF8, 0x73, 0xE6, 0xE4, 0xAD, 0xC8, 0x06, 0x10, 0x57, 0x35, 0x82, 0x04, 0x85, 0xAC, 0x09,
	0xD2, 0xF0, 0x93, 0xBB, 0x76, 0x59, 0xF7, 0x93, 0xC4, 0x96, 0x95, 0x9F, 0x99, 0x35, 0x05, 0xE2,
	0xA8, 0x2A, 0xA1, 0x63, 0x11, 0xF1, 0xFE, 0x2E, 0x0A, 0x50, 0x1D, 0x4B, 0x83, 0xBF, 0x78, 0xE9,
	0x76, 0x28, 0x28, 0xDE, 0x1D, 0x6D, 0x50, 0x17, 0x46, 0xF4, 0xCB, 0xAE, 0x64, 0x3F, 0xD8, 0xFB,
	0x26, 0x0C, 0x17, 0x97, 0x39, 0x63, 0x92, 0x87, 0xC9, 0xFD, 0xC1, 0x70, 0x8D, 0x13, 0x71, 0xD8,
	0x8D, 0x5B, 0x78, 0xCB, 0xD6, 0x5D, 0x32, 0x72, 0xD3, 0x71, 0xB2, 0x10, 0x8A, 0xE5, 0xB8, 0xE4,
	0x96, 0xED, 0x44, 0x8E, 0x37, 0x38, 0x1A, 0xFB, 0x8C, 0x26, 0xDE, 0x40, 0x60, 0xA1, 0x75, 0xE1,
	0x00, 0x4C, 0x85, 0x1B, 0xA9, 0xCD, 0x63, 0x26, 0x27, 0xB1, 0xA9, 0x82, 0x54, 0x2B, 0x27, 0xD7,
	0xB3, 0xC4, 0x19, 0xE3, 0xD5, 0x3B, 0x3F, 0x69, 0x17, 0x66, 0x56, 0x58, 0x11, 0xE7, 0x00, 0x6F,
	0x08, 0xAA, 0x41, 0x0C, 0xF5, 0xA1, 0xEE, 0xD5, 0x63, 0x3E, 0xBF, 0x54, 0xAA, 0x72, 0x2D, 0x7E,
	0x8E, 0x24, 0x30, 0x49, 0xD2, 0x6F, 0xE7, 0x04, 0x86, 0xC6, 0xDC, 0x8C, 0x35, 0x8B, 0x13, 0x98,
	0x27, 0xC0, 0x47, 0x24, 0xFE, 0x17, 0x85, 0xF9, 0x05, 0x49, 0xB0, 0x19, 0xEF, 0x03, 0xAA, 0x0B,
	0x66, 0x98, 0xD4, 0x47, 0x27, 0x7E, 0x05, 0x59, 0x41, 0x56, 0x90, 0x15, 0x64, 0x05, 0x59, 0x41,
	0x56, 0x90, 0xFF, 0x07, 0xC8, 0xE6, 0x0F, 0x7A, 0x9B, 0xCF, 0xF5, 0x5F, 0x7E, 0xA4, 0x3E, 0xBD,
	0xC3, 0x6B, 0x9C, 0xD4, 0xDD, 0x3B, 0xBC, 0x90, 0xEA, 0xFE, 0x1D, 0x5E, 0xAD, 0x75, 0x7F, 0x73,
	0xFD, 0x97, 0x84, 0xA9, 0xFB, 0x3B, 0x7A, 0xDD, 0xD9, 0xB5, 0x05, 0x91, 0x17, 0xB7, 0x5D, 0x71,
	0xC8, 0x8B, 0xDB, 0xAE, 0xF9, 0x0A, 0xBA, 0x5B, 0x7A, 0x05, 0xDD, 0x7F, 0x3B, 0x9C, 0xFD, 0xA3,
	0x3B, 0x91, 0x9E, 0xB8, 0x00, 0x00, 0x00, 0x00, 0x49, 0x45, 0x4E, 0x44, 0xAE, 0x42, 0x60, 0x82
};

std::uint8_t aiming[] = {
	0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A, 0x00, 0x00, 0x00, 0x0D, 0x49, 0x48, 0x44, 0x52,
	0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x20, 0x08, 0x03, 0x00, 0x00, 0x00, 0x44, 0xA4, 0x8A,
	0xC6, 0x00, 0x00, 0x00, 0x04, 0x67, 0x41, 0x4D, 0x41, 0x00, 0x00, 0xB1, 0x8F, 0x0B, 0xFC, 0x61,
	0x05, 0x00, 0x00, 0x00, 0x01, 0x73, 0x52, 0x47, 0x42, 0x00, 0xAE, 0xCE, 0x1C, 0xE9, 0x00, 0x00,
	0x00, 0x36, 0x50, 0x4C, 0x54, 0x45, 0x47, 0x70, 0x4C, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x86, 0x52, 0xCC, 0x5B,
	0x00, 0x00, 0x00, 0x11, 0x74, 0x52, 0x4E, 0x53, 0x00, 0x55, 0xF7, 0xE9, 0x17, 0x11, 0x20, 0x03,
	0x06, 0x0B, 0x6C, 0x2D, 0xC0, 0xD5, 0x9C, 0xB0, 0x3B, 0xB0, 0x51, 0xA5, 0x02, 0x00, 0x00, 0x01,
	0xB8, 0x49, 0x44, 0x41, 0x54, 0x38, 0xCB, 0x6D, 0x53, 0x81, 0x96, 0xC2, 0x30, 0x08, 0xA3, 0x1D,
	0xD0, 0xD2, 0x76, 0x53, 0xFE, 0xFF, 0x67, 0x2F, 0xD0, 0xE9, 0x9D, 0xBE, 0xEB, 0x9B, 0x53, 0x47,
	0x80, 0x2C, 0x04, 0xA2, 0xD7, 0x69, 0xAD, 0x5B, 0xA3, 0x51, 0xE8, 0xDF, 0xB3, 0xA3, 0x44, 0xE2,
	0xDE, 0xF3, 0xFF, 0x7F, 0x61, 0x2B, 0xD7, 0xE9, 0x38, 0xE7, 0x55, 0xBE, 0x20, 0x08, 0x0B, 0xD1,
	0x38, 0x10, 0xAC, 0x79, 0xF9, 0x31, 0xE8, 0x3B, 0x3E, 0x91, 0xFC, 0x18, 0x93, 0xDD, 0x6D, 0x96,
	0x87, 0xFB, 0x9A, 0x9F, 0xF1, 0x82, 0x30, 0x1E, 0x89, 0x94, 0x62, 0x46, 0x34, 0x01, 0x79, 0xB3,
	0xED, 0xC6, 0x11, 0x47, 0x51, 0x66, 0xD6, 0xB8, 0x2B, 0xEE, 0xC3, 0xFD, 0x79, 0x17, 0x40, 0x7C,
	0x06, 0xDE, 0xC4, 0x70, 0x5A, 0x33, 0x11, 0xD6, 0xCC, 0xD1, 0x5D, 0x40, 0xA4, 0x9D, 0xC8, 0x37,
	0xEB, 0x71, 0xF0, 0x00, 0x2D, 0xA3, 0xC8, 0xF0, 0x33, 0x01, 0x28, 0x30, 0x7C, 0x81, 0x49, 0xCB,
	0xCF, 0x5A, 0xC1, 0x2A, 0x6B, 0xAC, 0x4D, 0x43, 0x44, 0x0E, 0x9F, 0xD4, 0x93, 0x6D, 0x33, 0x77,
	0xBA, 0x11, 0x68, 0x7C, 0x24, 0x00, 0xDD, 0x56, 0xCA, 0x12, 0x6C, 0xA9, 0xD6, 0x4D, 0x2C, 0x10,
	0x2B, 0x79, 0x32, 0x5D, 0x28, 0x85, 0xFA, 0xC9, 0xF6, 0x72, 0xBF, 0x64, 0x83, 0x15, 0x99, 0x57,
	0x00, 0xFA, 0xE9, 0x1C, 0x62, 0x83, 0xA0, 0x1E, 0x7E, 0xE0, 0xE2, 0xA0, 0x26, 0x2A, 0x33, 0x69,
	0x76, 0xF5, 0x1A, 0x35, 0xAD, 0x31, 0x3D, 0x90, 0x6E, 0x97, 0x3F, 0x92, 0xBB, 0x8A, 0x54, 0x47,
	0xEB, 0x01, 0xED, 0x8F, 0x27, 0x10, 0xAB, 0x56, 0x24, 0x43, 0x8A, 0xC3, 0x6B, 0x5D, 0xCD, 0x7A,
	0xC1, 0x70, 0x6A, 0x79, 0x01, 0xBA, 0x24, 0x40, 0xC0, 0xEE, 0x06, 0xD8, 0x0D, 0x40, 0xA7, 0x1A,
	0x72, 0xB1, 0x68, 0x8F, 0x16, 0x1C, 0x2D, 0x5A, 0xB4, 0x60, 0xAE, 0x61, 0x0E, 0x95, 0x20, 0x09,
	0xD6, 0xAC, 0x36, 0x37, 0x49, 0xDD, 0x24, 0x79, 0x93, 0xD4, 0xFD, 0x9A, 0xF1, 0x5E, 0xD3, 0x62,
	0x8A, 0x97, 0x52, 0x4E, 0x24, 0xC4, 0xBE, 0x12, 0x50, 0x82, 0x76, 0x0C, 0x1D, 0x08, 0x0B, 0xA1,
	0xAC, 0x6F, 0xC0, 0xD6, 0x9A, 0x19, 0x52, 0x2B, 0xA5, 0x50, 0xCA, 0x0A, 0xC3, 0x84, 0xAC, 0xA1,
	0xEA, 0xD3, 0x8F, 0xB4, 0xA9, 0xE6, 0xB0, 0xB6, 0x7A, 0x6C, 0x6B, 0xB5, 0x2D, 0xB5, 0xA0, 0xC0,
	0x08, 0x2C, 0xC8, 0xE4, 0xB8, 0x77, 0x17, 0x09, 0xCD, 0x73, 0x58, 0x39, 0x6E, 0xFC, 0x8E, 0xF7,
	0x69, 0x69, 0x98, 0x94, 0xDB, 0xE2, 0x0B, 0x71, 0xD9, 0x86, 0xC9, 0x19, 0x4A, 0x8E, 0x25, 0x6A,
	0x6C, 0x40, 0xDF, 0x1E, 0x8F, 0x9C, 0xDE, 0xDE, 0x93, 0xBD, 0x4D, 0x4B, 0xF4, 0x4C, 0x27, 0x6E,
	0xD3, 0xF6, 0x76, 0x9B, 0x36, 0xDD, 0x11, 0xB6, 0x2F, 0xDA, 0xDC, 0x9B, 0x86, 0xED, 0xCF, 0xF9,
	0x8A, 0x27, 0x37, 0x20, 0xFA, 0xF7, 0xE2, 0x58, 0xFF, 0xBB, 0x18, 0xE1, 0x41, 0xFE, 0x5D, 0x3D,
	0x68, 0x61, 0xED, 0x63, 0xB5, 0x12, 0xD2, 0xBB, 0x40, 0x28, 0xCE, 0xB6, 0xFD, 0x73, 0x7D, 0x13,
	0x92, 0x98, 0x11, 0x0B, 0x10, 0x5A, 0xBF, 0x42, 0x3F, 0x3B, 0x05, 0x18, 0x39, 0x6A, 0xE2, 0xF8,
	0x37, 0x00, 0x00, 0x00, 0x00, 0x49, 0x45, 0x4E, 0x44, 0xAE, 0x42, 0x60, 0x82
};

std::uint8_t weapons[] = {
	0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A, 0x00, 0x00, 0x00, 0x0D, 0x49, 0x48, 0x44, 0x52,
	0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x20, 0x08, 0x03, 0x00, 0x00, 0x00, 0x44, 0xA4, 0x8A,
	0xC6, 0x00, 0x00, 0x00, 0x04, 0x67, 0x41, 0x4D, 0x41, 0x00, 0x00, 0xB1, 0x8F, 0x0B, 0xFC, 0x61,
	0x05, 0x00, 0x00, 0x00, 0x01, 0x73, 0x52, 0x47, 0x42, 0x00, 0xAE, 0xCE, 0x1C, 0xE9, 0x00, 0x00,
	0x00, 0x36, 0x50, 0x4C, 0x54, 0x45, 0x47, 0x70, 0x4C, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x86, 0x52, 0xCC, 0x5B,
	0x00, 0x00, 0x00, 0x11, 0x74, 0x52, 0x4E, 0x53, 0x00, 0xA9, 0xD5, 0x50, 0x98, 0x1F, 0x5E, 0x0A,
	0xC1, 0xF0, 0xE2, 0x38, 0x05, 0xB5, 0x70, 0xC8, 0x80, 0xF8, 0xD9, 0xC6, 0xB1, 0x00, 0x00, 0x00,
	0xD1, 0x49, 0x44, 0x41, 0x54, 0x38, 0xCB, 0x95, 0xD3, 0x01, 0x8A, 0xC4, 0x20, 0x0C, 0x05, 0xD0,
	0x68, 0x8C, 0xF6, 0x6B, 0x6D, 0x9B, 0xFB, 0x5F, 0x76, 0xB5, 0xDD, 0x59, 0x18, 0x1A, 0x03, 0x5B,
	0x28, 0x0A, 0xEF, 0x47, 0x54, 0x22, 0xD1, 0xFA, 0x2B, 0x57, 0xAC, 0xC9, 0xE1, 0x84, 0x78, 0xB0,
	0x2E, 0xFD, 0x42, 0x64, 0xA2, 0xA3, 0x2E, 0x58, 0x2A, 0xF2, 0x1C, 0x71, 0xD9, 0x9E, 0x35, 0xDC,
	0x23, 0xEB, 0x6E, 0x7A, 0xD2, 0xFC, 0x4C, 0x60, 0xEF, 0x31, 0x41, 0x3E, 0x0B, 0xED, 0x76, 0x7D,
	0xF8, 0x9D, 0xE9, 0x61, 0x79, 0xD0, 0x86, 0x27, 0xD1, 0xAD, 0x23, 0xC8, 0x39, 0x4E, 0x2E, 0xF7,
	0x1A, 0x59, 0xC5, 0x28, 0xC7, 0x09, 0x9E, 0x89, 0x3E, 0xFE, 0xFC, 0xBE, 0x3C, 0xC4, 0x36, 0x0A,
	0x07, 0x08, 0x92, 0xBE, 0xAF, 0xA0, 0xE8, 0xF6, 0xEC, 0x7D, 0x24, 0x9A, 0xA6, 0x95, 0xCF, 0x04,
	0x17, 0xCF, 0x47, 0x02, 0xBE, 0x13, 0xC5, 0xEA, 0xBB, 0xBC, 0x0F, 0xF8, 0xE5, 0x84, 0xE0, 0xFB,
	0x09, 0xDF, 0x37, 0x2D, 0xFF, 0x74, 0xA9, 0xBE, 0xD3, 0x06, 0xDF, 0x5B, 0x55, 0xF6, 0x3C, 0xA0,
	0xB7, 0xBF, 0xC6, 0x30, 0x9C, 0x46, 0x39, 0x7F, 0x12, 0x96, 0x8F, 0x06, 0x2C, 0x31, 0xC9, 0x9D,
	0x30, 0x7D, 0xB6, 0xD8, 0x9D, 0x60, 0x3A, 0x6D, 0x9F, 0x89, 0x3D, 0x26, 0xD6, 0x8A, 0xB2, 0x7A,
	0x65, 0x23, 0xD1, 0x6B, 0xEF, 0xCE, 0x33, 0x0E, 0x60, 0xAB, 0x41, 0xBF, 0x76, 0x1A, 0x56, 0xEB,
	0xFF, 0x00, 0x8D, 0xAE, 0x08, 0x47, 0xA6, 0xF0, 0x59, 0xE2, 0x00, 0x00, 0x00, 0x00, 0x49, 0x45,
	0x4E, 0x44, 0xAE, 0x42, 0x60, 0x82
};

std::uint8_t logo[] = {
	0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A, 0x00, 0x00, 0x00, 0x0D, 0x49, 0x48, 0x44, 0x52,
	0x00, 0x00, 0x00, 0xDC, 0x00, 0x00, 0x00, 0x26, 0x08, 0x03, 0x00, 0x00, 0x00, 0x98, 0x8D, 0x05,
	0xCC, 0x00, 0x00, 0x00, 0x04, 0x67, 0x41, 0x4D, 0x41, 0x00, 0x00, 0xB1, 0x8F, 0x0B, 0xFC, 0x61,
	0x05, 0x00, 0x00, 0x00, 0x01, 0x73, 0x52, 0x47, 0x42, 0x00, 0xAE, 0xCE, 0x1C, 0xE9, 0x00, 0x00,
	0x00, 0x42, 0x50, 0x4C, 0x54, 0x45, 0x47, 0x70, 0x4C, 0xFF, 0xFF, 0xFF, 0xFF, 0xB2, 0xB4, 0xF4,
	0x29, 0x2F, 0xFF, 0x2C, 0x33, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x12, 0x12,
	0x12, 0xFF, 0xFF, 0xFF, 0xFF, 0x2C, 0x33, 0xFF, 0x2C, 0x33, 0xFF, 0x2C, 0x33, 0x12, 0x12, 0x12,
	0xFF, 0x2C, 0x33, 0x14, 0x12, 0x11, 0xFF, 0xFF, 0xFF, 0xFF, 0x2C, 0x34, 0x29, 0x12, 0x12, 0x01,
	0x0C, 0x0B, 0x75, 0x18, 0x1A, 0xB8, 0x1F, 0x24, 0x70, 0x7A, 0xC9, 0xB6, 0x00, 0x00, 0x00, 0x0F,
	0x74, 0x52, 0x4E, 0x53, 0x00, 0xE7, 0x11, 0xF3, 0xBB, 0x34, 0x9B, 0xBC, 0xC2, 0x6F, 0x5C, 0x7C,
	0x27, 0x80, 0x99, 0x32, 0x15, 0x63, 0x87, 0x00, 0x00, 0x02, 0x97, 0x49, 0x44, 0x41, 0x54, 0x68,
	0xDE, 0xED, 0x59, 0xD9, 0x92, 0xC2, 0x20, 0x10, 0x84, 0xDC, 0x24, 0xAE, 0x18, 0x08, 0xFF, 0xFF,
	0xAB, 0xCB, 0x95, 0x30, 0xC8, 0x40, 0xB2, 0xEE, 0x93, 0x54, 0xBA, 0xCA, 0x52, 0x6B, 0x2A, 0x83,
	0x4D, 0xCF, 0x05, 0x12, 0x52, 0x37, 0x7E, 0xA6, 0x13, 0xFC, 0x7C, 0x31, 0x37, 0x7E, 0x8A, 0xEF,
	0x65, 0x37, 0x9D, 0x93, 0x9B, 0x6E, 0x72, 0x37, 0xB9, 0x9B, 0xDC, 0x4D, 0xEE, 0x8F, 0xE4, 0x24,
	0xE7, 0x82, 0xDB, 0x97, 0x7F, 0xAB, 0x87, 0x9C, 0x70, 0x74, 0x04, 0xF8, 0x22, 0xEA, 0x20, 0xA7,
	0xC9, 0xC8, 0x6D, 0x75, 0xAA, 0x39, 0xF0, 0x7A, 0xC8, 0x99, 0xA0, 0x5C, 0x57, 0x21, 0x05, 0x97,
	0x3B, 0xB8, 0x10, 0x3B, 0xBD, 0x6F, 0x27, 0x67, 0x84, 0x5B, 0x95, 0x34, 0x9A, 0x6D, 0x1A, 0x4A,
	0xB5, 0xF6, 0x6B, 0xA2, 0x5C, 0xC3, 0xC6, 0x14, 0xBD, 0x36, 0xF4, 0x23, 0x0E, 0x56, 0x34, 0x35,
	0x4B, 0xD7, 0x2D, 0xFA, 0xE9, 0xB9, 0x4B, 0xD1, 0x84, 0x55, 0x3F, 0x73, 0xEE, 0xC9, 0x19, 0x8D,
	0x56, 0x0D, 0x69, 0x28, 0x06, 0xEC, 0xB9, 0x17, 0xC8, 0x31, 0xFA, 0x42, 0x40, 0x7B, 0x32, 0xBC,
	0x70, 0x0C, 0xA4, 0x64, 0x9A, 0xF5, 0x16, 0xAE, 0x33, 0x21, 0xCB, 0x8A, 0x20, 0xB0, 0xFB, 0xCC,
	0x79, 0x50, 0x4E, 0x2A, 0xE3, 0x6F, 0x8B, 0xD9, 0x6D, 0xF2, 0x2D, 0x2C, 0x9B, 0x9C, 0xAB, 0x9C,
	0x81, 0xE5, 0x9F, 0x31, 0x26, 0xBB, 0x4A, 0x43, 0x9E, 0x2B, 0x8A, 0xE7, 0xC9, 0xAA, 0x65, 0xE7,
	0x30, 0xE7, 0xA4, 0xD9, 0x44, 0x1D, 0x88, 0x92, 0xAB, 0xC3, 0x7B, 0x2B, 0x5D, 0x61, 0x39, 0xC8,
	0xB1, 0x8C, 0xAF, 0x9E, 0xE5, 0xD7, 0x28, 0x98, 0x66, 0x27, 0x50, 0x87, 0x73, 0x33, 0x92, 0x96,
	0x56, 0x3D, 0x71, 0x0E, 0xAB, 0xA5, 0xE4, 0xC6, 0x9F, 0x29, 0x93, 0x40, 0x3C, 0x53, 0x61, 0xB4,
	0x6D, 0x8A, 0xE2, 0x83, 0xC1, 0x8C, 0xED, 0xAD, 0x33, 0xC4, 0x40, 0xF2, 0xCF, 0x1C, 0x78, 0x42,
	0x7D, 0x20, 0x9C, 0xA4, 0x17, 0x3C, 0x14, 0x4C, 0xB0, 0xA0, 0x68, 0x1E, 0x2E, 0x10, 0xCD, 0xA7,
	0xD6, 0x93, 0x53, 0x4E, 0xBA, 0x83, 0x9C, 0xCD, 0xB8, 0x1E, 0x3E, 0x6D, 0xB7, 0x6E, 0x44, 0x0C,
	0x24, 0x7A, 0x06, 0x4B, 0x76, 0x42, 0x5A, 0xA8, 0x0F, 0x84, 0x93, 0x34, 0xBF, 0x2A, 0xB9, 0x60,
	0x82, 0x61, 0x29, 0x4C, 0x2F, 0xD0, 0x6C, 0x4C, 0x0F, 0x90, 0x72, 0x0F, 0x4D, 0x19, 0x15, 0x14,
	0x2B, 0x13, 0x45, 0xB6, 0x0E, 0x31, 0xC4, 0xD2, 0xA2, 0x51, 0xF3, 0x88, 0xF4, 0x49, 0x24, 0x5D,
	0xF2, 0xAB, 0x92, 0x73, 0x53, 0x14, 0x96, 0x3E, 0x1A, 0x95, 0xEE, 0x03, 0xA6, 0xD9, 0x79, 0xF1,
	0x5C, 0x49, 0x99, 0xA0, 0x4C, 0x43, 0x4F, 0xF1, 0x94, 0x1B, 0x50, 0xF7, 0x58, 0x56, 0xF8, 0xAD,
	0x5E, 0x9C, 0x3E, 0xB1, 0x4C, 0x41, 0xD2, 0x47, 0xB4, 0x6A, 0xDE, 0xF9, 0x70, 0x65, 0xFC, 0x12,
	0xE2, 0x28, 0x24, 0x4A, 0x89, 0xAD, 0xF5, 0x25, 0x05, 0x90, 0x1B, 0x6D, 0x84, 0x25, 0xDC, 0x68,
	0x29, 0xF4, 0x47, 0xA4, 0x73, 0x78, 0x53, 0xE7, 0xF4, 0x59, 0xA0, 0x4C, 0x41, 0xD2, 0x36, 0xF2,
	0x50, 0x70, 0xCE, 0x2E, 0xCD, 0x96, 0x52, 0xA4, 0x15, 0x4B, 0x57, 0xCF, 0x40, 0x8E, 0xE6, 0x7A,
	0xCA, 0x67, 0x59, 0xE1, 0xF5, 0x49, 0x33, 0x6F, 0x89, 0x0A, 0xCD, 0x3F, 0x52, 0x2E, 0xE4, 0x9C,
	0x10, 0x71, 0x0B, 0xF7, 0x25, 0x25, 0x90, 0x73, 0x11, 0x1E, 0x95, 0x06, 0x1A, 0x52, 0xEE, 0x85,
	0xCE, 0x08, 0x05, 0x93, 0xD7, 0xC7, 0x65, 0x5E, 0x34, 0x9B, 0x78, 0xBA, 0x83, 0x9D, 0x7E, 0xD8,
	0x47, 0xCE, 0x93, 0x23, 0x8F, 0xE0, 0x52, 0xBD, 0x51, 0xDB, 0x60, 0x9F, 0x43, 0x22, 0xBC, 0xD4,
	0xE5, 0x58, 0xBE, 0x47, 0x31, 0xA0, 0xCF, 0x9C, 0xE9, 0x72, 0x8F, 0x7F, 0x39, 0x4F, 0x0F, 0xAB,
	0xC2, 0xB5, 0x72, 0x9F, 0x77, 0xB6, 0xB0, 0xC0, 0x9C, 0x1B, 0xF1, 0x2E, 0x47, 0x33, 0x33, 0x50,
	0x9F, 0x49, 0xB9, 0xDD, 0xD4, 0x39, 0x7D, 0xF0, 0xF1, 0xA4, 0x5D, 0x2E, 0x38, 0x2F, 0x98, 0x92,
	0x9C, 0x33, 0xE3, 0xB3, 0xF4, 0x25, 0x53, 0x1C, 0x07, 0x83, 0x83, 0x9C, 0x1B, 0x75, 0x1A, 0xA4,
	0x5A, 0x35, 0x18, 0x05, 0x9A, 0x9F, 0x9C, 0x68, 0x68, 0xD4, 0x3E, 0xE5, 0x92, 0xB9, 0xF2, 0xE1,
	0x7F, 0x7A, 0xC9, 0x79, 0xC9, 0x84, 0x5C, 0x33, 0x98, 0x06, 0xEE, 0x04, 0xE3, 0xF0, 0x50, 0x57,
	0xC3, 0x35, 0x83, 0xD7, 0xCE, 0x12, 0x83, 0xB7, 0x0C, 0xB5, 0x5C, 0x10, 0xB9, 0x93, 0xF8, 0x71,
	0xE1, 0xE0, 0x3F, 0x55, 0x77, 0xFB, 0x25, 0x6A, 0xBC, 0xDA, 0x13, 0xC7, 0xF5, 0xD7, 0x7D, 0x6F,
	0x79, 0x93, 0xBB, 0xC9, 0xDD, 0xE4, 0xFE, 0x8A, 0xAA, 0xFF, 0x7C, 0xAC, 0xFA, 0x6F, 0xE3, 0x8A,
	0xF1, 0x0B, 0x5F, 0xBE, 0x9E, 0x5A, 0x84, 0x62, 0x82, 0x6F, 0x00, 0x00, 0x00, 0x00, 0x49, 0x45,
	0x4E, 0x44, 0xAE, 0x42, 0x60, 0x82
};

std::uint8_t visuals[] = {
	0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A, 0x00, 0x00, 0x00, 0x0D, 0x49, 0x48, 0x44, 0x52,
	0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x20, 0x08, 0x03, 0x00, 0x00, 0x00, 0x44, 0xA4, 0x8A,
	0xC6, 0x00, 0x00, 0x00, 0x04, 0x67, 0x41, 0x4D, 0x41, 0x00, 0x00, 0xB1, 0x8F, 0x0B, 0xFC, 0x61,
	0x05, 0x00, 0x00, 0x00, 0x01, 0x73, 0x52, 0x47, 0x42, 0x00, 0xAE, 0xCE, 0x1C, 0xE9, 0x00, 0x00,
	0x00, 0x39, 0x50, 0x4C, 0x54, 0x45, 0x47, 0x70, 0x4C, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7D,
	0x3C, 0x96, 0x4D, 0x00, 0x00, 0x00, 0x12, 0x74, 0x52, 0x4E, 0x53, 0x00, 0xCC, 0x4F, 0x62, 0xAA,
	0x40, 0xD8, 0xE6, 0x18, 0x08, 0x2B, 0xB7, 0x73, 0x35, 0x99, 0x22, 0x87, 0xF4, 0x06, 0x9B, 0x48,
	0xA6, 0x00, 0x00, 0x01, 0x22, 0x49, 0x44, 0x41, 0x54, 0x38, 0xCB, 0x9D, 0x53, 0x59, 0xB2, 0xC4,
	0x20, 0x08, 0x74, 0x41, 0x31, 0x6A, 0xB6, 0xBE, 0xFF, 0x61, 0x07, 0xC9, 0xA4, 0x62, 0xB6, 0x7A,
	0xF5, 0x86, 0x1F, 0x50, 0x10, 0xB0, 0x69, 0x8C, 0x39, 0xC9, 0x10, 0xAD, 0x79, 0x96, 0x34, 0x8D,
	0xAA, 0x80, 0xA1, 0xE9, 0x30, 0xA5, 0x4B, 0x80, 0x03, 0xF7, 0x01, 0x2B, 0x82, 0xB9, 0xE6, 0x46,
	0x6D, 0x6A, 0xD5, 0xB8, 0x05, 0xF7, 0x4A, 0x01, 0xD0, 0x14, 0x9A, 0x00, 0xC8, 0xF7, 0x2E, 0xAA,
	0x7F, 0xB6, 0xFF, 0x27, 0x73, 0x70, 0x2E, 0xCC, 0x6F, 0x1F, 0xF5, 0xC4, 0x50, 0x61, 0xF2, 0xE9,
	0xDE, 0x23, 0xA9, 0x2F, 0x12, 0x45, 0x35, 0x68, 0x3C, 0xB9, 0x33, 0x75, 0xB7, 0x63, 0xD9, 0x0E,
	0x5D, 0xA9, 0x2A, 0x69, 0x2B, 0x63, 0xD9, 0xCF, 0x93, 0x1E, 0x15, 0x18, 0xC5, 0x48, 0x5E, 0x2C,
	0xC6, 0xA3, 0xE8, 0x73, 0x4D, 0x62, 0xE1, 0x24, 0x0A, 0x45, 0x41, 0x99, 0x19, 0x1C, 0x1A, 0x36,
	0xD2, 0xD8, 0x6C, 0x01, 0x2B, 0x3A, 0x63, 0x15, 0xF4, 0x57, 0xC4, 0xA4, 0xFE, 0x76, 0x15, 0x10,
	0x25, 0x17, 0x23, 0xC6, 0x66, 0x18, 0x6E, 0x50, 0x26, 0x0B, 0x4E, 0x62, 0x4E, 0x2D, 0x8F, 0x6F,
	0x2A, 0xB4, 0x11, 0x44, 0x48, 0x15, 0x92, 0x1A, 0xA6, 0x29, 0x96, 0xB9, 0x1D, 0x01, 0xEE, 0x29,
	0x20, 0xAF, 0xDA, 0xCB, 0x5E, 0xC2, 0xDA, 0x6B, 0x09, 0x93, 0xBB, 0x26, 0xB3, 0xA0, 0x64, 0xE7,
	0x6F, 0x93, 0x81, 0xB5, 0x49, 0x0D, 0x3C, 0xBE, 0x19, 0x94, 0x28, 0x45, 0x2A, 0x2C, 0xFB, 0x37,
	0x95, 0x1F, 0x88, 0x3D, 0x50, 0x0B, 0xD8, 0x77, 0x40, 0x75, 0xE8, 0x2A, 0x4D, 0x46, 0xEA, 0x0E,
	0xC7, 0xB0, 0xB6, 0x10, 0x4B, 0x64, 0x37, 0x77, 0xB8, 0x73, 0xA1, 0x96, 0x7D, 0xDC, 0xA5, 0xBE,
	0x70, 0x62, 0xC8, 0x4E, 0x24, 0x0F, 0x3F, 0xD2, 0xCD, 0xBB, 0xCE, 0x7E, 0x20, 0xED, 0xB8, 0xD1,
	0x7E, 0x78, 0xA5, 0xFD, 0x77, 0x71, 0xF8, 0x6D, 0x71, 0xFE, 0x5C, 0xBD, 0x7C, 0x5E, 0x5E, 0x37,
	0xA5, 0x97, 0x8F, 0xDE, 0xD6, 0xFF, 0x03, 0xB4, 0x88, 0x11, 0xBE, 0xCB, 0x5B, 0x3F, 0xB3, 0x00,
	0x00, 0x00, 0x00, 0x49, 0x45, 0x4E, 0x44, 0xAE, 0x42, 0x60, 0x82
};

#endif // !BYTES_HPP