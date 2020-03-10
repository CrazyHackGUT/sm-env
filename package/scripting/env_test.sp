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
#include <sourcemod>
#include <env_variables>

public void OnPluginStart()
{
    EmptyLines(10);

    char szValue[256];
    PrintToServer("Testing getting variables...");

    RunEnvironmentVariableCase("PATH", szValue, sizeof(szValue));
    RunEnvironmentVariableCase("SOURCEMOD", szValue, sizeof(szValue));
    RunEnvironmentVariableCase("METAMOD", szValue, sizeof(szValue));

    EmptyLines(10);
}

void RunEnvironmentVariableCase(const char[] szName, char[] szBuffer, int iBufferLength)
{
    szBuffer[0] = 0;

    int iLength = GetEnvironmentVariable(szName, szBuffer, iBufferLength);
    PrintToServer("%%%s%% (%d bytes) = %s", szName, iLength, szBuffer);
}

void EmptyLines(int iCount)
{
    for (int i = 0; i < iCount; ++i)
    {
        EmptyLine();
    }
}

void EmptyLine()
{
    PrintToServer(" ");
}
