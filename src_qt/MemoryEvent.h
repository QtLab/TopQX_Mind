#if !defined(_MEMORYEVENT_H)
#define _MEMORYEVENT_H

#include <QtCore/QString>
#include <QtCore/QVariant>

#include "ObjectToXml.h"

namespace CnotiMind
{

	class Perception;

	class MemoryEvent: public ObjectToXml
	{
	public:

		MemoryEvent();
		MemoryEvent( const QString& eventName );
		MemoryEvent( const QString& eventName, const QVariant& value );
		MemoryEvent( const QString& eventName, const QVariant& value, qint64 time );
		MemoryEvent( const Perception& perception );

		const QVariant& value() const;
		const QString& event() const;
		qint64 time() const;

		QString toXml() const;

		bool operator ==( const QString& name );
		bool operator ==( const MemoryEvent& event );

		friend bool operator ==(const MemoryEvent& event, const QString& name);
		friend bool operator ==(const QString& name, const MemoryEvent& event);

		static qint64 eventTime();

	protected:
		QString _eventName;
		QVariant _value;
		qint64 _time;
	};

}
#endif  //_MEMORYEVENT_H
