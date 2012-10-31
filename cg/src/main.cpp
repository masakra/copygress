#include "sameVolume.h"

#include <QApplication>
#include <QMessageBox>
#include <QDebug>

int
main( int argc, char ** argv )
{
	QApplication app( argc, argv );

	if ( sameVolume( "C:/CONFIG.SYS", "C:/tmp/an24.csv" ) )
		QMessageBox::information( 0, "", "Yes" );
	else
		QMessageBox::information( 0, "", "No" );

	return 0;
	//return app.exec();
}
