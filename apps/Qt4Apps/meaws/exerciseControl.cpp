#include <iostream>
using namespace std;

#include "exerciseControl.h"

ExerciseControl::ExerciseControl() {
}

ExerciseControl::~ExerciseControl() {
	instructionArea->removeWidget(instructionImageLabel);
	delete (instructionImageLabel);;

	resultArea->removeWidget(displayPitches);
	delete displayPitches;
	resultArea->removeWidget(displayAmplitude);
	delete displayAmplitude;
}

int ExerciseControl::getType() {
	return TYPE_CONTROL;
}

void ExerciseControl::setupDisplay() {
	displayPitches = new QtMarPlot();
	displayPitches->setPlotName("Pitch");
	displayPitches->setBackgroundColor(QColor(255,255,255));
	displayPitches->setPixelWidth(2);
	displayAmplitude = new QtMarPlot();
	displayAmplitude->setPlotName("Amplitude");
	displayAmplitude->setBackgroundColor(QColor(255,255,255));
	displayAmplitude->setPixelWidth(2);
/*
	displayPitches = new QLabel;
	displayAmplitude = new QLabel;
	displayPitches->setText("Display Pitches here");
	displayAmplitude->setText("Display Ampitudes here");
	resultArea->addWidget(displayPitches,0,0);
	resultArea->addWidget(displayAmplitude,0,1);
*/
	//QHBoxLayout *displayLayout = new QHBoxLayout;
	resultArea->addWidget(displayPitches,0,0);
	resultArea->addWidget(displayAmplitude,0,1);
	//resultArea->addLayout(displayLayout);

//	resultsDisplay = new MeawsDisplay();
//	mainLayout->addLayout(resultsDisplay);
}


QString ExerciseControl::exercisesDir() {
	QString toReturn(MEAWS_DIR);
	toReturn.append("data/control/");
	return toReturn;
}

void ExerciseControl::displayAnalysis(MarBackend *results) {
//	cout<<results->getPitches();
//	cout<<"displaying?"<<endl;
	displayPitches->setVertical(0,200);
	displayPitches->setData( results->getPitchPointer() );

}

