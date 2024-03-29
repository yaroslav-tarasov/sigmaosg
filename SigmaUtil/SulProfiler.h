// SulProfiler.h

#ifndef __SULPROFILER_H__
#define __SULPROFILER_H__

#include "SulString.h"
#include "SulProfilerData.h"
#include "SulGeomBarChart.h"
#include "SulExport.h"
#include <osg/referenced>
#include <osg/geode>

class SUL_EXPORT CSulProfiler : public osg::Referenced
{
public:
			CSulProfiler();

	CSulGeomBarChart*	getChart();

	void	create( const CSulString& name, const CSulString& groupName="" );

	void	start( const CSulString& name, const CSulString& groupName="" );
	void	end( const CSulString& name, const CSulString& groupName="" );

	void	frameUpdate();

	void	dump();

private:
	void	dumpData( CSulProfilerData* pData );

private:
	typedef std::map< CSulString, osg::ref_ptr<CSulProfilerData> >	MAP_DATA;
	typedef std::map< CSulString, MAP_DATA*>						MAP_GROUP;

	MAP_GROUP	m_mapGroup;

	osg::ref_ptr<CSulGeomBarChart>	m_rChart;
};

#endif // __SULPROFILER_H__

/*

basic concept


profile_start( "test1" )


profile_end( "test1" )








*/