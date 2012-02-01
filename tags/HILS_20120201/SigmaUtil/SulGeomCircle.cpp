// SulGeomCircle.cpp

#include "stdafx.h"
#include "SulGeomCircle.h"

CSulGeomCircle::CSulGeomCircle( float radius ) :
osg::Group()
{
	m_ofs.set(0,0,0);
	m_radius = radius;
	m_segments = 32;
	m_width = 2.0f;
	createDrawable();
}

void CSulGeomCircle::createDrawable()
{
	// remove any children we might have
	if ( getNumChildren() )
		removeChildren( 0, getNumChildren() );

	m_rLine = new CSulGeomLineStrip;
	addChild( m_rLine );

	sigma::VEC_VEC3::vector	vecPos;

	for ( sigma::uint32 i=0; i<m_segments; i++ )
	{
		double d = ((2.0*osg::PI)/(m_segments-1)) * (double)i;

		double x = cos( d );
		double y = sin( d );

		osg::Vec3 pos = osg::Vec3( x*m_radius, y*m_radius, 0 )+m_ofs;
		vecPos.push_back( pos );
	}

	m_rLine->setLines( vecPos );
	m_rLine->setWidth ( m_width );
}

void CSulGeomCircle::setOffset( const osg::Vec3& ofs )
{
	m_ofs = ofs;
	createDrawable();
}