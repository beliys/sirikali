/*
 *
 *  Copyright ( c ) 2019
 *  name : Francis Banyikwa
 *  email: mhogomchungu@gmail.com
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 of the License, or
 *  ( at your option ) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "runinthread.h"

#include <QMetaObject>

runInThread::runInThread( QThread * thread,std::function< void() > function ) :
	m_function( std::move( function ) )
{
	this->moveToThread( thread ) ;
	QMetaObject::invokeMethod( this,"run",Qt::QueuedConnection ) ;
}

void runInThread::run()
{
	m_function() ;
	this->deleteLater() ;
}
