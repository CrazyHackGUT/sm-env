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

#include "natives.h"
#include <cstdlib>

static cell_t sm_getenv(SourcePawn::IPluginContext *pContext, const cell_t *params)
{
    char *name;
    pContext->LocalToString(params[1], &name);

    char *value = getenv(name);

    cell_t is_success = (value != NULL) ? 1 : 0;
    if (params[0] > 3)
    {
        cell_t *addr;
        pContext->LocalToPhysAddr(params[4], &addr);
        *addr = is_success;
    }

    if (value != NULL)
    {
        size_t numBytes;
        pContext->StringToLocalUTF8(params[2], params[3], value, &numBytes);

        return numBytes;
    }

    return 0;
}
