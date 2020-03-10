/**
 * vim: set ts=4 :
 * =============================================================================
 * SourceMod Environment Variables
 * Copyright (C) 2020 CrazyHackGUT aka Kruzya.  All rights reserved.
 * =============================================================================
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License, version 3.0, as published by the
 * Free Software Foundation.
 * 
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * As a special exception, AlliedModders LLC gives you permission to link the
 * code of this program (as well as its derivative works) to "Half-Life 2," the
 * "Source Engine," the "SourcePawn JIT," and any Game MODs that run on software
 * by the Valve Corporation.  You must obey the GNU General Public License in
 * all respects for all other code used.  Additionally, AlliedModders LLC grants
 * this exception to all derivative works.  AlliedModders LLC defines further
 * exceptions, found in LICENSE.txt (as of this writing, version JULY-31-2007),
 * or <http://www.sourcemod.net/license.php>.
 *
 * Version: $Id$
 */

#if defined __env_variables_included
  #endinput
#endif
#define __env_variables_included

/**
 * Retrieves a environment value (if exists), writes value to passed buffer.
 *
 * @param   szName          The environment variable name.
 * @param   szBuffer        Buffer where value should be written.
 * @param   iBufferLength   Maximum size of the buffer.
 * @return                  The written bytes count.
 */
native int GetEnvironmentVariable(const char[] szName, char[] szBuffer, int iBufferLength);

/**
 * Do not edit below this line!
 */
public Extension __ext_env_variables =
{
	name = "env_variables",
	file = "env_variables.ext",
#if defined AUTOLOAD_EXTENSIONS
	autoload = 1,
#else
	autoload = 0,
#endif
#if defined REQUIRE_EXTENSIONS
	required = 1,
#else
	required = 0,
#endif
};
