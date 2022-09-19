/*
 * moveDroidStdout.cpp
 *
 *  Created on: Nov 29, 2020
 *      Author: Gabriel Dimitriu
 * Copyright (C) 2020 Gabriel Dimitriu
 * All rights reserved.
 *
 * This file is part of Robotics project.

 * Robotics is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.

 * Robotics is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public
 * License along with Robotics; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */


#include <iostream>
#include <CManualDroid.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <CBLECommand.h>
#include <CMoveCommand.h>
#include <CSettingCommand.h>
#include <CLoggerBle.h>
#include <CLoggerFile.h>

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr<<"Usage="<<argv[0]<<" configFile\n";
		exit(1);
	}
	CLogger *moveLogger = new CLoggerFile("/var/log/droid/move.log",'a');
	CLogger *settingsLogger = new CLoggerFile("/var/log/droid/settings.log",'a');
	moveLogger->setType(2);
	settingsLogger->setType(2);
	CBLECommand *commStd = new CBLECommand(new CMoveCommand(moveLogger), new CSettingCommand(settingsLogger));
	vector<CCommCommands *> *commands = new vector<CCommCommands *>();
	commands->push_back(commStd);
	CManualDroid *droid = new CManualDroid(argv[1], 0, commands);
	droid->startReceiving();
	delete droid;
}
