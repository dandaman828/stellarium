/*
 * Copyright (C) 2012 Alexander Wolf
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Suite 500, Boston, MA  02110-1335, USA.
 */

#ifndef _PULSAR_HPP_
#define _PULSAR_HPP_ 1

#include <QVariant>
#include <QString>
#include <QStringList>
#include <QFont>
#include <QList>
#include <QDateTime>

#include "StelObject.hpp"
#include "StelTextureTypes.hpp"
#include "StelPainter.hpp"
#include "StelFader.hpp"

class StelPainter;

//! @class Pulsar
//! A Pulsar object represents one pulsar on the sky.
//! Details about the Pulsars are passed using a QVariant which contains
//! a map of data from the json file.

class Pulsar : public StelObject
{
	friend class Pulsars;
public:
	//! @param id The official designation for a pulsar, e.g. "PSR 1919+21"
	Pulsar(const QVariantMap& map);
	~Pulsar();

	//! Get a QVariantMap which describes the pulsar. Could be used to
	//! create a duplicate.
	QVariantMap getMap(void);

	virtual QString getType(void) const
	{
		return "Pulsar";
	}
	virtual float getSelectPriority(const StelCore* core) const;

	//! Get an HTML string to describe the object
	//! @param core A pointer to the core
	//! @flags a set of flags with information types to include.
	virtual QString getInfoString(const StelCore* core, const InfoStringGroup& flags) const;
	virtual Vec3f getInfoColor(void) const;
	virtual Vec3d getJ2000EquatorialPos(const StelCore*) const
	{
		return XYZ;
	}
	virtual float getVMagnitude(const StelCore* core, bool withExtinction=false) const;
	virtual double getAngularSize(const StelCore* core) const;
	virtual QString getNameI18n(void) const
	{
		return designation;
	}
	virtual QString getEnglishName(void) const
	{
		return designation;
	}

	void update(double deltaTime);

private:
	bool initialized;

	Vec3d XYZ;                         // holds J2000 position	

	static StelTextureSP hintTexture;
	static StelTextureSP markerTexture;

	void draw(StelCore* core, StelPainter& painter);

	// Pulsar
	QString designation;		//! The designation of the pulsar (J2000 pulsar name)
	float RA;			//! J2000 right ascension
	float DE;			//! J2000 declination
	double distance;		//! Adopted distance of pulsar in kpc
	double period;			//! Barycentric period in seconds	
	int ntype;			//! Octal code for pulsar type

	LinearFader labelsFader;
};

#endif // _PULSAR_HPP_
