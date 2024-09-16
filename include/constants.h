/* 
 * This file is part of alaman (https://github.com/strokegmd/alaman).
 * Copyright (C) 2024  strokegmd.
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __CONSTANTS_H
#define __CONSTANTS_H

/* 1MB is maximum length for big strings. */
#define BIG_STRING_LENGTH 1024 * 1024

/* 64KB is maximum length for default strings. */
#define STRING_LENGTH 65536

/* Macro for removing unused warnings. */
#define UNUSED(x) (void)(x)

/* Regex used for detecting URLs in HTML string. */
#define URL_REGEX "href=[\'\"]?([^\'\" >]+)"

/* Base URL in Arch Linux Archive for finding package. */
#define ALA_BASE_URL "http://archive.archlinux.org/packages/%c/%s"

/* Base URL in Arch Linux Archive for downloading package. */
#define ALA_DOWNLOAD_URL "http://archive.archlinux.org/packages/%c/%.*s"

/* Base command for installing Arch Linux Archive package via pacman. */
#define PACMAN_BASE_CMD "pacman --noconfirm -U %s"

/* Unallowed symbols in URLs. */
#define URL_UNALLOWED1 "sig"
#define URL_UNALLOWED2 "../"

#endif
