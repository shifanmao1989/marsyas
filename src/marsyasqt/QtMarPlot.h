//  Graham Percival  <gperciva@uvic.ca>
#ifndef QTMARPLOT_H
#define QTMARPLOT_H

#include <QWidget>
#include <QPainter>

#include "MarSystemManager.h"
using namespace Marsyas;

namespace MarsyasQt
{
/**
	\brief A simple realvec plotting widget.
	\ingroup MarsyasQt

	Plots a realvec.  Is simple to use, but lacks many features of the
other plotting widget.

*/
class QtMarPlot : public QWidget
{
	Q_OBJECT
public:
	QtMarPlot(QWidget *parent = 0);
	~QtMarPlot();

	void setPlotName(QString plotName)
	{
		plotName_ = plotName;
	}
	void setBackgroundColor(QPalette color)
	{
		setPalette(color);
	}
	void setPixelWidth(mrs_natural width)
	{
		width_ = width;
	}
	void setCenterLine(bool drawCenter)
	{
		drawCenter_ = drawCenter;
	}
	void setImpulses(bool drawImpulses)
	{
		drawImpulses_ = drawImpulses;
	}

	/// scales data
	void setVertical(mrs_real minVal, mrs_real highVal)
	{
		minVal_ = minVal;
		highVal_ = highVal;
	}

	void setData(realvec getData)
	{
		data_ = getData;
		update();
	}

protected:
	void paintEvent(QPaintEvent *event);

	QString plotName_;
	mrs_real minVal_, highVal_;
	mrs_natural width_;
	bool drawCenter_;
	bool drawImpulses_;

	realvec data_;
};

} //namespace
#endif

