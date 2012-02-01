// SulGeomGeode.cpp

#include "stdafx.h"
#include "SulGeomGeode.h"
#include <osg/depth>

void CSulGeomGeode::enableBlend()
{
	getOrCreateStateSet()->setMode( GL_BLEND, osg::StateAttribute::ON );
}

void CSulGeomGeode::zbuffer( bool bEnable )
{
	osg::Depth* depth = new osg::Depth;
	depth->setWriteMask( bEnable?true:false );
	getOrCreateStateSet()->setAttributeAndModes( depth, osg::StateAttribute::ON );
}

void CSulGeomGeode::enableDebugTexture()
{
	int s = 64;
	unsigned char* pData = new unsigned char[s*s*3];
	for ( int y=0; y<s; y++ )
		for ( int x=0; x<s; x++ )
		{
			unsigned char  c = (( ((y&0x8)==0) ^ (((x&0x8))==0) ))*255;

			pData[x*3+y*s*3+0] = c;
			pData[x*3+y*s*3+1] = c;
			pData[x*3+y*s*3+2] = c;
 		}

	osg::Image* pImage = new osg::Image;
	pImage->setImage(
		s, s, 1,								// 1=r? depth perhaps?
		GL_RGB,									// internal format
        GL_RGB,GL_UNSIGNED_BYTE,				// pixelformat, type
        pData,									// data
        osg::Image::USE_NEW_DELETE,				// mode
        1 );									// packing

	osg::Texture2D* pTex = new osg::Texture2D;
	pTex->setImage( pImage );

	getOrCreateStateSet()->setTextureAttributeAndModes( 0, pTex, osg::StateAttribute::ON );
}