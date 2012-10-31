
#include <QtGui>

#ifdef Q_OS_WIN32
#include "qt_windows.h"
#else
#include <sys/types.h>
#include <sys/stat.h>
#endif

bool
sameVolume( const QString & p1, const QString &p2 )
{
#ifdef Q_OS_WIN32
	wchar_t s1[ 1000 ] = { 0 },
		s2[ 1000 ] = { 0 };

	wchar_t b1[ 100 ] = { 0 },
		b2[ 100 ] = { 0 };

	QDir::toNativeSeparators( p1 ).toWCharArray( s1 );
	QDir::toNativeSeparators( p2 ).toWCharArray( s2 );

	GetVolumePathName( s1, b1, 99 );
	GetVolumePathName( s2, b2, 99 );

	return QString::fromWCharArray( b1 ) == QString::fromWCharArray( b2 );
#else
	struct stat s1,
				s2;

	stat( p1.toAscii().data(), &s1 );
	stat( p2.toAscii().data(), &s2 );

	return s1.st_dev == s2.st_dev;
#endif



}
