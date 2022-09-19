/*
 * CFactoryFixDigitalSensor.cpp
 *
 *  Created on: Oct 16, 2020
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

#include "CFactoryFixDigitalSensor.h"
#include <CFixDigitalSensor.h>
#include <string.h>
#include <CLoggerStdout.h>
#include <CLoggerBleHC5.h>
#include <CFactoryLogger.h>

CFactoryFixDigitalSensor::CFactoryFixDigitalSensor(
		CSettingLoading *settingsLoader, CLogger *logger) :
		CFactorySensor(logger) {
	m_settingsLoader = settingsLoader;
}

CFactoryFixDigitalSensor::~CFactoryFixDigitalSensor() {
	// TODO Auto-generated destructor stub
}

CGenericSensor* CFactoryFixDigitalSensor::createSensor() {
	CFactoryLogger *loggerFactory = new CFactoryLogger(m_settingsLoader);
	CLogger *logger = loggerFactory->createLogger(m_logger);
	delete loggerFactory;
	int pin;
	int edge;
	int position;
	int isCollision;
	int relativePosition;
	sscanf(m_settingsLoader->getLine(), "%d %d %d %d %d", &pin, &edge, &position,
			&isCollision, &relativePosition);
	return new CFixDigitalSensor(pin, edge, position, isCollision, logger, relativePosition);
}

